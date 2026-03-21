Class BLEHIDMouse — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEHIDMouse
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEHIDMouse.rst)
# Class BLEHIDMouse[](#class-blehidmouse)
## **BLEHIDMouse Class**[](#blehidmouse-class)
### **Description**[](#description)
A class used for creating and managing a BLE HID Mouse.
### **Syntax**[](#syntax)
class BLEHIDMouse
### **Members**[](#members)
|**Public Constructors**
|
|
| BLEHIDMouse::BLEHIDMouse
|
Constructs a BLEHIDMouse object
|
|
| **Public Methods**
|
|
| BLEHIDMouse::setReportID
|
Set HID report ID for the HID Mouse
|
|
| BLEHIDMouse::mouseReport
|
Send a HID Mouse report
|
|
| BLEHIDMouse::mousePress
|
Send a HID Mouse report indicating
buttons pressed
|
|
| BLEHIDMouse::mouseRelease
|
Send a HID Mouse report indicating
buttons release
|
|
| BLEHIDMouse::
mouseReleaseAll
|
Send a HID Mouse report indicating no
button Pressed
|
|
| BLEHIDMouse::mouseMove
|
Send a HID Mouse report indicating
mouse movement
|
|
| BLEHIDMouse::mouseScroll
|
Send a HID Mouse report indicating
mouse scroll wheel movement
|
|
## **BLEHIDMouse::BLEHIDMouse**[](#blehidmouse-blehidmouse)
### **Description**[](#id1)
Constructs a BLEHIDMouse object.
### **Syntax**[](#id2)
BLEHIDMouse(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLEHIDMouse.h” must be included to use the class function.
## **BLEHIDMouse::setReportID**[](#blehidmouse-setreportid)
### **Description**[](#id3)
Set HID report ID for the HID Mouse.
### **Syntax**[](#id4)
void setReportID (uint8_t reportID);
### **Parameters**[](#id5)
reportID: The report ID for the HID mouse device, corresponding to the HID report descriptor.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
“BLEHIDMouse.h” must be included to use the class function.
## **BLEHIDMouse::mouseReport**[](#blehidmouse-mousereport)
### **Description**[](#id8)
Send a HID Mouse report.
### **Syntax**[](#id9)
void mouseReport (hid_mouse_report_t* report);
void mouseReport (uint8_t buttons, int8_t x, int8_t y, int8_t scroll);
### **Parameters**[](#id10)
report: pointer to mouse report structure containing data on mouse inputs.
buttons: bitmap indicating state of each button.
- 1 (pressed)
- 0 (released)
x: mouse x-axis movement in integer.
- -127 to 127.
y: mouse y-axis movement in integer.
- -127 to 127.
scroll: mouse scroll wheel movement in integer.
- -127 to 127.
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
NA
Note
“BLEHIDMouse.h” must be included to use the class function.
## **BLEHIDMouse::mousePress**[](#blehidmouse-mousepress)
### **Description**[](#id13)
Send a HID Mouse report indicating buttons pressed.
### **Syntax**[](#id14)
void mousePress (uint8_t buttons);
### **Parameters**[](#id15)
buttons: bitmap indicating buttons pressed.
- 1 (pressed)
### **Returns**[](#id16)
NA
### **Example Code**[](#id17)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLEHIDMouse.h” must be included to use the class function.
## **BLEHIDMouse::mouseRelease**[](#blehidmouse-mouserelease)
### **Description**[](#id19)
Send a HID Mouse report indicating buttons released.
### **Syntax**[](#id20)
void mouseRelease (uint8_t buttons);
### **Parameters**[](#id21)
buttons: bitmap indicating buttons released.
- 1 (pressed)
### **Returns**[](#id22)
NA
### **Example Code**[](#id23)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLEHIDMouse.h” must be included to use the class function.
## **BLEHIDMouse::mouseReleaseAll**[](#blehidmouse-mousereleaseall)
### **Description**[](#id25)
Send a HID Mouse report indicating no buttons pressed.
### **Syntax**[](#id26)
void mouseReleaseAll(void);
### **Parameters**[](#id27)
NA
### **Returns**[](#id28)
NA
### **Example Code**[](#id29)
NA
Note
“BLEHIDMouse.h” must be included to use the class function.
## **BLEHIDMouse::mouseMove**[](#blehidmouse-mousemove)
### **Description**[](#id30)
Send a HID Mouse report indicating mouse movement.
### **Syntax**[](#id31)
void mouseMove (int8_t x, int8_t y);
### **Parameters**[](#id32)
x: mouse x-axis movement in integer.
- -127 to 127.
y: mouse y-axis movement in integer.
- -127 to 127.
### **Returns**[](#id33)
NA
### **Example Code**[](#id34)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLEHIDMouse.h” must be included to use the class function.
## **BLEHIDMouse::mouseScroll**[](#blehidmouse-mousescroll)
### **Description**[](#id36)
Send a HID Mouse report indicating mouse scroll wheel movement.
### **Syntax**[](#id37)
void mouseScroll (int8_t scroll);
### **Parameters**[](#id38)
scroll: mouse scroll wheel movement in integer.
- -127 to 127.
### **Returns**[](#id39)
NA
### **Example Code**[](#id40)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLEHIDMouse.h” must be included to use the class function.
[ Previous](Class%20BLEHIDKeyboard.html)
[Next ](Class%20BLERemoteCharacteristic.html)
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