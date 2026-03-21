Class BLEClient — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEClient
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEClient.rst)
# Class BLEClient[](#class-bleclient)
## **BLEClient Class**[](#bleclient-class)
### **Description**[](#description)
A class used for discovering and accessing BLE GATT services on a connected remote device.
### **Syntax**[](#syntax)
class BLEClient
### **Members**[](#members)
|**Public Constructors**
|
|
| No public constructor is available for this class. You can get a pointer
to an instance of this class using BLEDevice::addClient().
|
|
| **Public Methods**
|
|
| BLEClient::connected
|
Check if the remote device
associated with the client is
connected.
|
|
| BLEClient::discoverServices
|
Start service discovery process
for connected device
|
|
| BLEClient::discoveryDone
|
Determine if service discovery
process has been completed
|
|
| BLEClient::printServices
|
Format and print discovered
services to serial port
|
|
| BLEClient::getService
|
Get a service with the
specified UUID on the remote
device
|
|
| BLEClient::getConnId
|
Get connection ID corresponding
to remote device
|
|
| BLEClient::getClientId
|
Get corresponding client ID
|
|
| BLEClient::setDisconnectCallback
|
Set a user function to be
called when the remote device
is disconnected
|
|
## **BLEClient::connected**[](#bleclient-connected)
### **Description**[](#id1)
Check if the remote device associated with the client is connected.
### **Syntax**[](#id2)
bool connected(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
This function returns TRUE if the remote device is connected.
### **Example Code**[](#example-code)
NA
Note
“BLEClient.h” must be included to use the class function.
## **BLEClient::discoverServices**[](#bleclient-discoverservices)
### **Description**[](#id3)
Start the service discovery process for the connected remote device.
### **Syntax**[](#id4)
void discoverServices(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [BLEUartClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartClient/BLEUartClient.ino)
Note
“BLEClient.h” must be included to use the class function.
**BLEClient::discoveryDone**
### **Description**[](#id8)
Determine if the service discovery process has been completed.
### **Syntax**[](#id9)
bool discoveryDone(void);
### **Parameters**[](#id10)
NA
### **Returns**[](#id11)
This function returns TRUE if the service discovery process has been completed successfully, FALSE if the service discovery process failed, is still in progress, or has yet to start.
### **Example Code**[](#id12)
Example: [BLEUartClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartClient/BLEUartClient.ino)
Note
“BLEClient.h” must be included to use the class function.
## **BLEClient::printServices**[](#bleclient-printservices)
### **Description**[](#id14)
Print out a formatted list of discovered services to the serial port.
### **Syntax**[](#id15)
void printServices(void);
### **Parameters**[](#id16)
NA
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
NA
Note
“BLEClient.h” must be included to use the class function.
## **BLEClient::getService**[](#bleclient-getservice)
### **Description**[](#id19)
Get a service with the specified UUID on the remote device.
### **Syntax**[](#id20)
BLERemoteService* getService(const char* uuid);
BLERemoteService* getService(BLEUUID uuid);
### **Parameters**[](#id21)
uuid: the desired service UUID, expressed as a character array or a BLEUUID object.
### **Returns**[](#id22)
This function returns the discovered service as a BLERemoteService object pointer, otherwise nullptr is returned if a service with the UUID is not found.
### **Example Code**[](#id23)
Example: [BLEUartClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEUartClient/BLEUartClient.ino)
Note
“BLEClient.h” must be included to use the class function.
## **BLEClient::getConnId**[](#bleclient-getconnid)
### **Description**[](#id25)
Get the connection ID associated with the remote device.
### **Syntax**[](#id26)
uint8_t getConnId(void);
### **Parameters**[](#id27)
NA
### **Returns**[](#id28)
This function returns the connection ID for the connected remote device.
### **Example Code**[](#id29)
NA
Note
“BLEClient.h” must be included to use the class function.
## **BLEClient::getClientId**[](#bleclient-getclientid)
### **Description**[](#id30)
Get the client ID for the BLEClient object.
### **Syntax**[](#id31)
T_CLIENT_ID getClientId(void);
### **Parameters**[](#id32)
NA
### **Returns**[](#id33)
This function returns the BLEClient object’s client ID.
### **Example Code**[](#id34)
NA
Note
The client ID is used when calling internal GATT client API. “BLEClient.h” must be included to use the class function.
## **BLEClient::setDisconnectCallback**[](#bleclient-setdisconnectcallback)
### **Description**[](#id35)
Set a user function as a callback function when the remote device is disconnected.
### **Syntax**[](#id36)
void setDisconnectCallback(void (*fCallback) (BLEClient* client));
### **Parameters**[](#id37)
fCallback: A user callback function that returns void and takes one argument.
client: A pointer to the BLEClient object corresponding to the disconnected remote device.
### **Returns**[](#id38)
NA
### **Example Code**[](#id39)
NA
Note
The user callback function will be called after the remote device has disconnected, before the characteristics, services and client associated with the remote device are deleted. “BLEClient.h” must be included to use the class function.
[ Previous](Class%20BLECharacteristic.html)
[Next ](Class%20BLEConnect.html)
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