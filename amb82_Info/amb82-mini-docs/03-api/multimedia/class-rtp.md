Class RTP — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class RTP
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class RTP.rst)
# Class RTP[](#class-rtp)
## **RTP Class**[](#rtp-class)
### **Description**[](#description)
A class used to receive an audio data stream over a network using the Real-time Transport Protocol (RTP). This allows streaming of an audio stream from a computer to the development board.
### **Syntax**[](#syntax)
class RTP
### **Members**[](#members)
|**Public Constructors**
|
|
| RTP::RTP
|
Constructs a RTP object.
|
|
| **Public Methods**
|
|
| RTP::configPort
|
Configure RTP network port.
|
|
| RTP::begin
|
Start RTP streaming.
|
|
| RTP::end
|
Stop RTP streaming.
|
|
| RTP::getPort
|
Get RTP network port value.
|
|
## **RTP::configPort**[](#rtp-configport)
### **Description**[](#id1)
Configure RTP network port.
### **Syntax**[](#id2)
void configPort(uint16_t port);
### **Parameters**[](#parameters)
port: Desired network port for RTP.
- 5004 (Default value)
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
NA
Note
“RTP.h” must be included to use the class function.
## **RTP::begin**[](#rtp-begin)
### **Description**[](#id3)
Start RTP streaming.
### **Syntax**[](#id4)
void begin(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [Audio/RTPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTPAudioStream/RTPAudioStream.ino)
Note
“RTP.h” must be included to use the class function.
## **RTP::end**[](#rtp-end)
### **Description**[](#id8)
Stop RTP streaming.
### **Syntax**[](#id9)
void end(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
NA
Note
“RTP.h” must be included to use the class function.
## **RTP::getPort**[](#rtp-getport)
### **Description**[](#id13)
Get RTP stream network port.
### **Syntax**[](#id14)
int getPort(void);
### **Parameters**[](#id15)
NA
### **Returns**[](#id16)
This function returns the port number as an integer.
### **Example Code**[](#id17)
NA
Note
“RTP.h” must be included to use the class function.
[ Previous](Class%20MP4Recording.html)
[Next ](Class%20RTSP.html)
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