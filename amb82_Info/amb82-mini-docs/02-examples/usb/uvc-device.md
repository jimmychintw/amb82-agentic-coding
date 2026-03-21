UVC Device — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [USB](index.html)
- UVC Device
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/USB/UVC Device.rst)
# UVC Device[](#uvc-device)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
AmebaPro2 ISP can support compressed (H264 / H265 / JPG) and uncompressed (NV16 / NV12) image through UVC (wired transmission), and user can check video on pc with PC applications (e.g., Potplayer).
Connect the “Micro USB” into Arduino IDE device. Open the sample code in File -> Examples -> AmebaUSB -> UVC_Device Compile and upload to Ameba, then press the reset button. Connect the “USB OTG” via micro-USB cable to the target device such as PC, then use the Ameba device as a USB cam.
[](../../../../_images/image01228.png)
Review the USB cam driver as following picture.
[](../../../../_images/image02221.png)
It is optional to open the Serial Monitor, review the processing log. At this stage “Micro USB” can be disconnected.
[](../../../../_images/image03196.png)
## Additional[](#additional)
For others common PC applications (e.g., Windows apps, VLC, Zoom, OBS, and Google Meet), define the encoder UVCD_MJPG value to **1**, and for all other applications, set it to **0** in [UVCD_pram.h](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/USB/src/UVCD_pram.h) within your Arduino environment.
[ Previous](index.html)
[Next ](USB%20Mass%20Storage.html)
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