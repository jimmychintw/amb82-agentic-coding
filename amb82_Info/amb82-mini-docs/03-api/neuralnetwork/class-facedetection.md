Class FaceDetection — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [NeuralNetwork](index.html)
- Class FaceDetection
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/NeuralNetwork/Class FaceDetection.rst)
# Class FaceDetection[](#class-facedetection)
## **FaceDetectionResult Class**[](#facedetectionresult-class)
### **Description**[](#description)
A class used to represent and retrieve data related to faces detected by a face detection neural network.
### **Syntax**[](#syntax)
class FaceDetectionResult
### **Members**[](#members)
|**Public Constructors**
|
|
| FaceDetectionResult::
FaceDetectionResult
|
Constructs a FaceDetectionResult object.
|
|
| **Public Methods**
|
|
| FaceDetectionResult::name
|
Get name of detected result.
|
|
| FaceDetectionResult::score
|
Get confidence score of detected face.
|
|
| FaceDetectionResult::xMin
|
Get x coordinate of the top left corner of the bounding box containing the detected face.
|
|
| FaceDetectionResult::xMax
|
Get x coordinate of the bottom right corner of the bounding box containing the detected face.
|
|
| FaceDetectionResult::yMin
|
Get y coordinate of the top left corner of the bounding box containing the detected face.
|
|
| FaceDetectionResult::yMax
|
Get y coordinate of the bottom right corner of the bounding box containing the detected face.
|
|
| FaceDetectionResult::xFeature
|
Get x coordinate of a feature point on the detected face.
|
|
| FaceDetectionResult::yFeature
|
Get y coordinate of a feature point on the detected face.
|
|
## **FaceDetectionResult::name**[](#facedetectionresult-name)
### **Description**[](#id1)
Get name of detected result.
### **Syntax**[](#id2)
const char* name(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
A pointer to a character array containing the category name. For face detection, the category name is “Face”.
### **Example Code**[](#example-code)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **FaceDetectionResult::score**[](#facedetectionresult-score)
### **Description**[](#id3)
Get confidence score of detected face.
### **Syntax**[](#id4)
int score(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
An integer ranging from 0 to 100 representing the confidence of the detected face.
### **Example Code**[](#id7)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **FaceDetectionResult::xMin**[](#facedetectionresult-xmin)
### **Description**[](#id9)
Get x coordinate of the top left corner of the bounding box containing the detected face.
### **Syntax**[](#id10)
float xMin(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id13)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **FaceDetectionResult::xMax**[](#facedetectionresult-xmax)
### **Description**[](#id15)
Get x coordinate of the bottom right corner of the bounding box containing the detected face.
### **Syntax**[](#id16)
float xMax(void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id19)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **FaceDetectionResult::yMin**[](#facedetectionresult-ymin)
### **Description**[](#id21)
Get y coordinate of the top left corner of the bounding box containing the detected face.
### **Syntax**[](#id22)
float yMin(void);
### **Parameters**[](#id23)
NA
### **Returns**[](#id24)
A float ranging from 0.00 to 1.00, with 0.00 indicating the top edge of the input video frame and 1.00 indicating the bottom edge of the input video frame.
### **Example Code**[](#id25)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **FaceDetectionResult::yMax**[](#facedetectionresult-ymax)
### **Description**[](#id27)
Get y coordinate of the bottom right corner of the bounding box containing the detected face.
### **Syntax**[](#id28)
float yMax(void);
### **Parameters**[](#id29)
NA
### **Returns**[](#id30)
A float ranging from 0.00 to 1.00, with 0.00 indicating the top edge of the input video frame and 1.00 indicating the bottom edge of the input video frame.
### **Example Code**[](#id31)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **FaceDetectionResult::xFeature**[](#facedetectionresult-xfeature)
### **Description**[](#id33)
Get x coordinate of a feature point on the detected face.
### **Syntax**[](#id34)
float xFeature(uint8_t index);
### **Parameters**[](#id35)
index: index number of face feature point
- 0 (right eye)
- 1 (left eye)
- 2 (nose)
- 3 (right mouth corner)
- 4 (left mouth corner)
### **Returns**[](#id36)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id37)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **FaceDetectionResult::yFeature**[](#facedetectionresult-yfeature)
### **Description**[](#id39)
Get y coordinate of a feature point on the detected face.
### **Syntax**[](#id40)
float yFeature(uint8_t index);
### **Parameters**[](#id41)
index: index number of face feature point.
- 0 (right eye)
- 1 (left eye)
- 2 (nose)
- 3 (right mouth corner)
- 4 (left mouth corner)
### **Returns**[](#id42)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id43)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **NNFaceDetection Class**[](#nnfacedetection-class)
### **Description**[](#id45)
A class used to configure, run, and retrieve results of a face detection neural network model.
### **Syntax**[](#id46)
class NNFaceDetection
### **Members**[](#id47)
|**Public Constructors**
|
|
| NNFaceDetection::NNFaceDetection
|
Constructs an NNFaceDetection object.
|
|
| **Public Methods**
|
|
| NNFaceDetection::configVideo
|
Configure input video stream parameters.
|
|
| NNFaceDetection::configFaceRecogCascadedMode
|
Configure for running face recognition after face detection.
|
|
| NNFaceDetection::begin
|
Start face detection process on input video.
|
|
| NNFaceDetection::end
|
Stop face detection process on input video.
|
|
| NNFaceDetection::setResultCallback
|
Set a callback function to receive face detection results.
|
|
| NNFaceDetection::getResultCount
|
Get number of face detection results.
|
|
| NNFaceDetection::getResult
|
Get face detection results.
|
|
## **NNFaceDetection::configVideo**[](#nnfacedetection-configvideo)
### **Description**[](#id48)
Configure input video stream parameters.
### **Syntax**[](#id49)
void configVideo(VideoSetting& config);
### **Parameters**[](#id50)
config: VideoSetting class object containing desired video configuration.
### **Returns**[](#id51)
NA
### **Example Code**[](#id52)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **NNFaceDetection::configFaceRecogCascadedMode**[](#nnfacedetection-configfacerecogcascadedmode)
### **Description**[](#id54)
Configure for running face recognition after face detection.
### **Syntax**[](#id55)
void configFaceRecogCascadedMode(uint8_t enable);
### **Parameters**[](#id56)
enable: 1 to enable configuration for running face recognition NN model after face detection.
### **Returns**[](#id57)
NA
### **Example Code**[](#id58)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **NNFaceDetection::begin**[](#nnfacedetection-begin)
### **Description**[](#id59)
Start face detection process on input video.
### **Syntax**[](#id60)
void begin(void);
### **Parameters**[](#id61)
NA
### **Returns**[](#id62)
NA
### **Example Code**[](#id63)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **NNFaceDetection::end**[](#nnfacedetection-end)
### **Description**[](#id65)
Stop face detection process on input video.
### **Syntax**[](#id66)
void end(void);
### **Parameters**[](#id67)
NA
### **Returns**[](#id68)
NA
### **Example Code**[](#id69)
NA
Note
“NNFaceDetection.h” must be included to use the class function.
## **NNFaceDetection::setResultCallback**[](#nnfacedetection-setresultcallback)
### **Description**[](#id70)
Set a callback function to receive face detection results.
### **Syntax**[](#id71)
void setResultCallback(void (*fd_callback)(std::vector));
### **Parameters**[](#id72)
fd_callback: A callback function that accepts a vector of FaceDetectionResultclass objects as argument and returns void.
### **Returns**[](#id73)
NA
### **Example Code**[](#id74)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **NNFaceDetection::getResultCount**[](#nnfacedetection-getresultcount)
### **Description**[](#id76)
Get number of face detection results.
### **Syntax**[](#id77)
uint16_t getResultCount(void);
### **Parameters**[](#id78)
NA
### **Returns**[](#id79)
The number of detected faces in the most recent set of results, as an unsigned integer.
### **Example Code**[](#id80)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
## **NNFaceDetection::getResult**[](#nnfacedetection-getresult)
### **Description**[](#id82)
Get face detection results.
### **Syntax**[](#id83)
FaceDetectionResult getResult(uint16_t index);
std::vector getResult(void);
### **Parameters**[](#id84)
index: index of specific face detection result to retrieve.
### **Returns**[](#id85)
If no index is specified, the function returns all detected faces contained in a vector of FaceDetectionResult class objects.
If an index is specified, the function returns the specific detected face contained in a FaceDetectionResult class object.
### **Example Code**[](#id86)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“NNFaceDetection.h” must be included to use the class function.
[ Previous](Class%20Audio%20Classification.html)
[Next ](Class%20FaceDetectionRecognition.html)
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