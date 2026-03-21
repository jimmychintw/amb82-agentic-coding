Class AmebaServo — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Analog](index.html)
- Class AmebaServo
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Analog/Class AmebaServo.rst)
# Class AmebaServo[](#class-amebaservo)
## **AmebaServo Class**[](#amebaservo-class)
### **Description**[](#description)
A class used for controlling servo motors connected to Ameba boards.
### **Syntax**[](#syntax)
class AmebaServo
### **Members**[](#members)
|**Public Constructors**
|
|
| AmebaServo::AmebaServo
|
Constructs an AmebaServo object.
|
|
| **Public Methods**
|
|
| AmebaServo::attach
|
Attach a PWM pin to control servo.
|
|
| AmebaServo::detach
|
Detach the servo.
|
|
| AmebaServo::write
|
Write a value to control servo. The
value is between 0 - 180 degrees.
|
|
| AmebaServo::writeMicroseconds
|
Write a value to control servo. The
value is between 544 - 2400us.
|
|
| AmebaServo::read
|
Read the value from servo and returns
current pulse width as an angle between
0 and 180 degrees.
|
|
| AmebaServo::readMicroseconds
|
Read the value from servo and returns
current pulse width in microseconds.
|
|
| AmebaServo::attached
|
Check if the servo is attached.
|
|
## **AmebaServo::attach**[](#amebaservo-attach)
### **Description**[](#id1)
Attach a PWM pin to control servo on Ameba boards. Minimum and maximum pulse width can be set optionally.
### **Syntax**[](#id2)
uint8_t attach(int pin);
uint8_t attach(int pin, int min, int max);
### **Parameters**[](#parameters)
pin: A PWM pin that is one of the Ameba boards’ PWM pins.
min: Minimum pulse width to be set for PWM. Default value is 544us.
max: Maximum pulse width to be set for PWM. Default value is 2400us.
### **Returns**[](#returns)
0
### **Example Code**[](#example-code)
Example: [PWM_ServoControl](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Analog/examples/PWM_ServoControl/PWM_ServoControl.ino)
The code demonstrates a servo motor sweeping from 0 - 180 - 0 degrees, in 1-degree intervals.
Note
“AmebaServo.h” must be included to use the class function.
## **AmebaServo::detach**[](#amebaservo-detach)
### **Description**[](#id3)
Detach the servo by disabling the PWM pin previously set in attach().
### **Syntax**[](#id4)
void detach(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
“AmebaServo.h” must be included to use the class function.
## **AmebaServo::write**[](#amebaservo-write)
### **Description**[](#id8)
Write an integer value to control servo. The value is between 0 - 180 degrees.
### **Syntax**[](#id9)
void write(int value);
### **Parameters**[](#id10)
value: An integer value.
- 0 to 180 (If the value is < 0, it will be taken as 0 and if the value >180, it will be taken as 180)
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
Example: [PWM_ServoControl](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Analog/examples/PWM_ServoControl/PWM_ServoControl.ino)
Note
“AmebaServo.h” must be included to use the class function.
## **AmebaServo::writeMicroseconds**[](#amebaservo-writemicroseconds)
### **Description**[](#id14)
Write a value to control servo. The value is between 544 - 2400us that represents pulse width.
### **Syntax**[](#id15)
void writeMicroseconds(int value);
### **Parameters**[](#id16)
value: An integer value (us) as pulse width.
- 544 to 2400 (If the value is < 544, it will be taken as 544 and if the value > 2400, it will be taken as 2400)
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
NA
Note
“AmebaServo.h” must be included to use the class function.
## **AmebaServo::read**[](#amebaservo-read)
### **Description**[](#id19)
The function reads the value from servo and returns current pulse width as an angle between 0 - 180 degrees.
### **Syntax**[](#id20)
int read(void);
### **Parameters**[](#id21)
NA
### **Returns**[](#id22)
This function returns integer value that represents pulse width between 0 - 180 degrees.
### **Example Code**[](#id23)
NA
Note
“AmebaServo.h” must be included to use the class function.
## **AmebaServo::readMicroseconds**[](#amebaservo-readmicroseconds)
### **Description**[](#id24)
The function reads and returns the pulse width of the current servo in microseconds.
### **Syntax**[](#id25)
int readMicroseconds(void);
### **Parameters**[](#id26)
NA
### **Returns**[](#id27)
This function returns an integer value that represents pulse width in microseconds.
### **Example Code**[](#id28)
NA
Note
“AmebaServo.h” must be included to use the class function.
## **AmebaServo::attached**[](#amebaservo-attached)
### **Description**[](#id29)
Check if the servo PWM pin is attached successfully.
### **Syntax**[](#id30)
bool attached(void);
### **Parameters**[](#id31)
NA
### **Returns**[](#id32)
This function returns 1 if the servo has been attached, else it returns 0.
### **Example Code**[](#id33)
Example: [PWM_ServoControl](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Analog/examples/PWM_ServoControl/PWM_ServoControl.ino)
Note
“AmebaServo.h” must be included to use the class function.
[ Previous](index.html)
[Next ](../BLE/index.html)
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