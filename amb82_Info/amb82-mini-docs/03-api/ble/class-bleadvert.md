Class BLEAdvert — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEAdvert
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEAdvert.rst)
# Class BLEAdvert[](#class-bleadvert)
## **BLEAdvert Class**[](#bleadvert-class)
### **Description**[](#description)
A class used for managing BLE advertising settings.
### **Syntax**[](#syntax)
class BLEAdvert
### **Members**[](#members)
|**Public Constructors**
|
No public constructor is available as this class is intended to be a
singleton class. You can get a pointer to this class using
BLEDevice::configAdvert().
|
|
| **Public Methods**
|
|
| BLEAdvert::updateAdvertParams
|
Update the current BLE advertisement settings.
|
|
| BLEAdvert::startAdv
|
Start BLE advertising.
|
|
| BLEAdvert::stopAdv
|
Stop BLE advertising.
|
|
| BLEAdvert::setAdvType
|
Set the BLE advertising type.
|
|
| BLEAdvert::setMinInterval
|
Set the BLE advertising minimum interval.
|
|
| BLEAdvert::setMaxInterval
|
Set the BLE advertising maximum interval.
|
|
| BLEAdvert::setAdvData
|
Set BLE advertising data.
|
|
| BLEAdvert::setScanRspData
|
Set BLE scan response data.
|
|
## **BLEAdvert::updateAdvertParams**[](#bleadvert-updateadvertparams)
### **Description**[](#id1)
Update the current BLE advertisement settings.
### **Syntax**[](#id2)
void updateAdvertParams(void);
### **Parameters**[](#parameters)
NA
**Returns**
NA
### **Example Code**[](#example-code)
Example: [BLEWifiConfig](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEWifiConfig/BLEWifiConfig.ino)
Note
Please use the other class member functions to set the BLE advertising parameters before using this function to update the advert data. “BLEAdvert.h” must be included to use the class function.
## **BLEAdvert::startAdv**[](#bleadvert-startadv)
### **Description**[](#id3)
Start BLE advertising.
### **Syntax**[](#id4)
void startAdv(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#id6)
Example: [BLEWifiConfig](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEWifiConfig/BLEWifiConfig.ino)
Note
This function gives you more control and flexibility over BLE advertising parameters. This function should not be used to start the BLE advertising process without first registering the necessary callback and handler functions. Call BLEDevice::beginPeripheral() to register the necessary functions and start advertising for the first time.”BLEAdvert.h” must be included to use the class function.
## **BLEAdvert::stopAdv**[](#bleadvert-stopadv)
### **Description**[](#id8)
Stop BLE advertising.
### **Syntax**[](#id9)
void stopAdv(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
Example: [BLEWifiConfig](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEWifiConfig/BLEWifiConfig.ino)
Note
This function gives you more control and flexibility over BLE advertising parameters. This function should not be used to directly stop the BLE advertising process. Call BLEDevice::end() to stop advertising and free up used resources. “BLEAdvert.h” must be included to use the class function.
## **BLEAdvert::setAdvType**[](#bleadvert-setadvtype)
### **Description**[](#id14)
Set the BLE advertising type.
### **Syntax**[](#id15)
void setAdvType(uint8_t advType);
### **Parameters**[](#id16)
advType: the desired advertisement type.
- GAP_ADTYPE_ADV_IND (0, connectable undirected advertisement)
- GAP_ADTYPE_ADV_HDC_DIRECT_IND (1, connectable high duty cycle directed advertisement)
- GAP_ADTYPE_ADV_SCAN_IND (2, scannable undirected advertisement)
- GAP_ADTYPE_ADV_NONCONN_IND (3, Non-connectable undirected advertisement)
- GAP_ADTYPE_ADV_LDC_DIRECT_IND (4, connectable low duty cycle directed advertisement)
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
Example: [BLEBeacon](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBeacon/BLEBeacon.ino)
Note
If connection requests should be allowed, call this function with GAP_ADTYPE_ADV_IND. If all connection requests should be rejected, call this function with GAP_ADTYPE_ADV_NONCONN_IND. “BLEAdvert.h” must be included to use the class function.
## **BLEAdvert::setMinInterval**[](#bleadvert-setmininterval)
### **Description**[](#id19)
Set the minimum BLE advertising interval.
### **Syntax**[](#id20)
void setMinInterval(uint16_t minInt_ms);
### **Parameters**[](#id21)
minInt_ms: the desired advertisement minimum interval, expressed in milliseconds.
- 20 to 10240.
### **Returns**[](#id22)
NA
### **Example Code**[](#id23)
NA
Note
BLE advertisements will repeat with an interval between the set minimum and maximum intervals. Set a shorter interval for the BLE device to be discovered rapidly and set a longer interval to conserve power. “BLEAdvert.h” must be included to use the class function.
## **BLEAdvert::setMaxInterval**[](#bleadvert-setmaxinterval)
### **Description**[](#id24)
Set the maximum BLE advertising interval.
### **Syntax**[](#id25)
void setMaxInterval(uint16_t minInt_ms);
### **Parameters**[](#id26)
minInt_ms: the desired advertisement maximum interval, expressed in milliseconds.
- 20ms to 10240.
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
NA
Note
BLE advertisements will repeat with an interval between the set minimum and maximum intervals. Set a shorter interval for the BLE device to be discovered rapidly and set a longer interval to conserve power. “BLEAdvert.h” must be included to use the class function.
## **BLEAdvert::setAdvData**[](#bleadvert-setadvdata)
### **Description**[](#id29)
Set BLE advertising data.
### **Syntax**[](#id30)
void setAdvData(BLEAdvertData adData);
void setAdvData(uint8_t* pData, uint8_t size);
### **Parameters**[](#id31)
adData: advertising data formatted in a BLEAdvertData class object.
pData: pointer to a byte array containing the required advertising data.
size: number of bytes the advertising data contains, maximum of 31 bytes.
### **Returns**[](#id32)
NA
### **Example Code**[](#id33)
Example: [BLEWifiConfig](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEWifiConfig/BLEWifiConfig.ino)
Note
“BLEAdvert.h” must be included to use the class function.
## **BLEAdvert::setScanRspData**[](#bleadvert-setscanrspdata)
### **Description**[](#id35)
Set BLE scan response data.
### **Syntax**[](#id36)
void setScanRspData(BLEAdvertData adData);
void setScanRspData(uint8_t* pData, uint8_t size);
### **Parameters**[](#id37)
adData: scan response data formatted in a BLEAdvertData class object.
pData: pointer to a byte array containing the required scan response data.
size: number of bytes the scan response data contains, maximum of 31 bytes.
### **Returns**[](#id38)
NA
### **Example Code**[](#id39)
NA
Note
“BLEAdvert.h” must be included to use the class function.
[ Previous](Class%20BLEAddr.html)
[Next ](Class%20BLEAdvertData.html)
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