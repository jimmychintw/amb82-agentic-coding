# Display User-generated QR Code

## Materials

- AMB82-mini x 1
- Waveshare E-Paper [2.9inch E-Paper HAT (D)/ 2.9inch E-Paper V2/ 2.9inch e-Paper Module (B)/ 4.2inch e-Paper Module/ 7.5-inch E-Ink display HAT] x1

Note: The Universal E-Paper Driver HAT using for all E-Papers is compatible with version V2.1 only.

## Introduction

In this example, Ameba Pro2 board will be used to connect to a Waveshare e-Paper module (2.9inch/ 4.2inch/ 7.5inch) to display QR codes.

## Procedure

**AMB82-Mini wiring diagram:**

Connect according to the appropriate wiring diagram for your e-Paper size.

Download the Eink zip library AmebaEink.zip and install it.

Open one of the "EinkDisplayQR" examples. For example, File -> Examples -> AmebaEink -> EPD_2in9v2 -> EinkDisplayQR

You may choose any GPIO pins for Busy, Reset and DC pin.

Modify the URL in the loop() section for your QR code, then upload the code to the Ameba board.

A QR code generated based on the input URL will be shown on the E-paper module.

## Code Reference

1. Good Display GDEH029A1 2.9 Inch Arduino Sample Code: http://www.good-display.com/product/201.html

2. EPD libraries: https://github.com/waveshare/e-Paper

3. QR code generation: https://eugeniopace.org/qrcode/arduino/eink/2019/07/01/qrcode-on-arduino.html

4. QR code library for C: https://github.com/ricmoo/QRCode