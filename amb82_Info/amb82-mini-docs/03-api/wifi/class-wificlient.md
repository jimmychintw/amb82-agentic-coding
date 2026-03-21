Class WiFiClient — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [WiFi](index.html)
- Class WiFiClient
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/WiFi/Class WiFiClient.rst)
# Class WiFiClient[](#class-wificlient)
## **WiFiClient Class**[](#wificlient-class)
### **Description**[](#description)
A class of WiFi Client implementation for Ameba.
### **Syntax**[](#syntax)
class WiFiClient
### **Members**[](#members)
|**Public Constructors**
|
|
| WiFiClient::WiFiClient
|
Constructs a WiFiClient instance that
connects to the specified IP address
and port.
|
|
| **Public Methods**
|
|
| WiFiClient::connect
|
Connect to the IP address and port.
|
|
| WiFiClient::write
|
Write data (single byte) to the
server.
|
|
| WiFiClient::available
|
Get the number of bytes available for
reading.
|
|
| WiFiClient::read
|
Read the incoming byte from the
server.
|
|
| WiFiClient::recv
|
Read the received byte from the
server that the client is connected
to.
|
|
| WiFiClient::peek
|
Get the next byte from the current
packet without moving on to the next
byte.
|
|
| WiFiClient::flush
|
Clear all the bytes that have been
written to the client but not yet
read.
|
|
| WiFiClient::stop
|
Disconnect from the server.
|
|
| WiFiClient::connected
|
Check if client is connected.
|
|
| WiFiClient::setRecvTimeout
|
Set the amount of time the client
will wait for new data to arrive each
time WiFiClient::read() is called.
|
|
| WiFiClient::setBlockingMode
|
Set WiFi Client to blocking mode.
|
|
| WiFiClient::
setNonBlocking Mode
|
Set WiFi Client to non-blocking mode.
|
|
## **WiFiClient::WiFiClient**[](#wificlient-wificlient)
### **Description**[](#id1)
Constructs a WiFiClient instance that connects to a specified IP address and port.
### **Syntax**[](#id2)
WiFiClient(void);
WiFiClient(uint8_t sock);
WiFiClient(tPortMode portMode);
WiFiClient(tBlockingMode blockMode);
WiFiClient(uint8_t sock, tPortMode portMode);
WiFiClient(uint8_t sock, tPortMode portMode, tBlockingMode blockMode);
### **Parameters**[](#parameters)
sock: socket state
portMode: 0-TCP_MODE, 1-UDP_MODE
blockMode: 0-BLOCKING_MODE, 1-NON_BLOCKING_MODE
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [SimpleHttpRequest](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleHttpRequest/SimpleHttpRequest.ino)
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::connect**[](#wificlient-connect)
### **Description**[](#id3)
Connect to the IP address and port.
### **Syntax**[](#id4)
int connect(const char *host, uint16_t port);
int connect(IPAddress ip, uint16_t port);
### **Parameters**[](#id5)
ip: IP address that the client will connect to.
host: Host name that the client will connect to.
port: the port that the client will connect to.
### **Returns**[](#id6)
This function returns “1” if the connection is successful, else returns
“0”.
### **Example Code**[](#id7)
Example: [SimpleHttpRequest](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleHttpRequest/SimpleHttpRequest.ino)
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::write**[](#wificlient-write)
### **Description**[](#id9)
Write data (single byte) to the server that the client is connected to.
### **Syntax**[](#id10)
size_t write(uint8_t b);
size_t write(const uint8_t *buf, size_t size);
### **Parameters**[](#id11)
b: the byte or char to write
buf: a pointer to an array containing the outgoing message
size: the size of the buffer
### **Returns**[](#id12)
This function returns the byte / character that will be written to the
server or the size of the buffer.
### **Example Code**[](#id13)
NA
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::available**[](#wificlient-available)
### **Description**[](#id14)
Get the number of bytes available for reading.
### **Syntax**[](#id15)
int available(void);
### **Parameters**[](#id16)
NA
### **Returns**[](#id17)
This function returns 1 and number of bytes available for reading if there are available data, else returns 0.
### **Example Code**[](#id18)
Example: [SimpleHttpRequest](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleHttpRequest/SimpleHttpRequest.ino)
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::read**[](#wificlient-read)
### **Description**[](#id20)
Read the incoming byte from the server that the client is connected to.
### **Syntax**[](#id21)
int read(void);
int read(uint8_t *buf, size_t size);
int read(char *buf, size_t size);
### **Parameters**[](#id22)
buf: buffer to hold incoming byte
size: maximum size of the buffer
### **Returns**[](#id23)
This function returns the size of the buffer or returns -1 if no buffer is available.
### **Example Code**[](#id24)
Example: [SimpleHttpRequest](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleHttpRequest/SimpleHttpRequest.ino)
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::recv**[](#wificlient-recv)
### **Description**[](#id26)
Read the received byte from the server that the client is connected to.
### **Syntax**[](#id27)
int recv (uint8_t *buf, size_t size);
### **Parameters**[](#id28)
buf: buffer to hold received byte
size: maximum size of the buffer
### **Returns**[](#id29)
This function returns 1 and number of bytes received or returns -1 if no data is available.
### **Example Code**[](#id30)
Example: [SimpleHttpRequest](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleHttpRequest/SimpleHttpRequest.ino)
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::peek**[](#wificlient-peek)
### **Description**[](#id32)
Get the next byte from the current packet without moving on to the next byte.
### **Syntax**[](#id33)
int peek(void);
### **Parameters**[](#id34)
NA
### **Returns**[](#id35)
This function returns the next byte or character, else returns -1 if none is available.
### **Example Code**[](#id36)
NA
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::flush**[](#wificlient-flush)
### **Description**[](#id37)
Clear all the bytes that have been written to the client but not yet read.
### **Syntax**[](#id38)
void flush(void);
### **Parameters**[](#id39)
NA
### **Returns**[](#id40)
NA
### **Example Code**[](#id41)
NA
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::stop**[](#wificlient-stop)
### **Description**[](#id42)
Disconnect from the server.
### **Syntax**[](#id43)
void stop(void);
### **Parameters**[](#id44)
NA
### **Returns**[](#id45)
NA
### **Example Code**[](#id46)
Example: [SimpleHttpRequest](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleHttpRequest/SimpleHttpRequest.ino)
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::connected**[](#wificlient-connected)
### **Description**[](#id48)
Check if client is connected.
### **Syntax**[](#id49)
virtual uint8_t connected(void);
### **Parameters**[](#id50)
NA
### **Returns**[](#id51)
This function returns “1” if connected, returns “0” if not connected.
### **Example Code**[](#id52)
Example: [SimpleHttpRequest](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleHttpRequest/SimpleHttpRequest.ino)
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::setRecvTimeout**[](#wificlient-setrecvtimeout)
### **Description**[](#id54)
Set the amount of time the client will wait for new data to arrive each time WiFiClient::read() is called.
### **Syntax**[](#id55)
int setRecvTimeout(int timeout);
### **Parameters**[](#id56)
timeout: timeout in seconds
### **Returns**[](#id57)
This function returns “0” if client is not connected.
### **Example Code**[](#id58)
NA
Note
“WiFiClient.h” must be included to use the class function.
## **WiFiClient::setBlockingMode**[](#wificlient-setblockingmode)
### **Description**[](#id59)
Set WiFi Client to blocking mode.
### **Syntax**[](#id60)
void setBlockingMode(void);
### **Parameters**[](#id61)
NA
### **Returns**[](#id62)
NA
### **Example Code**[](#id63)
NA
## **WiFiClient::setNonBlockingMode**[](#wificlient-setnonblockingmode)
### **Description**[](#id64)
Set WiFi Client to non-blocking mode.
### **Syntax**[](#id65)
void setNonBlockingMode(void);
### **Parameters**[](#id66)
NA
### **Returns**[](#id67)
NA
### **Example Code**[](#id68)
NA
[ Previous](Class%20WiFi.html)
[Next ](Class%20WiFiServer.html)
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