NAU7802 Gain Sample Rate — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- NAU7802 Gain Sample Rate
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/NAU7802 Gain Sample Rate.rst)
# NAU7802 Gain Sample Rate[](#nau7802-gain-sample-rate)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- [SparkFun Qwiic Scale - NAU7802](https://www.sparkfun.com/sparkfun-qwiic-scale-nau7802.html) x 1
- [Load Cell (20 kg)](https://shopee.sg/Load-Cell-1kg-5kg-10kg-20kg-i.440521573.7989384220)  x 1
## Example[](#example)
### Introduction[](#introduction)
This example shows how to adjust the specific parameters used in SparkFun NAU7802.
- 
**Gain** - The magnitude of amplification. Setting higher gain usually gives higher sensitivity.
Gain can be set to one of the following values:
`NAU7802_GAIN_128`  - 128x
- `NAU7802_GAIN_64`   - 64x
- `NAU7802_GAIN_32`   - 32x
- `NAU7802_GAIN_16`   - 16x (default gain)
- `NAU7802_GAIN_8`    - 8x
- `NAU7802_GAIN_4`    - 4x
- `NAU7802_GAIN_2`    - 2x
- `NAU7802_GAIN_1`    - 1x (zero gain)
- 
**Sample Rate** - The number of samples taken per second (SPS).
Sample Rate can be set to one of the following values:
`NAU7802_SPS_320`   - 320 Hz
- `NAU7802_SPS_80`    -  80 Hz
- `NAU7802_SPS_40`    -  40 Hz
- `NAU7802_SPS_20`    -  20 Hz
- `NAU7802_SPS_10`    -  10 Hz (default sample rate)
### Procedure[](#procedure)
Connect the Load Cell to NAU7802.
- Connect the red wire of Load Cell to RED pin (Excitation +) of NAU7802.
- Connect the black wire of Load Cell to BLK pin (Excitation -) of NAU7802.
- Connect the green wire of Load Cell to GRN pin (Signal +) of NAU7802.
- Connect the white wire of Load Cell to WHT pin (Signal -) of NAU7802.
Connect the AMB82-mini to NAU7802.
- Connect the VDD33 of AMB82-mini to 3V3 of NAU7802.
- Connect the GND   of AMB82-mini to GND of NAU7802.
- Connect the Pin 12 (I2C_SDA pin) of AMB82-mini to SDA of NAU7802.
- Connect the Pin 13 (I2C_SCL pin) of AMB82-mini to SCL of NAU7802.
Note
Download [User Guide](https://www.amebaiot.com/?s2member_file_download=AMB82-Mini_Hardware_User_Guide_0V3_20230303.pdf) to understand more on pin definition.
Tip
Depending on your NAU7802 version, some may support 5V+ operating voltage—please check the official website before you connect to a 5V power supply. If your NAU7802 supports 5V+ operating voltage, connecting to V_USB instead of VDD33 tends to have less jitter effect.
The final wiring should look like the diagram below.
[](../../../../_images/image01159.png)
Open the example in File -> Examples -> AmebaWire -> NAU7802 -> GainSampleRate
[](../../../../_images/image02154.png)
Compile and run the example.
[](../../../../_images/image03133.png)
You can try setting different values for **Gain** or **Sample Rate** to see the difference. The output above sets **Gain** to 2x and **Sample Rate** to 40 Hz (40 SPS). If you set the **Sample Rate** to 8x, you should see the values doubled.
[ Previous](NAU7802%20External%20Calibration.html)
[Next ](NAU7802%20Interrupt.html)
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