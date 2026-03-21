Class WiFiUdp — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [WiFi](index.html)
- Class WiFiUdp
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/WiFi/Class WiFiUdp.rst)
# Class WiFiUdp[](#class-wifiudp)
## **WiFiUDP Class**[](#wifiudp-class)
### **Description**[](#description)
A class used for managing WiFi UDP implementation for Ameba.
### **Syntax**[](#syntax)
class WiFiUDP
### **Members**[](#members)
|**Public Constructors**
|
|
| WiFiUDP::WiFiUDP
|
Constructs a WiFiUDP instance of the Wi-Fi
UDP class that can send and receive UDP
messages.
|
|
| **Public Methods**
|
|
| WiFiUDP::begin
|
Initialize Wi-Fi UDP library, network
settings and start listening at specified
local port.
|
|
| WiFiUDP::stop
|
Disconnect from the server.
|
|
| WiFiUDP::beginPacket
|
Start building up a packet to send to the
remote host-specific in IP and port.
|
|
| WiFiUDP::endPacket
|
Finish off this packet and send it.
|
|
| WiFiUDP::write
|
Write UDP data (single byte) to remote
connection.
|
|
| WiFiUDP::writeImmediately
|
Send packet immediately from the buffer.
|
|
| WiFiUDP::parsePacket
|
Check for the presence of a UDP packets and
start processing the next available incoming
packet.
|
|
| WiFiUDP::available
|
Get the number of bytes (characters)
available for reading from the buffer.
|
|
| WiFiUDP::read
|
Read UDP data from specified buffer.
|
|
| WiFiUDP::peek
|
Get the next byte from the current packet
without moving on to the next byte.
|
|
| WiFiUDP::flush
|
Clear all the bytes that have been written to
the client but not yet read.
|
|
| WiFiUDP::remoteIP
|
Get the IP address of the remote connection
who sent the current incoming packet.
|
|
| WiFiUDP::remotePort
|
Get the port of the remote UDP connection who
sent the current incoming packet.
|
|
| WiFiUDP::setRecvTimeout
|
Set receiving timeout.
|
|
## **WiFiUDP::WiFiUDP**[](#wifiudp-wifiudp)
### **Description**[](#id1)
Constructs a WiFiUDP instance of the Wi-Fi UDP class that can send and receive UDP messages.
### **Syntax**[](#id2)
WiFiUDP (void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [SimpleUDP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleUDP/SimpleUDP.ino)
Note
This constructor does not take in any parameter, thus use another
method to set up the IP address and port number. “WiFiUdp.h” must be
included to use the class function.
## **WiFiUDP::begin**[](#wifiudp-begin)
### **Description**[](#id3)
Initialize Wi-Fi UDP library, network settings and start listening at specified local port.
### **Syntax**[](#id4)
virtual uint8_t begin(uint16_t);
### **Parameters**[](#id5)
port: the local port to listen on
### **Returns**[](#id6)
This function returns 1 if successful, else returns 0 if there are no
sockets available to use.
### **Example Code**[](#id7)
Example: [SimpleUDP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleUDP/SimpleUDP.ino)
Note
“WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::stop**[](#wifiudp-stop)
### **Description**[](#id9)
Disconnect from the server. Release any resource being used during the UDP session.
### **Syntax**[](#id10)
virtual void stop(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
NA
Note
“WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::beginPacket**[](#wifiudp-beginpacket)
### **Description**[](#id14)
Start building up a packet to send to the remote host-specific in IP and port.
### **Syntax**[](#id15)
virtual int beginPacket(IPAddress ip, uint16_t port);
virtual int beginPacket(const char *host, uint16_t port);
### **Parameters**[](#id16)
host: remote host name.
port: the port of the remote connection.
ip: IP address of the remote connection.
### **Returns**[](#id17)
This function returns “1” of successful, else returns “0” if there is a problem with the given IP address or port.
### **Example Code**[](#id18)
Example: [SimpleUDP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleUDP/SimpleUDP.ino)
Note
“WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::endPacket**[](#wifiudp-endpacket)
### **Description**[](#id20)
Finish off the packet and send it.
### **Syntax**[](#id21)
virtual int endPacket(void);
### **Parameters**[](#id22)
NA
### **Returns**[](#id23)
This function returns “1” if packet was sent successfully, else returns “0” if there was an error.
### **Example Code**[](#id24)
Example: [SimpleUDP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleUDP/SimpleUDP.ino)
Note
“WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::write**[](#wifiudp-write)
### **Description**[](#id26)
Write UDP data (single byte) to remote connection.
### **Syntax**[](#id27)
virtual size_t write(uint8_t);
virtual size_t write(const uint8_t *buffer, size_t size);
### **Parameters**[](#id28)
buf: a pointer to an array containing the outgoing message.
size: the size of the buffer.
### **Returns**[](#id29)
This function returns the byte / character that will be written to the server or the size of the buffer.
### **Example Code**[](#id30)
Example: [SimpleUDP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleUDP/SimpleUDP.ino)
Note
This function must be wrapped between beginPacket() and endPacket(). beginPacket() initializes the packet of data, it is not sent until endPacket() is called. “WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::writeImmediately**[](#wifiudp-writeimmediately)
### **Description**[](#id32)
Send packet immediately from the buffer.
### **Syntax**[](#id33)
int writeImmediately(const uint8_t *buffer, size_t size);
int writeImmediately(const uint8_t *buffer, size_t size, uint32_t peer_ip, uint16_t peer_port);
### **Parameters**[](#id34)
*buffer: a pointer to an array containing the outgoing message.
size: the size of the buffer.
peer_ip: ip address of peer device
peer_port: port number of peer device
### **Returns**[](#id35)
This function returns the byte / character that will be written to the server or the size of the buffer.
### **Example Code**[](#id36)
NA
Note
“WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::parsePacket**[](#wifiudp-parsepacket)
### **Description**[](#id37)
Check for the presence of a UDP packets and start processing the next available incoming packet.
### **Syntax**[](#id38)
virtual int parsePacket(void);
### **Parameters**[](#id39)
NA
### **Returns**[](#id40)
This function returns the number of bytes available in the current packet, will return “0” if WiFiUDP.parsePacket() hasn’t been called yet.
### **Example Code**[](#id41)
Example: [SimpleUDP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleUDP/SimpleUDP.ino)
Note
“WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::available**[](#wifiudp-available)
### **Description**[](#id43)
Get the number of bytes (characters) available for reading from the buffer.
### **Syntax**[](#id44)
virtual int available(void);
### **Parameters**[](#id45)
NA
### **Returns**[](#id46)
This function returns the number of bytes available in the current packet, else returns “0” if WiFiUDP.parsePacket() hasn’t been called yet.
### **Example Code**[](#id47)
NA
Note
This function can only be successfully called after WiFiUDP.parsePacket(). “WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::read**[](#wifiudp-read)
### **Description**[](#id48)
Read UDP data from specified buffer.
### **Syntax**[](#id49)
virtual int read (void);
virtual int read (char *buffer, size_t len);
### **Parameters**[](#id50)
buf: buffer to hold incoming byte.
size: maximum size of the buffer.
### **Returns**[](#id51)
This function returns the size of the buffer or returns -1 if no buffer is available.
### **Example Code**[](#id52)
Example: [SimpleUDP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleUDP/SimpleUDP.ino)
Note
This function can only be successfully called after WiFiUDP.parsePacket(). “WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::peek**[](#wifiudp-peek)
### **Description**[](#id54)
Get the next byte from the current packet without moving on to the next byte.
### **Syntax**[](#id55)
virtual int peek (void);
### **Parameters**[](#id56)
NA
### **Returns**[](#id57)
This function returns the next byte or character or returns -1 if none is available.
### **Example Code**[](#id58)
NA
Note
“WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::flush**[](#wifiudp-flush)
### **Description**[](#id59)
Clear all the bytes that have been written to the client but not yet read.
### **Syntax**[](#id60)
virtual void flush(void);
### **Parameters**[](#id61)
NA
### **Returns**[](#id62)
NA
### **Example Code**[](#id63)
NA
Note
“WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::remoteIP**[](#wifiudp-remoteip)
### **Description**[](#id64)
Get the IP address of the remote connection who sent the current incoming packet.
### **Syntax**[](#id65)
virtual IPAddress remoteIP(void);
### **Parameters**[](#id66)
NA
### **Returns**[](#id67)
This function returns the IP address of the remote connection.
### **Example Code**[](#id68)
Example: [SimpleUDP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleUDP/SimpleUDP.ino)
Note
This function must be called after WiFiUDP.parsePacket(). “WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::remotePort**[](#wifiudp-remoteport)
### **Description**[](#id70)
Get the port of the remote UDP connection who sent the current incoming packet.
### **Syntax**[](#id71)
virtual uint16_t remotePort(void);
### **Parameters**[](#id72)
NA
### **Returns**[](#id73)
This function returns the port of the remote connection.
### **Example Code**[](#id74)
Example: [SimpleUDP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SimpleUDP/SimpleUDP.ino)
Note
This function must be called after WiFiUDP.parsePacket(). “WiFiUdp.h” must be included to use the class function.
## **WiFiUDP::setRecvTimeout**[](#wifiudp-setrecvtimeout)
### **Description**[](#id76)
Set receiving timeout.
### **Syntax**[](#id77)
void setRecvTimeout(int timeout);
### **Parameters**[](#id78)
timeout: timeout in seconds.
### **Returns**[](#id79)
NA
### **Example Code**[](#id80)
NA
Note
“WiFiUdp.h” must be included to use the class function.
[ Previous](Class%20WiFiSSLClient.html)
[Next ](Class%20WiFi_eap.html)
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