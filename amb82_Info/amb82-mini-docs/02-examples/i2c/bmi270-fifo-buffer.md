BMI270 FIFO Buffer — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- BMI270 FIFO Buffer
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/BMI270 FIFO Buffer.rst)
# BMI270 FIFO Buffer[](#bmi270-fifo-buffer)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- [SparkFun 6oF IMU Breakout - BMI270](https://www.sparkfun.com/sparkfun-6dof-imu-breakout-bmi270-qwiic.html) x 1
## Example[](#example)
### Introduction[](#introduction)
This example shows how to use SparkFun 6DoF BMI270 to get basic measurements using I2C based on FIFO buffer.
### Procedure[](#procedure)
Connect the AMB82-mini to I2C_SDA, I2C_SCL, INT1 of the sensor as shown in the diagram below.
[](../../../../_images/image01138.png)
Open the example in File -> Examples -> AmebaWire -> BMI270 -> FIFOBuffer
[](../../../../_images/image02133.png)
Compile and run the example.
The measurements from the sensor will be printed based on a FIFO buffer (default size is 5).
[](../../../../_images/image03112.png)
[ Previous](BMI270%20Calibration%20NVM.html)
[Next ](BMI270%20Filtering.html)
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