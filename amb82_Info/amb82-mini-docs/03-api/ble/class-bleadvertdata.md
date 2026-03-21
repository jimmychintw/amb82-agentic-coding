Class BLEAdvertData — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEAdvertData
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEAdvertData.rst)
# Class BLEAdvertData[](#class-bleadvertdata)
## **BLEAdvertData Class**[](#bleadvertdata-class)
### **Description**[](#description)
A class used for managing BLE advertising data.
### **Syntax**[](#syntax)
class BLEAdvertData
### **Members**[](#members)
|**Public Constructors**
|
|
| BLEAdvertData::BLEAdvertData
|
Constructs a BLEAdvertData object
|
|
| **Public Methods**
|
|
| BLEAdvertData::clear
|
Clear all advertising data.
|
|
| BLEAdvertData::addData
|
Add binary data to advertising
data packet.
|
|
| BLEAdvertData::addFlags
|
Add flags to advertising data
packet.
|
|
| BLEAdvertData::addPartialServices
|
Add partial list of service UUIDs
to advertising data packet.
|
|
| BLEAdvertData::
addCompleteServices
|
Add complete service UUIDs to
advertising data packet.
|
|
| BLEAdvertData::addAppearance
|
Add device appearance to
advertising data packet.
|
|
| BLEAdvertData::addShortName
|
Add shortened device name to
advertising data packet.
|
|
| BLEAdvertData::addCompleteName
|
Add complete device name to
advertising data packet.
|
|
| BLEAdvertData::parseScanInfo
|
Parse advertising data packets
received from a scan.
|
|
| BLEAdvertData::hasFlags
|
Check if received data includes
advertising flags.
|
|
| BLEAdvertData::hasUUID
|
Check if received data includes
service UUIDs.
|
|
| BLEAdvertData::hasName
|
Check if received data includes
device name.
|
|
| BLEAdvertData::hasManufacturer
|
Check if received data includes
manufacturer data.
|
|
| BLEAdvertData::getAdvType
|
Get advertising type of received
data.
|
|
| BLEAdvertData::getAddrType
|
Get Bluetooth address type of
received data.
|
|
| BLEAdvertData::getAddr
|
Get Bluetooth address of received
data.
|
|
| BLEAdvertData::getRSSI
|
Get received signal strength
indicator (RSSI) of received data.
|
|
| BLEAdvertData::getFlags
|
Get advertising flags of received
data
|
|
| BLEAdvertData::getServiceCount
|
Get the total number of advertised
services in the received data.
|
|
| BLEAdvertData::getServiceList
|
Get a list of advertised service
UUIDs in received data.
|
|
| BLEAdvertData::getName
|
Get advertised device name in
received data.
|
|
| BLEAdvertData::getTxPower
|
Get the advertised transmission
power from received data.
|
|
| BLEAdvertData::getAppearance
|
Get advertised device appearance
in received data.
|
|
| BLEAdvertData::getManufacturer
|
Get advertised manufacturer in
received data.
|
|
| BLEAdvertData::
getManufacturerDataLength
|
Get length of manufacturer data in
received data.
|
|
| BLEAdvertData::
getManufacturerData
|
Get advertised manufacturer data
in received data.
|
|
## **BLEAdvertData::BLEAdvertData**[](#bleadvertdata-bleadvertdata)
### **Description**[](#id1)
Constructs a BLEAdvertData object.
### **Syntax**[](#id2)
BLEAdvertData(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
NA
Note
This class is used for managing BLE advertising data for two primary uses. First is to assemble advertising data for broadcasting as advertising packets. Second is to process and split up the advertising data received from a scan into separate types. “BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::clear**[](#bleadvertdata-clear)
### **Description**[](#id3)
Clear all advertising data.
### **Syntax**[](#id4)
void clear(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::addData**[](#bleadvertdata-adddata)
### **Description**[](#id8)
Add binary data to advertising data packet.
### **Syntax**[](#id9)
void addData(const uint8_t* data, uint8_t size);
### **Parameters**[](#id10)
data: pointer to array containing desired advertising data.
size: number of bytes in the array.
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
NA
Note
This function is provided for flexibility in adding BLE advertising data. Other functions should be used for adding advertising data, if possible, as this function does not perform any checks on the validity of the data. “BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::addFlags**[](#bleadvertdata-addflags)
### **Description**[](#id13)
Add flags to advertising data packet.
### **Syntax**[](#id14)
uint8_t addFlags(uint8_t flags);
### **Parameters**[](#id15)
flags: desired flags to add to advertising data. Default value is (GAP_ADTYPE_FLAGS_LIMITED | GAP_ADTYPE_FLAGS_BREDR_NOT_SUPPORTED).
- GAP_ADTYPE_FLAGS_LIMITED (LE Limited Discoverable Mode
- GAP_ADTYPE_FLAGS_GENERAL (LE General Discoverable Mode)
- GAP_ADTYPE_FLAGS_BREDR_NOT_SUPPORTED (BR/EDR Not Supported)
- GAP_ADTYPE_FLAGS_SIMULTANEOUS_LE_BREDR_CONTROLLER (Simultaneous LE and BR/EDR Controller Supported)
- GAP_ADTYPE_FLAGS_SIMULTANEOUS_LE_BREDR_HOST (Simultaneous LE and BR/EDR Host Supported)
### **Returns**[](#id16)
This function returns the current total size of advertising data.
### **Example Code**[](#id17)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::addPartialServices**[](#bleadvertdata-addpartialservices)
### **Description**[](#id18)
Add partial list of service UUIDs to advertising data packet.
### **Syntax**[](#id19)
uint8_t addPartialServices(BLEUUID uuid);
### **Parameters**[](#id20)
uuid: the desired UUID contained in BLEUUID class object.
### **Returns**[](#id21)
This function returns the current total size of the advertising data.
### **Example Code**[](#id22)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData:: addCompleteServices**[](#bleadvertdata-addcompleteservices)
### **Description**[](#id23)
Add complete list of service UUIDs to advertising data packet.
### **Syntax**[](#id24)
uint8_t addCompleteServices(BLEUUID uuid);
uint8_t addCompleteServices(uint8_t uuidBitLength);
### **Parameters**[](#id25)
uuid: the desired UUID contained in BLEUUID class object.
uuidBitLength: UUID bit length for which a blank entry is to be added.
- 
- 
- 
**Returns**
This function returns the current total size of the advertising data.
**Example Code**
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
uuidBitLength is used when a blank entry in the advertisement data is required to be present. It is to indicate that no services with UUIDs of a certain length are available. “BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::addAppearance**[](#bleadvertdata-addappearance)
### **Description**[](#id27)
Add device appearance to advertising data.
### **Syntax**[](#id28)
uint8_t addAppearance(uint16_t appearance);
### **Parameters**[](#id29)
appearance: the desired device appearance.
### **Returns**[](#id30)
This function returns the current total size of the advertising data.
### **Example Code**[](#id31)
Example: [BLEHIDGamepad](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDGamepad/BLEHIDGamepad.ino)
Note
Refer to “gap_le_types.h” or Bluetooth specifications for a full list of device appearance values. “BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::addShortName**[](#bleadvertdata-addshortname)
### **Description**[](#id32)
Add shortened device name to advertising data packet.
### **Syntax**[](#id33)
uint8_t addShortName(const char* str);
### **Parameters**[](#id34)
str: character string containing desired short device name.
### **Returns**[](#id35)
This function returns the current total size of the advertising data.
### **Example Code**[](#id36)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::addCompleteName**[](#bleadvertdata-addcompletename)
### **Description**[](#id37)
Add complete device name to advertising data packet.
### **Syntax**[](#id38)
uint8_t addCompleteName(const char* str);
### **Parameters**[](#id39)
str: character string containing desired device name.
### **Returns**[](#id40)
This function returns the current total size of the advertising data.
### **Example Code**[](#id41)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::parseScanInfo**[](#bleadvertdata-parsescaninfo)
### **Description**[](#id43)
Parse advertising data packets received from a scan.
### **Syntax**[](#id44)
void parseScanInfo(T_LE_CB_DATA *p_data);
### **Parameters**[](#id45)
p_data: pointer to advertising data received from a Bluetooth scan.
### **Returns**[](#id46)
NA
### **Example Code**[](#id47)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
The information of the received data from advertising data can be accessed using the member functions starting with “has” and “get”. “BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::hasFlags**[](#bleadvertdata-hasflags)
### **Description**[](#id48)
Check if received data includes advertising flags.
### **Syntax**[](#id49)
bool hasFlags(void);
### **Parameters**[](#id50)
NA
### **Returns**[](#id51)
This function returns true if flags are present in received advertising data.
### **Example Code**[](#id52)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::hasUUID**[](#bleadvertdata-hasuuid)
### **Description**[](#id53)
Check if received data includes service UUIDs.
### **Syntax**[](#id54)
bool hasUUID(void);
### **Parameters**[](#id55)
NA
### **Returns**[](#id56)
This function returns true if service UUIDs are present in received advertising data.
### **Example Code**[](#id57)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::hasName**[](#bleadvertdata-hasname)
### **Description**[](#id58)
Check if received data includes device name.
### **Syntax**[](#id59)
bool hasName(void);
### **Parameters**[](#id60)
NA
### **Returns**[](#id61)
This function returns true if device name is present in received advertising data.
### **Example Code**[](#id62)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::hasManufacturer**[](#bleadvertdata-hasmanufacturer)
### **Description**[](#id64)
Check if received data includes manufacturer data.
### **Syntax**[](#id65)
bool hasManufacturer(void);
### **Parameters**[](#id66)
NA
### **Returns**[](#id67)
This function returns true if manufacturer data is present in the received advertising data.
### **Example Code**[](#id68)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getAdvType**[](#bleadvertdata-getadvtype)
### **Description**[](#id69)
Get advertising type of received data.
### **Syntax**[](#id70)
T_GAP_ADV_EVT_TYPE getAdvType(void);
### **Parameters**[](#id71)
NA
### **Returns**[](#id72)
This function returns the advertising type of received advertising data.
### **Example Code**[](#id73)
NA
Note
Possible types:
- GAP_ADV_EVT_TYPE_UNDIRECTED
- GAP_ADV_EVT_TYPE_DIRECTED
- GAP_ADV_EVT_TYPE_SCANNABLE
- GAP_ADV_EVT_TYPE_NON_CONNECTABLE
- GAP_ADV_EVT_TYPE_SCAN_RSP
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getAddrType**[](#bleadvertdata-getaddrtype)
### **Description**[](#id74)
Get Bluetooth address type of received data.
### **Syntax**[](#id75)
T_GAP_REMOTE_ADDR_TYPE getAddrType(void);
### **Parameters**[](#id76)
NA
### **Returns**[](#id77)
This function returns the Bluetooth address type of received data.
### **Example Code**[](#id78)
NA
Note
Possible types:
- GAP_REMOTE_ADDR_LE_PUBLIC
- GAP_REMOTE_ADDR_LE_RANDOM
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getRSSI**[](#bleadvertdata-getrssi)
### **Description**[](#id79)
Get received signal strength indicator (RSSI) of received data.
### **Syntax**[](#id80)
Int8_t getRSSI(void);
### **Parameters**[](#id81)
NA
### **Returns**[](#id82)
This function returns the received signal strength.
### **Example Code**[](#id83)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getFlags**[](#bleadvertdata-getflags)
### **Description**[](#id84)
Get advertising flags of received data.
### **Syntax**[](#id85)
uint8_t getFlags(void);
### **Parameters**[](#id86)
NA
### **Returns**[](#id87)
This function returns a single byte containing the advertising flags found in received advertising data.
### **Example Code**[](#id88)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getServiceCount**[](#bleadvertdata-getservicecount)
### **Description**[](#id89)
Get the total number of advertised services in the received data.
### **Syntax**[](#id90)
uint8_t getServiceCount(void);
### **Parameters**[](#id91)
NA
### **Returns**[](#id92)
This function returns the number of advertised service UUIDs in received data.
### **Example Code**[](#id93)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getServiceList**[](#bleadvertdata-getservicelist)
### **Description**[](#id95)
Get a list of advertised service UUIDs in received data.
### **Syntax**[](#id96)
BLEUUID* getServiceList(void);
### **Parameters**[](#id97)
NA
### **Returns**[](#id98)
This function returns a pointer to a BLEUUID array containing all advertised service UUIDs.
### **Example Code**[](#id99)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getName**[](#bleadvertdata-getname)
### **Description**[](#id101)
Get advertised device name in received data.
### **Syntax**[](#id102)
String getName(void);
### **Parameters**[](#id103)
NA
### **Returns**[](#id104)
This function returns advertised device name contained in a String class object.
### **Example Code**[](#id105)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getTxPower**[](#bleadvertdata-gettxpower)
### **Description**[](#id107)
Get the advertised transmission power of the received data.
### **Syntax**[](#id108)
int8_t getTxPower(void);
### **Parameters**[](#id109)
NA
### **Returns**[](#id110)
This function returns advertised transmission power of the received data.
### **Example Code**[](#id111)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getAppearance**[](#bleadvertdata-getappearance)
### **Description**[](#id112)
Get advertised device appearance in received data.
### **Syntax**[](#id113)
uint16_t getAppearance(void);
### **Parameters**[](#id114)
NA
### **Returns**[](#id115)
This function returns advertised device appearance of the received data.
### **Example Code**[](#id116)
NA
Note
Refer to “gap_le_types.h” or Bluetooth specifications for full list of device appearance values. “BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getManufacturer**[](#bleadvertdata-getmanufacturer)
### **Description**[](#id117)
Get advertised manufacturer in received data.
### **Syntax**[](#id118)
uint16_t getManufacturer(void);
### **Parameters**[](#id119)
NA
### **Returns**[](#id120)
This function returns advertised manufacturer of the received data.
### **Example Code**[](#id121)
NA
Note
Refer to Bluetooth specifications for full list of manufacturer codes. “BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getManufacturerDataLength**[](#bleadvertdata-getmanufacturerdatalength)
### **Description**[](#id122)
Get length of manufacturer data in received data.
### **Syntax**[](#id123)
uint8_t getManufacturerDataLength(void);
### **Parameters**[](#id124)
NA
### **Returns**[](#id125)
This function returns the number of bytes of manufacturer data present in received advertising data.
### **Example Code**[](#id126)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
## **BLEAdvertData::getManufacturerData**[](#bleadvertdata-getmanufacturerdata)
### **Description**[](#id127)
Get manufacturer data in received data.
### **Syntax**[](#id128)
uint8_t* getManufacturerData(void);
### **Parameters**[](#id129)
NA
### **Returns**[](#id130)
This function returns a pointer to an array containing manufacturer data.
### **Example Code**[](#id131)
NA
Note
“BLEAdvertData.h” must be included to use the class function.
[ Previous](Class%20BLEAdvert.html)
[Next ](Class%20BLEBeacon.html)
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