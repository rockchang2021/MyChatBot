# Tasks: 001-hello-world

## Phase 1: Project scaffold

- [x] T1.1 Root CMakeLists, sdkconfig.defaults, sdkconfig.defaults.esp32s3
- [x] T1.2 Root .gitignore and README.md

## Phase 2: Driver component [P]

- [x] T2.1 `components/platform_drv` (CMakeLists, Kconfig, header, source)
- [x] T2.2 Implement contract platform_drv-api.md

## Phase 3: Application

- [x] T3.1 Thin `main/app_main.c` and CMakeLists

## Phase 4: Validation

- [x] T4.1 `idf.py set-target esp32s3 build`
- [x] T4.2 `idf.py -p /dev/ttyACM0 flash` and monitor sample vs quickstart

## Phase 5: Publish

- [ ] T5.1 Git commit and push to MyChatBot origin