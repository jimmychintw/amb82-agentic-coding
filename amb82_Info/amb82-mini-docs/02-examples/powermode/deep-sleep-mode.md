Deep Sleep Mode — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [PowerMode](index.html)
- Deep Sleep Mode
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/PowerMode/Deep Sleep Mode.rst)
# Deep Sleep Mode[](#deep-sleep-mode)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- Optional: Push button x 1
- Optional: Register 220 ohms x 1
## Example[](#example)
In this example, the development board will demo the non retention Deep Sleep Mode for power save. There are 3 wake-up sources for Deep Sleep Mode which are: AON Timer, AON GPIO, and RTC. The system will count down 5s then go to Deep Sleep mode. Upon the wake-up source being triggered, the system will be reboot and wake up again.
The module and board power consumption report under Deep Sleep mode are listed in these two tables below.
**RTL8735B module power consumption test results**
**Wake-up
source**
**Module power consumption
(uA)**
Deep Sleep Mode (measure at 3V3)
AON timer
32.78
AON GPIO
40.98
RTC
41.08
**AMB82 MINI board Power Consumption**
**Wake-up
source**
**Development board power
consumption Approximate
measurement
(mA)
Voltage source : pin V_USB(5V)**
**Development board power
consumption Approximate
measurement
(mA)
Voltage source : pin V_USB(3V)**
**Development board power
consumption Approximate
measurement
(mA)
Voltage source : USB CH340(MicroUSB)**
**Development board power
consumption Approximate
measurement
(mA)
Voltage source : USB OTG**
Normal Mode
DeepSleep Mode
Normal Mode
DeepSleep Mode
Normal Mode
DeepSleep Mode
Normal Mode
DeepSleep Mode
AON timer
57.42
3.31
84.14
5.18
60.65
5.67
57.42
3.31
AON GPIO
57.42
3.31
84.14
5.18
60.65
5.67
57.42
3.31
RTC
57.42
3.31
84.14
5.18
60.65
5.67
57.42
3.31
Note
The USB‑UART bridge (CH340) and indicator LEDs (D1, D2, D3 with resistors R85, R101) were originally included to provide a better user experience. However, to achieve improved power consumption results, we eliminated these non‑essential current paths so that the measured values reflect only the SoC and essential circuitry.
**Wake-up
source**
**Development board power
consumption Approximate
measurement after removing CH340 and LEDs
(mA)
Voltage source : pin V_USB(5V)**
**Development board power
consumption Approximate
measurement after removing CH340 and LEDs
(mA)
Voltage source : pin V_USB(3V)**
**Development board power
consumption Approximate
measurement after removing CH340 and LEDs
(mA)
Voltage source : USB CH340(MicroUSB)**
**Development board power
consumption Approximate
measurement after removing CH340 and LEDs
(mA)
Voltage source : USB OTG**
Normal Mode
DeepSleep Mode
Normal Mode
DeepSleep Mode
Normal Mode
DeepSleep Mode
Normal Mode
DeepSleep Mode
AON timer
53
0.2
81
0.9
54
0.2
55
0.2
AON GPIO
53
0.2
81
0.9
54
0.2
55
0.2
RTC
53
0.2
81
0.9
54
0.2
55
0.2
Open example in File -> Examples -> AmebaPowerMode -> DeepSleepMode
[](../../../../_images/image01219.png)
Next is setting up the system and entering the power mode. Please refer to the following steps for entering Deep Sleep mode.
Step 1. Ensure RETENTION is “#define RETENTION 0” in this example.
Step 2. Set up the “WAKEUP_SOURCE”, AON timer: 0; AON GPIO: 1; RTC: 2.
Step 3. Set up the wake-up source setting. There are 3 wake-up sources, each one has its own settings.
For AON timer, at section “#if (WAKEUP_SOURCE == 0)”, set value to “CLOCK” and “SLEEP_DURATION”. “CLOCK” can be 4MHz or 100kHz. “SLEEP_DURATION” unit is in seconds.
For AON GPIO, at section “#elif (WAKEUP_SOURCE == 1)”, set value to “WAKUPE_SETTING”. “WAKUPE_SETTING” in this case is the Pin number, that can be 21 or 22. The GPIO pin is set to active high, please refer to the following connection.
[](../../../../_images/image02211.png)
For RTC, at section “#elif (WAKEUP_SOURCE == 2)”, set value to “ALARM_DAY”, “ALARM_HOUR”, “ALARM_MIN”, or “ALARM_SEC”. All alarm values set the duration of RTC wake-up. The range is “1day, 0h, 0m, 0s” to “365day, 23h, 59min, 59s”.
Step 3. Start the Deep Sleep mode. There is only 1 optional setting for this step. When the wake-up source is set to RTC, use “PowerMode.start(1970, 1, 1, 0, 0, 0);” to replace “PowerMode.start();” for setting the start time. (Default is 1970.1.1 00:00:00).
[](../../../../_images/image03188.png)
To wake up, all timers will automatically wake up when the duration is finished, all GPIO pins must active high by pressing the push button.
The correct boot, enter deep sleep, and reboot cycle will be same as following picture.
[](../../../../_images/image04135.png)
[ Previous](index.html)
[Next ](Standby%20Mode.html)
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