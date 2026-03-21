Class FlashMemory — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [FlashMemory](index.html)
- Class FlashMemory
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/FlashMemory/Class FlashMemoryClass.rst)
# Class FlashMemory[](#class-flashmemory)
## **FlashMemoryClass Class**[](#flashmemoryclass-class)
### **Description**[](#description)
A class for Flash memory API.
### **Syntax**[](#syntax)
class FlashMemoryClass
### **Members**[](#members)
|**Public Constructors**
|
|
| FlashMemoryClass::FlashMemoryClass
|
Constructs a FlashMemoryClass
object
|
|
| **Public Methods**
|
|
| FlashMemoryClass::begin
|
Initialize/Re-initialize the
base address and size
|
|
| FlashMemoryClass::end
|
Free the buf set by begin,
deinit flash memory process
|
|
| FlashMemoryClass::read
|
Read content (stream of word)
from flash memory to buffer.
Able to set address with
specific offset.
|
|
| FlashMemoryClass::write
|
Write the content in the buffer
back to the flash memory. Able
to set address with specific
offset.
|
|
| FlashMemoryClass::readWord
|
Read word (4 bytes) from flash
memory based on the new base
address with specific offset.
|
|
| FlashMemoryClass::writeWord
|
Write word to flash memory based
on the new base address with
specific offset.
|
|
| FlashMemoryClass::eraseSector
|
Erase flash memory by sector (4K
bytes)
|
|
| FlashMemoryClass::eraseWord
|
Erase flash memory by word
|
|
| FlashMemoryClass::buf_size
|
The buf size regarded as work
size
|
|
| FlashMemoryClass::buf
|
The buf to be operated
|
|
## **FlashMemoryClass::FlashMemoryClass**[](#flashmemoryclass-flashmemoryclass)
### **Description**[](#id1)
Constructs a FlashMemoryClass object.
### **Syntax**[](#id2)
FlashMemoryClass(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [ReadWriteWord](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FlashMemory/examples/ReadWriteWord/ReadWriteWord.ino)
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::begin**[](#flashmemoryclass-begin)
### **Description**[](#id3)
Initialize/Re-initialize the base address and size. The default usable flash memory size is 0x3000.
### **Syntax**[](#id4)
void begin(unsigned int flash_base_address, unsigned int flash_buf_size);
### **Parameters**[](#id5)
flash_base_address: The starting location/position of the flash memory.
flash_buf_size: The desired buffer size.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [ReadWriteWord](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FlashMemory/examples/ReadWriteWord/ReadWriteWord.ino)
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::end**[](#flashmemoryclass-end)
### **Description**[](#id9)
Free the buf set by begin, deinit flash memory process.
### **Syntax**[](#id10)
void end(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
NA
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::read**[](#flashmemoryclass-read)
### **Description**[](#id14)
Read from the flash memory and copy into a buffer. All modification of the contents will be done in the buffer before updating the flash memory. The default length of the buf is buf_size with 0x3000. Update buf and buf_size by function “begin()”. Indicate the starting address by “offset”.
### **Syntax**[](#id15)
void read(unsigned int offset = 0);
### **Parameters**[](#id16)
offset: offset to the base address.
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
Example: [ReadWriteStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FlashMemory/examples/ReadWriteStream/ReadWriteStream.ino)
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::write**[](#flashmemoryclass-write)
### **Description**[](#id19)
Write buf back to flash memory. Indicate the starting address by “offset”. The default length of the buf is buf_size with 0x3000. Update buf and buf_size by function “begin()”
### **Syntax**[](#id20)
void write(unsigned int offset = 0);
### **Parameters**[](#id21)
offset: offset to the base address.
### **Returns**[](#id22)
NA
### **Example Code**[](#id23)
Example: [ReadWriteStream](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FlashMemory/examples/ReadWriteStream/ReadWriteStream.ino)
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::readWord**[](#flashmemoryclass-readword)
### **Description**[](#id25)
Read 4 bytes data (a word) from a flash address, based on the new base address with specific offset.
### **Syntax**[](#id26)
unsigned int readWord(unsigned int offset);
### **Parameters**[](#id27)
offset: offset to the base address.
### **Returns**[](#id28)
This function returns the 4 bytes read data. The return type is “unsigned int”.
### **Example Code**[](#id29)
Example: [ReadWriteWord](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FlashMemory/examples/ReadWriteWord/ReadWriteWord.ino)
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::writeWord**[](#flashmemoryclass-writeword)
### **Description**[](#id31)
Write 4 bytes data (a word) to a flash address, based on the new base address with specific offset. Then read data from the address and compare with the original data. If there is difference. Buffer a flash sector from the new base address, then erase the sector from the flash. Replace the correct data back into buffer. Then rewrite the buffer into the flash.
### **Syntax**[](#id32)
void writeWord(unsigned int offset, unsigned int data);
### **Parameters**[](#id33)
offset: offset to the base address.
data: The data to be written (4 bytes / a word)
### **Returns**[](#id34)
NA
### **Example Code**[](#id35)
Example: [ReadWriteWord](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FlashMemory/examples/ReadWriteWord/ReadWriteWord.ino)
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::eraseSector**[](#flashmemoryclass-erasesector)
### **Description**[](#id37)
Erase flash memory by sector (4K bytes). The erase size should be the multiples of sector size.
### **Syntax**[](#id38)
void eraseSector(unsigned int sector_offset);
### **Parameters**[](#id39)
offset: offset to the base address.
### **Returns**[](#id40)
NA
### **Example Code**[](#id41)
NA
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::eraseWord**[](#flashmemoryclass-eraseword)
### **Description**[](#id42)
Erase flash memory by word (4 bytes). The offset according to base address.
### **Syntax**[](#id43)
void eraseWord(unsigned int offset);
### **Parameters**[](#id44)
offset: offset to the base address.
### **Returns**[](#id45)
NA
### **Example Code**[](#id46)
NA
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::buf_size**[](#flashmemoryclass-buf-size)
### **Description**[](#id47)
The buf size regarded as work size. Maximum size is MAX_FLASH_MEMORY_APP_SIZE that is 0x3000.
### **Syntax**[](#id48)
unsigned int buf_size;
### **Parameters**[](#id49)
NA
### **Returns**[](#id50)
NA
### **Example Code**[](#id51)
Example: [ReadWriteWord](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FlashMemory/examples/ReadWriteWord/ReadWriteWord.ino)
Note
“FlashMemory.h” must be included to use the class function.
## **FlashMemoryClass::buf**[](#flashmemoryclass-buf)
### **Description**[](#id53)
The buf to be operated. Modify buf won’t change the content of buf. It needs update to write back to flash memory.
### **Syntax**[](#id54)
unsigned char *buf;
### **Parameters**[](#id55)
NA
### **Returns**[](#id56)
NA
### **Example Code**[](#id57)
Example: [ReadWriteWord](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FlashMemory/examples/ReadWriteWord/ReadWriteWord.ino)
Note
“FlashMemory.h” must be included to use the class function.
[ Previous](index.html)
[Next ](../GPIO/index.html)
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