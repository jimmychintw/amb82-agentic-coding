/**
 * @file dwc2_rtl8735b.h
 * @brief DWC2 USB OTG platform port header for Realtek RTL8735B (AMB82-MINI)
 *
 * This file defines all hardware-specific constants, register addresses,
 * and function declarations needed to port TinyUSB's DWC2 driver to the
 * Realtek RTL8735B SoC (AMB82-MINI board).
 *
 * Hardware: Synopsys DesignWare DWC2 USB OTG controller
 * SDK reference:
 *   - component/usb/common_new/ameba_usb.h
 *   - component/soc/8735b/fwlib/rtl8735b/lib/source/ram/usb_otg/dwc_otg_regs.h
 *
 * NOTE: TinyUSB has not yet been added to lib/tinyusb/. Once it is, the
 * dwc2_controller_t array and the #include below must be adjusted to match
 * the actual struct definition in src/portable/synopsys/dwc2/dwc2_type.h.
 */

#ifndef DWC2_RTL8735B_H
#define DWC2_RTL8735B_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ===========================================================================
 * Section 1: USB Core Register Base Address
 * Synopsys DWC2 is memory-mapped at 0x400C0000.
 * Direct pointer dereference is expected to work (standard DWC2 MMIO).
 * Realtek's own HAL uses HAL_OTG_READ32/WRITE32 for indirect access, but
 * TinyUSB uses direct MMIO — believed to be equivalent on this SoC.
 * =========================================================================*/

/** USB OTG core register base (confirmed from ameba_usb.h / rtl8735b.h) */
#define USB_OTG_REG_BASE            0x400C0000UL

/* DWC2 standard sub-region offsets from USB_OTG_REG_BASE */
#define USB_OTG_GLOBAL_BASE         0x000UL   /**< Global CSRs (GOTGCTL, GAHBCFG, …) */
#define USB_OTG_HOST_BASE           0x400UL   /**< Host global registers */
#define USB_OTG_HOST_PORT_BASE      0x440UL   /**< Host port CSR */
#define USB_OTG_HOST_CHANNEL_BASE   0x500UL   /**< Host channel registers (base) */
#define USB_OTG_HOST_CHANNEL_SIZE   0x020UL   /**< Size of one host channel register set */
#define USB_OTG_DEVICE_BASE         0x800UL   /**< Device global registers */
#define USB_OTG_IN_ENDPOINT_BASE    0x900UL   /**< Device IN endpoint registers */
#define USB_OTG_OUT_ENDPOINT_BASE   0xB00UL   /**< Device OUT endpoint registers */
#define USB_OTG_EP_REG_SIZE         0x020UL   /**< Size of one endpoint register set */
#define USB_OTG_PCGCCTL_BASE        0xE00UL   /**< Power & clock gating control */
#define USB_OTG_FIFO_BASE           0x1000UL  /**< Data FIFO region (one 4 KB window per EP) */
#define USB_OTG_FIFO_SIZE           0x1000UL  /**< FIFO window size per endpoint */

/* ===========================================================================
 * Section 2: Realtek Addon Register Block
 * Located at USB_OTG_REG_BASE + 0x30000 (addon block base).
 * The key control register is at offset 0x30004 from the core base.
 * =========================================================================*/

/** Addon register block base offset from USB_OTG_REG_BASE */
#define USB_OTG_ADDON_BASE          0x30000UL

/** Addon control register (PHY & OTG core enable) — offset from USB_OTG_REG_BASE */
#define USB_OTG_ADDON_REG_CTRL      0x30004UL

/** Addon vendor status-out register — offset from USB_OTG_REG_BASE */
#define USB_OTG_ADDON_REG_VND_STS_OUT  0x3001CUL

/* Addon control register bit masks (from ameba_usb.h) */
#define USB_OTG_ADDON_UPLL_CKRDY        (1UL << 5)   /**< [RO] USB PHY PLL clock ready */
#define USB_OTG_ADDON_USB_OTG_RST       (1UL << 8)   /**< [RW] Enable USB OTG core (1=enable) */
#define USB_OTG_ADDON_USB_DPHY_FEN      (1UL << 9)   /**< [RW] Enable USB digital PHY (1=enable) */
#define USB_OTG_ADDON_USB_APHY_EN       (1UL << 14)  /**< [RW] Enable USB analog PHY (1=enable) */
#define USB_OTG_ADDON_LS_HST_UTMI_EN    (1UL << 22)  /**< [RW] Low-speed host UTMI-16bit support */

/** Mask for HS inter-packet gap option field [21:20] */
#define USB_OTG_ADDON_HS_IP_GAP_OPT_POS  20U
#define USB_OTG_ADDON_HS_IP_GAP_OPT_MASK (0x3UL << USB_OTG_ADDON_HS_IP_GAP_OPT_POS)

/* ===========================================================================
 * Section 3: SoC Clock / Functional Control Register
 * HP_OTG_FUNC_CLK_CTRL at address 0x50000920
 * (= 0x50000000 HP base + 0x0800 subblock + 0x0120 offset)
 * Source: dwc_otg_regs.h hp_otg_func_ctrl_t (pro2 variant)
 * =========================================================================*/

/** SoC OTG functional/clock control register absolute address */
#define HP_OTG_FUNC_CLK_CTRL_ADDR   0x50000920UL

/** Pointer-form convenience macro (use with caution — volatile access only) */
#define HP_OTG_FUNC_CLK_CTRL_REG   (*(volatile uint32_t *)HP_OTG_FUNC_CLK_CTRL_ADDR)

/* hp_otg_func_ctrl_t bit positions (RTL8735B / pro2 variant) */
#define HP_OTG_CLK_OTG_EN           (1UL << 0)   /**< bit 0: enable OTG IP */
#define HP_OTG_CLK_WD_RST_MSK       (1UL << 1)   /**< bit 1: mask watchdog reset */
#define HP_OTG_CLK_LPM_PLL_ALIVE    (1UL << 3)   /**< bit 3: LPM PLL alive */
#define HP_OTG_CLK_OTG_CLK_EN       (1UL << 4)   /**< bit 4: enable OTG clock */
#define HP_OTG_CLK_UTMI_CLK_EN      (1UL << 5)   /**< bit 5: enable OTG UTMI clock */
#define HP_OTG_CLK_DIGI_PC_EN       (1UL << 16)  /**< bit 16: USB digital power-cut enable */
#define HP_OTG_CLK_ANA_HV_EN        (1UL << 18)  /**< bit 18: USB analog HV power-cut enable */
#define HP_OTG_CLK_BG_EN            (1UL << 19)  /**< bit 19: USB BG (band-gap) enable */
#define HP_OTG_CLK_PDN               (1UL << 20)  /**< bit 20: power down USB (default 1) */
#define HP_OTG_CLK_IBX_USB_EN       (1UL << 21)  /**< bit 21: enable IBX to USB */
#define HP_OTG_CLK_IBX_MIPI_EN      (1UL << 22)  /**< bit 22: enable IBX to MIPI */
#define HP_OTG_CLK_DISO_EN          (1UL << 24)  /**< bit 24: USB digital ISO (default 1) */
#define HP_OTG_CLK_AISO_EN          (1UL << 25)  /**< bit 25: USB analog ISO (default 1) */

/* ===========================================================================
 * Section 4: USB PHY Paged Registers
 * The internal UTMI PHY is accessed through a paged register interface.
 * Register F4 selects the active page; other registers (E0–F6) are the data
 * registers whose meaning depends on the selected page.
 *
 * Access helpers: USB_OTG_PHY_HIGH_ADDR / USB_OTG_PHY_LOW_ADDR split the
 * 8-bit register address into the 4-bit high nibble (used as addr/command)
 * and 4-bit low nibble (used as sub-address).  See ameba_usb.h for detail.
 * =========================================================================*/

/* PHY register addresses (8-bit) */
#define USB_OTG_PHY_REG_E0          0xE0U  /**< PAGE0: impedance auto-k, ADJR */
#define USB_OTG_PHY_REG_E1          0xE1U  /**< PAGE1: EN_OTG, REG_SRC */
#define USB_OTG_PHY_REG_E2          0xE2U  /**< PAGE1: SRVH, SRM, SREN */
#define USB_OTG_PHY_REG_E4          0xE4U  /**< PAGE0: SITX (TX slew-rate) */
#define USB_OTG_PHY_REG_E6          0xE6U  /**< PAGE0: RX_BOOST */
#define USB_OTG_PHY_REG_E7          0xE7U  /**< PAGE2: SEND_OBJ, SENH_OBJ */
#define USB_OTG_PHY_REG_F1          0xF1U  /**< PAGE0: UTMI_POS_OUT */
#define USB_OTG_PHY_REG_F4          0xF4U  /**< Page selector register */
#define USB_OTG_PHY_REG_F6          0xF6U  /**< PAGE1: late DLL, NSQ valid sel, EB disable */

/* Address split helpers */
#define USB_OTG_PHY_HIGH_ADDR(x)    (((x) & 0xF0U) >> 4)  /**< High nibble of PHY reg addr */
#define USB_OTG_PHY_LOW_ADDR(x)     ((x) & 0x0FU)          /**< Low nibble of PHY reg addr */
#define USB_OTG_PHY_DATA_MASK       0xFFU                   /**< PHY data byte mask */

/* F4 — Page selector bit field [6:5] */
#define USB_OTG_PHY_REG_F4_PAGE_SEL_POS    5U
#define USB_OTG_PHY_REG_F4_PAGE_SEL_MASK   (0x3U << USB_OTG_PHY_REG_F4_PAGE_SEL_POS)
#define USB_OTG_PHY_REG_F4_PAGE0           0U  /**< Select page 0 */
#define USB_OTG_PHY_REG_F4_PAGE1           1U  /**< Select page 1 */
#define USB_OTG_PHY_REG_F4_PAGE2           2U  /**< Select page 2 */
#define USB_OTG_PHY_REG_F4_PAGE3           3U  /**< Select page 3 */

/* Selected per-page bit definitions ---------------------------------------- */

/* E0 PAGE0 */
#define USB_OTG_PHY_E0_P0_Z0_AUTO_K_POS    6U
#define USB_OTG_PHY_E0_P0_Z0_AUTO_K_MASK   (0x1U << USB_OTG_PHY_E0_P0_Z0_AUTO_K_POS)
#define USB_OTG_PHY_E0_P0_Z0_ADJR_POS      2U
#define USB_OTG_PHY_E0_P0_Z0_ADJR_MASK     (0xFU << USB_OTG_PHY_E0_P0_Z0_ADJR_POS)

/* E1 PAGE1 */
#define USB_OTG_PHY_E1_P1_EN_OTG_POS       7U
#define USB_OTG_PHY_E1_P1_EN_OTG_MASK      (0x1U << USB_OTG_PHY_E1_P1_EN_OTG_POS)
#define USB_OTG_PHY_E1_P1_REG_SRC_POS      4U
#define USB_OTG_PHY_E1_P1_REG_SRC_MASK     (0x7U << USB_OTG_PHY_E1_P1_REG_SRC_POS)

/* E2 PAGE1 */
#define USB_OTG_PHY_E2_P1_REG_SRVH_POS     0U
#define USB_OTG_PHY_E2_P1_REG_SRVH_MASK    (0x7U << USB_OTG_PHY_E2_P1_REG_SRVH_POS)
#define USB_OTG_PHY_E2_P1_REG_SRM_POS      3U
#define USB_OTG_PHY_E2_P1_REG_SRM_MASK     (0x7U << USB_OTG_PHY_E2_P1_REG_SRM_POS)
#define USB_OTG_PHY_E2_P1_SREN_POS         6U
#define USB_OTG_PHY_E2_P1_SREN_MASK        (0x1U << USB_OTG_PHY_E2_P1_SREN_POS)

/* E4 PAGE0 */
#define USB_OTG_PHY_E4_P0_REG_SITX_POS     0U
#define USB_OTG_PHY_E4_P0_REG_SITX_MASK    (0xFU << USB_OTG_PHY_E4_P0_REG_SITX_POS)

/* E6 PAGE0 */
#define USB_OTG_PHY_E6_P0_RX_BOOST_POS     0U
#define USB_OTG_PHY_E6_P0_RX_BOOST_MASK    (0x3U << USB_OTG_PHY_E6_P0_RX_BOOST_POS)

/* E7 PAGE2 */
#define USB_OTG_PHY_E7_P2_SEND_OBJ_POS     0U
#define USB_OTG_PHY_E7_P2_SEND_OBJ_MASK    (0xFU << USB_OTG_PHY_E7_P2_SEND_OBJ_POS)
#define USB_OTG_PHY_E7_P2_SENH_OBJ_POS     4U
#define USB_OTG_PHY_E7_P2_SENH_OBJ_MASK    (0xFU << USB_OTG_PHY_E7_P2_SENH_OBJ_POS)

/* F1 PAGE0 */
#define USB_OTG_PHY_F1_P0_UTMI_POS_OUT_POS  7U
#define USB_OTG_PHY_F1_P0_UTMI_POS_OUT_MASK (0x1U << USB_OTG_PHY_F1_P0_UTMI_POS_OUT_POS)

/* F6 PAGE1 */
#define USB_OTG_PHY_F6_P1_LATE_DLLEN_POS           0U
#define USB_OTG_PHY_F6_P1_LATE_DLLEN_MASK          (0x3U << USB_OTG_PHY_F6_P1_LATE_DLLEN_POS)
#define USB_OTG_PHY_F6_P1_NSQ_VLD_SEL_POS          2U
#define USB_OTG_PHY_F6_P1_NSQ_VLD_SEL_MASK         (0x1U << USB_OTG_PHY_F6_P1_NSQ_VLD_SEL_POS)
#define USB_OTG_PHY_F6_P1_DISABLE_EB_WAIT4IDLE_POS 3U
#define USB_OTG_PHY_F6_P1_DISABLE_EB_WAIT4IDLE_MASK (0x1U << USB_OTG_PHY_F6_P1_DISABLE_EB_WAIT4IDLE_POS)
#define USB_OTG_PHY_F6_P1_WATER_LEVEL_CLEAN_SEL_POS 4U
#define USB_OTG_PHY_F6_P1_WATER_LEVEL_CLEAN_SEL_MASK (0x1U << USB_OTG_PHY_F6_P1_WATER_LEVEL_CLEAN_SEL_POS)
#define USB_OTG_PHY_F6_P1_NSQ_DEL_SEL_POS          5U
#define USB_OTG_PHY_F6_P1_NSQ_DEL_SEL_MASK         (0x3U << USB_OTG_PHY_F6_P1_NSQ_DEL_SEL_POS)

/* ===========================================================================
 * Section 5: Interrupt
 * USB OTG IRQ number verified from CMSIS header rtl8735b.h.
 * =========================================================================*/

/** USB OTG IRQ number (CMSIS IRQn, maps to NVIC vector 25) */
#define USB_OTG_IRQ_NUM             25

/* ===========================================================================
 * Section 6: dwc2_controller_t forward-compatible placeholder
 *
 * TinyUSB defines dwc2_controller_t in:
 *   src/portable/synopsys/dwc2/dwc2_type.h
 *
 * A typical entry looks like:
 *   { .reg_base = 0x400C0000UL, .irqnum = 25, .ep_count = 6,
 *     .ep_fifo_size = 0x1000U }
 *
 * The exact fields depend on the TinyUSB version.  Once lib/tinyusb/ is
 * populated, uncomment and adjust the block below, then #include the proper
 * TinyUSB type header.
 *
 * #include "portable/synopsys/dwc2/dwc2_type.h"
 *
 * static const dwc2_controller_t _dwc2_controller[] = {
 *     {
 *         .reg_base      = USB_OTG_REG_BASE,   // 0x400C0000
 *         .irqnum        = USB_OTG_IRQ_NUM,    // 25
 *         .ep_count      = 6,                  // adjust to actual HW value
 *         .ep_fifo_size  = USB_OTG_FIFO_SIZE,  // 0x1000
 *     },
 * };
 * =========================================================================*/

/* ===========================================================================
 * Section 7: Register access convenience macros
 *
 * The Realtek HAL uses HAL_OTG_READ32 / HAL_OTG_WRITE32 which go through
 * an indirect path.  For TinyUSB we use direct MMIO dereference, consistent
 * with how every other DWC2 port works.  These macros mirror the Realtek
 * naming for documentation purposes and can be used in the BSP glue code.
 * =========================================================================*/

/** Read a 32-bit register at (base + offset) */
#define DWC2_READ_REG32(base, offset) \
    (*(volatile uint32_t *)((uint32_t)(base) + (uint32_t)(offset)))

/** Write a 32-bit register at (base + offset) */
#define DWC2_WRITE_REG32(base, offset, value) \
    (*(volatile uint32_t *)((uint32_t)(base) + (uint32_t)(offset)) = (uint32_t)(value))

/* ===========================================================================
 * Section 8: Function declarations (implemented in dwc2_rtl8735b.c / bsp.c)
 * =========================================================================*/

/**
 * @brief  Power-up and initialize the USB PHY and OTG core clocks.
 *
 * Sequence (derived from Realtek SDK usb_chip_init / usb_hal_board_init):
 *  1. Enable SoC functional clocks via HP_OTG_FUNC_CLK_CTRL_REG.
 *  2. Assert addon-register enables: APHY_EN, DPHY_FEN, OTG_RST.
 *  3. Wait for UPLL_CKRDY to assert.
 *  4. Configure PHY paged registers (impedance, OTG enable, etc.).
 *
 * @return true on success (UPLL_CKRDY asserted within timeout), false otherwise.
 */
bool dwc2_phy_init(void);

/**
 * @brief  Update / re-calibrate PHY settings after enumeration speed is known.
 *
 * Called by the TinyUSB DWC2 port after the ENUMDNE interrupt to apply
 * speed-dependent PHY tuning (e.g. TX amplitude, RX boost).
 *
 * @param high_speed  true if the link enumerated at high-speed (480 Mbps).
 */
void dwc2_phy_update(bool high_speed);

/**
 * @brief  Disable the USB PHY and gate SoC clocks.
 *
 * Reverses dwc2_phy_init() — de-asserts addon enables and disables
 * HP_OTG_FUNC_CLK_CTRL_REG clock bits.
 */
void dwc2_phy_deinit(void);

/**
 * @brief  Enable or disable the USB OTG interrupt in the NVIC.
 *
 * @param enable  true to enable IRQ 25, false to disable.
 */
void dwc2_int_set(bool enable);

/* ===========================================================================
 * Section 9: Optional DMA cache management (commented out)
 *
 * If DMA is used for USB transfers on a Cortex-M55 with D-cache, cache
 * maintenance is required before/after DMA operations.  Uncomment and
 * implement these if CONFIG_USB_DMA_ENABLE is set.
 *
 * void dwc2_dcache_clean(const void *addr, uint32_t size);
 * void dwc2_dcache_invalidate(void *addr, uint32_t size);
 * void dwc2_dcache_clean_invalidate(void *addr, uint32_t size);
 * =========================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* DWC2_RTL8735B_H */
