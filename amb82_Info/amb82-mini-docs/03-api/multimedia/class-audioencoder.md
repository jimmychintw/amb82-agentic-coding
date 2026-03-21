Class AudioEncoder — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class AudioEncoder
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class AudioEncoder.rst)
# Class AudioEncoder[](#class-audioencoder)
## **AAC Class**[](#aac-class)
### **Description**[](#description)
A class used to encode an audio data stream using AAC (Advanced Audio Codec) standard.
### **Syntax**[](#syntax)
class AAC
### **Members**[](#members)
|**Public Constructors**
|
|
| AAC::AAC
|
Constructs an AAC object.
|
|
| **Public Methods**
|
|
| AAC::configAudio
|
Configure AAC module by setting up
audio configuration parameters.
|
|
| AAC::begin
|
Start AAC module audio encoder.
|
|
| AAC::end
|
Stop AAC module audio encoder.
|
|
## **AAC::configAudio**[](#aac-configaudio)
### **Description**[](#id1)
Configure AAC module by setting up audio configuration parameters.
### **Syntax**[](#id2)
void configAudio(AudioSetting& config);
### **Parameters**[](#parameters)
config: AudioSetting object containing desired audio configuration.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [Audio/RTSPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTSPAudioStream/RTSPAudioStream.ino)
Note
“AudioEncoder.h” must be included to use the class function.
## **AAC::begin**[](#aac-begin)
### **Description**[](#id3)
Start AAC audio encoder.
### **Syntax**[](#id4)
void begin(void);
### **Parameters**[](#id5)
config: AudioSetting object containing desired audio configuration.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [Audio/RTSPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTSPAudioStream/RTSPAudioStream.ino)
Note
“AudioEncoder.h” must be included to use the class function.
## **AAC::end**[](#aac-end)
### **Description**[](#id9)
Stop AAC audio encoder.
### **Syntax**[](#id10)
void end(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
NA
Note
“AudioEncoder.h” must be included to use the class function.
## **G711E Class**[](#g711e-class)
### **Description**[](#id14)
A class used to encode an audio data stream using ITU-T G.711 standard.
### **Syntax**[](#id15)
class G711E
### **Members**[](#id16)
|**Public Constructors**
|
|
| G711E::G711E
|
Constructs a G711E object.
|
|
| **Public Methods**
|
|
| G711E::configAudio
|
Configure G711E module by setting up
audio configuration parameters.
|
|
| G711E::configCodec
|
Configure G711E module companding
algorithm.
|
|
| G711E::begin
|
Start G711E module audio encoder.
|
|
| G711E::end
|
Stop G711E module audio encoder.
|
|
## **G711E::configAudio**[](#g711e-configaudio)
### **Description**[](#id17)
Configure G711E module by setting up audio configuration parameters.
### **Syntax**[](#id18)
void configAudio(AudioSetting& config);
### **Parameters**[](#id19)
config: AudioSetting object containing desired audio configuration.
### **Returns**[](#id20)
NA
### **Example Code**[](#id21)
Example: [Audio/RTPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTPAudioStream/RTPAudioStream.ino)
Note
“AudioEncoder.h” must be included to use the class function. The G711E audio encoder will only work when the audio sample rate is configured as 8kHz or 16kHz.
## **G711E::configCodec**[](#g711e-configcodec)
### **Description**[](#id22)
Configure G711E module companding algorithm.
### **Syntax**[](#id23)
void configCodec(Audio_Codec_T codec);
### **Parameters**[](#id24)
codec: Codec format of audio stream.
- CODEC_G711_PCMU (Default value)
- CODEC_G711_PCMA
### **Returns**[](#id25)
NA
### **Example Code**[](#id26)
Example: [Audio/RTPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTPAudioStream/RTPAudioStream.ino)
Note
“AudioEncoder.h” must be included to use the class function. The G711E audio encoder will only work when the audio sample rate is configured as 8kHz or 16kHz.
## **G711E::begin**[](#g711e-begin)
### **Description**[](#id28)
Start G711E audio encoder.
### **Syntax**[](#id29)
void begin(void);
### **Parameters**[](#id30)
NA
### **Returns**[](#id31)
NA
### **Example Code**[](#id32)
Example: [Audio/RTPAudioStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/RTPAudioStream/RTPAudioStream.ino)
Note
“AudioEncoder.h” must be included to use the class function.
## **G711E::end**[](#g711e-end)
### **Description**[](#id34)
Stop G711E audio encoder.
### **Syntax**[](#id35)
void end(void);
### **Parameters**[](#id36)
NA
### **Returns**[](#id37)
NA
### **Example Code**[](#id38)
NA
Note
“AudioEncoder.h” must be included to use the class function.
[ Previous](Class%20AudioDecoder.html)
[Next ](Class%20AudioStream.html)
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