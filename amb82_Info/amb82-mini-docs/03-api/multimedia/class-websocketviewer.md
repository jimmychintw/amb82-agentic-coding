Class WebSocketViewer — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class WebSocketViewer
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class WebSocketViewer.rst)
# Class WebSocketViewer[](#class-websocketviewer)
## **WebSocketViewer Class**[](#websocketviewer-class)
### **Description**[](#description)
A class for streaming live camera video from the AMB82 Mini to a web browser using WebSocket.
### **Syntax**[](#syntax)
class WebSocketViewer
### **Members**[](#members)
|**Public Constructors**
|
|
| WebSocketViewer::WebSocketViewer
|
Constructs a WebSocketViewer object.
|
|
| **Public Methods**
|
|
| WebSocketViewer::loadWebResourcesFromSD
|
Load htdocs.bin from the SD card.
|
|
| WebSocketViewer::loadWebResources
|
Load WebSocket Viewer web resources.
|
|
| WebSocketViewer::init
|
Initialize the WebSocket Viewer module.
|
|
| WebSocketViewer::begin
|
Start the WebSocket Viewer service.
|
|
| WebSocketViewer::deinit
|
Deinitialize the WebSocket Viewer service.
|
|
## **WebSocketViewer::loadWebResourcesFromSD**[](#websocketviewer-loadwebresourcesfromsd)
### **Description**[](#id1)
Load htdocs.bin from the SD card.
### **Syntax**[](#id2)
int loadWebResourcesFromSD(unsigned char **buf, int *len);
### **Parameters**[](#parameters)
buf: Pointer to the buffer containing the loaded web resources.
len: Length of the loaded data in bytes.
### **Returns**[](#returns)
0 on success, -1 on failure.
### **Example Code**[](#example-code)
NA
Note
“WebSocketViewer.h” must be included to use the class function.
## **WebSocketViewer::loadWebResources**[](#websocketviewer-loadwebresources)
### **Description**[](#id3)
Load WebSocket Viewer web resources.
### **Syntax**[](#id4)
void loadWebResources(int websocket_from_sd);
### **Parameters**[](#id5)
websocket_from_sd: 1 to load web resources (htdocs.bin) from the SD card, 0 to load web resources from htdocs.h as an array.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [WebSocketViewer](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/WebSocketViewer/WebSocketViewer.ino)
Note
“WebSocketViewer.h” must be included to use the class function.
## **WebSocketViewer::init**[](#websocketviewer-init)
### **Description**[](#id8)
Initialize the WebSocket Viewer module.
### **Syntax**[](#id9)
void init(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
Example: [WebSocketViewer](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/WebSocketViewer/WebSocketViewer.ino)
Note
“WebSocketViewer.h” must be included to use the class function.
## **WebSocketViewer::begin**[](#websocketviewer-begin)
### **Description**[](#id14)
Start the WebSocket Viewer service.
### **Syntax**[](#id15)
void begin(void);
### **Parameters**[](#id16)
NA
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
Example: [WebSocketViewer](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/WebSocketViewer/WebSocketViewer.ino)
Note
“WebSocketViewer.h” must be included to use the class function.
## **WebSocketViewer::deinit**[](#websocketviewer-deinit)
### **Description**[](#id20)
Deinitialize the WebSocket Viewer service.
### **Syntax**[](#id21)
mm_context_t *deinit(mm_context_t *p);
### **Parameters**[](#id22)
p:  pointer to the mm_context_t to be deinitialized.
### **Returns**[](#id23)
Pointer to the deinitialized mm_context_t.
### **Example Code**[](#id24)
NA
Note
“WebSocketViewer.h” must be included to use the class function.
[ Previous](Class%20VideoStreamOverlay.html)
[Next ](../Multithreading/index.html)
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