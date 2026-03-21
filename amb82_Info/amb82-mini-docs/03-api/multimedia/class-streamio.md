Class StreamIO — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class StreamIO
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class StreamIO.rst)
# Class StreamIO[](#class-streamio)
## **StreamIO Class**[](#streamio-class)
### **Description**[](#description)
A class used to connect streaming data from data stream producers (e.g., video, audio) to data stream consumers (e.g., RTSP, MP4 recording). Can be configured to duplicate a single data stream to multiple consumers, or to combine several data streams into a single consumer.
### **Syntax**[](#syntax)
class StreamIO
### **Members**[](#members)
|**Public Constructors**
|
|
| StreamIO::StreamIO
|
Constructs a StreamIO object
|
|
| **Public Methods**
|
|
| StreamIO::begin
|
Start streaming data from data producer
to data consumer.
|
|
| StreamIO::end
|
Stop streaming data from data producer to
data consumer.
|
|
| StreamIO::pause
|
Pause streaming data from data producer
to data consumer.
|
|
| StreamIO::resume
|
Resume streaming data from data producer
to data consumer.
|
|
| StreamIO::registerInput
|
Register input data stream from a data
producer.
|
|
| StreamIO::registerInput1
|
Register first input data stream from a
data producer.
|
|
| StreamIO::registerInput2
|
Register second input data stream from a
data producer.
|
|
| StreamIO::registerInput3
|
Register third input data stream from a
data producer.
|
|
| StreamIO::registerOutput
|
Register output data stream to a data
consumer.
|
|
| StreamIO::registerOutput1
|
Register first output data stream to a
data consumer.
|
|
| StreamIO::registerOutput2
|
Register second output data stream to a
data consumer.
|
|
| StreamIO::setStackSize
|
Configure memory stack size available to
StreamIO data processing task.
|
|
| StreamIO::setTaskPriority
|
Configure priority of StreamIO data
processing task.
|
|
## **StreamIO::StreamIO**[](#streamio-streamio)
### **Description**[](#id1)
A class used to connect streaming data from data stream producers (e.g., video, audio) to data stream consumers (e.g., RTSP, MP4 recording). Can be configured to duplicate a single data stream to multiple consumers, or to combine several data streams into a single consumer.
### **Syntax**[](#id2)
StreamIO::StreamIO(uint8_t numInput, uint8_t numOutput)
### **Parameters**[](#parameters)
numInput: number of input data streams.
numOutput: number of output data streams.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [StreamRTSP/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
“StreamIO.h” must be included to use the class function.
## **StreamIO::begin**[](#streamio-begin)
### **Description**[](#id3)
Start streaming data from data producer to data consumer.
### **Syntax**[](#id4)
int begin(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
Function returns 0 for success, -1 for fail to start the data streaming task.
### **Example Code**[](#id7)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
This function should only be called after configuration of input and output data streams. “StreamIO.h” must be included to use the class function.
## **StreamIO::end**[](#streamio-end)
### **Description**[](#id8)
Stop streaming data from data producer to data consumer.
### **Syntax**[](#id9)
void end(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
NA
Note
“StreamIO.h” must be included to use the class function.
## **StreamIO::pause**[](#streamio-pause)
### **Description**[](#id13)
Pause streaming data from data producer to data consumer.
### **Syntax**[](#id14)
void pause(void);
### **Parameters**[](#id15)
NA
### **Returns**[](#id16)
NA
### **Example Code**[](#id17)
NA
Note
“StreamIO.h” must be included to use the class function.
## **StreamIO::resume**[](#streamio-resume)
### **Description**[](#id18)
Resume streaming data from data producer to data consumer.
### **Syntax**[](#id19)
void resume(void);
### **Parameters**[](#id20)
NA
### **Returns**[](#id21)
NA
### **Example Code**[](#id22)
NA
Note
“StreamIO.h” must be included to use the class function.
## **StreamIO::registerInput**[](#streamio-registerinput)
### **Description**[](#id23)
Register input data stream from a data producer.
### **Syntax**[](#id24)
void registerInput(const MMFModule& module);
### **Parameters**[](#id25)
module: data stream producer module.
### **Returns**[](#id26)
NA
### **Example Code**[](#id27)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
When used on a multi-input StreamIO class, this has the same effect as calling registerInput1. “StreamIO.h” must be included to use the class function.
## **StreamIO::registerInput1**[](#streamio-registerinput1)
### **Description**[](#id29)
Register first input data stream from a data producer.
### **Syntax**[](#id30)
void registerInput1(const MMFModule& module);
### **Parameters**[](#id31)
module: data stream producer module.
### **Returns**[](#id32)
NA
### **Example Code**[](#id33)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
When used on a single-input StreamIO class, this has the same effect as calling registerInput. “StreamIO.h” must be included to use the class function.
## **StreamIO::registerInput2**[](#streamio-registerinput2)
### **Description**[](#id35)
Register second input data stream from a data producer.
### **Syntax**[](#id36)
void registerInput2(const MMFModule& module);
### **Parameters**[](#id37)
module: data stream producer module.
### **Returns**[](#id38)
NA
### **Example Code**[](#id39)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
When used on a single-input StreamIO class, this has the same effect as calling registerInput. “StreamIO.h” must be included to use the class function.
## **StreamIO::registerInput3**[](#streamio-registerinput3)
### **Description**[](#id41)
Register third input data stream from a data producer.
### **Syntax**[](#id42)
void registerInput3(const MMFModule& module);
### **Parameters**[](#id43)
module: data stream producer module.
### **Returns**[](#id44)
NA
### **Example Code**[](#id45)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
When used on a single-input StreamIO class, this has the same effect as calling registerInput. “StreamIO.h” must be included to use the class function.
## **StreamIO::registerOutput**[](#streamio-registeroutput)
### **Description**[](#id47)
Register output data stream to a data consumer.
### **Syntax**[](#id48)
void registerOutput(const MMFModule& module);
### **Parameters**[](#id49)
module: data stream consumer module.
### **Returns**[](#id50)
NA
### **Example Code**[](#id51)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
When used on a multi-output StreamIO class, this has the same effect as calling registerOutput1. “StreamIO.h” must be included to use the class function.
## **StreamIO::registerOutput1**[](#streamio-registeroutput1)
### **Description**[](#id53)
Register first output data stream to a data consumer.
### **Syntax**[](#id54)
void registerOutput1(const MMFModule& module);
### **Parameters**[](#id55)
module: data stream consumer module.
### **Returns**[](#id56)
NA
### **Example Code**[](#id57)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
When used on a single-output StreamIO class, this has the same effect as calling registerOutput. “StreamIO.h” must be included to use the class function.
## **StreamIO::registerOutput2**[](#streamio-registeroutput2)
### **Description**[](#id59)
Register second output data stream to a data consumer.
### **Syntax**[](#id60)
void registerOutput2(const MMFModule& module);
### **Parameters**[](#id61)
module: data stream consumer module.
### **Returns**[](#id62)
NA
### **Example Code**[](#id63)
Example: [RecordMP4/SingleVideoWithAudio](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/RecordMP4/SingleVideoWithAudio/SingleVideoWithAudio.ino)
Note
When used on a single-output StreamIO class, this has the same effect as calling registerOutput. “StreamIO.h” must be included to use the class function.
## **StreamIO::setStackSize**[](#streamio-setstacksize)
### **Description**[](#id65)
Configure memory stack size available to StreamIO data processing task.
### **Syntax**[](#id66)
void setStackSize(void);
### **Parameters**[](#id67)
NA
### **Returns**[](#id68)
NA
### **Example Code**[](#id69)
NA
Note
“StreamIO.h” must be included to use the class function.
## **StreamIO::setTaskPriority**[](#streamio-settaskpriority)
### **Description**[](#id70)
Configure priority of StreamIO data processing task.
### **Syntax**[](#id71)
void setTaskPriority(void);
### **Parameters**[](#id72)
NA
### **Returns**[](#id73)
NA
### **Example Code**[](#id74)
NA
Note
“StreamIO.h” must be included to use the class function.
[ Previous](Class%20RTSP.html)
[Next ](Class%20VideoStream.html)
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