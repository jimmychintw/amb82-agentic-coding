HTTP Upload Image — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [HTTP](index.html)
- HTTP Upload Image
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/HTTP/HTTP Upload Image.rst)
# HTTP Upload Image[](#http-upload-image)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- SD card x1
## Example[](#example)
This example illustrates how to upload an image file to a local server via HTTP, a copy of the uploaded image will also be saved to SD card.
Install Docker Desktop.
Download “http-image-server” package from ‘Ameba_misc’ folder.
Unzip “http-image-server” and run “docker compose up –build” command.
Open File -> Examples -> AmebaHTTP -> HttpUploadImage
[](../../../../_images/image01131.png)
Update WiFi credentials and server IP. Kindly use LAN IP of the Docker host.
Compile and run the code.
Once image is uploaded successfully, you may find it in the “upload folder”
The uploaded image files are stored in the /http-image-server/uploads directory. You will need to navigate to this folder to look for the images.
[](../../../../_images/image02126.png)
[ Previous](HTTP%20Post%20MP4.html)
[Next ](HTTP%20Upload%20Image%20Google%20Drive.html)
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