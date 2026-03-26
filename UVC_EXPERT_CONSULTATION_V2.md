# AMB82 UVC macOS — Expert Consultation V2

## Previous Consultation Summary

In V1, we identified that `GADGET_WRAPPER_TMP[0x00]` (PCD pointer) was NULL, causing `ep_enable()` to call `dwc_otg_pcd_ep_enable(NULL, ...)`. We fixed this by setting `wrapper[0x00] = &gpcd` in the format change callback. **This eliminated the Bus Fault in `iso_ep_start`.**

## New Finding: Second State Check in dwc_otg_pcd_ep_enable

Even with the correct PCD pointer, **EP3 is still not enabled** (DIEPCTL3 bit 31 stays 0). Diagnostic reveals a second state check:

### dwc_otg_pcd_ep_enable Disassembly (Key Section)

```arm-asm
; r5 = pcd (= gpcd, now valid)
; After finding the correct EP in PCD structure:

168: ldr  r2, [r5, #8]           ; r2 = gpcd[+0x08] = core_if pointer
16a: ldrb.w r2, [r2, #71]       ; r2 = core_if[+0x47] = state byte
16c: cmp  r2, #0
16e: beq.n 0xb6                 ; if state == 0 → SKIP hardware config!

; ... (hardware register writes via HAL_OTG_READ32/WRITE32 only if state != 0)
```

### Runtime Diagnostic Data (5 second monitoring)

```
t=0s  EP3_CTL=0x00868400  gpcd[0x08]=0x70448220 (core_if)  core_if[0x47]=0x00
t=1s  EP3_CTL=0x00868400  gpcd[0x08]=0x70448220 (core_if)  core_if[0x47]=0x00
t=2s  EP3_CTL=0x00868400  gpcd[0x08]=0x70448220 (core_if)  core_if[0x47]=0x00
t=3s  EP3_CTL=0x00868400  gpcd[0x08]=0x70448220 (core_if)  core_if[0x47]=0x00
t=4s  EP3_CTL=0x00868400  gpcd[0x08]=0x70448220 (core_if)  core_if[0x47]=0x00
Final: EP3_CTL=0x00868400  (unchanged for 5 seconds)
"stream on" prints AFTER the 5-second wait
```

### Key Observations

1. **`core_if` pointer is valid** (`0x70448220`) — not NULL
2. **`core_if[0x47]` is persistently 0x00** — never changes, even after SET_INTERFACE alt=1
3. **This byte is the reason `dwc_otg_pcd_ep_enable` skips hardware register writes**
4. **EP3 registers never change** — no DMA, no transfer size, no enable
5. **`stream on` prints AFTER the 5-second wait** — confirming `fun_set_alt` completes eventually but EP3 was never hardware-enabled

### The State Check Chain (Complete Picture)

```
ep_enable() checks:
  1. GADGET_WRAPPER_TMP[0x14] != 0  (gadget.speed)     ← PASS (0x03 = USB_SPEED_HIGH)
  2. GADGET_WRAPPER_TMP[0x24] != 0  (driver/name ptr)  ← PASS (non-zero)
  3. GADGET_WRAPPER_TMP[0x00] != 0  (PCD pointer)      ← PASS (= &gpcd, our fix)

  Then calls dwc_otg_pcd_ep_enable(gpcd, ep_desc, usb_ep):
  4. gpcd[0x08] != 0                (core_if pointer)   ← PASS (0x70448220)
  5. core_if[0x47] != 0             (???)               ← FAIL (0x00)
     → Skips all hardware register writes
     → EP3 never enabled
```

## What is core_if[0x47]?

### From DWC2 Linux Driver Knowledge

In the standard DWC2/Synopsys driver, `core_if` is `dwc_otg_core_if_t`. Offset 0x47 (byte 71) falls within the core interface structure. Based on the structure layout:

```c
typedef struct dwc_otg_core_if {
    dwc_otg_core_global_regs_t *core_global_regs;  // +0x00
    uint32_t reg_offset;                             // +0x04
    dwc_otg_dev_if_t *dev_if;                       // +0x08
    dwc_otg_host_if_t *host_if;                     // +0x0C
    dwc_otg_core_params_t *core_params;             // +0x10
    // ... many more fields
    // Byte at offset 0x47 could be:
    //   - Part of hwcfg/capabilities structure
    //   - A DMA enable flag
    //   - An "op_state" or "otg_sts" flag
    //   - Part of device/host configuration
};
```

The exact field at offset 0x47 depends on Realtek's specific version of the structure. It could be:
- **DMA descriptor enable flag** (`dma_desc_enable`)
- **Part of hardware configuration cache** (`hwcfg` bits)
- **Device/host mode flag**
- **A capability/feature flag set during core init**

### Nearby Symbols for Context

```
core_if at:    0x70448220
gpcd at:       0x704486C0 (offset +0x4A0 from core_if)
```

The core_if structure is ~1184 bytes (0x4A0) based on the gap to gpcd.

## Questions for Expert

### Q1: What is `core_if[0x47]` in the DWC2 Synopsys driver?

Given:
- Structure `dwc_otg_core_if_t` (Synopsys DWC OTG v2.81a, 2012 revision)
- Total size approximately 1184 bytes
- Byte at offset 0x47 (71) controls whether `dwc_otg_pcd_ep_enable` writes to hardware registers
- It's checked as a single byte: `ldrb.w r2, [core_if, #71]; cmp r2, #0; beq skip_hw_config`
- In the working case (Windows), this byte must be non-zero

Possible candidates:
- `dma_enable` / `dma_desc_enable`?
- `en_multiple_tx_fifo`?
- Part of `hwcfg2` / `hwcfg4` cached values?
- An initialization completion flag?

### Q2: Who should set this byte?

The byte is 0 throughout the entire device lifecycle on macOS:
- After `_usb_init()` + `wait_usb_ready()`: 0
- After USB enumeration: 0
- After SET_CONFIGURATION: 0
- During SET_INTERFACE alt=1: 0
- After `fun_set_alt` completes: 0

On Windows (reportedly works), this byte must be non-zero. What part of the DWC2 initialization sets it?

### Q3: Is there a safe way to determine the correct value?

Options we're considering:
1. **Set it to 1** in the format change callback (like we did for wrapper[0x14])
2. **Read it from hardware** — is there a DWC2 register that corresponds to this field?
3. **Trace the init path** — find which function in `libusbd.a` is supposed to set it

### Q4: Could this be related to DMA descriptor mode vs buffer mode?

In DWC2, there are two DMA modes:
- **Buffer DMA mode**: Simple DMA, one buffer per transfer
- **Descriptor DMA mode**: Uses DMA descriptors for scatter-gather

If `core_if[0x47]` is `dma_desc_enable` and it's 0, it might mean the driver is in buffer DMA mode. In that case, `dwc_otg_pcd_ep_enable` might be skipping descriptor-based EP setup because it thinks buffer mode is active and EP setup happens differently.

Could the "skip hardware config" branch actually be the CORRECT path for buffer DMA mode, with the real EP hardware configuration happening elsewhere (e.g., in the actual transfer start function)?

### Q5: Alternative interpretation of the disassembly

Is it possible that `core_if[0x47]` being 0 is NORMAL, and the `beq skip_hw_config` is actually skipping optional/advanced configuration (not the essential EP enable)? In that case, the EP3 enable failure might be for a completely different reason that we haven't found yet.

## Current Fix Stack

```c
// In uvcd_change_format_resolution() callback (called inside fun_set_alt):
extern uint32_t GADGET_WRAPPER_TMP;
extern uint32_t gpcd;
volatile uint32_t *wrapper = &GADGET_WRAPPER_TMP;
if (wrapper[0] == 0) {
    wrapper[0] = (uint32_t)&gpcd;  // Fix: set PCD pointer
}
```

## What We Need

The single most important thing to figure out: **What is the byte at `dwc_otg_core_if_t + 0x47`, and should we set it to non-zero?**

If yes → one more line of code and EP3 might finally be enabled.
If no → we need to find the REAL reason EP3 hardware registers are never written.
