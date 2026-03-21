Class BLEAddr — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEAddr
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEAddr.rst)
# Class BLEAddr[](#class-bleaddr)
## **BLEAddr Class**[](#bleaddr-class)
### **Description**[](#description)
A class used for managing Bluetooth addresses.
### **Syntax**[](#syntax)
class BLEAddr
### **Members**[](#members)
|**Public Constructors**
|
|
| BLEAddr::BLEAddr
|
Constructs a BLEAddr object
|
|
| **Public Methods**
|
|
| BLEAddr::str
|
Get the Bluetooth address
represented as a formatted string
|
|
| BLEAddr::data
|
Get the Bluetooth address
represented as an integer array
|
|
## **BLEAddr::BLEAddr**[](#bleaddr-bleaddr)
### **Description**[](#id1)
Constructs a BLEAddr object.
### **Syntax**[](#id2)
BLEAddr(void);
BLEAddr(uint8_t (&addr)[6]);
BLEAddr(const char * str);
### **Parameters**[](#parameters)
addr: An array of 6 bytes containing the desired Bluetooth address.
str: desired Bluetooth address represented in character string.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
NA
Note
When expressing the Bluetooth address as a string, it should be written as 6 bytes in hexadecimal format. The bytes can be separated using a colon “:”, for example – 00:11:22:33:EE:FF. “BLEAddr.h” must be included to use the class function.
## **BLEAddr::str**[](#bleaddr-str)
### **Description**[](#id3)
Get the Bluetooth address represented as a formatted string.
### **Syntax**[](#id4)
const char* str(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
This function returns a pointer to the character string containing the hexadecimal representation of the Bluetooth address.
### **Example Code**[](#id7)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
When expressing the Bluetooth address as a string, it should be written as 6 bytes in hexadecimal format. The bytes can be separated using a colon “:”, for example – 00:11:22:33:EE:FF. “BLEAddr.h” must be included to use the class function.
## **BLEAddr::data**[](#bleaddr-data)
### **Description**[](#id8)
Get the Bluetooth address represented as an integer array.
### **Syntax**[](#id9)
uint8_t* data(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
This function returns a pointer to a 6-byte array containing the Bluetooth address.
**Example Code**
NA
Note
The MSB of Bluetooth address is stored at index 5 of the byte array. “BLEAddr.h” must be included to use the class function.
[ Previous](index.html)
[Next ](Class%20BLEAdvert.html)
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