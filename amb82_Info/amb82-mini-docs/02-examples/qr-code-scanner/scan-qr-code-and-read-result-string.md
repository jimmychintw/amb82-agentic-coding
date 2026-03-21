Scan QR Code And Read Result String — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [QR Code Scanner](index.html)
- Scan QR Code And Read Result String
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/QR Code Scanner/Scan QR Code And Read Result String.rst)
# Scan QR Code And Read Result String[](#scan-qr-code-and-read-result-string)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
This example will demonstrate how to retrieve the result string and length when QR code is placed in front of the camera of AMB82 MINI.
Open the QR Code Scanner example File -> Examples -> AmebaQR -> QRCodeScanner
[](../../../../_images/image01223.png)
You can start the scanner by calling the method StartScanning(). Please note that this should be in the setup() and not in the loop().
You can retrieve the result string and result length by calling the method GetResultString() and GetResultLength().
Please note that users are to modify their conditional checks in the loop(). This is just an illustration on how to get the result string and length. Currently, 3rd successful scan onwards will be able to retrieve the result string and length reliably. Strongly encourage more people to try out and improve the performance of this example. This example may not be the most optimised version.
To optimise the performance for your application, one can modify the qr_code_scanner_config_map in qrcode_drv.c as shown in the picture below. For now, there is no API exposed on the Arduino level, but this can be done in future if there is a huge demand for it.
[](../../../../_images/image02215.png)
To test this example, compile and run the example. Place a QR code in from the camera of AMB82 MINI. If there is no QR code detected, you will be able to see this in Serial Monitor.
[](../../../../_images/image03192.png)
If QR Code is detected after 3 successful times, you will observe this log on the Serial Monitor.
[](../../../../_images/image04139.png)
[ Previous](index.html)
[Next ](../RTC/index.html)
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