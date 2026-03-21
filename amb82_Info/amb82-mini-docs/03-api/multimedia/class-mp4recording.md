Class MP4Recording — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class MP4Recording
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class MP4Recording.rst)
# Class MP4Recording[](#class-mp4recording)
## **MP4Recording Class**[](#mp4recording-class)
### **Description**[](#description)
A class used to record video and audio data streams into a MP4 file on the SD card.
### **Syntax**[](#syntax)
class MP4Recording
### **Members**[](#members)
|**Public Constructors**
|
|
| MP4Recording::MP4Recording
|
Constructs a MP4Recording object
|
|
| **Public Methods**
|
|
| MP4Recording::configVideo
|
Initialize MP4Recording video
stream parameters.
|
|
| MP4Recording::configAudio
|
Initialize MP4Recording audio
stream parameters.
|
|
| MP4Recording::begin
|
Start recording MP4 to SD card.
|
|
| MP4Recording::end
|
Stop recording MP4 to SD card.
|
|
| MP4Recording::setRecordingFileName
|
Set base file name of recorded MP4
files.
|
|
| MP4Recording::setRecordingDuration
|
Set per-file MP4 recording
duration.
|
|
| MP4Recording::setRecordingFileCount
|
Set total number of MP4 files to
record.
|
|
| MP4Recording::setLoopRecording
|
Enable loop recording mode for
continuous recording.
|
|
| MP4Recording::setRecordingDataType
|
Enable recording video data and
audio data.
|
|
| MP4Recording::getRecordingFileName
|
Get currently configured base file
name of recorded MP4 files.
|
|
| MP4Recording::getRecordingDuration
|
Get currently configured per-file
MP4 recording duration.
|
|
| MP4Recording::getRecordingFileCount
|
Get currently configured total
number of MP4 files to record.
|
|
| MP4Recording::getRecordingState
|
Get current MP4 recording state.
|
|
| MP4Recording::printInfo
|
Print current MP4 recording
parameters.
|
|
## **MP4Recording::configVideo**[](#mp4recording-configvideo)
### **Description**[](#id1)
Initialize MP4Recording video stream parameters.
### **Syntax**[](#id2)
void configVideo(VideoSetting& config);
### **Parameters**[](#parameters)
config: VideoSetting class object containing desired video configuration.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::configAudio**[](#mp4recording-configaudio)
### **Description**[](#id3)
Initialize MP4Recording audio stream parameters.
### **Syntax**[](#id4)
void configAudio(AudioSetting& config, Audio_Codec_T codec);
### **Parameters**[](#id5)
config: AudioSetting object containing desired audio configuration.
codec: Codec format of Audio stream input.
- CODEC_AAC
- CODEC_G711_PCMU
- CODEC_G711_PCMA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::begin**[](#mp4recording-begin)
### **Description**[](#id9)
Start MP4 recording to SD card.
### **Syntax**[](#id10)
void begin(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::end**[](#mp4recording-end)
### **Description**[](#id15)
Stop MP4 recording to SD card.
### **Syntax**[](#id16)
void end(void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
NA
### **Example Code**[](#id19)
NA
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::setRecordingFileName**[](#mp4recording-setrecordingfilename)
### **Description**[](#id20)
Set base file name of recorded MP4 files.
### **Syntax**[](#id21)
void setRecordingFileName(const char* filename);
void setRecordingFileName(String filename);
### **Parameters**[](#id22)
filename: Desired recorded MP4 filename, expresses as a character array or String class object.
### **Returns**[](#id23)
NA
### **Example Code**[](#id24)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
Filename can be up to 127 characters long.
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::setRecordingDuration**[](#mp4recording-setrecordingduration)
### **Description**[](#id26)
Set per-file MP4 recording duration.
### **Syntax**[](#id27)
void setRecordingDuration(uint32_t secs);
### **Parameters**[](#id28)
secs: Duration of MP4 to record, expressed in seconds.
### **Returns**[](#id29)
NA
### **Example Code**[](#id30)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::setRecordingFileCount**[](#mp4recording-setrecordingfilecount)
### **Description**[](#id32)
Set total number of MP4 files to record.
### **Syntax**[](#id33)
void setRecordingFileCount(uint32_t count);
### **Parameters**[](#id34)
count: Total number of MP4 files to record to SD card.
### **Returns**[](#id35)
NA
### **Example Code**[](#id36)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
If configured to record more than 1 file, a number will be appended to the end of the base file name.
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::setLoopRecording**[](#mp4recording-setlooprecording)
### **Description**[](#id38)
Enable loop recording mode for continuous recording.
### **Syntax**[](#id39)
void setLoopRecording(int enable);
### **Parameters**[](#id40)
enable: Enable or disable loop recording.
### **Returns**[](#id41)
NA
### **Example Code**[](#id42)
NA
Note
Enabling loop recording will overwrite the oldest previously recorded MP4 file when the total number of MP4 files to record has been reached.
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::setRecordingDataType**[](#mp4recording-setrecordingdatatype)
### **Description**[](#id43)
Enable recording video data and audio data.
### **Syntax**[](#id44)
void setRecordingDataType(uint8_t type);
### **Parameters**[](#id45)
type: one of the following values, default value of STORAGE_ALL.
- STORAGE_ALL – record both video data and audio data.
- STORAGE_VIDEO – record only video data.
- STORAGE_AUDIO – record only audio data.
### **Returns**[](#id46)
NA
### **Example Code**[](#id47)
Example: [RecordMP4/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/VideoOnly/VideoOnly.ino)
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::getRecordingFileName**[](#mp4recording-getrecordingfilename)
### **Description**[](#id48)
Get currently configured base file name of recording MP4 files.
### **Syntax**[](#id49)
String getRecordingFileName(void);
### **Parameters**[](#id50)
NA
### **Returns**[](#id51)
A String class object containing the currently configured MP4 base file name.
### **Example Code**[](#id52)
NA
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::getRecordingDuration**[](#mp4recording-getrecordingduration)
### **Description**[](#id53)
Get currently configured per-file MP4 recording duration.
### **Syntax**[](#id54)
uint32_t getRecordingDuration(void);
### **Parameters**[](#id55)
NA
### **Returns**[](#id56)
Currently configured per-file recording duration, expressed in seconds.
### **Example Code**[](#id57)
NA
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::getRecordingFileCount**[](#mp4recording-getrecordingfilecount)
### **Description**[](#id58)
Get currently configured total number of MP4 files to record.
### **Syntax**[](#id59)
uint32_t getRecordingFileCount(void);
### **Parameters**[](#id60)
NA
### **Returns**[](#id61)
Currently configured total number of MP4 files to record.
### **Example Code**[](#id62)
NA
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::getRecordingState**[](#mp4recording-getrecordingstate)
### **Description**[](#id63)
Get current MP4 recording state.
### **Syntax**[](#id64)
uint8_t getRecordingState(void);
### **Parameters**[](#id65)
NA
### **Returns**[](#id66)
TRUE if MP4 is currently recording, FALSE if MP4 recording has stopped.
### **Example Code**[](#id67)
NA
Note
“MP4Recording.h” must be included to use the class function.
## **MP4Recording::printInfo**[](#mp4recording-printinfo)
### **Description**[](#id68)
Print out current configuration of MP4 recording.
### **Syntax**[](#id69)
void printInfo(void);
### **Parameters**[](#id70)
NA
### **Returns**[](#id71)
NA
### **Example Code**[](#id72)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
“MP4Recording.h” must be included to use the class function.
[ Previous](Class%20MotionDetection.html)
[Next ](Class%20RTP.html)
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