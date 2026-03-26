/**
 * ota_boot_target.h — OTA boot target control for AMB82-MINI
 *
 * FW2 must call ota_boot_target_fw1() at startup to ensure
 * next reboot loads FW1 (OTA Manager).
 *
 * Usage in FW2:
 *   #include "ota_boot_target.h"
 *   // at the beginning of app_example():
 *   ota_boot_target_fw1();
 */
#ifndef OTA_BOOT_TARGET_H
#define OTA_BOOT_TARGET_H

#include "flash_api.h"
#include "device_lock.h"
#include <stdio.h>

#define OTA_FW2_ADDR  0x520000
#define OTA_SECTOR_SZ 4096

/**
 * Invalidate FW2 signature so bootloader loads FW1 on next reboot.
 * Safe to call from FW2 — flips first byte of FW2 flash image.
 */
static inline void ota_boot_target_fw1(void)
{
    flash_t flash;
    static uint8_t buf[OTA_SECTOR_SZ];

    device_mutex_lock(RT_DEV_LOCK_FLASH);
    flash_stream_read(&flash, OTA_FW2_ADDR, OTA_SECTOR_SZ, buf);

    if (buf[0] == 0x52) { /* 'R' from "RTL8735B" — signature valid */
        buf[0] = ~buf[0];
        flash_erase_sector(&flash, OTA_FW2_ADDR);
        flash_burst_write(&flash, OTA_FW2_ADDR, OTA_SECTOR_SZ, buf);
        printf("[OTA] FW2 signature invalidated, next reboot → FW1\n");
    }

    device_mutex_unlock(RT_DEV_LOCK_FLASH);
}

#endif /* OTA_BOOT_TARGET_H */
