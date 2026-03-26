#ifndef EXAMPLE_UVC_CAM_H
#define EXAMPLE_UVC_CAM_H

#include "sensor.h"
#include "uvc/inc/usbd_uvc_desc.h"

/*============================================================================
 * UVC Camera Configuration
 *
 * 將 AMB82 Mini 當作 USB 攝影機，透過 USB OTG 傳送影像到 PC。
 * 預設使用 MJPEG 格式，相容性最佳 (VLC/Zoom/OBS/Google Meet)。
 *============================================================================*/

/* 影像通道配置 */
#define UVC_CHANNEL     0
#define UVC_RESOLUTION  VIDEO_FHD       /* VIDEO_VGA / VIDEO_HD / VIDEO_FHD */
#define UVC_FPS         24
#define UVC_GOP         (UVC_FPS * 3)   /* GOP = 3 秒 */
#define UVC_BPS         (2 * 1024 * 1024)  /* 2 Mbps */
#define UVC_RCMODE      2               /* 1: CBR, 2: VBR */

/* 影像格式 - 選擇其一 */
#define UVC_VIDEO_TYPE  VIDEO_JPEG      /* MJPEG: 相容性最佳 */
// #define UVC_VIDEO_TYPE  VIDEO_H264   /* H.264: 壓縮率高 */
// #define UVC_VIDEO_TYPE  VIDEO_HEVC   /* H.265: 最佳壓縮 */
// #define UVC_VIDEO_TYPE  VIDEO_NV16   /* YUY2: 無壓縮 */

/* 感測器最大解析度 */
#define MAX_W   sensor_params[USE_SENSOR].sensor_width
#define MAX_H   sensor_params[USE_SENSOR].sensor_height

/* 啟用的 UVC 格式 (PC 端可選) */
#define UVCD_YUY2   0
#define UVCD_NV12   0
#define UVCD_MJPG   1
#define UVCD_H264   0
#define UVCD_H265   0

/* Tuning 模式 (一般使用設為 0) */
#define UVCD_TUNNING_MODE           0
#define CUSTOMER_AMEBAPRO_ADVANCE   0

void example_uvc_cam(void);

#endif /* EXAMPLE_UVC_CAM_H */
