Class BLEHIDKeyboard — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEHIDKeyboard
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEHIDKeyboard.rst)
# Class BLEHIDKeyboard[](#class-blehidkeyboard)
## **BLEHIDKeyboard Class**[](#blehidkeyboard-class)
### **Description**[](#description)
A class used for creating and managing a BLE HID Keyboard.
### **Syntax**[](#syntax)
class BLEHIDKeyboard
### **Members**[](#members)
**Public Constructors**
|**Public Constructors**
|
|
| BLEHIDKeyboard::BLEHIDKeyboard
|
Constructs a BLEHIDKeyboard
object
|
|
| **Public Methods**
|
|
| BLEHIDKeyboard::setReportID
|
Set HID report ID for the HID
Keyboard and HID consumer
control
|
|
| BLEHIDKeyboard::consumerReport
|
Send a HID Consumer report
|
|
| BLEHIDKeyboard::keyboardReport
|
Send a HID Keyboard report
|
|
| BLEHIDKeyboard::consumerPress
|
Send a HID Consumer report
indicating button pressed
|
|
| BLEHIDKeyboard::consumerRelease
|
Send a HID Consumer report
indicating button released
|
|
| BLEHIDKeyboard::keypress
|
Send a HID Keyboard report
indicating keys pressed
|
|
| BLEHIDKeyboard::keyRelease
|
Send a HID Keyboard report
indicating keys released
|
|
| BLEHIDKeyboard::keyReleaseAll
|
Send a HID Keyboard report
indicating no keys pressed
|
|
| BLEHIDKeyboard::keyCharPress
|
Send a HID Keyboard report
indicating keys pressed to
output an ASCII character
|
|
| BLEHIDKeyboard::keySequence
|
Send a HID Keyboard report
indicating keys pressed to
output an ASCII string
|
|
## **BLEHIDKeyboard::BLEHIDKeyboard**[](#blehidkeyboard-blehidkeyboard)
### **Description**[](#id1)
Constructs a BLEHIDKeyboard object.
### **Syntax**[](#id2)
BLEHIDKeyboard(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEHIDKeyboard](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDKeyboard/BLEHIDKeyboard.ino)
Note
“BLEHIDKeyboard.h” must be included to use the class function.
**BLEHIDKeyboard::setReportID**
### **Description**[](#id3)
Set HID report ID for the HID Keyboard and HID consumer control.
### **Syntax**[](#id4)
void setReportID (uint8_t reportIDKeyboard, uint8_t reportIDConsumer);
### **Parameters**[](#id5)
reportIDKeyboard: The report ID for the HID keyboard device, corresponding to the HID report descriptor.
reportIDConsumer: The report ID for the HID consumer control device, corresponding to the HID report descriptor.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
“BLEHIDKeyboard.h” must be included to use the class function.
## **BLEHIDKeyboard::consumerReport**[](#blehidkeyboard-consumerreport)
### **Description**[](#id8)
Send a HID Consumer report.
### **Syntax**[](#id9)
void consumerReport (uint16_t usage_code);
### **Parameters**[](#id10)
usage_code: HID consumer control usage code for the button pressed.
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
NA
Note
“BLEHIDKeyboard.h” must be included to use the class function.
## **BLEHIDKeyboard::keyboardReport**[](#blehidkeyboard-keyboardreport)
### **Description**[](#id13)
Send a HID Keyboard report.
### **Syntax**[](#id14)
void keyboardReport (void);
void keyboardReport (uint8_t modifiers, uint8_t keycode[6]);
### **Parameters**[](#id15)
modifiers: bitmap indicating key modifiers pressed (CTRL, ALT, SHIFT).
keycode: byte array indicating keys pressed.
### **Returns**[](#id16)
NA
### **Example Code**[](#id17)
NA
Note
“BLEHIDKeyboard.h” must be included to use the class function.
## **BLEHIDKeyboard::consumerPress**[](#blehidkeyboard-consumerpress)
### **Description**[](#id18)
Send a HID Consumer report indicating button pressed.
### **Syntax**[](#id19)
void consumerPress (uint16_t usage_code);
### **Parameters**[](#id20)
usage_code: HID consumer control usage code for the button pressed.
### **Returns**[](#id21)
NA
### **Example Code**[](#id22)
Example: [BLEHIDKeyboard](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDKeyboard/BLEHIDKeyboard.ino)
Note
“BLEHIDKeyboard.h” must be included to use the class function.
## **BLEHIDKeyboard::consumerRelease**[](#blehidkeyboard-consumerrelease)
### **Description**[](#id24)
Send a HID Consumer report indicating button released.
### **Syntax**[](#id25)
void consumerRelease (void);
### **Parameters**[](#id26)
NA
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
Example: [BLEHIDKeyboard](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDKeyboard/BLEHIDKeyboard.ino)
Note
“BLEHIDKeyboard.h” must be included to use the class function.
## **BLEHIDKeyboard::keypress**[](#blehidkeyboard-keypress)
### **Description**[](#id30)
Send a HID Keyboard report indicating keys pressed.
### **Syntax**[](#id31)
void keyPress (uint16_t key);
### **Parameters**[](#id32)
key: HID keycode for key pressed.
- 0x00 to 0xE7.
### **Returns**[](#id33)
NA
### **Example Code**[](#id34)
Example: [BLEHIDKeyboard](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDKeyboard/BLEHIDKeyboard.ino)
Note
“BLEHIDKeyboard.h” must be included to use the class function.
## **BLEHIDKeyboard::keyRelease**[](#blehidkeyboard-keyrelease)
### **Description**[](#id36)
Send a HID Keyboard report indicating keys released.
### **Syntax**[](#id37)
void keyRelease (uint16_t key);
### **Parameters**[](#id38)
key: HID keycode for key pressed.
- 0x00 to 0xE7.
### **Returns**[](#id39)
NA
### **Example Code**[](#id40)
NA
Note
“BLEHIDKeyboard.h” must be included to use the class function.
## **BLEHIDKeyboard::keyReleaseAll**[](#blehidkeyboard-keyreleaseall)
### **Description**[](#id41)
Send a HID Keyboard report indicating no keys pressed.
### **Syntax**[](#id42)
void keyReleaseAll (void);
### **Parameters**[](#id43)
NA
### **Returns**[](#id44)
NA
### **Example Code**[](#id45)
Example: [BLEHIDKeyboard](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDKeyboard/BLEHIDKeyboard.ino)
Note
“BLEHIDKeyboard.h” must be included to use the class function.
## **BLEHIDKeyboard::keyCharPress**[](#blehidkeyboard-keycharpress)
### **Description**[](#id47)
Send a HID Keyboard report indicating keys pressed to output a specific ASCII character.
### **Syntax**[](#id48)
void keyCharPress (char ch);
### **Parameters**[](#id49)
ch: ASCII character to output.
### **Returns**[](#id50)
NA
### **Example Code**[](#id51)
NA
Note
“BLEHIDKeyboard.h” must be included to use the class function.
## **BLEHIDKeyboard::keySequence**[](#blehidkeyboard-keysequence)
### **Description**[](#id52)
Send a HID Keyboard report indicating keys pressed to output an ASCII string.
### **Syntax**[](#id53)
void keySequence (const char* str, uint16_t delayTime);
void keySequence (String str, uint16_t delayTime);
### **Parameters**[](#id54)
str: character string to output, expressed as a pointer to a character array or a String class object.
delayTime: time delay between key press and release, in milliseconds. Default value is 5.
### **Returns**[](#id55)
NA
### **Example Code**[](#id56)
Example: [BLEHIDKeyboard](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDKeyboard/BLEHIDKeyboard.ino)
Note
“BLEHIDKeyboard.h” must be included to use the class function.
[ Previous](Class%20BLEHIDGamepad.html)
[Next ](Class%20BLEHIDMouse.html)
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