/*
 * Thin application entry for 001-hello-world (Spec Kit).
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_check.h"
#include "platform_drv.h"
#include "sdkconfig.h"

void app_main(void)
{
    if (platform_drv_init() != ESP_OK) {
        ESP_LOGE("app", "platform_drv_init failed");
        return;
    }
    esp_err_t err = platform_drv_print_banner();
    if (err != ESP_OK) {
        return;
    }

    const TickType_t period = pdMS_TO_TICKS(CONFIG_PLATFORM_DRV_HEARTBEAT_PERIOD_MS);
    for (;;) {
        vTaskDelay(period);
        if (platform_drv_log_heartbeat() != ESP_OK) {
            break;
        }
    }
}