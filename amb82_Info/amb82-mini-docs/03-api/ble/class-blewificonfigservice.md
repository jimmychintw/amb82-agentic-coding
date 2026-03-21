Class BLEWifiConfigService — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEWifiConfigService
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEWifiConfigService.rst)
# Class BLEWifiConfigService[](#class-blewificonfigservice)
## **BLEWifiConfigService Class**[](#blewificonfigservice-class)
### **Description**[](#description)
A class used for managing a BLE WiFi configuration service running on
the device
### **Syntax**[](#syntax)
class BLEWifiConfigService
### **Members**[](#members)
|**Public Constructors**
|
|
| BLEWifiConfigService::
BLEWifiConfigService
|
Create an instance of the
BLEWifiConfigService object
|
|
| **Public Methods**
|
|
| BLEWifiConfigService::begin
|
Start background thread to
process WiFi configuration
commands
|
|
| BLEWifiConfigService::end
|
Stop background thread
processing WiFi configuration
commands
|
|
| BLEWifiConfigService::addService
|
Add the service to the BLE stack
|
|
| BLEWifiConfigService::advData
|
Get advertising data correctly
formatted for WiFi configuration
service
|
|
## **BLEWifiConfigService::BLEWifiConfigService**[](#blewificonfigservice-blewificonfigservice)
### **Description**[](#id1)
Create an instance of the BLEWifiConfigService object.
### **Syntax**[](#id2)
void BLEWifiConfigService (void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEWifiConfig](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEWifiConfig/BLEWifiConfig.ino)
Note
Only one instance of this class / service should be created. “BLEWifiConfigService.h” must be included to use the class function.
## **BLEWifiConfigService::begin**[](#blewificonfigservice-begin)
### **Description**[](#id3)
Start background thread to process WiFi configuration commands.
### **Syntax**[](#id4)
void begin(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [BLEWifiConfig](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEWifiConfig/BLEWifiConfig.ino)
Note
“BLEWifiConfigService.h” must be included to use the class function.
## **BLEWifiConfigService::end**[](#blewificonfigservice-end)
### **Description**[](#id9)
Stop background thread processing WiFi configuration commands.
### **Syntax**[](#id10)
void end(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
NA
Note
“BLEWifiConfigService.h” must be included to use the class function.
## **BLEWifiConfigService::addService**[](#blewificonfigservice-addservice)
### **Description**[](#id14)
Add the WiFi configuration service to the BLE stack.
### **Syntax**[](#id15)
void addService(void);
### **Parameters**[](#id16)
NA
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
Example: [BLEWifiConfig](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEWifiConfig/BLEWifiConfig.ino)
Note
“BLEWifiConfigService.h” must be included to use the class function.
## **BLEWifiConfigService::advData**[](#blewificonfigservice-advdata)
### **Description**[](#id20)
Get advertising data correctly formatted for WiFi configuration service.
### **Syntax**[](#id21)
BLEAdvertData advData(void);
### **Parameters**[](#id22)
NA
### **Returns**[](#id23)
This function returns a BLEAdvertData object that contains the required advertising data fields for the WiFi configuration service to work.
### **Example Code**[](#id24)
Example: [BLEWifiConfig](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEWifiConfig/BLEWifiConfig.ino)
Note
The advertisement data needs to be correctly formatted for the corresponding smartphone app to recognise the device. WiFi configuration service advertisement data requires the local BT address, and should be called only after peripheral mode is started and may also require stopping and restarting the advertising process. “BLEWifiConfigService.h” must be included to use the class function.
[ Previous](Class%20BLEUUID.html)
[Next ](../FileSystem/index.html)
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