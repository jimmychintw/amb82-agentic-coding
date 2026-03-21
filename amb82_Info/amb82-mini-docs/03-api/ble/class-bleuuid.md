Class BLEUUID — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEUUID
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEUUID.rst)
# Class BLEUUID[](#class-bleuuid)
## **BLEUUID Class**[](#bleuuid-class)
### **Description**[](#description)
A class used for creating and managing UUIDs.
### **Syntax**[](#syntax)
class BLEUUID
### **Members**[](#members)
|**Public Constructors**
|
|
| BLEUUID::BLEUUID
|
Create a BLEUUID object
|
|
| **Public Methods**
|
|
| BLEUUID::str
|
Get the character string
representation of UUID
|
|
| BLEUUID::data
|
Get the binary representation of
UUID, with the UUID MSB in array
index [0]
|
|
| BLEUUID::dataNative
|
Get the binary representation of
UUID, with the UUID LSB in array
index [0]
|
|
| BLEUUID::length
|
Get the length of UUID
|
|
## **BLEUUID::BLEUUID**[](#bleuuid-bleuuid)
### **Description**[](#id1)
Create a BLEUUID object from a UUID character string.
### **Syntax**[](#id2)
BLEUUID(void);
BLEUUID(const char* str);
BLEUUID(uint8_t* data, uint8_t length);
### **Parameters**[](#parameters)
str: UUID as character string used to create object
data: pointer to byte array containing the desired UUID
length: number of bytes in array containing the desired UUID.
- 2, 4 or 16.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
NA
Note
“BLEUUID.h” must be included to use the class function.
## **BLEUUID::str**[](#bleuuid-str)
### **Description**[](#id3)
Get the character string representation of UUID.
### **Syntax**[](#id4)
const char* str(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
This function returns a pointer to the UUID represented as a character string.
### **Example Code**[](#id7)
NA
Note
“BLEUUID.h” must be included to use the class function.
## **BLEUUID::data**[](#bleuuid-data)
### **Description**[](#id8)
Get the binary representation of UUID, with the UUID MSB in array index[0].
### **Syntax**[](#id9)
const uint8_t* data(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
This function returns a pointer to an unsigned 8-bit integer array containing the UUID expressed in binary form.
### **Example Code**[](#id12)
NA
Note
Returned pointer is of const uint8_t* type and will not allow changing of the data. “BLEUUID.h” must be included to use the class function.
## **BLEUUID::dataNative**[](#bleuuid-datanative)
### **Description**[](#id13)
Get the binary representation of UUID, with the UUID LSB in array index [0].
### **Syntax**[](#id14)
const uint8_t* dataNative(void);
### **Parameters**[](#id15)
NA
### **Returns**[](#id16)
This function returns a pointer to an unsigned 8-bit integer array containing the UUID expressed in binary form.
### **Example Code**[](#id17)
NA
Note
Returned pointer is of const uint8_t* type and will not allow changing of the data. “BLEUUID.h” must be included to use the class function.
## **BLEUUID::length**[](#bleuuid-length)
### **Description**[](#id18)
Get the length of UUID.
### **Syntax**[](#id19)
uint8_t length(void);
### **Parameters**[](#id20)
NA
### **Returns**[](#id21)
This function returns the length of the UUID, in units of bytes.
### **Example Code**[](#id22)
NA
Note
A 4-character UUID will be 16 bits / 2 bytes long. A 8-character UUID will be 32 bits / 4 bytes long. A 32-character UUID will be 128 bits / 16 bytes long. “BLEUUID.h” must be included to use the class function.
[ Previous](Class%20BLEService.html)
[Next ](Class%20BLEWifiConfigService.html)
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