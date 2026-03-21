Class WDT — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Watchdog](index.html)
- Class WDT
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Watchdog/Class WDT.rst)
# Class WDT[](#class-wdt)
## **WDT Class**[](#wdt-class)
### **Description**[](#description)
A class used for initializing, starting, stopping watchdog timer.
### **Syntax**[](#syntax)
class WDT
### **Members**[](#members)
|**Public Constructors**
|
|
| WDT::WDT
|
Constructs an WDT object.
|
|
| **Public Methods**
|
|
| WDT::init
|
Initialize the watchdog,
including time setting, and mode
register.
|
|
| WDT::start
|
Enable and start the watchdog
timer
|
|
| WDT::stop
|
Stop the watchdog timer.
|
|
| WDT::refresh
|
Refresh the watchdog timer to
prevent WDT timeout.
|
|
| WDT::init_irq
|
Switch the watchdog timer to
interrupt mode and register a
watchdog timer timeout interrupt
handler.
|
|
## **WDT::init**[](#wdt-init)
### **Description**[](#id1)
Initialize the watchdog, including time setting, and mode register.
### **Syntax**[](#id2)
void init(uint32_t timeout_ms);
### **Parameters**[](#parameters)
timeout_ms: the watch-dog timer timeout value in millisecond (ms). The default action after watchdog timer timeout is to reset the whole system.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [SimpleWDT](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Watchdog/examples/SimpleWDT/SimpleWDT.ino)
Note
“WDT.h” must be included to use the class function.
## **WDT::start**[](#wdt-start)
### **Description**[](#id3)
Start the watchdog timer by enabling the WDG state.
### **Syntax**[](#id4)
void start(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [SimpleWDT](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Watchdog/examples/SimpleWDT/SimpleWDT.ino)
Note
“WDT.h” must be included to use the class function.
## **WDT::stop**[](#wdt-stop)
### **Description**[](#id9)
Stop the watchdog timer by disabling the WDG state.
### **Syntax**[](#id10)
void stop(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [SimpleWDT](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Watchdog/examples/SimpleWDT/SimpleWDT.ino)
Note
“WDT.h” must be included to use the class function.
## **WDT::refresh**[](#wdt-refresh)
### **Description**[](#id15)
Clear watchdog timer and refresh to prevent timeout.
### **Syntax**[](#id16)
void refresh(void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
NA
### **Example Code**[](#id19)
Example: [SimpleWDT](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Watchdog/examples/SimpleWDT/SimpleWDT.ino)
Note
“WDT.h” must be included to use the class function.
## **WDT::init_irq**[](#wdt-init-irq)
### **Description**[](#id21)
Switch the watchdog timer to interrupt mode and register a watchdog  timer timeout interrupt handler. The interrupt handler will be called when the watchdog timer is timeout.
### **Syntax**[](#id22)
void init_irq(wdt_irq_handler handler, uint32_t id);
### **Parameters**[](#id23)
handler: the callback function for WDT timeout interrupt.
id: the parameter for the callback function.
### **Returns**[](#id24)
NA
### **Example Code**[](#id25)
Example: [SimpleWDT](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Watchdog/examples/SimpleWDT/SimpleWDT.ino)
Note
“WDT.h” must be included to use the class function.
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