Class WS2812B — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [WS2812B](index.html)
- Class WS2812B
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/WS2812B/Class WS2812B.rst)
# Class WS2812B[](#class-ws2812b)
## **WS2812B Class**[](#ws2812b-class)
### **Description**[](#description)
A class for using WS2812B LED.
### **Syntax**[](#syntax)
class WS2812B
### **Members**[](#members)
|**Public Methods**
|
|
| WS2812B::WS2812B
|
Constructs a WS2812B
object
|
|
| **Public Methods**
|
|
| WS2812B::begin
|
Check for correct pin
settings and prepare to
drive the WS2812B
|
|
| WS2812B::show
|
Pushes the color data
out to the LEDs
|
|
| WS2812B::clear
|
Clear the memory
|
|
| WS2812B::setLEDCount
|
Set total number of LED
that will be used and
allocate memory for
all the LEDs
|
|
| WS2812B::setPixelColor
|
Set the color of a LED
|
|
| WS2812B::fill
|
Set multiple LEDs with
the same color
|
|
| WS2812B::colorHSV
|
Convert to RGB values
from HSV
|
|
| WS2812B::rainbow
|
Fill all the LEDs with
one or more cycle of
hues
|
|
## **WS2812B::WS2812B**[](#ws2812b-ws2812b)
### **Description**[](#id1)
Constructs a WS2812B object
### **Syntax**[](#id2)
WS2812B(uint8_t input_pin, uint16_t num_leds);
### **Parameters**[](#parameters)
`input_pin` : The MOSI pin that is connected to the WS2812B LED.
`num_leds` : The number of LEDs that needs to be light up
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [WS2812B_Basics](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WS2812B/examples/WS2812B_Basics/WS2812B_Basics.ino)
Important
Only SPI MOSI pin is valid for driving WS2812B LEDs.
Note
“WS2812B.h” must be included to use the class function.
## **WS2812B::begin**[](#ws2812b-begin)
### **Description**[](#id3)
Check for correct pin settings and prepare to drive the WS2812B
### **Syntax**[](#id4)
void begin(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [WS2812B_Basics](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WS2812B/examples/WS2812B_Basics/WS2812B_Basics.ino)
Important
Only SPI MOSI pin is valid for driving WS2812B LEDs.
Note
“WS2812B.h” must be included to use the class function.
## **WS2812B::show**[](#ws2812b-show)
### **Description**[](#id9)
Pushes the color data out to the LEDs by initialising SPI pins and revert all the unnecessary SPI pins (MISO, DC and SS) to GPIO function first. Then allocate the RGB data to each LED.
### **Syntax**[](#id10)
void show(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [WS2812B_Basics](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WS2812B/examples/WS2812B_Basics/WS2812B_Basics.ino)
Important
The amount of time needed to push the color data will increase with more LEDs.
Note
“WS2812B.h” must be included to use the class function.
## **WS2812B::clear**[](#ws2812b-clear)
### **Description**[](#id15)
Clear the memory
### **Syntax**[](#id16)
void clear (void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
NA
### **Example Code**[](#id19)
Example: [WS2812B_Patterns](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WS2812B/examples/WS2812B_Patterns/WS2812B_Patterns.ino)
Important
This function only clears the color data from memory. To turn off the LED, please use WS2812B::show().
Note
“WS2812B.h” must be included to use the class function.
## **WS2812B::setLEDCount**[](#ws2812b-setledcount)
### **Description**[](#id20)
Set the total number of LEDs to be used and allocate memory for all the LEDs.
### **Syntax**[](#id21)
void setLEDCount(uint16_t num_leds);
### **Parameters**[](#id22)
`num_leds`: total number of LEDs to be used
### **Returns**[](#id23)
NA
### **Example Code**[](#id24)
NA
Note
“WS2812B.h” must be included to use the class function.
## **WS2812B::setPixelColor**[](#ws2812b-setpixelcolor)
### **Description**[](#id25)
Verify that memory has been successfully allocated to the LED and set the color.
### **Syntax**[](#id26)
void setPixelColor(uint16_t led_Number, uint8_t rColor, uint8_t gColor, uint8_t bColor);
### **Parameters**[](#id27)
`led_Number`: The LED number, with 0 being the LED closest to the data input pin
`rColor`: Red brightness level (Value available from 0-255, 0 indicates LED is off and 255 indicates LED is in the maximum brightness)
`gColor`: Green brightness level (Value available from 0-255)
`bColor`: Blue brightness level (Value available from 0-255)
### **Returns**[](#id28)
NA
### **Example Code**[](#id29)
Example: [WS2812B_Patterns](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WS2812B/examples/WS2812B_Patterns/WS2812B_Patterns.ino)
Note
“WS2812B.h” must be included to use the class function.
## **WS2812B::fill**[](#ws2812b-fill)
### **Description**[](#id31)
Set multiple LEDs with the same colors
### **Syntax**[](#id32)
void fill(uint8_t rColor, uint8_t gColor, uint8_t bColor, uint16_t first, uint16_t count);
### **Parameters**[](#id33)
`rColor`: Red brightness level (Value available from 0-255)
`gColor`: Green brightness level (Value available from 0-255)
`bColor`: Blue brightness level (Value available from 0-255)
`first`: The index of the first LED to start filling with color (Default: 0)
`count`: Total number of LEDs to be set with the color (Default: 0)
### **Returns**[](#id34)
NA
### **Example Code**[](#id35)
Example: [WS2812B_Basics](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WS2812B/examples/WS2812B_Basics/WS2812B_Basics.ino)
Important
If the input parameters “first” and “count” are not provided, the default behaviour would be to fill all the LEDs.
Note
“WS2812B.h” must be included to use the class function.
## **WS2812B::colorHSV**[](#ws2812b-colorhsv)
### **Description**[](#id37)
Convert to RGB values from HSV (Hue Saturation Value).
### **Syntax**[](#id38)
uint32_t colorHSV(uint16_t hue, uint8_t sat, uint8_t val);
### **Parameters**[](#id39)
`hue`: hue value in 16-bit. (Default: 0, acceptable range from: 0 - 65535, representing one full cycle of the color wheel. Starting from 0 for red, it increments first towards yellow, and on through green, cyan, blue, magenta, and black to red.)
`sat`: Intensity or purity of the color in 8-bit. (Acceptable range from: 0 - 255, you will get pastel color when value setting is adjusted to the middle)
`val`: Brightness of a color in 8-bit. (Value available from 0-255)
### **Returns**[](#id40)
The function returns the RGB values converted from HSV.
### **Example Code**[](#id41)
Example: [WS2812B_Patterns](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WS2812B/examples/WS2812B_Patterns/WS2812B_Patterns.ino)
Note
“WS2812B.h” must be included to use the class function.
## **WS2812B::rainbow**[](#ws2812b-rainbow)
### **Description**[](#id43)
Fill all the LEDs with one or more cycle of hues
### **Syntax**[](#id44)
void rainbow(uint16_t first_hue, int8_t reps, uint8_t saturation, uint8_t brightness);
### **Parameters**[](#id45)
`first_hue`: hue of first LED (Default: 0, acceptable range from: 0 - 65535, representing one full cycle of the color wheel)
`reps`: number of cycles of the color wheel over the length of the strip. (Default: 1. Negative values can be used to reverse the hue order)
`saturation`: Intensity or purity of the color in 8-bit. (Default: 255. Acceptable range from: 0 - 255, you will get pastel color when value setting is adjusted to the middle)
`brightness`: Brightness of a color in 8-bit. (Default: 60. Acceptable range from 0-255)
### **Returns**[](#id46)
NA
### **Example Code**[](#id47)
Example: [WS2812B_Patterns](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WS2812B/examples/WS2812B_Patterns/WS2812B_Patterns.ino)
Note
“WS2812B.h” must be included to use the class function.
[ Previous](index.html)
[Next ](../../Other_Guides/index.html)
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