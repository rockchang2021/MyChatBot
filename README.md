# MyChatBot — ESP32-S3 Firmware | MyChatBot — ESP32-S3 固件

> **EN:** ESP32-S3 bring-up and future chatbot firmware using [GitHub Spec Kit](https://github.com/github/spec-kit).  
> **ZH | 中文：** ESP32-S3 上电与后续聊天机器人固件，采用 [GitHub Spec Kit](https://github.com/github/spec-kit) 规格驱动开发。

> **EN:** Bilingual docs (maintenance): `specs/**`, this file, `.specify/memory/constitution.md` — see `docs/markdown-bilingual-style.md`. Vendor `.cursor/skills/` and `.specify/templates/` are not modified.  
> **ZH | 中文：** 维护用双语文档：`specs/**`、本 README、`constitution.md`；见 `docs/markdown-bilingual-style.md`。不改动 Spec Kit 上游技能/模板。

## Quickstart | 快速开始

> **EN:** [specs/001-hello-world/quickstart.md](specs/001-hello-world/quickstart.md)  
> **ZH | 中文：** 烧录与验收见 [quickstart.md](specs/001-hello-world/quickstart.md)

```bash
source scripts/idf-env.sh
idf.py set-target esp32s3
idf.py -p /dev/ttyACM0 build flash monitor
```

## Layout | 目录结构

| Path | EN | ZH |
|------|----|-----|
| `specs/` | Feature specs & plans (bilingual) | 功能规格与计划（双语） |
| `.specify/memory/constitution.md` | Project rules (bilingual) | 项目宪法（双语） |
| `components/platform_drv` | Hello banner / heartbeat (001) | 平台上电与心跳（001） |
| `main/` | Thin `app_main` | 薄应用入口 |

## Remote | 远程仓库

`git@github.com:rockchang2021/MyChatBot.git`