Display SD JPG ILI9341 TFT — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [SPI](index.html)
- Display SD JPG ILI9341 TFT
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/SPI/Display SD JPG ILI9341 TFT.rst)
# Display SD JPG ILI9341 TFT[](#display-sd-jpg-ili9341-tft)
If you are not familiar with SPI, please read [Introduction to SPI](https://www.amebaiot.com/spi-intro/) first.
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- ILI9341 TFT LCD with SPI interface x 1
- microSD card x 1
## Example[](#example)
- QVGA 2.2″ TFT LCD
[http://www.lcdwiki.com/2.2inch_SPI_Module_ILI9341_SKU:MSP2202](http://www.lcdwiki.com/2.2inch_SPI_Module_ILI9341_SKU:MSP2202)
Common pins in ILI9341 TFT LCD with SPI interface:
- MOSI: Standard SPI Pin
- MISO: Standard SPI Pin
- SLK: Standard SPI Pin
- CS: Standard SPI Pin
- RESET: Used to reboot LCD.
- D/C: Data/Command. When it is at LOW, the signal transmitted are commands, otherwise the data transmitted are data.
- LED (or BL): Adapt the screen backlight. Can be controlled by PWM or connected to VCC for 100% backlight.
- VCC: Connected to 3V or 5V, depends on its spec.
- GND: Connected to GND.
**AMB82 MINI and QVGA TFT LCD Wiring Diagram:**
[](../../../../_images/image01226.png)
Note
Before compilation, kindly install TJpg_Decoder library via Arduino IDE library manager.
After installing the TJpg_Decoder library, in the library’s configuration file, User_Config.h, comment out line 5 which reads: #define TJPGD_LOAD_SD_LIBRARY to avoid compilation error.
Open the example, File -> Examples -> AmebaSPI -> DisplaySDJPG_ILI9341_TFT
[](../../../../_images/image02218.png)
Modify the file name according to the image saved name.
[](../../../../_images/image03193.png)
Compile and upload to Ameba, then press the reset button.
Then, you can see the image displayed on the LCD screen.
[ Previous](index.html)
[Next ](LCD%20Screen%20ILI9341%20TFT.html)
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