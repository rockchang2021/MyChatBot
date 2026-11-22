# MyChatBot / ESP32-S3 Firmware Constitution

## Core Principles

### I. Spec-First

Behavior MUST match `specs/*/spec.md`. Implementation MUST NOT ship ahead of
accepted specification for that feature.

### II. ESP-IDF 6.1

Target `esp32s3`. Use `sdkconfig.defaults` and `sdkconfig.defaults.esp32s3`.
Do NOT commit `sdkconfig` or `sdkconfig.old`.

### III. Layered Architecture

`main/` orchestrates only. Platform and peripheral logic live in
`components/*_drv`. `main/` MUST NOT call `esp_chip_info`, flash size, or PSRAM
helpers directly; use `platform_drv`.

### IV. Driver API Contract

Public surface is a single `include/<name>_drv.h`. All functions return
`esp_err_t`. Each driver `README.md` MUST link to its `specs/.../contracts/`
entry.

### V. Logging and Bring-Up

Use `ESP_LOGx` with a static `TAG`. UART console is the default acceptance
channel for Hello and bring-up features.

### VI. Quality Gate (Hello)

`idf.py build` MUST succeed. Validation follows
`specs/001-hello-world/quickstart.md` (flash + serial monitor).

### VII. Version Control

After converge, push to `git@github.com:rockchang2021/MyChatBot.git`. NEVER
commit `build/`, secrets, `.env`, API keys, or production tokens.

## Additional Constraints

- MINIMAL_BUILD ON for hello-scale projects unless constitution amended.
- Octal PSRAM defaults for ESP32-S3-WROOM 8MB PSRAM modules.
- No Wi-Fi credentials in repository.

## Development Workflow

Features use Spec Kit: specify → plan → tasks → implement → converge.
Amend this constitution before adopting Unity tests or multi-board BSP.

## Governance

This constitution overrides ad-hoc coding habits. Amendments update the
version footer and require a one-line changelog in the amending commit.

**Version**: 1.0.0 | **Ratified**: 2026-11-22 | **Last Amended**: 2026-11-22