Class File — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [FileSystem](index.html)
- Class File
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/FileSystem/Class File.rst)
# Class File[](#class-file)
## **File Class**[](#file-class)
### **Description**[](#description)
A class for data manipulation of files in a file system.
### **Syntax**[](#syntax)
class File
### **Members**[](#members)
|**Public Constructors**
|
|
| [File::File](File::File)
|
Constructs a File object.
|
|
| **Public Methods**
|
|
| [File::open](File::open)
|
Open a file from the filesystem.
|
|
| [File::close](File::close)
|
Close a previously opened file.
|
|
| [File::write](File::write)
|
Write data to the currently open file.
|
|
| [File::read](File::read)
|
Read data from the currently open file.
|
|
| [File::peek](File::peek)
|
Peek at the next data byte from the
currently open file.
|
|
| [File::available](File::available)
|
Check number of bytes remaining till end
of file.
|
|
| [File::flush](File::flush)
|
Flush cached data.
|
|
| [File::seek](File::seek)
|
Move read write pointer.
|
|
| [File::position](File::position)
|
Get current read write pointer.
|
|
| [File::size](File::size)
|
Get file size.
|
|
| [File::isOpen](File::isOpen)
|
Check if a file is currently open.
|
|
| [File::name](File::name)
|
Get currently open file name.
|
|
| [File::convertMp3ToArray](File::convertMp3ToArray)
|
Convert MP3 file to MP3data and MP3size.
|
|
| [File::setMp3DigitalVol](File::setMp3DigitalVol)
|
Control the digital gain of DAC.
|
|
| [File::playmp3](File::playmp3)
|
Execute convertMp3TArray.
|
|
| [File::sdstartota](File::sdstartota)
|
Pass filename with full path and
execute ota_sd.
|
|
| [File::readFile](File::readFile)
|
Read data according to opened file size
|
|
## **File::File**[](#file-file)
### **Description**[](#id1)
Constructs a File object.
### **Syntax**[](#id2)
File::File(void);
File::File(const char* filename);
File::File(const char *filename, int fileType);
### **Parameters**[](#parameters)
filename: pointer to a char array containing the path of the file to open.
fileType: The macro of the file type defined in AmebaFatFSFile.h to support different opening methods for different types of file.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [CreateFolder](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FileSystem/examples/CreateFolder/CreateFolder.ino)
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::open**[](#file-open)
### **Description**[](#id3)
Open a file from the file system.
### **Syntax**[](#id4)
bool open(const char* filename);
bool open(const char *filename, int fileType);
### **Parameters**[](#id5)
filename: pointer to a char array containing the path of the file to open.
fileType: The macro of the file type defined in AmebaFatFSFile.h to support different opening methods for different types of file.
### **Returns**[](#id6)
This function returns true if the file is opened successfully, false otherwise.
### **Example Code**[](#id7)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::close**[](#file-close)
### **Description**[](#id8)
Close a previously opened file.
### **Syntax**[](#id9)
void close(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
Example: [CreateFolder](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FileSystem/examples/CreateFolder/CreateFolder.ino)
Note
“AmebaFatFSFile.h” must be included to use the class function. Opened files need to be closed to ensure that any pending data is saved correctly.
## **File::write**[](#file-write)
### **Description**[](#id14)
Write data to the currently open file.
### **Syntax**[](#id15)
size_t write(uint8_t c);
size_t write(const uint8_t* buf, size_t size);
size_t write(const char* str);
size_t write(const char* buf, size_t size);
### **Parameters**[](#id16)
c: single data byte to write.
str: pointer to char array containing data to write, expressed as a null terminated string.
buf: pointer to array containing data to write.
size: number of bytes to write.
### **Returns**[](#id17)
This function returns the number of data bytes written to file.
### **Example Code**[](#id18)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::read**[](#file-read)
### **Description**[](#id19)
Read data from the currently open file.
### **Syntax**[](#id20)
int read(void);
int read(void* buf, size_t size);
### **Parameters**[](#id21)
buf: pointer to buffer to store read data.
size: number of data bytes to read.
### **Returns**[](#id22)
When a buffer pointer is not used, this function returns the data byte read if successful, otherwise it returns “-1”.
When a buffer pointer is used, this function returns the number of bytes read.
### **Example Code**[](#id23)
Example: [CreateFolder](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FileSystem/examples/CreateFolder/CreateFolder.ino)
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::peek**[](#file-peek)
### **Description**[](#id25)
Peek at the next data byte from the currently open file.
### **Syntax**[](#id26)
int peek(void);
### **Parameters**[](#id27)
NA
### **Returns**[](#id28)
This function returns the next data byte if successful, otherwise it returns “-1”.
### **Example Code**[](#id29)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::available**[](#file-available)
### **Description**[](#id30)
Check number of bytes remaining till end of file.
### **Syntax**[](#id31)
int available(void);
### **Parameters**[](#id32)
NA
### **Returns**[](#id33)
This function returns the number of bytes available to read until the end of file.
### **Example Code**[](#id34)
Example: [ReadHTMLFile](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/FileSystem/examples/ReadHTMLFile/ReadHTMLFile.ino)
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::flush**[](#file-flush)
### **Description**[](#id35)
Flush cached data.
### **Syntax**[](#id36)
void flush(void);
### **Parameters**[](#id37)
NA
### **Returns**[](#id38)
This function flushes any cached data and writes all pending data into file.
### **Example Code**[](#id39)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::seek**[](#file-seek)
### **Description**[](#id40)
Move the file read/write pointer of the currently open file.
### **Syntax**[](#id41)
bool seek(uint32_t pos);
### **Parameters**[](#id42)
pos: file position to move.
### **Returns**[](#id43)
This function returns true if the file pointer is move successfully, false otherwise.
### **Example Code**[](#id44)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function. If the target position is larger than the size of the currently open file, the file size will be increased as required.
## **File::position**[](#file-position)
### **Description**[](#id45)
Get the read/write pointer of the currently open file.
### **Syntax**[](#id46)
uint32_t position(void);
### **Parameters**[](#id47)
NA
### **Returns**[](#id48)
This function returns the current file read/write position.
### **Example Code**[](#id49)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::size**[](#file-size)
### **Description**[](#id50)
Get the size of the currently open file.
### **Syntax**[](#id51)
uint32_t size(void);
### **Parameters**[](#id52)
NA
### **Returns**[](#id53)
This function returns the size of the currently open file.
### **Example Code**[](#id54)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::isOpen**[](#file-isopen)
### **Description**[](#id55)
Check if a file is currently open.
### **Syntax**[](#id56)
bool isOpen(void);
### **Parameters**[](#id57)
NA
### **Returns**[](#id58)
This function returns true if a file is currently open, false otherwise.
### **Example Code**[](#id59)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::name**[](#file-name)
### **Description**[](#id60)
Get the filename of the currently open file.
### **Syntax**[](#id61)
const char* name(void);
### **Parameters**[](#id62)
NA
### **Returns**[](#id63)
This function returns a pointer to a character array containing the filename of the currently open file. If no file is open, it returns NULL.
### **Example Code**[](#id64)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::convertMp3ToArray**[](#file-convertmp3toarray)
### **Description**[](#id65)
Convert MP3 file to MP3data and MP3size.
### **Syntax**[](#id66)
void convertMp3ToArray(void);
### **Parameters**[](#id67)
NA
### **Returns**[](#id68)
This function convert MP3 file into character array containing the MP3data without the ID3 header. If no file is open for conversion, it will print out error message.
### **Example Code**[](#id69)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::setMp3DigitalVol**[](#file-setmp3digitalvol)
### **Description**[](#id70)
Control the digital gain of DAC.
### **Syntax**[](#id71)
void setMp3DigitalVol(uint8_t digitalVol);
### **Parameters**[](#id72)
digitalVol: output digital volume
Note
Every Step is 0.375dB.
0xAF: 0dB.
0xAE: -0.375dB.
…
0x00: -65.625dB.
### **Returns**[](#id73)
NA
### **Example Code**[](#id74)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::playMp3**[](#file-playmp3)
### **Description**[](#id75)
Execute convertMp3TArray.
### **Syntax**[](#id76)
void playMp3(void);
### **Parameters**[](#id77)
NA
### **Returns**[](#id78)
NA
### **Example Code**[](#id79)
Example: [OTA](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/OTA/examples/OTA/OTA.ino)
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::sdstartota**[](#file-sdstartota)
### **Description**[](#id80)
Pass filename with full path and execute ota_sd.
### **Syntax**[](#id81)
void sdstartota(const char *filename);
### **Parameters**[](#id82)
filename: Filename with full path.
### **Returns**[](#id83)
NA
### **Example Code**[](#id84)
Example: [SDCardOTA](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/OTA/examples/SDCardOTA/SDCardOTA.ino)
Note
“AmebaFatFSFile.h” must be included to use the class function.
## **File::readFile**[](#file-readfile)
### **Description**[](#id85)
Read opened data file according to its file size, malloc is done within API, no pre-definition of fixed size buffer needed.
### **Syntax**[](#id86)
bool readFile(unsigned char *file_data, uint32_t &file_size);
### **Parameters**[](#id87)
file_data: buffer pointer for the file to be read
file_size: the size of the file to be read
### **Returns**[](#id88)
True if the file data is read successfully, false if failed to read file data.
### **Example Code**[](#id89)
NA
Note
“AmebaFatFSFile.h” must be included to use the class function.
[ Previous](Class%20AmebaFatFS.html)
[Next ](../FlashMemory/index.html)
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