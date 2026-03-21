Class OTA — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [OTA](index.html)
- Class OTA
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/OTA/Class OTA.rst)
# Class OTA[](#class-ota)
## **OTA Class**[](#ota-class)
### **Description**[](#description)
A class used for updating firmware Over the Air (OTA) in local area network.
### **Syntax**[](#syntax)
class OTA
### **Members**[](#members)
|**Public Constructors**
|
|
| A public constructor should not be used as this class is intended to be a singleton class.
Access member functions using the object instance named OTA.
|
|
| **Public Methods**
|
|
| OTA::start_OTA_threads
|
To begin threading tasks for OTA
firmware update.
|
|
## **OTA::start_OTA_threads**[](#ota-start-ota-threads)
### **Description**[](#id1)
To begin threading tasks for OTA firmware update.
### **Syntax**[](#id2)
void start_OTA_threads(int port, char* server);
### **Parameters**[](#parameters)
port: port number for the OTA HTTP server IP address
*server: pointer for OTA HTTP server IP address
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [OTA](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/OTA/examples/OTA/OTA.ino)
Note
“OTA.h” must be included to use the function.
[ Previous](index.html)
[Next ](../PowerMode/index.html)
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