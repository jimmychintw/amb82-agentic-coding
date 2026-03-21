Class FaceDetectionRecognition — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [NeuralNetwork](index.html)
- Class FaceDetectionRecognition
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/NeuralNetwork/Class FaceDetectionRecognition.rst)
# Class FaceDetectionRecognition[](#class-facedetectionrecognition)
## **FaceRecognitionResult Class**[](#facerecognitionresult-class)
### **Description**[](#description)
A class used to represent and retrieve data related to faces recognized by a face recognition neural network.
### **Syntax**[](#syntax)
class FaceRecognitionResult
### **Members**[](#members)
|**Public Constructors**
|
|
| FaceRecognitionResult::
FaceRecognitionResult
|
Constructs a FaceDetectionResult
object
|
|
| **Public Methods**
|
|
| FaceRecognitionResult::name
|
Get name of recognized face.
|
|
| FaceRecognitionResult::xMin
|
Get x coordinate of the top left corner of the bounding box containing the recognized face.
|
|
| FaceRecognitionResult::xMax
|
Get x coordinate of the bottom right corner of the bounding box containing the recognized face.
|
|
| FaceRecognitionResult::yMin
|
Get y coordinate of the top left corner of the bounding box containing the recognized face.
|
|
| FaceRecognitionResult::yMax
|
Get y coordinate of the bottom right corner of the bounding box containing the recognized face.
|
|
## **FaceRecognitionResult::name**[](#facerecognitionresult-name)
### **Description**[](#id1)
Get name of recognized face.
### **Syntax**[](#id2)
const char* name(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
A pointer to a character array containing the name of the recognized face.
### **Example Code**[](#example-code)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **FaceRecognitionResult::xMin**[](#facerecognitionresult-xmin)
### **Description**[](#id3)
Get x coordinate of the top left corner of the bounding box containing the recognized face.
### **Syntax**[](#id4)
float xMin(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id7)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **FaceRecognitionResult::yMin**[](#facerecognitionresult-ymin)
### **Description**[](#id9)
Get y coordinate of the top left corner of the bounding box containing the recognized face.
### **Syntax**[](#id10)
float yMin(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
A float ranging from 0.00 to 1.00, with 0.00 indicating the top edge of the input video frame and 1.00 indicating the bottom edge of the input video frame.
### **Example Code**[](#id13)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **FaceRecognitionResult::xMax**[](#facerecognitionresult-xmax)
### **Description**[](#id15)
Get x coordinate of the bottom right corner of the bounding box containing the recognized face.
### **Syntax**[](#id16)
float xMax(void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
A float ranging from 0.00 to 1.00, with 0.00 indicating the left edge of the input video frame and 1.00 indicating the right edge of the input video frame.
### **Example Code**[](#id19)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **FaceRecognitionResult::yMax**[](#facerecognitionresult-ymax)
### **Description**[](#id21)
Get y coordinate of the bottom right corner of the bounding box containing the recognized face.
### **Syntax**[](#id22)
float yMax(void);
### **Parameters**[](#id23)
NA
### **Returns**[](#id24)
A float ranging from 0.00 to 1.00, with 0.00 indicating the top edge of the input video frame and 1.00 indicating the bottom edge of the input video frame.
### **Example Code**[](#id25)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **NNFaceDetectionRecognition Class**[](#nnfacedetectionrecognition-class)
### **Description**[](#id27)
A class used to configure, run, and retrieve results of a face recognition neural network model.
### **Syntax**[](#id28)
class NNFaceDetectionRecognition
### **Members**[](#id29)
|**Public Constructors**
|
|
| NNFaceDetectionRecognition::
NNFaceDetectionRecognition
|
Constructs an NNFaceDetectionRecognition object.
|
|
| **Public Methods**
|
|
| NNFaceDetectionRecognition::begin
|
Start face recognition process on input video.
|
|
| NNFaceDetectionRecognition::end
|
Stop face recognition process on input video.
|
|
| NNFaceDetectionRecognition::registerFace
|
Register a detected face and assign it a name.
|
|
| NNFaceDetectionRecognition::exitRegisterMode
|
Exit face registration mode.
|
|
| NNFaceDetectionRecognition::resetRegisteredFace
|
Reset all previously registered faces.
|
|
| NNFaceDetectionRecognition::backupRegisteredFace
|
Save currently registered faces to flash.
|
|
| NNFaceDetectionRecognition::restoreRegisteredFace
|
Load registered faces from flash.
|
|
| NNFaceDetectionRecognition::setThreshold
|
Set minimum threshold for face recognition confidence level.
|
|
| NNFaceDetectionRecognition::setResultCallback
|
Set a callback function to receive face recognition results.
|
|
| NNFaceDetectionRecognition::getResultCount
|
Get number of face recognition results.
|
|
| NNFaceDetectionRecognition::getResult
|
Get face recognition results.
|
|
## **NNFaceDetectionRecognition::begin**[](#nnfacedetectionrecognition-begin)
### **Description**[](#id30)
Start face recognition process on input video.
### **Syntax**[](#id31)
void begin(void);
### **Parameters**[](#id32)
NA
### **Returns**[](#id33)
NA
### **Example Code**[](#id34)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **NNFaceDetectionRecognition::end**[](#nnfacedetectionrecognition-end)
### **Description**[](#id36)
Stop face recognition process on input video.
### **Syntax**[](#id37)
void end(void);
### **Parameters**[](#id38)
NA
### **Returns**[](#id39)
NA
### **Example Code**[](#id40)
NA
Note
“NNFaceRecognition.h” must be included to use the class function.
## **NNFaceDetectionRecognition::registerFace**[](#nnfacedetectionrecognition-registerface)
### **Description**[](#id41)
Register a detected face and assign it a name.
### **Syntax**[](#id42)
void registerFace(String name);
void registerFace(const char* name);
### **Parameters**[](#id43)
name: name to assign to newly registered face, expressed as a String class object or a pointer to a character array.
### **Returns**[](#id44)
NA
### **Example Code**[](#id45)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **NNFaceDetectionRecognition::exitRegisterMode**[](#nnfacedetectionrecognition-exitregistermode)
### **Description**[](#id47)
Exit face registration mode.
### **Syntax**[](#id48)
void exitRegisterMode(void);
### **Parameters**[](#id49)
NA
### **Returns**[](#id50)
NA
### **Example Code**[](#id51)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **NNFaceDetectionRecognition::resetRegisteredFace**[](#nnfacedetectionrecognition-resetregisteredface)
### **Description**[](#id53)
Reset all previously registered faces.
### **Syntax**[](#id54)
void resetRegisteredFace(void);
### **Parameters**[](#id55)
NA
### **Returns**[](#id56)
NA
### **Example Code**[](#id57)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **NNFaceDetectionRecognition::backupRegisteredFace**[](#nnfacedetectionrecognition-backupregisteredface)
### **Description**[](#id59)
Save currently registered faces to flash.
### **Syntax**[](#id60)
void backupRegisteredFace(void);
### **Parameters**[](#id61)
NA
### **Returns**[](#id62)
NA
### **Example Code**[](#id63)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **NNFaceDetectionRecognition::restoreRegisteredFace**[](#nnfacedetectionrecognition-restoreregisteredface)
### **Description**[](#id65)
Load registered faces from flash.
### **Syntax**[](#id66)
void restoreRegisteredFace(void);
### **Parameters**[](#id67)
NA
### **Returns**[](#id68)
NA
### **Example Code**[](#id69)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **NNFaceDetectionRecognition::setThreshold**[](#nnfacedetectionrecognition-setthreshold)
### **Description**[](#id71)
Set minimum threshold for face recognition confidence level.
### **Syntax**[](#id72)
void setThreshold(uint8_t threshold);
### **Parameters**[](#id73)
threshold: Face recognition confidence threshold as an unsigned integer.
- 0 to 100 (Default value is 1)
### **Returns**[](#id74)
NA
### **Example Code**[](#id75)
NA
Note
“NNFaceRecognition.h” must be included to use the class function. A higher threshold results in a stricter face recognition process. For example increasing the threshold may cause recognition to fail if the face is turned sideways. The default value of 1 has been tested to minimize false positives, while maximizing the conditions for recognizing a registered face.
## **NNFaceDetectionRecognition::setResultCallback**[](#nnfacedetectionrecognition-setresultcallback)
### **Description**[](#id76)
Set a callback function to receive face recognition results.
### **Syntax**[](#id77)
void setResultCallback(void (*fr_callback)(std::vector));
### **Parameters**[](#id78)
fr_callback: A callback function that accepts a vector of FaceRecognitionResult class objects as argument and returns void.
### **Returns**[](#id79)
NA
### **Example Code**[](#id80)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function. The callback function will be called with the latest results once per iteration.
## **NNFaceDetectionRecognition::getResultCount**[](#nnfacedetectionrecognition-getresultcount)
### **Description**[](#id82)
Get number of face recognition results.
### **Syntax**[](#id83)
uint16_t getResultCount(void);
### **Parameters**[](#id84)
NA
### **Returns**[](#id85)
The number of recognized faces in the most recent set of results, as an unsigned integer.
### **Example Code**[](#id86)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
## **NNFaceDetectionRecognition::getResult**[](#nnfacedetectionrecognition-getresult)
### **Description**[](#id88)
Get face recognition results.
### **Syntax**[](#id89)
FaceRecognitionResult getResult(uint16_t index);
std::vector getResult(void);
### **Parameters**[](#id90)
index: index of specific face recognition result to retrieve.
### **Returns**[](#id91)
If no index is specified, the function returns all recognized faces contained in a vector of FaceRecognitionResult class objects.
If an index is specified, the function returns the specific recognized face contained in a FaceRecognitionResult class object.
### **Example Code**[](#id92)
Example: [RTSPFaceRecognition](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceRecognition/RTSPFaceRecognition.ino)
Note
“NNFaceRecognition.h” must be included to use the class function.
[ Previous](Class%20FaceDetection.html)
[Next ](Class%20GenAI.html)
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