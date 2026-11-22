# Contract: platform_drv  
# 契约：platform_drv

| Field | EN | ZH |
|-------|----|-----|
| Feature | 001-hello-world | 功能 001 |
| Header | `components/platform_drv/include/platform_drv.h` | 头文件 |

## Functions | 函数

> **EN:** All return `esp_err_t`; `ESP_OK` on success.  
> **ZH | 中文：** 均返回 `esp_err_t`；成功为 `ESP_OK`。

### `platform_drv_init(void)`

> **EN:** Idempotent at boot; initializes beat counter; Hello always `ESP_OK`.  
> **ZH | 中文：** 上电可幂等调用；初始化心跳计数；Hello 阶段恒 `ESP_OK`。

### `platform_drv_print_banner(void)`

> **EN:** Logs hello and `ChipSnapshot` fields; on flash error logs `ESP_LOGE` and returns error from `esp_flash_get_size`.  
> **ZH | 中文：** 打印 Hello 与芯片/内存摘要；Flash 读失败则 `ESP_LOGE` 并返回错误。

### `platform_drv_log_heartbeat(void)`

> **EN:** One INFO line: uptime seconds and beat index; increments counter.  
> **ZH | 中文：** 一条 INFO：uptime 与 beat；计数加一。

## Kconfig

> **EN:** `CONFIG_PLATFORM_DRV_HEARTBEAT_PERIOD_MS` (default 5000) — used by `main` for `vTaskDelay`.  
> **ZH | 中文：** 心跳周期毫秒（默认 5000），`main` 中 `vTaskDelay` 使用。

## Dependencies | 依赖

> **EN:** Allowed IDF components: `esp_hw_support`, `spi_flash`, `log`, `esp_timer`, `heap`, `esp_psram`.  
> **ZH | 中文：** 允许依赖上述 IDF 组件。