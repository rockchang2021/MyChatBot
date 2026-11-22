# MyChatBot — ESP32-S3 firmware

ESP32-S3 bring-up and future chatbot firmware, developed with
[GitHub Spec Kit](https://github.com/github/spec-kit).

## Quickstart

See [specs/001-hello-world/quickstart.md](specs/001-hello-world/quickstart.md).

```bash
source scripts/idf-env.sh
idf.py set-target esp32s3
idf.py -p /dev/ttyACM0 build flash monitor
```

## Layout

- `specs/` — feature specifications and plans
- `components/platform_drv` — platform banner and heartbeat (001-hello-world)
- `main/` — thin `app_main`

## Remote

`git@github.com:rockchang2021/MyChatBot.git`