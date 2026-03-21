NAU7802 Complete Scale — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [I2C](index.html)
- NAU7802 Complete Scale
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/I2C/NAU7802 Complete Scale.rst)
# NAU7802 Complete Scale[](#nau7802-complete-scale)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- [SparkFun Qwiic Scale - NAU7802](https://www.sparkfun.com/sparkfun-qwiic-scale-nau7802.html) x 1
- [Load Cell (20 kg)](https://shopee.sg/Load-Cell-1kg-5kg-10kg-20kg-i.440521573.7989384220)  x 1
- 
Known weights for calibration purposes (e.g., 200g and 500g) x 2
1st known weight is used DURING calibration to calculate calibration factor.
- 2nd known weight is used AFTER calibration to test the accuracy of the calibrated setup.
Note
For more information, you may refer to the [Qwiic Scale Hookup Guide](https://learn.sparkfun.com/tutorials/qwiic-scale-hookup-guide).
- If you need very precise calibration (this example is only meant for learning purposes), you may need to 3D print or purchase a scale where you can fit your Load Cell into.
[](../../../../_images/image01157.png)
## Example[](#example)
### Introduction[](#introduction)
This example shows how to calibrate SparkFun NAU7802 to get actual measurements (in grams) from a Load Cell, using software calibration.
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
[](../../../../_images/image02152.png)
Open the example in File -> Examples -> AmebaWire -> NAU7802 -> CompleteScale
[](../../../../_images/image03131.png)
The calibration process here involves 3 main steps:
- **Taring (Zeroing)** - Remove any offset to ensure the scale reads 0g when empty.
- **Calibration** - Use a known weight to calculate the calibration factor.
- **Verification** - Use another known weight to verify if the scale is accurate.
Compile and run the example.
[](../../../../_images/image0496.png)
Follow the instructions on Serial Monitor to complete the calibrate process, start the process by sending `c` from Serial Monitor.
### Step 1: Taring the Scale[](#step-1-taring-the-scale)
**Purpose:** Zero out the scale to remove any initial offset or bias.
- Remove any objects from the Load Cell.
- 
Ensure the Load Cell is on a level, stable surface.
Please take note that the Load Cell is very sensitive to any form of vibration or pressure, you should ensure the Load Cell is firmly mounted a flat surface to get accurate readings.
- When prompted with `Setup scale with no weight on it. Press a key when ready.`, send any key from the Serial Monitor, or simply type `Enter`.
- Wait for the confirmation message like `New zero offset: ...`.
**What’s happening:** The NAU7802 takes multiple readings and sets this as the zero point (baseline). Any future measurements will be relative to this baseline.
### Step 2: Measuring Known Weight[](#step-2-measuring-known-weight)
**Purpose:** Calculate the calibration factor by comparing raw sensor readings to a known weight.
**Procedure:**
- When prompted with `Place known weight on scale. Press a key when weight is in place and stable.`, place your 1st known weight (e.g., 200g) on the Load Cell and send any key from the Serial Monitor, or simply press `Enter`.
- When prompted with `Please enter the weight, without units, currently sitting on the scale (for example '200.0' - in gram):`, send the weight in grams in the Serial Monitor (e.g., `200.0` for 200g).
- Press `Enter` to send the value.
- The system will take readings and calculate the calibration factor.
- Note down the `New cal factor: ...` displayed in the Serial Monitor.
**What’s happening:** The code reads the raw and amplified signal from the NAU7802 and divides it by your known weight to determine how many raw units equal one gram. This ratio is your calibration factor.
### Step 3: Re-Taring for Verification (Optional But Recommended)[](#step-3-re-taring-for-verification-optional-but-recommended)
**Purpose:** Verify that the scale correctly reads 0g when empty after calibration.
- Remove the known weight from the Load Cell.
- Send `t` from the Serial Monitor.
**What’s happening:** This ensures that after calibration, the scale still properly zeros out when empty.
### Step 4: Calibration Complete[](#step-4-calibration-complete)
After completing all three steps, your scale is now calibrated! The Serial Monitor will continuously display weight readings every second.
- Now, place you 2nd known weight to test if the calibrated setup is accurate.
- Finally, you can use these commands in the Serial Monitor:
`t` - Tare (zero) the scale
- `c` - Run the full calibration procedure again
Tip
Use heavier calibration weights (200g-1000g) as they provide more reliable calibration factors.
[ Previous](NAU7802%20Basic%20Reading.html)
[Next ](NAU7802%20External%20Calibration.html)
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