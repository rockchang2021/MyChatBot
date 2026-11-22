#pragma once

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t platform_drv_init(void);
esp_err_t platform_drv_print_banner(void);
esp_err_t platform_drv_log_heartbeat(void);

#ifdef __cplusplus
}
#endif