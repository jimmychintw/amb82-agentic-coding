/**
 * @file board_amb82.c
 * @brief Board-support implementation for AMB82-MINI (RTL8735B)
 *
 * Implements the three BSP functions declared in board_amb82.h.
 *
 * Notes
 * -----
 * - The USB PHY clock/power sequence is NOT performed here.  It is instead
 *   embedded in dwc2_phy_init() (in dwc2_rtl8735b.h), which TinyUSB calls
 *   automatically during dcd_init().  This keeps the init path contained
 *   inside the DWC2 port header, consistent with other TinyUSB ports.
 *
 * - printf() calls rely on the Realtek SDK's UART console which is already
 *   initialised by the FreeRTOS startup code before any application task runs.
 */

#include <stdint.h>
#include "board_amb82.h"
#include "dwc2_rtl8735b.h"   /* USB_OTG_REG_BASE, DWC2_READ_REG32 */

/* -------------------------------------------------------------------------
 * DWC2 hardware configuration register offsets (from GHWCFG1..4 in DWC2 spec)
 * These are at GLOBAL_BASE + 0x044 .. 0x050.
 * ------------------------------------------------------------------------- */
#define DWC2_GHWCFG1_OFFSET   0x044UL
#define DWC2_GHWCFG2_OFFSET   0x048UL
#define DWC2_GHWCFG3_OFFSET   0x04CUL
#define DWC2_GHWCFG4_OFFSET   0x050UL

/* -------------------------------------------------------------------------
 * board_init
 * ------------------------------------------------------------------------- */
void board_init(void)
{
    printf("[BSP] AMB82-MINI board_init: USB OTG reg base = 0x%08lX\n",
           (unsigned long)USB_OTG_REG_BASE);
    printf("[BSP] USB IRQ number = %d\n", USB_OTG_IRQ_NUM);

    /* Print USB hardware config for diagnostic purposes */
    board_usb_print_hwcfg();
}

/* -------------------------------------------------------------------------
 * board_init_after_tusb
 * ------------------------------------------------------------------------- */
void board_init_after_tusb(void)
{
    /* Placeholder — nothing required for initial CDC bring-up.
     * Future uses: enable VBUS power switch, start LED blink task, etc. */
    printf("[BSP] board_init_after_tusb: USB stack is up\n");
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

    printf("[BSP] USB DWC2 HW Config Registers:\n");
    printf("[BSP]   GHWCFG1 = 0x%08lX  (endpoint direction bitmap)\n",
           (unsigned long)cfg1);
    printf("[BSP]   GHWCFG2 = 0x%08lX  (OTG mode, arch, endpoints, FIFO)\n",
           (unsigned long)cfg2);
    printf("[BSP]   GHWCFG3 = 0x%08lX  (DFIFO depth, packet counts)\n",
           (unsigned long)cfg3);
    printf("[BSP]   GHWCFG4 = 0x%08lX  (IN endpoint count, power opt, phy)\n",
           (unsigned long)cfg4);

    /* Decode a few key fields for convenience */
    uint32_t num_eps       = ((cfg2 >> 10) & 0xFU) + 1U; /* GHWCFG2[13:10] */
    uint32_t dfifo_depth   = (cfg3 >> 16) & 0xFFFFU;      /* GHWCFG3[31:16], in 32-bit words */
    uint32_t num_in_eps    = (cfg4 >> 26) & 0xFU;          /* GHWCFG4[29:26] */

    printf("[BSP]   Decoded: num_eps=%lu  dfifo_depth=%lu words (%lu bytes)  num_in_eps=%lu\n",
           (unsigned long)num_eps,
           (unsigned long)dfifo_depth,
           (unsigned long)(dfifo_depth * 4UL),
           (unsigned long)num_in_eps);
}
