HX711 Basic Reading — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [GPIO](index.html)
- HX711 Basic Reading
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/GPIO/HX711 Basic Reading.rst)
# HX711 Basic Reading[](#hx711-basic-reading)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- [SparkFun Load Cell Amplifier - HX711](https://www.sparkfun.com/sparkfun-load-cell-amplifier-hx711.html) x 1
- [Load Cell (20 kg)](https://shopee.sg/Load-Cell-1kg-5kg-10kg-20kg-i.440521573.7989384220)  x 1
## Example[](#example)
### Introduction[](#introduction)
This example shows how to use SparkFun HX711 to get raw readings from a Load Cell.
### Procedure[](#procedure)
Connect the Load Cell to HX711.
- Connect the red wire of Load Cell to RED pin (Excitation +) of HX711.
- Connect the black wire of Load Cell to BLK pin (Excitation -) of HX711.
- Connect the green wire of Load Cell to GRN pin (Signal +) of HX711.
- Connect the white wire of Load Cell to WHT pin (Signal -) of HX711.
Connect the AMB82-mini to HX711.
- Connect the V_USB of AMB82-mini to VDD of HX711.
- Connect the GND   of AMB82-mini to GND of HX711.
- Connect the Pin 2 of AMB82-mini to DAT of HX711.
- Connect the Pin 3 of AMB82-mini to CLK of HX711.
The final wiring should look like the diagram below.
[](../../../../_images/image01123.png)
Open the example in File -> Examples -> AmebaGPIO -> HXH711 -> BasicReading
[](../../../../_images/image02118.png)
Compile and run the example.
[](../../../../_images/image0399.png)
The measurements from the Load Cell will be printed at 1s interval.
Please take note that this is raw and amplified readings from the Load Cell. We will learn how to calibrate this setup in the next example, so that the output is actually meaningful in grams.
[ Previous](Measure%20Temperature%20and%20Humidity%20DHT%20Tester.html)
[Next ](HX711%20Calibration.html)
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