# MyChatBot / ESP32-S3 Firmware Constitution  
# MyChatBot / ESP32-S3 固件宪法

## Core Principles | 核心原则

### I. Spec-First | 规格先行

> **EN:** Behavior MUST match `specs/*/spec.md`. Implementation MUST NOT ship ahead of accepted specification for that feature.  
> **ZH | 中文：** 行为须符合 `specs/*/spec.md`；不得先于已验收规格实现。

### II. ESP-IDF 6.1

> **EN:** Target `esp32s3`. Use `sdkconfig.defaults` and `sdkconfig.defaults.esp32s3`. Do NOT commit `sdkconfig` or `sdkconfig.old`.  
> **ZH | 中文：** 目标 `esp32s3`；仅 defaults 入库；勿提交 `sdkconfig` / `sdkconfig.old`。

### III. Layered Architecture | 分层架构

> **EN:** `main/` orchestrates only. Logic in `components/*_drv`. `main/` MUST NOT call `esp_chip_info`, flash, or PSRAM helpers directly—use `platform_drv`.  
> **ZH | 中文：** `main/` 只编排；逻辑在 `components/*_drv`；禁止在 `main/` 直接读芯片/Flash/PSRAM。

### IV. Driver API Contract | 驱动 API 契约

> **EN:** Single public `include/<name>_drv.h`; `esp_err_t` returns; driver `README.md` links to `specs/.../contracts/`.  
> **ZH | 中文：** 单头文件对外；统一 `esp_err_t`；README 链到 contracts。

### V. Logging and Bring-Up | 日志与上电

> **EN:** `ESP_LOGx` with static `TAG`; UART is default acceptance for bring-up.  
> **ZH | 中文：** 固定 TAG 日志；串口为上电验收默认手段。

### VI. Quality Gate (Hello) | 质量门禁

> **EN:** `idf.py build` MUST succeed; validate via `specs/001-hello-world/quickstart.md`.  
> **ZH | 中文：** 须构建通过；按 quickstart 烧录与串口验收。

### VII. Version Control | 版本控制

> **EN:** Push to `git@github.com:rockchang2021/MyChatBot.git` after converge; never commit `build/`, secrets, or keys.  
> **ZH | 中文：** 收敛后推送 MyChatBot；禁止提交构建产物与密钥。

### VIII. Bilingual Markdown | 双语文档

> **EN:** Bilingual EN+ZH per `docs/markdown-bilingual-style.md` for: `specs/<feature>/**`, this `constitution.md`, and root `README.md`. Do **not** edit `.cursor/skills/**` or `.specify/templates/**`.  
> **ZH | 中文：** `specs/**`、本宪法、根目录 `README.md` 须中英对照；勿改 Spec Kit 上游技能与模板。

## Additional Constraints | 附加约束

> **EN:** MINIMAL_BUILD for hello-scale unless amended; Octal PSRAM defaults for 8MB S3-WROOM; no Wi-Fi credentials in repo.  
> **ZH | 中文：** Hello 默认 MINIMAL_BUILD；8MB 八线 PSRAM defaults；仓库无 Wi-Fi 凭据。

## Development Workflow | 开发流程

> **EN:** Spec Kit: specify → plan → tasks → implement → converge. Amend constitution before Unity or multi-board BSP.  
> **ZH | 中文：** 按 Spec Kit 流程推进；引入单测/多板前先修订宪法。

## Governance | 治理

> **EN:** Constitution overrides ad-hoc habits; amendments update version footer and one-line commit changelog.  
> **ZH | 中文：** 宪法优先；修订须更新版本脚注与提交说明。

**Version | 版本**: 1.1.2 | **Ratified | 批准**: 2026-11-22 | **Last Amended | 最后修订**: 2026-11-22