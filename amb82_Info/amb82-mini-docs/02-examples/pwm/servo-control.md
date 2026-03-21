Servo Control — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [PWM](index.html)
- Servo Control
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/PWM/Servo Control.rst)
# Servo Control[](#servo-control)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- Servo x 1 (Ex. Tower Pro SG90)
## Example[](#example)
A typical servo has 3 wires, the red wire is for power, black or brown one should be connected to GND, and the other one is for signal data. We use PWM signal to control the rotation angle of the axis of the servo. The frequency of the signal is 50Hz, that is length 20ms. Each servo defines its pulse bandwidth, which is usually 1ms~2ms.
To control the rotation angle, for example if 1ms-length pulse rotates the axis to degree 0, then 1.5 ms pulse rotates the axis to 90 degrees, and 2 ms pulse rotates the axis to 180 degrees. Furthermore, a servo defines the “dead bandwidth”, which stands for the required minimum difference of the length of two consecutive pulse for the servo to work.
**AMB82 MINI** wiring diagram:
[](../../../../_images/image01218.png)
Open the example, File -> Examples -> AmebaAnalog -> PWM_ServoControl
This example makes the servo to rotate from degree 0 to 180, and then rotate back to degree 0.
## Code Reference[](#code-reference)
The Servo API of Ameba is similar to the API of Arduino. To distinguish from the original API of Arduino, we name the header file “AmebaServo.h” and the Class “AmebaServo”, the usage is identical to the Arduino API.
The default pulse bandwidth of Arduino Servo is 0.5ms~2.4ms, which is the same as Tower Pro SG90. Therefore, we set the attached pin directly:
myservo.attach(9);
Next, rotate the axis to desired position:
myservo.write(pos);
[ Previous](Buzzer%20Play%20Melody.html)
[Next ](../QR%20Code%20Scanner/index.html)
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