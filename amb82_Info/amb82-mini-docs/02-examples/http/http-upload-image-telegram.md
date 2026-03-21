HTTP Upload Image Telegram — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [HTTP](index.html)
- HTTP Upload Image Telegram
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/HTTP/HTTP Upload Image Telegram.rst)
# HTTP Upload Image Telegram[](#http-upload-image-telegram)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- SD card x1
## Example[](#example)
This example illustrates how to upload an image file to A Telegram bot.
Open Telegram, search for @BotFather, send /newbot, then follow the instructions to create a bot.
Upon successful bot generation, you will receive a bot token.
Send your bot any message, then open “[https://api.telegram.org/botYOUR_TOKEN/getUpdates](https://api.telegram.org/botYOUR_TOKEN/getUpdates)”, replace YOUR_TOKEN with received bot token.
In the JSON, please look for your chat ID. For example,
"chat": { "id": 987654321 }
987654321 is your chat ID.
Open File -> Examples -> AmebaHTTP -> HttpUploadImageTelegram
[](../../../../_images/image01133.png)
Update WiFi credentials, bot token and chat ID.
[](../../../../_images/image02128.png)
Compile and run the code.
Once image is uploaded successfully, you may see it on your Telegram bot.
[ Previous](HTTP%20Upload%20Image%20Google%20Drive.html)
[Next ](Retrieve%20HTTP%20webs.html)
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