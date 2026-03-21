Class BLEHIDGamepad — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEHIDGamepad
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEHIDGamepad.rst)
# Class BLEHIDGamepad[](#class-blehidgamepad)
## **BLEHIDGamepad Class**[](#blehidgamepad-class)
### **Description**[](#description)
A class used for creating and managing a BLE HID Gamepad.
### **Syntax**[](#syntax)
class BLEHIDGamepad
### **Members**[](#members)
|**Public Constructors**
|
|
| BLEHIDGamepad::BLEHIDG
amepad
|
Constructs a BLEHIDGamepad object
|
|
| **Public Methods**
|
|
| BLEHIDGamepad::setReportID
|
Set HID report ID for the HID Gamepad
|
|
| BLEHIDGamepad::gamepad
Report
|
Send a HID Gamepad report
|
|
| BLEHIDGamepad::buttonPress
|
Send a HID Gamepad report indicating
buttons pressed
|
|
| BLEHIDGamepad::
buttonRelease
|
Send a HID Gamepad report indicating
buttons released
|
|
| BLEHIDGamepad::
buttonReleaseAll
|
Send a HID Gamepad report indicating no
buttons pressed
|
|
| BLEHIDGamepad::setHat
|
Send a HID Gamepad report indicating
hat switch position
|
|
| BLEHIDGamepad::setAxes
|
Send a HID Gamepad report indicating
position of all axes
|
|
| BLEHIDGamepad::setLeftStick
|
Send a HID Gamepad report indicating
position of axes corresponding to left
analog stick
|
|
| BLEHIDGamepad::
setRightStick
|
Send a HID Gamepad report indicating
position of axes corresponding to right
analog stick
|
|
| BLEHIDGamepad::setTriggers
|
Send a HID Gamepad report indicating
position of axes corresponding to
triggers
|
|
## **BLEHIDGamepad::BLEHIDGamepad**[](#blehidgamepad-blehidgamepad)
### **Description**[](#id1)
Constructs a BLEHIDGamepad object.
### **Syntax**[](#id2)
BLEHIDGamepad(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEHIDGamepad](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDGamepad/BLEHIDGamepad.ino)
Note
By default, the BLEHIDGamepad class assumes the HID report descriptor implements a gamepad device with 16 buttons, 6 16-bit axes and an 8-direction hat switch. This class will not work if a different gamepad report descriptor is implemented. “BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::setReportID**[](#blehidgamepad-setreportid)
### **Description**[](#id3)
Set HID report ID for the HID Gamepad.
### **Syntax**[](#id4)
void setReportID (uint8_t reportID);
### **Parameters**[](#id5)
reportID: The report ID for the gamepad device, corresponding to the HID report descriptor.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [BLEHIDGamepad](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDGamepad/BLEHIDGamepad.ino)
Note
HID report ID should start at 1. Some systems may consider a report ID of 0 as invalid. “BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::gamepadReport**[](#blehidgamepad-gamepadreport)
### **Description**[](#id9)
Send a HID Gamepad report.
### **Syntax**[](#id10)
void gamepadReport (hid_gamepad_report_t* report);
void gamepadReport (uint16_t buttons, uint8_t hat, int16_t x, int16_t y, int16_t z, int16_t Rz, int16_t Rx, int16_t Ry);
### **Parameters**[](#id11)
report: pointer to gamepad report structure containing data on all inputs.
buttons: bitmap indicating state of each button.
- 1 (pressed)
- 0 (released)
hat: position of hat switch.
- GAMEPAD_HAT_CENTERED (0)
- GAMEPAD_HAT_UP (1)
- GAMEPAD_HAT_UP_RIGHT (2)
- GAMEPAD_HAT_RIGHT (3)
- GAMEPAD_HAT_DOWN_RIGHT (4)
- GAMEPAD_HAT_DOWN (5)
- GAMEPAD_HAT_DOWN_LEFT (6)
- GAMEPAD_HAT_LEFT (7)
- GAMEPAD_HAT_UP_LEFT (8)
x: position of x axis in integer.
- -32767 to 32767.
y: position of y axis in integer.
- -32767 to 32767.
z: position of z axis in integer.
- -32767 to 32767.
Rz: position of Rz axis in integer.
- -32767 to 32767.
Rx: position of Rx axis in integer.
- -32767 to 32767.
Ry: position of Ry axis in integer.
- -32767 to 32767.
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [BLEHIDGamepad](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDGamepad/BLEHIDGamepad.ino)
Note
“BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::buttonPress**[](#blehidgamepad-buttonpress)
### **Description**[](#id15)
Send a HID Gamepad report indicating buttons pressed.
### **Syntax**[](#id16)
void buttonPress (uint16_t buttons);
### **Parameters**[](#id17)
buttons: bitmap indicating buttons pressed.
- 1 (pressed)
### **Returns**[](#id18)
NA
### **Example Code**[](#id19)
NA
Note
“BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::buttonRelease**[](#blehidgamepad-buttonrelease)
### **Description**[](#id20)
Send a HID Gamepad report indicating buttons released.
### **Syntax**[](#id21)
void buttonRelease (uint16_t buttons);
### **Parameters**[](#id22)
buttons: bitmap indicating buttons released.
- 1 (pressed)
### **Returns**[](#id23)
NA
### **Example Code**[](#id24)
NA
Note
“BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::buttonReleaseAll**[](#blehidgamepad-buttonreleaseall)
### **Description**[](#id25)
Send a HID Gamepad report indicating no buttons pressed.
### **Syntax**[](#id26)
void buttonReleaseAll (void);
### **Parameters**[](#id27)
NA
### **Returns**[](#id28)
NA
### **Example Code**[](#id29)
Example: [BLEHIDGamepad](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDGamepad/BLEHIDGamepad.ino)
Note
“BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::setHat**[](#blehidgamepad-sethat)
### **Description**[](#id31)
Send a HID Gamepad report indicating hat switch position.
### **Syntax**[](#id32)
void setHat (uint8_t hat);
### **Parameters**[](#id33)
hat: position of hat switch.
- GAMEPAD_HAT_CENTERED (0)
- GAMEPAD_HAT_UP (1)
- GAMEPAD_HAT_UP_RIGHT (2)
- GAMEPAD_HAT_RIGHT (3)
- GAMEPAD_HAT_DOWN_RIGHT (4)
- GAMEPAD_HAT_DOWN (5)
- GAMEPAD_HAT_DOWN_LEFT (6)
- GAMEPAD_HAT_LEFT (7)
- GAMEPAD_HAT_UP_LEFT (8)
### **Returns**[](#id34)
NA
### **Example Code**[](#id35)
NA
Note
“BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::setAxes**[](#blehidgamepad-setaxes)
### **Description**[](#id36)
Send a HID Gamepad report indicating position of all axes.
### **Syntax**[](#id37)
void setAxes (int16_t x, int16_t y, int16_t z, int16_t Rz, int16_t Rx, int16_t Ry);
### **Parameters**[](#id38)
x: position of x axis in integer.
- -32767 to 32767.
y: position of y axis in integer.
- -32767 to 32767.
z: position of z axis in integer.
- -32767 to 32767.
Rz: position of Rz axis in integer.
- -32767 to 32767.
Rx: position of Rx axis in integer.
- -32767 to 32767.
Ry: position of Ry axis in integer.
- -32767 to 32767.
### **Returns**[](#id39)
NA
### **Example Code**[](#id40)
Example: [BLEHIDGamepad](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDGamepad/BLEHIDGamepad.ino)
Note
“BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::setLeftStick**[](#blehidgamepad-setleftstick)
### **Description**[](#id42)
Send a HID Gamepad report indicating position of axes corresponding to left analog stick.
### **Syntax**[](#id43)
void setLeftStick (int16_t x, int16_t y);
### **Parameters**[](#id44)
x: position of x axis in integer.
- -32767 to 32767.
y: position of y axis in integer.
- -32767 to 32767.
### **Returns**[](#id45)
NA
### **Example Code**[](#id46)
NA
Note
“BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::setRightStick**[](#blehidgamepad-setrightstick)
### **Description**[](#id47)
Send a HID Gamepad report indicating position of axes corresponding to right analog stick.
### **Syntax**[](#id48)
void setLeftStick (int16_t z, int16_t Rz);
### **Parameters**[](#id49)
z: position of z axis in integer.
- -32767 to 32767.
Rz: position of Rz axis in integer.
- -32767 to 32767.
### **Returns**[](#id50)
NA
### **Example Code**[](#id51)
NA
Note
“BLEHIDGamepad.h” must be included to use the class function.
## **BLEHIDGamepad::setTriggers**[](#blehidgamepad-settriggers)
### **Description**[](#id52)
Send a HID Gamepad report indicating position of axes corresponding to triggers.
### **Syntax**[](#id53)
void setTriggers (int16_t Rx, int16_t Ry);
### **Parameters**[](#id54)
Rx: position of Rx axis in integer.
- -32767 to 32767.
Ry: position of Ry axis in integer.
- -32767 to 32767.
### **Returns**[](#id55)
NA
### **Example Code**[](#id56)
NA
Note
“BLEHIDGamepad.h” must be included to use the class function.
[ Previous](Class%20BLEHIDDevice.html)
[Next ](Class%20BLEHIDKeyboard.html)
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