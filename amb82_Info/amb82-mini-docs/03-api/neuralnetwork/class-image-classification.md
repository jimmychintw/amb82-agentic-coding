Class Image Classification — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [NeuralNetwork](index.html)
- Class Image Classification
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/NeuralNetwork/Class Image Classification.rst)
# Class Image Classification[](#class-image-classification)
## **ImageClassification Class**[](#imageclassification-class)
### **Description**[](#description)
A class used to represent and retrieve data related to objects recognized by an image classification neural network.
### **Syntax**[](#syntax)
class ImageClassificationResult
### **Members**[](#members)
|**Public Constructors**
|
|
| ImageClassificationResult::
ImageClassificationResult
|
Constructs an ImageClassificationResult
object.
|
|
| **Public Methods**
|
|
| ImageClassificationResult::classID
|
Get class ID of recognized object.
|
|
| ImageClassificationResult::score
|
Get confidence score of recognized object.
|
|
## **ImageClassificationResult::classID**[](#imageclassificationresult-classid)
### **Description**[](#id1)
Get class ID of recognized object.
### **Syntax**[](#id2)
int classID(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
“NNImageClassification.h” must be included to use the class function. Object categories can be obtained from the “ClassificationClassList.h” file.
## **ImageClassificationResult::score**[](#imageclassificationresult-score)
### **Description**[](#id3)
Get confidence score of recognized object.
### **Syntax**[](#id4)
int score(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
“NNImageClassification.h” must be included to use the class function. Object categories can be obtained from the “ClassificationClassList.h” file.
## **NNImageClassification Class**[](#nnimageclassification-class)
### **Description**[](#id9)
A class used to configure, run, and retrieve results of an image classification neural network model.
### **Syntax**[](#id10)
class NNImageClassification
### **Members**[](#id11)
|**Public Constructors**
|
|
| NNImageClassification::NNImageClassification
|
Constructs an NNImageClassification object
|
|
| **Public Methods**
|
|
| NNImageClassification::configInputImageColor
|
Configure input image color used during model training process
|
|
| NNImageClassification::configVideo
|
Configure input video stream parameters
|
|
| NNImageClassification::configRegionOfInterest
|
Configure image classification region of interest
|
|
| NNImageClassification::begin
|
Start image classification process on input video
|
|
| NNImageClassification::end
|
Stop image classification process on input video
|
|
| NNImageClassification::setResultCallback
|
Set a user callback function
|
|
| NNImageClassification::getResultCount
|
Get number of object detection results
|
|
| NNImageClassification::getResult
|
Get image classification results
|
|
| NNImageClassification::parseModelMetaData
|
Parses and extracts key information from the model’s metadata for
use in image classification
|
|
| NNImageClassification::getClassNameFromMeta
|
Retrieves the class label name from the model’s metadata
using the given class index
|
|
| NNImageClassification::useModelMetaData
|
Check whether the use of model metadata is currently enabled
|
|
## **NNImageClassification::configInputImageColor**[](#nnimageclassification-configinputimagecolor)
### **Description**[](#id12)
Configure input image color used during model training process.
### **Syntax**[](#id13)
void configInputImageColor(int color);
### **Parameters**[](#id14)
color: Color of images used for model training.
- 0 (Grayscale)
- 1 (RGB)
### **Returns**[](#id15)
NA
### **Example Code**[](#id16)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::configVideo**[](#nnimageclassification-configvideo)
### **Description**[](#id18)
Configure input video stream parameters.
### **Syntax**[](#id19)
void configVideo(VideoSetting &config);
### **Parameters**[](#id20)
config: VideoSetting class object containing desired video configuration.
### **Returns**[](#id21)
NA
### **Example Code**[](#id22)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::configRegionOfInterest**[](#nnimageclassification-configregionofinterest)
### **Description**[](#id24)
Configure image classification region of interest.
### **Syntax**[](#id25)
void configRegionOfInterest(int xmin, int xmax, int ymin, int ymax);
### **Parameters**[](#id26)
xmin: left boundary of region of interest, expressed in units of pixel.
xmax: right boundary of region of interest, expressed in units of pixel.
ymin: top boundary of region of interest, expressed in units of pixel.
ymax: bottom boundary of region of interest, expressed in units of pixel.
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
NA
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::begin**[](#nnimageclassification-begin)
### **Description**[](#id29)
Start image classification process on input video.
### **Syntax**[](#id30)
void begin (void);
### **Parameters**[](#id31)
NA
### **Returns**[](#id32)
NA
### **Example Code**[](#id33)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::end**[](#nnimageclassification-end)
### **Description**[](#id35)
Stop image classification process on input video.
### **Syntax**[](#id36)
void end (void);
### **Parameters**[](#id37)
NA
### **Returns**[](#id38)
NA
### **Example Code**[](#id39)
NA
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::setResultCallback**[](#nnimageclassification-setresultcallback)
### **Description**[](#id40)
Set a user callback function.
### **Syntax**[](#id41)
void setResultCallback(void (*ic_callback)(void));
### **Parameters**[](#id42)
ic_callback: user callback function.
### **Returns**[](#id43)
NA
### **Example Code**[](#id44)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::getResultCount**[](#nnimageclassification-getresultcount)
### **Description**[](#id46)
Get number of object detection results.
### **Syntax**[](#id47)
uint16_t getResultCount(void);
### **Parameters**[](#id48)
NA
### **Returns**[](#id49)
The number of detected objects in the most recent set of results, as an unsigned integer.
### **Example Code**[](#id50)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::getResult**[](#nnimageclassification-getresult)
### **Description**[](#id52)
Get image classification results.
### **Syntax**[](#id53)
ImageClassificationResult getResult(uint16_t index);
std::vector<ImageClassificationResult> getResult(void);
### **Parameters**[](#id54)
index: index of specific image classification result to retrieve
### **Returns**[](#id55)
If no index is specified, the function returns all detected objects contained in a vector of ImageClassificationResult class objects.
If an index is specified, the function returns the specific detected object contained in a ImageClassificationResult class object.
### **Example Code**[](#id56)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::parseModelMetaData**[](#nnimageclassification-parsemodelmetadata)
### **Description**[](#id58)
Parses and extracts key information from the model’s metadata for use in image classification.
### **Syntax**[](#id59)
char *parseModelMetaData(mm_context_t *vipnn_ctx);
### **Parameters**[](#id60)
vipnn_ctx: pointer to the mm_context_t that holds the model information.
### **Returns**[](#id61)
A pointer to a string containing the parsed model metadata.
### **Example Code**[](#id62)
NA
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::getClassNameFromMeta**[](#nnimageclassification-getclassnamefrommeta)
### **Description**[](#id63)
Retrieves the class label name from the model’s metadata using the given class index.
### **Syntax**[](#id64)
char *getClassNameFromMeta(char *meta_data, int class_id, int prob);
### **Parameters**[](#id65)
meta_data: pointer to metadata buffer that contains class information.
class_id: numeric ID of the class to look up.
prob: probability or confidence value associated with the class.
### **Returns**[](#id66)
A pointer to a string containing the class name.
### **Example Code**[](#id67)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
NNImageClassification.h” must be included to use the class function.
## **NNImageClassification::useModelMetaData**[](#nnimageclassification-usemodelmetadata)
### **Description**[](#id69)
Check whether the use of model metadata is currently enabled.
### **Syntax**[](#id70)
void useModelMetaData(int use_meta_data);
### **Parameters**[](#id71)
use_meta_data: flag (1 = enable, 0 = disable) to control whether model metadata is used.
### **Returns**[](#id72)
NA
### **Example Code**[](#id73)
Example: [RTSPImageClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPImageClassification/RTSPImageClassification.ino)
Note
NNImageClassification.h” must be included to use the class function.
[ Previous](Class%20GenAI.html)
[Next ](Class%20NNModelSelection.html)
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