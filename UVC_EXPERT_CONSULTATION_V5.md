# AMB82 UVC — Expert Consultation V5

## Hardware
- **SoC:** Realtek RTL8735B (ARM Cortex-A32)
- **USB Controller:** Synopsys DWC2 OTG, running in **Buffer DMA mode** (NOT Descriptor DMA)
- **Host:** macOS (Apple Silicon), connected via USB 2.0 Hub
- **SDK:** Realtek ameba-rtos-pro2, with `libusbd.a` (closed-source binary blob)

## Goal
Make AMB82-Mini function as a UVC webcam on macOS.

## Current Status: ALL transfer attempts fail at the same point

**DMA successfully moves data from memory → TX FIFO, but the DWC2 packet engine NEVER transmits it onto the USB bus.** This happens with BOTH Isochronous AND Bulk transfer types.

## What Works

| Step | Status |
|------|--------|
| USB enumerate on macOS | ✅ VID 7531, PID 258 |
| UVC PROBE/COMMIT negotiation | ✅ 1920x1080 @ 24fps MJPEG |
| SET_INTERFACE alt=1 (stream on) | ✅ |
| ep_enable (PCD level) | ✅ via our override (see below) |
| EP3 register configuration | ✅ EPEna, CNAK, TXFNUM, MPS, EPType all correct |
| DMA transfer (memory → FIFO) | ✅ XFRSIZ consumed on all frames |
| **Packet transmission (FIFO → USB bus)** | **❌ NEVER happens** |

## The Core Symptom

After programming EP3 and starting DMA:
```
DIEPCTL3 = 0x80C88200  (EPEna=1, Bulk, MPS=512, TXFNUM=3, USBActEP=1)
DIEPTSIZ3: 0x00080002 → 0x00080000  (XFRSIZ consumed: 2→0, but PKTCNT stays at 1)
DIEPINT3 = 0x00000000  (NO interrupts at all — no XFRC, no errors)
DAINT = 0x00000000  (EP3 never appears in DAINT)
```

After 5 seconds of polling: no XFRC (Transfer Complete). This pattern is 100% consistent across hundreds of attempts with both ISO and Bulk.

## Register Dump (Baseline)

```
DCFG    = 0x08240040  DevSpd=0(HS)  DescDMA=0  EPMisCnt=9
DCTL    = 0x00008000  IFrmNum=1  GNPINNakSts=0  SftDiscon=0  GMC=0
DSTS    = 0x0046F900  EnumSpd=0(HS)  SOFFN=1785
GINTSTS = 0x04008028  (SOF, NPTxFEmp, InEPInt — but NO IISOIXFR with Bulk)
GINTMSK = 0xD02C3C06  (IISOIXFR masked by us)
DAINTMSK= 0x0001000B  (EP0 IN, EP1 IN, EP3 IN, EP0 OUT)

GNPTXFSIZ = 0x00800200  (depth=128 words, start=512)
DTXFSIZ1  = 0x03000280  (depth=768 words)
DTXFSIZ2  = 0x03000580  (depth=768 words)
DTXFSIZ3  = 0x01000880  (depth=256 words = 1024 bytes, start=2176)
TXFSTS3   = 0x00000300  (768 words free — more than allocated??)
```

## All Attempted Fixes (Cumulative)

### 1. GAHBCFG bit 0 (Global Interrupt Mask)
- Override `dwc_otg_enable_global_interrupts` weak symbol
- Sets GAHBCFG bit 0 = 1
- **Result:** Needed for basic USB function, but doesn't fix EP3

### 2. ep_enable Override (MAJOR BREAKTHROUGH)
- Override `ep_enable` weak symbol
- Fix GADGET_WRAPPER_TMP[0x14] (gadget.speed) from 0 → 0x03 (USB_SPEED_HIGH)
- Fix GADGET_WRAPPER_TMP[0x00] (PCD pointer) to &gpcd
- Call `dwc_otg_pcd_ep_enable(pcd, ep_desc, usb_ep)` — **returns 0 (success)**
- **Result:** PCD now knows about EP3, but hardware still doesn't transmit

### 3. EP Descriptor Patch (ISO → Bulk)
- Patch `uvc_hs_streaming_ep` in memory before enumeration
- bmAttributes: 0x05 (ISO) → 0x02 (Bulk)
- wMaxPacketSize: 0x1400 (5120) → 0x0200 (512)
- **Result:** macOS sees Bulk endpoint, same failure

### 4. DCTL.IFrmNum = 1 (Ignore Frame Number)
- Already set by Realtek SDK by default
- **Result:** N/A (was already 1)

### 5. GINTMSK: Mask IISOIXFR (bit 20) + IPXFR (bit 22)
- Prevents libusbd.a ISR from handling incomplete ISO
- **Result:** Doesn't fix transmission

### 6. DCFG.EPMisCnt = 31 (max)
- Increase EP IN mismatch tolerance
- **Result:** No change

### 7. EP3 Disable/Re-enable Between Frames
- Set EPDis + SNAK, wait for EPDisDone, then reprogram
- **Result:** Fixed DMA for frames after #0 (important fix but doesn't solve core issue)

### 8. Manual DIEPCTL3 Programming
```c
ctl = 0;
ctl |= (512 & 0x7FF);    // MPS = 512
ctl |= (1u << 15);        // USBActEP
ctl |= (2u << 18);        // EPType = Bulk
ctl |= (3u << 22);        // TXFNUM = 3
ctl |= (1u << 26);        // CNAK
ctl |= (1u << 31);        // EPEna
EP3_DIEPCTL = ctl;
```
- **Result:** Register looks correct, but no transmission

### 9. Full Speed Mode (DCFG.DevSpd = 1)
- **Result:** WORSE — EP3 completely unconfigured (MPS=0, EPType=Control)

### 10. EP3 in DAINTMSK
- Added EP3 (bit 3) to DAINTMSK
- **Result:** EP3 appears in mask but DAINT stays 0

## Key Observations

### 1. DAINT is ALWAYS 0x00000000 for EP3
Even with EP3 in DAINTMSK, DAINT never shows EP3. This means the DWC2 hardware never generates ANY interrupt for EP3 — not XFRC, not errors, nothing.

### 2. DIEPINT3 is ALWAYS 0x00000000
Polled thousands of times over 5+ seconds per frame. Zero. Never any bit set.

### 3. DMA Works but Goes Nowhere
DIEPTSIZ3.XFRSIZ goes from 2 → 0 (DMA consumed data), but PKTCNT stays at 1 (packet was never sent). Data enters the FIFO but the packet engine doesn't pick it up.

### 4. ISO and Bulk Have Identical Failure
Switching from ISO to Bulk changes nothing. The exact same symptom — DMA works, packet engine doesn't send.

### 5. TXFSTS3 Shows 768 Words Free but DTXFSIZ3 Shows 256 Word Depth
This inconsistency is suspicious. Either the register is reading wrong, or the FIFO mapping isn't what we think.

### 6. dwc_otg_pcd_ep_enable Returns 0 but Doesn't Activate Hardware
PCD layer says "success" but the hardware never responds to IN tokens.

## Questions for Expert

1. **Why would DWC2 not generate ANY interrupt on EP3?** Even an error interrupt would be informative. The total silence suggests EP3 is simply not in the hardware's active endpoint list.

2. **Is there a separate "endpoint activation" step beyond DIEPCTL.EPEna?** Some DWC2 implementations have internal registers or mailbox commands that need to be issued to actually start the endpoint.

3. **Could the TXFSTS3 vs DTXFSIZ3 mismatch indicate a FIFO mapping problem?** TXFSTS3 shows 768 words free but DTXFSIZ3 allocates only 256 words. Is DMA writing to the wrong FIFO?

4. **Is there a way to check if the host is actually sending IN tokens for EP3?** We see SOF interrupts (host is active) but no indication that EP3 tokens arrive.

5. **Could Realtek's DWC2 customization restrict which EPs can do IN transfers?** EP0 works (control transfers succeed during enumeration). EP1 is used by UVC interrupt endpoint. EP3 is the streaming endpoint that never works.

6. **Would trying EP1 or EP2 for streaming help?** Maybe there's a hardware limitation on EP3 specifically.

7. **In Linux DWC2 gadget driver, what additional steps does `dwc2_hsotg_ep_enable` do beyond writing DIEPCTL?** We need to understand if there are internal state machines that need initialization.

## Architecture Context

```
┌─── macOS Host ───┐     USB 2.0 HS     ┌─── AMB82 Device ───┐
│                   │                     │                     │
│  Photo Booth      │  ──IN tokens──→    │  EP3 (Bulk/ISO IN)  │
│  sees "USB UVC    │                     │  DIEPCTL=0x80C88200 │
│  CLASS" device    │  ←──NO response──  │  DMA ✅ → FIFO      │
│                   │                     │  FIFO → Bus ❌      │
│  Black screen     │                     │  DIEPINT3 = 0x0     │
└───────────────────┘                     └─────────────────────┘
```

## File References
- `usb_patch.c` — ep_enable override, GAHBCFG fix, descriptor patch
- `module_uvcd.c` — manual EP3 DMA, diagnostic dumps, EP disable cycle
- `libusbd.a` — closed-source, contains dwc_otg_pcd_ep_enable (callable as extern)
