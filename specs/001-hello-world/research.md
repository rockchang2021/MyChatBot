# Research: 001-hello-world  
# 调研：001-hello-world

## ESP-IDF References | IDF 参考

> **EN:** Official hello_world: `idf-v6.1/esp-idf/examples/get-started/hello_world`. MINIMAL_BUILD trims components for bring-up.  
> **ZH | 中文：** 官方 hello_world 示例；`MINIMAL_BUILD` 用于精简上电工程组件集。

## Hardware | 硬件（2026-11-22 实测）

| Item 项目 | Value 值 | ZH | 中文 |
|-----------|----------|----|------|
| Chip | ESP32-S3 (QFN56) v0.2 | 芯片 | |
| PSRAM | 8MB embedded octal | 内置八线 PSRAM | esptool 探测 |
| Port | `/dev/ttyACM0` | 串口 | |
| MAC | `c0:4e:30:37:11:c0` | MAC | |

## sdkconfig | 配置

> **EN:** Octal PSRAM (IDF internal test defaults pattern):  
> **ZH | 中文：** 八线 PSRAM 推荐 defaults：

```ini
CONFIG_SPIRAM=y
CONFIG_SPIRAM_MODE_OCT=y
CONFIG_SPIRAM_SPEED_80M=y
```

> **EN:** `platform_drv` should `PRIV_REQUIRES esp_psram` so Kconfig symbols apply under MINIMAL_BUILD.  
> **ZH | 中文：** `platform_drv` 需依赖 `esp_psram`，否则 MINIMAL_BUILD 下 defaults 可能不生效。

## Serial | 串口

> **EN:** UART console 115200 8N1 via ACM; user in `dialout`.  
> **ZH | 中文：** 115200 8N1，ACM；`dialout` 组。