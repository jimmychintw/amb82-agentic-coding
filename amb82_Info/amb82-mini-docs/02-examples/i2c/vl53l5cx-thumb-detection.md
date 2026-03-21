VL53L5CX Thumb Detection — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- VL53L5CX Thumb Detection
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/VL53L5CX Thumb Detection.rst)
# VL53L5CX Thumb Detection[](#vl53l5cx-thumb-detection)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- [SparkFun Qwiic ToF Imager - VL53L5CX](https://www.sparkfun.com/sparkfun-qwiic-tof-imager-vl53l5cx.html) x 1
## Example[](#example)
### Introduction[](#introduction)
This example shows how to use the SparkFun VL53L5CX Time-of-Flight sensor in 8x8 mode to detect thumbs-up or thumbs-down gestures.
### Procedure[](#procedure)
Connect the VL53L5CX to I2C_SDA and I2C_SCL of the board as shown in the diagram below.
[](../../../../_images/image01171.png)
Open the example in File -> Examples -> AmebaWire -> VL53L5CX -> ThumbDetection
[](../../../../_images/image02166.png)
Compile and run the example. In the Serial Monitor, you should be able to see the logs.
When no thumb direction is detected, the log will display “Unclear thumb direction”.
[](../../../../_images/image03145.png)
If a thumbs-up is detected, it will display “Thumbs up”.
[](../../../../_images/image04101.png)
and if a thumb-down is detected, it will display “Thumbs down”.
[](../../../../_images/image0578.png)
[ Previous](Scan%20I2C%20devices.html)
[Next ](VL53L5CX%20sensor%20Hand%20Presence%20Detection.html)
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