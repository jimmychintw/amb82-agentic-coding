HTTP Post MP4 — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [HTTP](index.html)
- HTTP Post MP4
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/HTTP/HTTP Post MP4.rst)
# HTTP Post MP4[](#http-post-mp4)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- PushButton x1
- 220 ohm resistor x1
- MicroSD card x 1
## Example[](#example)
These examples illustrate how to send HTTP Post request of MP4 audio file to a HTTP server.
This guide will be relevant to 2 examples:
- HTTP_Post_MP4_Whisper_Server or HTTP_Post_MP4_Whisper_Server_FASTAPI
- RecordMP4_HTTP_Post_Whisper_Server or RecordMP4_HTTP_Post_Whisper_Server_FASTAPI
The difference between these 2 type of examples is that type 1 is expected to have an MP4 file already saved inside the SD card. Whereas type 2 is not necessary to have a MP4 file inside the SD card.
This is the block diagram for the example flow.
[](../../../../_images/image01130.png)
Note
This server can only be run on Linux OS. Mac OS and Windows have not been supported yet.
For fastapi examples, server setup may require that NVIDIA GPU and drivers.
Set up the HTTP server by locating the python script called `whisper_server_test_2_endpoints.py`, `whisper_server_test_2_endpoints_fastapi.py`, `whisper_llm_server.py` or `whisper_llm_server_fastapi.py` in `libraries/Http/src` folder.
Go to `command prompt/terminal` at `libraries/Http/src` folder. The files are located in the `libraries/Http/src directory` You will need to navigate to this folder before running the Python. Execute following code.
python3 whisper_llm_server.py
# Setup env for running py file
python3 -m venv .venv
source .venv/bin/activate
# Install requirement for test env
sudo apt update && sudo apt install ffmpeg
pip install --upgrade pip
pip install -r requirements.txt
# Chose 1 of the py file to run according to the example
python3 whisper_llm_server.py
# or
python3 whisper_llm_server_fastapi.py
# or
python3 whisper_server_test_2_endpoints.py
# or
python3 whisper_server_test_2_endpoints_fastapi.py
[](../../../../_images/image0488.png)
Press the push button for 2s to trigger the recording. Speak into the microphone to ask the AI. This should be the expected output on the terminal that was running the python script. Please note that if you are to use a more powerful model such as MediaTek 7B model, you will need a PC with a powerful GPU to test. Purely CPU will not be able to run that model.
[](../../../../_images/image0573.png)
Connect the pushbutton and resistor to AMB82 Mini as shown below.
[](../../../../_images/image02125.png)
Open File -> Examples -> AmebaHTTP -> HTTP_Post_MP4_Whisper_Server or RecordMP4_HTTP_Post_Whisper_Server
or Open File -> Examples -> AmebaHTTP -> HTTP_Post_MP4_Whisper_Server_FASTAPI or RecordMP4_HTTP_Post_Whisper_Server_FASTAPI
[](../../../../_images/image03106.png)
Compile and run the code.
[ Previous](HTTP%20Post%20Image%20and%20MP4.html)
[Next ](HTTP%20Upload%20Image.html)
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