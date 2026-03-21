/**
 * @file tusb_config.h
 * @brief TinyUSB configuration for AMB82-MINI (RTL8735B)
 *
 * This header is included by TinyUSB's tusb_option.h via the compiler's
 * include path.  It selects the DWC2 device driver and activates the
 * RTL8735B-specific port header (dwc2_rtl8735b.h).
 */

#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------
 * Select RTL8735B DWC2 IP variant.
 * TUP_USBIP_DWC2        — activates the generic DWC2 device driver
 * TUP_USBIP_DWC2_RTL8735B — selects dwc2_rtl8735b.h inside dcd_dwc2.c
 * ------------------------------------------------------------------------- */
#define TUP_USBIP_DWC2              1
#define TUP_USBIP_DWC2_RTL8735B    1
#define TUP_DCD_ENDPOINT_MAX        6   /* Conservative; verify from GHWCFG2 */

/* -------------------------------------------------------------------------
 * TinyUSB operating mode
 * ------------------------------------------------------------------------- */
#define CFG_TUSB_RHPORT0_MODE       (OPT_MODE_DEVICE | OPT_MODE_HIGH_SPEED)

/* -------------------------------------------------------------------------
 * RTOS: FreeRTOS is used on AMB82-MINI
 * ------------------------------------------------------------------------- */
#define CFG_TUSB_OS                 OPT_OS_FREERTOS

/* -------------------------------------------------------------------------
 * Debug level (0 = off, 1 = error, 2 = warning, 3 = info)
 * Set to 1 for bring-up; reduce to 0 for production.
 * ------------------------------------------------------------------------- */
#ifndef CFG_TUSB_DEBUG
#define CFG_TUSB_DEBUG              1
#endif

/* -------------------------------------------------------------------------
 * Device class enablement
 * CDC enabled for initial bring-up / serial debug
 * ------------------------------------------------------------------------- */
#define CFG_TUD_CDC                 1
#define CFG_TUD_CDC_RX_BUFSIZE      512
#define CFG_TUD_CDC_TX_BUFSIZE      512

/* UVC will be enabled in a later task */
#define CFG_TUD_VIDEO               0

/* UAC will be enabled in a later task */
#define CFG_TUD_AUDIO               0

/* Disable unused classes */
#define CFG_TUD_MSC                 0
#define CFG_TUD_HID                 0
#define CFG_TUD_MIDI                0
#define CFG_TUD_VENDOR              0

/* -------------------------------------------------------------------------
 * Endpoint and buffer limits
 * ------------------------------------------------------------------------- */
#define CFG_TUD_ENDPOINT0_SIZE      64

#ifdef __cplusplus
}
#endif

#endif /* _TUSB_CONFIG_H_ */
