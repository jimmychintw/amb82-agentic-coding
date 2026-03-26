/******************************************************************************
 *
 * AMB82 Mini - USB UVC MJPEG Test (MMF2 Pipeline)
 *
 * 使用 SDK 的 array_module → SISO → uvcd_module 架構
 * 送 1920x1080 綠色 JPEG test pattern 到 USB UVC
 *
 *****************************************************************************/

#include "mmf2_module.h"
#include "module_uvcd.h"
#include "module_array.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "example_uvc_cam.h"
#include "platform_opts.h"
#include "log_service.h"
#include "test_jpeg.h"
#include "avcodec.h"

/*============================================================================
 * 全域變數
 *============================================================================*/
static mm_context_t *uvcd_ctx = NULL;
static mm_context_t *array_ctx = NULL;
static mm_siso_t *siso_array_uvcd = NULL;

extern struct uvc_format *uvc_format_ptr;

/*============================================================================
 * UVC 主初始化 (MMF2 Pipeline)
 *============================================================================*/
static void uvc_cam_init(void)
{
    printf("\r\n========================================\r\n");
    printf("  AMB82 USB UVC MJPEG Test\r\n");
    printf("  array_module → SISO → uvcd_module\r\n");
    printf("  Test pattern: 1920x1080 green JPEG\r\n");
    printf("========================================\r\n\r\n");

    /* Step 1: 分配 UVC 格式結構 */
    uvc_format_ptr = (struct uvc_format *)malloc(sizeof(struct uvc_format));
    memset(uvc_format_ptr, 0, sizeof(struct uvc_format));
    rtw_init_sema(&uvc_format_ptr->uvcd_change_sema, 0);

    uvc_format_ptr->format = FORMAT_TYPE_MJPEG;
    uvc_format_ptr->width  = MAX_W;
    uvc_format_ptr->height = MAX_H;
    uvc_format_ptr->fps    = UVC_FPS;

    /* Step 2: 開啟 UVCD module (初始化 USB) */
    printf("[UVC] Opening uvcd_module...\r\n");
    uvcd_ctx = mm_module_open(&uvcd_module);
    if (!uvcd_ctx) {
        printf("[UVC] ERROR: uvcd module open failed!\r\n");
        return;
    }
    printf("[UVC] uvcd_module opened OK\r\n");

    /* Step 3: 設定 MJPEG test frame array */
    printf("[UVC] Setting up MJPEG test frame (%d bytes)\r\n", TEST_JPEG_SIZE);

    static array_t jpeg_arr;
    jpeg_arr.data_addr = (uint32_t)test_jpeg_data;
    jpeg_arr.data_len = (uint32_t)TEST_JPEG_SIZE;

    array_params_t jpeg_array_params = {
        .type = AVMEDIA_TYPE_VIDEO,
        .codec_id = AV_CODEC_ID_MJPEG,
        .mode = ARRAY_MODE_LOOP,
        .u = {
            .v = {
                .fps = UVC_FPS,
            }
        }
    };

    array_ctx = mm_module_open(&array_module);
    if (array_ctx) {
        mm_module_ctrl(array_ctx, CMD_ARRAY_SET_PARAMS, (int)&jpeg_array_params);
        mm_module_ctrl(array_ctx, CMD_ARRAY_SET_ARRAY, (int)&jpeg_arr);
        mm_module_ctrl(array_ctx, CMD_ARRAY_RECOUNT_PERIOD, 0);
        mm_module_ctrl(array_ctx, MM_CMD_SET_QUEUE_LEN, 3);
        mm_module_ctrl(array_ctx, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_DYNAMIC);
        mm_module_ctrl(array_ctx, CMD_ARRAY_STREAMING, 1);
        printf("[UVC] array_module started (MJPEG %d bytes/frame @ %d fps)\r\n",
               TEST_JPEG_SIZE, UVC_FPS);
    } else {
        printf("[UVC] ERROR: array module open failed!\r\n");
        return;
    }

    /* Step 4: 建立 SISO pipeline (array → uvcd) */
    siso_array_uvcd = siso_create();
    if (siso_array_uvcd) {
#if defined(configENABLE_TRUSTZONE) && (configENABLE_TRUSTZONE == 1)
        siso_ctrl(siso_array_uvcd, MMIC_CMD_SET_SECURE_CONTEXT, 1, 0);
#endif
        siso_ctrl(siso_array_uvcd, MMIC_CMD_ADD_INPUT, (uint32_t)array_ctx, 0);
        siso_ctrl(siso_array_uvcd, MMIC_CMD_ADD_OUTPUT, (uint32_t)uvcd_ctx, 0);
        siso_start(siso_array_uvcd);
        printf("[UVC] SISO pipeline started (array → uvcd)\r\n");
    } else {
        printf("[UVC] ERROR: siso_create failed!\r\n");
        return;
    }

    /* Dump GADGET_WRAPPER_TMP after USB init */
    {
        volatile uint32_t *gw = (volatile uint32_t *)0x70449160;
        printf("[GW] After init: ");
        for (int i = 0; i < 12; i++) printf("%02x:%08X ", i*4, gw[i]);
        printf("\n");
        printf("[GW] [0x14]=%02X [0x24]=%08X\n",
               *(volatile uint8_t *)(0x70449160 + 0x14),
               *(volatile uint32_t *)(0x70449160 + 0x24));
    }

    printf("[UVC] === Ready! Open a camera app on Mac ===\r\n\r\n");

    /* 主迴圈: 監控格式切換 */
    while (1) {
        rtw_down_sema(&uvc_format_ptr->uvcd_change_sema);

        /* Dump GADGET_WRAPPER_TMP during set_alt */
        {
            printf("[GW] During set_alt: [0x14]=%02X [0x24]=%08X\n",
                   *(volatile uint8_t *)(0x70449160 + 0x14),
                   *(volatile uint32_t *)(0x70449160 + 0x24));
        }

        printf("[UVC] Format change: format=%d, %dx%d @ %d fps\r\n",
               uvc_format_ptr->format,
               uvc_format_ptr->width,
               uvc_format_ptr->height,
               uvc_format_ptr->fps);
    }
}

/*============================================================================
 * FreeRTOS Task Entry
 *============================================================================*/
static void uvc_cam_main_task(void *param)
{
#if defined(configENABLE_TRUSTZONE) && (configENABLE_TRUSTZONE == 1) && defined(CONFIG_PLATFORM_8735B)
    rtw_create_secure_context(configMINIMAL_SECURE_STACK_SIZE);
#endif
    uvc_cam_init();
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
                    "uvc_main",
                    8192,
                    NULL,
                    tskIDLE_PRIORITY + 1,
                    NULL) != pdPASS) {
        printf("[UVC] ERROR: Failed to create main task\r\n");
    }
}
