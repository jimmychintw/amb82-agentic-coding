# AMB82-MINI UVC Camera on macOS — Expert Consultation

## Goal

Make Realtek AMB82-MINI (RTL8735B, ARM Cortex-M33, DWC2 OTG USB) work as a **USB Video Class (UVC) camera on macOS**. The device should stream MJPEG 1920x1080 video via USB isochronous transfer.

## What Works

- USB enumeration on macOS ✅ — device appears as "USB UVC CLASS"
- UVC descriptor negotiation ✅ — macOS PROBE → COMMIT → SET_INTERFACE alt=1 → "stream on"
- MJPEG format negotiation ✅ — 1920x1080 @ 10/15/24fps
- MMF2 pipeline (array → SISO → UVCD) ✅ — firmware side data flow works
- On Windows (PotPlayer/Teams) the same USB driver reportedly works

## What Doesn't Work

**EP3 IN isochronous endpoint is never enabled by the USB driver.** After `SET_INTERFACE alt=1`, the EP3 hardware register shows:
```
DIEPCTL3  = 0x00868400  → EPEna(bit31)=0, USBActEP(bit15)=1, EPTYP=ISO, MPS=1024
DIEPINT3  = 0x00000000  → No interrupts
DIEPTSIZ3 = 0x00000000  → No transfer configured
DIEPDMA3  = 0x00000000  → No DMA address
```

macOS doesn't send IN tokens to EP3, so no data is transferred.

## Root Cause Analysis

### The ep_enable State Check

The USB driver is Realtek's proprietary `libusbd.a` (closed source, DWC2-based). The `ep_enable()` function (weak symbol) checks a global structure `GADGET_WRAPPER_TMP` before enabling any endpoint:

```arm-asm
; ep_enable disassembly (from libusbd.a)
ep_enable:
    ; ...
    ldr  r3, [pc, #148]        ; r3 = &GADGET_WRAPPER_TMP (0x70449160)
    ; ...
    ldr  r2, [r3, #0x24]       ; r2 = struct[0x24] — "driver" pointer?
    cbz  r2, error_bogus        ; if NULL → "bogus device state"
    ldrb r2, [r3, #0x14]       ; r2 = struct[0x14] — device state byte
    cbnz r2, do_enable          ; if non-zero → proceed to enable
    ; fall through to error
error_bogus:
    ; prints "[OTG Err]ERROR:: ep_enable, bogus device state"
    ; returns -1
do_enable:
    ldr  r0, [r3, #0]          ; r0 = struct[0x00] — PCD pointer
    bl   dwc_otg_pcd_ep_enable  ; enable EP via DWC2 hardware
```

### GADGET_WRAPPER_TMP State

At address `0x70449160` (964 bytes, data section):

**After USB init (before enumeration):**
```
offset 0x00: 0x00000000  ← PCD pointer = NULL!
offset 0x04: 0x7070A100
offset 0x08: 0x7070A080
offset 0x0C: 0x70304284
offset 0x10: 0x7070B1A0
offset 0x14: 0x00        ← device state = 0
offset 0x18-0x2C: all zeros
offset 0x24: 0x00000000  ← driver pointer = NULL
```

**During streaming (after SET_INTERFACE alt=1, read from format change callback):**
```
offset 0x14: 0x03        ← device state now 3 (CONFIGURED?)
offset 0x24: 0x70314230  ← driver pointer now set!
```

BUT `offset 0x00` (PCD pointer) — **we never checked this during streaming**. It might still be NULL.

### The Three Problems

1. **During initial USB init**: `ep_enable` is called but struct[0x14]=0 and struct[0x24]=0 → fails with "bogus device state". This is expected (device not yet configured).

2. **During SET_INTERFACE alt=1**: `fun_set_alt` calls the format change callback (step 1), then `usb_ep_enable` → `ep_enable` (step 3). By this time, struct[0x14] and struct[0x24] might be non-zero. But **even if state checks pass, struct[0x00] (PCD pointer) might be NULL**, causing `dwc_otg_pcd_ep_enable(NULL, ...)` to fail silently.

3. **iso_ep_start Bus Fault**: After ep_enable (regardless of success/failure), `fun_set_alt` calls `iso_ep_start` which triggers DMA on improperly initialized EP → Bus Fault (asynchronous, DMA access to invalid address).

### fun_set_alt Flow (from disassembly)

```
fun_set_alt(dev, interface=1, alt=1):
  1. Call change_parm_cb()           ← format change callback (we can hook here)
  2. usb_ep_disable(EP3)
  3. usb_ep_enable(EP3, descriptor)  ← calls ep_enable → "bogus device state"
  4. alloc_iso_request(EP3, 1, 1)
  5. Setup ISO request fields
  6. iso_ep_start(EP3, iso_req, 1)   ← Bus Fault! DMA to invalid buffer
  7. Return 0 (success regardless)
```

### Key Symbols (from nm.map)

| Symbol | Address | Size | Description |
|--------|---------|------|-------------|
| GADGET_WRAPPER_TMP | 0x70449160 | 964B | USB gadget wrapper (partially uninitialized) |
| gpcd | 0x704485C0 | 2880B | Global PCD (Peripheral Controller Driver) |
| ep_enable | 0x701c32c0 | - | Weak symbol, endpoint enable with state check |
| dwc_otg_pcd_ep_enable | 0x701bd64c | - | Weak symbol, actual DWC2 EP enable |
| fun_set_alt | 0x701c6f5c | - | SET_INTERFACE handler in UVC driver |
| iso_ep_start | 0x701c48e0 | - | Start isochronous transfer |
| usbd_uvc_driver | 0x70314230 | - | UVC class driver struct |

## What We've Tried

### 1. Binary Patch ep_enable State Check
- Patched firmware_ntz.bin to NOP/bypass the struct[0x14] and struct[0x24] checks
- **Result**: Bypassing only struct[0x14] → struct[0x24] still blocks. Bypassing both → breaks USB enumeration (EP enable runs during init when device not ready, corrupts USB state machine)

### 2. Binary Patch NOP iso_ep_start
- NOP'd the `bl iso_ep_start` call in fun_set_alt (must patch linked binary, not .a file due to relocations)
- **Result**: Prevents Bus Fault, fun_set_alt returns cleanly. But EP3 still not enabled.

### 3. Runtime Fix in Format Change Callback
- Set struct[0x14]=1 and struct[0x24]=non-zero in the `uvcd_change_format_resolution` callback (called inside fun_set_alt before ep_enable)
- **Result**: Values are set, but struct[0x00] (PCD pointer) is still NULL → dwc_otg_pcd_ep_enable can't work

### 4. Manual DWC2 Register Write
- Manually wrote DIEPCTL3 (EPEna + CNAK), DIEPTSIZ3, DIEPDMA3 from firmware code
- **Result**: EP3 enabled in hardware, DMA address set, all global config correct (GAHBCFG DMA enable, DAINTMSK EP3 masked, DIEPTXF3 allocated). But DIEPINT3 stays 0 — no transfer completes. macOS not sending IN tokens.

### 5. Override ep_enable Weak Symbol
- Provided our own `ep_enable()` that calls `dwc_otg_pcd_ep_enable` and force-enables EP3 if it fails
- **Result**: Breaks USB enumeration because ep_enable is also called for EP0/EP1 during init, and our override disrupts those

## Technical Environment

- **SoC**: Realtek RTL8735B (AmebaPro2)
- **Core**: ARM Cortex-M33 (TrustZone)
- **USB**: Synopsys DWC2 OTG, Device mode
- **USB Base**: 0x400C0000
- **SDK**: Realtek ameba-rtos-pro2 (FreeRTOS based)
- **USB Library**: libusbd.a (closed source, DWC2 wrapper)
- **Host**: macOS 25.3.0 (Darwin, Apple Silicon)
- **Toolchain**: arm-none-eabi-gcc 10.3.0

## Specific Questions

1. **Why is GADGET_WRAPPER_TMP[0x00] (PCD pointer) NULL?** The gadget wrapper struct has some fields initialized (offsets 0x04-0x10) but the PCD pointer at offset 0x00 is zero. Is this a Realtek-specific initialization order issue? Could `gpcd` (at 0x704485C0) be the correct PCD to use?

2. **How to fix ep_enable without breaking enumeration?** We can't bypass the state check globally (breaks init), and the state check naturally passes during set_alt for struct[0x14] and [0x24], but struct[0x00] is NULL. How should we properly initialize the gadget wrapper?

3. **Why does macOS not send IN tokens even after manual EP3 enable?** When we manually set DIEPCTL3 with EPEna+CNAK, DIEPTSIZ3, and DIEPDMA3, the hardware is configured but DIEPINT3 stays 0. Is this because macOS's SET_INTERFACE response was ACKed but the EP wasn't in the correct USB protocol state?

4. **Is there a way to make iso_ep_start work?** The Bus Fault in iso_ep_start is from DMA accessing invalid buffers in the ISO request. Could we pre-allocate proper DMA buffers before iso_ep_start runs?

5. **Alternative approach**: Could we bypass the entire libusbd.a ISO transfer mechanism and implement our own isochronous transfer using direct DWC2 register access? If so, what's the correct sequence for DWC2 DMA-based isochronous IN transfer?

## File References

- Disassembly: `/tmp/libusbd_disasm.txt` (65K lines)
- Attack plan: `UVC_ATTACK_PLAN.md`
- Session plan: `UVC_NEXT_SESSION_PLAN.md`
- Project notes: Memory files in `.claude/projects/` directory
