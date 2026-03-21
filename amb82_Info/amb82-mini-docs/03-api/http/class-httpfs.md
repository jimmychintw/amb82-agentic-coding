Class Httpfs — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [HTTP](index.html)
- Class Httpfs
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/HTTP/Class Httpfs.rst)
# Class Httpfs[](#class-httpfs)
## **Httpfs Class**[](#httpfs-class)
### **Description**[](#description)
A class used HTTP File Server.
### **Syntax**[](#syntax)
class Httpfs
### **Members**[](#members)
|**Public Constructors**
|
|
|
| Httpfs::Httpfs
|
Constructs a Httpfs object.
|
|
| **Public Methods**
|
|
| Httpfs::begin
|
Initializes the HTTP file server,
set parameter, response callback
function of the file server.
|
|
| Httpfs::mp4DirectoryInit
|
Initializes the directory to save
MP4 recordings on SD card.
|
|
| Httpfs::end
|
Deinitializes the HTTP file
server.
|
|
## **Httpfs::begin**[](#httpfs-begin)
### **Description**[](#id1)
Initializes the HTTP file server, set parameter, response callback function of the file server.
### **Syntax**[](#id2)
void begin(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [Httpfs_mp4](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Http/examples/Httpfs_mp4/Httpfs_mp4.ino)
## **Httpfs::mp4DirectoryInit**[](#httpfs-mp4directoryinit)
### **Description**[](#id3)
Initializes the directory to save MP4 recordings on SD card.
### **Syntax**[](#id4)
void mp4DirectoryInit(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [Httpfs_mp4](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Http/examples/Httpfs_mp4/Httpfs_mp4.ino)
## **Httpfs::end**[](#httpfs-end)
### **Description**[](#id9)
Deinitializes the HTTP file server.
### **Syntax**[](#id10)
void end(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [Httpfs_mp4](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Http/examples/Httpfs_mp4/Httpfs_mp4.ino)
[ Previous](index.html)
[Next ](../Multimedia/index.html)
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