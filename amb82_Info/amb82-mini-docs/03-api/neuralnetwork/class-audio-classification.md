Class Audio Classification — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [NeuralNetwork](index.html)
- Class Audio Classification
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/NeuralNetwork/Class Audio Classification.rst)
# Class Audio Classification[](#class-audio-classification)
## **AudioClassificationResult Class**[](#audioclassificationresult-class)
### **Description**[](#description)
A class used to represent and retrieve data related to audio recognized by an audio classification neural network.
### **Syntax**[](#syntax)
class AudioClassificationResult
### **Members**[](#members)
|**Public Constructors**
|
|
| AudioClassificationResult::
AudioClassificationResult
|
Constructs an AudioClassificationResult
object.
|
|
| **Public Methods**
|
|
| AudioClassificationResult::classID
|
Get class ID of recognized audio.
|
|
| AudioClassificationResult::score
|
Get confidence score of recognized audio.
|
|
## **AudioClassificationResult::classID**[](#audioclassificationresult-classid)
### **Description**[](#id1)
Get class ID of recognized audio.
### **Syntax**[](#id2)
int classID(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [AudioClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/AudioClassification/AudioClassification.ino)
Note
“NNAudioClassification.h” must be included to use the class function. Object categories can be obtained from the “AudioClassList.h” file.
## **AudioClassificationResult::score**[](#audioclassificationresult-score)
### **Description**[](#id3)
Get confidence score of recognized audio classes.
### **Syntax**[](#id4)
int score(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [AudioClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/AudioClassification/AudioClassification.ino)
Note
“NNAudioClassification.h” must be included to use the class function. Object categories can be obtained from the “AudioClassList.h” file.
## **NNAudioClassification Class**[](#nnaudioclassification-class)
### **Description**[](#id9)
A class used to configure, run, and retrieve results of an audio classification neural network model.
### **Syntax**[](#id10)
class NNAudioClassification
### **Members**[](#id11)
|**Public Constructors**
|
|
| NNAudioClassification::
NNAudioClassification
|
Constructs an NNAudioClassification
object
|
|
| **Public Methods**
|
|
| NNAudioClassification::configAudio
|
Configure input audio stream
parameters
|
|
| NNAudioClassification::begin
|
Start audio classification
process on input audio
|
|
| NNAudioClassification::end
|
Stop audio classification
process on input audio
|
|
| NNAudioClassification::setResultCallback
|
Set a callback function to receive audio
classification results
|
|
| NNAudioClassification::getResultCount
|
Get number of audio classification results
|
|
| NNAudioClassification::getResult
|
Get audio classification results
|
|
## **NNAudioClassification::configAudio**[](#nnaudioclassification-configaudio)
### **Description**[](#id12)
Configure input audio stream parameters.
### **Syntax**[](#id13)
void configAudio(AudioSetting& config, uint16_t bitDepth = 16);
### **Parameters**[](#id14)
config: AudioSetting class object containing desired audio configuration.
bitDepth: number of bits of information in each audio sample. (Default value is 16)
### **Returns**[](#id15)
NA
### **Example Code**[](#id16)
Example: [AudioClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/AudioClassification/AudioClassification.ino)
Note
“NNAudioClassification.h” must be included to use the class function.
## **NNAudioClassification::begin**[](#nnaudioclassification-begin)
### **Description**[](#id18)
Start audio classification process on input audio.
### **Syntax**[](#id19)
void begin(void);
### **Parameters**[](#id20)
NA
### **Returns**[](#id21)
NA
### **Example Code**[](#id22)
Example: [AudioClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/AudioClassification/AudioClassification.ino)
Note
“NNAudioClassification.h” must be included to use the class function.
## **NNAudioClassification::end**[](#nnaudioclassification-end)
### **Description**[](#id24)
Stop audio classification process on input audio.
### **Syntax**[](#id25)
void end(void);
### **Parameters**[](#id26)
NA
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
NA
Note
“NNAudioClassification.h” must be included to use the class function.
## **NNAudioClassification::setResultCallback**[](#nnaudioclassification-setresultcallback)
### **Description**[](#id29)
Set a callback function to receive audio classification results.
### **Syntax**[](#id30)
void setResultCallback(void (*ac_callback)(std::vector));
### **Parameters**[](#id31)
ac_callback: A callback function that accepts a vector of AudioClassificationResult class objects as argument and returns void.
### **Returns**[](#id32)
NA
### **Example Code**[](#id33)
Example: [AudioClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/AudioClassification/AudioClassification.ino)
Note
“NNAudioClassification.h” must be included to use the class function. The callback function will be called with the latest results once per iteration.
## **NNAudioClassification::getResultCount**[](#nnaudioclassification-getresultcount)
### **Description**[](#id35)
Get number of audio classification results.
### **Syntax**[](#id36)
uint16_t getResultCount(void);
### **Parameters**[](#id37)
NA
### **Returns**[](#id38)
The number of recognized audio classes in the most recent set of results, as an unsigned integer.
### **Example Code**[](#id39)
Example: [AudioClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/AudioClassification/AudioClassification.ino)
Note
“NNAudioClassification.h” must be included to use the class function.
## **NNAudioClassification::getResult**[](#nnaudioclassification-getresult)
### **Description**[](#id41)
Get audio classification results.
### **Syntax**[](#id42)
AudioClassificationResult getResult(uint16_t index);
std::vector getResult(void);
### **Parameters**[](#id43)
index: index of specific audio classification result to retrieve.
### **Returns**[](#id44)
If no index is specified, the function returns all recognized audio classes contained in a vector of AudioClassificationResult class objects.
If an index is specified, the function returns the specific recognized audio class contained in a AudioClassificationResult class object.
### **Example Code**[](#id45)
Example: [AudioClassification](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/AudioClassification/AudioClassification.ino)
Note
“NNAudioClassification.h” must be included to use the class function.
[ Previous](index.html)
[Next ](Class%20FaceDetection.html)
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