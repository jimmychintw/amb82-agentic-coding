Timer Periodical — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [GTimer](index.html)
- Timer Periodical
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/GTimer/Timer Periodical.rst)
# Timer Periodical[](#timer-periodical)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
Ameba provides 4 hardware GTimer for users to use. The timers’ resolutions are at microseconds scale.
The timer can be set to be periodic or for single use. The periodic timers reset periodically, and the single-use timers do not.
Open the example, File -> Examples -> AmebaGTimer -> TimerPeriodical Compile and upload to Ameba, and press reset.
In the Serial Monitor, you can see the counter value is increased periodically.
## Code Reference[](#code-reference)
The first argument of begin() is the timer id (0~3).
The second argument is the value of the timer (in microseconds). In the example, we fill in 1000000us = 1s.
The third argument specifies the function to call when the time is up. In the example, we call the “myhandler” function to increase the counter value by 1 and print the counter value to serial monitor.
GTimer.begin(0, 1 * 1000 * 1000, myhandler);
The GTimer is periodic by default, therefore “myhandler” function is called every second.
When we want to stop the GTimer, use “stop()”:
```
GTimer.stop(0);
```
[ Previous](Timer%20Oneshot.html)
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