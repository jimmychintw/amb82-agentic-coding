/**
 * @file board_amb82.c
 * @brief Board-support implementation for AMB82-MINI (RTL8735B)
 *
 * Implements BSP functions and the USB PHY init sequence.
 * PHY init is derived from disassembly of Realtek's libusbd.a:
 *   dwc_otg_power_init() -> hal_sys_peripheral_en(58,1) + dwc_uphy_init()
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "board_amb82.h"
#include "dwc2_rtl8735b.h"
#include "hal_irq.h"

/* -------------------------------------------------------------------------
 * SDK HAL function — enables USB OTG clock/power domain at SoC level.
 * This handles SYSON_S_REG_SYS_OTG_CTRL (0x50000920) properly.
 * OTG_SYS_CTRL = 58 (0x3a)
 * ------------------------------------------------------------------------- */
extern void hal_sys_peripheral_en(uint8_t id, uint8_t en);
#define OTG_SYS_CTRL  58

/* -------------------------------------------------------------------------
 * DWC2 hardware configuration register offsets
 * ------------------------------------------------------------------------- */
#define DWC2_GHWCFG1_OFFSET   0x044UL
#define DWC2_GHWCFG2_OFFSET   0x048UL
#define DWC2_GHWCFG3_OFFSET   0x04CUL
#define DWC2_GHWCFG4_OFFSET   0x050UL

/* -------------------------------------------------------------------------
 * PHY register read/write via addon indirect access
 *
 * The internal UTMI PHY uses a paged register interface accessed through
 * the addon register block at USB_OTG_REG_BASE + 0x30000.
 *
 * Protocol (reverse-engineered from libusbd.a):
 *   Write: addon[0x20] = (phy_addr_high << 4) | data_nibble_low
 *          addon[0x24] = (phy_addr_low  << 4) | data_nibble_high
 *   Read:  addon[0x20] = (phy_addr_high << 4) | 0x00
 *          return addon[0x28] & 0xFF
 *
 * We use the simplified HAL_OTG approach: write via vendor STS registers.
 * ------------------------------------------------------------------------- */
#define USB_OTG_ADDON_WRITE_REG  (USB_OTG_REG_BASE + 0x30020UL)
#define USB_OTG_ADDON_READ_DATA  (USB_OTG_REG_BASE + 0x30028UL)

#define REG32(addr) (*(volatile uint32_t *)(addr))

/*
 * PHY register access via GPVNDCTL (offset 0x34 from USB_OTG_REG_BASE)
 * and addon VND_STS_OUT (offset 0x3001C from USB_OTG_REG_BASE).
 *
 * Protocol reverse-engineered from DWCWritePhyReg / DWCReadPhyReg disassembly:
 *   GPVNDCTL command format:
 *     bits [11:8]  = addr nibble (high or low, shifted)
 *     bit  25      = NewReq
 *     bits [27:24] = 0xA for write, 0x4 for read
 *     bit  27      = VStsDone (poll until set after write, clear before start)
 */
#define GPVNDCTL         (USB_OTG_REG_BASE + 0x034UL)
#define ADDON_VND_STS    (USB_OTG_REG_BASE + 0x3001CUL)
#define GPVNDCTL_BUSY    (1UL << 27)
#define GPVNDCTL_WRITE   0x0A300000UL  /* write command: bits[27:24]=A, bit25=NewReq */
#define GPVNDCTL_READ    0x04300000UL  /* read command:  bits[27:24]=4, bit25=NewReq */

static void usb_phy_write(uint8_t addr, uint8_t data)
{
    volatile uint32_t timeout;

    /* Wait for GPVNDCTL not busy (bit 27 clear) */
    timeout = 10000;
    while ((REG32(GPVNDCTL) & GPVNDCTL_BUSY) && --timeout) {}

    /* Write data byte to addon VND_STS_OUT register */
    REG32(ADDON_VND_STS) = (uint32_t)data;

    /* Write high nibble of addr as command */
    uint32_t addr_high = ((uint32_t)(addr) << 8) & 0xF00UL;
    REG32(GPVNDCTL) = addr_high | GPVNDCTL_WRITE;

    /* Wait for done (bit 27 set) */
    timeout = 10000;
    while (!(REG32(GPVNDCTL) & GPVNDCTL_BUSY) && --timeout) {}

    /* Write low nibble of addr as command */
    uint32_t addr_low = ((uint32_t)(addr) << 4) & 0xF00UL;
    REG32(GPVNDCTL) = addr_low | GPVNDCTL_WRITE;

    /* Wait for done */
    timeout = 10000;
    while (!(REG32(GPVNDCTL) & GPVNDCTL_BUSY) && --timeout) {}
}

static uint8_t usb_phy_read(uint8_t addr)
{
    volatile uint32_t timeout;

    /* Wait not busy */
    timeout = 10000;
    while ((REG32(GPVNDCTL) & GPVNDCTL_BUSY) && --timeout) {}

    /* Read high nibble */
    uint32_t addr_high = ((uint32_t)(addr) << 8) & 0xF00UL;
    REG32(GPVNDCTL) = addr_high | GPVNDCTL_READ;
    timeout = 10000;
    while (!(REG32(GPVNDCTL) & GPVNDCTL_BUSY) && --timeout) {}

    /* Read low nibble */
    uint32_t addr_low = ((uint32_t)(addr) << 4) & 0xF00UL;
    REG32(GPVNDCTL) = addr_low | GPVNDCTL_READ;
    timeout = 10000;
    while (!(REG32(GPVNDCTL) & GPVNDCTL_BUSY) && --timeout) {}

    /* Read result from GPVNDCTL data field (bits [7:0]) or addon register */
    return (uint8_t)(REG32(GPVNDCTL) & 0xFFUL);
}

/* -------------------------------------------------------------------------
 * dwc_uphy_init — USB PHY register programming
 *
 * Values from disassembly of libusbd.a dwc_uphy_init() @ 0x701b8a64.
 * Device mode values are used (gOtgHostMode == 0).
 * ------------------------------------------------------------------------- */
static void dwc_uphy_init(void)
{
    uint8_t val;

    printf("[USB PHY] Programming PHY registers (device mode)...\n");

    /* 1. Select PAGE 0 */
    val = usb_phy_read(0xF4);
    usb_phy_write(0xF4, val & 0x9F);  /* Clear bits [6:5] -> PAGE 0 */

    /* 2. PAGE 0 writes */
    usb_phy_write(0xE0, 0xA1);  /* Z0_AUTO_K, Z0_ADJR */
    usb_phy_write(0xE1, 0x19);
    usb_phy_write(0xE2, 0xB9);
    usb_phy_write(0xE3, 0xDD);  /* WAS MISSING! TX amplitude/eye from disasm */
    usb_phy_write(0xE4, 0x68);  /* SITX (device mode) */
    usb_phy_write(0xE6, 0xD1);  /* RX_BOOST (for rom_ver <= 3) */
    usb_phy_write(0xF1, 0x8C);  /* UTMI_POS_OUT (device mode) */

    /* 3. Write F6 before switching page */
    usb_phy_write(0xF6, 0x01);

    /* 4. Switch to PAGE 2 */
    val = usb_phy_read(0xF4);
    usb_phy_write(0xF4, (val & 0x9F) | 0x40);  /* Set bit6 -> PAGE 2 */

    /* 5. PAGE 2 write */
    usb_phy_write(0xE7, 0x32);  /* SEND_OBJ, SENH_OBJ */

    /* 6. Switch to PAGE 1 */
    val = usb_phy_read(0xF4);
    usb_phy_write(0xF4, (val & 0x9F) | 0x20);  /* Set bit5 -> PAGE 1 */

    /* 7. PAGE 1 calibration (device mode) */
    usb_phy_write(0xE0, 0x01);
    usb_phy_write(0xE0, 0x05);  /* Trigger calibration */
    usb_phy_write(0xE5, 0x0A);
    usb_phy_write(0xE6, 0xD8);
    usb_phy_write(0xF7, 0x40);  /* Device mode */

    /* 8. Return to PAGE 0 */
    val = usb_phy_read(0xF4);
    usb_phy_write(0xF4, val & 0x9F);

    printf("[USB PHY] PHY register programming complete\n");
}

/* -------------------------------------------------------------------------
 * rtl8735b_usb_phy_init — full USB power + PHY init
 *
 * Called by TinyUSB's dcd_dwc2.c via dwc2_phy_init() before core reset.
 * Sequence from disassembly of dwc_otg_power_init() @ 0x701b8b6c:
 *   1. Pre-init register writes (0x40000008, 0x40009090)
 *   2. hal_sys_peripheral_en(OTG_SYS_CTRL=58, ENABLE=1)
 *   3. dwc_uphy_init() — program PHY registers
 *   4. Enable addon registers (APHY, DPHY, OTG core)
 *   5. Wait for UPLL_CKRDY
 * ------------------------------------------------------------------------- */
void rtl8735b_usb_phy_init(void)
{
    printf("[USB] Starting USB power/PHY init...\n");

    /* Step 1: Pre-init register writes (from dwc_otg_power_init disasm) */
    volatile uint32_t *reg_40000008 = (volatile uint32_t *)0x40000008UL;
    uint32_t val = *reg_40000008;
    val &= ~0xF0000UL;   /* Clear bits 16-19 */
    *reg_40000008 = val;
    val = *reg_40000008;
    val &= ~0x0FUL;      /* Clear bits 0-3 */
    *reg_40000008 = val;

    volatile uint32_t *reg_40009090 = (volatile uint32_t *)0x40009090UL;
    val = *reg_40009090;
    val &= ~0x02UL;      /* Clear bit 1 */
    *reg_40009090 = val;

    /* Step 2: Enable USB OTG peripheral via SDK HAL
     * This properly configures SYSON_S_REG_SYS_OTG_CTRL (0x50000920):
     * - Sets OTG_EN, OTG_CLK_EN, UTMI_CLK_EN
     * - Sets USB power bits (USBD_EN, UAHV_EN, UABG_EN, PDN33)
     * - Clears isolation bits (ISO_USBD_EN, ISO_USBA_EN)
     */
    printf("[USB] Calling hal_sys_peripheral_en(OTG=%d, enable=1)...\n", OTG_SYS_CTRL);
    hal_sys_peripheral_en(OTG_SYS_CTRL, 1);

    /* Settle delay after power-up */
    volatile uint32_t dly = 200000UL;
    while (dly--) { __asm volatile ("nop"); }

    /* Read back clock control register for debug */
    uint32_t clk_val = REG32(HP_OTG_FUNC_CLK_CTRL_ADDR);
    printf("[USB] HP_OTG_FUNC_CLK_CTRL = 0x%08lX\n", (unsigned long)clk_val);

    /* Step 3: Program USB PHY registers */
    dwc_uphy_init();

    /* Step 4: Enable addon register — PHY and OTG core */
    volatile uint32_t *addon_ctrl =
        (volatile uint32_t *)(USB_OTG_REG_BASE + USB_OTG_ADDON_REG_CTRL);

    uint32_t addon = *addon_ctrl;
    printf("[USB] Addon reg before = 0x%08lX\n", (unsigned long)addon);

    addon |= (USB_OTG_ADDON_USB_APHY_EN |    /* bit 14 */
              USB_OTG_ADDON_USB_DPHY_FEN |    /* bit 9  */
              USB_OTG_ADDON_USB_OTG_RST);     /* bit 8  */
    *addon_ctrl = addon;

    /* Step 5: Wait for PHY PLL lock (UPLL_CKRDY, bit 5) */
    uint32_t timeout = 500000UL;
    while (!(*addon_ctrl & USB_OTG_ADDON_UPLL_CKRDY) && --timeout) {
        __asm volatile ("nop");
    }

    addon = *addon_ctrl;
    printf("[USB] Addon reg after = 0x%08lX (UPLL_CKRDY=%s)\n",
           (unsigned long)addon,
           (addon & USB_OTG_ADDON_UPLL_CKRDY) ? "YES" : "NO");

    if (!(addon & USB_OTG_ADDON_UPLL_CKRDY)) {
        printf("[USB] ERROR: PHY PLL did not lock!\n");
    } else {
        printf("[USB] PHY PLL locked OK\n");
    }

    /* Verify GHWCFG registers are now readable */
    uint32_t gsnpsid = DWC2_READ_REG32(USB_OTG_REG_BASE, 0x040UL);
    printf("[USB] GSNPSID = 0x%08lX (expect 0x4F54xxxx for DWC2)\n",
           (unsigned long)gsnpsid);

    /* Force B-session valid — needed for device mode when VBUS sensing is
     * not wired or not reliable. Without this, the DWC2 won't pull up D+.
     * GOTGCTL register at offset 0x000:
     *   bit 19: BValidOvEn  = 1 (enable B-valid override)
     *   bit 18: BValidOvVal = 1 (force B-session valid)
     *   bit 6:  SesReqScs   = 1 (session request success)
     */
    volatile uint32_t *gotgctl = (volatile uint32_t *)(USB_OTG_REG_BASE + 0x000UL);
    uint32_t gotg = *gotgctl;
    gotg |= (1UL << 19) | (1UL << 18);  /* BValidOvEn + BValidOvVal */
    *gotgctl = gotg;
    printf("[USB] GOTGCTL = 0x%08lX (forced B-session valid)\n", (unsigned long)*gotgctl);

    printf("[USB] USB power/PHY init complete\n");
}

/* -------------------------------------------------------------------------
 * USB IRQ handler + setup via Realtek HAL
 * ------------------------------------------------------------------------- */
/* TinyUSB interrupt handler */
extern void dcd_int_handler(uint8_t rhport);

volatile uint32_t usb_irq_count = 0;

/* Realtek SDK IRQ handler signature: u32 handler(void *data) */
static uint32_t usb_otg_irq_handler(void *data)
{
    (void)data;
    usb_irq_count++;

    /* Debug: log interrupts — first 50 */
    if (usb_irq_count <= 50) {
        uint32_t gintsts = DWC2_READ_REG32(USB_OTG_REG_BASE, 0x014);
        uint32_t gintmsk = DWC2_READ_REG32(USB_OTG_REG_BASE, 0x018);
        uint32_t active = gintsts & gintmsk;
        uint32_t doepint0 = DWC2_READ_REG32(USB_OTG_REG_BASE, 0xB08);
        uint32_t diepint0 = DWC2_READ_REG32(USB_OTG_REG_BASE, 0x908);
        printf("[IRQ#%lu] m=0x%08lX OEP0=0x%X IEP0=0x%X\n",
               (unsigned long)usb_irq_count, (unsigned long)active,
               (unsigned)doepint0, (unsigned)diepint0);
    }

    dcd_int_handler(0);
    return 0;
}

static uint8_t usb_irq_registered = 0;

/* Direct NVIC register access (bypasses SDK HAL which may not work for USB) */
#define NVIC_ISER  ((volatile uint32_t *)0xE000E100UL)
#define NVIC_ICER  ((volatile uint32_t *)0xE000E180UL)
#define NVIC_IPR   ((volatile uint8_t  *)0xE000E400UL)

void rtl8735b_usb_irq_disable(void)
{
    NVIC_ICER[USB_OTG_IRQ_NUM / 32] = (1UL << (USB_OTG_IRQ_NUM % 32));
}

void rtl8735b_usb_irq_setup(void)
{
    if (usb_irq_registered) {
        NVIC_ISER[USB_OTG_IRQ_NUM / 32] = (1UL << (USB_OTG_IRQ_NUM % 32));
        return;
    }

    printf("[USB] Registering USB IRQ handler (IRQ %d)...\n", USB_OTG_IRQ_NUM);

    /* Register handler in SDK's vector dispatch table via HAL */
    hal_irq_set_vector((int32_t)USB_OTG_IRQ_NUM, (uint32_t)usb_otg_irq_handler);
    hal_irq_set_priority((int32_t)USB_OTG_IRQ_NUM, 6);

    /* Enable via BOTH SDK HAL and direct NVIC (belt and suspenders) */
    hal_irq_enable((int32_t)USB_OTG_IRQ_NUM);
    NVIC_ISER[USB_OTG_IRQ_NUM / 32] = (1UL << (USB_OTG_IRQ_NUM % 32));

    usb_irq_registered = 1;

    /* Verify: read NVIC ISER + read back the vector from SDK */
    uint32_t iser_val = NVIC_ISER[0];
    uint32_t vector = hal_irq_get_vector((int32_t)USB_OTG_IRQ_NUM);
    printf("[USB] NVIC ISER[0]=0x%08lX (bit25=%lu)\n",
           (unsigned long)iser_val, (unsigned long)((iser_val >> 25) & 1));
    printf("[USB] Vector for IRQ25=0x%08lX (expect 0x%08lX)\n",
           (unsigned long)vector, (unsigned long)(uint32_t)usb_otg_irq_handler);

    /* Also check: is the interrupt actually pending? */
    volatile uint32_t *nvic_ispr = (volatile uint32_t *)0xE000E200UL;
    printf("[USB] NVIC ISPR[0]=0x%08lX (pending bit25=%lu)\n",
           (unsigned long)nvic_ispr[0], (unsigned long)((nvic_ispr[0] >> 25) & 1));

    /* Force-pend the interrupt to test if handler works */
    volatile uint32_t *nvic_stir = (volatile uint32_t *)0xE000EF00UL;
    printf("[USB] Force-pending IRQ 25 via STIR...\n");
    *nvic_stir = USB_OTG_IRQ_NUM;

    /* Small delay to let ISR run */
    volatile uint32_t dly = 100000;
    while (dly--) { __asm volatile ("nop"); }
    printf("[USB] After STIR: irq_count=%lu\n", (unsigned long)usb_irq_count);
}

/* -------------------------------------------------------------------------
 * board_init
 * ------------------------------------------------------------------------- */
void board_init(void)
{
    printf("[BSP] AMB82-MINI board_init\n");
    rtl8735b_usb_phy_init();
    board_usb_print_hwcfg();
}

/* -------------------------------------------------------------------------
 * board_init_after_tusb
 * ------------------------------------------------------------------------- */
void board_init_after_tusb(void)
{
    printf("[BSP] board_init_after_tusb: USB stack is up\n");

    /* Print key DMA registers */
    printf("[BSP] GDFIFOCFG=0x%08lX GAHBCFG=0x%08lX DOEPDMA0=0x%08lX\n",
           (unsigned long)DWC2_READ_REG32(USB_OTG_REG_BASE, 0x05C),
           (unsigned long)DWC2_READ_REG32(USB_OTG_REG_BASE, 0x008),
           (unsigned long)DWC2_READ_REG32(USB_OTG_REG_BASE, 0xB14));
    printf("[BSP] DOEPCTL0=0x%08lX DOEPTSIZ0=0x%08lX GNPTXFSIZ=0x%08lX\n",
           (unsigned long)DWC2_READ_REG32(USB_OTG_REG_BASE, 0xB00),
           (unsigned long)DWC2_READ_REG32(USB_OTG_REG_BASE, 0xB10),
           (unsigned long)DWC2_READ_REG32(USB_OTG_REG_BASE, 0x028));
    board_usb_print_hwcfg();
}

/* -------------------------------------------------------------------------
 * board_usb_print_hwcfg
 * ------------------------------------------------------------------------- */
void board_usb_print_hwcfg(void)
{
    uint32_t cfg1 = DWC2_READ_REG32(USB_OTG_REG_BASE, DWC2_GHWCFG1_OFFSET);
    uint32_t cfg2 = DWC2_READ_REG32(USB_OTG_REG_BASE, DWC2_GHWCFG2_OFFSET);
    uint32_t cfg3 = DWC2_READ_REG32(USB_OTG_REG_BASE, DWC2_GHWCFG3_OFFSET);
    uint32_t cfg4 = DWC2_READ_REG32(USB_OTG_REG_BASE, DWC2_GHWCFG4_OFFSET);

    printf("[BSP] GHWCFG1=0x%08lX GHWCFG2=0x%08lX GHWCFG3=0x%08lX GHWCFG4=0x%08lX\n",
           (unsigned long)cfg1, (unsigned long)cfg2,
           (unsigned long)cfg3, (unsigned long)cfg4);

    uint32_t num_eps     = ((cfg2 >> 10) & 0xFU) + 1U;
    uint32_t dfifo_depth = (cfg3 >> 16) & 0xFFFFU;
    uint32_t num_in_eps  = (cfg4 >> 26) & 0xFU;

    printf("[BSP] Decoded: eps=%lu  dfifo=%lu words (%lu bytes)  in_eps=%lu\n",
           (unsigned long)num_eps,
           (unsigned long)dfifo_depth,
           (unsigned long)(dfifo_depth * 4UL),
           (unsigned long)num_in_eps);
}
