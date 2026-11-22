# Contract: platform_drv

**Feature**: 001-hello-world  
**Header**: `components/platform_drv/include/platform_drv.h`

## Functions

All return `esp_err_t`. `ESP_OK` on success.

### `platform_drv_init(void)`

- Idempotent: safe to call once at boot.
- Initializes internal beat counter.
- Returns `ESP_FAIL` only if future extensions require it; Hello always `ESP_OK`.

### `platform_drv_print_banner(void)`

- Logs hello string and chip/memory summary per `ChipSnapshot` in data-model.md.
- On flash size error: logs `ESP_LOGE` and returns propagated error from
  `esp_flash_get_size`.

### `platform_drv_log_heartbeat(void)`

- Logs one INFO line with uptime seconds and beat index; increments counter.

## Kconfig

- `CONFIG_PLATFORM_DRV_HEARTBEAT_PERIOD_MS` (int, default 5000): used by `main`
  for `vTaskDelay`.

## Dependencies

Allowed IDF components: `esp_hw_support`, `spi_flash`, `log`, `esp_timer`,
`heap` (via heap_caps).