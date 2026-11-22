# Quickstart: 001-hello-world

## Prerequisites

- ESP-IDF 6.1 at `/home/chang/dp/esp32/idf-v6.1/esp-idf`
- Device on `/dev/ttyACM0`, user in `dialout`

## Build and flash

```bash
source /home/chang/dp/esp32/idf-v6.1/esp-idf/export.sh
cd /home/chang/dp/esp32s3-wroom/a-dev
idf.py set-target esp32s3
idf.py -p /dev/ttyACM0 build flash monitor
```

Exit monitor: `Ctrl+]`

## Expected log patterns

Within a few seconds after reset, monitor should contain lines similar to:

- `Hello, ESP32-S3!`
- `chip:` or `target` with `esp32s3`
- `silicon revision v0.2` (hardware-dependent)
- flash size in MB
- `min heap` or `Minimum free heap`
- `PSRAM total` near `8388608` (8 MB) when octal PSRAM is on
- Every ~5s: `heartbeat` with `uptime` and `beat`

## Convergence checklist

- [x] Build: no errors
- [x] Flash: success
- [x] Banner within 3s
- [x] Heartbeat ~5s interval
- [x] No automatic reboot loop