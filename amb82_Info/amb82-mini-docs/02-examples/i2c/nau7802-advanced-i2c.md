NAU7802 Advanced I2C — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- NAU7802 Advanced I2C
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/NAU7802 Advanced I2C.rst)
# NAU7802 Advanced I2C[](#nau7802-advanced-i2c)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- [SparkFun Qwiic Scale - NAU7802](https://www.sparkfun.com/sparkfun-qwiic-scale-nau7802.html) x 1
- [Load Cell (20 kg)](https://shopee.sg/Load-Cell-1kg-5kg-10kg-20kg-i.440521573.7989384220)  x 1
## Example[](#example)
### Introduction[](#introduction)
This example shows how to configure a different I2C bus with different clock speed for NAU7802.
### Procedure[](#procedure)
Connect the Load Cell to NAU7802.
- Connect the red wire of Load Cell to RED pin (Excitation +) of NAU7802.
- Connect the black wire of Load Cell to BLK pin (Excitation -) of NAU7802.
- Connect the green wire of Load Cell to GRN pin (Signal +) of NAU7802.
- Connect the white wire of Load Cell to WHT pin (Signal -) of NAU7802.
Connect the AMB82-mini to NAU7802.
- Connect the VDD33 of AMB82-mini to 3V3 of NAU7802.
- Connect the GND   of AMB82-mini to GND of NAU7802.
- Connect the Pin 09 (I2C_SDA1 pin) of AMB82-mini to SDA of NAU7802.
- Connect the Pin 10 (I2C_SCL1 pin) of AMB82-mini to SCL of NAU7802.
Note
Download [User Guide](https://www.amebaiot.com/?s2member_file_download=AMB82-Mini_Hardware_User_Guide_0V3_20230303.pdf) to understand more on pin definition. If you are following through all other NAU7802 examples for AMB82-mini, do remember to configure your I2C pins properly, this example uses Pin 09 and Pin 10.
Tip
Depending on your NAU7802 version, some may support 5V+ operating voltage—please check the official website before you connect to a 5V power supply. If your NAU7802 supports 5V+ operating voltage, connecting to V_USB instead of VDD33 tends to have less jitter effect.
The final wiring should look like the diagram below.
[](../../../../_images/image01155.png)
Open the example in File -> Examples -> AmebaWire -> NAU7802 -> AdvancedI2C
[](../../../../_images/image02150.png)
Compile and run the example.
[](../../../../_images/image03129.png)
The NAU7802 supports up to **400k Hz**. You can also pass different wire port into the library.
[ Previous](NAU7802%20Low%20Power.html)
[Next ](../MQTT/index.html)
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