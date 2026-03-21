BMI270 Self Test — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- BMI270 Self Test
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/BMI270 Self Test.rst)
# BMI270 Self Test[](#bmi270-self-test)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- [SparkFun 6oF IMU Breakout - BMI270](https://www.sparkfun.com/sparkfun-6dof-imu-breakout-bmi270-qwiic.html) x 1
## Example[](#example)
### Introduction[](#introduction)
This example will run the sensor’s self test feature. This will return an error code to indicate whether the test was successful.
### Procedure[](#procedure)
Connect the AMB82-mini to I2C_SDA and I2C_SCL of the sensor as shown in the diagram below.
[](../../../../_images/image01144.png)
Open the example in File -> Examples -> AmebaWire -> BMI270 -> SelfTest
[](../../../../_images/image02139.png)
Compile and run the example.
The error code will be printed out if the test was unsuccessful.
[](../../../../_images/image03118.png)
[ Previous](BMI270%20Remap%20Axes.html)
[Next ](BMI270%20Significant%20Motion.html)
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