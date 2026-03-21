Retrieve Universal Time (UTC) by NTPClient library — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [NTP](index.html)
- Retrieve Universal Time (UTC) by NTPClient library
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/NTP/Retrieve Universal Time (UTC) by NTPClient library.rst)
# Retrieve Universal Time (UTC) by NTPClient library[](#retrieve-universal-time-utc-by-ntpclient-library)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
In this example, we use an NTP client to sync with NTP servers using UDP and keep track of time locally.Open the example. File -> Examples -> NTPClient -> Advanced
[](../../../../_images/image01197.png)
Modify the highlighted code section (ssid, password) to connect to your WiFi network.
[](../../../../_images/image02190.png)
Compile the code and upload it to Ameba. After pressing the Reset button, Ameba connects to WiFi, gets the UTC time from the NTP server, and prints out the current time with time zone offset to the serial monitor.
[](../../../../_images/image03169.png)
## Code Reference[](#code-reference)
Configure NTP client:
The NTPClient needs to use a UDP client for communications. A WiFiUDP client is declared and passed to the NTPClient constructor, along with an NTP server address, time zone offset in seconds, and update interval in milliseconds. If detailed configuration is not needed, just passing in the UDP client is also sufficient, refer to the NTPClient -> Basic example.
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);
Start NTP client:
After connecting to WiFi, the NTPClient is started using the begin() function, which causes the client to sync with the NTP server and get the UTC time.
```
WiFiUDP ntpUDP;
timeClient.begin();
```
Get local time:
getFormattedTime() is used to format the received UTC time into the local time zone.
update() is called every loop so that the NTPClient will sync with the NTP server once every update interval.
```
timeClient.update();
timeClient.getFormattedTime();
```
[ Previous](index.html)
[Next ](../OTA/index.html)
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