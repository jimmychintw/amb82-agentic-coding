Class BLEService — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEService
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEService.rst)
# Class BLEService[](#class-bleservice)
## **BLEService Class**[](#bleservice-class)
### **Description**[](#description)
A class used for creating and managing BLE GATT services.
### **Syntax**[](#syntax)
class BLEService
### **Members**[](#members)
|**Public Constructors**
|
|
| BLEService::BLEService
|
Constructs a BLEService object
|
|
| **Public Methods**
|
|
| BLEService::setUUID
|
Set service UUID
|
|
| BLEService::getUUID
|
Get service UUID
|
|
| BLEService::addCharacteristic
|
Add a characteristic to service
|
|
| BLEService::getCharacteristic
|
Get a previously added
characteristic
|
|
## **BLEService::BLEService**[](#bleservice-bleservice)
### **Description**[](#id1)
Constructs a BLEService object.
### **Syntax**[](#id2)
BLEService(BLEUUID uuid);
BLEService(const char* uuid);
### **Parameters**[](#parameters)
uuid: service UUID, expressed as a BLEUUID class object or a character array.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
“BLEService.h” must be included to use the class function.
## **BLEService::setUUID**[](#bleservice-setuuid)
### **Description**[](#id3)
Set the service UUID.
### **Syntax**[](#id4)
void setUUID(BLEUUID uuid);
### **Parameters**[](#id5)
uuid: service UUID, expressed as a BLEUUID class object.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
“BLEService.h” must be included to use the class function.
## **BLEService::getUUID**[](#bleservice-getuuid)
### **Description**[](#id8)
Get the service UUID.
### **Syntax**[](#id9)
BLEUUID getUUID(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
This function returns the service UUID in a BLEUUID class object.
### **Example Code**[](#id12)
NA
Note
“BLEService.h” must be included to use the class function.
**BLE::addCharacteristic**
### **Description**[](#id13)
Add a characteristic to the service.
### **Syntax**[](#id14)
void addCharacteristic(BLECharacteristic& newChar);
### **Parameters**[](#id15)
newChar: the BLECharacteristic to add to the service.
### **Returns**[](#id16)
NA
### **Example Code**[](#id17)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
“BLEService.h” must be included to use the class function.
## **BLE::getCharacteristic**[](#ble-getcharacteristic)
### **Description**[](#id19)
Get a previously added characteristic.
### **Syntax**[](#id20)
BLECharacteristic* getCharacteristic(uint8_t charIndex);
### **Parameters**[](#id21)
charIndex: position index of characteristic.
### **Returns**[](#id22)
This function returns a pointer to the BLECharacteristic at the requested position index else return NULL.
### **Example Code**[](#id23)
NA
Note
“BLEService.h” must be included to use the class function.
[ Previous](Class%20BLESecurity.html)
[Next ](Class%20BLEUUID.html)
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