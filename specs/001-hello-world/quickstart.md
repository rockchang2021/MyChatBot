# Quickstart: 001-hello-world  
# 快速开始：001-hello-world

## Prerequisites | 前置条件

> **EN:** ESP-IDF 6.1 at `/home/chang/dp/esp32/idf-v6.1/esp-idf`. Device on `/dev/ttyACM0`, user in `dialout`.  
> **ZH | 中文：** ESP-IDF 6.1 路径如上；设备 `/dev/ttyACM0`；用户在 `dialout` 组。

## Build and flash | 编译与烧录

```bash
source /home/chang/dp/esp32/idf-v6.1/esp-idf/export.sh
cd /home/chang/dp/esp32s3-wroom/a-dev
idf.py set-target esp32s3
idf.py -p /dev/ttyACM0 build flash monitor
```

> **EN:** Exit monitor: `Ctrl+]`.  
> **ZH | 中文：** 退出监视器：`Ctrl+]`。

## Expected log patterns | 预期日志

> **EN:** After reset, within a few seconds, expect:  
> **ZH | 中文：** 复位后数秒内应出现：

- `Hello, ESP32-S3!`
- `chip:` / `target` = `esp32s3` | 芯片目标 esp32s3
- `silicon revision v0.2` (HW-dependent) | 硅片版本（依硬件）
- flash size in MB | Flash 容量（MB）
- `min heap` | 最小堆
- `PSRAM total` ≈ `8388608` (8 MB) when Oct PSRAM on | 八线 PSRAM 开启时约 8MB
- Every ~5s: `heartbeat` with `uptime` and `beat` | 约 5 秒心跳

## Convergence checklist | 收敛检查

| Item | EN | ZH | 状态 |
|------|----|----|------|
| Build | no errors | 构建无错 | [x] |
| Flash | success | 烧录成功 | [x] |
| Banner | within 3s | 3 秒内横幅 | [x] |
| Heartbeat | ~5s interval | 约 5 秒间隔 | [x] |
| Reboot | no auto reboot loop | 无自动重启循环 | [x] |