Class AudioDecoder — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class AudioDecoder
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class AudioDecoder.rst)
# Class AudioDecoder[](#class-audiodecoder)
## **AAD Class**[](#aad-class)
### **Description**[](#description)
A class used to decode an audio data stream using AAC (Advanced Audio Codec) standard.
### **Syntax**[](#syntax)
class AAD
### **Members**[](#members)
|**Public Constructors**
|
|
| AAD::AAD
|
Constructs an AAD object.
|
|
| **Public Methods**
|
|
| AAD::configAudio
|
Configure AAD module by setting up
audio configuration parameters.
|
|
| AAD::begin
|
Start AAD module audio decoder.
|
|
| AAD::end
|
Stop AAD module audio decoder.
|
|
## **AAD::configAudio**[](#aad-configaudio)
### **Description**[](#id1)
Configure AAD module by setting up audio configuration parameters.
### **Syntax**[](#id2)
void configAudio(AudioSetting& config);
### **Parameters**[](#parameters)
config: AudioSetting object containing desired audio configuration.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [Audio/RTPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTPAudioStream/RTPAudioStream.ino)
Note
“AudioDecoder.h” must be included to use the class function.
## **AAD::begin**[](#aad-begin)
### **Description**[](#id3)
Start AAD audio decoder.
### **Syntax**[](#id4)
void begin(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [Audio/RTPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTPAudioStream/RTPAudioStream.ino)
Note
“AudioDecoder.h” must be included to use the class function.
## **AAD::end**[](#aad-end)
### **Description**[](#id9)
Stop AAD audio decoder.
### **Syntax**[](#id10)
void end(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
NA
Note
“AudioDecoder.h” must be included to use the class function.
## **G711D Class**[](#g711d-class)
### **Description**[](#id14)
A class used to decode an audio data stream using ITU-T G.711 standard.
### **Syntax**[](#id15)
class G711D
### **Members**[](#id16)
|**Public Constructors**
|
|
| G711D::G711D
|
Constructs a G711D object.
|
|
| **Public Methods**
|
|
| G711D::configAudio
|
Configure G711D module by setting up
audio configuration parameters.
|
|
| G711D::configCodec
|
Configure G711D module companding
algorithm.
|
|
| G711D::begin
|
Start G711D module audio decoder.
|
|
| G711D::end
|
Stop G711D module audio decoder.
|
|
## **G711D::configAudio**[](#g711d-configaudio)
### **Description**[](#id17)
Configure G711D module by setting up audio configuration parameters.
### **Syntax**[](#id18)
void configAudio(AudioSetting& config);
### **Parameters**[](#id19)
config: AudioSetting object containing desired audio configuration.
### **Returns**[](#id20)
NA
### **Example Code**[](#id21)
Example: [Audio/RTPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTPAudioStream/RTPAudioStream.ino)
Note
“AudioDecoder.h” must be included to use the class function. The G711D audio decoder will only work when the audio sample rate is configured as 8kHz or 16kHz.
## **G711D::configCodec**[](#g711d-configcodec)
### **Description**[](#id23)
Configure G711D module companding algorithm.
### **Syntax**[](#id24)
void configCodec(Audio_Codec_T codec);
### **Parameters**[](#id25)
codec: Codec format of audio stream.
- CODEC_G711_PCMU (Default value)
- CODEC_G711_PCMA
### **Returns**[](#id26)
NA
### **Example Code**[](#id27)
Example: [Audio/RTPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTPAudioStream/RTPAudioStream.ino)
Note
“AudioDecoder.h” must be included to use the class function. The G711D audio decoder will only work when the audio sample rate is configured as 8kHz or 16kHz.
## **G711D::begin**[](#g711d-begin)
### **Description**[](#id29)
Start G711D audio decoder.
### **Syntax**[](#id30)
void begin(void);
### **Parameters**[](#id31)
NA
### **Returns**[](#id32)
NA
### **Example Code**[](#id33)
Example: [Audio/RTPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTPAudioStream/RTPAudioStream.ino)
Note
“AudioDecoder.h” must be included to use the class function.
## **G711D::end**[](#g711d-end)
### **Description**[](#id35)
Stop G711D audio decoder.
### **Syntax**[](#id36)
void end(void);
### **Parameters**[](#id37)
NA
### **Returns**[](#id38)
NA
### **Example Code**[](#id39)
NA
Note
“AudioDecoder.h” must be included to use the class function.
[ Previous](index.html)
[Next ](Class%20AudioEncoder.html)
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