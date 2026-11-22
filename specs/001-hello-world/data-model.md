# Data Model: 001-hello-world

## ChipSnapshot

Logical read-only snapshot printed once at boot (not persisted).

| Field | Type | Source |
|-------|------|--------|
| target | string | `CONFIG_IDF_TARGET` |
| cores | uint8 | `esp_chip_info.cores` |
| revision_major | uint | chip_info revision / 100 |
| revision_minor | uint | chip_info revision % 100 |
| flash_bytes | uint32 | `esp_flash_get_size` |
| min_heap | uint32 | `esp_get_minimum_free_heap_size` |
| psram_bytes | uint32 | `heap_caps_get_total_size(SPIRAM)` if enabled |

## HeartbeatLine

Ephemeral log record each interval.

| Field | Type | Notes |
|-------|------|-------|
| uptime_sec | int64 | `esp_timer_get_time()` / 1e6 |
| beat_index | uint32 | Incremented each heartbeat |