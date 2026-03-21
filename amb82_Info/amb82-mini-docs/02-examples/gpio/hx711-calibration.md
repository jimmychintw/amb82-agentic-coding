HX711 Calibration — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [GPIO](index.html)
- HX711 Calibration
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/GPIO/HX711 Calibration.rst)
# HX711 Calibration[](#hx711-calibration)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- [SparkFun Load Cell Amplifier - HX711](https://www.sparkfun.com/sparkfun-load-cell-amplifier-hx711.html) x 1
- [Load Cell (20 kg)](https://shopee.sg/Load-Cell-1kg-5kg-10kg-20kg-i.440521573.7989384220)  x 1
- 
Known weights for calibration purposes (e.g., 200g and 500g) x 2
1st known weight is used DURING calibration to calculate calibration factor.
- 2nd known weight is used AFTER calibration to test the accuracy of the calibrated setup.
## Example[](#example)
### Introduction[](#introduction)
This example shows how to calibrate SparkFun HX711 to get actual measurements (in grams) from a Load Cell.
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
[](../../../../_images/image01124.png)
Open the example in File -> Examples -> AmebaGPIO -> HXH711 -> Calibration
[](../../../../_images/image02119.png)
The calibration process here involves 3 main steps:
- **Taring (Zeroing)** - Remove any offset to ensure the scale reads 0g when empty.
- **Calibration** - Use a known weight to calculate the calibration factor.
- **Verification** - Use another known weight to verify if the scale is accurate.
Compile and run the example.
[](../../../../_images/image03100.png)
### Step 1: Taring the Scale[](#step-1-taring-the-scale)
**Purpose:** Zero out the scale to remove any initial offset or bias.
- Remove any objects from the Load Cell.
- 
Ensure the Load Cell is on a level, stable surface.
Please take note that the Load Cell is very sensitive to any form of vibration or pressure, you should ensure the Load Cell is firmly mounted a flat surface to get accurate readings.
- When prompted, send `t` (tare) from the Serial Monitor.
- Wait for the confirmation message: “Tare completed”.
**What’s happening:** The HX711 takes multiple readings and sets this as the zero point (baseline). Any future measurements will be relative to this baseline.
### Step 2: Measuring Known Weight[](#step-2-measuring-known-weight)
**Purpose:** Calculate the calibration factor by comparing raw sensor readings to a known weight.
**Procedure:**
- Place your 1st known weight (e.g., 200g) on the Load Cell.
- When prompted, type the weight in grams in the Serial Monitor (e.g., `200.0` for 200g).
- Press `Enter` to send the value.
- The system will take 30 readings and calculate the calibration factor.
- Note down the `NEW CALIBRATION VALUE` displayed in the Serial Monitor.
**What’s happening:** The code reads the raw and amplified signal from the HX711 and divides it by your known weight to determine how many raw units equal one gram. This ratio is your calibration factor.
### Step 3: Re-Taring for Verification (Optional But Recommended)[](#step-3-re-taring-for-verification-optional-but-recommended)
**Purpose:** Verify that the scale correctly reads 0g when empty after calibration.
- Remove the known weight from the Load Cell.
- When prompted, send `t` from the Serial Monitor.
- Wait for confirmation: `✓ Scale zeroed! Empty scale now reads 0g`.
**What’s happening:** This ensures that after calibration, the scale still properly zeros out when empty.
### Step 4: Calibration Complete[](#step-4-calibration-complete)
After completing all three steps, your scale is now calibrated! The Serial Monitor will continuously display weight readings every second.
- Now, place you 2nd known weight to test if the calibrated setup is accurate.
- Finally, you can use these commands in the Serial Monitor:
`t` - Tare (zero) the scale
- `r` - Run the full calibration procedure again
- `c` - Manually change the calibration factor
Tip
Use heavier calibration weights (200g-1000g) as they provide more reliable calibration factors.
[ Previous](HX711%20Basic%20Reading.html)
[Next ](../GTimer/index.html)
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