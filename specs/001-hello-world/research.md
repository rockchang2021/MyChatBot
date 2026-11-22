# Research: 001-hello-world

## ESP-IDF References

- Official hello_world example: `idf-v6.1/esp-idf/examples/get-started/hello_world`
- MINIMAL_BUILD reduces component set for bring-up.

## Hardware (measured on rock's machine, 2026-11-22)

| Item | Value |
|------|-------|
| Chip | ESP32-S3 (QFN56) rev v0.2 |
| PSRAM | 8MB embedded octal (esptool) |
| Port | `/dev/ttyACM0` |
| MAC | `c0:4e:30:37:11:c0` |

## sdkconfig

Octal PSRAM per IDF internal test defaults:

```ini
CONFIG_SPIRAM=y
CONFIG_SPIRAM_MODE_OCT=y
CONFIG_SPIRAM_SPEED_80M=y
```

## Serial

Default UART console 1158400 8N1 via ACM; user in `dialout` group.