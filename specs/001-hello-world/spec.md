# Feature Specification: ESP32-S3 Hello Bring-Up

**Feature Branch**: `001-hello-world`

**Created**: 2026-11-22

**Status**: Accepted

**Input**: ESP32-S3 bring-up: UART hello, chip info, heartbeat, 8MB octal PSRAM.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Developer validates board over USB (Priority: P1)

As a firmware developer, I need serial output after flash so I can confirm the
board, IDF target, and memory configuration without extra tools.

**Why this priority**: Blocks all further MyChatBot hardware work.

**Independent Test**: Connect `/dev/ttyACM0`, run quickstart flash/monitor, read
banner and repeating heartbeat lines.

**Acceptance Scenarios**:

1. **Given** firmware is flashed and UART is 115200, **When** the chip resets,
   **Then** within 3 seconds logs include a hello message and chip target, core
   count, silicon revision, flash size (MB), and minimum heap.
2. **Given** octal PSRAM is enabled in defaults, **When** the banner prints,
   **Then** logs include PSRAM total size on the order of 8 MB.
3. **Given** the device is running, **When** 5 seconds elapse, **Then** an INFO
   heartbeat line appears with uptime and the device does not call `esp_restart`.

### Edge Cases

- Flash size query failure MUST log an error and skip the periodic heartbeat loop
  (init/banner may partially complete per driver behavior).
- Missing PSRAM Kconfig: banner omits PSRAM line without failing boot.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: System MUST print a human-readable hello banner on the default UART
  console after boot.
- **FR-002**: System MUST report ESP-IDF target name, CPU cores, silicon
  revision, flash size, and minimum free heap in the banner.
- **FR-003**: When SPIRAM is enabled, system MUST report total PSRAM capacity in
  the banner.
- **FR-004**: System MUST emit a heartbeat log at a configurable interval
  (default 5000 ms) including uptime seconds.
- **FR-005**: System MUST NOT automatically restart on a timer for this feature.
- **FR-006**: Application entry MUST delegate chip/platform logging to
  `platform_drv` per contracts.

### Key Entities

- **ChipSnapshot**: Logical snapshot of chip target, cores, revision, flash
  bytes, min heap, optional psram bytes.
- **HeartbeatLine**: Uptime seconds and monotonic beat counter for logs.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Three consecutive flash cycles produce the same banner fields on
  the same hardware.
- **SC-002**: `idf.py build` completes with zero errors for `esp32s3`.
- **SC-003**: Heartbeat appears at approximately the configured interval (±500 ms)
  on serial monitor.

## Assumptions

- Board is ESP32-S3 with USB serial on `ttyACM0` (QinHeng CH343 class).
- Developers use ESP-IDF 6.1 from the path documented in quickstart.
- Wi-Fi, BLE, and LED GPIO are out of scope for this feature.