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
 * Section 6: TinyUSB DWC2 port — controller descriptor + inline functions
 *
 * This section satisfies the TinyUSB 0.17.0 DWC2 port contract as defined in
 * src/portable/synopsys/dwc2/dcd_dwc2.c.  The ESP32 port (dwc2_esp32.h) was
 * used as a template.
 * =========================================================================*/

/* ===========================================================================
 * Section 7: Register access convenience macros
 *
 * Available to ALL compilation units (not just TinyUSB).
 * Used by board_amb82.c for GHWCFG register reads.
 * =========================================================================*/

/** Read a 32-bit register at (base + offset) */
#define DWC2_READ_REG32(base, offset) \
    (*(volatile uint32_t *)((uint32_t)(base) + (uint32_t)(offset)))

/** Write a 32-bit register at (base + offset) */
#define DWC2_WRITE_REG32(base, offset, value) \
    (*(volatile uint32_t *)((uint32_t)(base) + (uint32_t)(offset)) = (uint32_t)(value))

/* Only provide TinyUSB port functions when compiling within the TinyUSB driver
 * context.  dcd_dwc2.c includes dwc2_type.h (which defines _TUSB_DWC2_TYPES_H_)
 * before including this header, so dwc2_controller_t, dwc2_regs_t, and TU_*
 * macros are all available.  board_amb82.c and other non-TinyUSB files skip
 * this entire section since they don't have the TinyUSB include chain. */
#ifdef _TUSB_DWC2_TYPES_H_

/** Conservative endpoint count — will be confirmed from GHWCFG2 at runtime */
#define DWC2_EP_MAX   6

/** Controller descriptor table (index 0 = rhport 0) */
static const dwc2_controller_t _dwc2_controller[] = {
    {
        .reg_base     = USB_OTG_REG_BASE,   /* 0x400C0000 */
        .irqnum       = USB_OTG_IRQ_NUM,    /* 25 */
        .ep_count     = DWC2_EP_MAX,
        .ep_fifo_size = 8928,               /* 2232 words x 4 = 8928 bytes (from GHWCFG3) */
    },
};

/* ===========================================================================
 * Section 8: TinyUSB DWC2 port — required inline functions
 *
 * These four functions are called directly by dcd_dwc2.c and must be present
 * as static inline in this header.  Signatures must match exactly.
 * =========================================================================*/

/**
 * Enable the USB OTG interrupt in the NVIC.
 * TinyUSB calls this after initialising the device controller.
 */
/* Forward declaration — implemented in board_amb82.c */
void rtl8735b_usb_irq_setup(void);

TU_ATTR_ALWAYS_INLINE static inline void dwc2_dcd_int_enable(uint8_t rhport) {
    (void)rhport;
    /* Use Realtek HAL to register + enable USB IRQ.
     * hal_irq_set_vector sets the handler in the SDK's vector table.
     * hal_irq_enable enables the interrupt through the SDK's NVIC wrapper. */
    rtl8735b_usb_irq_setup();
}

/**
 * Disable the USB OTG interrupt in the NVIC via Realtek HAL.
 */
void rtl8735b_usb_irq_disable(void);

TU_ATTR_ALWAYS_INLINE static inline void dwc2_dcd_int_disable(uint8_t rhport) {
    (void)rhport;
    rtl8735b_usb_irq_disable();
}

/**
 * Remote-wakeup delay (~1 ms).
 * A simple busy-wait loop is used here; replace with an RTOS delay when the
 * scheduler is running.
 */
TU_ATTR_ALWAYS_INLINE static inline void dwc2_remote_wakeup_delay(void) {
    /* ~1 ms at 500 MHz (Cortex-M55 max clock).  Adjust if clock changes. */
    volatile uint32_t count = 500000UL;
    while (count--) { __asm volatile ("nop"); }
}

/**
 * MCU-specific PHY initialisation — called BEFORE the DWC2 core reset.
 * Implemented in board_amb82.c (too complex for static inline).
 */
void rtl8735b_usb_phy_init(void);

TU_ATTR_ALWAYS_INLINE static inline void dwc2_phy_init(dwc2_regs_t* dwc2,
                                                        uint8_t hs_phy_type) {
    (void)hs_phy_type;
    rtl8735b_usb_phy_init();

    /* RTL8735B only has UTMI+ HS PHY — NEVER select dedicated FS PHY.
     * Clear PHYSEL (bit 6) regardless of what TinyUSB sets. */
    dwc2->gusbcfg &= ~(1UL << 6);  /* PHYSEL = 0 → use UTMI+ PHY */
}

/**
 * MCU-specific PHY update — called AFTER the DWC2 core reset.
 * Can add speed-dependent PHY tuning here later.
 */
TU_ATTR_ALWAYS_INLINE static inline void dwc2_phy_update(dwc2_regs_t* dwc2,
                                                          uint8_t hs_phy_type) {
    (void)hs_phy_type;

    /* RTL8735B has NO dedicated FS PHY — only UTMI+ HS PHY.
     * TinyUSB's phy_fs_init() sets GUSBCFG_PHYSEL which selects a non-existent
     * FS transceiver, breaking D+ pull-up. Clear it here after core reset. */
    dwc2->gusbcfg &= ~(1UL << 6);  /* PHYSEL = bit 6, clear it */
}

/* ===========================================================================
 * Section 9: Optional — deinit / DMA cache management
 *
 * dwc2_phy_deinit() and cache-maintenance helpers are not required by the
 * TinyUSB 0.17.0 DWC2 port contract and are left as stubs for future use.
 *
 * If CONFIG_USB_DMA_ENABLE is set and D-cache is active on Cortex-M55,
 * implement the cache-maintenance wrappers and call them from the relevant
 * dcd_dwc2.c hooks via a local patch.
 * =========================================================================*/

#endif /* _TUSB_DWC2_TYPES_H_ — end of TinyUSB-specific section */

#ifdef __cplusplus
}
#endif

#endif /* DWC2_RTL8735B_H */
