Class WiFiSSLClient — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [WiFi](index.html)
- Class WiFiSSLClient
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/WiFi/Class WiFiSSLClient.rst)
# Class WiFiSSLClient[](#class-wifisslclient)
## **WiFiSSLClient Class**[](#wifisslclient-class)
### **Description**[](#description)
A class for Wi-Fi Secure Socket Layer Client implementation for Ameba.
### **Syntax**[](#syntax)
class WiFiSSLClient
### **Members**[](#members)
|**Public Constructors**
|
|
| WiFiSSLClient::WiFiSSLClient
|
Constructs a WiFiSSLClient instance that always connects in SSL
to the specified IP address and port.
|
|
| **Public Methods**
|
|
| WiFiSSLClient::connect
|
Connect to the IP address and port.
|
|
| WiFiSSLClient::write
|
Write data (single byte) to the server.
|
|
| WiFiSSLClient::available
|
Get the availability of the Wi-Fi SSL socket for reading.
|
|
| WiFiSSLClient::read
|
Read the incoming byte from the server.
|
|
| WiFiSSLClient::peek
|
Get the next byte from the current packet without moving on
to the next byte.
|
|
| WiFiSSLClient::flush
|
Clear all the bytes that have been written to the client but not
yet read.
|
|
| WiFiSSLClient::stop
|
Disconnect from the server.
|
|
| WiFiSSLClient::connected
|
Check if SSL client is connected.
|
|
| WiFiSSLClient::setRootCA
|
Set Root CA for authentication.
|
|
| WiFiSSLClient::setClientCertificate
|
Set certificate of the client.
|
|
| WiFiSSLClient::setRecvTimeout
|
Set receiving timeout.
|
|
| WiFiSSLClient::setPreSharedKey
|
Set the Pre Shared Key (PSK) to use for authentication.
|
|
## **WiFiSSLClient::WiFiSSLClient**[](#wifisslclient-wifisslclient)
### **Description**[](#id1)
Constructs a WiFiSSLClient instance that always connects in SSL to the specified IP address and port.
### **Syntax**[](#id2)
WiFiSSLClient(void);
WiFiSSLClient(uint8_t sock);
### **Parameters**[](#parameters)
sock: socket state, default -1.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [SSLClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SSLClient/SSLClient.ino)
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::connect**[](#wifisslclient-connect)
### **Description**[](#id3)
Connect to the IP address and port.
### **Syntax**[](#id4)
virtual int connect(IPAddress ip, uint16_t port);
virtual int connect(const char *host, uint16_t port);
int connect(const char *host, uint16_t port, unsigned char *rootCABuff, unsigned char *cli_cert, unsigned char *cli_key);
int connect(IPAddress ip, uint16_t port, unsigned char *rootCABuff, unsigned char *cli_cert, unsigned char *cli_key);
int connect(const char *host, uint16_t port, unsigned char *pskIdent, unsigned char *psKey);
int connect(IPAddress ip, uint16_t port, unsigned char *pskIdent, unsigned char *psKey);
### **Parameters**[](#id5)
ip: IP address.
host: Host name.
port: the port to listen to.
rootCABuff: buffer that store root CA.
cli_cert: buffer that store client certificate.
cli_key: buffer that store client key pair.
pskIdent: identity for PSK.
psKey: Pre shared key.
### **Returns**[](#id6)
This function returns “1” if successful, else returns “0”.
### **Example Code**[](#id7)
Example: [SSLClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SSLClient/SSLClient.ino)
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::write**[](#wifisslclient-write)
### **Description**[](#id9)
Write data (single byte) to the server the SSL client is connected to.
### **Syntax**[](#id10)
virtual size_t write(uint8_t);
virtual size_t write(const uint8_t *buf, size_t size);
### **Parameters**[](#id11)
buf: a pointer to an array containing the outgoing message.
size: the size of the buffer.
### **Returns**[](#id12)
This function returns the byte / character that will be written to the server or the size of the buffer.
### **Example Code**[](#id13)
NA
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::available**[](#wifisslclient-available)
### **Description**[](#id14)
Get the availability of the Wi-Fi SSL socket for reading.
### **Syntax**[](#id15)
virtual int available(void);
### **Parameters**[](#id16)
NA
### **Returns**[](#id17)
This function returns “1” and number of bytes available for reading if there are available data, else returns 0.
### **Example Code**[](#id18)
Example: [SSLClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SSLClient/SSLClient.ino)
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::read**[](#wifisslclient-read)
### **Description**[](#id20)
Read the incoming byte from the server that the SSL client is connected to.
### **Syntax**[](#id21)
virtual int read(void);
virtual int read(uint8_t *buf, size_t size);
### **Parameters**[](#id22)
buf: buffer that holds incoming data in 8-bit.
size: maximum size of the buffer.
### **Returns**[](#id23)
This function returns the size of the buffer or returns “-1” if no buffer is available.
### **Example Code**[](#id24)
Example: [SSLClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SSLClient/SSLClient.ino)
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::peek**[](#wifisslclient-peek)
### **Description**[](#id26)
Get the next byte from the current packet without moving on to the next byte.
### **Syntax**[](#id27)
virtual int peek(void);
### **Parameters**[](#id28)
NA
### **Returns**[](#id29)
This function returns the next byte or character, else returns -1 if none is available.
### **Example Code**[](#id30)
NA
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::flush**[](#wifisslclient-flush)
### **Description**[](#id31)
Clear all the bytes that have been written to the client but not yet read.
### **Syntax**[](#id32)
virtual void flush(void);
### **Parameters**[](#id33)
NA
### **Returns**[](#id34)
NA
### **Example Code**[](#id35)
NA
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::stop**[](#wifisslclient-stop)
### **Description**[](#id36)
Disconnect from the server.
### **Syntax**[](#id37)
virtual void stop (void);
### **Parameters**[](#id38)
NA
### **Returns**[](#id39)
NA
### **Example Code**[](#id40)
Example: [SSLClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SSLClient/SSLClient.ino)
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::connected**[](#wifisslclient-connected)
### **Description**[](#id42)
Check if SSL client is connected.
### **Syntax**[](#id43)
virtual uint8_t connected(void);
### **Parameters**[](#id44)
NA
### **Returns**[](#id45)
The function returns “1” if the SSLClient socket is connected, else returns “0” if not connected.
**Example Code**
Example: [SSLClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/SSLClient/SSLClient.ino)
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::setRootCA**[](#wifisslclient-setrootca)
### **Description**[](#id47)
Set Root CA(certification authority) for SSL authentication.
### **Syntax**[](#id48)
void setRootCA(unsigned char *rootCA);
### **Parameters**[](#id49)
rootCA: a string of rootCA.
### **Returns**[](#id50)
NA
### **Example Code**[](#id51)
NA
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::setClientCertificate**[](#wifisslclient-setclientcertificate)
### **Description**[](#id52)
Set certificate of the client.
### **Syntax**[](#id53)
void setClientCertificate(unsigned char *client_ca, unsigned char *private_key);
### **Parameters**[](#id54)
client_ca: Client certificate.
private_key: client’s private key pair.
### **Returns**[](#id55)
NA
### **Example Code**[](#id56)
NA
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::setRecvTimeout**[](#wifisslclient-setrecvtimeout)
### **Description**[](#id57)
This function sets the SSL client socket receiving timeout.
### **Syntax**[](#id58)
int setRecvTimeout(int timeout);
### **Parameters**[](#id59)
timeout: timeout in seconds.
### **Returns**[](#id60)
The function returns “0”.
### **Example Code**[](#id61)
NA
Note
“WiFiSSLClient.h” must be included to use the class function.
## **WiFiSSLClient::setPreSharedKey**[](#wifisslclient-setpresharedkey)
### **Description**[](#id62)
Set the Pre Shared Key (PSK) to use for authentication.
### **Syntax**[](#id63)
void setPreSharedKey(unsigned char *pskIdent, unsigned char *psKey);
### **Parameters**[](#id64)
pskIdent: identity for PSK.
psKey: Pre shared key.
### **Returns**[](#id65)
NA
### **Example Code**[](#id66)
NA
Note
Do not set a root CA and client certificate if PSK should be used for authentication. If root CA, client certificate and PSK are all set, certificate-based authentication will be used. “WiFiSSLClient.h” must be included to use the class function.
[ Previous](Class%20WiFiServer.html)
[Next ](Class%20WiFiUdp.html)
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