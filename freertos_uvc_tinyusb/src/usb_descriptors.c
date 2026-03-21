/**
 * @file usb_descriptors.c
 * @brief TinyUSB descriptor callbacks for AMB82-MINI CDC device (Phase 0)
 *
 * Provides the three mandatory TinyUSB descriptor callbacks:
 *   - tud_descriptor_device_cb()
 *   - tud_descriptor_configuration_cb()
 *   - tud_descriptor_string_cb()
 *
 * Because AMB82 has a High-Speed PHY, we also provide:
 *   - tud_descriptor_device_qualifier_cb()
 *   - tud_descriptor_other_speed_configuration_cb()
 */

#include <string.h>
#include "tusb.h"
#include "usb_descriptors.h"

#define USB_BCD  0x0200

//--------------------------------------------------------------------+
// Device Descriptor
//--------------------------------------------------------------------+

tusb_desc_device_t const desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = USB_BCD,

    // Use Interface Association Descriptor (IAD) for CDC
    // As required by USB Specs IAD's subclass must be common class (2) and protocol must be IAD (1)
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

    .bNumConfigurations = 0x01
};

// Invoked when received GET DEVICE DESCRIPTOR
uint8_t const *tud_descriptor_device_cb(void) {
    return (uint8_t const *) &desc_device;
}

//--------------------------------------------------------------------+
// Configuration Descriptor
//--------------------------------------------------------------------+

// CDC bulk endpoint packet size: 512 for HS, 64 for FS
#define CDC_EP_PACKET_SIZE_HS  512
#define CDC_EP_PACKET_SIZE_FS  64

#define CONFIG_TOTAL_LEN  (TUD_CONFIG_DESC_LEN + TUD_CDC_DESC_LEN)

// Full-speed configuration
uint8_t const desc_fs_configuration[] = {
    // Config number, interface count, string index, total length, attribute, power in mA
    TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, 0x00, 100),

    // Interface number, string index, EP notification address and size,
    // EP data address (out, in) and size
    TUD_CDC_DESCRIPTOR(ITF_NUM_CDC, STRID_CDC_ITF,
                       EPNUM_CDC_NOTIF, 8,
                       EPNUM_CDC_OUT, EPNUM_CDC_IN, CDC_EP_PACKET_SIZE_FS),
};

#if TUD_OPT_HIGH_SPEED
// High-speed configuration
uint8_t const desc_hs_configuration[] = {
    TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, 0x00, 100),

    TUD_CDC_DESCRIPTOR(ITF_NUM_CDC, STRID_CDC_ITF,
                       EPNUM_CDC_NOTIF, 8,
                       EPNUM_CDC_OUT, EPNUM_CDC_IN, CDC_EP_PACKET_SIZE_HS),
};

// Other-speed configuration buffer (filled at runtime)
uint8_t desc_other_speed_config[CONFIG_TOTAL_LEN];

// Device qualifier — describes what would change at the other speed
tusb_desc_device_qualifier_t const desc_device_qualifier = {
    .bLength            = sizeof(tusb_desc_device_qualifier_t),
    .bDescriptorType    = TUSB_DESC_DEVICE_QUALIFIER,
    .bcdUSB             = USB_BCD,

    .bDeviceClass       = TUSB_CLASS_MISC,
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,

    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .bNumConfigurations = 0x01,
    .bReserved          = 0x00
};

// Invoked when received GET DEVICE QUALIFIER DESCRIPTOR request
uint8_t const *tud_descriptor_device_qualifier_cb(void) {
    return (uint8_t const *) &desc_device_qualifier;
}

// Invoked when received GET OTHER SPEED CONFIGURATION DESCRIPTOR request
uint8_t const *tud_descriptor_other_speed_configuration_cb(uint8_t index) {
    (void) index;

    // Return the opposite-speed config with descriptor type patched to OTHER_SPEED_CONFIG
    memcpy(desc_other_speed_config,
           (tud_speed_get() == TUSB_SPEED_HIGH) ? desc_fs_configuration : desc_hs_configuration,
           CONFIG_TOTAL_LEN);
    desc_other_speed_config[1] = TUSB_DESC_OTHER_SPEED_CONFIG;

    return desc_other_speed_config;
}
#endif // TUD_OPT_HIGH_SPEED

// Invoked when received GET CONFIGURATION DESCRIPTOR
uint8_t const *tud_descriptor_configuration_cb(uint8_t index) {
    (void) index;

#if TUD_OPT_HIGH_SPEED
    return (tud_speed_get() == TUSB_SPEED_HIGH) ? desc_hs_configuration : desc_fs_configuration;
#else
    return desc_fs_configuration;
#endif
}

//--------------------------------------------------------------------+
// String Descriptors
//--------------------------------------------------------------------+

// Array of string descriptor pointers
static char const *string_desc_arr[] = {
    (const char[]) { 0x09, 0x04 },  // 0: Language ID — English (0x0409)
    "Realtek",                       // 1: Manufacturer
    "AMB82-MINI USB Device",         // 2: Product
    "123456",                        // 3: Serial number
    "AMB82 CDC",                     // 4: CDC interface
};

static uint16_t _desc_str[32 + 1];

// Invoked when received GET STRING DESCRIPTOR request
uint16_t const *tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    (void) langid;
    size_t chr_count;

    switch (index) {
        case STRID_LANGID:
            memcpy(&_desc_str[1], string_desc_arr[0], 2);
            chr_count = 1;
            break;

        default:
            if (index >= sizeof(string_desc_arr) / sizeof(string_desc_arr[0])) {
                return NULL;
            }

            {
                const char *str = string_desc_arr[index];
                chr_count = strlen(str);
                size_t const max_count = sizeof(_desc_str) / sizeof(_desc_str[0]) - 1;
                if (chr_count > max_count) chr_count = max_count;

                // Convert ASCII to UTF-16
                for (size_t i = 0; i < chr_count; i++) {
                    _desc_str[1 + i] = str[i];
                }
            }
            break;
    }

    // First byte = total length (header + UTF-16 chars), second byte = string type
    _desc_str[0] = (uint16_t) ((TUSB_DESC_STRING << 8) | (2 * chr_count + 2));

    return _desc_str;
}
