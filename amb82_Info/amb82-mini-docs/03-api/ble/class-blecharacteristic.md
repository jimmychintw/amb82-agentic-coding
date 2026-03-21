Class BLECharacteristic — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLECharacteristic
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLECharacteristic.rst)
# Class BLECharacteristic[](#class-blecharacteristic)
## **BLECharacteristic Class**[](#blecharacteristic-class)
### **Description**[](#description)
A class used for creating and managing BLE GATT characteristics.
### **Syntax**[](#syntax)
class BLECharacteristic
### **Members**[](#members)
|**Public Constructors**
|
|
| BLECharacteristic::BLECharacteristic
|
Constructs a BLECharacteristic
object
|
|
| **Public Methods**
|
|
| BLECharacteristic::setUUID
|
Set the UUID of the
characteristic.
|
|
| BLECharacteristic::getUUID
|
Get the UUID of the
characteristic.
|
|
| BLECharacteristic::setBufferLen
|
Set the size of the internal
data buffer
|
|
| BLECharacteristic::getBufferLen
|
Get the current size of the
internal data buffer
|
|
| BLECharacteristic::setReadProperty
|
Set the Read property value
|
|
| BLECharacteristic::setWriteProperty
|
Set the Write property value
|
|
| BLECharacteristic::setWriteNRProperty
|
Set the write without response
property value
|
|
| BLECharacteristic::setNotifyProperty
|
Set the Notify property value
|
|
| BLECharacteristic::setIndicateProperty
|
Set the Indicate property value
|
|
| BLECharacteristic::setProperties
|
Set the characteristic properties
|
|
| BLECharacteristic::getProperties
|
Get the characteristic properties
|
|
| BLECharacteristic::setReadPermissions
|
Set the characteristic read
permissions
|
|
| BLECharacteristic::setWritePermissions
|
Set the characteristic write
permissions
|
|
| BLECharacteristic::setPermissions
|
Set the characteristic
permissions
|
|
| BLECharacteristic::getPermissions
|
Get the characteristic
permissions
|
|
| BLECharacteristic::readString
|
Read the characteristic data
buffer as a String object
|
|
| BLECharacteristic::readData8
|
Read the characteristic data
buffer as an unsigned 8-bit
integer
|
|
| BLECharacteristic::readData16
|
Read the characteristic data
buffer as an unsigned 16-bit
integer
|
|
| BLECharacteristic::readData32
|
Read the characteristic data
buffer as an unsigned 32-bit
integer
|
|
| BLECharacteristic::writeString
|
Write data to the characteristic
data buffer as a String object or
character array
|
|
| BLECharacteristic::writeData8
|
Write data to the
characteristic data buffer as
an unsigned 8-bit integer
|
|
| BLECharacteristic::writeData16
|
Write data to the
characteristic data buffer as
an unsigned 16-bit integer
|
|
| BLECharacteristic::writeData32
|
Write data to the
characteristic data buffer as
an unsigned 16-bit integer
|
|
| BLECharacteristic::setData
|
Write data to the
characteristic data buffer
|
|
| BLECharacteristic::getData
|
Read data from the
characteristic data buffer
|
|
| BLECharacteristic::getDataBuff
|
Get a pointer to the
characteristic data buffer
|
|
| BLECharacteristic::getDataLen
|
Get the length of data (in
bytes) in the characteristic
data buffer.
|
|
| BLECharacteristic::notify
|
Send a notification to a
connected device
|
|
| BLECharacteristic::indicate
|
Send an indication to a
connected device
|
|
| BLECharacteristic::setUserDescriptor
|
Add a user description
descriptor to characteristic
|
|
| BLECharacteristic::setFormatDescriptor
|
Add a data format descriptor to
characteristic
|
|
| BLECharacteristic::setReportRefDescriptor
|
Add a report reference
descriptor to a characteristic
|
|
| BLECharacteristic::getReportRefID
|
Get the previously set report
reference descriptor ID
|
|
| BLECharacteristic::getReportRefType
|
Get the previously set report
reference descriptor type
|
|
| BLECharacteristic::setReadCallback
|
Set a user function as a read
callback
|
|
| BLECharacteristic::setWriteCallback
|
Set a user function as a write
callback
|
|
| BLECharacteristic::setCCCDCallback
|
Set a user function as a CCCD
write callback
|
|
## **BLECharacteristic::BLECharacteristic**[](#blecharacteristic-blecharacteristic)
### **Description**[](#id1)
Constructs a BLECharacteristic object.
### **Syntax**[](#id2)
BLECharacteristic::BLECharacteristic(BLEUUID uuid);
BLECharacteristic::BLECharacteristic(const char* uuid);
### **Parameters**[](#parameters)
uuid: characteristic UUID, expressed as a BLEUUID class object or a character array
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setUUID**[](#blecharacteristic-setuuid)
### **Description**[](#id3)
Set the UUID of the characteristic.
### **Syntax**[](#id4)
void setUUID(BLEUUID uuid);
### **Parameters**[](#id5)
uuid: new UUID for the characteristic, expressed as a BLEUUID class object.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::getUUID**[](#blecharacteristic-getuuid)
### **Description**[](#id8)
Get the UUID of the characteristic.
### **Syntax**[](#id9)
BLEUUID getUUID(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
The function returns the UUID of the characteristic in a BLEUUID class object.
### **Example Code**[](#id12)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setBufferLen**[](#blecharacteristic-setbufferlen)
### **Description**[](#id13)
Set the size of the internal data buffer of the characteristic.
### **Syntax**[](#id14)
void setBufferLen(uint16_t max_len);
### **Parameters**[](#id15)
max_len: the number of bytes that the internal buffer will be resized to
### **Returns**[](#id16)
NA
### **Example Code**[](#id17)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
Characteristic data buffer has a default size of 20 bytes and can be increased up to 230 bytes. “BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::getBufferLen**[](#blecharacteristic-getbufferlen)
### **Description**[](#id19)
Get the current size of the internal data buffer of the characteristic.
### **Syntax**[](#id20)
uint16_t getBufferLen(void);
### **Parameters**[](#id21)
NA
### **Returns**[](#id22)
The function returns the currently set internal buffer size.
### **Example Code**[](#id23)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setReadProperty**[](#blecharacteristic-setreadproperty)
### **Description**[](#id24)
Set the Read property value of the characteristic.
### **Syntax**[](#id25)
void setReadProperty(bool value);
### **Parameters**[](#id26)
value: To allow connected devices to read characteristic’s data.
- true.
- false.
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setWriteProperty**[](#blecharacteristic-setwriteproperty)
### **Description**[](#id29)
Set the Write property value of the characteristic.
### **Syntax**[](#id30)
void setWriteProperty(bool value);
### **Parameters**[](#id31)
value: To allow connected devices to write characteristic data.
- true.
- false.
### **Returns**[](#id32)
NA
### **Example Code**[](#id33)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setWriteNRProperty**[](#blecharacteristic-setwritenrproperty)
### **Description**[](#id35)
Set the write without response property value of the characteristic.
### **Syntax**[](#id36)
void setWriteNRProperty(bool value);
### **Parameters**[](#id37)
value: To allow connected devices to write characteristic data with no response.
- true.
- false.
### **Returns**[](#id38)
NA
### **Example Code**[](#id39)
NA
Note
“BLECharacteristic.h” must be included to use the class function.**
## **BLECharacteristic::setNotifyProperty**[](#blecharacteristic-setnotifyproperty)
### **Description**[](#id40)
Set the Notify property of the characteristic.
### **Syntax**[](#id41)
void setNotifyProperty(bool value);
### **Parameters**[](#id42)
value: To allow connected devices to receive characteristic data notification messages.
- true.
- false.
### **Returns**[](#id43)
NA
### **Example Code**[](#id44)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
Enabling this property will add a CCCD descriptor to the characteristic. “BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setIndicateProperty**[](#blecharacteristic-setindicateproperty)
### **Description**[](#id46)
Set the Indicate property value of characteristic.
### **Syntax**[](#id47)
void setIndicateProperty(bool value);
### **Parameters**[](#id48)
value: To allow connected devices to receive characteristic data indication messages.
- true.
- false.
### **Returns**[](#id49)
NA
### **Example Code**[](#id50)
NA
Note
Enabling this property will add a CCCD descriptor to the characteristic. “BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setProperties**[](#blecharacteristic-setproperties)
### **Description**[](#id51)
Set the characteristic properties.
### **Syntax**[](#id52)
void setProperties(uint8_t value);
### **Parameters**[](#id53)
value: desired characteristic properties. Default value is 0x00 (no properties)
### **Returns**[](#id54)
NA
### **Example Code**[](#id55)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::getProperties**[](#blecharacteristic-getproperties)
### **Description**[](#id56)
Get characteristic properties that is currently set.
### **Syntax**[](#id57)
uint8_t getProperties(void);
### **Parameters**[](#id58)
NA
### **Returns**[](#id59)
This function returns the currently set characteristic properties expressed as an unsigned 8-bit integer.
### **Example Code**[](#id60)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setReadPermissions**[](#blecharacteristic-setreadpermissions)
### **Description**[](#id61)
Set the characteristic read permissions.
### **Syntax**[](#id62)
void setReadPermissions(uint32_t value);
### **Parameters**[](#id63)
value: desired characteristic read permissions.
- GATT_PERM_READ
- GATT_PERM_READ_AUTHEN_REQ
- GATT_PREM_READ_AUTHOR_REQ
- GATT_PERM_READ_ENCRYPTED_REQ
- GATT_PERM_READ_AUTHEN_SC_REQ
### **Returns**[](#id64)
NA
### **Example Code**[](#id65)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
If no permissions are set, the default permission is GATT_PERM_NONE. “BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setWritePermissions**[](#blecharacteristic-setwritepermissions)
### **Description**[](#id67)
Set the characteristic write permissions.
### **Syntax**[](#id68)
void setWritePermissions(uint32_t value);
### **Parameters**[](#id69)
value: desired characteristic write permissions.
- GATT_PERM_WRITE
- GATT_PERM_WRITE_AUTHEN_REQ
- GATT_PREM_WRITE_AUTHOR_REQ
- GATT_PERM_WRITE_ENCRYPTED_REQ
- GATT_PERM_WRITE_AUTHEN_SC_REQ
### **Returns**[](#id70)
NA
### **Example Code**[](#id71)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
If no permissions are set, the default permission is GATT_PERM_NONE. “BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setPermissions**[](#blecharacteristic-setpermissions)
### **Description**[](#id73)
Set the characteristic permissions.
### **Syntax**[](#id74)
void setPermissions(uint32_t value);
### **Parameters**[](#id75)
value: desired characteristic permissions.
- GATT_PERM_READ
- GATT_PERM_READ_AUTHEN_REQ
- GATT_PREM_READ_AUTHOR_REQ
- GATT_PERM_READ_ENCRYPTED_REQ
- GATT_PERM_READ_AUTHEN_SC_REQ
- GATT_PERM_WRITE
- GATT_PERM_WRITE_AUTHEN_REQ
- GATT_PREM_WRITE_AUTHOR_REQ
- GATT_PERM_WRITE_ENCRYPTED_REQ
- GATT_PERM_WRITE_AUTHEN_SC_REQ
### **Returns**[](#id76)
NA
### **Example Code**[](#id77)
NA
Note
If no permissions are set, the default permission is GATT_PERM_NONE. “BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::getPermissions**[](#blecharacteristic-getpermissions)
### **Description**[](#id78)
Get the characteristic permissions.
### **Syntax**[](#id79)
uint32_t getPermissions(void);
### **Parameters**[](#id80)
NA
### **Returns**[](#id81)
This function returns the characteristic permissions that are previously set using the setReadPermissions, setWritePermissions and setPermissions functions.
### **Example Code**[](#id82)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::readString**[](#blecharacteristic-readstring)
### **Description**[](#id83)
Read the characteristic data buffer as a String object.
### **Syntax**[](#id84)
String readString(void);
### **Parameters**[](#id85)
NA
### **Returns**[](#id86)
The function returns the data in the characteristic internal buffer as a String class object.
### **Example Code**[](#id87)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
Non-ASCII data may result in unexpected characters in the string. “BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::readData8**[](#blecharacteristic-readdata8)
### **Description**[](#id89)
Read the data in the characteristic internal buffer, expressed as an unsigned 8-bit integer.
### **Syntax**[](#id90)
uint8_t readData8(void);
### **Parameters**[](#id91)
NA
### **Returns**[](#id92)
This function returns the data in the characteristic internal buffer expressed as a uint8_t value.
### **Example Code**[](#id93)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::readData16**[](#blecharacteristic-readdata16)
### **Description**[](#id94)
Read the data in the characteristic internal buffer, expressed as an unsigned 16-bit integer.
### **Syntax**[](#id95)
uint16_t readData16(void);
### **Parameters**[](#id96)
NA
### **Returns**[](#id97)
This function returns the data in the characteristic internal buffer expressed as a uint16_t value.
### **Example Code**[](#id98)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::readData32**[](#blecharacteristic-readdata32)
### **Description**[](#id99)
Read the data in the characteristic internal buffer, expressed as an unsigned 32-bit integer.
### **Syntax**[](#id100)
uint32_t readData32(void);
### **Parameters**[](#id101)
NA
### **Returns**[](#id102)
This function returns the data in the characteristic internal buffer expressed as a uint32_t value.
### **Example Code**[](#id103)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::writeString**[](#blecharacteristic-writestring)
### **Description**[](#id104)
Write data to the characteristic data buffer as a String object or character array.
### **Syntax**[](#id105)
bool writeString(String str);
bool writeString(const char* str);
### **Parameters**[](#id106)
str: the data to write to the characteristic buffer, expressed as a String class object or a char array.
### **Returns**[](#id107)
This function returns TRUE if write data is successful.
### **Example Code**[](#id108)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::writeData8**[](#blecharacteristic-writedata8)
### **Description**[](#id110)
Write data to the characteristic data buffer as an unsigned 8-bit integer.
### **Syntax**[](#id111)
bool writeData8(uint8_t num);
### **Parameters**[](#id112)
num: the data to write to the characteristic buffer expressed as an unsigned 8-bit integer.
### **Returns**[](#id113)
This function returns TRUE if write data is successful.
### **Example Code**[](#id114)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::writeData16**[](#blecharacteristic-writedata16)
### **Description**[](#id116)
Write data to the characteristic data buffer as an unsigned 16-bit integer.
### **Syntax**[](#id117)
bool writeData16(uint16_t num);
### **Parameters**[](#id118)
num: the data to write to the characteristic buffer expressed as an unsigned 16-bit integer.
### **Returns**[](#id119)
This function returns TRUE if write data is successful.
### **Example Code**[](#id120)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::writeData32**[](#blecharacteristic-writedata32)
### **Description**[](#id121)
Write data to the characteristic data buffer as an unsigned 32-bit integer.
### **Syntax**[](#id122)
bool writeData32(uint32_t num);
bool writeData32(int num);
### **Parameters**[](#id123)
num: the data to write to the characteristic buffer expressed as a signed or unsigned 32-bit integer.
### **Returns**[](#id124)
This function returns TRUE if write data is successful.
### **Example Code**[](#id125)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setData**[](#blecharacteristic-setdata)
### **Description**[](#id126)
Write data to the characteristic data buffer.
### **Syntax**[](#id127)
bool setData(uint8_t* data, uint16_t datalen);
### **Parameters**[](#id128)
data: pointer to byte array containing desired data.
datalen: number of bytes of data to write.
### **Returns**[](#id129)
This function returns TRUE if write data is successful.
### **Example Code**[](#id130)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::getData**[](#blecharacteristic-getdata)
### **Description**[](#id131)
Read data from the characteristic data buffer.
### **Syntax**[](#id132)
uint16_t getData(uint8_t* data, uint16_t datalen);
### **Parameters**[](#id133)
data: pointer to byte array containing saved data from data buffer.
datalen: number of bytes of data to be read.
### **Returns**[](#id134)
This function returns the number of bytes read.
### **Example Code**[](#id135)
NA
Note
If the data buffer contains less data than requested, it will only read the available number of bytes of data. “BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::getDataBuff**[](#blecharacteristic-getdatabuff)
### **Description**[](#id136)
Get a pointer to the characteristic data buffer.
### **Syntax**[](#id137)
uint8_t* getDataBuff(void);
### **Parameters**[](#id138)
NA
### **Returns**[](#id139)
This function returns a pointer to the uint8_t array used as the characteristic internal buffer.
### **Example Code**[](#id140)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::getDataLen**[](#blecharacteristic-getdatalen)
### **Description**[](#id141)
Get the length of data (in bytes) in the characteristic data buffer.
### **Syntax**[](#id142)
uint16_t getDataLen(void);
### **Parameters**[](#id143)
NA
### **Returns**[](#id144)
This function returns the length of the last written data (in bytes) in the internal data buffer.
### **Example Code**[](#id145)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::notify**[](#blecharacteristic-notify)
### **Description**[](#id146)
Send a notification to a connected device.
### **Syntax**[](#id147)
void notify(uint8_t conn_id);
### **Parameters**[](#id148)
conn_id: the connection ID for the device to send a notification to.
### **Returns**[](#id149)
NA
**Example Code**
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::indicate**[](#blecharacteristic-indicate)
Send an indication to a connected device.
### **Syntax**[](#id151)
void indicate(uint8_t conn_id);
### **Parameters**[](#id152)
conn_id: the connection ID for the device to send an indication to.
### **Returns**[](#id153)
NA
### **Example Code**[](#id154)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setUserDescriptor**[](#blecharacteristic-setuserdescriptor)
### **Description**[](#id155)
Add a user description descriptor attribute (UUID 0x2901) to the characteristic.
### **Syntax**[](#id156)
void setUserDescriptor(const char* description);
### **Parameters**[](#id157)
description: the desired user description string expressed in a char array.
### **Returns**[](#id158)
NA
### **Example Code**[](#id159)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setFormatDescriptor**[](#blecharacteristic-setformatdescriptor)
### **Description**[](#id160)
Add a data format descriptor attribute (UUID 0x2904) to the characteristic.
### **Syntax**[](#id161)
void setFormatDescriptor(uint8_t format, uint8_t exponent, uint16_t unit, uint16_t description);
### **Parameters**[](#id162)
format: refer to [https://www.bluetooth.com/specifications/assigned-numbers/format-types/](https://www.bluetooth.com/specifications/assigned-numbers/format-types/) for the valid values and associated format types.
exponent: base-10 exponent to be applied to characteristic data value.
unit: refer to [https://btprodspecificationrefs.blob.core.windows.net/assigned-values/16-bit%20UUID%20Numbers%20Document.pdf](https://btprodspecificationrefs.blob.core.windows.net/assigned-values/16-bit%20UUID%20Numbers%20Document.pdf) for the valid values and associated units.
description: refer to [https://www.bluetooth.com/specifications/assigned-numbers/gatt-namespace-descriptors/](https://www.bluetooth.com/specifications/assigned-numbers/gatt-namespace-descriptors/) for the valid values and associated descriptors.
### **Returns**[](#id163)
NA
### **Example Code**[](#id164)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setReportRefDescriptor**[](#blecharacteristic-setreportrefdescriptor)
### **Description**[](#id165)
Add a HID report reference descriptor attribute (UUID 0x2908) to the characteristic.
### **Syntax**[](#id166)
void setReportRefDescriptor(uint8_t id, uint8_t type);
### **Parameters**[](#id167)
id: HID report reference ID
type: HID report type.
- 0x01 (input report)
- 0x02 (output report)
- 0x03 (feature report)
### **Returns**[](#id168)
NA
### **Example Code**[](#id169)
NA
Note
HID report reference ID should begin at 1. Some HID host systems may consider an ID of 0 as invalid. “BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::getReportRefID**[](#blecharacteristic-getreportrefid)
### **Description**[](#id170)
Get the previously set HID report reference descriptor ID.
### **Syntax**[](#id171)
uint8_t getReportRefID(void);
**Parameters**
NA
### **Returns**[](#id172)
This function returns the report reference ID previously set using the setReportRefDescriptor function.
### **Example Code**[](#id173)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::getReportRefType**[](#blecharacteristic-getreportreftype)
### **Description**[](#id174)
Get the previously set HID report reference descriptor type.
### **Syntax**[](#id175)
uint8_t getReportRefType(void);
### **Parameters**[](#id176)
NA
### **Returns**[](#id177)
This function returns the report reference type previously set using the setReportRefDescriptor function.
### **Example Code**[](#id178)
NA
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setReadCallback**[](#blecharacteristic-setreadcallback)
### **Description**[](#id179)
Set a user function to be called when the characteristic data is read by a connected device.
### **Syntax**[](#id180)
void setReadCallback(void (*fCallback) (BLECharacteristic* chr, uint8_t conn_id));
### **Parameters**[](#id181)
fCallback: A user callback function that returns void and takes two arguments.
chr: pointer to BLECharacteristic object containing data read.
conn_id: connection ID of connected device that read characteristic data.
### **Returns**[](#id182)
NA
### **Example Code**[](#id183)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setWriteCallback**[](#blecharacteristic-setwritecallback)
### **Description**[](#id185)
Set a user function to be called when the characteristic data is written by a connected device.
### **Syntax**[](#id186)
void setWriteCallback(void (*fCallback) (BLECharacteristic* chr, uint8_t conn_id));
### **Parameters**[](#id187)
fCallback: A user callback function that returns void and takes two arguments.
chr: pointer to BLECharacteristic object containing written data.
conn_id: connection ID of connected device that wrote characteristic data.
### **Returns**[](#id188)
NA
### **Example Code**[](#id189)
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
“BLECharacteristic.h” must be included to use the class function.
## **BLECharacteristic::setCCCDCallback**[](#blecharacteristic-setcccdcallback)
### **Description**[](#id191)
Set a user function to be called when a connected device modifies the characteristic CCCD to enable or disable notifications or indications.
### **Syntax**[](#id192)
void setCCCDCallback(void (*fCallback) (BLECharacteristic* chr, uint8_t conn_id, uint16_t ccc_bits));
### **Parameters**[](#id193)
fCallback: A user callback function that returns void and takes two arguments.
chr: pointer to BLECharacteristic object containing written data.
conn_id: connection ID of connected device that wrote characteristic data.
ccc_bits: the new CCCD data bits after modification by the connected device.
### **Returns**[](#id194)
NA
**Example Code**
Example: [BLEUartService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartService/BLEUartService.ino)
Note
“BLECharacteristic.h” must be included to use the class function.
[ Previous](Class%20BLEBeacon.html)
[Next ](Class%20BLEClient.html)
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