OLED Display — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- OLED Display
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/OLED Display.rst)
# OLED Display[](#oled-display)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- 0.96 inch OLED Display 128x64 (SSD1306) x 1
## Example[](#example)
### Introduction[](#introduction)
The example will showcase texts, shapes, and bitmap images on an OLED display using the I2C communication protocol alongside Adafruit libraries.
### Procedure[](#procedure)
Connect the 0.96-inch OLED display to I2C_SDA and I2C_SCL of the board.
[](../../../../_images/image01162.png)
Open the example in File -> Examples -> AmebaWire -> OLED_SSD1306
[](../../../../_images/image02157.png)
For this example, we will be using 0x3D as the address.
[](../../../../_images/image03136.png)
If the address doesn’t work for you, you can run I2CScanner to find the
OLED address by navigating to File -> Examples -> AmebaWire -> I2CScanner
[](../../../../_images/image0499.png)
Compile and upload to Ameba, then press the reset button.
First, Realtek logo will be shown, followed by shapes, text, and animations. Some examples are shown below.
[](../../../../_images/image0577.png)
[](../../../../_images/image0668.png)
[](../../../../_images/image0763.png)
If you would like to change the Bitmap image shown on the OLED display,
you can prepare a picture/photo and resize the image based on the OLED
display that you are using. You can look for a photo resizing tool
online, for example, [https://resizeimage.net/](https://resizeimage.net/).
Next, you may use online tools such as [https://javl.github.io/image2cpp/](https://javl.github.io/image2cpp/)
to convert image into an array.
## Code Reference[](#code-reference)
[1] Adafruit_SSD1306 library and example obtained from:
[https://github.com/adafruit/Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
[2] Adafruit_GFX library obtained from:
[https://github.com/adafruit/Adafruit-GFX-Library/tree/master](https://github.com/adafruit/Adafruit-GFX-Library/tree/master)
[ Previous](MPU6050%20Raw%20Data.html)
[Next ](Retrieve%20Data%20from%20VL53L0X%20IR%20sensor.html)
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