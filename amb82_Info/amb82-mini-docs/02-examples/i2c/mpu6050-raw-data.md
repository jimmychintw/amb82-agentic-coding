MPU6050 Raw Data — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- MPU6050 Raw Data
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/MPU6050 Raw Data.rst)
# MPU6050 Raw Data[](#mpu6050-raw-data)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- MPU6050 x 1
## Example[](#example)
### Introduction[](#introduction)
This example will demonstrate getting the raw data from MPU6050.
### Procedure[](#procedure)
Connect the MPU6050 to I2C_SDA and I2C_SCL of the board as shown in the diagram below.
[](../../../../_images/image01152.png)
Open the example in File -> Examples -> AmebaWire -> MPU6050 -> MPU6050_raw
[](../../../../_images/image02147.png)
Compile and run the example. In the Serial Monitor, you should be able to see the raw data from MPU6050.
[](../../../../_images/image03126.png)
If you see that the values are all 0, press reset until you can get values from MPU6050. If the first initialisation is done properly, the
values will be sent continuously over the I2C interface and will not cause any hanging issues.
You may choose to uncomment `#define OUTPUT_BINARY_ACCELGYRO` and comment
`#define OUTPUT_READABLE_ACCELGYRO` to transmit the raw data faster.
[](../../../../_images/image0493.png)
## Code Reference[](#code-reference)
[1] MPU6050 library and examples by ElectronicCats:
[https://github.com/ElectronicCats/mpu6050](https://github.com/ElectronicCats/mpu6050)
[ Previous](MPU6050%20IMU%20Zero.html)
[Next ](OLED%20Display.html)
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