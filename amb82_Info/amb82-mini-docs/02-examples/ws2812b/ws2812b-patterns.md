WS2812B - Patterns — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [WS2812B](index.html)
- WS2812B - Patterns
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/WS2812B/WS2812B - Patterns.rst)
# WS2812B - Patterns[](#ws2812b-patterns)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- WS2812B LED Strip / Ring / Stick / Board x1
## Example[](#example)
### **Introduction**[](#introduction)
This example controls the WS2812B RGB LED, using the SPI peripheral to create the waveform necessary for the LEDs.
WS2812B patterns controls LED (Strip / Ring / Stick / Board) with different colors with different LED patterns.
## Procedure[](#procedure)
Connect the WS2812B to the Ameba board as shown in the following diagrams.
Wiring Diagram:
[](../../../../_images/image01230.png)
To create different light patterns with many different colors,
Open the example in File -> Example -> AmebaWS2812B -> WS2812B_Patterns
Modify **TOTAL_NUM_OF_LEDS** to be the total number of LEDs on the WS2812B module, and modify **NUM_OF_LEDS** to be the number of LEDs that has connected.
Next, compile and upload, then press the reset button. The WS2812B displaying a color wipe, theater chase, rainbow, and theater chase rainbow light patterns in loop.
[](../../../../_images/image02223.png)
[](../../../../_images/image03198.png)
[](../../../../_images/image04141.png)
[](../../../../_images/image05110.png)
## Code Reference[](#code-reference)
[WS2812B Datasheet](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf)
[ Previous](WS2812B%20-%20Basics.html)
[Next ](../../API_Documents/index.html)
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