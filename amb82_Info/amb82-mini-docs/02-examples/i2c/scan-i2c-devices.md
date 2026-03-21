Scan I2C devices — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- Scan I2C devices
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/Scan I2C devices.rst)
# Scan I2C devices[](#scan-i2c-devices)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- Any I2C device x 1
## Example[](#example)
### Introduction[](#introduction)
The example will scan the I2C bus for devices that is connected to Ameba. When a device is found, it will be shown on the serial monitor
with the address of the device.
### Procedure[](#procedure)
Connect any I2C device to I2C_SDA and I2C_SCL of the board.
Open the example in File -> Examples -> AmebaWire -> I2C_Scanner
[](../../../../_images/image01164.png)
When the I2C bus detect any I2C device, the serial monitor will show the
address of the I2C device as shown below:
[](../../../../_images/image02159.png)
When there is no I2C device connected to the board, the Arduino IDE
serial monitor will show the message below:
[](../../../../_images/image03138.png)
## Code Reference[](#code-reference)
You can find detailed information of this example in the documentation of Arduino:
[https://playground.arduino.cc/Main/I2cScanner/](https://playground.arduino.cc/Main/I2cScanner/)
[ Previous](Retrieve%20Data%20from%20VL53L0X%20IR%20sensor.html)
[Next ](VL53L5CX%20Thumb%20Detection.html)
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