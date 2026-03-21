/******************************************************************************
 *
 * AMB82 Mini - USB OTG 假資料測試
 *
 * 目的: 繞過 sensor/video module，直接送假資料到 USB UVC endpoint
 *       用來確認 USB OTG isochronous 傳輸通道是否正常
 *
 * 如果假資料能串流 → USB 正常，問題在 sensor timing
 * 如果假資料也失敗 → USB/OTG 有問題
 *
 *****************************************************************************/

#include "mmf2_module.h"
#include "module_uvcd.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "example_uvc_cam.h"
#include "platform_opts.h"
#include "log_service.h"

/*============================================================================
 * 全域變數
 *============================================================================*/
static TaskHandle_t uvc_main_handle = NULL;

/* MMF2 模組 context - 只用 UVC，不用 Video */
static mm_context_t *uvcd_ctx = NULL;

/* UVC 格式追蹤 */
extern struct uvc_format *uvc_format_ptr;

/* 外部 USB UVC 函數宣告 */
extern int usbd_uvc_get_status(void);
extern struct usbd_uvc_buffer *uvc_video_out_stream_queue(void);
extern void uvc_video_put_in_stream_queue(struct usbd_uvc_buffer *payload);
extern void usbd_wait_frame_down(void);

/*============================================================================
 * 假資料緩衝區
 * 用 NV12 格式: Y plane 全灰 (0x80), UV plane 全中性 (0x80)
 * 使用較小的 buffer 測試 USB 傳輸
 *============================================================================*/
#define FAKE_WIDTH   1920
#define FAKE_HEIGHT  1080
#define FAKE_NV12_SIZE  (FAKE_WIDTH * FAKE_HEIGHT * 3 / 2)  /* 3,110,400 bytes */

/* 用較小的 MJPEG 假資料 - 最小合法 JPEG (灰色 8x8) */
static const unsigned char fake_jpeg[] = {
    0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00, 0x01,
    0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0xFF, 0xDB, 0x00, 0x43,
    0x00, 0x08, 0x06, 0x06, 0x07, 0x06, 0x05, 0x08, 0x07, 0x07, 0x07, 0x09,
    0x09, 0x08, 0x0A, 0x0C, 0x14, 0x0D, 0x0C, 0x0B, 0x0B, 0x0C, 0x19, 0x12,
    0x13, 0x0F, 0x14, 0x1D, 0x1A, 0x1F, 0x1E, 0x1D, 0x1A, 0x1C, 0x1C, 0x20,
    0x24, 0x2E, 0x27, 0x20, 0x22, 0x2C, 0x23, 0x1C, 0x1C, 0x28, 0x37, 0x29,
    0x2C, 0x30, 0x31, 0x34, 0x34, 0x34, 0x1F, 0x27, 0x39, 0x3D, 0x38, 0x32,
    0x3C, 0x2E, 0x33, 0x34, 0x32, 0xFF, 0xC0, 0x00, 0x0B, 0x08, 0x00, 0x08,
    0x00, 0x08, 0x01, 0x01, 0x11, 0x00, 0xFF, 0xC4, 0x00, 0x1F, 0x00, 0x00,
    0x01, 0x05, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0A, 0x0B, 0xFF, 0xC4, 0x00, 0xB5, 0x10, 0x00, 0x02, 0x01, 0x03,
    0x03, 0x02, 0x04, 0x03, 0x05, 0x05, 0x04, 0x04, 0x00, 0x00, 0x01, 0x7D,
    0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05, 0x12, 0x21, 0x31, 0x41, 0x06,
    0x13, 0x51, 0x61, 0x07, 0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xA1, 0x08,
    0x23, 0x42, 0xB1, 0xC1, 0x15, 0x52, 0xD1, 0xF0, 0x24, 0x33, 0x62, 0x72,
    0x82, 0x09, 0x0A, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2A, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x43, 0x44, 0x45,
    0x46, 0x47, 0x48, 0x49, 0x4A, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5A, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x73, 0x74, 0x75,
    0x76, 0x77, 0x78, 0x79, 0x7A, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
    0x8A, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0xA2, 0xA3,
    0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6,
    0xB7, 0xB8, 0xB9, 0xBA, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9,
    0xCA, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xE1, 0xE2,
    0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xF1, 0xF2, 0xF3, 0xF4,
    0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFF, 0xDA, 0x00, 0x08, 0x01, 0x01,
    0x00, 0x00, 0x3F, 0x00, 0x7B, 0x94, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xD9
};
#define FAKE_JPEG_SIZE  sizeof(fake_jpeg)

/* NV12 假資料 buffer (動態分配) */
static unsigned char *fake_nv12_buf = NULL;

/*============================================================================
 * 假資料發送 Task
 * 直接送資料到 USB UVC endpoint，不經過 video module
 *============================================================================*/
static void fake_data_sender_task(void *param)
{
    struct usbd_uvc_buffer *payload = NULL;
    int frame_count = 0;
    int format = -1;

    printf("\r\n[FAKE] === USB OTG Fake Data Test ===\r\n");
    printf("[FAKE] Waiting for USB host to start streaming...\r\n");

    /* 等待 USB host 開始串流請求 */
    while (1) {
        if (usbd_uvc_get_status() != 0) {
            break;
        }
        vTaskDelay(100);
        if ((frame_count++ % 50) == 0) {
            printf("[FAKE] Still waiting... (uvc_status=%d, format_state=%d)\r\n",
                   usbd_uvc_get_status(),
                   uvc_format_ptr ? uvc_format_ptr->state : -1);
        }
    }

    format = uvc_format_ptr ? uvc_format_ptr->format : -1;
    printf("[FAKE] Host started streaming! format=%d, %dx%d\r\n",
           format,
           uvc_format_ptr ? uvc_format_ptr->width : 0,
           uvc_format_ptr ? uvc_format_ptr->height : 0);

    frame_count = 0;

    /* 主迴圈: 送假資料 */
    while (1) {
        if (usbd_uvc_get_status() == 0) {
            printf("[FAKE] Host stopped streaming, waiting...\r\n");
            vTaskDelay(100);
            continue;
        }

        /* 取得可用的 USB buffer */
        payload = uvc_video_out_stream_queue();
        if (payload == NULL) {
            vTaskDelay(1);
            continue;
        }

        /* 根據格式選擇假資料 */
        format = uvc_format_ptr ? uvc_format_ptr->format : FORMAT_TYPE_MJPEG;

        switch (format) {
        case FORMAT_TYPE_NV12:
        case FORMAT_TYPE_YUY2:
            /* 未壓縮: 送全灰色 NV12 */
            if (!fake_nv12_buf) {
                int w = uvc_format_ptr ? uvc_format_ptr->width : FAKE_WIDTH;
                int h = uvc_format_ptr ? uvc_format_ptr->height : FAKE_HEIGHT;
                int sz = w * h * 3 / 2;
                fake_nv12_buf = (unsigned char *)malloc(sz);
                if (fake_nv12_buf) {
                    memset(fake_nv12_buf, 0x80, sz);  /* 灰色 */
                    printf("[FAKE] Allocated NV12 buffer: %d bytes\r\n", sz);
                } else {
                    printf("[FAKE] ERROR: Failed to allocate NV12 buffer (%d bytes)\r\n", sz);
                    vTaskDelay(1000);
                    continue;
                }
            }
            payload->mem = fake_nv12_buf;
            payload->bytesused = (uvc_format_ptr ? uvc_format_ptr->width : FAKE_WIDTH) *
                                 (uvc_format_ptr ? uvc_format_ptr->height : FAKE_HEIGHT) * 3 / 2;
            break;

        case FORMAT_TYPE_MJPEG:
        default:
            /* MJPEG: 送最小合法 JPEG */
            payload->mem = (unsigned char *)fake_jpeg;
            payload->bytesused = FAKE_JPEG_SIZE;
            break;

        case FORMAT_TYPE_H264:
        case FORMAT_TYPE_H265:
            /* H.264/H.265: 送一個空的 NAL unit (SPS placeholder) */
            payload->mem = (unsigned char *)fake_jpeg;  /* 任意資料 */
            payload->bytesused = 64;  /* 小量資料測試 USB 傳輸 */
            break;
        }

        /* 送入 USB 傳輸佇列 */
        uvc_video_put_in_stream_queue(payload);

        /* 等待 USB 傳輸完成 */
        usbd_wait_frame_down();

        frame_count++;
        if ((frame_count % 100) == 0) {
            printf("[FAKE] Sent %d frames (format=%d, size=%d)\r\n",
                   frame_count, format, payload->bytesused);
        }

        /* 控制幀率 ~10 fps */
        vTaskDelay(100);
    }
}

/*============================================================================
 * UVC 主初始化 (假資料模式)
 *============================================================================*/
static void uvc_cam_init(void)
{
    printf("\r\n========================================\r\n");
    printf("  AMB82 USB OTG Fake Data Test\r\n");
    printf("  No sensor / No video module\r\n");
    printf("  Testing USB isochronous transfer only\r\n");
    printf("========================================\r\n\r\n");

    /* Step 1: 分配 UVC 格式結構 */
    uvc_format_ptr = (struct uvc_format *)malloc(sizeof(struct uvc_format));
    memset(uvc_format_ptr, 0, sizeof(struct uvc_format));
    rtw_init_sema(&uvc_format_ptr->uvcd_change_sema, 0);

    uvc_format_ptr->format = FORMAT_TYPE_MJPEG;
    uvc_format_ptr->width  = FAKE_WIDTH;
    uvc_format_ptr->height = FAKE_HEIGHT;
    uvc_format_ptr->fps    = 10;

    printf("[FAKE] Initializing USB UVC device...\r\n");

    /* Step 2: 開啟 UVC Device 模組 (這會初始化 USB) */
    uvcd_ctx = mm_module_open(&uvcd_module);
    if (!uvcd_ctx) {
        printf("[FAKE] ERROR: uvcd module open failed!\r\n");
        printf("[FAKE] This means USB OTG initialization failed.\r\n");
        return;
    }
    printf("[FAKE] USB UVC device initialized successfully!\r\n");

    /* Step 3: 啟動假資料發送 task */
    printf("[FAKE] Starting fake data sender...\r\n");
    printf("[FAKE] Open a video app on Mac to trigger streaming.\r\n");
    printf("[FAKE] Try: ffmpeg -f avfoundation -i \"USB UVC CLASS\" -t 5 test.mp4\r\n\r\n");

    xTaskCreate(fake_data_sender_task,
                "fake_sender",
                4096,
                NULL,
                tskIDLE_PRIORITY + 2,
                NULL);

    /* 主迴圈: 監控格式切換 */
    while (1) {
        rtw_down_sema(&uvc_format_ptr->uvcd_change_sema);
        printf("[FAKE] Format change requested: format=%d, %dx%d @ %d fps\r\n",
               uvc_format_ptr->format,
               uvc_format_ptr->width,
               uvc_format_ptr->height,
               uvc_format_ptr->fps);

        /* 釋放舊的 NV12 buffer (下次會重新分配) */
        if (fake_nv12_buf) {
            free(fake_nv12_buf);
            fake_nv12_buf = NULL;
        }
    }
}

/*============================================================================
 * FreeRTOS Task Entry
 *============================================================================*/
static void dump_dwc2_regs_old(void)
{
    #define USB_BASE 0x400C0000UL
    #define RD(off) (*(volatile unsigned int *)(USB_BASE + (off)))
    printf("\n=== DWC2 REALTEK REG DUMP ===\n");
    printf("GOTGCTL  = 0x%08X\n", RD(0x000));
    printf("GOTGINT  = 0x%08X\n", RD(0x004));
    printf("GAHBCFG  = 0x%08X\n", RD(0x008));
    printf("GUSBCFG  = 0x%08X\n", RD(0x00C));
    printf("GRSTCTL  = 0x%08X\n", RD(0x010));
    printf("GINTSTS  = 0x%08X\n", RD(0x014));
    printf("GINTMSK  = 0x%08X\n", RD(0x018));
    printf("GRXFSIZ  = 0x%08X\n", RD(0x024));
    printf("GNPTXFSIZ= 0x%08X\n", RD(0x028));
    printf("GSNPSID  = 0x%08X\n", RD(0x040));
    printf("GHWCFG1  = 0x%08X\n", RD(0x044));
    printf("GHWCFG2  = 0x%08X\n", RD(0x048));
    printf("GHWCFG3  = 0x%08X\n", RD(0x04C));
    printf("GHWCFG4  = 0x%08X\n", RD(0x050));
    printf("DCFG     = 0x%08X\n", RD(0x800));
    printf("DCTL     = 0x%08X\n", RD(0x804));
    printf("DSTS     = 0x%08X\n", RD(0x808));
    printf("DIEPMSK  = 0x%08X\n", RD(0x810));
    printf("DOEPMSK  = 0x%08X\n", RD(0x814));
    printf("DAINT    = 0x%08X\n", RD(0x818));
    printf("DAINTMSK = 0x%08X\n", RD(0x81C));
    printf("DIEPTXF0 = 0x%08X\n", RD(0x028));
    printf("DIEPTXF1 = 0x%08X\n", RD(0x104));
    printf("DIEPTXF2 = 0x%08X\n", RD(0x108));
    printf("DOEPCTL0 = 0x%08X\n", RD(0xB00));
    printf("DOEPTSIZ0= 0x%08X\n", RD(0xB10));
    printf("DOEPCTL1 = 0x%08X\n", RD(0xB20));
    printf("DIEPCTL0 = 0x%08X\n", RD(0x900));
    printf("DIEPCTL1 = 0x%08X\n", RD(0x920));
    printf("PCGCCTL  = 0x%08X\n", RD(0xE00));
    printf("ADDON    = 0x%08X\n", RD(0x30004));
    printf("GPVNDCTL = 0x%08X\n", RD(0x034));
    printf("=== END REALTEK DUMP ===\n\n");
    #undef RD
    #undef USB_BASE
}

static void uvc_cam_main_task(void *param)
{
#if defined(configENABLE_TRUSTZONE) && (configENABLE_TRUSTZONE == 1) && defined(CONFIG_PLATFORM_8735B)
    rtw_create_secure_context(configMINIMAL_SECURE_STACK_SIZE);
#endif
    uvc_cam_init();

    /* Dump DWC2 registers AFTER Realtek's full USB init */
    vTaskDelay(pdMS_TO_TICKS(3000));  /* Wait 3s for USB enumeration to complete */
    dump_dwc2_regs_old();

    vTaskDelete(NULL);
}

/*============================================================================
 * AT 指令
 *============================================================================*/
static log_item_t uvc_at_items[] = {
    {"UVCD", NULL,},
    {"UVCE", NULL,},
};

void atcmd_uvc_init(void)
{
    log_service_add_table(uvc_at_items,
                          sizeof(uvc_at_items) / sizeof(uvc_at_items[0]));
}

/*============================================================================
 * Public API
 *============================================================================*/
void example_uvc_cam(void)
{
    if (xTaskCreate(uvc_cam_main_task,
                    "uvc_fake_test",
                    4096,
                    NULL,
                    tskIDLE_PRIORITY + 1,
                    &uvc_main_handle) != pdPASS) {
        printf("[FAKE] ERROR: Failed to create main task\r\n");
    }
}
