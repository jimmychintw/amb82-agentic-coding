Class RTSP — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class RTSP
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class RTSP.rst)
# Class RTSP[](#class-rtsp)
## **RTSP Class**[](#rtsp-class)
### **Description**[](#description)
A class used to send audio and video data streams over a network using the Real Time Streaming Protocol (RTSP). This allows viewing of a video stream on a computer using media players.
### **Syntax**[](#syntax)
class RTSP
### **Members**[](#members)
|**Public Constructors**
|
|
| [RTSP::RTSP](RTSP::RTSP)
|
Constructs a RTSP object.
|
|
| **Public Methods**
|
|
| [RTSP::configVideo](RTSP::configVideo)
|
Configure RTSP module by setting up RTSP
video parameters.
|
|
| [RTSP::configAudio](RTSP::configAudio)
|
Configure RTSP module by setting up RTSP
audio parameters.
|
|
| [RTSP::begin](RTSP::begin)
|
Start RTSP streaming.
|
|
| [RTSP::end](RTSP::end)
|
Stop RTSP streaming.
|
|
| [RTSP::getPort](RTSP::getPort)
|
Get RTSP port value.
|
|
| RTSP:: printInfo
|
Print out current configuration of RTSP.
|
|
## **RTSP::configVideo**[](#rtsp-configvideo)
### **Description**[](#id1)
Configure RTSP module by setting up RTSP video parameters.
### **Syntax**[](#id2)
void configVideo(VideoSetting& config);
### **Parameters**[](#parameters)
config: VideoSetting object
### **Returns**[](#returns)
NA
### *Example Code**[](#example-code)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“RTSP.h” must be included to use the class function.
## **RTSP::configAudio**[](#rtsp-configaudio)
### **Description**[](#id3)
Configure RTSP module by setting up RTSP audio parameters.
### **Syntax**[](#id4)
void configAudio(AudioSetting& config, Audio_Codec_T codec);
### **Parameters**[](#id5)
config: AudioSetting object containing desired audio configuration
codec: Codec format of Audio stream input. Valid values: CODEC_AAC,
CODEC_G711_PCMU, CODEC_G711_PCMA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [StreamRTSP/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
“RTSP.h” must be included to use the class function.
## **RTSP::begin**[](#rtsp-begin)
### **Description**[](#id8)
Start RTSP streaming.
### **Syntax**[](#id9)
void begin(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“RTSP.h” must be included to use the class function.
## **RTSP::end**[](#rtsp-end)
### **Description**[](#id14)
Stop RTSP streaming.
### **Syntax**[](#id15)
void end(void);
### **Parameters**[](#id16)
NA
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
NA
Note
“RTSP.h” must be included to use the class function.
## **RTSP::getPort**[](#rtsp-getport)
### **Description**[](#id19)
Get RTSP stream network port.
### **Syntax**[](#id20)
int getPort(void);
### **Parameters**[](#id21)
NA
### **Returns**[](#id22)
This function returns the port number as an integer.
### **Example Code**[](#id23)
NA
Note
“RTSP.h” must be included to use the class function.
## **RTSP::printInfo**[](#rtsp-printinfo)
### **Description**[](#id24)
Print out current configuration of RTSP.
### **Syntax**[](#id25)
void printInfo(void);
### **Parameters**[](#id26)
NA
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“RTSP.h” must be included to use the class function.
[ Previous](Class%20RTP.html)
[Next ](Class%20StreamIO.html)
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