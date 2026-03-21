HTTP File Server and MP4 — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [HTTP](index.html)
- HTTP File Server and MP4
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/HTTP/HTTP File Server and MP4.rst)
# HTTP File Server and MP4[](#http-file-server-and-mp4)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- MicroSD card x1
## Example[](#example)
In this example, we will use AmebaPro2 development board to establish a file server for mp4 recordings access.
Open File -> Examples -> AmebaHttp -> Http_fs_mp4
[](../../../../_images/image01128.png)
In the highlighted section, kindly modify it according to your WiFi SSID and password.
[](../../../../_images/image02123.png)
You may also change the mp4 recording duration (in seconds) and filecount. Please do not change the filename (“folder”/”file”).
[](../../../../_images/image03104.png)
Then, compile and upload the code to AMB82 Mini.
Note
Kindly insert SD card before pressing the reset button
Open the serial monitor to view the logs. Please copy down the IP address and paste it on a web browser to view the file server page created.
[](../../../../_images/image0487.png)
You may follow the instruction shown to download the mp4 recordings from AMB82 Mini over HTTP.
Note
Kindly refresh the page to view the latest update on the file server
[ Previous](index.html)
[Next ](HTTP%20Post%20Image%20and%20MP4.html)
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