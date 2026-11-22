#include "platform_drv.h"

#include <inttypes.h>

#include "esp_check.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_heap_caps.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_timer.h"
#include "sdkconfig.h"

static const char *TAG = "platform_drv";

static uint32_t s_beat_index;
static bool s_initialized;

esp_err_t platform_drv_init(void)
{
    if (s_initialized) {
        return ESP_OK;
    }
    s_beat_index = 0;
    s_initialized = true;
    return ESP_OK;
}

esp_err_t platform_drv_print_banner(void)
{
    ESP_RETURN_ON_FALSE(s_initialized, ESP_ERR_INVALID_STATE, TAG, "not initialized");

    ESP_LOGI(TAG, "Hello, ESP32-S3!");

    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    uint32_t flash_size = 0;
    esp_err_t err = esp_flash_get_size(NULL, &flash_size);
    ESP_RETURN_ON_ERROR(err, TAG, "esp_flash_get_size failed");

    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    uint32_t min_heap = esp_get_minimum_free_heap_size();

    ESP_LOGI(TAG, "chip: target=%s cores=%d revision=v%u.%u",
             CONFIG_IDF_TARGET,
             chip_info.cores,
             major_rev,
             minor_rev);
    ESP_LOGI(TAG, "flash: %" PRIu32 " bytes (%.2f MB)",
             flash_size,
             (double)flash_size / (1024.0 * 1024.0));
    ESP_LOGI(TAG, "min heap: %" PRIu32 " bytes", min_heap);

#if CONFIG_SPIRAM
    uint32_t psram = heap_caps_get_total_size(MALLOC_CAP_SPIRAM);
    ESP_LOGI(TAG, "PSRAM total: %" PRIu32 " bytes", psram);
#else
    ESP_LOGI(TAG, "PSRAM: not enabled");
#endif

    return ESP_OK;
}

esp_err_t platform_drv_log_heartbeat(void)
{
    ESP_RETURN_ON_FALSE(s_initialized, ESP_ERR_INVALID_STATE, TAG, "not initialized");

    int64_t uptime_sec = esp_timer_get_time() / 1000000;
    s_beat_index++;

    ESP_LOGI(TAG, "heartbeat: uptime=%" PRId64 "s beat=%" PRIu32,
             uptime_sec,
             s_beat_index);
    return ESP_OK;
}