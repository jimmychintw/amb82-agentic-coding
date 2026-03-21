# AMB82-MINI TinyUSB UVC+UAC Implementation Design

**Date:** 2026-03-21
**Status:** Approved
**Author:** Jimmy (PM) + Claude Code

## Problem Statement

AMB82-MINI's existing USB UVC implementation (built on Realtek's precompiled `libusbd.a`) was designed only for optical image quality tuning with PotPlayer on Windows. It does not implement standard UVC protocols — the USB endpoint initialization fails (`ep_enable, bogus device state`), preventing isochronous streaming on macOS, Linux, and most Windows applications.

**Goal:** Replace the existing USB stack with TinyUSB to create a fully standard-compliant USB composite device (UVC webcam + UAC microphone) that works cross-platform.

## Approach

**Full replacement** — bypass `libusbd.a` entirely and use TinyUSB to directly control the DWC2 OTG hardware registers. TinyUSB natively supports DWC2 controllers with 8+ verified platform ports.

### Why Not Other Approaches

- **Patching Realtek stack:** Already attempted (timing fixes, library swaps) — all failed. `libusbd.a` is a black box.
- **Hybrid (Realtek HAL + TinyUSB):** Two USB stacks on the same hardware will conflict. Unclear boundaries, hard to maintain.

## Hardware Facts

| Item | Value |
|------|-------|
| SoC | Realtek RTL8735B |
| USB OTG Controller | Synopsys DesignWare DWC2 |
| USB Base Address | `0x400C0000` |
| USB Addon Registers | `+0x30000` |
| USB Speed | High-Speed (480 Mbps) |
| Register Header | `dwc_otg_regs.h` (Synopsys HS OTG Linux Software Driver) |
| Camera Sensor | MIPI CSI |
| Audio Input | AMIC (Analog Mic) + DMIC (Digital PDM Mic) support |
| Video Pipeline | MMF2 framework (ISP -> Encoder -> Queue) |
| Audio Pipeline | MMF2 Audio Module -> PCM output |
| RTOS | FreeRTOS |
| Build System | CMake + GCC ARM toolchain |

## System Architecture

```
┌──────────────────────────────────────────────────────────┐
│                      AMB82-MINI                          │
│                                                          │
│  ┌──────────┐    ┌──────────┐    ┌────────────────────┐ │
│  │ Camera   │───>│ ISP /    │───>│ Video Frame Buffer │ │
│  │ Sensor   │    │ Encoder  │    │ (MJPEG/H264/YUV)   │ │
│  └──────────┘    └──────────┘    └─────────┬──────────┘ │
│                                            │             │
│  ┌──────────┐    ┌──────────┐              │             │
│  │ AMIC /   │───>│ Audio    │──────┐       │             │
│  │ DMIC     │    │ Module   │      │       │             │
│  └──────────┘    └──────────┘      │       │             │
│                                    ▼       ▼             │
│  ┌─────────────────────────────────────────────────────┐│
│  │              Bridge Layer                            ││
│  │  usb_uvc_bridge.c  — video frames -> TinyUSB UVC   ││
│  │  usb_uac_bridge.c  — audio PCM -> TinyUSB UAC      ││
│  │  usb_composite_init.c — init TinyUSB composite      ││
│  └──────────────────────┬──────────────────────────────┘│
│                         │                                │
│  ┌──────────────────────▼──────────────────────────────┐│
│  │                TinyUSB Stack                         ││
│  │  ┌──────────┐  ┌──────────┐  ┌───────────────────┐ ││
│  │  │ UVC      │  │ UAC      │  │ Composite Device  │ ││
│  │  │ Device   │  │ Device   │  │ Manager           │ ││
│  │  │ Class    │  │ Class    │  │                   │ ││
│  │  └────┬─────┘  └────┬─────┘  └────────┬──────────┘ ││
│  │       └──────────────┴────────────────┘             ││
│  │                      │                               ││
│  │       ┌──────────────▼─────────────────┐            ││
│  │       │  DWC2 Device Controller Driver │            ││
│  │       │  (dcd_dwc2.c — from TinyUSB)   │            ││
│  │       └──────────────┬─────────────────┘            ││
│  └──────────────────────┼──────────────────────────────┘│
│                         │                                │
│  ┌──────────────────────▼──────────────────────────────┐│
│  │     DWC2 Platform Port (NEW)                        ││
│  │  dwc2_rtl8735b.h                                    ││
│  │  • USB_OTG_REG_BASE = 0x400C0000                   ││
│  │  • PHY init via addon registers                     ││
│  │  • Clock enable, interrupt config                   ││
│  └──────────────────────┬──────────────────────────────┘│
│                    ┌────▼────┐                           │
│                    │ DWC2 HW │                           │
│                    └────┬────┘                           │
└─────────────────────────┼────────────────────────────────┘
                          │ USB Cable
                     ┌────▼────┐
                     │ PC Host │
                     └─────────┘
```

## New Modules to Write

| Module | Files | Purpose |
|--------|-------|---------|
| DWC2 Platform Port | `dwc2_rtl8735b.h` | Register base, EP count, FIFO size, PHY init |
| Board BSP | `board_amb82.c`, `board_amb82.h` | Clock enable, interrupt handler, GPIO |
| TinyUSB Config | `tusb_config.h` | TinyUSB feature flags, buffer sizes |
| USB Descriptors | `usb_descriptors.c/h` | Composite device descriptors (UVC+UAC) |
| UVC Bridge | `usb_uvc_bridge.c/h` | MMF2 video queue -> TinyUSB frame xfer |
| UAC Bridge | `usb_uac_bridge.c/h` | MMF2 audio PCM -> TinyUSB audio stream |
| Composite Init | `usb_composite_init.c/h` | Unified TinyUSB initialization |

## Reused from TinyUSB (may need minor adaptation)

- `dcd_dwc2.c` — DWC2 device controller driver. Uses direct memory-mapped register access; Realtek's HAL uses `HAL_OTG_READ32/WRITE32`. May need thin adaptation layer or minor patches for DMA/cache coherency on RTL8735B's ARM core.
- `dwc2_common.c/h` — DWC2 shared utilities
- `video_device.c/h` — UVC device class
- `audio_device.c/h` — UAC device class
- TinyUSB core (descriptor handling, control transfers, composite device management)

**Note:** The addon register block (`+0x30000`) and PHY paged registers (E0-F6) are Realtek-proprietary and not part of standard DWC2. These are handled entirely in `board_amb82.c`, not in `dcd_dwc2.c`.

## USB Composite Device Descriptor Structure

```
USB Device (VID/PID TBD)
├── Configuration 1
│   ├── IAD 0: Video Function
│   │   ├── Interface 0 — Video Control (VC)
│   │   │   └── Endpoint 0x81 (Interrupt IN, status)
│   │   └── Interface 1 — Video Streaming (VS)
│   │       ├── Alt Setting 0 — Zero bandwidth (idle)
│   │       └── Alt Setting 1 — Active streaming
│   │           └── Endpoint 0x82 (Isochronous IN)
│   │
│   └── IAD 1: Audio Function
│       ├── Interface 2 — Audio Control (AC)
│       │   ├── Input Terminal (Microphone)
│       │   └── Output Terminal (USB Streaming)
│       └── Interface 3 — Audio Streaming (AS)
│           ├── Alt Setting 0 — Zero bandwidth
│           └── Alt Setting 1 — PCM 16kHz 16-bit Mono
│               └── Endpoint 0x83 (Isochronous IN)
```

## Video Format Support

### Compressed Formats (up to 1080p)

| Format | Resolutions | FPS | Est. Bandwidth |
|--------|-------------|-----|----------------|
| MJPEG | 1920x1080 | 20 | ~3 MB/s |
| MJPEG | 1280x720 | 30 | ~2 MB/s |
| MJPEG | 640x480 | 30 | ~1 MB/s |
| H.264 | 1920x1080 | 30 | ~0.5 MB/s |
| H.264 | 1280x720 | 30 | ~0.3 MB/s |

**H.264 note:** macOS AVFoundation has limited UVC H.264 support. H.264 is a stretch goal — primary verification uses MJPEG. H.264 uses UVC 1.5 Frame-Based format descriptors.

### Uncompressed Formats (low resolution only — USB 2.0 HS bandwidth limit)

| Format | Resolutions | FPS | Est. Bandwidth | ISO wMaxPacketSize |
|--------|-------------|-----|----------------|-------------------|
| YUY2 | 320x240 | 30 | ~4.5 MB/s | 1024 x mult=1 |
| YUY2 | 640x480 | 10 | ~6 MB/s | 1024 x mult=1 |

**Note on uncompressed formats:**
- Single-transaction ISO endpoint caps at ~8 MB/s (1024 bytes x 8000 microframes/s).
- YUY2 640x480@15fps (~9 MB/s) exceeds this limit. Reduced to 10fps to fit.
- NV12 removed: not a standard UVC uncompressed format GUID. macOS may not recognize it. YUY2 is the universal uncompressed format.
- High-bandwidth ISO (mult=2/3) is possible but TinyUSB support is unverified. Revisit if needed.

### Isochronous Endpoint Configuration

| Endpoint | wMaxPacketSize | Mult | Effective BW |
|----------|---------------|------|-------------|
| 0x82 (video) | 1024 | 1 | ~8 MB/s |
| 0x83 (audio) | 32 | 1 | ~0.25 MB/s |

## Audio Specification

| Item | Value |
|------|-------|
| Class | UAC1 (universal driver-free support) |
| Sample Rate | 16kHz (optional 8kHz) |
| Bit Depth | 16-bit |
| Channels | Mono |
| Data per USB frame | 32 bytes (16kHz x 16bit x 1ms) |
| USB Bandwidth | ~32 KB/s (negligible) |

## DWC2 Platform Port Details

### Register Map (from ameba_usb.h)

```
USB_OTG_REG_BASE         = 0x400C0000
USB_OTG_GLOBAL_BASE      = +0x000
USB_OTG_DEVICE_BASE      = +0x800
USB_OTG_IN_EP_BASE       = +0x900
USB_OTG_OUT_EP_BASE      = +0xB00
USB_OTG_PCGCCTL_BASE     = +0xE00
USB_OTG_FIFO_BASE        = +0x1000
USB_OTG_ADDON_BASE       = +0x30000
```

### PHY Initialization Sequence

```
0. Enable SoC USB clock domain and power (REG_SYS_FUNC_EN / REG_SYS_CLK_CTRL)
   — Must happen before any access to 0x400C0000 or bus fault occurs
   — Reverse-engineer from Realtek HAL or libusbd.a init path
1. Enable USB APHY      (ADDON_REG_CTRL bit 14)
2. Enable USB DPHY      (ADDON_REG_CTRL bit 9)
3. Enable USB OTG       (ADDON_REG_CTRL bit 8)
4. Wait PHY clock ready (ADDON_REG_CTRL bit 5, polling)
5. Configure PHY registers (E0-F6) — Realtek-proprietary paged register protocol
6. Core soft reset       (GRSTCTL.CSftRst)
7. Force device mode     (GUSBCFG.ForceDevMode)
8. Configure FIFO sizes  (see FIFO Allocation Plan below)
```

### FIFO Allocation Plan

Exact sizes depend on GHWCFG3 total. Target allocation (assuming ~1024 words total):

| FIFO | Size (words) | Purpose |
|------|-------------|---------|
| RX FIFO | 256 | Control OUT, setup packets |
| EP0 TX FIFO | 64 | Control IN |
| EP1 TX FIFO (interrupt) | 16 | UVC status |
| EP2 TX FIFO (video ISO) | 512-1024 | UVC isochronous streaming (maximize) |
| EP3 TX FIFO (audio ISO) | 16 | UAC isochronous streaming |

If total FIFO > 1024 words, allocate surplus to EP2 TX (video).

### Hardware Parameters (to be verified by reading GHWCFG1-4)

| Parameter | Expected | Verification |
|-----------|----------|-------------|
| IN EP count | 6-8 | Read GHWCFG1 |
| OUT EP count | 6-8 | Read GHWCFG1 |
| Total FIFO size | 1024-4096 words | Read GHWCFG3 |
| DMA support | Likely yes | Read GHWCFG2 |
| HS PHY | Yes (USB 2.0 HS) | Known |

## Bridge Layer Design

### Video Bridge Data Flow

```
MMF2 Video Module                Bridge Layer                  TinyUSB
                  output_ready
ISP/Encoder ────> xQueue ──────> bridge_task() ──────> tud_video_n_frame_xfer()
                  output_recycle
ISP/Encoder <──── xQueue <────── frame_xfer_complete_cb()
```

### Audio Bridge Data Flow

```
MMF2 Audio Module                Bridge Layer                  TinyUSB
                  output_ready
AMIC/DMIC ──────> xQueue ──────> audio_bridge_task() ──> tud_audio_n_write()
                  output_recycle
Audio Module <─── xQueue <────── audio write complete
```

### Format Switching (Probe/Commit)

When host selects a different format via UVC Probe/Commit:

1. Parse requested format + resolution + fps
2. Stop current video channel
3. Reconfigure MMF2: `CMD_VIDEO_SET_PARAMS` -> `CMD_VIDEO_APPLY`
4. Restart video channel
5. Bridge task begins sending new format frames

### Buffer Management

| Item | Value |
|------|-------|
| Frame buffer count | 3 (triple buffering) |
| MJPEG 1080p buffer | ~200 KB |
| H.264 1080p buffer | ~50 KB |
| YUV 480p buffer | ~600 KB |
| Audio buffer | ~512 bytes |

Buffers are allocated by MMF2. Bridge layer passes pointers only — no data copy.

## Validation Strategy

### Phase 0: DWC2 Port Verification

1. Initialize PHY + DWC2
2. Read GHWCFG1-4 registers to confirm hardware capabilities
3. Enumerate as a simple CDC device
4. Verify on macOS: `system_profiler SPUSBDataType` shows device

**CDC first, not UVC.** CDC is the simplest USB class — proves the port works before adding complexity.

### Phase 1: UVC Verification

1. Add UVC descriptors (MJPEG 640x480 only)
2. Send static test pattern (color bars)
3. Verify on macOS: Photo Booth / QuickTime shows video
4. Add remaining formats and resolutions
5. Connect to MMF2 video pipeline

### Phase 2: UAC Verification

1. Add UAC descriptors to composite device
2. Send sine wave test tone
3. Verify on macOS: System Preferences > Sound shows input device
4. Connect to MMF2 audio pipeline

### Phase 3: Integration Testing

1. UVC + UAC simultaneous operation
2. Format switching under streaming
3. Hot plug/unplug stability
4. Cross-platform verification (Windows/Linux if available)

## FreeRTOS Integration

TinyUSB requires `tud_task()` to be called regularly to process USB events.

### Task Model

```
tusb_config.h:
  CFG_TUSB_OS = OPT_OS_FREERTOS

Tasks:
  1. usb_device_task (high priority)
     — Calls tud_task() in a loop
     — Signaled from USB ISR via xSemaphoreGiveFromISR()

  2. video_bridge_task (normal priority)
     — Reads MMF2 video queue, calls tud_video_n_frame_xfer()

  3. audio_bridge_task (normal priority)
     — Reads MMF2 audio queue, calls tud_audio_n_write()
```

USB ISR calls `tud_int_handler()` and gives semaphore to wake `usb_device_task`.

### USB IRQ

IRQ number: to be discovered in Phase 0 from CMSIS device header (`rtl8735b.h` interrupt vector table) or by tracing Realtek HAL's `InterruptRegister()` call for USB.

## Key Risks

| Risk | Mitigation |
|------|-----------|
| dcd_dwc2.c register access mismatch | Realtek uses HAL_OTG_READ32/WRITE32 vs TinyUSB direct dereference. May need thin wrapper or verify direct access works at 0x400C0000 |
| SoC clock/power gating | Must enable USB clock domain before any register access. Reverse-engineer from Realtek HAL. High uncertainty — Phase 0 blocker |
| DWC2 FIFO configuration wrong | Read GHWCFG registers first; start with small EP sizes; follow FIFO allocation plan |
| PHY init sequence incomplete | Extract from Realtek HAL; add debug logging at each step |
| H.264 UVC on macOS | macOS has limited support. Treat as stretch goal; verify with MJPEG first |
| TinyUSB UVC class missing features | MJPEG is well-tested; H.264 uses Frame-Based format which is standard |
| Memory constraints | AMB82 has sufficient SRAM; buffers managed by MMF2 |
| USB interrupt conflict with other peripherals | Dedicate USB IRQ; verify NVIC priority |
| DMA/cache coherency | RTL8735B ARM core may need cache management for DMA buffers. Verify with `CFG_TUSB_MEM_SECTION` |

## File Organization

```
freertos_uvc_tinyusb/
├── src/
│   ├── app_example.c              # Entry point
│   ├── usb_composite_init.c/h     # TinyUSB composite device init
│   ├── usb_descriptors.c/h        # All USB descriptors
│   ├── usb_uvc_bridge.c/h         # Video pipeline bridge
│   ├── usb_uac_bridge.c/h         # Audio pipeline bridge
│   ├── tusb_config.h              # TinyUSB configuration
│   ├── board_amb82.c/h            # BSP: clock, PHY, IRQ
│   └── dwc2_rtl8735b.h            # DWC2 platform port
├── lib/
│   └── tinyusb/                   # TinyUSB source (git submodule)
├── build.sh                       # Build script
└── CMakeLists.txt                 # Build configuration
```

### Build Integration

- Hooks into Ameba SDK build system (same pattern as `freertos_uvc/` and `freertos_blink/`)
- Reuses SDK linker script and memory layout
- Links against MMF2, ISP, audio SDK libraries
- **Explicitly excludes `libusbd.a`** from link — TinyUSB replaces it entirely
- TinyUSB sources compiled directly into the project (not as a prebuilt library)

### VID/PID

For development: use TinyUSB default test VID `0xCafe` with a unique PID. For production, use Realtek's official VID or apply for one via pid.codes.

### USB Suspend/Resume

TinyUSB provides `tud_suspend_cb()` and `tud_resume_cb()`. Bridge layer must pause/resume MMF2 video and audio pipelines accordingly. Not critical for Phase 0-2 but must be implemented for Phase 3 stability testing.
