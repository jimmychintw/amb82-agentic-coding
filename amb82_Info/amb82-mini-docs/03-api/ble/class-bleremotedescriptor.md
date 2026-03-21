Class BLERemoteDescriptor — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLERemoteDescriptor
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLERemoteDescriptor.rst)
# Class BLERemoteDescriptor[](#class-bleremotedescriptor)
## **BLERemoteDescriptor Class**[](#bleremotedescriptor-class)
### **Description**[](#description)
A class used for managing BLE GATT descriptors on connected remote devices.
### **Syntax**[](#syntax)
class BLERemoteDescriptor
### **Members**[](#members)
|**Public Constructors**
|
|
| No public constructor is available for this class. You can get a
pointer to an instance of this class using
BLERemoteCharacteristic::getDescriptor()
|
|
| **Public Methods**
|
|
| BLERemoteDescriptor::getUUID
|
Get the descriptor UUID
|
|
| BLERemoteDescriptor::setBufferLen
|
Set the size of the internal
data buffer
|
|
| BLERemoteDescriptor::getBufferLen
|
Get the current size of the
internal data  buffer
|
|
| BLERemoteDescriptor::readString
|
Read the descriptor data buffer
as a String object
|
|
| BLERemoteDescriptor::readData8
|
Read the descriptor data buffer
as an unsigned 8-bit integer
|
|
| BLERemoteDescriptor::readData16
|
Read the descriptor data buffer
as an unsigned 16-bit integer
|
|
| BLERemoteDescriptor::readData32
|
Read the descriptor data buffer
as an unsigned 32-bit integer
|
|
| BLERemoteDescriptor::writeString
|
Write data to the descriptor as
a String object or character
array
|
|
| BLERemoteDescriptor::writeData8
|
Write data to the descriptor
as an unsigned 8-bit integer
|
|
| BLERemoteDescriptor::writeData16
|
Write data to the descriptor
as an unsigned 16-bit integer
|
|
| BLERemoteDescriptor::writeData32
|
Write data to the descriptor
as an unsigned 32-bit integer
|
|
| BLERemoteDescriptor::setData
|
Write data to the descriptor
|
|
| BLERemoteDescriptor::getData
|
Get data from the descriptor
|
|
## **BLERemoteDescriptor::getUUID**[](#bleremotedescriptor-getuuid)
### **Description**[](#id1)
Get the descriptor UUID.
### **Syntax**[](#id2)
BLEUUID getUUID(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
This function returns the descriptor UUID as a BLEUUID class object.
### **Example Code**[](#example-code)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::setBufferLen**[](#bleremotedescriptor-setbufferlen)
### **Description**[](#id3)
Set the size of the internal data buffer of the descriptor.
### **Syntax**[](#id4)
void setBufferLen(uint16_t max_len);
### **Parameters**[](#id5)
max_len: the size in bytes to resize the internal buffer to.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
Descriptor data buffer has a default size of 20 bytes and can be increased up to 230 bytes. “BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::getBufferLen**[](#bleremotedescriptor-getbufferlen)
### **Description**[](#id8)
Get the current size of the descriptor internal buffer.
### **Syntax**[](#id9)
uint16_t getBufferLen(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
This function returns the current internal buffer size that is set.
### **Example Code**[](#id12)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::readString**[](#bleremotedescriptor-readstring)
### **Description**[](#id13)
Request for descriptor data from the remote device and read the data in the buffer, expressed as a String class object.
### **Syntax**[](#id14)
String readString(void);
### **Parameters**[](#id15)
NA
### **Returns**[](#id16)
The function returns the data in the descriptor buffer expressed as a String class object.
### **Example Code**[](#id17)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::readData8**[](#bleremotedescriptor-readdata8)
### **Description**[](#id18)
Request for descriptor data from the remote device and read the data in the buffer, expressed as an unsigned 8-bit integer.
### **Syntax**[](#id19)
uint8_t readData8(void);
### **Parameters**[](#id20)
NA
### **Returns**[](#id21)
The function returns the data in the descriptor buffer expressed as a uint8_t value.
### **Example Code**[](#id22)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::readData16**[](#bleremotedescriptor-readdata16)
### **Description**[](#id23)
Request for descriptor data from the remote device and read the data in the buffer, expressed as an unsigned 16-bit integer.
### **Syntax**[](#id24)
uint16_t readData16(void);
### **Parameters**[](#id25)
NA
### **Returns**[](#id26)
The function returns the data in the descriptor buffer expressed as a uint16_t value.
### **Example Code**[](#id27)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::readData32**[](#bleremotedescriptor-readdata32)
### **Description**[](#id28)
Request for descriptor data from the remote device and read the data in the buffer, expressed as an unsigned 32-bit integer.
### **Syntax**[](#id29)
uint32_t readData32(void);
### **Parameters**[](#id30)
NA
### **Returns**[](#id31)
The function returns the data in the descriptor buffer expressed as a uint32_t value.
### **Example Code**[](#id32)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::writeString**[](#bleremotedescriptor-writestring)
### **Description**[](#id33)
Write data to the remote device descriptor as a String object or character array.
### **Syntax**[](#id34)
bool writeString(String str);
bool writeString(const char* str);
### **Parameters**[](#id35)
str: the data to write to the remote descriptor, expressed as a String class object or a char array.
### **Returns**[](#id36)
This function returns TRUE if writing data to remote device descriptor is successful.
### **Example Code**[](#id37)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::writeData8**[](#bleremotedescriptor-writedata8)
### **Description**[](#id38)
Write data to the remote device descriptor as an unsigned 8-bit integer.
### **Syntax**[](#id39)
bool writeData8(uint8_t num);
### **Parameters**[](#id40)
num: the data to write to the descriptor buffer expressed as an unsigned 8-bit integer.
### **Returns**[](#id41)
This function returns TRUE if writing data to remote device descriptor is successful.
### **Example Code**[](#id42)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::writeData16**[](#bleremotedescriptor-writedata16)
### **Description**[](#id43)
Write data to the remote device descriptor as an unsigned 16-bit integer.
### **Syntax**[](#id44)
bool writeData16(uint16_t num);
### **Parameters**[](#id45)
num: the data to write to the descriptor buffer expressed as an unsigned 16-bit integer.
### **Returns**[](#id46)
This function returns TRUE if writing data to remote device descriptor is successful.
### **Example Code**[](#id47)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::writeData32**[](#bleremotedescriptor-writedata32)
### **Description**[](#id48)
Write data to the remote device descriptor as a 32-bit integer.
### **Syntax**[](#id49)
bool writeData32(uint32_t num);
bool writeData32(int num);
### **Parameters**[](#id50)
num: the data to write to the descriptor buffer expressed as a 32-bit integer.
### **Returns**[](#id51)
This function returns TRUE if writing data to remote device descriptor is successful.
### **Example Code**[](#id52)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::setData**[](#bleremotedescriptor-setdata)
### **Description**[](#id53)
Write data to the descriptor.
### **Syntax**[](#id54)
bool setData(uint8_t* data, uint16_t datalen);
### **Parameters**[](#id55)
data: pointer to byte array containing desired data to write.
datalen: number of bytes of data to write.
### **Returns**[](#id56)
This function returns TRUE if writing data to remote device descriptor is successful.
### **Example Code**[](#id57)
NA
Note
“BLERemoteDescriptor.h” must be included to use the class function.
## **BLERemoteDescriptor::getData**[](#bleremotedescriptor-getdata)
### **Description**[](#id58)
Get the descriptor data from the remote device and read the data in the buffer.
### **Syntax**[](#id59)
uint16_t getData(uint8_t* data, uint16_t datalen);
### **Parameters**[](#id60)
data: pointer to byte array to save data read from buffer.
datalen: number of bytes of data to read.
### **Returns**[](#id61)
The function returns the number of bytes read.
### **Example Code**[](#id62)
NA
Note
If the data buffer contains less data than requested, it will only read the available number of bytes of data. “BLERemoteDescriptor.h” must be included to use the class function.
[ Previous](Class%20BLERemoteCharacteristic.html)
[Next ](Class%20BLERemoteService.html)
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