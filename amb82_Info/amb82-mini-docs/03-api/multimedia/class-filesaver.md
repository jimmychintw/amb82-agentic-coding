Class Filesaver — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class Filesaver
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class Filesaver.rst)
# Class Filesaver[](#class-filesaver)
## **Filesaver Class**[](#filesaver-class)
### **Description**[](#description)
A class for file saving.
### **Syntax**[](#syntax)
class Filesaver
### **Members**[](#members)
|**Public Constructors**
|
|
| Filesaver::Filesaver
|
Constructs a Filesaver object.
|
|
| **Public Methods**
|
|
| Filesaver::setFileName
|
Set the filename to be saved.
|
|
| Filesaver::staticImgSaveCB
|
Static raw image saving callback function.
|
|
| Filesaver::rawImgSaveSDBegin
|
Save raw image into SD card.
|
|
| Filesaver::rawImgSaveCB
|
Raw image saving callback function.
|
|
| Filesaver::rawReform
|
Function to perform image raw reform.
|
|
## **Filesaver::setFileName**[](#filesaver-setfilename)
### **Description**[](#id1)
Set the filename to be saved.
### **Syntax**[](#id2)
void setFileName(char *filename);
### **Parameters**[](#parameters)
filename: name of the file to be saved.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [SDCardSaveRaw](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/CaptureRaw/SDCardSaveRaw/SDCardSaveRaw.ino)
Note
“Filesaver.h” must be included to use the class function.
## **Filesaver::staticImgSaveCB**[](#filesaver-staticimgsavecb)
### **Description**[](#id3)
Static raw image saving callback function.
### **Syntax**[](#id4)
void staticImgSaveCB(char *file_path, uint32_t data_addr, uint32_t data_size);
### **Parameters**[](#id5)
file_path: file path of the image to be saved
data_addr: image data address
data_size: image data size
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [SDCardSaveRaw](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/CaptureRaw/SDCardSaveRaw/SDCardSaveRaw.ino)
Note
“Filesaver.h” must be included to use the class function.
## **Filesaver::rawImgSaveSDBegin**[](#filesaver-rawimgsavesdbegin)
### **Description**[](#id9)
Save raw image into SD card.
### **Syntax**[](#id10)
void rawImgSaveSDBegin();
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [SDCardSaveRaw](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/CaptureRaw/SDCardSaveRaw/SDCardSaveRaw.ino)
Note
“Filesaver.h” must be included to use the class function.
## **Filesaver::rawImgSaveCB**[](#filesaver-rawimgsavecb)
### **Description**[](#id15)
Raw image saving callback function.
### **Syntax**[](#id16)
void rawImgSaveCB(char *file_path, uint32_t data_addr, uint32_t data_size);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
NA
### **Example Code**[](#id19)
Example: [SDCardSaveRaw](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/CaptureRaw/SDCardSaveRaw/SDCardSaveRaw.ino)
Note
“Filesaver.h” must be included to use the class function.
## **Filesaver::rawReform**[](#filesaver-rawreform)
### **Description**[](#id21)
Function to perform image raw reform.
### **Syntax**[](#id22)
void rawReform(unsigned char *pData, int dataLen);
### **Parameters**[](#id23)
pData:  pointer to the image data address
dataLen: image data length
### **Returns**[](#id24)
NA
### **Example Code**[](#id25)
Example: [SDCardSaveRaw](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/CaptureRaw/SDCardSaveRaw/SDCardSaveRaw.ino)
Note
“Filesaver.h” must be included to use the class function.
[ Previous](Class%20Demuxer.html)
[Next ](Class%20MotionDetection.html)
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