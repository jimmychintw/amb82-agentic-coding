Class RTC — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [RTC](index.html)
- Class RTC
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/RTC/Class RTCClass.rst)
# Class RTC[](#class-rtc)
## **RTCClass Class**[](#rtcclass-class)
### **Description**[](#description)
A class used for initializing, starting, stopping, and setting alarm with RTC.
### **Syntax**[](#syntax)
class WDT
### **Members**[](#members)
|**Public Constructors**
|
|
| RTCClass:: RTCClass
|
Constructs an RTC object.
|
|
| **Public Methods**
|
|
| RTCClass::Init
|
Initializes the RTC device,
include clock, RTC registers and
function.
|
|
| RTCClass::DeInit
|
Deinitializes the RTC device.
|
|
| RTCClass::Write
|
Set the specified timestamp in
seconds to RTC.
|
|
| RTCClass::Read
|
Get current timestamp in seconds
from RTC.
|
|
| RTCClass::Wait
|
Wait for seconds. A delay
function.
|
|
| RTCClass::SetEpoch
|
Convert human readable time to
epoch time.
|
|
| RTCClass::EnableAlarm
|
Enable the RTC alarm.
|
|
| RTCClass::DisableAlarm
|
Disable the RTC alarm.
|
|
## **RTCClass::Init**[](#rtcclass-init)
### **Description**[](#id1)
Initializes the RTC device, include clock, RTC registers and function.
### **Syntax**[](#id2)
void Init(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [Simple_RTC](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC/Simple_RTC.ino) [Simple_RTC_Alarm](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC_Alarm/Simple_RTC_Alarm.ino)
Note
“rtc.h” must be included to use the class function.
## **RTCClass::DeInit**[](#rtcclass-deinit)
### **Description**[](#id3)
Deinitializes the RTC device.
### **Syntax**[](#id4)
void DeInit(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [Simple_RTC](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC/Simple_RTC.ino) [Simple_RTC_Alarm](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC_Alarm/Simple_RTC_Alarm.ino)
Note
“rtc.h” must be included to use the class function.
## **RTCClass::Write**[](#rtcclass-write)
### **Description**[](#id9)
Set the specified timestamp in seconds to RTC.
### **Syntax**[](#id10)
void Write(long long t);
### **Parameters**[](#id11)
t: Seconds from 1970.1.1 00:00:00 to specified data and time which is to be set.
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [Simple_RTC](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC/Simple_RTC.ino) [Simple_RTC_Alarm](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC_Alarm/Simple_RTC_Alarm.ino)
Note
“rtc.h” must be included to use the class function.
## **RTCClass::Read**[](#rtcclass-read)
### **Description**[](#id15)
Get current timestamp in seconds from RTC.
### **Syntax**[](#id16)
long long Read(void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
The current timestamp in seconds which is calculated from 1970.1.100:00:00.
### **Example Code**[](#id19)
Example: [Simple_RTC](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC/Simple_RTC.ino) [Simple_RTC_Alarm](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC_Alarm/Simple_RTC_Alarm.ino)
Note
“rtc.h” must be included to use the class function.
## **RTCClass::Wait**[](#rtcclass-wait)
### **Description**[](#id21)
Wait for seconds. A delay function.
### **Syntax**[](#id22)
void Wait(int s);
### **Parameters**[](#id23)
s: delay time in seconds.
### **Returns**[](#id24)
NA
### **Example Code**[](#id25)
Example: [Simple_RTC](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC/Simple_RTC.ino) [Simple_RTC_Alarm](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC_Alarm/Simple_RTC_Alarm.ino)
Note
“rtc.h” must be included to use the class function.
## **RTCClass::SetEpoch**[](#rtcclass-setepoch)
### **Description**[](#id27)
Convert human readable time to epoch time.
### **Syntax**[](#id28)
long long SetEpoch(int year, int month, int day, int hour, int min, int sec);
### **Parameters**[](#id29)
year: Input time in year.
- Start from 1900
month: Input time in month.
- 0 to 11
day: Input time unit in day.
- 1 to 31
hour: Input time unit in hour.
- 0 to 23
min: Input time unit in min.
- 0 to 59
sec: Input time unit in sec.
- 0 to 59
### **Returns**[](#id30)
The epoch time of the input date.
### **Example Code**[](#id31)
Example: [Simple_RTC](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC/Simple_RTC.ino) [Simple_RTC_Alarm](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC_Alarm/Simple_RTC_Alarm.ino)
Note
“rtc.h” must be included to use the class function.
## **RTCClass::EnableAlarm**[](#rtcclass-enablealarm)
### **Description**[](#id33)
Enable the RTC alarm.
### **Syntax**[](#id34)
void EnableAlarm(int day, int hour, int min, int sec, void(*rtc_handler)(void));
### **Parameters**[](#id35)
day: Alarm time unit in day.
- 1 to 31
hour: Alarm time unit in hour.
- 0 to 23
min: Alarm time unit in min.
- 0 to 59
sec: Alarm time unit in sec.
- 0 to 59
rtc_handler: the callback function for rtc alarm interrupt.
### **Returns**[](#id36)
NA
### **Example Code**[](#id37)
Example: [Simple_RTC](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC/Simple_RTC.ino) [Simple_RTC_Alarm](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC_Alarm/Simple_RTC_Alarm.ino)
Note
“rtc.h” must be included to use the class function.
## **RTCClass::DisableAlarm**[](#rtcclass-disablealarm)
### **Description**[](#id39)
Disable the RTC alarm.
### **Syntax**[](#id40)
void DisableAlarm(void);
### **Parameters**[](#id41)
NA
### **Returns**[](#id42)
NA
### **Example Code**[](#id43)
Example: [Simple_RTC](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC/Simple_RTC.ino) [Simple_RTC_Alarm](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/RTC/examples/Simple_RTC_Alarm/Simple_RTC_Alarm.ino)
Note
“rtc.h” must be included to use the class function.
[ Previous](index.html)
[Next ](../SPI/index.html)
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