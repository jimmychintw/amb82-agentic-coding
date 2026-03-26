# AMB82 UVC macOS — Expert Consultation V3 (Latest)

## One-Line Summary

AMB82-MINI (RTL8735B, DWC2 OTG) 的 UVC camera 在 macOS 上 enumerate 正常、streaming negotiation 正常、`SET_INTERFACE alt=1` 正常返回，但 **EP3 IN isochronous endpoint 的硬體從未被啟用**，因為 Realtek 關閉了 DMA descriptor mode (`dma_desc_enable=0`)，而 `iso_ep_start` 只在 descriptor DMA mode 下才會程式化 EP 硬體寄存器。

---

## Architecture

```
Mac (macOS host)
  ↕ USB High-Speed
AMB82-MINI (RTL8735B, Cortex-M33, DWC2 OTG)
  ├── libusbd.a (closed source, Synopsys DWC OTG v2.81a based)
  │     ├── ep_enable()              — weak symbol, state check + software EP config
  │     ├── dwc_otg_pcd_ep_enable()  — weak symbol, hardware EP config
  │     ├── iso_ep_start()           — ISO transfer start
  │     └── fun_set_alt()            — SET_INTERFACE handler
  ├── module_uvcd.c (open source, MMF2 pipeline)
  │     ├── uvcd_handle()            — frame data flow
  │     └── uvcd_change_format_resolution() — format change callback
  └── usb_patch.c (our patches)
        └── dwc_otg_enable/disable_global_interrupts overrides
```

---

## What Works

| Item | Status |
|------|--------|
| USB enumerate on macOS | ✅ "USB UVC CLASS" visible |
| UVC PROBE/COMMIT | ✅ MJPEG 1920x1080 @10/15/24fps |
| SET_INTERFACE alt=1 | ✅ "stream on" printed |
| fun_set_alt completes | ✅ No crash (with PCD fix) |
| ep_enable software config | ✅ DIEPCTL3 NAKSts changes |
| MMF2 pipeline | ✅ array→SISO→uvcd |
| Windows (reportedly) | ✅ PotPlayer/Teams work |

## What Doesn't Work

**EP3 IN isochronous endpoint is NEVER hardware-enabled.**

After `stream on` (fun_set_alt completed, including iso_ep_start):
```
DIEPCTL3  = 0x00868400  → EPEna=0, USBActEP=1, EPTYP=ISO, MPS=1024
DIEPINT3  = 0x00000000  → No interrupts
DIEPTSIZ3 = 0x00000000  → No transfer configured
DIEPDMA3  = 0x00000000  → No DMA address set
```

**EP3 registers never change from this state.** Not during init, not during set_alt, not after stream_on. `iso_ep_start` runs but does NOT program these registers.

---

## Root Cause: dma_desc_enable = 0

### Discovery

In `dwc_otg_core_if.h`:
```c
//#define dwc_param_dma_desc_enable_default 1
#define dwc_param_dma_desc_enable_default 0  //wei add
```

Realtek engineer "wei" changed the default from 1 (DMA Descriptor mode) to 0 (Buffer DMA mode).

### Impact Chain

```
dma_desc_enable = 0
  → dwc_otg_core_init() sets core_if->dma_desc_enable = 0
  → dwc_otg_pcd_ep_enable() skips DMA descriptor chain allocation
  → iso_ep_start() → dwc_otg_pcd_iso_ep_start() →
    finds no DMA descriptors → silently fails
  → EP3 hardware never programmed (DIEPCTL3 EPEna never set)
  → macOS receives no data → gives up
```

### Evidence

5-second continuous monitoring of EP3 registers while fun_set_alt executes:
```
t=0s  CTL=0x00878400 DMA=0x00000000  core_if[0x47]=0x00
t=1s  CTL=0x00868400 DMA=0x00000000  core_if[0x47]=0x00
t=2s  CTL=0x00868400 DMA=0x00000000  core_if[0x47]=0x00
t=3s  CTL=0x00868400 DMA=0x00000000  core_if[0x47]=0x00
t=4s  CTL=0x00868400 DMA=0x00000000  core_if[0x47]=0x00
(stream on)  ← fun_set_alt completed, iso_ep_start ran
EP3 registers: UNCHANGED
```

### Attempted Fix: Force dma_desc_enable=1

Both approaches broke USB enumeration:
1. Setting `core_if[0x47]=1` at runtime (in format change callback)
2. Overriding `dwc_otg_set_param_dma_desc_enable()` weak symbol to force val=1

**Reason**: DMA descriptor mode requires additional infrastructure (descriptor chain allocation, descriptor ring buffers, specific FIFO configuration) that isn't initialized when `dma_desc_enable=0`. Enabling the flag without the infrastructure causes the USB stack to crash during enumeration.

---

## What We've Fixed Successfully

### Fix 1: GADGET_WRAPPER_TMP PCD Pointer

```c
// In uvcd_change_format_resolution() callback
extern uint32_t GADGET_WRAPPER_TMP;
extern uint32_t gpcd;
volatile uint32_t *wrapper = &GADGET_WRAPPER_TMP;
if (wrapper[0] == 0) {
    wrapper[0] = (uint32_t)&gpcd;
}
```

**Effect**: Eliminated Bus Fault in `iso_ep_start`. `fun_set_alt` now completes cleanly.

### Fix 2: dwc_otg_enable_global_interrupts

```c
void dwc_otg_enable_global_interrupts(void *core_if) {
    // Force GAHBCFG bit 0 (GlblIntrMsk) = 1
}
```

**Effect**: Fixed GAHBCFG bit 0 not being set, enabling USB interrupts.

---

## Key Structures (Confirmed from Headers)

```c
// From usb_gadget.h
struct gadget_wrapper {
    dwc_otg_pcd_t *pcd;                    // [0x00] — was NULL, fixed to &gpcd
    struct usb_gadget gadget;               // [0x04]
    struct usb_gadget_driver *driver;       // [0x30]
    struct usb_ep ep0;
    struct usb_ep in_ep[16];
    struct usb_ep out_ep[16];
};

// From dwc_otg_cil.h — core_if structure near offset 0x47
struct dwc_otg_core_if {
    ...
    uint16_t total_fifo_size;               // +0x40
    uint16_t rx_fifo_size;                  // +0x42
    uint16_t nperio_tx_fifo_size;           // +0x44
    uint8_t  dma_enable;                    // +0x46
    uint8_t  dma_desc_enable;               // +0x47 ← THE BLOCKER
    uint8_t  pti_enh_enable;                // +0x48
    uint8_t  multiproc_int_enable;          // +0x49
    uint8_t  en_multiple_tx_fifo;           // +0x4A
    ...
};
```

---

## The Central Question

**How to make isochronous IN transfers work with `dma_desc_enable=0` (buffer DMA mode)?**

### Context

- Realtek intentionally uses buffer DMA mode (not descriptor DMA)
- Non-ISO endpoints (EP0 control, EP1 interrupt) work fine in this mode
- ISO endpoints require different handling in buffer DMA vs descriptor DMA
- The existing `iso_ep_start` function appears to only work in descriptor DMA mode
- We cannot switch to descriptor DMA mode without breaking everything

### Specific Questions

**Q1: In DWC2 buffer DMA mode, how should isochronous IN endpoints be started?**

In Linux DWC2 gadget driver, there are separate paths:
- `dwc2_gadget_start_isoc_ddma()` for descriptor DMA
- `dwc2_gadget_start_isoc()` for buffer DMA

Does Realtek's `iso_ep_start` only implement the descriptor DMA path? If so, how should we implement the buffer DMA path?

**Q2: What is the correct register programming sequence for DWC2 ISO IN in buffer DMA mode?**

We tried manually programming:
```
DIEPTSIZ3 = (MULCNT=1 << 29) | (PKTCNT << 19) | XFRSIZ
DIEPDMA3  = buffer_address
DIEPCTL3  = EPEna(31) | CNAK(26) | existing_config
```

EP3 was enabled but DIEPINT3 stayed 0 (no transfer completed). macOS didn't send IN tokens. This was BEFORE our PCD fix. Should we retry this approach now that PCD is correctly bound?

**Q3: Could we bypass iso_ep_start entirely and drive EP3 from uvcd_handle?**

The MMF2 pipeline calls `uvc_video_put_in_stream_queue()` which is in `libusbd.a`. Does this function also rely on DMA descriptors? Or could it work independently to program EP3 for each frame?

**Q4: What does `put_in_stream_queue` / `wait_frame_down` actually do internally?**

These are in the closed-source `libusbd.a`. Do they:
- a) Program DIEPCTL3/DIEPTSIZ3/DIEPDMA3 directly for each frame? (buffer DMA)
- b) Fill DMA descriptors that are processed by hardware? (descriptor DMA)
- c) Just manage a software queue, with actual DMA handled by iso_ep_start?

If (a), they should work independently of `dma_desc_enable`.
If (b) or (c), they require descriptor DMA or iso_ep_start to be functional.

**Q5: Is there a way to enable descriptor DMA mode safely?**

We know setting `dma_desc_enable=1` alone breaks enumeration. What other initialization is needed? Looking at DWC2 Linux driver, what functions set up the descriptor DMA infrastructure? Could we call them manually?

**Q6: ESP32-S2/S3 uses the same DWC2 IP with TinyUSB. How does TinyUSB handle ISO IN in buffer DMA mode?**

ESP32 Cam projects stream UVC over USB. TinyUSB's DWC2 port must handle isochronous transfers. How does it program the EP registers without descriptor DMA?

---

## Symbols Reference

| Symbol | Address | Type |
|--------|---------|------|
| GADGET_WRAPPER_TMP | (varies per build) | D (extern) |
| gpcd | (varies per build) | D (extern) |
| dwc_otg_set_param_dma_desc_enable | W (weak) | overridable |
| dwc_otg_pcd_ep_enable | W (weak) | overridable |
| ep_enable | W (weak) | overridable |
| iso_ep_start | in libusbd.a | not overridable |
| dwc_otg_pcd_iso_ep_start | in libusbd.a | not overridable |
| uvc_video_put_in_stream_queue | in libusbd.a | callable |
| uvc_video_out_stream_queue | in libusbd.a | callable |
| usbd_wait_frame_down | in libusbd.a | callable |

---

## Files

- Disassembly: `/tmp/libusbd_disasm.txt`
- Headers: `ameba-arduino-pro2/.../usb_otg/dwc_otg_cil.h`, `usb_gadget.h`, `dwc_otg_core_if.h`
- Attack plan: `UVC_ATTACK_PLAN.md`
- Previous consultations: `UVC_EXPERT_CONSULTATION.md`, `UVC_EXPERT_CONSULTATION_V2.md`
