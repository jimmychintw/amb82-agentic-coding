WS2812B - Basics — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [WS2812B](index.html)
- WS2812B - Basics
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/WS2812B/WS2812B - Basics.rst)
# WS2812B - Basics[](#ws2812b-basics)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- WS2812B LED Strip / Ring / Stick / Board x1
## Example[](#example)
### **Introduction**[](#introduction)
This example controls the WS2812B RGB LED, using the SPI peripheral to create the waveform necessary for the LEDs.
WS2812B basics controls a single LED with a color or fill all the LED with the same color.
## Procedure[](#procedure)
Connect the WS2812B to the Ameba board as shown in the following diagrams.
Wiring Diagram:
[](../../../../_images/image01229.png)
To light up individual LED or multiple LEDs with the same color,
Open the example in File -> Example -> AmebaWS2812B -> WS2812B_Basics
Modify **TOTAL_NUM_OF_LEDS** to be the total number of LEDs on the WS2812B module, and modify **NUM_OF_LEDS** to be the number of LEDs that has connected.
Next, compile and upload, then press the reset button. The first 3 LEDs light up with red, green, and blue color and after a while all the LED will be filled with 1 color.
[](../../../../_images/image02222.png)
[](../../../../_images/image03197.png)
## Code Reference[](#code-reference)
[WS2812B Datasheet](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf)
[ Previous](index.html)
[Next ](WS2812B%20-%20Patterns.html)
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