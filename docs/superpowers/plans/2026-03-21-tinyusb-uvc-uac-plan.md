# TinyUSB UVC+UAC for AMB82-MINI Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Replace AMB82-MINI's broken Realtek USB stack with TinyUSB to create a standard-compliant USB composite device (UVC webcam + UAC microphone) on the DWC2 OTG controller.

**Architecture:** TinyUSB directly controls the Synopsys DWC2 OTG hardware at `0x400C0000`, bypassing `libusbd.a`. A bridge layer connects the existing MMF2 video/audio pipelines to TinyUSB's UVC and UAC device classes. FreeRTOS tasks handle USB event processing, video frame transfer, and audio streaming independently.

**Tech Stack:** TinyUSB (USB stack), FreeRTOS (RTOS), Ameba SDK (MMF2 media framework, ISP, audio), CMake + GCC ARM toolchain, Synopsys DWC2 OTG controller.

**Spec:** `docs/superpowers/specs/2026-03-21-tinyusb-uvc-uac-design.md`

---

## File Map

| File | Responsibility |
|------|---------------|
| `freertos_uvc_tinyusb/src/tusb_config.h` | TinyUSB feature flags, DWC2 mode, buffer sizes |
| `freertos_uvc_tinyusb/src/dwc2_rtl8735b.h` | DWC2 platform port: register base, EP count, FIFO, PHY functions |
| `freertos_uvc_tinyusb/src/board_amb82.c` | BSP: SoC clock enable, PHY init sequence, USB IRQ handler |
| `freertos_uvc_tinyusb/src/board_amb82.h` | BSP header |
| `freertos_uvc_tinyusb/src/usb_descriptors.c` | Device/config/string descriptors, UVC+UAC composite |
| `freertos_uvc_tinyusb/src/usb_descriptors.h` | Descriptor constants, interface/endpoint numbers |
| `freertos_uvc_tinyusb/src/usb_uvc_bridge.c` | Video bridge: MMF2 queue -> tud_video_n_frame_xfer() |
| `freertos_uvc_tinyusb/src/usb_uvc_bridge.h` | Video bridge header |
| `freertos_uvc_tinyusb/src/usb_uac_bridge.c` | Audio bridge: MMF2 audio -> tud_audio_n_write() |
| `freertos_uvc_tinyusb/src/usb_uac_bridge.h` | Audio bridge header |
| `freertos_uvc_tinyusb/src/app_example.c` | Entry point: create FreeRTOS tasks, init TinyUSB |
| `freertos_uvc_tinyusb/src/media_uvcd_tinyusb.cmake` | CMake build config for Ameba SDK integration |
| `freertos_uvc_tinyusb/build.sh` | Build script (same pattern as freertos_blink/) |
| `freertos_uvc_tinyusb/lib/tinyusb/` | TinyUSB source (git submodule) |

---

## Phase 0: DWC2 Port + CDC Verification

Goal: Prove TinyUSB can talk to the DWC2 hardware. CDC device enumerates on macOS.

---

### Task 1: Project Scaffold and TinyUSB Integration

**Files:**
- Create: `freertos_uvc_tinyusb/build.sh`
- Create: `freertos_uvc_tinyusb/src/app_example.c`
- Create: `freertos_uvc_tinyusb/src/media_uvcd_tinyusb.cmake`
- Create: `freertos_uvc_tinyusb/lib/tinyusb/` (git submodule)

- [ ] **Step 1: Create project directory structure**

```bash
mkdir -p /Users/jimmy/Projects/amb82_agentic_coding/freertos_uvc_tinyusb/src
mkdir -p /Users/jimmy/Projects/amb82_agentic_coding/freertos_uvc_tinyusb/lib
```

- [ ] **Step 2: Add TinyUSB as git submodule (pin specific version)**

```bash
cd /Users/jimmy/Projects/amb82_agentic_coding
git submodule add https://github.com/hathach/tinyusb.git freertos_uvc_tinyusb/lib/tinyusb
cd freertos_uvc_tinyusb/lib/tinyusb
git checkout 0.17.0  # Pin to known stable release — verify tag exists, use latest stable
cd ../../..
```

- [ ] **Step 2b: Verify TinyUSB DWC2 port interface**

Read `freertos_uvc_tinyusb/lib/tinyusb/src/portable/synopsys/dwc2/` to confirm:
- Exact `dwc2_controller_t` struct fields (may vary between versions)
- Required platform functions (`dwc2_phy_init`, `dwc2_int_set`, etc.)
- How the port header is included (check `#if CFG_TUSB_MCU == ...` in `dcd_dwc2.c`)
- Whether `dwc2_common.c` exists and needs compilation

**This is a hard gate** — all subsequent code depends on the exact TinyUSB API.

- [ ] **Step 3: Create build.sh**

Based on `freertos_blink/build.sh` pattern. Key differences:
- `EXAMPLE_NAME=media_uvcd_tinyusb`
- Link against MMF2, video, audio SDK libraries
- **Exclude** `libusbd.a` from link
- Add TinyUSB source files to compilation

```bash
#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
SDK_ROOT="${SCRIPT_DIR}/../amb82_Info/ameba-rtos-pro2"
GCC_RELEASE="${SDK_ROOT}/project/realtek_amebapro2_v0_example/GCC-RELEASE"
BUILD_DIR="${GCC_RELEASE}/build"
EXAMPLE_NAME="media_uvcd_tinyusb"

# Symlink source to SDK example directory
EXAMPLE_LINK="${SDK_ROOT}/component/example/${EXAMPLE_NAME}"

if [ "$1" = "clean" ]; then
    echo "Cleaning build..."
    rm -rf "${BUILD_DIR}"
    rm -f "${EXAMPLE_LINK}"
    echo "Done."
    exit 0
fi

if [ ! -L "${EXAMPLE_LINK}" ]; then
    echo "Linking example: ${SCRIPT_DIR}/src -> ${EXAMPLE_LINK}"
    ln -sf "${SCRIPT_DIR}/src" "${EXAMPLE_LINK}"
fi

# Build
echo "Building TinyUSB UVC+UAC example..."
echo "  SDK: ${SDK_ROOT}"
echo "  Build dir: ${BUILD_DIR}"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

cmake .. -G "Unix Makefiles" \
    -DCMAKE_TOOLCHAIN_FILE="${GCC_RELEASE}/toolchain.cmake" \
    -DEXAMPLE=${EXAMPLE_NAME}

cmake --build . -- -j$(sysctl -n hw.ncpu 2>/dev/null || nproc)

echo ""
echo "Build complete!"
if [ -f "flash_ntz.bin" ]; then
    SIZE=$(du -h flash_ntz.bin | cut -f1)
    echo "  Binary: flash_ntz.bin (${SIZE})"
fi
```

- [ ] **Step 4: Create minimal app_example.c**

```c
#include "FreeRTOS.h"
#include "task.h"
#include "platform_stdlib.h"

// Minimal entry point — will be expanded later
void example_media_uvcd_tinyusb(void)
{
    printf("[TinyUSB] Project scaffold OK\n");
}
```

- [ ] **Step 5: Create media_uvcd_tinyusb.cmake**

```cmake
### TinyUSB source files ###
set(TINYUSB_ROOT ${CMAKE_CURRENT_LIST_DIR}/../../lib/tinyusb)

list(APPEND app_example_lib)

list(APPEND app_example_flags
    -DCFG_TUSB_MCU=OPT_MCU_NONE
)

list(APPEND app_example_inc_path
    ${TINYUSB_ROOT}/src
    ${CMAKE_CURRENT_LIST_DIR}
)

list(APPEND app_example_sources
    app_example.c
)
list(TRANSFORM app_example_sources PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

### TinyUSB core sources ###
list(APPEND app_example_sources
    ${TINYUSB_ROOT}/src/tusb.c
    ${TINYUSB_ROOT}/src/common/tusb_fifo.c
    ${TINYUSB_ROOT}/src/device/usbd.c
    ${TINYUSB_ROOT}/src/device/usbd_control.c
    ${TINYUSB_ROOT}/src/portable/synopsys/dwc2/dcd_dwc2.c
    ${TINYUSB_ROOT}/src/portable/synopsys/dwc2/dwc2_common.c
    ${TINYUSB_ROOT}/src/class/cdc/cdc_device.c
)

### IMPORTANT: Exclude Realtek libusbd.a to avoid symbol conflicts ###
### If the SDK auto-includes libusbd.cmake, create an empty override: ###
### touch ${SDK_ROOT}/component/usb/usb_class/device/class/uvc/libusbd.cmake ###
```

- [ ] **Step 6: Verify build compiles (expect link errors for missing USB functions — that's OK)**

```bash
cd /Users/jimmy/Projects/amb82_agentic_coding/freertos_uvc_tinyusb
bash build.sh 2>&1 | tail -20
```

Expected: Compilation proceeds, may have link errors for missing `tusb_config.h` or board functions. This confirms the build pipeline works.

- [ ] **Step 7: Commit**

```bash
git add freertos_uvc_tinyusb/
git commit -m "feat: scaffold freertos_uvc_tinyusb project with TinyUSB submodule"
```

---

### Task 2: DWC2 Platform Port Header

**Files:**
- Create: `freertos_uvc_tinyusb/src/dwc2_rtl8735b.h`

**Reference docs:**
- Realtek USB HAL: `ameba-rtos-pro2/component/usb/common_new/ameba_usb.h`
- DWC2 registers: `ameba-arduino-pro2/.../usb_otg/dwc_otg_regs.h`
- TinyUSB DWC2 examples: `tinyusb/src/portable/synopsys/dwc2/dwc2_stm32.h`

- [ ] **Step 1: Create dwc2_rtl8735b.h with controller definition**

```c
#ifndef DWC2_RTL8735B_H
#define DWC2_RTL8735B_H

#ifdef __cplusplus
extern "C" {
#endif

#include "dwc2_common.h"

// RTL8735B USB OTG register base address
#define USB_OTG_REG_BASE        0x400C0000UL

// Addon register offsets (Realtek-proprietary, relative to USB_OTG_REG_BASE)
#define USB_OTG_ADDON_BASE      0x30000UL
#define USB_OTG_ADDON_REG_CTRL  0x30004UL

// Addon control bits
#define ADDON_CTRL_UPLL_CKRDY   (1U << 5)   // PHY clock ready (read-only)
#define ADDON_CTRL_USB_OTG_RST  (1U << 8)   // Enable USB OTG core
#define ADDON_CTRL_USB_DPHY_FEN (1U << 9)   // Enable USB digital PHY
#define ADDON_CTRL_USB_APHY_EN  (1U << 14)  // Enable USB analog PHY

// HP_OTG_FUNC_CLK_CTRL register (SoC-level clock/power control)
#define HP_OTG_FUNC_CLK_CTRL   (0x50000000UL + 0x0800UL + 0x0120UL)
#define FUNC_CLK_OTG_EN        (1U << 0)
#define FUNC_CLK_OTG_CLK_EN    (1U << 4)
#define FUNC_CLK_UTMI_CLK_EN   (1U << 5)
#define FUNC_CLK_USBOTG_EN     (1U << 8)
#define FUNC_CLK_USBPHY_EN     (1U << 9)

// USB PHY paged registers (Realtek-proprietary indirect access)
#define USB_PHY_REG_E0          0xE0U
#define USB_PHY_REG_E1          0xE1U
#define USB_PHY_REG_E2          0xE2U
#define USB_PHY_REG_E4          0xE4U
#define USB_PHY_REG_E6          0xE6U
#define USB_PHY_REG_E7          0xE7U
#define USB_PHY_REG_F1          0xF1U
#define USB_PHY_REG_F4          0xF4U  // Page selector
#define USB_PHY_REG_F6          0xF6U

// USB IRQ number (from rtl8735b.h CMSIS)
#define USB_OTG_IRQn            25

// DWC2 controller configuration
// Note: EP count and FIFO size are estimated; Phase 0 reads GHWCFG1-4 to confirm
static const dwc2_controller_t dwc2_controller[] = {
    {
        .reg_base   = USB_OTG_REG_BASE,
        .irqnum     = USB_OTG_IRQn,
        .ep_count   = 8,            // Verify via GHWCFG1
        .ep_in_count = 8,           // Verify via GHWCFG1
        .ep_fifo_size = 4096,       // Verify via GHWCFG3 (in bytes)
    }
};

// PHY init/deinit — implemented in board_amb82.c
void dwc2_phy_init(uint8_t rhport);
void dwc2_phy_update(uint8_t rhport);
void dwc2_phy_deinit(uint8_t rhport);
void dwc2_int_set(uint8_t rhport, bool en);

// Optional: DMA cache management (if DMA enabled)
// void dwc2_dcache_clean(void *addr, uint32_t size);
// void dwc2_dcache_invalidate(void *addr, uint32_t size);
// void dwc2_dcache_clean_invalidate(void *addr, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif // DWC2_RTL8735B_H
```

- [ ] **Step 2: Verify header compiles with TinyUSB**

Add `#include "dwc2_rtl8735b.h"` to app_example.c and rebuild. Fix any type/include issues.

- [ ] **Step 3: Commit**

```bash
git add freertos_uvc_tinyusb/src/dwc2_rtl8735b.h
git commit -m "feat: add DWC2 platform port header for RTL8735B"
```

---

### Task 3: Board BSP — Clock, PHY Init, IRQ

**Files:**
- Create: `freertos_uvc_tinyusb/src/board_amb82.h`
- Create: `freertos_uvc_tinyusb/src/board_amb82.c`

**Reference docs:**
- `ameba-rtos-pro2/component/usb/common_new/ameba_usb.h` — addon register bit definitions
- `ameba-arduino-pro2/.../dwc_otg_regs.h` — HP_OTG_FUNC_CLK_CTRL_REG, HP_OTG_PWR_CTRL_REG
- `ameba-rtos-pro2/component/soc/8735b/cmsis/rtl8735b/include/rtl8735b.h` — USB_IRQn = 25

- [ ] **Step 1: Create board_amb82.h**

```c
#ifndef BOARD_AMB82_H
#define BOARD_AMB82_H

#include <stdint.h>
#include <stdbool.h>

// Board-level init (called before tusb_init)
void board_init(void);

// Called after tusb_init completes
void board_init_after_tusb(void);

// Debug: read and print GHWCFG1-4 registers to discover hardware capabilities
void board_usb_print_hwcfg(void);

#endif // BOARD_AMB82_H
```

- [ ] **Step 2: Create board_amb82.c with SoC clock enable**

```c
#include "board_amb82.h"
#include "dwc2_rtl8735b.h"
#include "FreeRTOS.h"
#include "task.h"

// Direct register access macros
#define REG32(addr)  (*(volatile uint32_t *)(addr))

//--------------------------------------------------------------------
// Step 0: SoC-level clock and power domain enable
//--------------------------------------------------------------------
static void usb_clock_enable(void)
{
    uint32_t val;

    // Enable OTG function clock (HP_OTG_FUNC_CLK_CTRL)
    val = REG32(HP_OTG_FUNC_CLK_CTRL);
    val |= FUNC_CLK_OTG_EN | FUNC_CLK_OTG_CLK_EN | FUNC_CLK_UTMI_CLK_EN;
    val |= FUNC_CLK_USBOTG_EN | FUNC_CLK_USBPHY_EN;
    REG32(HP_OTG_FUNC_CLK_CTRL) = val;

    // Brief delay for clock stabilization
    vTaskDelay(pdMS_TO_TICKS(10));

    printf("[USB] Clock domain enabled, FUNC_CLK_CTRL=0x%08lx\n",
           REG32(HP_OTG_FUNC_CLK_CTRL));
}

//--------------------------------------------------------------------
// PHY initialization (Realtek-proprietary addon + paged registers)
//--------------------------------------------------------------------
static void usb_phy_write(uint8_t reg, uint8_t val)
{
    // Realtek PHY register write via addon indirect access
    // TODO: Reverse-engineer exact write protocol from HAL
    // This is a placeholder — the actual mechanism uses addon registers
    // to perform paged writes to PHY registers E0-F6
    (void)reg;
    (void)val;
    printf("[USB PHY] Write reg 0x%02x = 0x%02x (TODO: implement)\n", reg, val);
}

void dwc2_phy_init(uint8_t rhport)
{
    (void)rhport;

    // Step 1: Enable analog PHY
    uint32_t ctrl = REG32(USB_OTG_REG_BASE + USB_OTG_ADDON_REG_CTRL);
    ctrl |= ADDON_CTRL_USB_APHY_EN;
    REG32(USB_OTG_REG_BASE + USB_OTG_ADDON_REG_CTRL) = ctrl;

    // Step 2: Enable digital PHY
    ctrl |= ADDON_CTRL_USB_DPHY_FEN;
    REG32(USB_OTG_REG_BASE + USB_OTG_ADDON_REG_CTRL) = ctrl;

    // Step 3: Enable USB OTG core
    ctrl |= ADDON_CTRL_USB_OTG_RST;
    REG32(USB_OTG_REG_BASE + USB_OTG_ADDON_REG_CTRL) = ctrl;

    // Step 4: Wait for PHY clock ready
    int timeout = 1000;
    while (!(REG32(USB_OTG_REG_BASE + USB_OTG_ADDON_REG_CTRL) & ADDON_CTRL_UPLL_CKRDY)) {
        if (--timeout == 0) {
            printf("[USB] ERROR: PHY clock not ready!\n");
            return;
        }
        vTaskDelay(pdMS_TO_TICKS(1));
    }
    printf("[USB] PHY clock ready\n");

    // Step 5: Configure PHY registers (E0-F6)
    // TODO: Reverse-engineer exact values from Realtek HAL
    // usb_phy_write(USB_PHY_REG_E0, 0x??);
    // usb_phy_write(USB_PHY_REG_E1, 0x??);
    // ...

    printf("[USB] PHY init complete\n");
}

void dwc2_phy_update(uint8_t rhport)
{
    (void)rhport;
    // Called after GRSTCTL soft reset — re-apply PHY settings if needed
}

void dwc2_phy_deinit(uint8_t rhport)
{
    (void)rhport;
    uint32_t ctrl = REG32(USB_OTG_REG_BASE + USB_OTG_ADDON_REG_CTRL);
    ctrl &= ~(ADDON_CTRL_USB_APHY_EN | ADDON_CTRL_USB_DPHY_FEN | ADDON_CTRL_USB_OTG_RST);
    REG32(USB_OTG_REG_BASE + USB_OTG_ADDON_REG_CTRL) = ctrl;
}

//--------------------------------------------------------------------
// USB interrupt enable/disable
//--------------------------------------------------------------------
void dwc2_int_set(uint8_t rhport, bool en)
{
    (void)rhport;
    if (en) {
        // Prefer Realtek's HAL if available:
        // InterruptRegister((IRQ_FUN)usb_irq_handler, USB_OTG_IRQn, NULL, 5);
        // InterruptEn(USB_OTG_IRQn, 5);
        // Fallback to raw NVIC:
        NVIC_SetPriority(USB_OTG_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_EnableIRQ(USB_OTG_IRQn);
    } else {
        NVIC_DisableIRQ(USB_OTG_IRQn);
    }
}

//--------------------------------------------------------------------
// USB IRQ handler — calls TinyUSB interrupt handler
//--------------------------------------------------------------------
// Note: Realtek SDK uses InterruptRegister() for IRQ registration,
// not weak-linked vector table names. Register in board_init():
//   InterruptRegister((IRQ_FUN)usb_irq_handler, USB_OTG_IRQn, NULL, 5);
//   InterruptEn(USB_OTG_IRQn, 5);
// If InterruptRegister is not available, fall back to NVIC directly.
static void usb_irq_handler(void *data)
{
    (void)data;
    extern void tusb_int_handler(uint8_t rhport, bool in_isr);
    tusb_int_handler(0, true);
}

//--------------------------------------------------------------------
// Board init
//--------------------------------------------------------------------
void board_init(void)
{
    printf("[Board] AMB82 USB board init\n");
    usb_clock_enable();
}

void board_init_after_tusb(void)
{
    printf("[Board] Post-TinyUSB init complete\n");
}

//--------------------------------------------------------------------
// Debug: print hardware configuration registers
//--------------------------------------------------------------------
void board_usb_print_hwcfg(void)
{
    volatile uint32_t *global_regs = (volatile uint32_t *)USB_OTG_REG_BASE;

    // GHWCFG1 @ offset 0x44, GHWCFG2 @ 0x48, GHWCFG3 @ 0x4C, GHWCFG4 @ 0x50
    uint32_t ghwcfg1 = global_regs[0x44 / 4];
    uint32_t ghwcfg2 = global_regs[0x48 / 4];
    uint32_t ghwcfg3 = global_regs[0x4C / 4];
    uint32_t ghwcfg4 = global_regs[0x50 / 4];

    printf("[USB HWCFG] GHWCFG1=0x%08lx GHWCFG2=0x%08lx GHWCFG3=0x%08lx GHWCFG4=0x%08lx\n",
           ghwcfg1, ghwcfg2, ghwcfg3, ghwcfg4);

    // Decode key fields
    uint32_t num_dev_ep = ((ghwcfg2 >> 10) & 0xF);  // Bits 13:10
    uint32_t num_dev_in_ep = ((ghwcfg4 >> 26) & 0xF); // Bits 29:26 (some DWC2 variants)
    uint32_t dfifo_depth = (ghwcfg3 >> 16) & 0xFFFF;  // Bits 31:16 = DFIFO depth in words

    printf("[USB HWCFG] Dev EP count=%lu, Dev IN EP=%lu, DFIFO depth=%lu words (%lu bytes)\n",
           num_dev_ep, num_dev_in_ep, dfifo_depth, dfifo_depth * 4);
}
```

- [ ] **Step 3: Add PHY register write protocol reference**

The PHY paged register write mechanism must be reverse-engineered from:
- `ameba-rtos-pro2/component/usb/common_new/ameba_usb.h` — look for `USB_PHY_Write()` / `USB_PHY_Read()`
- `ameba-arduino-pro2/.../usb_otg/dwc_otg_regs.h` — look for `hp_otg_func_ctrl_t` struct to verify bit positions for `HP_OTG_FUNC_CLK_CTRL`
- Trace `_usb_init()` call in `module_uvcd.c` to find the full init chain

Update `usb_phy_write()` with actual implementation once protocol is understood.

- [ ] **Step 4: Verify it compiles**

Rebuild. Fix any missing includes (NVIC/InterruptRegister from CMSIS/Realtek HAL headers).

- [ ] **Step 5: CHECKPOINT — Flash and verify PHY clock ready**

Flash firmware with only `board_init()` + debug output. Monitor serial:
```
[USB] Clock domain enabled, FUNC_CLK_CTRL=0x????????
[USB] PHY clock ready
```

**This is a hard gate.** If PHY clock does not become ready:
- Verify `HP_OTG_FUNC_CLK_CTRL` bit positions against actual `hp_otg_func_ctrl_t` struct
- Check if additional SoC power domain enables are needed
- Do NOT proceed to Task 4 until this passes

- [ ] **Step 6: Commit**

```bash
git add freertos_uvc_tinyusb/src/board_amb82.*
git commit -m "feat: add board BSP with USB clock enable and PHY init for RTL8735B"
```

---

### Task 4: TinyUSB Config + CDC Descriptors (Minimal Enumeration Test)

**Files:**
- Create: `freertos_uvc_tinyusb/src/tusb_config.h`
- Create: `freertos_uvc_tinyusb/src/usb_descriptors.h`
- Create: `freertos_uvc_tinyusb/src/usb_descriptors.c`
- Modify: `freertos_uvc_tinyusb/src/app_example.c`
- Modify: `freertos_uvc_tinyusb/src/media_uvcd_tinyusb.cmake`

- [ ] **Step 1: Create tusb_config.h for CDC-only (Phase 0)**

```c
#ifndef TUSB_CONFIG_H
#define TUSB_CONFIG_H

//--------------------------------------------------------------------
// Common
//--------------------------------------------------------------------
#define CFG_TUSB_MCU              OPT_MCU_NONE  // Custom port
#define CFG_TUSB_OS               OPT_OS_FREERTOS
#define CFG_TUSB_MEM_ALIGN        __attribute__((aligned(4)))

//--------------------------------------------------------------------
// Device
//--------------------------------------------------------------------
#define CFG_TUD_ENABLED           1
#define CFG_TUD_MAX_SPEED         OPT_MODE_HIGH_SPEED

// Endpoint 0 max packet size
#define CFG_TUD_ENDPOINT0_SIZE    64

//--------------------------------------------------------------------
// Phase 0: CDC only (for enumeration test)
//--------------------------------------------------------------------
#define CFG_TUD_CDC               1
#define CFG_TUD_CDC_RX_BUFSIZE    256
#define CFG_TUD_CDC_TX_BUFSIZE    256

//--------------------------------------------------------------------
// Phase 1: UVC (uncomment when CDC works)
//--------------------------------------------------------------------
// #define CFG_TUD_VIDEO             1
// #define CFG_TUD_VIDEO_STREAMING   1
// #define CFG_TUD_VIDEO_STREAMING_EP_BUFSIZE  1024

//--------------------------------------------------------------------
// Phase 2: UAC (uncomment when UVC works)
//--------------------------------------------------------------------
// #define CFG_TUD_AUDIO             1

#endif // TUSB_CONFIG_H
```

- [ ] **Step 2: Create usb_descriptors.h**

```c
#ifndef USB_DESCRIPTORS_H
#define USB_DESCRIPTORS_H

// Development VID/PID
#define USB_VID   0xCafe
#define USB_PID   0x4000  // TinyUSB test PID

// String descriptor indices
enum {
    STRID_LANGID = 0,
    STRID_MANUFACTURER,
    STRID_PRODUCT,
    STRID_SERIAL,
};

// Interface numbers (Phase 0: CDC only)
enum {
    ITF_NUM_CDC = 0,
    ITF_NUM_CDC_DATA,
    ITF_NUM_TOTAL
};

// Endpoint numbers
#define EPNUM_CDC_NOTIF   0x81
#define EPNUM_CDC_OUT     0x02
#define EPNUM_CDC_IN      0x82

#endif // USB_DESCRIPTORS_H
```

- [ ] **Step 3: Create usb_descriptors.c**

```c
#include "tusb.h"
#include "usb_descriptors.h"

//--------------------------------------------------------------------
// Device Descriptor
//--------------------------------------------------------------------
tusb_desc_device_t const desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,  // USB 2.0
    .bDeviceClass       = TUSB_CLASS_MISC,
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor           = USB_VID,
    .idProduct          = USB_PID,
    .bcdDevice          = 0x0100,
    .iManufacturer      = STRID_MANUFACTURER,
    .iProduct           = STRID_PRODUCT,
    .iSerialNumber      = STRID_SERIAL,
    .bNumConfigurations = 1,
};

uint8_t const *tud_descriptor_device_cb(void)
{
    return (uint8_t const *)&desc_device;
}

//--------------------------------------------------------------------
// Configuration Descriptor (Phase 0: CDC only)
//--------------------------------------------------------------------
#define CONFIG_TOTAL_LEN  (TUD_CONFIG_DESC_LEN + TUD_CDC_DESC_LEN)

uint8_t const desc_configuration[] = {
    TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, 0x00, 100),
    TUD_CDC_DESCRIPTOR(ITF_NUM_CDC, 4, EPNUM_CDC_NOTIF, 8, EPNUM_CDC_OUT, EPNUM_CDC_IN, 64),
};

uint8_t const *tud_descriptor_configuration_cb(uint8_t index)
{
    (void)index;
    return desc_configuration;
}

//--------------------------------------------------------------------
// String Descriptors
//--------------------------------------------------------------------
static char const *string_desc_arr[] = {
    [STRID_LANGID]       = (const char[]){ 0x09, 0x04 },  // English
    [STRID_MANUFACTURER] = "Realtek",
    [STRID_PRODUCT]      = "AMB82-MINI USB Device",
    [STRID_SERIAL]       = "123456",
};

static uint16_t _desc_str[32 + 1];

uint16_t const *tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    (void)langid;
    size_t chr_count;

    switch (index) {
        case STRID_LANGID:
            memcpy(&_desc_str[1], string_desc_arr[0], 2);
            chr_count = 1;
            break;
        default:
            if (index >= sizeof(string_desc_arr) / sizeof(string_desc_arr[0]))
                return NULL;

            const char *str = string_desc_arr[index];
            chr_count = strlen(str);
            if (chr_count > 31) chr_count = 31;

            for (size_t i = 0; i < chr_count; i++) {
                _desc_str[1 + i] = str[i];
            }
            break;
    }

    _desc_str[0] = (uint16_t)((TUSB_DESC_STRING << 8) | (2 * chr_count + 2));
    return _desc_str;
}
```

- [ ] **Step 4: Update app_example.c with FreeRTOS + TinyUSB init**

```c
#include "FreeRTOS.h"
#include "task.h"
#include "tusb.h"
#include "board_amb82.h"

#define USBD_STACK_SIZE  4096

static StackType_t usb_device_stack[USBD_STACK_SIZE];
static StaticTask_t usb_device_taskdef;

// USB device task — processes TinyUSB events
static void usb_device_task(void *param)
{
    (void)param;

    // Init TinyUSB
    tusb_rhport_init_t rh_init = {
        .role  = TUSB_ROLE_DEVICE,
        .speed = TUSB_SPEED_AUTO,
    };
    tusb_init(0, &rh_init);
    board_init_after_tusb();

    // Print hardware config for Phase 0 verification
    board_usb_print_hwcfg();

    printf("[TinyUSB] Device task running\n");

    while (1) {
        tud_task();
        // For CDC: echo back received data
        if (tud_cdc_available()) {
            uint8_t buf[64];
            uint32_t count = tud_cdc_read(buf, sizeof(buf));
            tud_cdc_write(buf, count);
            tud_cdc_write_flush();
        }
    }
}

// TinyUSB callbacks
void tud_mount_cb(void)     { printf("[TinyUSB] Device mounted\n"); }
void tud_umount_cb(void)    { printf("[TinyUSB] Device unmounted\n"); }
void tud_suspend_cb(bool remote_wakeup_en) {
    (void)remote_wakeup_en;
    printf("[TinyUSB] Suspended\n");
}
void tud_resume_cb(void)    { printf("[TinyUSB] Resumed\n"); }

// Entry point
void example_media_uvcd_tinyusb(void)
{
    printf("[TinyUSB] Starting AMB82 USB device...\n");

    board_init();

    xTaskCreateStatic(
        usb_device_task, "usbd",
        USBD_STACK_SIZE, NULL,
        configMAX_PRIORITIES - 1,
        usb_device_stack, &usb_device_taskdef
    );
}
```

- [ ] **Step 5: Update cmake to include new source files**

Add to `media_uvcd_tinyusb.cmake`:
```cmake
list(APPEND app_example_sources
    app_example.c
    board_amb82.c
    usb_descriptors.c
)
# Also add CDC class
list(APPEND app_example_sources
    ${TINYUSB_ROOT}/src/class/cdc/cdc_device.c
)
```

- [ ] **Step 6: Build and fix compilation errors**

```bash
cd /Users/jimmy/Projects/amb82_agentic_coding/freertos_uvc_tinyusb
bash build.sh
```

Iterate until clean compile. Common issues:
- Missing CMSIS headers for NVIC → add include path
- TinyUSB OPT_MCU_NONE may need `dwc2_rtl8735b.h` to be included by TinyUSB → check `dcd_dwc2.c` includes
- `tusb_init` signature may differ between TinyUSB versions

- [ ] **Step 7: Commit**

```bash
git add freertos_uvc_tinyusb/src/
git commit -m "feat: TinyUSB CDC device for Phase 0 DWC2 port verification"
```

---

### Task 5: Flash and Verify CDC Enumeration

**Files:** None (testing only)

**Tools needed:**
- AMB82-MINI board + USB OTG cable
- macOS terminal
- Serial monitor for debug output

- [ ] **Step 1: Flash firmware to AMB82-MINI**

Use the AMB82 MCP upload tool or manual flash:
```bash
# Via MCP tool (preferred)
amb82_upload <firmware_path>
```

- [ ] **Step 2: Connect USB OTG port and check serial output**

Monitor serial port for debug messages:
```
[TinyUSB] Starting AMB82 USB device...
[Board] AMB82 USB board init
[USB] Clock domain enabled, FUNC_CLK_CTRL=0x????????
[USB] PHY clock ready
[USB] PHY init complete
[USB HWCFG] GHWCFG1=0x???????? ...
[USB HWCFG] Dev EP count=?, Dev IN EP=?, DFIFO depth=? words
[TinyUSB] Device task running
[TinyUSB] Device mounted    <-- SUCCESS!
```

- [ ] **Step 3: Verify USB enumeration on macOS**

```bash
system_profiler SPUSBDataType | grep -A 5 "AMB82"
```

Expected: Device appears as "AMB82-MINI USB Device" with VID 0xCafe.

- [ ] **Step 4: Record GHWCFG values and update dwc2_rtl8735b.h**

From serial output, update `dwc2_controller[]` with actual:
- `ep_count` from GHWCFG2
- `ep_fifo_size` from GHWCFG3

- [ ] **Step 5: If enumeration fails, debug**

Common issues:
1. Bus fault on register access → clock domain not enabled (Step 0 failed)
2. PHY clock never ready → wrong addon register bits or sequence
3. No USB events → IRQ handler not connected (check vector table)
4. Enumeration starts but fails → FIFO size wrong, check GHWCFG3

- [ ] **Step 6: Commit with verified GHWCFG values**

```bash
git commit -am "fix: update DWC2 hardware config with verified GHWCFG values"
```

---

## Phase 1: UVC Webcam

Goal: MJPEG video stream visible in macOS Photo Booth / QuickTime.

---

### Task 6: UVC Descriptors (MJPEG 640x480)

**Files:**
- Modify: `freertos_uvc_tinyusb/src/tusb_config.h`
- Modify: `freertos_uvc_tinyusb/src/usb_descriptors.h`
- Modify: `freertos_uvc_tinyusb/src/usb_descriptors.c`
- Modify: `freertos_uvc_tinyusb/src/media_uvcd_tinyusb.cmake`

- [ ] **Step 1: Enable UVC in tusb_config.h**

Uncomment the UVC config lines and disable CDC:
```c
#define CFG_TUD_CDC               0   // Disable CDC
#define CFG_TUD_VIDEO             1
#define CFG_TUD_VIDEO_STREAMING   1
#define CFG_TUD_VIDEO_STREAMING_EP_BUFSIZE  1024
```

- [ ] **Step 2: Update usb_descriptors.h for UVC**

```c
// Interface numbers (Phase 1: UVC only)
enum {
    ITF_NUM_VIDEO_CONTROL = 0,
    ITF_NUM_VIDEO_STREAMING,
    ITF_NUM_TOTAL
};

// Endpoint numbers
#define EPNUM_VIDEO_STREAMING  0x82  // Isochronous IN
```

- [ ] **Step 3: Update usb_descriptors.c with UVC MJPEG descriptor**

Reference TinyUSB's `examples/device/video_capture/` for exact descriptor layout. Define:
- Video Control interface (camera terminal + output terminal)
- Video Streaming interface with MJPEG format descriptor
- Frame descriptor: 640x480 @ 30fps
- Color matching descriptor
- Alt setting 1 with isochronous endpoint (wMaxPacketSize = 1024)

This is the most complex descriptor — follow TinyUSB's UVC example structure exactly.

- [ ] **Step 4: Add video_device.c to cmake**

```cmake
list(APPEND app_example_sources
    ${TINYUSB_ROOT}/src/class/video/video_device.c
)
```

- [ ] **Step 5: Build and verify compilation**

- [ ] **Step 6: Commit**

```bash
git commit -am "feat: add UVC MJPEG 640x480 descriptors"
```

---

### Task 7: Static Test Pattern (Color Bars)

**Files:**
- Create: `freertos_uvc_tinyusb/src/usb_uvc_bridge.h`
- Create: `freertos_uvc_tinyusb/src/usb_uvc_bridge.c`
- Modify: `freertos_uvc_tinyusb/src/app_example.c`

- [ ] **Step 1: Create usb_uvc_bridge.h**

```c
#ifndef USB_UVC_BRIDGE_H
#define USB_UVC_BRIDGE_H

#include <stdint.h>

// Initialize UVC bridge (test pattern mode)
void uvc_bridge_init_test_pattern(void);

// Initialize UVC bridge (MMF2 pipeline mode)
// void uvc_bridge_init_mmf2(mm_context_t *video_ctx);

#endif // USB_UVC_BRIDGE_H
```

- [ ] **Step 2: Create usb_uvc_bridge.c with MJPEG test pattern**

Generate a minimal valid MJPEG frame (a small JPEG image of color bars):
- Pre-encode a 640x480 JPEG color bar image as a const byte array
- In `tud_video_frame_xfer_complete_cb()`, send the same frame again
- In `tud_video_commit_cb()`, start sending frames

```c
#include "tusb.h"
#include "usb_uvc_bridge.h"

// Pre-encoded 640x480 MJPEG test pattern (color bars)
// Generate with: ffmpeg -f lavfi -i testsrc=size=640x480:rate=1 -frames:v 1 -q:v 5 test.jpg
// Then xxd -i test.jpg > test_frame.h
// For now, use a minimal JPEG (can be ~10-20 KB)
static const uint8_t test_frame_mjpeg[] = {
    // TODO: embed actual JPEG bytes here
    // Placeholder — generate during implementation
    0xFF, 0xD8, 0xFF, 0xE0, // JPEG SOI + APP0 marker
    // ... rest of JPEG data ...
    0xFF, 0xD9              // JPEG EOI
};
static const size_t test_frame_size = sizeof(test_frame_mjpeg);

static bool streaming = false;

void tud_video_frame_xfer_complete_cb(uint_fast8_t ctl_idx, uint_fast8_t stm_idx)
{
    (void)ctl_idx;
    // Send next frame (same test pattern)
    if (streaming) {
        tud_video_n_frame_xfer(0, stm_idx,
                               (void *)test_frame_mjpeg, test_frame_size);
    }
}

int tud_video_commit_cb(uint_fast8_t ctl_idx, uint_fast8_t stm_idx,
                        video_probe_and_commit_control_t const *parameters)
{
    (void)ctl_idx;
    (void)parameters;

    streaming = true;
    // Send first frame to kick off streaming
    tud_video_n_frame_xfer(0, stm_idx,
                           (void *)test_frame_mjpeg, test_frame_size);
    return 0;  // VIDEO_ERROR_NONE
}

void uvc_bridge_init_test_pattern(void)
{
    printf("[UVC Bridge] Test pattern mode initialized\n");
}
```

- [ ] **Step 3: Update app_example.c to call UVC bridge init**

Replace CDC echo loop with UVC:
```c
#include "usb_uvc_bridge.h"

// In usb_device_task after tusb_init:
uvc_bridge_init_test_pattern();
```

- [ ] **Step 4: Generate actual JPEG test frame**

On dev machine:
```bash
ffmpeg -f lavfi -i "testsrc=size=640x480:rate=1" -frames:v 1 -q:v 8 /tmp/test_frame.jpg
xxd -i /tmp/test_frame.jpg > freertos_uvc_tinyusb/src/test_frame.h
```

Include the generated header in `usb_uvc_bridge.c`.

- [ ] **Step 5: Build**

- [ ] **Step 6: Commit**

```bash
git commit -am "feat: UVC bridge with MJPEG test pattern"
```

---

### Task 8: Flash and Verify UVC Test Pattern on macOS

**Files:** None (testing only)

- [ ] **Step 1: Flash firmware**

- [ ] **Step 2: Connect USB OTG and check serial output**

Look for:
```
[TinyUSB] Device mounted
[UVC Bridge] Test pattern mode initialized
```

- [ ] **Step 3: Open Photo Booth or QuickTime on macOS**

- Select "AMB82-MINI USB Device" as camera source
- Should see static color bars image

**This is the key milestone!** If color bars appear, TinyUSB UVC is fully working.

- [ ] **Step 4: If video doesn't appear, debug with USB descriptor analysis**

```bash
system_profiler SPUSBDataType  # Check device appears
# Check USB descriptor details
```

Common issues:
- Wrong MJPEG format GUID
- Frame descriptor timing fields incorrect
- Isochronous endpoint not properly configured

- [ ] **Step 5: Commit**

```bash
git commit -am "test: verify UVC MJPEG test pattern on macOS"
```

---

### Task 9: Connect MMF2 Video Pipeline (MJPEG 640x480 only)

**Keep only MJPEG 640x480 until live camera works.** Adding more formats before verifying the pipeline end-to-end risks compounding debugging difficulty.

**Files:**
- Modify: `freertos_uvc_tinyusb/src/usb_uvc_bridge.c`
- Modify: `freertos_uvc_tinyusb/src/usb_uvc_bridge.h`
- Modify: `freertos_uvc_tinyusb/src/app_example.c`

**Reference:**
- `ameba-rtos-pro2/component/example/media_uvcd/example_media_uvc.c` — how existing UVC uses MMF2
- `ameba-rtos-pro2/component/media/mmfv2/module_video.h` — video module API

- [ ] **Step 1: Add MMF2 video channel setup to app_example.c**

Initialize camera sensor and ISP/encoder via MMF2 for MJPEG 640x480:
```c
#include "module_video.h"
#include "mmf2_module.h"

video_params_t video_params = {
    .stream_id   = 0,
    .type        = VIDEO_JPEG,
    .resolution  = VIDEO_VGA,
    .width       = 640,
    .height      = 480,
    .fps         = 30,
    .bps         = 1 * 1024 * 1024,
    .rc_mode     = 1,
};

mm_context_t *video_ctx = mm_module_open(&video_module);
mm_module_ctrl(video_ctx, CMD_VIDEO_SET_PARAMS, (int)&video_params);
mm_module_ctrl(video_ctx, CMD_VIDEO_APPLY, 0);
```

- [ ] **Step 2: Update usb_uvc_bridge.c with semaphore-based buffer lifecycle**

(See corrected bridge_task code with `xfer_done_sem` above)

- [ ] **Step 3: Create FreeRTOS task for video bridge**

- [ ] **Step 4: Build and test with real camera**

Flash, connect USB OTG, open Photo Booth — should see live camera feed at 640x480.

**This is a key milestone!** Live camera through TinyUSB UVC.

- [ ] **Step 5: Commit**

```bash
git commit -am "feat: connect MMF2 video pipeline to TinyUSB UVC (MJPEG 640x480)"
```

---

### Task 10: Add All Video Formats and Resolutions

Now that live MJPEG 640x480 works, add remaining formats.

**Files:**
- Modify: `freertos_uvc_tinyusb/src/usb_descriptors.c`
- Modify: `freertos_uvc_tinyusb/src/usb_uvc_bridge.c`
- Modify: `freertos_uvc_tinyusb/src/tusb_config.h`

- [ ] **Step 1: Add MJPEG 720p and 1080p frame descriptors**

Add frame descriptors for:
- 1920x1080 @ 20fps
- 1280x720 @ 30fps

- [ ] **Step 2: Add H.264 format and frame descriptors (Frame-Based, stretch goal)**

Use UVC 1.5 Frame-Based format with H.264 GUID. Note: macOS has limited UVC H.264 support — verify with MJPEG first. Add frame descriptors for:
- 1920x1080 @ 30fps
- 1280x720 @ 30fps

- [ ] **Step 3: Add YUY2 uncompressed format and frame descriptors**

Use standard YUY2 GUID. Add frame descriptors for:
- 640x480 @ 10fps
- 320x240 @ 30fps

- [ ] **Step 4: Implement format switching in tud_video_commit_cb**

When host selects different format/resolution via Probe/Commit:
```c
int tud_video_commit_cb(uint_fast8_t ctl_idx, uint_fast8_t stm_idx,
                        video_probe_and_commit_control_t const *params)
{
    // Parse format index and frame index from params
    // Map to MMF2 video_params_t (VIDEO_JPEG/VIDEO_H264/VIDEO_YUV)
    // Stop current channel: mm_module_ctrl(video_ctx, CMD_VIDEO_STREAM_STOP, 0)
    // Reconfigure: CMD_VIDEO_SET_PARAMS -> CMD_VIDEO_APPLY
    // Restart: CMD_VIDEO_STREAM_START
}
```

- [ ] **Step 5: Update CONFIG_TOTAL_LEN calculation**

- [ ] **Step 6: Build and verify all formats enumerate**

```bash
system_profiler SPUSBDataType  # Check all formats listed
```

- [ ] **Step 7: Test each format on macOS** (MJPEG should work; H.264 may not; YUY2 at low res)

- [ ] **Step 8: Commit**

```bash
git commit -am "feat: add all UVC video formats (MJPEG, H.264, YUY2) with format switching"
```

---

## Phase 2: UAC Microphone

Goal: AMB82 appears as USB microphone on macOS.

---

### Task 11: UAC1 Descriptors

**Files:**
- Modify: `freertos_uvc_tinyusb/src/tusb_config.h`
- Modify: `freertos_uvc_tinyusb/src/usb_descriptors.h`
- Modify: `freertos_uvc_tinyusb/src/usb_descriptors.c`
- Modify: `freertos_uvc_tinyusb/src/media_uvcd_tinyusb.cmake`

- [ ] **Step 1: Enable UAC in tusb_config.h**

```c
#define CFG_TUD_AUDIO             1
#define CFG_TUD_AUDIO_FUNC_1_N_BYTES_PER_SAMPLE_TX  2   // 16-bit
#define CFG_TUD_AUDIO_FUNC_1_N_CHANNELS_TX          1   // Mono
#define CFG_TUD_AUDIO_FUNC_1_SAMPLE_RATE            16000 // 16kHz
```

- [ ] **Step 2: Update usb_descriptors.h**

Add audio interface numbers:
```c
enum {
    ITF_NUM_VIDEO_CONTROL = 0,
    ITF_NUM_VIDEO_STREAMING,
    ITF_NUM_AUDIO_CONTROL,
    ITF_NUM_AUDIO_STREAMING,
    ITF_NUM_TOTAL
};

#define EPNUM_AUDIO_IN  0x83  // Isochronous IN
```

- [ ] **Step 3: Add UAC1 descriptors to configuration descriptor**

Add IAD for audio function, audio control interface (input terminal + output terminal), audio streaming interface with PCM format.

- [ ] **Step 4: Add audio_device.c to cmake**

```cmake
list(APPEND app_example_sources
    ${TINYUSB_ROOT}/src/class/audio/audio_device.c
)
```

- [ ] **Step 5: Build**

- [ ] **Step 6: Commit**

```bash
git commit -am "feat: add UAC1 microphone descriptors to composite device"
```

---

### Task 12: UAC Audio Bridge + Test Tone

**Files:**
- Create: `freertos_uvc_tinyusb/src/usb_uac_bridge.h`
- Create: `freertos_uvc_tinyusb/src/usb_uac_bridge.c`
- Modify: `freertos_uvc_tinyusb/src/app_example.c`

- [ ] **Step 1: Create usb_uac_bridge.h**

```c
#ifndef USB_UAC_BRIDGE_H
#define USB_UAC_BRIDGE_H

// Init with sine wave test tone
void uac_bridge_init_test_tone(void);

// Init with MMF2 audio pipeline
// void uac_bridge_init_mmf2(mm_context_t *audio_ctx);

#endif
```

- [ ] **Step 2: Create usb_uac_bridge.c with sine wave test**

Generate 16kHz 16-bit mono PCM sine wave (440 Hz):
```c
#include "tusb.h"
#include "usb_uac_bridge.h"
#include <math.h>

#define SAMPLE_RATE  16000
#define TONE_FREQ    440

static int16_t audio_buf[SAMPLE_RATE / 1000]; // 1ms of audio = 16 samples
static uint32_t sample_count = 0;

bool tud_audio_tx_done_pre_load_cb(uint8_t rhport, uint8_t itf, uint8_t ep_in, uint8_t cur_alt_setting)
{
    (void)rhport; (void)itf; (void)ep_in; (void)cur_alt_setting;

    // Generate 1ms of sine wave
    for (int i = 0; i < SAMPLE_RATE / 1000; i++) {
        float t = (float)(sample_count++) / SAMPLE_RATE;
        audio_buf[i] = (int16_t)(sinf(2.0f * 3.14159f * TONE_FREQ * t) * 16000);
    }

    tud_audio_write((uint8_t *)audio_buf, sizeof(audio_buf));
    return true;
}

void uac_bridge_init_test_tone(void)
{
    printf("[UAC Bridge] Test tone mode (440Hz sine wave)\n");
}
```

- [ ] **Step 3: Update app_example.c**

```c
#include "usb_uac_bridge.h"
// After uvc_bridge_init:
uac_bridge_init_test_tone();
```

- [ ] **Step 4: Build and flash**

- [ ] **Step 5: Verify on macOS**

```bash
# Check System Preferences > Sound > Input
# Should see "AMB82-MINI USB Device" as input device
# Select it, speak test — level meter should show 440Hz tone
```

- [ ] **Step 6: Commit**

```bash
git commit -am "feat: UAC bridge with 440Hz test tone"
```

---

### Task 13: Connect MMF2 Audio Pipeline

**Files:**
- Modify: `freertos_uvc_tinyusb/src/usb_uac_bridge.c`
- Modify: `freertos_uvc_tinyusb/src/app_example.c`

- [ ] **Step 1: Add MMF2 audio module setup to app_example.c**

```c
#include "module_audio.h"

// Audio config: 16kHz Mono Analog Mic (preset 1)
AudioSetting configA(1);  // or equivalent FreeRTOS API
mm_context_t *audio_ctx = mm_module_open(&audio_module);
// Configure and start audio capture
```

- [ ] **Step 2: Update usb_uac_bridge.c to read from MMF2 audio queue**

Replace sine wave with real PCM from audio module output queue.

- [ ] **Step 3: Build, flash, test with real mic**

Verify on macOS: speak into AMB82 mic, hear audio in any recording app.

- [ ] **Step 4: Commit**

```bash
git commit -am "feat: connect MMF2 audio pipeline to TinyUSB UAC"
```

---

## Phase 3: Integration and Stability

Goal: UVC + UAC work simultaneously, stable hot plug/unplug.

---

### Task 14: Simultaneous UVC + UAC Testing

**Files:** None (testing only)

- [ ] **Step 1: Flash composite firmware (UVC + UAC)**

- [ ] **Step 2: Verify both appear on macOS**

```bash
system_profiler SPUSBDataType | grep -A 10 "AMB82"
```

Both video and audio interfaces should be listed.

- [ ] **Step 3: Open Photo Booth (video) + QuickTime audio recording simultaneously**

- [ ] **Step 4: Test format switching while audio streams**

Switch video resolution in Photo Booth; audio should not glitch.

- [ ] **Step 5: Document results**

---

### Task 15: Hot Plug/Unplug and Suspend/Resume

**Files:**
- Modify: `freertos_uvc_tinyusb/src/app_example.c`
- Modify: `freertos_uvc_tinyusb/src/usb_uvc_bridge.c`
- Modify: `freertos_uvc_tinyusb/src/usb_uac_bridge.c`

- [ ] **Step 1: Implement tud_suspend_cb / tud_resume_cb**

Pause/resume MMF2 video and audio pipelines on USB suspend/resume.

- [ ] **Step 2: Test repeated plug/unplug cycles (10x)**

No crashes, no memory leaks, device re-enumerates cleanly each time.

- [ ] **Step 3: Test cable disconnect during active streaming**

Both video and audio should recover gracefully when cable is reconnected.

- [ ] **Step 4: Commit**

```bash
git commit -am "feat: USB suspend/resume handling for video and audio pipelines"
```

---

### Task 16: Final Cleanup and Documentation

**Files:**
- Modify: various source files
- Update: `docs/superpowers/specs/2026-03-21-tinyusb-uvc-uac-design.md`

- [ ] **Step 1: Remove debug printf statements (or gate behind a DEBUG flag)**

- [ ] **Step 2: Update spec with final GHWCFG values and any design changes**

- [ ] **Step 3: Update VID/PID if Realtek provides production values**

- [ ] **Step 4: Final commit**

```bash
git commit -am "chore: cleanup debug output, update documentation"
```

---

## Risk Checkpoints

| After Task | Check | If Fail |
|-----------|-------|---------|
| Task 3 Step 5 | PHY clock ready on serial | Clock domain enable is wrong — verify `HP_OTG_FUNC_CLK_CTRL` bits against `hp_otg_func_ctrl_t` struct |
| Task 5 | CDC enumerates on macOS | DWC2 port issue — compare with known-working platform (STM32) |
| Task 5 Step 4 | GHWCFG values sensible | If DFIFO < 512 words, video ISO may not work — redesign EP allocation |
| Task 8 | Color bars in Photo Booth | UVC descriptor issue — analyze with `USB Prober` or Wireshark USB |
| Task 9 | Live MJPEG camera in Photo Booth | MMF2 bridge issue — verify frames arrive, check buffer lifecycle |
| Task 12 | Test tone in System Preferences | UAC descriptor issue — similar debug as UVC |
| Task 14 | UVC + UAC simultaneous | Composite device bandwidth issue — check FIFO allocation |

Each checkpoint is a **hard gate** — do not proceed to next phase if current phase fails.
