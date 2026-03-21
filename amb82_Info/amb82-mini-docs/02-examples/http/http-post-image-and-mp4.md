HTTP Post Image and MP4 — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [HTTP](index.html)
- HTTP Post Image and MP4
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/HTTP/HTTP Post Image and MP4.rst)
# HTTP Post Image and MP4[](#http-post-image-and-mp4)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- PushButton x 1
- 220 ohm resistor x 1
- MicroSD card x 1
## Example[](#example)
In this example, we are doing a Post request with image and recorded audio file together to LLM Server. This example does not contain integration to the LLM server but integration to the HTTP server.
Note
This server can only be run on Linux OS. Mac OS and Windows have not been supported yet.
For fastapi examples, server setup may require that NVIDIA GPU and drivers.
Set up the HTTP server by locating the python script called `whisper_server_test_2_endpoints.py` or `whisper_server_test_2_endpoints_fastapi.py`
Go to `command prompt/terminal` at `libraries/Http/src` folder. The files are located in the `libraries/Http/src directory` You will need to navigate to this folder before running the Python. Execute following code.
# Setup env for running py file
python3 -m venv .venv
source .venv/bin/activate
# Install requirement for test env
sudo apt update && sudo apt install ffmpeg
pip install --upgrade pip
pip install -r requirements.txt
# Chose 1 of the py file to run according to the example
python3 whisper_server_test_2_endpoints.py
# or
python3 whisper_server_test_2_endpoints_fastapi.py
[](../../../../_images/image03105.png)
After server is running successfully, incert the MicroSD card to Ameba board.
Open File -> Examples -> AmebaHttp -> Capture_Image_HTTP_Post_Image_Llava_Server
or File -> Examples -> AmebaHttp -> Capture_Image_HTTP_Post_Image_Llava_Server_FASTAPI
[](../../../../_images/image01129.png)
Connect the pushbutton and resistor to AMB82 Mini as shown below.
[](../../../../_images/image02124.png)
Compile and run the example.
Press button for 2s when you wish to take a snapshot and speak into the mic for the prompt to ask the Visual Language Model (VLM).
If the HTTP Post image and audio file is successful, the image and audio file will be saved at the location where this script is being run at.
[ Previous](HTTP%20File%20Server%20and%20MP4.html)
[Next ](HTTP%20Post%20MP4.html)
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