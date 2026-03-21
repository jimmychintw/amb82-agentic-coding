/**
 * FreeRTOS Blink LED Example for AMB82 Mini
 *
 * Blinks the onboard blue LED (PF_9) using FreeRTOS task.
 */
#include "FreeRTOS.h"
#include "task.h"
#include "gpio_api.h"
#include "PinNames.h"

/* AMB82 Mini onboard blue LED = PF_9 */
#define LED_PIN  PF_9

static void blink_task(void *param)
{
    gpio_t gpio_led;

    gpio_init(&gpio_led, LED_PIN);
    gpio_dir(&gpio_led, PIN_OUTPUT);
    gpio_mode(&gpio_led, PullNone);

    printf("FreeRTOS Blink - Starting!\n");

    while (1) {
        gpio_write(&gpio_led, 1);
        printf("LED ON\n");
        vTaskDelay(pdMS_TO_TICKS(500));

        gpio_write(&gpio_led, 0);
        printf("LED OFF\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void app_example(void)
{
    xTaskCreate(blink_task, "blink", 1024, NULL, tskIDLE_PRIORITY + 1, NULL);
}
