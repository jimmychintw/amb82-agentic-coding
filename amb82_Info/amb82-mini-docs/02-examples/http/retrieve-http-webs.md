Retrieve HTTP webs — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [HTTP](index.html)
- Retrieve HTTP webs
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/HTTP/Retrieve HTTP webs.rst)
# Retrieve HTTP webs[](#retrieve-http-webs)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
In this example, the HttpClient library is used to retrieve a webpage using the HTTP protocol.
First, make sure that the correct Ameba development board is selected in Tools -> Board
Then open File -> Examples -> AmebaHttp -> RetrieveHttpWebs
[](../../../../_images/image01134.png)
In the sample code, modify the highlighted section to enter the information required (ssid, password, key index) to connect to your WiFi network.
[](../../../../_images/image02129.png)
Upload the code and press the reset button on Ameba once the upload is finished. Open the serial monitor in the Arduino IDE and you can see the information retrieved from the website.
[](../../../../_images/image03108.png)
## Code Reference[](#code-reference)
Use WiFi.begin() to establish WiFi connection:
[https://www.arduino.cc/en/Reference/WiFiBegin](https://www.arduino.cc/en/Reference/WiFiBegin)
To get the information of a WiFi connection:
Use WiFi.SSID() to get SSID of the current connected network.
[https://www.arduino.cc/en/Reference/WiFiSSID](https://www.arduino.cc/en/Reference/WiFiSSID)
Use WiFi.RSSI() to get the signal strength of the connection.
[https://www.arduino.cc/en/Reference/WiFiRSSI](https://www.arduino.cc/en/Reference/WiFiRSSI)
Use WiFi.localIP() to get the IP address of Ameba.
[https://www.arduino.cc/en/Reference/WiFiLocalIP](https://www.arduino.cc/en/Reference/WiFiLocalIP)
Use WiFiClient to create a client to handle the WiFi connection.
[https://www.arduino.cc/en/Reference/WiFiClient](https://www.arduino.cc/en/Reference/WiFiClient)
Use HTTPClient to create a client to handle the HTTP connection.
Use http.get() to send a GET request to the website.
[ Previous](HTTP%20Upload%20Image%20Telegram.html)
[Next ](Use%20IFTTT%20for%20Web%20Service.html)
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