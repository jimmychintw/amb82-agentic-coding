# Display Images on E-Paper

## Materials

- AMB82-mini x 1
- Waveshare E-Paper [2.9inch E-Paper HAT (D)/ 2.9inch E-Paper V2/ 2.9inch e-Paper Module (B)/ 4.2inch e-Paper Module/ 7.5-inch E-Ink display HAT] x1

Note: The Universal E-Paper Driver HAT using for all E-Papers is compatible with version V2.1 only.

## Introduction

In this example, Ameba Pro2 board will be used to connect to a Waveshare e-Paper module (2.9inch/ 4.2inch/ 7.5inch) to display images.

## Procedure

**AMB82-Mini wiring diagram:**

Connect according to the appropriate wiring diagram for your e-Paper size.

Firstly, prepare a picture/photo and resize the image based on the e-Paper display:
- 2.9" e-Paper module: 296x128 pixels
- 4.2" e-Paper module: 400x300 pixels
- 7.5" e-Paper module: 800x480 pixels

Secondly, use Image2LCD tool to convert the resized JPEG image into hexadecimal codes.

Download the Eink zip library AmebaEink.zip and install it.

Eink examples are categorised based on the size and modules of the e-Paper display.

Open one of the "EinkDisplayImages" examples. For example, File -> Examples -> AmebaEink -> EPD_2in9v2 -> EinkDisplayImages

You may choose any GPIO pins for Busy, Reset and DC pin.

Upload the code to the board and press the reset button after uploading is done. Wait for around 1-2 seconds for the e-Paper module to refresh its screen. Images will start to loop on the e-Paper display, each image will be displaying for 4 seconds.

The 2.9-inch e-Paper Module (B) supports three colours—red, black, and white.