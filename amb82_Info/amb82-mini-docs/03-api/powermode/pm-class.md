# PMClass Class

## Description

A class used for PowerMode control.

## Syntax

```cpp
class PMClass
```

## Members

### Public Constructors

`PMClass::PMClass` - Constructs a PMClass object.

### Public Methods

| Method | Description |
|--------|-------------|
| `PMClass::begin` | Initialize PowerMode settings |
| `PMClass::start` | Start the PowerMode of device |

## PMClass::begin

### Description

Initialize the PowerMode settings for device, include type of the mode, wake up sources, retention and related source settings.

### Syntax

```cpp
void begin(uint32_t sleep_mode, int wakeup_source, uint32_t retention, uint32_t wakeup_setting = 0);
```

### Parameters

- `sleep_mode`: Power Mode selection
  - `DEEPSLEEP_MODE` - Deep sleep mode
  - `STANDBY_MODE` - Standby mode

- `wakeup_source`: Wake up source selection (0-5)
  - 0: AON timer
  - 1: AON GPIO
  - 2: RTC
  - 3: PON GPIO
  - 4: UART/Serial1
  - 5: Gtimer0

- `retention`: Retention on/off
  - 1: On
  - 0: Off

- `wakeup_setting`: Settings for different wakeup sources (default 0)
  - AON timer: pointer to array [clock(1:4MHz; 0:100kHz), duration(seconds)]
  - AON GPIO: pin number 21 or 22
  - RTC: pointer to array [day, hour, min, sec]
  - PON GPIO: pin number 0-11
  - Gtimer0: time duration in seconds (start from 1s)

## PMClass::start

### Description

Start the PowerMode of device.

### Syntax

```cpp
void start(void);
void start(int year, int month, int day, int hour, int min, int sec);
```

### Parameters

Optional when wake up source is RTC. Default start time is 1970.1.1 00:00:00.

- `year`: Start time by year (from 1900)
- `month`: Start time by month (0-11)
- `day`: Start time by day (1-365)
- `hour`: Start time by hour (0-23)
- `min`: Start time by min (0-59)
- `sec`: Start time by sec (0-59)

## Example Code

- DeepSleepMode
- StandbyMode
- RetentionDeepSleepMode
- RetentionStandbyMode