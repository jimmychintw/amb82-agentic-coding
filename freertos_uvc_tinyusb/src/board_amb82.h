/**
 * @file board_amb82.h
 * @brief Board-support declarations for AMB82-MINI (RTL8735B)
 *
 * Provides the minimal BSP surface required by app_example.c and any
 * TinyUSB application that needs to call board_init() before tusb_init().
 */

#ifndef BOARD_AMB82_H
#define BOARD_AMB82_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Early board initialisation.
 *
 * Called once at startup, before tusb_init().
 * Prints debug information about the USB hardware registers.
 * The actual PHY clock enable sequence is performed inside dwc2_phy_init(),
 * which TinyUSB calls as part of dcd_init().
 */
void board_init(void);

/**
 * @brief Post-TinyUSB board initialisation.
 *
 * Called after tusb_init() returns successfully.
 * Placeholder for any board-level actions that must happen after the USB
 * stack is running (e.g. enabling a VBUS power switch, toggling an LED).
 */
void board_init_after_tusb(void);

/**
 * @brief Print USB hardware configuration registers to the debug console.
 *
 * Reads GHWCFG1–GHWCFG4 from USB_OTG_REG_BASE and prints the raw values.
 * Useful during initial bring-up to verify register access and decode the
 * endpoint / FIFO capabilities of the on-chip DWC2 instance.
 */
void board_usb_print_hwcfg(void);

/**
 * @brief Full USB power + PHY initialization.
 *
 * Must be called BEFORE tusb_init() — TinyUSB's dcd_init() reads GSNPSID
 * to verify DWC2 exists, which requires USB clock to be enabled first.
 * Implemented in board_amb82.c.
 */
void rtl8735b_usb_phy_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_AMB82_H */
