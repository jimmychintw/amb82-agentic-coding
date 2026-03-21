Class PMClass — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [PowerMode](index.html)
- Class PMClass
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/PowerMode/Class PMClass.rst)
# Class PMClass[](#class-pmclass)
## **PMClass Class**[](#pmclass-class)
### **Description**[](#description)
A class used for PowerMode control.
### **Syntax**[](#syntax)
class PMClass
### **Members**[](#members)
|**Public Constructors**
|
|
| PMClass::PMClass
|
Constructs an PMClass object.
|
|
| **Public Methods**
|
|
| PMClass::begin
|
Initializes the PowerMode
settings for device, include type
of the mode, wake up sources
, retention and related source
settings.
|
|
| PMClass::start
|
Start the PowerMode of device.
|
|
### **PMClass::begin**[](#pmclass-begin)
### **Description**[](#id1)
Initializes the PowerMode settings for device, include type of the mode, wake up sources, retention and related source settings.
### **Syntax**[](#id2)
void begin(uint32_t sleep_mode, int wakeup_source, uint32_t retention, uint32_t wakeup_setting = 0);
### **Parameters**[](#parameters)
sleep_mode: Power Mode selection.
- Deepsleep mode: DEEPSLEEP_MODE; Standby mode: STANDBY_MODE
wakeup_source: Wake up source selection.
- AON timer, AON GPIO, RTC, PON GPIO, UART/Serial1, and Gtimer0 (0 to 5).
retention: Retention on/off
- On: 1; Off: 0
wakeup_setting: Settings for different wakeup sources. Default value is 0.
- For AON time, it is a pointer to an array that stores clock(1:4MHz; 0:100kHz) and duration(by seconds).
- For AON GPIO, it is pin number 21 or 22.
- For RTC, it is a pointer to an array that stores time duration as day, hour, min and sec(0, 0:0:0, to 365, 23:59:59).
- For PON GPIO, it is pin number 0 to 11.
- For Gtimer0, it is time duration in seconds. (start from 1s)
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [DeepSleepMode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/PowerMode/examples/DeepSleepMode/DeepSleepMode.ino) [StandbyMode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/PowerMode/examples/StandbyMode/StandbyMode.ino) [RetentionDeepSleepMode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/PowerMode/examples/RetentionDeepSleepMode/RetentionDeepSleepMode.ino) [RetentionStandbyMode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/PowerMode/examples/RetentionStandbyMode/RetentionStandbyMode.ino)
Note
“PowerMode.h” must be included to use the class function.
## **PMClass::start**[](#pmclass-start)
### **Description**[](#id3)
Start the PowerMode of device.
### **Syntax**[](#id4)
void start(void);
void start(int year, int month, int day, int hour, int min, int sec);
### **Parameters**[](#id5)
Optional when wake up source is RTC. Default start time is 1970.1.100:00:00.
year: Start time by year.
- Starts from 1900
month: Start time by month.
- 0 to 11
day: Start time by day.
- 1 to 365
hour: Start time by hour
- 0 to 23
min: Start time by min.
- 0 to 59
sec: Start time by sec.
- 0 to 59
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [DeepSleepMode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/PowerMode/examples/DeepSleepMode/DeepSleepMode.ino) [StandbyMode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/PowerMode/examples/StandbyMode/StandbyMode.ino) [RetentionDeepSleepMode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/PowerMode/examples/RetentionDeepSleepMode/RetentionDeepSleepMode.ino) [RetentionStandbyMode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/PowerMode/examples/RetentionStandbyMode/RetentionStandbyMode.ino)
Note
“PowerMode.h” must be included to use the class function.
[ Previous](index.html)
[Next ](../RTC/index.html)
[
](https://github.com/search?q=topic%3Aarduino+org%3AAmeba-AIoT&type=Repositories)
[
](https://www.youtube.com/@amebaiot7033)
[
](https://www.facebook.com/groups/amebaioten)
[
](https://www.facebook.com/groups/AmebaIoT)
[
](https://space.bilibili.com/457777430)
© Copyright 2026 Realtek Semiconductor Corp. All rights reserved.