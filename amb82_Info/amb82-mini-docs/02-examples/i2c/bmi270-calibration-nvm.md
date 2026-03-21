BMI270 Calibration NVM — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- BMI270 Calibration NVM
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/BMI270 Calibration NVM.rst)
# BMI270 Calibration NVM[](#bmi270-calibration-nvm)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- [SparkFun 6oF IMU Breakout - BMI270](https://www.sparkfun.com/sparkfun-6dof-imu-breakout-bmi270-qwiic.html) x 1
## Example[](#example)
### Introduction[](#introduction)
This example does some basic calibration of the BMI270 and then allows you to write those calibrations to non volatile memory.
### Procedure[](#procedure)
Connect the AMB82-mini to I2C_SDA and I2C_SCL of the sensor as shown in the diagram below.
[](../../../../_images/image01137.png)
Open the example in File -> Examples -> AmebaWire -> BMI270 -> CalibrationNVM
[](../../../../_images/image02132.png)
Compile and run the example.
[](../../../../_images/image03111.png)
Warning
This chip only allows a total of 14 writes. Be mindful of this limit when recalibrating.
[ Previous](BMI270%20Basic%20Readings%20I2C.html)
[Next ](BMI270%20FIFO%20Buffer.html)
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