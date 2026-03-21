Class NNModelSelection — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [NeuralNetwork](index.html)
- Class NNModelSelection
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/NeuralNetwork/Class NNModelSelection.rst)
# Class NNModelSelection[](#class-nnmodelselection)
## **NNModelSelection Class**[](#nnmodelselection-class)
### **Description**[](#description)
A class used to select Neural Network (NN) task and models.
### **Syntax**[](#syntax)
class NNModelSelection
### **Members**[](#members)
|**Public Constructors**
|
|
| NNModelSelection::NNModelSelection
|
Constructs a NNModelSelection object.
|
|
| **Public Methods**
|
|
| NNModelSelection::modelSelect
|
Select NN task and models.
|
|
## **NNModelSelection::modelSelect**[](#nnmodelselection-modelselect)
### **Description**[](#id1)
Select Neural Network (NN) task and models.
### **Syntax**[](#id2)
void modelSelect(unsigned char nntask);
void modelSelect(unsigned char nntask, unsigned char objdetmodel, unsigned char facedetmodel, unsigned char facerecogmodel);
### **Parameters**[](#parameters)
nntask: Neural network task to perform. Default value is NA_MODEL.
- OBJECT_DETECTION, FACE_DETECTION, FACE_RECOGNITION
objdetmodel: Neural network model used for Object Detection. Default value is NA_MODEL.
- DEFAULT_YOLOV3TINY, CUSTOMIZED_YOLOV3TINY (YOLOv3 model)
- DEFAULT_YOLOV4TINY, CUSTOMIZED_YOLOV4TINY (YOLOv4 model)
- DEFAULT_YOLOV7TINY, CUSTOMIZED_YOLOV7TINY (YOLOv7 model)
facedetmodel: Neural network model used for Face Detection. Default value is NA_MODEL.
- DEFAULT_SCRFD, CUSTOMIZED_SCRFD
facerecogmodel: Neural network model used for Face Recognition. Default value is NA_MODEL.
- DEFAULT_MOBILEFACENET, CUSTOMIZED_MOBILEFACENET
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [ObjectDetectionCallback](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/ObjectDetectionCallback/ObjectDetectionCallback.ino)
Note
“NNModelSelection.h” must be included to use the class function. Replace objdetmodel, facedetmodel and facerecogmodel arguments with “NA_MODEL” if they are not necessary for your selected NN Task.
[ Previous](Class%20Image%20Classification.html)
[Next ](Class%20ObjectDetection.html)
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