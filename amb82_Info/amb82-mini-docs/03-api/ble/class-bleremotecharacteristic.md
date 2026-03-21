Class BLERemoteCharacteristic — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLERemoteCharacteristic
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLERemoteCharacteristic.rst)
# Class BLERemoteCharacteristic[](#class-bleremotecharacteristic)
## **BLERemoteCharacteristic Class**[](#bleremotecharacteristic-class)
### **Description**[](#description)
A class used for managing BLE GATT characteristics on connected remote devices.
### **Syntax**[](#syntax)
class BLERemoteCharacteristic
### **Members**[](#members)
|**Public Constructors**
|
|
| No public constructor is available for this class. You can get a
pointer to an instance of this class using
BLERemoteService::getCharacteristic().
|
|
| **Public Methods**
|
|
| BLERemoteCharacteristic::
getDescriptor
|
Get a descriptor with the
specified UUID on the
remotedevice
|
|
| BLERemoteCharacteristic::getUUID
|
Get the characteristic UUID
|
|
| BLERemoteCharacteristic::
setBufferLen
|
Set the size of the internal
data buffer
|
|
| BLERemoteCharacteristic::
getBufferLen
|
Get the current size of the
internal data buffer
|
|
| BLERemoteCharacteristic::canRead
|
Determine if characteristic has
read property enabled
|
|
| BLERemoteCharacteristic::canWrite
|
Determine if characteristic has
write property enabled
|
|
| BLERemoteCharacteristic::canNotify
|
Determine if characteristic has
notify property enabled
|
|
| BLERemoteCharacteristic::
canIndicate
|
Determine if characteristic has
indicate property enabled
|
|
| BLERemoteCharacteris tic::
getProperties
|
Get the characteristic
properties
|
|
| BLERemoteCharacteristic::readString
|
Read the characteristic data
buffer as a String object
|
|
| BLERemoteCharacteristic::readData8
|
Read the characteristic data
buffer as an unsigned 8-bit
integer
|
|
| BLERemoteCharacteristic::readData16
|
Read the characteristic data
buffer as an unsigned 16-bit
integer
|
|
| BLERemoteCharacteristic::readData32
|
Read the characteristic data
buffer as an unsigned 32-bit
integer
|
|
| BLERemoteCharacteristic::
writeString
|
Write data to the
characteristic as a String
object or character array
|
|
| BLERemoteCharacteristic::writeData8
|
Write data to the
characteristic as an unsigned
8-bit integer
|
|
| BLERemoteCharacteristic::
writeData16
|
Write data to the
characteristic as an unsigned
16-bit integer
|
|
| BLERemoteCharacteristic::
writeData32
|
Write data to the
characteristic as an unsigned
32-bit integer
|
|
| BLERemoteCharacteristic::setData
|
Write data to the remote device
characteristic
|
|
| BLERemoteCharacteristic::getData
|
Get the characteristic data
from the remote device and read
the data in the buffer
|
|
| BLERemoteCharacteristic::
enableNotifyIndicate
|
Enable notification or
indication for the
characteristic
|
|
| BLERemoteCharacteristic::
disableNotifyIndicate
|
Disable notification and
indication for the
characteristic
|
|
| BLERemoteCharacteristic::
setNotifyCallback
|
Set a user function as a
notification callback
|
|
## **BLERemoteCharacteristic::getDescriptor**[](#bleremotecharacteristic-getdescriptor)
### **Description**[](#id1)
Get a descriptor with the specified UUID on the remote device.
### **Syntax**[](#id2)
BLERemoteDescriptor* getDescriptor(const char* uuid);
BLERemoteDescriptor* getDescriptor(BLEUUID uuid);
### **Parameters**[](#parameters)
uuid: the desired descriptor UUID, expressed as a character array or a BLEUUID object.
### **Returns**[](#returns)
This function returns the found descriptor as a BLERemoteDescriptor object pointer, otherwise nullptr is returned if a descriptor with the UUID is not found.
### **Example Code**[](#example-code)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::getUUID**[](#bleremotecharacteristic-getuuid)
### **Description**[](#id3)
Get the characteristic UUID.
### **Syntax**[](#id4)
BLEUUID getUUID(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
The function returns the characteristic UUID as a BLEUUID class object.
### **Example Code**[](#id7)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::setBufferLen**[](#bleremotecharacteristic-setbufferlen)
### **Description**[](#id8)
Set the size of the internal data buffer of the characteristic.
### **Syntax**[](#id9)
void setBufferLen(uint16_t max_len);
### **Parameters**[](#id10)
max_len: the size in bytes to resize the internal buffer to.
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
Example: [BLEUartClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartClient/BLEUartClient.ino)
Note
Characteristic data buffer has a default size of 20 bytes and can be increased up to 230 bytes. “BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::getBufferLen**[](#bleremotecharacteristic-getbufferlen)
### **Description**[](#id13)
Get the current size of the characteristic internal buffer.
### **Syntax**[](#id14)
uint16_t getBufferLen(void);
### **Parameters**[](#id15)
NA
### **Returns**[](#id16)
This function returns the current internal buffer size that is set.
### **Example Code**[](#id17)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the clas function.
## **BLERemoteCharacteristic::canRead**[](#bleremotecharacteristic-canread)
### **Description**[](#id18)
Determine if characteristic has read property enabled.
### **Syntax**[](#id19)
bool canRead(void);
### **Parameters**[](#id20)
NA
### **Returns**[](#id21)
This function returns TRUE if the read property for the characteristic is enabled.
### **Example Code**[](#id22)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::canWrite**[](#bleremotecharacteristic-canwrite)
### **Description**[](#id23)
Determine if characteristic has write property enabled.
### **Syntax**[](#id24)
bool canWrite(void);
### **Parameters**[](#id25)
NA
### **Returns**[](#id26)
This function returns TRUE if the write property or the write no response property for the characteristic is enabled.
### **Example Code**[](#id27)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::canNotify**[](#bleremotecharacteristic-cannotify)
### **Description**[](#id28)
Determine if characteristic has notify property enabled.
### **Syntax**[](#id29)
bool canNotify(void);
### **Parameters**[](#id30)
NA
### **Returns**[](#id31)
The function returns TRUE if the notify property for the characteristic is enabled.
### **Example Code**[](#id32)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::canIndicate**[](#bleremotecharacteristic-canindicate)
### **Description**[](#id33)
Determine if characteristic has indicate property enabled.
### **Syntax**[](#id34)
bool canIndicate(void);
### **Parameters**[](#id35)
NA
### **Returns**[](#id36)
The function returns TRUE if the indicate property for the characteristic is enabled.
### **Example Code**[](#id37)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::getProperties**[](#bleremotecharacteristic-getproperties)
### **Description**[](#id38)
Get the characteristic properties.
### **Syntax**[](#id39)
uint16_t getProperties(void);
### **Parameters**[](#id40)
NA
### **Returns**[](#id41)
The function returns the characteristic properties.
### **Example Code**[](#id42)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::readString**[](#bleremotecharacteristic-readstring)
### **Description**[](#id43)
Request for characteristic data from the remote device and read the data in the buffer, expressed as a String class object.
### **Syntax**[](#id44)
String readString(void);
### **Parameters**[](#id45)
NA
### **Returns**[](#id46)
The function returns the data in the characteristic data buffer expressed as a String class object.
### **Example Code**[](#id47)
Example: [BLEUartClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartClient/BLEUartClient.ino)
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::readData8**[](#bleremotecharacteristic-readdata8)
### **Description**[](#id49)
Request for characteristic data from the remote device and read the data in the buffer, expressed as an unsigned 8-bit integer.
### **Syntax**[](#id50)
uint8_t readData8(void);
### **Parameters**[](#id51)
NA
### **Returns**[](#id52)
This function returns the data in the characteristic data buffer expressed as a uint8_t value.
### **Example Code**[](#id53)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::readData16**[](#bleremotecharacteristic-readdata16)
### **Description**[](#id54)
Request for characteristic data from the remote device and read the data in the buffer, expressed as an unsigned 16-bit integer.
### **Syntax**[](#id55)
uint16_t readData16(void);
### **Parameters**[](#id56)
NA
### **Returns**[](#id57)
This function returns the data in the characteristic data buffer expressed as a uint16_t value.
### **Example Code**[](#id58)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::readData32**[](#bleremotecharacteristic-readdata32)
### **Description**[](#id59)
Request for characteristic data from the remote device and read the data in the buffer, expressed as an unsigned 32-bit integer.
### **Syntax**[](#id60)
uint32_t readData32(void);
### **Parameters**[](#id61)
NA
### **Returns**[](#id62)
This function returns the data in the characteristic data buffer expressed as a uint32_t value.
### **Example Code**[](#id63)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::writeString**[](#bleremotecharacteristic-writestring)
### **Description**[](#id64)
Write data to the remote device characteristic as a String object or character array.
### **Syntax**[](#id65)
bool writeString(String str);
bool writeString(const char* str);
### **Parameters**[](#id66)
str: the data to write to the remote characteristic, expressed as a String class object or a char array.
### **Returns**[](#id67)
This function returns TRUE if writing data to the remote device characteristic is successful.
### **Example Code**[](#id68)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::writeData8**[](#bleremotecharacteristic-writedata8)
### **Description**[](#id69)
Write data to the remote device characteristic as an unsigned 8-bit integer.
### **Syntax**[](#id70)
bool writeData8(uint8_t num);
### **Parameters**[](#id71)
num: the data to write to the characteristic buffer expressed as an unsigned 8-bit integer.
### **Returns**[](#id72)
This function returns TRUE if writing data to the remote device characteristic is successful.
### **Example Code**[](#id73)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::writeData16**[](#bleremotecharacteristic-writedata16)
### **Description**[](#id74)
Write data to the remote device characteristic as an unsigned 16-bit integer.
### **Syntax**[](#id75)
bool writeData16(uint16_t num);
### **Parameters**[](#id76)
num: the data to write to the characteristic buffer expressed as an unsigned 16-bit integer.
### **Returns**[](#id77)
This function returns TRUE if writing data to the remote device characteristic is successful.
### **Example Code**[](#id78)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::writeData32**[](#bleremotecharacteristic-writedata32)
### **Description**[](#id79)
Write data to the remote device characteristic as a 32-bit integer.
### **Syntax**[](#id80)
bool writeData32(uint32_t num);
bool writeData32(int num);
### **Parameters**[](#id81)
num: the data to write to the characteristic buffer expressed as a 32-bit integer.
### **Returns**[](#id82)
This function returns TRUE if writing data to the remote device characteristic is successful.
### **Example Code**[](#id83)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::setData**[](#bleremotecharacteristic-setdata)
### **Description**[](#id84)
Write data to the remote device characteristic.
### **Syntax**[](#id85)
bool setData(uint8_t* data, uint16_t datalen);
### **Parameters**[](#id86)
data: pointer to byte array containing desired data.
datalen: number of bytes of data to write.
### **Returns**[](#id87)
This function returns TRUE if writing data to the remote device characteristic is successful.
### **Example Code**[](#id88)
NA
## **BLERemoteCharacteristic::getData**[](#bleremotecharacteristic-getdata)
### **Description**[](#id89)
Get the characteristic data from the remote device and read the data in the buffer.
### **Syntax**[](#id90)
uint16_t getData (uint8_t* data, uint16_t datalen);
### **Parameters**[](#id91)
data: pointer to byte array to save data read from buffer.
datalen: number of bytes of data to read.
### **Returns**[](#id92)
This function returns the number of bytes read.
### **Example Code**[](#id93)
NA
Note
If the data buffer contains less data than requested, it will only read the available number of bytes of data. “BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::enableNotifyIndicate**[](#bleremotecharacteristic-enablenotifyindicate)
### **Description**[](#id94)
Enable the remote device to send notifications or indications for the characteristic.
### **Syntax**[](#id95)
void enableNotifyIndicate(bool notify);
### **Parameters**[](#id96)
notify: Enable notifications or indications. Default value is TRUE.
- TRUE (enable notifications)
- FALSE (enable indications)
### **Returns**[](#id97)
NA
### **Example Code**[](#id98)
Example: [BLEUartClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartClient/BLEUartClient.ino)
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::disableNotifyIndicate**[](#bleremotecharacteristic-disablenotifyindicate)
### **Description**[](#id100)
Disable receiving notifications and indications for the characteristic from the remote device.
### **Syntax**[](#id101)
void disableNotifyIndicate(void);
**Parameters**
NA
### **Returns**[](#id102)
NA
### **Example Code**[](#id103)
NA
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
## **BLERemoteCharacteristic::setNotifyCallback**[](#bleremotecharacteristic-setnotifycallback)
### **Description**[](#id104)
Set a user function to be called when the characteristic receives a notification from the remote device.
### **Syntax**[](#id105)
void setNotifyCallback(void (*fCallback) (BLERemoteCharacteristic* chr, uint8_t* data, uint16_t length));
### **Parameters**[](#id106)
fCallback: A user callback function that returns void and takes three arguments.
chr: pointer to BLERemoteCharacteristic object associated with notification.
data: pointer to byte array containing notification data.
length: number of bytes of notification data in array.
### **Returns**[](#id107)
NA
### **Example Code**[](#id108)
Example: [BLEUartClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartClient/BLEUartClient.ino)
Note
“BLERemoteCharacteristic.h” must be included to use the class function.
[ Previous](Class%20BLEHIDMouse.html)
[Next ](Class%20BLERemoteDescriptor.html)
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