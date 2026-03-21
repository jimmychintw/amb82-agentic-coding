Class BLERemoteService — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLERemoteService
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLERemoteService.rst)
# Class BLERemoteService[](#class-bleremoteservice)
## **BLERemoteService Class**[](#bleremoteservice-class)
### **Description**[](#description)
A class used for managing BLE GATT services on connected remote devices.
### **Syntax**[](#syntax)
class BLERemoteService
### **Members**[](#members)
|**Public Constructors**
|
|
| No public constructor is available for this class. You can get a
pointer to an instance of this class using BLEClient::getService().
|
|
| **Public Methods**
|
|
| BLERemoteService::getUUID
|
Get the service UUID
|
|
| BLERemoteService::getCharacteristic
|
Get a specific characteristic
on the remote device
|
|
## **BLERemoteService::getUUID**[](#bleremoteservice-getuuid)
### **Description**[](#id1)
Get the service UUID.
### **Syntax**[](#id2)
BLEUUID getUUID(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
This function returns the service UUID as a BLEUUID class object.
### **Example Code**[](#example-code)
NA
Note
“BLERemoteService.h” must be included to use the class function.
## **BLERemoteService::getCharacteristic**[](#bleremoteservice-getcharacteristic)
### **Description**[](#id3)
Get a characteristic with the specified UUID on the remote device.
### **Syntax**[](#id4)
BLERemoteCharacteristic* getCharacteristic (const char* uuid);
BLERemoteCharacteristic* getCharacteristic (BLEUUID uuid);
### **Parameters**[](#id5)
uuid: the desired characteristic UUID, expressed as a character array or a BLEUUID class object.
### **Returns**[](#id6)
The function returns the found characteristic as a BLERemoteCharacteristic object pointer, otherwise nullptr is returned if a characteristic with the UUID is not found.
### **Example Code**[](#id7)
Example: [BLEUartClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartClient/BLEUartClient.ino)
Note
BLERemoteService.h” must be included to use the class function.
[ Previous](Class%20BLERemoteDescriptor.html)
[Next ](Class%20BLEScan.html)
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