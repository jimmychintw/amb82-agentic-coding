Simple WDT — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [Watchdog](index.html)
- Simple WDT
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/Watchdog/Simple WDT.rst)
# Simple WDT[](#simple-wdt)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
### Introduction[](#introduction)
This is a simple Watchdog Timer (WDT) example and demonstrate the usage of watchdog API. Refer to the following information about the definition and working principles of Watchdog.
#### Watchdog[](#watchdog)
Watchdog Timer is a hardware timer that is used to detect the occurrence of a software fault, then automatically generates a system reset or a watchdog interrupt on the expiry of a programmed period.
In layman terms, imagine in the situation while your micro-controller is confused in an infinity loop, or any case like the micro-controller hang while performing some tasks. The normal troubleshooting method would be to press the reset button and jump out of the infinity loop. However, is it practically impossible to do press on the button all time, therefore, the watchdog timer that embedded inside the micro-controller would help with this situation.
#### Feed the Dog[](#feed-the-dog)
If you have a dog in your home. You need to feed that dog at a regular interval. if you can’t feed one day, it will bite you! And likewise, this is the working logic behind the watchdog timer.
[](../../../../_images/image01231.png)
In the example, there are 2 tasks that contain some loops that runs repeatedly, one is called “Small_Task” and the other is called “Big_Task”. The watchdog timer is enabled with an initial value 5 seconds greater than the total delay in the “Small_Task” (1s), but shorter than the “Big_Task” (10s).
For the successful case, the watchdog is being refreshed/feed within 5 seconds, however, for the failed case, the loop is under processing and the watchdog is not being fresh after 5 seconds, which triggers the watchdog (dog barks), an interrupt is generated to reset the processor. Likewise, the watchdog timer protects the micro-controller from the hanging case.
### Procedure[](#procedure)
Connect the board, then open the example from Arduino IDE, File -> Examples -> AmebaWatchdog -> SimpleWDT
[](../../../../_images/image02224.png)
There are 2 settings needs to be done before uploading.
**Define names**
**Set values**
**Functions description**
AON_WDT_Enable
1
Watchdog timer sets to
always on
AON_WDT_Enable
0
Always on disabled
RUN_CALLBACK_IF_WATCHDOG_BARKS
1
Execute IRQ functions
after “barks”
RUN_CALLBACK_IF_WATCHDOG_BARKS
0
IRQ disabled
Note
IRQ is not supported when “AON_WDT_Enable” sets to “1”.
[](../../../../_images/image03199.png)
Upon successfully upload the sample code, open the serial monitor, and press the reset button. You will find that the “Small_Task” can refresh the watchdog within the 5 seconds (initialized in the watchdog timer). However, the “Big_Task” will not be able to refresh the watchdog within 5 seconds, which the watchdog “barks” then the microcontroller reset.
[](../../../../_images/image04142.png)
When set “#define RUN_CALLBACK_IF_WATCHDOG_BARKS (0)” value be “1”, for customized “my_watchdog_irq_handler”. Write the code inside the handler for execution after “barks”.
[](../../../../_images/image05111.png)
[ Previous](index.html)
[Next ](../WiFi/index.html)
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