Class MotionDetection — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class MotionDetection
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class MotionDetection.rst)
# Class MotionDetection[](#class-motiondetection)
## **MotionDetectionResult Class**[](#motiondetectionresult-class)
### **Description**[](#description)
A class used to represent and retrieve data related to motion detected.
### **Syntax**[](#syntax)
class MotionDetectionResult
### **Members**[](#members)
|**Public Constructors**
|
|
| MotionDetectionResult::MotionDetectionResult
|
Constructs a MotionDetectionResultobject
|
|
| **Public Methods**
|
|
| MotionDetectionResult::xMin
|
Get x coordinate of the top left corner
of the bounding box containing the
detected motion
|
|
| MotionDetectionResult::xMax
|
Get x coordinate of the bottom right
corner of the bounding box containing
the detected motion
|
|
| MotionDetectionResult::yMin
|
Get y coordinate of the top left corner
of the bounding box containing the
detected motion
|
|
| MotionDetectionResult::yMax
|
Get y coordinate of the bottom right
corner of the bounding box containing
the detected motion
|
|
## **MotionDetectionResult::xMin**[](#motiondetectionresult-xmin)
### **Description**[](#id1)
Get x coordinate of the top left corner of the bounding box containing the detected motion.
### **Syntax**[](#id2)
float xMin(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#example-code)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetectionResult::xMax**[](#motiondetectionresult-xmax)
### **Description**[](#id3)
Get x coordinate of the bottom right corner of the bounding box containing the detected motion.
### **Syntax**[](#id4)
float xMax(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id7)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetectionResult::yMin**[](#motiondetectionresult-ymin)
### **Description**[](#id9)
Get y coordinate of the top left corner of the bounding box containing the detected motion.
### **Syntax**[](#id10)
float yMin(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id13)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetectionResult::yMax**[](#motiondetectionresult-ymax)
### **Description**[](#id15)
Get y coordinate of the bottom right corner of the bounding box containing the detected motion.
### **Syntax**[](#id16)
float yMax(void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id19)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection Class**[](#motiondetection-class)
### **Description**[](#id21)
A class used to retrieve data when motion is detected by comparing the RGB information of each image frame captured from the on-board camera sensor (JX-F37P).
### **Syntax**[](#id22)
class MotionDetection
### **Members**[](#id23)
|**Public Constructors**
|
|
| MotionDetection::MotionDetection
|
Constructs a MotionDetection
object and set motion detection
resolution.
|
|
| **Public Methods**
|
|
| MotionDetection::configResolution
|
Configure motion detection grid
resolution.
|
|
| MotionDetection::configVideo
|
Configure input video stream
parameters.
|
|
| MotionDetection::begin
|
Start motion detection process
on input video.
|
|
| MotionDetection::end
|
Stop motion detection process on
input video.
|
|
| MotionDetection::setTriggerBlockCount
|
Set the number of blocks to
trigger motion detection output.
|
|
| MotionDetection::setDetectionMask
|
Set a specific region in the
video stream to enable motion
detection.
|
|
| MotionDetection::getResult
|
Get motion detection results.
|
|
| MotionDetection::setResultCallback
|
Set a callback function to
receive and display motion
detection results.
|
|
| MotionDetection::getResultCount
|
Get number of motion detection
results
|
|
| MotionDetection::rows
|
Get currently configured number
of rows for motion detection
grid.
|
|
| MotionDetection::cols
|
Get currently configured number
of columns for motion detection
grid.
|
|
## **MotionDetectionResult::MotionDetection**[](#motiondetectionresult-motiondetection)
### **Description**[](#id24)
Constructs a MotionDetection object and configure motion detection resolution.
### **Syntax**[](#id25)
MotionDetection(uint8_t row, uint8_t col);
### **Parameters**[](#id26)
row: Number of rows for motion detection grid resolution.
- 18
- 32
col: Number of columns for motion detection grid resolution.
- 
(Default value)
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::configResolution**[](#motiondetection-configresolution)
### **Description**[](#id30)
Configure motion detection resolution.
### **Syntax**[](#id31)
void configResolution(uint8_t row, uint8_t col);
### **Parameters**[](#id32)
row: Number of rows for motion detection grid resolution.
- 18 (Default value)
- 32
col: Number of columns for motion detection grid resolution.
- 32 (Default value)
### **Returns**[](#id33)
NA
### **Example Code**[](#id34)
NA
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::configVideo**[](#motiondetection-configvideo)
### **Description**[](#id35)
Configure input video stream parameters.
### **Syntax**[](#id36)
void configVideo(VideoSetting& config);
### **Parameters**[](#id37)
config: VideoSetting class object containing desired video configuration.
### **Returns**[](#id38)
NA
### **Example Code**[](#id39)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function. For motion detection, the input video stream uses the RGB format, which is only available on video stream channel 3.
## **MotionDetection::begin**[](#motiondetection-begin)
### **Description**[](#id41)
Start motion detection process on input video.
### **Syntax**[](#id42)
void begin(void);
### **Parameters**[](#id43)
NA
### **Returns**[](#id44)
NA
### **Example Code**[](#id45)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::end**[](#motiondetection-end)
### **Description**[](#id47)
Stop motion detection process on input video.
### **Syntax**[](#id48)
void end(void);
### **Parameters**[](#id49)
NA
### **Returns**[](#id50)
NA
### **Example Code**[](#id51)
NA
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::setTriggerBlockCount**[](#motiondetection-settriggerblockcount)
### **Description**[](#id52)
Set the number of blocks to trigger motion detection output.
### **Syntax**[](#id53)
void setTriggerBlockCount(uint16_t count);
### **Parameters**[](#id54)
count: Threshold number of blocks with motion.
### **Returns**[](#id55)
NA
### **Example Code**[](#id56)
NA
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::setDetectionMask**[](#motiondetection-setdetectionmask)
### **Description**[](#id57)
Set a specific region in the motion detection grid to ignore motion.
### **Syntax**[](#id58)
void setDetectionMask(char * mask);
### **Parameters**[](#id59)
mask: a pointer to a char array containing the regions where motion detection is enabled or disabled.
- 1 (Enable motion detection for the grid region)
- 0 (Disable motion detection for the grid region)
### **Returns**[](#id60)
NA
### **Example Code**[](#id61)
NA
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::getResult**[](#motiondetection-getresult)
### **Description**[](#id62)
Get motion detection results.
### **Syntax**[](#id63)
MotionDetectionResult getResult(uint16_t index);
std::vector<MotionDetectionResult> getResult(void);
### **Parameters**[](#id64)
index: index of specific motion detection result to retrieve.
### **Returns**[](#id65)
If there is no index specified, the function returns all detected motions contained in a vector of MotionDetectionResult class objects.
If there is an index specified, the function returns the specific detected motion contained in a MotionDetectionResult class object.
### **Example Code**[](#id66)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::setResultCallback**[](#motiondetection-setresultcallback)
### **Description**[](#id68)
Set a callback function to receive and display motion detection results.
### **Syntax**[](#id69)
void setResultCallback(void(*md_callback)(std::vector<MotionDetectionResult>));
### **Parameters**[](#id70)
md_callback: A callback function that accepts a vector of MotionDetectionResult class objects as argument and returns void.
### **Returns**[](#id71)
NA
### **Example Code**[](#id72)
Example: [MotionDetection/CallbackPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/CallbackPostProcessing/CallbackPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::getResultCount**[](#motiondetection-getresultcount)
### **Description**[](#id73)
Get number of motion detection results.
### **Syntax**[](#id74)
uint16_t getResultCount(void);
### **Parameters**[](#id75)
NA
### **Returns**[](#id76)
The number of detected motions in the most recent set of results, as an unsigned integer.
### **Example Code**[](#id77)
Example: [MotionDetection/CallbackPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/CallbackPostProcessing/CallbackPostProcessing.ino)
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::rows**[](#motiondetection-rows)
### **Description**[](#id79)
Get currently configured number of rows for motion detection grid.
### **Syntax**[](#id80)
uint8_t rows(void);
### **Parameters**[](#id81)
NA
### **Returns**[](#id82)
The number of rows in the motion detection grid, expressed as an unsigned integer.
### **Example Code**[](#id83)
NA
Note
“MotionDetection.h” must be included to use the class function.
## **MotionDetection::cols**[](#motiondetection-cols)
### **Description**[](#id84)
Get currently configured number of columns for motion detection grid.
### **Syntax**[](#id85)
uint8_t cols(void);
### **Parameters**[](#id86)
NA
### **Returns**[](#id87)
The number of cols in the motion detection grid, expressed as an unsigned integer.
### **Example Code**[](#id88)
NA
Note
“MotionDetection.h” must be included to use the class function.
[ Previous](Class%20Filesaver.html)
[Next ](Class%20MP4Recording.html)
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