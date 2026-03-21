Retrieve Data from VL53L0X IR sensor — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- Retrieve Data from VL53L0X IR sensor
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/Retrieve Data from VL53L0X IR sensor.rst)
# Retrieve Data from VL53L0X IR sensor[](#retrieve-data-from-vl53l0x-ir-sensor)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- VL53L0X IR sensor x 1
## Example[](#example)
### Introduction[](#introduction)
This example will illustrate how to retrieve the value of VL53L0X IR
sensor and pass it to the AMB82-Mini board. VL53L0X Distance Sensor is a
Time-of-Flight (ToF) ranging module based on the VL53L0X from ST, with
accurate ranging up to 2m, which can be controlled via I2C interface and
has pretty low power consumption.
This guide will be the same for these 2 examples:
1) Continuous.ino
2) Single.ino
### Procedure[](#procedure)
Connect the VL53L0X IR sensor to I2C_SDA and I2C_SCL of the board as shown in the diagram below.
[](../../../../_images/image01163.png)
Open the example in File -> Examples -> AmebaWire -> VL53L0X -> Continuous OR Single
[](../../../../_images/image02158.png)
You will choose “Single” if you want to get single-shot range
measurements from the VL53L0X sensor. The sensor can be optionally be
configured with different ranging profiles to get better performance for
a certain application.
For both examples, the Serial Monitor will output the range measurements
as shown in the below image. It will output 8190 if there is no object
within 2m range.
[](../../../../_images/image03137.png)
## Code Reference[](#code-reference)
[1] VL53L0X library and examples by Pololu:
[https://github.com/pololu/vl53l0x-arduino](https://github.com/pololu/vl53l0x-arduino)
[ Previous](OLED%20Display.html)
[Next ](Scan%20I2C%20devices.html)
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