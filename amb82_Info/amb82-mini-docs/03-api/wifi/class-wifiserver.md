Class WiFiServer — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [WiFi](index.html)
- Class WiFiServer
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/WiFi/Class WiFiServer.rst)
# Class WiFiServer[](#class-wifiserver)
## **WiFiServer Class**[](#wifiserver-class)
### **Description**[](#description)
A class of WiFi server implementation for Ameba.
### **Syntax**[](#syntax)
class WiFiServer
### **Members**[](#members)
|**Public Constructors**
|
|
| WiFiServer::WiFiServer
|
Constructs a WiFiServer object and creates
a server that listens for incoming
connections on the specified port.
|
|
| **Public Methods**
|
|
| WiFiServer::available
|
Gets a client that is connected to the
server and has data available for reading.
|
|
| WiFiServer::begin
|
Server start listening for incoming
connections.
|
|
| WiFiServer::write
|
Write data to all the clients connected to
a server.
|
|
| WiFiServer::stop
|
Stops a server connection
|
|
| WiFiServer::setBlockingMode
|
Set WiFi Server to blocking mode.
|
|
| WiFiServer::
setNonBlockingMode
|
Set WiFi Client to non-blocking mode.
|
|
| WiFiServer::end
|
Stops server connection
|
|
| WiFiServer::close
|
Stops server connection
|
|
## **WiFiServer::WiFiServer**[](#wifiserver-wifiserver)
### **Description**[](#id1)
Constructs a WiFiServer object and creates a server that listens for incoming connections on the specified port.
### **Syntax**[](#id2)
WiFiServer (uint16_t port);
WiFiServer(tPortMode portMode);
WiFiServer(tBlockingMode blockMode);
WiFiServer(uint16_t port, tPortMode portMode);
WiFiServer(uint16_t port, tPortMode portMode, tBlockingMode blockMode);
### **Parameters**[](#parameters)
port: The port number being connected to.
portMode: 0-TCP_MODE, 1-UDP_MODE
blockMode: 0-BLOCKING_MODE, 1-NON_BLOCKING_MODE
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [SimpleTCPServer.ino](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleTCPServer/SimpleTCPServer.ino)
Note
“WiFiServer.h” must be included to use the class function.
## **WiFiServer::available**[](#wifiserver-available)
### **Description**[](#id3)
Gets a client that is connected to the server and has data available for reading. The connection persists when the returned client object goes out of scope; you can close it by calling the client.stop().
### **Syntax**[](#id4)
WiFiClient available(uint8_t *status = NULL);
### **Parameters**[](#id5)
status: Wi-Fi availability status. Default value is NULL.
### **Returns**[](#id6)
This function returns a client object; if no Client has data available for reading, this object will evaluate to false in an if-statement
### **Example Code**[](#id7)
Example: [SimpleTCPServer.ino](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleTCPServer/SimpleTCPServer.ino)
Note
“WiFiServer.h” must be included to use the class function.
## **WiFiServer::begin**[](#wifiserver-begin)
### **Description**[](#id9)
Server start listening for incoming connections.
### **Syntax**[](#id10)
void begin(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [SimpleTCPServer.ino](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleTCPServer/SimpleTCPServer.ino)
Note
“WiFiServer.h” must be included to use the class function.
## **WiFiServer::connected**[](#wifiserver-connected)
### **Description**[](#id15)
Check if server is still connected.
### **Syntax**[](#id16)
uint8_t connected(void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
This function returns “1” if connected, returns “0” if not connected.
### **Example Code**[](#id19)
NA
Note
“WiFiServer.h” must be included to use the class function.
## **WiFiServer::write**[](#wifiserver-write)
### **Description**[](#id20)
Write data to all the clients connected to a server.
### **Syntax**[](#id21)
virtual size_t write(uint8_t b);
### **Parameters**[](#id22)
b: byte to be written.
buf: data buffer.
size: size of the data buffer.
### **Returns**[](#id23)
This function returns the number of bytes written. It is not necessary to read this.
### **Example Code**[](#id24)
Example: [SimpleTCPServer.ino](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleTCPServer/SimpleTCPServer.ino)
Note
“WiFiServer.h” must be included to use the class function.
## **WiFiServer::stop**[](#wifiserver-stop)
### **Description**[](#id26)
Stops a server connection.
### **Syntax**[](#id27)
void stop(void);
### **Parameters**[](#id28)
NA
### **Returns**[](#id29)
NA
### **Example Code**[](#id30)
NA
Note
“WiFiServer.h” must be included to use the class function.
## **WiFiServer::end**[](#wifiserver-end)
### **Description**[](#id31)
Stops a server connection.
### **Syntax**[](#id32)
void end(void);
### **Parameters**[](#id33)
NA
### **Returns**[](#id34)
NA
### **Example Code**[](#id35)
NA
Note
“WiFiServer.h” must be included to use the class function.
## **WiFiServer::close**[](#wifiserver-close)
### **Description**[](#id36)
Stops a server connection.
### **Syntax**[](#id37)
void close(void);
### **Parameters**[](#id38)
NA
### **Returns**[](#id39)
NA
### **Example Code**[](#id40)
NA
Note
“WiFiServer.h” must be included to use the class function.
## **WiFiServer::setBlockingMode**[](#wifiserver-setblockingmode)
### **Description**[](#id41)
Set WiFi Server to blocking mode.
### **Syntax**[](#id42)
void setBlockingMode(void);
### **Parameters**[](#id43)
NA
### **Returns**[](#id44)
NA
### **Example Code**[](#id45)
NA
## **WiFiServer::setNonBlockingMode**[](#wifiserver-setnonblockingmode)
### **Description**[](#id46)
Set WiFi Server to non-blocking mode.
### **Syntax**[](#id47)
void setNonBlockingMode(void);
### **Parameters**[](#id48)
NA
### **Returns**[](#id49)
NA
### **Example Code**[](#id50)
NA
[ Previous](Class%20WiFiClient.html)
[Next ](Class%20WiFiSSLClient.html)
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