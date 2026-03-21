/**
 * @file app_example.c
 * @brief AMB82-MINI TinyUSB CDC device — Phase 0 bring-up application
 *
 * Creates a single FreeRTOS task that runs the TinyUSB device stack and
 * echoes any incoming CDC data back to the host.
 */

#include "FreeRTOS.h"
#include "task.h"
#include "tusb.h"
#include "board_amb82.h"

// Stack depth in 32-bit words (4096 bytes)
#define USBD_STACK_SIZE  (4096 / sizeof(StackType_t))

//--------------------------------------------------------------------+
// USB Device Task
//--------------------------------------------------------------------+

/**
 * @brief USB device task — processes TinyUSB events at high priority.
 *
 * This task must not block for long periods; tud_task() returns quickly
 * when there is nothing to do.
 */
static void usb_device_task(void *param) {
    (void) param;

    // Initialise TinyUSB device stack
    // tusb_init() is the 0.17.0 API — it calls tud_init(BOARD_TUD_RHPORT) internally
    tusb_init();

    // Any post-stack board actions (e.g. enable VBUS switch)
    board_init_after_tusb();

    // Dump DWC2 hardware config registers for bring-up verification
    board_usb_print_hwcfg();

    printf("[TinyUSB] Device task running\n");

    while (1) {
        // Process all pending USB events (non-blocking)
        tud_task();

        // CDC echo: read whatever the host sent and echo it back
        if (tud_cdc_available()) {
            uint8_t buf[64];
            uint32_t count = tud_cdc_read(buf, sizeof(buf));
            tud_cdc_write(buf, count);
            tud_cdc_write_flush();
        }
    }
}

//--------------------------------------------------------------------+
// TinyUSB Device Callbacks
//--------------------------------------------------------------------+

void tud_mount_cb(void) {
    printf("[TinyUSB] Device mounted\n");
}

void tud_umount_cb(void) {
    printf("[TinyUSB] Device unmounted\n");
}

void tud_suspend_cb(bool remote_wakeup_en) {
    (void) remote_wakeup_en;
    printf("[TinyUSB] Suspended\n");
}

void tud_resume_cb(void) {
    printf("[TinyUSB] Resumed\n");
}

//--------------------------------------------------------------------+
// Entry Point
//--------------------------------------------------------------------+

/**
 * @brief Example entry point — called by the FreeRTOS scheduler startup.
 *
 * The function name must match EXAMPLE_NAME defined in build.sh so that
 * the Realtek SDK's example dispatch table finds it.
 */
void app_example(void) {
    printf("[TinyUSB] Starting AMB82 USB device...\n");

    // Early board init (prints GHWCFG register snapshot before stack starts)
    board_init();

    xTaskCreate(usb_device_task,
                "usbd",
                USBD_STACK_SIZE,
                NULL,
                configMAX_PRIORITIES - 1,
                NULL);
}
