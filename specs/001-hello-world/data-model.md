# Data Model: 001-hello-world  
# 数据模型：001-hello-world

## ChipSnapshot

> **EN:** Logical read-only snapshot at boot (not persisted).  
> **ZH | 中文：** 启动时只读逻辑快照，不持久化。

| Field | Type | Source | ZH | 中文 |
|-------|------|--------|----|------|
| target | string | `CONFIG_IDF_TARGET` | 目标名 | |
| cores | uint8 | `esp_chip_info.cores` | CPU 核数 | |
| revision_major | uint | revision / 100 | 主版本 | |
| revision_minor | uint | revision % 100 | 次版本 | |
| flash_bytes | uint32 | `esp_flash_get_size` | Flash 字节 | |
| min_heap | uint32 | `esp_get_minimum_free_heap_size` | 最小堆 | |
| psram_bytes | uint32 | `heap_caps_get_total_size(SPIRAM)` | PSRAM 总容量 | 可选 |

## HeartbeatLine

> **EN:** Ephemeral log record each interval.  
> **ZH | 中文：** 每个心跳周期的瞬时日志记录。

| Field | Type | Notes EN | ZH |
|-------|------|----------|-----|
| uptime_sec | int64 | `esp_timer_get_time()` / 1e6 | 运行秒数 |
| beat_index | uint32 | Incremented each beat | 递增计数 |