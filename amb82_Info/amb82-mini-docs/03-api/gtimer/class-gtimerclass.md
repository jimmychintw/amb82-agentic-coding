Class GTimerClass — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Gtimer](index.html)
- Class GTimerClass
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Gtimer/Class GTimerClass.rst)
# Class GTimerClass[](#class-gtimerclass)
## **GTimerClass Class**[](#gtimerclass-class)
### **Description**[](#description)
A class used for initializing, starting, stopping Gtimer.
### **Syntax**[](#syntax)
class GTimerClass
### **Members**[](#members)
|**Public Constructors**
|
|
| GTimerClass:: GTimerClass
|
Constructs a GTimerClass object
|
|
| **Public Methods**
|
|
| GTimerClass::begin
|
Initialize a timer and start it
immediately
|
|
| GTimerClass::stop
|
Stop a specific timer
|
|
| GTimerClass::reload
|
Reload a specific timer
|
|
| GTimerClass::read_us
|
Read current countdown value
|
|
## **GtimerCass::begin**[](#gtimercass-begin)
### **Description**[](#id1)
Initialize a timer and start it immediately.
### **Syntax**[](#id2)
void begin(uint32_t timerid, uint32_t duration_us, void (*handler)(uint32_t), bool periodical = true, uint32_t userdata = 0, uint32_t timer0_clk_sel = 0);
### **Parameters**[](#parameters)
timerid: There are 5 valid GTimer with timer id.
- 0 to 4
duration_us: The duration of timer unit is microsecond. The precision is 32768Hz.
handler: As timer timeout, it would invoke this handler.
periodical: By default, the timer would keep periodically countdown and reload which leads the handler periodically invoked.
userdata: The user data brings to the handler. Default value is 0.
timer0_clk_sel: Select the timer0 clock, 0 for 40MHz or 1 for 4MHz. Default value is 0.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [TimerOneshot](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GTimer/examples/TimerOneshot/TimerOneshot.ino) [TimerPeriodical](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GTimer/examples/TimerPeriodical/TimerPeriodical.ino)
Note
“GTimer.h” must be included to use the class function.
## **GtimerCass::stop**[](#gtimercass-stop)
### **Description**[](#id3)
Stop a specific timer.
### **Syntax**[](#id4)
void stop(uint32_t timerid);
### **Parameters**[](#id5)
timerid: Stop the timer with its timer id.
- 0 to 4
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [TimerOneshot](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GTimer/examples/TimerOneshot/TimerOneshot.ino) [TimerPeriodical](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GTimer/examples/TimerPeriodical/TimerPeriodical.ino)
Note
“GTimer.h” must be included to use the class function.
## **GtimerCass::reload**[](#gtimercass-reload)
### **Description**[](#id9)
Reload a specific timer. The GTimer is a countdown timer. Reload it would make it discard the current countdown value and restart countdown based on the duration.
### **Syntax**[](#id10)
void refresh(uint32_t timerid, uint32_t duration_u);
### **Parameters**[](#id11)
timerid: The timer to be modified with its timer id.
- 0 to 4
duration_us: The updated duration in unit of microseconds.
- 1 to 10000
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [TimerOneshot](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GTimer/examples/TimerOneshot/TimerOneshot.ino) [TimerPeriodical](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GTimer/examples/TimerPeriodical/TimerPeriodical.ino)
Note
“GTimer.h” must be included to use the class function.
## **GtimerCass::read_us**[](#gtimercass-read-us)
### **Description**[](#id15)
Read current countdown value.
### **Syntax**[](#id16)
void reload(uint32_t timerid, uint32_t duration_us);
### **Parameters**[](#id17)
timerid: The timer to be read with its timer id.
- 0 to 4
### **Returns**[](#id18)
The current countdown value in microseconds.
### **Example Code**[](#id19)
Example: [TimerOneshot](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GTimer/examples/TimerOneshot/TimerOneshot.ino) [TimerPeriodical](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GTimer/examples/TimerPeriodical/TimerPeriodical.ino)
Note
“GTimer.h” must be included to use the class function.
[ Previous](index.html)
[Next ](../HTTP/index.html)
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