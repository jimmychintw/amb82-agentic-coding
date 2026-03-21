Simple RTC Alarm — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [RTC](index.html)
- Simple RTC Alarm
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/RTC/Simple RTC Alarm.rst)
# Simple RTC Alarm[](#simple-rtc-alarm)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
This example demonstrates how to use the RTC library methods to create a RTC Alarm, so that to do some tasks when an alarm is matched. In particular, the RTC time is set at 16:00:00 and an alarm at 16:00:10. When the time matches, “Alarm Match” information will be printed on the serial monitor.
First, select the correct Ameba development board from the Arduino IDE Tools -> Board
Then open the “RTCAlarm” example from File -> Examples -> RTC -> Simple_RTC_Alarm
[](../../../../_images/image01225.png)
In the example, the RTC time is set at 16:00:00 and an alarm is set at 16:00:10. Upon successfully upload the sample code and press the reset button. When the alarm time (10 seconds) is reached the attached interrupt function will print the following information: “Alarm Matched!” showing in this figure below.
[](../../../../_images/image02217.png)
[ Previous](Simple%20RTC.html)
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