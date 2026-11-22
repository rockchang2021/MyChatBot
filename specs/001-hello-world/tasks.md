# Tasks: 001-hello-world  
# 任务：001-hello-world

## Phase 1: Project scaffold | 阶段 1：工程骨架

| Task | EN | ZH | 状态 |
|------|----|----|------|
| T1.1 | Root CMakeLists, sdkconfig.defaults* | 根 CMake 与 defaults | [x] |
| T1.2 | .gitignore and README.md | 忽略文件与 README | [x] |

## Phase 2: Driver component [P] | 阶段 2：驱动组件（可并行）

| Task | EN | ZH | 状态 |
|------|----|----|------|
| T2.1 | `components/platform_drv` skeleton | platform_drv 骨架 | [x] |
| T2.2 | Implement platform_drv-api contract | 实现 API 契约 | [x] |

## Phase 3: Application | 阶段 3：应用

| Task | EN | ZH | 状态 |
|------|----|----|------|
| T3.1 | Thin `main/app_main.c` | 薄 main | [x] |

## Phase 4: Validation | 阶段 4：验证

| Task | EN | ZH | 状态 |
|------|----|----|------|
| T4.1 | `idf.py set-target esp32s3 build` | 设 target 并构建 | [x] |
| T4.2 | flash/monitor vs quickstart | 烧录监视对照 quickstart | [x] |

## Phase 5: Publish | 阶段 5：发布

| Task | EN | ZH | 状态 |
|------|----|----|------|
| T5.1 | Git commit and push to MyChatBot | 提交并推送 MyChatBot | [x] |