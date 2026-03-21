Class Demuxer — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class Demuxer
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class Demuxer.rst)
# Class Demuxer[](#class-demuxer)
## **Demuxer Class**[](#demuxer-class)
### **Description**[](#description)
A class used to handle MP4 file processing and extract audio and video streams from an MP4 file.
### **Syntax**[](#syntax)
class Demuxer
### **Members**[](#members)
|**Public Constructors**
|
|
| Demuxer::Demuxer
|
Constructs a Demuxer object.
|
|
| **Public Methods**
|
|
| Demuxer::begin
|
Begin initializes and starts the demuxer
for processing an MP4 file.
|
|
| Demuxer::pause
|
Pause the RTSP streaming.
|
|
| Demuxer::resume
|
Resume the RTSP streaming.
|
|
| Demuxer::end
|
Stop demuxer.
|
|
## **Demuxer::begin**[](#demuxer-begin)
### **Description**[](#id1)
Begin initializes and starts the demuxer for processing an MP4 file.
### **Syntax**[](#id2)
void begin(const char* MP4FileName, uint32_t loopMode, uint32_t startTime = 0);
### **Parameters**[](#parameters)
MP4FileName: The name of the MP4 file to be processed.
loopMode: Determines whether the file should play in a loop. (Valid value: 0 (No looping) & 1 (looping))
startTime: The starting position (in milliseconds) from which playback begins. (Default: 0ms)
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [DemuxerRTSP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/DemuxerRTSP/DemuxerRTSP.ino)
Note
“Demuxer.h” must be included to use the class function.
## **Demuxer::pause**[](#demuxer-pause)
### **Description**[](#id3)
Pause the RTSP streaming.
### **Syntax**[](#id4)
void pause(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [DemuxerRTSP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/DemuxerRTSP/DemuxerRTSP.ino)
Note
“Demuxer.h” must be included to use the class function.
## **Demuxer::resume**[](#demuxer-resume)
### **Description**[](#id9)
Resume the RTSP streaming.
### **Syntax**[](#id10)
void pause(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [DemuxerRTSP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/DemuxerRTSP/DemuxerRTSP.ino)
Note
“Demuxer.h” must be included to use the class function.
## **Demuxer::end**[](#demuxer-end)
### **Description**[](#id15)
Stop demuxer.
### **Syntax**[](#id16)
void end(void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
NA
### **Example Code**[](#id19)
NA
Note
“RTP.h” must be included to use the class function.
[ Previous](Class%20AudioStream.html)
[Next ](Class%20Filesaver.html)
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