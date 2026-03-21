MPU6050 DMP6 ImuData for ROS — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- MPU6050 DMP6 ImuData for ROS
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/MPU6050 DMP6 ImuData for ROS.rst)
# MPU6050 DMP6 ImuData for ROS[](#mpu6050-dmp6-imudata-for-ros)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- MPU6050 x 1
## Example[](#example)
### Introduction[](#introduction)
This example will demonstrate getting the data from MPU6050 with DMP6.
MPU6050 is equipped with a Digital Motion Processor (DMP) to handle the
calculations of motion algorithms such as conversion to 3-axis
yaw/pitch/roll of planes, conversion to quaternion, or conversion to
Euler angle. In addition, this example will calculate world-frame
acceleration, adjusted to remove gravity, and rotated based on known
orientation from quaternion.
### Procedure[](#procedure)
Connect the MPU6050 to I2C_SDA and I2C_SCL of the board as shown in the diagram below.
[](../../../../_images/image01150.png)
Open the example in File -> Examples -> AmebaWire -> MPU6050 -> MPU6050_DMP6_ImuData_for_ROS.ino
[](../../../../_images/image02145.png)
Compile and run the example. In the Serial Monitor, you should be able
to see the output of quaternion, world-frame acceleration, world-frame
gyro values and yaw/pitch/roll values.
[](../../../../_images/image03124.png)
## Code Reference[](#code-reference)
[1] MPU6050 library and examples by ElectronicCats:
[https://github.com/ElectronicCats/mpu6050](https://github.com/ElectronicCats/mpu6050)
[ Previous](MPU6050%20DMP6.html)
[Next ](MPU6050%20IMU%20Zero.html)
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