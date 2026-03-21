/**
 * @file usb_descriptors.h
 * @brief USB descriptor constants for AMB82-MINI TinyUSB CDC device (Phase 0)
 */

#ifndef USB_DESCRIPTORS_H
#define USB_DESCRIPTORS_H

// Development VID/PID
#define USB_VID   0xCafe
#define USB_PID   0x4000

// String descriptor indices
enum {
    STRID_LANGID = 0,
    STRID_MANUFACTURER,
    STRID_PRODUCT,
    STRID_SERIAL,
    STRID_CDC_ITF,
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

#endif /* USB_DESCRIPTORS_H */
