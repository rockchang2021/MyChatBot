# Feature Specification: ESP32-S3 Hello Bring-Up  
# 功能规格：ESP32-S3 Hello 上电

| Field | EN | ZH | 中文 |
|-------|----|----|------|
| Branch | `001-hello-world` | 功能分支 | `001-hello-world` |
| Created | 2026-11-22 | 创建日期 | 2026-11-22 |
| Status | Accepted | 状态 | 已接受 |
| Input | UART hello, chip info, heartbeat, 8MB octal PSRAM | 输入 | 串口 Hello、芯片信息、心跳、8MB 八线 PSRAM |

## User Scenarios & Testing | 用户场景与测试

### User Story 1 — Developer validates board over USB (P1)  
### 用户故事 1 — 开发者经 USB 验板（P1）

> **EN:** As a firmware developer, I need serial output after flash to confirm board, IDF target, and memory without extra tools.  
> **ZH | 中文：** 固件开发者烧录后需串口输出，以确认板子、IDF 目标与内存配置。

> **EN:** **Why P1:** Blocks all further MyChatBot hardware work. **Independent test:** `/dev/ttyACM0`, quickstart flash/monitor, read banner and heartbeats.  
> **ZH | 中文：** **优先级原因：** 阻塞后续硬件工作。**独立测试：** 接 ACM0，按 quickstart 烧录监视，读横幅与心跳。

**Acceptance Scenarios | 验收场景**

1. **Given** flashed, UART 115200, **When** reset, **Then** within 3s: hello + target, cores, revision, flash MB, min heap.  
   **中文：** 已烧录、115200，复位后 3 秒内输出 Hello 与上述字段。

2. **Given** octal PSRAM in defaults, **When** banner, **Then** PSRAM total ≈ 8 MB.  
   **中文：** 开启 Oct PSRAM 时横幅含约 8MB PSRAM。

3. **Given** running, **When** 5s elapses, **Then** INFO heartbeat with uptime, no `esp_restart`.  
   **中文：** 约 5 秒 INFO 心跳，不自动重启。

### Edge Cases | 边界情况

> **EN:** Flash size query failure → log error, skip heartbeat loop (banner may be partial). Missing SPIRAM Kconfig → omit PSRAM line, still boot.  
> **ZH | 中文：** 读 Flash 失败则打错误并停止心跳循环；未配 SPIRAM 则省略 PSRAM 行仍可启动。

## Requirements | 需求

### Functional Requirements | 功能需求

| ID | EN | ZH | 中文 |
|----|----|----|------|
| FR-001 | MUST print hello banner on default UART after boot | 上电后在默认 UART 打印可读 Hello 横幅 | |
| FR-002 | MUST report target, cores, revision, flash, min heap | 必须报告目标、核数、版本、Flash、最小堆 | |
| FR-003 | When SPIRAM enabled, report total PSRAM | 开启 SPIRAM 时报告 PSRAM 总容量 | |
| FR-004 | Heartbeat log each interval (default 5000 ms), uptime | 可配置间隔心跳（默认 5s），含 uptime | |
| FR-005 | MUST NOT auto-restart on timer | 禁止定时 `esp_restart` | |
| FR-006 | `main` delegates platform logs to `platform_drv` | 应用入口平台日志委托 `platform_drv` | |

### Key Entities | 关键实体

> **EN:** **ChipSnapshot** — target, cores, revision, flash, min heap, optional psram. **HeartbeatLine** — uptime, beat counter.  
> **ZH | 中文：** **ChipSnapshot** 启动快照；**HeartbeatLine** 周期性心跳日志字段。

## Success Criteria | 成功标准

| ID | EN | ZH | 中文 |
|----|----|----|------|
| SC-001 | Three flashes, same banner fields on same HW | 同板连续烧录 3 次横幅字段一致 | |
| SC-002 | `idf.py build` zero errors for esp32s3 | esp32s3 构建零错误 | |
| SC-003 | Heartbeat interval ≈ configured (±500 ms) | 心跳周期约等于配置值（±500ms） | |

## Assumptions | 假设

> **EN:** ESP32-S3, `ttyACM0` (CH343). ESP-IDF 6.1 per quickstart. Wi-Fi / BLE / LED out of scope.  
> **ZH | 中文：** 如上硬件与 IDF 路径；不含 Wi-Fi、BLE、LED。