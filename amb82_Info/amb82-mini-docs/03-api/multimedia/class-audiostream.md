Class AudioStream — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class AudioStream
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class AudioStream.rst)
# Class AudioStream[](#class-audiostream)
## **AudioSetting Class**[](#audiosetting-class)
### **Description**[](#description)
A class used to contain audio configuration parameters for the audio codec.
### **Syntax**[](#syntax)
class AudioSetting
### **Members**[](#members)
|**Public Constructors**
|
|
|
| AudioSetting::AudioSetting
|
Constructs an AudioSetting object.
|
|
## **Audio Class**[](#audio-class)
### **Description**[](#id1)
A class used to configure and initialize the on-board Audio Codec to generate an audio data stream.
### **Syntax**[](#id2)
class Audio
### **Members**[](#id3)
|**Public Constructors**
|
|
| Audio::Audio
|
Constructs an Audio object.
|
|
| **Public Methods**
|
|
| Audio::configAudio
|
Configure audio module by setting up
audio parameters.
|
|
| Audio::configMicAEC
|
Configure Acoustic Echo Cancellation
algorithm for microphone audio input.
|
|
| Audio::configMicAGC
|
Configure Automatic Gain Control
algorithm for microphone audio input.
|
|
| Audio::configMicNS
|
Configure Noise Suppression algorithm
for microphone audio input.
|
|
| Audio::configSpkAGC
|
Configure Automatic Gain Control
algorithm for speaker audio output.
|
|
| Audio::configSpkNS
|
Configure Noise Suppression algorithm
for speaker audio output.
|
|
| Audio::begin
|
Start audio data streaming.
|
|
| Audio::end
|
Stop audio data streaming.
|
|
| Audio::setAMicBoost
|
Adjust input sensitivity boost for
analog mic.
|
|
| Audio::setDMicBoost
|
Adjust input sensitivity boost for
digital mic.
|
|
| Audio::setMicGain
|
Adjust microphone input volume.
|
|
| Audio::setSpkGain
|
Adjust speaker output volume.
|
|
| Audio::muteMic
|
Mute microphone input.
|
|
| Audio::muteSpk
|
Mute speaker output.
|
|
| Audio::printInfo
|
Print out current configuration of
audio channels.
|
|
| Audio::micLevel
|
Get mic input audio level.
|
|
| Audio::setHPFc
|
Set HPF cutoff frequency.
|
|
## **Audio::configAudio**[](#audio-configaudio)
### **Description**[](#id4)
Initialize audio stream settings for the audio codec.
### **Syntax**[](#id5)
void configAudio(AudioSetting& config);
### **Parameters**[](#parameters)
config: AudioSetting object containing desired audio configuration.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [Audio/LoopbackTest](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/LoopbackTest/LoopbackTest.ino)
Note
“AudioStream.h” must be included to use the class function.
## **Audio::configMicAEC**[](#audio-configmicaec)
### **Description**[](#id6)
Configure Acoustic Echo Cancellation algorithm for microphone audio input.
### **Syntax**[](#id7)
void configMicAEC(uint8_t enable, uint8_t level);
### **Parameters**[](#id8)
enable: Enable or disable Acoustic Echo Cancellation algorithm.
level: Strength of echo cancellation effect.
- 0 to 17 (Default value is 5)
### **Returns**[](#id9)
NA
### **Example Code**[](#id10)
Example: [Audio/EchoCancellation](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/EchoCancellation/EchoCancellation.ino)
Note
“AudioStream.h” must be included to use the class function. The algorithm will only work when the audio sample rate is configured as 8kHz or 16kHz. The Acoustic Echo Cancellation algorithm is intended to prevent the microphone audio input from picking up sounds produced by the speaker audio output.
## **Audio::configMicAEC**[](#id11)
### **Description**[](#id12)
Configure Automatic Gain Control algorithm for microphone audio input.
### **Syntax**[](#id13)
void configMicAGC(uint8_t enable, uint8_t dBFS);
### **Parameters**[](#id14)
enable: Enable or disable Automatic Gain Control algorithm.
level: Target reference level of gain control algorithm.
- 0 to 30 (Corresponding to 0 dBFS to -30 dBFS. Default value is 6)
### **Returns**[](#id15)
NA
### **Example Code**[](#id16)
Example: [Audio/AudioEffect](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/AudioEffect/AudioEffect.ino)
Note
“AudioStream.h” must be included to use the class function. The algorithm will only work when the audio sample rate is configured as 8kHz or 16kHz.
## **Audio::configMicNS**[](#audio-configmicns)
### **Description**[](#id17)
Configure Noise Suppression algorithm for microphone audio input.
### **Syntax**[](#id18)
void configMicNS(uint8_t enable, uint8_t level);
### **Parameters**[](#id19)
enable: Enable or disable Noise Suppression algorithm.
level: Strength of Noise Suppression effect.
- 0 to 12 (Default value is 12)
### **Returns**[](#id20)
NA
### **Example Code**[](#id21)
Example: [Audio/AudioEffect](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/AudioEffect/AudioEffect.ino)
Note
“AudioStream.h” must be included to use the class function. The algorithm will only work when the audio sample rate is configured as 8kHz or 16kHz.
## **Audio::configSpkAGC**[](#audio-configspkagc)
### **Description**[](#id23)
Configure Acoustic Echo Cancellation algorithm for speaker audio output.
### **Syntax**[](#id24)
void configMicAGC(uint8_t enable, uint8_t dBFS);
### **Parameters**[](#id25)
enable: Enable or disable Automatic Gain Control algorithm.
level: Target reference level of gain control algorithm.
- 0 to 30 (Corresponding to 0 dBFS to -30 dBFS. Default value is 6)
### **Returns**[](#id26)
NA
### **Example Code**[](#id27)
Example: [Audio/AudioEffect](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/AudioEffect/AudioEffect.ino)
Note
“AudioStream.h” must be included to use the class function. The algorithm will only work when the audio sample rate is configured as 8kHz or 16kHz.
## **Audio::configSpkNS**[](#audio-configspkns)
### **Description**[](#id29)
Configure Noise Suppression algorithm for speaker audio output.
### **Syntax**[](#id30)
void configMicNS(uint8_t enable, uint8_t level);
### **Parameters**[](#id31)
enable: Enable or disable Noise Suppression algorithm.
level: Strength of Noise Suppression effect.
- 0 to 12 (Default value is 12)
### **Returns**[](#id32)
NA
### **Example Code**[](#id33)
Example: [Audio/AudioEffect](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/AudioEffect/AudioEffect.ino)
Note
“AudioStream.h” must be included to use the class function. The algorithm will only work when the audio sample rate is configured as 8kHz or 16kHz.
## **Audio::begin**[](#audio-begin)
### **Description**[](#id35)
Start audio data streaming.
### **Syntax**[](#id36)
void begin(void);
### **Parameters**[](#id37)
NA
### **Returns**[](#id38)
NA
### **Example Code**[](#id39)
Example: [Audio/LoopbackTest](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/LoopbackTest/LoopbackTest.ino)
Note
“AudioStream.h” must be included to use the class function.
## **Audio::end**[](#audio-end)
### **Description**[](#id41)
Stop audio data streaming.
### **Syntax**[](#id42)
void end(void);
### **Parameters**[](#id43)
NA
### **Returns**[](#id44)
NA
### **Example Code**[](#id45)
NA
Note
“AudioStream.h” must be included to use the class function.
## **Audio::setAMicBoost**[](#audio-setamicboost)
### **Description**[](#id46)
Adjust input sensitivity boost for analog mic.
### **Syntax**[](#id47)
void setAMicBoost(uint8_t amicBoost);
### **Parameters**[](#id48)
amicBoost: Sensitivity boost for analog mic input.
- 0 to 3 (Corresponding to sensitivity boosts of 0 dB, 20 dB, 30 dB, 40 dB. Default value is 0)
### **Returns**[](#id49)
NA
### **Example Code**[](#id50)
Example: [Audio/AudioEffect](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/AudioEffect/AudioEffect.ino)
Note
“AudioStream.h” must be included to use the class function.
## **Audio::setDMicBoost**[](#audio-setdmicboost)
### **Description**[](#id52)
Adjust input sensitivity boost for digital mic.
### **Syntax**[](#id53)
void setDMicBoost(uint8_t dmicBoost);
### **Parameters**[](#id54)
dmicBoost: Sensitivity boost for analog mic input.
- 0 to 3 (Corresponding to sensitivity boosts of 0 dB, 12 dB, 24 dB, 36 dB. Default value is 0)
### **Returns**[](#id55)
NA
### **Example Code**[](#id56)
Example: [Audio/AudioEffect](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/AudioEffect/AudioEffect.ino)
Note
“AudioStream.h” must be included to use the class function.
## **Audio::setMicGain**[](#audio-setmicgain)
### **Description**[](#id58)
Adjust microphone input volume.
### **Syntax**[](#id59)
void setMicGain(uint8_t gain);
### **Parameters**[](#id60)
gain: Volume level of microphone input.
- 0 to 100
### **Returns**[](#id61)
NA
### **Example Code**[](#id62)
Example: [Audio/AudioVolumeAdjust](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/AudioVolumeAdjust/AudioVolumeAdjust.ino)
Note
“AudioStream.h” must be included to use the class function.
## **Audio::setSpkGain**[](#audio-setspkgain)
### **Description**[](#id63)
Adjust speaker output volume.
### **Syntax**[](#id64)
void setSpkGain(uint8_t gain);
### **Parameters**[](#id65)
gain: Volume level of speaker output.
- 0 to 100
### **Returns**[](#id66)
NA
### **Example Code**[](#id67)
Example: [Audio/AudioVolumeAdjust](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/AudioVolumeAdjust/AudioVolumeAdjust.ino)
Note
“AudioStream.h” must be included to use the class function.
## **Audio::muteMic**[](#audio-mutemic)
### **Description**[](#id69)
Mute microphone input.
### **Syntax**[](#id70)
void muteMic(uint8_t mute);
### **Parameters**[](#id71)
mute: Mute or unmute microphone input.
### **Returns**[](#id72)
NA
### **Example Code**[](#id73)
NA
Note
“AudioStream.h” must be included to use the class function.
## **Audio::muteSpk**[](#audio-mutespk)
### **Description**[](#id74)
Mute speaker output.
### **Syntax**[](#id75)
void muteSpk(uint8_t mute);
### **Parameters**[](#id76)
mute: Mute or unmute speaker output.
### **Returns**[](#id77)
NA
### **Example Code**[](#id78)
NA
Note
“AudioStream.h” must be included to use the class function.
## **Audio::printInfo**[](#audio-printinfo)
### **Description**[](#id79)
Print out current configuration of audio channel.
### **Syntax**[](#id80)
void printInfo(void);
### **Parameters**[](#id81)
NA
### **Returns**[](#id82)
NA
### **Example Code**[](#id83)
Example: [StreamRTSP/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
“AudioStream.h” must be included to use the class function.
## **Audio::micLevel**[](#audio-miclevel)
### **Description**[](#id84)
To detect microphone input audio level.
### **Syntax**[](#id85)
int micLevel();
### **Parameters**[](#id86)
NA
### **Returns**[](#id87)
Audio input level detected on microphone.
### **Example Code**[](#id88)
Example: [AudioTriggerRecording](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/Audio/AudioTriggerRecording/AudioTriggerRecording.ino)
Note
“AudioStream.h” must be included to use the class function.
## **Audio::setHPFc**[](#audio-sethpfc)
### **Description**[](#id89)
To set high pass filter value to lower background noise.
### **Syntax**[](#id90)
void setHPFc(uint8_t fc);
### **Parameters**[](#id91)
fc: 0 to 7, cutoff freq ~= 5e-3 / (fc + 1) * fs
### **Returns**[](#id92)
NA
### **Example Code**[](#id93)
NA
Note
“AudioStream.h” must be included to use the class function.
[ Previous](Class%20AudioEncoder.html)
[Next ](Class%20Demuxer.html)
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