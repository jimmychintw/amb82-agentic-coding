Class BLEBeacon — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEBeacon
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEBeacon.rst)
# Class BLEBeacon[](#class-blebeacon)
## **iBeacon Class**[](#ibeacon-class)
### **Description**[](#description)
A class used for managing iBeacon BLE advertising data.
### **Syntax**[](#syntax)
class iBeacon
### **Members**[](#members)
|**Public Constructors**
|
|
| iBeacon::iBeacon
|
Constructs an iBeacon object
|
|
| **Public Methods**
|
|
| iBeacon::getManufacturerId
|
Get current manufacturer ID value
|
|
| iBeacon::getUUID
|
Get current UUID value
|
|
| iBeacon::getMajor
|
Get current Major value for customizing
beacons
|
|
| iBeacon::getMinor
|
Get current Minor value for customizing
beacons
|
|
| iBeacon::getRSSI
|
Get current received signal strength
indicator (RSSI) value
|
|
| iBeacon::setManufacturerId
|
Set manufacturer ID value
|
|
| iBeacon::setUUID
|
Set UUID value
|
|
| iBeacon::setMajor
|
Set Major value for customizing beacons
|
|
| iBeacon::setMinor
|
Set Minor value for customizing beacons
|
|
| iBeacon::setRSSI
|
Set received signal strength indicator
(RSSI) value
|
|
| iBeacon::getAdvData
|
Get current advertising data
|
|
| iBeacon::getScanRsp
|
Get current scan response data
|
|
## **altBeacon Class**[](#altbeacon-class)
### **Description**[](#id1)
A class used for managing altBeacon BLE advertising data.
### **Syntax**[](#id2)
class altBeacon
### **Members**[](#id3)
|**Public Constructors**
|
|
| altBeacon::altBeacon
|
Constructs an altBeacon object
|
|
| **Public Methods**
|
|
| altBeacon::getManufacturerId
|
Get current manufacturer ID value
|
|
| altBeacon::getUUID
|
Get current UUID value
|
|
| altBeacon::getMajor
|
Get current Major value for
customizing beacons
|
|
| altBeacon::getMinor
|
Get current Minor value for
customizing beacons
|
|
| altBeacon::getRSSI
|
Get current received signal strength
indicator (RSSI) value
|
|
| altBeacon::getRSVD
|
Get current Reserved value
|
|
| altBeacon::setManufacturerId
|
Set manufacturer ID value
|
|
| altBeacon::setUUID
|
Set UUID value
|
|
| altBeacon::setMajor
|
Set Major value for customizing
beacons
|
|
| altBeacon::setMinor
|
Set Minor value for customizing
beacons
|
|
| altBeacon::setRSSI
|
Set received signal strength
indicator (RSSI) value
|
|
| altBeacon::setRSVD
|
Set Reserved value
|
|
| altBeacon::getAdvData
|
Get current advertising data
|
|
| altBeacon::getScanRsp
|
Get current scan response data
|
|
## **iBeacon::iBeacon**[](#ibeacon-ibeacon)
### **Description**[](#id4)
Constructs an iBeacon object.
### **Syntax**[](#id5)
void iBeacon(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
NA
Note
“BLEBeacon.h” must be included to use the class function.
## **altBeacon::altBeacon**[](#altbeacon-altbeacon)
### **Description**[](#id6)
Constructs an altBeacon object
### **Syntax**[](#id7)
void altBeacon(void);
### **Parameters**[](#id8)
NA
### **Returns**[](#id9)
NA
### **Example Code**[](#id10)
NA
Note
“BLEBeacon.h” must be included to use the class function.
## **iBeacon::getManufacturerId** / **altBeacon::getManufacturerId**[](#ibeacon-getmanufacturerid-altbeacon-getmanufacturerid)
### **Description**[](#id11)
Get current Manufacturer ID value.
### **Syntax**[](#id12)
uint16_t getManufacturerId(void);
### **Parameters**[](#id13)
NA
### **Returns**[](#id14)
The function returns a 16-bit unsigned integer containing the current Company ID.
### **Example Code**[](#id15)
NA
Note
Refer to [https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers/](https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers/) for the full list of assigned Bluetooth company identifiers. “BLEBeacon.h” must be included to use the class function.
## **iBeacon::getUUID** / **altBeacon::getUUID**[](#ibeacon-getuuid-altbeacon-getuuid)
### **Description**[](#id16)
Get the current UUID value.
### **Syntax**[](#id17)
void getUUID(uint8_t* UUID);
### **Parameters**[](#id18)
UUID: Provide a pointer to a 16 elements uint8_t array containing current UUID.
### **Returns**[](#id19)
NA
### **Example Code**[](#id20)
NA
Note
UUID is a 128-bit number used to uniquely identify a beacon. It is commonly expressed as a 32-character hexadecimal string. UUIDs can be generated at [https://www.uuidgenerator.net/](https://www.uuidgenerator.net/). “BLEBeacon.h” must be included to use the class function.
## **iBeacon::getMajor** / **altBeacon::getMajor**[](#ibeacon-getmajor-altbeacon-getmajor)
### **Description**[](#id21)
Get current Major value for customizing beacons.
### **Syntax**[](#id22)
uint16_t getMajor(void);
### **Parameters**[](#id23)
NA
### **Returns**[](#id24)
This function returns a 16-bit unsigned integer containing the current major value.
### **Example Code**[](#id25)
NA
Note
Major and Minor are values used for customizing beacons. These can be set to any value. Refer to [https://developer.apple.com/ibeacon/](https://developer.apple.com/ibeacon/) or [https://altbeacon.org/](https://altbeacon.org/) for more information. “BLEBeacon.h” must be included to use the class function.
## **iBeacon::getMinor** - **altBeacon::getMinor**[](#ibeacon-getminor-altbeacon-getminor)
### **Description**[](#id26)
Get current Minor value for customizing beacons.
### **Syntax**[](#id27)
uint16_t getMinor(void);
### **Parameters**[](#id28)
NA
### **Returns**[](#id29)
This function returns a 16-bit unsigned integer containing the current minor value.
### **Example Code**[](#id30)
NA
Note
Major and Minor are values used for customizing beacons. These can be set to any value. Refer to [https://developer.apple.com/ibeacon/](https://developer.apple.com/ibeacon/) or [https://altbeacon.org/](https://altbeacon.org/) for more information. “BLEBeacon.h” must be included to use the class function.
## **iBeacon::getRSSI** / **altBeacon::getRSSI**[](#ibeacon-getrssi-altbeacon-getrssi)
### **Description**[](#id31)
Get the current received signal strength indicator (RSSI) value.
### **Syntax**[](#id32)
int8_t getRSSI(void);
### **Parameters**[](#id33)
NA
### **Returns**[](#id34)
This function returns an 8-bit signed integer containing the currently set RSSI value.
### **Example Code**[](#id35)
NA
Note
The beacon RSSI value is the received signal strength at 1 meter. This can be used to estimate the distance to the beacon. Refer to [https://developer.apple.com/ibeacon/](https://developer.apple.com/ibeacon/) or [https://altbeacon.org/](https://altbeacon.org/) for more information. “BLEBeacon.h” must be included to use the class function.
## **iBeacon::setManufacturerId** / **altBeacon::setManufacturerId**[](#ibeacon-setmanufacturerid-altbeacon-setmanufacturerid)
### **Description**[](#id36)
Set Manufacturer ID value.
### **Syntax**[](#id37)
void setManufacturerId(uint16_t id);
### **Parameters**[](#id38)
id: desired Manufacturer ID
### **Returns**[](#id39)
NA
### **Example Code**[](#id40)
Example: [BLEBeacon](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBeacon/BLEBeacon.ino)
Note
Refer to [https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers/](https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers/) for the full list of assigned Bluetooth company identifiers. “BLEBeacon.h” must be included to use the class function.
## **iBeacon::setUUID** / **altBeacon::setUUID**[](#ibeacon-setuuid-altbeacon-setuuid)
### **Description**[](#id41)
Set UUID value.
### **Syntax**[](#id42)
void setUUID(uint8_t* UUID);
void setUUID(const char* UUID);
### **Parameters**[](#id43)
uint8_t* UUID: Provide pointer to a 16 element uint8_t array containing the desired UUID.
const char* UUID: desired UUID expressed as a character string.
### **Returns**[](#id44)
NA
### **Example Code**[](#id45)
Example: [BLEBeacon](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBeacon/BLEBeacon.ino)
Note
UUID is a 128-bit number used to uniquely identify a beacon. It is commonly expressed as a 32-character hexadecimal string. UUIDs can be generated at [https://www.uuidgenerator.net/](https://www.uuidgenerator.net/). “BLEBeacon.h” must be included to use the class function.
## **iBeacon::setMajor** / **altBeacon::setMajor**[](#ibeacon-setmajor-altbeacon-setmajor)
### **Description**[](#id47)
Set Major value for customizing beacons.
### **Syntax**[](#id48)
void setMajor(uint16_t major);
### **Parameters**[](#id49)
major: desired Major value
### **Returns**[](#id50)
NA
### **Example Code**[](#id51)
Example: [BLEBeacon](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBeacon/BLEBeacon.ino)
Note
Major and Minor are values used for customizing beacons. These can be set to any value. Refer to [https://developer.apple.com/ibeacon/](https://developer.apple.com/ibeacon/) or [https://altbeacon.org/](https://altbeacon.org/) for more information. “BLEBeacon.h” must be included to use the class function.
## **iBeacon::setMinor** / **altBeacon::setMinor**[](#ibeacon-setminor-altbeacon-setminor)
### **Description**[](#id53)
Set Minor value for customizing beacons.
### **Syntax**[](#id54)
void setMinor(uint16_t minor);
### **Parameters**[](#id55)
minor: desired Minor value
### **Returns**[](#id56)
NA
### **Example Code**[](#id57)
Example: [BLEBeacon](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBeacon/BLEBeacon.ino)
Note
Major and Minor are values used for customizing beacons. These can be set to any value. Refer to [https://developer.apple.com/ibeacon/](https://developer.apple.com/ibeacon/) or [https://altbeacon.org/](https://altbeacon.org/) for more information. “BLEBeacon.h” must be included to use the class function.
## **iBeacon::setRSSI** / **altBeacon::setRSSI**[](#ibeacon-setrssi-altbeacon-setrssi)
### **Description**[](#id59)
Set RSSI value.
### **Syntax**[](#id60)
### **Parameters**[](#id61)
RSSI: desired RSSI value
### **Returns**[](#id62)
NA
### **Example Code**[](#id63)
Example: [BLEBeacon](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBeacon/BLEBeacon.ino)
Note
The beacon RSSI value is the received signal strength at 1 meter. This can be used to estimate the distance to the beacon. Refer to [https://developer.apple.com/ibeacon/](https://developer.apple.com/ibeacon/) or [https://altbeacon.org/](https://altbeacon.org/) for more information. “BLEBeacon.h” must be included to use the class function.
## **iBeacon::getAdvData** / **altBeacon::getAdvData**[](#ibeacon-getadvdata-altbeacon-getadvdata)
### **Description**[](#id65)
Get current beacon advertising data.
### **Syntax**[](#id66)
uint8_t* getAdvData(void);
### **Parameters**[](#id67)
NA
### **Returns**[](#id68)
This function returns a uint8_t pointer to the structure containing beacon advertising data.
### **Example Code**[](#id69)
NA
Note
Avoid changing the beacon data through the returned pointer, use the member functions instead. “BLEBeacon.h” must be included to use the class function.
## **iBeacon::getScanRsp** / **altBeacon::getScanRsp**[](#ibeacon-getscanrsp-altbeacon-getscanrsp)
### **Description**[](#id70)
Get current beacon advertising scan response data.
### **Syntax**[](#id71)
uint8_t* getScanRsp(void);
### **Parameters**[](#id72)
NA
### **Returns**[](#id73)
This function returns a uint8_t pointer to the structure containing beacon advertising scan response data.
### **Example Code**[](#id74)
NA
Note
Avoid changing the beacon data through the returned pointer, use the member functions instead. “BLEBeacon.h” must be included to use the class function.
## **altBeacon::getRSVD**[](#altbeacon-getrsvd)
### **Description**[](#id75)
Get current Reserved value.
### **Syntax**[](#id76)
uint8_t getRSVD(void);
### **Parameters**[](#id77)
NA
### **Returns**[](#id78)
This function returns an 8-bit unsigned integer containing the current Reserved value.
### **Example Code**[](#id79)
NA
Note
Reserved for use by the manufacturer to implement special features. The interpretation of this value is to be defined by the manufacturer and is to be evaluated based on the MFG ID value. Refer to [https://altbeacon.org/](https://altbeacon.org/) for more information. “BLEBeacon.h” must be included to use the class function.
## **altBeacon::setRSVD**[](#altbeacon-setrsvd)
### **Description**[](#id80)
Set Reserved value.
### **Syntax**[](#id81)
void setRSVD(uint8_t rsvd);
### **Parameters**[](#id82)
rsvd: desired Reserved value
### **Returns**[](#id83)
NA
### **Example Code**[](#id84)
NA
Note
Reserved for use by the manufacturer to implement special features. The interpretation of this value is to be defined by the manufacturer and is to be evaluated based on the MFG ID value. Refer to [https://altbeacon.org/](https://altbeacon.org/) for more information. “BLEBeacon.h” must be included to use the class function.
[ Previous](Class%20BLEAdvertData.html)
[Next ](Class%20BLECharacteristic.html)
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