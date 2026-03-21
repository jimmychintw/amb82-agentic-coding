Class ObjectDetection — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [NeuralNetwork](index.html)
- Class ObjectDetection
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/NeuralNetwork/Class ObjectDetection.rst)
# Class ObjectDetection[](#class-objectdetection)
## **ObjectDetectionResult Class**[](#objectdetectionresult-class)
### **Description**[](#description)
A class used to represent and retrieve data related to objects recognized by an object detection neural network.
### **Syntax**[](#syntax)
class ObjectDetectionResult
### **Members**[](#members)
|**Public Constructors**
|
|
| ObjectDetectionResult::
ObjectDetectionResult
|
Constructs an NNImageClassification object
|
|
| **Public Methods**
|
|
| ObjectDetectionResult::type
|
Get type index of recognized object.
|
|
| ObjectDetectionResult::name
|
Get name of recognized object.
|
|
| ObjectDetectionResult::score
|
Get confidence score of recognized object.
|
|
| ObjectDetectionResult::xMin
|
Get x coordinate of the top left corner of the bounding box containing the recognized object.
|
|
| ObjectDetectionResult::xMax
|
Get x coordinate of the bottom right corner of the bounding box containing the recognized object.
|
|
| ObjectDetectionResult::yMin
|
Get y coordinate of the top left corner of the bounding box containing the recognized object.
|
|
| ObjectDetectionResult::yMax
|
Get y coordinate of the bottom right corner of the bounding box containing the recognized object.
|
|
## **ObjectDetectionResult::type**[](#objectdetectionresult-type)
### **Description**[](#id1)
Get type index of recognized object, corresponding to the object category in the COCO image dataset.
### **Syntax**[](#id2)
int type(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
An integer indicating the category of the recognized object.
### **Example Code**[](#example-code)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function. Object categories can be obtained from the “ObjectClassList.h” file.
## **ObjectDetectionResult::name**[](#objectdetectionresult-name)
### **Description**[](#id3)
Get name of recognized object.
### **Syntax**[](#id4)
const char* name(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
A pointer to a character array containing the category name of the recognized object.
### **Example Code**[](#id7)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function. Object categories can be obtained from the “ObjectClassList.h” file.
## **ObjectDetectionResult::score**[](#objectdetectionresult-score)
### **Description**[](#id9)
Get confidence score of recognized object.
### **Syntax**[](#id10)
int score(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
An integer ranging from 0 to 100 representing the confidence of the recognized object category.
### **Example Code**[](#id13)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function.
## **ObjectDetectionResult::xMin**[](#objectdetectionresult-xmin)
### **Description**[](#id15)
Get x coordinate of the top left corner of the bounding box containing the recognized object.
### **Syntax**[](#id16)
float xMin(void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id19)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function. Object categories can be obtained from the “ObjectClassList.h” file.
## **ObjectDetectionResult::xMax**[](#objectdetectionresult-xmax)
### **Description**[](#id21)
Get x coordinate of the bottom right corner of the bounding box containing the recognized object.
### **Syntax**[](#id22)
float xMax(void);
### **Parameters**[](#id23)
NA
### **Returns**[](#id24)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id25)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function. Object categories can be obtained from the “ObjectClassList.h” file.
## **ObjectDetectionResult::yMin**[](#objectdetectionresult-ymin)
### **Description**[](#id27)
Get y coordinate of the top left corner of the bounding box containing the recognized object.
### **Syntax**[](#id28)
float yMin(void);
### **Parameters**[](#id29)
NA
### **Returns**[](#id30)
A float ranging from 0.00 to 1.00, with 0.00 indicating the top edge of the input video frame and 1.00 indicating the bottom edge of the input video frame.
### **Example Code**[](#id31)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function. Object categories can be obtained from the “ObjectClassList.h” file.
## **ObjectDetectionResult::yMax**[](#objectdetectionresult-ymax)
### **Description**[](#id33)
Get y coordinate of the bottom right corner of the bounding box containing the recognized object.
### **Syntax**[](#id34)
float yMax(void);
### **Parameters**[](#id35)
NA
### **Returns**[](#id36)
A float ranging from 0.00 to 1.00, with 0.00 indicating the top edge of the input video frame and 1.00 indicating the bottom edge of the input video frame.
### **Example Code**[](#id37)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function. Object categories can be obtained from the “ObjectClassList.h” file.
## **NNObjectDetection Class**[](#nnobjectdetection-class)
### **Description**[](#id39)
A class used to configure, run, and retrieve results of an object detection neural network model.
### **Syntax**[](#id40)
class NNObjectDetection
### **Members**[](#id41)
|**Public Constructors**
|
|
| NNObjectDetection::NNObjectDetection
|
Constructs an NNObjectDetection object.
|
|
| **Public Methods**
|
|
| NNObjectDetection::configVideo
|
Configure input video stream parameters.
|
|
| NNObjectDetection::configRegionOfInterest
|
Configure object detection region of interest.
|
|
| NNObjectDetection::configThreshold
|
Configure object detection threshold.
|
|
| NNObjectDetection::begin
|
Start object detection process on input video.
|
|
| NNObjectDetection::end
|
Stop object detection process on input video.
|
|
| NNObjectDetection::setResultCallback
|
Set a callback function to receive object detection results.
|
|
| NNObjectDetection::getResultCount
|
Get number of object detection results.
|
|
| NNObjectDetection::getResult
|
Get object detection results.
|
|
## **NNObjectDetection::configVideo**[](#nnobjectdetection-configvideo)
### **Description**[](#id42)
Configure input video stream parameters.
### **Syntax**[](#id43)
void configVideo(VideoSetting& config);
### **Parameters**[](#id44)
config: VideoSetting class object containing desired video configuration.
### **Returns**[](#id45)
NA
### **Example Code**[](#id46)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function. The object detection model requires that the input video stream uses the RGB format, which is only available on video stream channel 3. The input video stream needs to be configured before object detection can begin.
## **NNObjectDetection::configRegionOfInterest**[](#nnobjectdetection-configregionofinterest)
### **Description**[](#id48)
Configure object detection region of interest. Object detection will only be performed on the image frame within the region of interest.
### **Syntax**[](#id49)
void configRegionOfInterest(int xmin, int xmax, int ymin, int ymax);
### **Parameters**[](#id50)
xmin: left boundary of region of interest, expressed in units of pixel.
xmax: right boundary of region of interest, expressed in units of pixel.
ymin: top boundary of region of interest, expressed in units of pixel.
ymax: bottom boundary of region of interest, expressed in units of pixel.
### **Returns**[](#id51)
NA
### **Example Code**[](#id52)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function.
## **NNObjectDetection::configThreshold**[](#nnobjectdetection-configthreshold)
### **Description**[](#id54)
Configure object detection threshold.
### **Syntax**[](#id55)
void configThreshold(float confidence_threshold, float nms_threshold);
### **Parameters**[](#id56)
confidence_threshold: Object detection confidence threshold. Default value is 0.5.
nms_threshold: Non-Maximal Suppression threshold. Default value of 0.3. Affects the selection of appropriate and accurate bounding boxes. A smaller value results in less accurate bounding boxes.
### **Returns**[](#id57)
NA
### **Example Code**[](#id58)
NA
Note
“NNObjectDetection.h” must be included to use the class function.
## **NNObjectDetection::begin**[](#nnobjectdetection-begin)
### **Description**[](#id59)
Start object detection process on input video.
### **Syntax**[](#id60)
void begin(void);
### **Parameters**[](#id61)
NA
### **Returns**[](#id62)
NA
### **Example Code**[](#id63)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function.
## **NNObjectDetection::end**[](#nnobjectdetection-end)
### **Description**[](#id65)
Stop object detection process on input video.
### **Syntax**[](#id66)
void end(void);
### **Parameters**[](#id67)
NA
### **Returns**[](#id68)
NA
### **Example Code**[](#id69)
NA
Note
“NNObjectDetection.h” must be included to use the class function.
## **NNObjectDetection::setResultCallback**[](#nnobjectdetection-setresultcallback)
### **Description**[](#id70)
Set a callback function to receive object detection results.
### **Syntax**[](#id71)
void setResultCallback(void (*od_callback)(std::vector));
### **Parameters**[](#id72)
od_callback: A callback function that accepts a vector of ObjectDetectionResult class objects as argument and returns void.
### **Returns**[](#id73)
NA
### **Example Code**[](#id74)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function. The callback function will be called with the latest results once per iteration.
## **NNObjectDetection::getResultCount**[](#nnobjectdetection-getresultcount)
### **Description**[](#id76)
Get number of object detection results.
### **Syntax**[](#id77)
uint16_t getResultCount(void);
### **Parameters**[](#id78)
NA
### **Returns**[](#id79)
The number of detected objects in the most recent set of results, as an unsigned integer.
### **Example Code**[](#id80)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNObjectDetection.h” must be included to use the class function.
## **NNObjectDetection::getResult**[](#nnobjectdetection-getresult)
### **Description**[](#id82)
Get object detection results.
### **Syntax**[](#id83)
ObjectDetectionResult getResult(uint16_t index);
std::vector getResult(void);
### **Parameters**[](#id84)
index: index of specific object detection result to retrieve
### **Returns**[](#id85)
If no index is specified, the function returns all detected objects contained in a vector of ObjectDetectionResult class objects.
If an index is specified, the function returns the specific detected object contained in a ObjectDetectionResult class object.
### **Example Code**[](#id86)
Example: [ObjectDetectionLoop](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionLoop/ObjectDetectionLoop.ino)
Note
“NNObjectDetection.h” must be included to use the class function.
[ Previous](Class%20NNModelSelection.html)
[Next ](../NTPClient/index.html)
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