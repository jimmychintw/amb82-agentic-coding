# AMB82 UVC on macOS — DWC2 IN Endpoint Accepts DMA but Never Reaches Packet Engine

**ISO and Bulk both fail identically. Problem is below class/protocol level.**

---

## Executive Summary

EP3 IN accepts register programming and DMA submission, but **never becomes visible to the DWC2 interrupt / packet-engine path**. Failure is identical for Isochronous and Bulk transfer types, suggesting **endpoint activation or vendor wrapper state is missing** rather than transfer-type-specific timing.

Specifically:
- `DIEPTSIZ3.XFRSIZ` is consumed (DMA completed) → **payload submission happened**
- `DIEPTSIZ3.PKTCNT` never decrements → **packet issuance did not**
- `DIEPINT3` is permanently 0x00000000 → **no lifecycle events at all on EP3**
- `DAINT` never reports EP3 → **hardware does not consider EP3 active**

Therefore the problem appears to be **below class/protocol level and above raw DMA write completion** — likely in endpoint activation, token matching, or vendor-specific DWC2 wrapper state.

---

## Hardware & Software Context

| Item | Detail |
|------|--------|
| SoC | Realtek RTL8735B (ARM Cortex-A32, FreeRTOS) |
| USB Controller | Synopsys DWC2 OTG, **Buffer DMA mode** (NOT Descriptor DMA) |
| USB Driver | `libusbd.a` — Realtek closed-source binary blob |
| Host | macOS 15 (Apple Silicon M1 Pro), connected via USB 2.0 Hub |
| App | Photo Booth — selects "USB UVC CLASS", shows black screen |
| Endpoint | EP3 IN (bEndpointAddress=0x83), tested as both ISO and Bulk |

---

## Proven Facts (Hardest Evidence)

These are verified through direct register reads across hundreds of transfer attempts:

| Fact | Evidence |
|------|----------|
| USB enumeration succeeds | macOS sees device (VID 7531, PID 258), `ioreg` confirms |
| UVC PROBE/COMMIT succeeds | UART shows `streaming request`, `setting commit control` |
| SET_INTERFACE alt=1 succeeds | UART shows `set_alt interface 1 alt =1`, `stream on` |
| `dwc_otg_pcd_ep_enable()` returns 0 | Called via our `ep_enable` override with fixed gadget state |
| DIEPCTL3 register is correctly programmed | EPEna=1, CNAK, TXFNUM=3, MPS=512, EPType=Bulk, USBActEP=1 |
| DMA completes (XFRSIZ consumed) | DIEPTSIZ3 goes from `0x00080002` to `0x00080000` |
| **PKTCNT never decrements** | Stays at 1 after DMA completion |
| **DIEPINT3 = 0x00000000 always** | Polled thousands of times over 5+ seconds, never any bit set |
| **DAINT never reports EP3** | Even with EP3 in DAINTMSK (bit 3 = 1), DAINT stays 0 |
| **Identical failure with ISO and Bulk** | Changed bmAttributes 0x05→0x02, wMaxPacketSize 5120→512 — same result |

---

## Register Baseline (After Stream-On, Before First Transfer)

```
DCFG     = 0x08240040   DevSpd=0 (HS)   DescDMA=0   EPMisCnt=9→31
DCTL     = 0x00008000   IFrmNum=1   GNPINNakSts=0   SftDiscon=0   GMC=0
DSTS     = 0x0046F900   EnumSpd=0 (HS)   SOFFN=1785

GINTSTS  = 0x04008028   SOF ✓  NPTxFEmp ✓  (no IISOIXFR with Bulk)
GINTMSK  = 0xD02C3C06   IISOIXFR masked by us
DAINTMSK = 0x0001000B   EP0 IN + EP1 IN + EP3 IN + EP0 OUT

DIEPCTL3 = 0x80C88200   EPEna=1  Bulk  MPS=512  TXFNUM=3  USBActEP=1
DIEPTSIZ3= 0x00080002   MC=0  PKTCNT=1  XFRSIZ=2
DIEPDMA3 = 0x70328D00   32-byte aligned buffer
DIEPINT3 = 0x00000000   (always)
DAINT    = 0x00000000   (EP3 never appears)

GNPTXFSIZ = 0x00800200   depth=128 words  start=512
DTXFSIZ3  = 0x01000880   depth=256 words (1024 bytes)  start=2176
DTXFSTS3  = 0x00000300   768 words free (see note below)
```

**Note on TXFSTS3 inconsistency:** DTXFSIZ3 allocates 256 words but TXFSTS3 reports 768 words free. Semantics may differ from vanilla Synopsys DWC2 — should be validated against RTL8735B-specific DWC2 integration details.

---

## EP Descriptor (After In-Memory Patch, Before Enumeration)

```
BEFORE patch: 07 05 83 05 00 14 01   (ISO, wMaxPacketSize=0x1400=5120, bInterval=1)
AFTER  patch: 07 05 83 02 00 02 00   (Bulk, wMaxPacketSize=0x0200=512, bInterval=0)
```

Patch applied in `dwc_otg_enable_global_interrupts()` override, **before** host reads descriptors during enumeration. macOS `ioreg` confirms device is visible as "USB UVC CLASS".

---

## Endpoint Enable Flow (Our Override)

Original `ep_enable()` in libusbd.a fails with `"bogus device state"` because `GADGET_WRAPPER_TMP[0x14]` (gadget.speed) is 0 (`USB_SPEED_UNKNOWN`). We override `ep_enable` as a weak symbol:

```c
int ep_enable(void *usb_ep, void *ep_desc) {
    // 1. Fix gadget.speed = USB_SPEED_HIGH (0x03)
    GADGET_WRAPPER_TMP[0x14] = 0x03;
    // 2. Fix PCD pointer if NULL
    GADGET_WRAPPER_TMP[0x00] = &gpcd;
    // 3. Call the REAL internal function
    return dwc_otg_pcd_ep_enable(pcd, ep_desc, usb_ep);  // returns 0 ✓
}
```

`dwc_otg_pcd_ep_enable` is an extern symbol found in `libusbd.a` — it links and returns 0 (success). **But this "success" does not result in hardware activation.**

---

## Transfer Code (Simplified)

```c
// 0. Disable EP3 if still enabled (required between transfers)
if (DIEPCTL3 & EPEna) { DIEPCTL3 |= EPDis | SNAK; wait EPDisDone; }

// 1. Clear interrupts
DIEPINT3 = 0xFF;

// 2. Program transfer (Bulk, no MC)
DIEPTSIZ3 = (1 << 19) | 2;     // PKTCNT=1, XFRSIZ=2 bytes

// 3. Set DMA address (32-byte aligned)
DIEPDMA3 = aligned_buffer_addr;

// 4. Program DIEPCTL3 from scratch
DIEPCTL3 = EPEna | CNAK | TXFNUM(3) | EPType(Bulk) | USBActEP | MPS(512);

// 5. Poll DIEPINT3 for XFRC for 5 seconds
// Result: DIEPINT3 = 0x00000000 always. Timeout.
```

---

## All Attempted Fixes (13 Total)

| # | Fix | Result |
|---|-----|--------|
| 1 | GAHBCFG bit 0 (global interrupt enable) | Required for basic USB, doesn't fix EP3 |
| 2 | **ep_enable override + dwc_otg_pcd_ep_enable call** | **PCD returns 0 but hardware inactive** |
| 3 | Gadget state fix (speed=0x03, PCD pointer) | Enables ep_enable to succeed |
| 4 | EP descriptor ISO→Bulk patch | macOS sees Bulk, same failure |
| 5 | DCTL.IFrmNum=1 | Already set by Realtek SDK |
| 6 | Mask IISOIXFR + IPXFR in GINTMSK | Prevents ISR interference, no fix |
| 7 | DCFG.EPMisCnt = 31 (max) | No change |
| 8 | EP3 disable/re-enable between frames | **Fixed DMA on frames after #0** |
| 9 | Manual DIEPCTL3 programming (both ISO and Bulk) | Correct register values, no transmission |
| 10 | Full Speed mode (DCFG.DevSpd=1) | Worse — EP3 completely unconfigured |
| 11 | EP3 added to DAINTMSK | EP3 in mask, DAINT still 0 |
| 12 | Clear Global IN NAK (DCTL.CGNPINNAK) | NAK was already clear |
| 13 | TXFNUM=3 (TX FIFO routing) | Correct mapping, no help |

---

## Most Likely Hypotheses (Ranked)

### H1: EP3 Not Truly Activated in Hardware Scheduler / Active Endpoint List

**Confidence: HIGH**

Evidence:
- DAINT never reports EP3 (no lifecycle events)
- DIEPINT3 permanently zero (no errors, no completions, no nothing)
- PKTCNT unchanged (packet engine never attempted to send)
- ISO and Bulk both fail identically

This strongly suggests the DWC2 packet engine simply does not consider EP3 as a schedulable/token-matchable endpoint, regardless of what DIEPCTL shows.

### H2: Vendor Wrapper / Closed Blob Missing Endpoint-Specific Initialization

**Confidence: HIGH**

Evidence:
- `libusbd.a` is closed-source with Realtek wrapper
- `ep_enable` originally fails due to uninitialized gadget state
- Fixing gadget state makes `dwc_otg_pcd_ep_enable` return 0 but doesn't activate hardware
- There may be additional internal context tables, endpoint routing state, or doorbell mechanisms within the blob

### H3: Host Never Sends EP3 IN Tokens

**Confidence: MEDIUM**

Evidence for: We cannot directly confirm host-side token activity.
Evidence against: USB enumeration + SET_INTERFACE alt=1 + UVC COMMIT all succeed, and Photo Booth shows the device as selected (black screen, not "no camera"). In ISO mode, GINTSTS showed IISOIXFR (incomplete ISO IN), which implies the host WAS scheduling tokens.

**This is the most important unknown to resolve next.**

### H4: Endpoint / FIFO Mapping Inconsistency

**Confidence: LOW-MEDIUM**

TXFSTS3 reports 768 words free vs DTXFSIZ3 depth of 256 words. If DMA is writing to a different location than where the packet engine reads, data would "disappear." However, if FIFO mapping were completely wrong, we'd expect DMA to also fail or produce error interrupts.

### H5: EP3-Specific Hardware Restriction on This Platform

**Confidence: MEDIUM**

EP0 (control) works. EP1 (interrupt) appears functional. EP3 (streaming) never works. Possible that EP3 has vendor-specific restrictions in this DWC2 integration, or that the blob only initializes endpoint contexts for EP0-EP2.

### Deprioritized (Ruled Out by Bulk Test)
- ISO frame parity / even-odd
- MC (Multi-Count) settings
- IISOIXFR handling
- Microframe timing
- ISO-specific descriptor issues

---

## Key Questions for Expert

### Q1 (CRITICAL): Can an endpoint show valid DIEPCTL/DIEPTSIZ/DIEPDMA contents yet still remain absent from the internal active endpoint scheduler?

Specifically: in DWC2 Buffer DMA mode, is EPEna=1 in DIEPCTL sufficient for the packet engine to respond to host IN tokens? Or is there an additional "activation" step (internal endpoint context, doorbell, queue state) that must be completed by the PCD layer?

### Q2: In a known-good Linux DWC2 gadget implementation, what software state, FIFO association, and endpoint scheduling state are established beyond the visible DIEPCTL/DIEPTSIZ/DIEPDMA writes?

We need to understand if there are hidden state machines, active endpoint lists, or frame scheduling structures that `dwc_otg_pcd_ep_enable` should initialize but might not in this blob.

### Q3: Is there a device-side DWC2 register or debug path that can confirm token match / endpoint scheduling attempts for a specific IN endpoint?

We need to distinguish between "host never sends EP3 IN tokens" and "host sends but device doesn't respond." Any register that counts token matches, NAK responses, or scheduling attempts would be invaluable.

### Q4: Are there known vendor DWC2 integrations where only a subset of IN endpoints are fully wired for non-control traffic?

Our pattern: EP0 (control) works, EP1 (interrupt) seems functional, EP3 (streaming) completely dead. Could EP3 be restricted or uninitialized in this specific SoC integration?

### Q5: Does the TXFSTS3 vs DTXFSIZ3 mismatch suggest a FIFO routing problem?

DTXFSIZ3 allocates 256 words but TXFSTS3 shows 768 words free. Could this indicate the DMA is writing to a different FIFO than what the packet engine reads from?

---

## Recommended Next Experiments (Priority Order)

### Experiment 1: Move Streaming to EP1 or EP2

**Diagnostic value: VERY HIGH**

If EP1/EP2 works but EP3 doesn't → endpoint-specific restriction.
If EP1/EP2 also fails → generic IN endpoint activation problem.

### Experiment 2: Capture Host-Side Token Activity

**Diagnostic value: VERY HIGH**

Use `log stream --predicate 'subsystem == "com.apple.usb"' --level debug` on macOS, or a USB protocol analyzer, to confirm whether the host is actually scheduling IN tokens for EP3.

### Experiment 3: Register Snapshot Comparison

**Diagnostic value: HIGH**

Dump ALL relevant registers (DIEPCTL3, DIEPINT3, DIEPTSIZ3, DIEPDMA3, DAINTMSK, DAINT, DTXFSIZ3, TXFSTS3) at four points:
1. After `dwc_otg_pcd_ep_enable` returns 0
2. After our manual DIEPCTL3 programming
3. After DMA completes (XFRSIZ consumed)
4. After 1 second of no activity

Check if any register changes between snapshots — something might be resetting EP3 state.

### Experiment 4: Verify EP3 in DAINT After Masking All ISR Handlers

Temporarily mask ALL interrupts in GINTMSK (disable all ISR processing) and check if DAINT ever shows EP3 bit. This would confirm whether the ISR is clearing EP3 state, or if the hardware truly never generates it.

---

## Architecture Diagram

```
┌─── macOS Host ──────────────┐         ┌─── AMB82 Device (RTL8735B) ─────────────┐
│                              │  USB HS │                                          │
│  Photo Booth                 │         │  DWC2 OTG (Buffer DMA mode)              │
│  → selects "USB UVC CLASS"   │         │                                          │
│  → SET_INTERFACE alt=1  ✅   │         │  ┌─ EP3 IN ──────────────────────┐       │
│  → COMMIT streaming     ✅   │         │  │ DIEPCTL3 = 0x80C88200  ✅     │       │
│                              │         │  │ DIEPTSIZ3: XFRSIZ 2→0  ✅     │       │
│  Sends IN tokens for EP3?    │─── ? ──→│  │ DMA: memory → FIFO     ✅     │       │
│                              │         │  │ Packet engine → bus     ❌     │       │
│  ← NO DATA response         │← ─ ─ ─ │  │ DIEPINT3 = 0x00000000  ❌     │       │
│                              │         │  │ DAINT bit 3 = never    ❌     │       │
│  Result: BLACK SCREEN        │         │  └────────────────────────────────┘       │
│                              │         │                                          │
│                              │         │  ┌─ EP0 (control) ───────────────┐       │
│  ← enumeration OK       ✅  │← ─ ─ ─ │  │ Works perfectly               │       │
│  ← descriptors read     ✅  │← ─ ─ ─ │  │ DAINT reports EP0 activity    │       │
│                              │         │  └────────────────────────────────┘       │
└──────────────────────────────┘         └──────────────────────────────────────────┘
```
