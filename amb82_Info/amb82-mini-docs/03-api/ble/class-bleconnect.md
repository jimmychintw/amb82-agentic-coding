Class BLEConnect — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEConnect
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEConnect.rst)
# Class BLEConnect[](#class-bleconnect)
## **BLEConnect Class**[](#bleconnect-class)
### **Description**[](#description)
A class used for managing BLE connection settings.
### **Syntax**[](#syntax)
class BLEConnect
### **Members**[](#members)
|**Public Constructors**
|
|
| No public constructor is available as this class is intended to be a
singleton class. You can get a pointer to this class using
BLEDevice::configConnection
|
|
| **Public Methods**
|
|
| BLEConnect::connect
|
Scan and search for all accessible
BLE devices, then select and
connect to one of them
|
|
| BLEConnect::disconnect
|
Disconnect from targeted BLE device
|
|
| BLEConnect::setScanInterval
|
Set the scan interval when
searching for the targeted device
|
|
| BLEConnect::setScanWindow
|
Set the BLE scan window when
searching for the targeted device
to connect to
|
|
| BLEConnect::setConnInterval
|
Set the BLE connection interval
duration
|
|
| BLEConnect::setConnLatency
|
Set the BLE connection slave
latency value
|
|
| BLEConnect::setConnTimeout
|
Set the BLE connection timeout
value
|
|
| BLEConnect::updateConnParams
|
Update a connected device with new
connection parameters
|
|
| BLEConnect::getConnInfo
|
Get connection information
|
|
| BLEConnect::getConnAddr
|
Get the Bluetooth address for a
certain connection
|
|
| BLEConnect::getConnId
|
Get the connection ID for a certain
device
|
|
## **BLEConnect::connect**[](#bleconnect-connect)
### **Description**[](#id1)
This class function is used to scan and search for all accessible BLE devices, then select and connect to one of them.
### **Syntax**[](#id2)
bool connect(char* btAddr, T_GAP_REMOTE_ADDR_TYPE destAddrType, uint16_t scanTimeout);
bool connect(uint8_t (&btAddr)[6], T_GAP_REMOTE_ADDR_TYPE destAddrType, uint16_t scanTimeout);
bool connect(BLEAdvertData targetDevice, uint16_t scanTimeout);
bool connect(BLEAddr destAddr, T_GAP_REMOTE_ADDR_TYPE destAddrType, uint16_t scanTimeout);
### **Parameters**[](#parameters)
char* btAddr: pointer to the targeted BLE device’s Bluetooth address expressed as a character string.
uint8_t (&btAddr): targeted BLE device’s Bluetooth address contained in a 6-byte array.
destAddr: targeted BLE device’s Bluetooth address contained in BLEAddr class object.
targetDevice: advertising data packet scanned from targeted BLE device.
destAddrType: Bluetooth address type of targeted BLE device.
- GAP_REMOTE_ADDR_LE_PUBLIC
- GAP_REMOTE_ADDR_LE_RANDOM
scan timeout: duration in milliseconds for which to look for the targeted BLE device before giving up.
### **Returns**[](#returns)
This function returns true if the connection is successful, otherwise false.
### **Example Code**[](#example-code)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
“BLEConnect.h” must be included to use the class function.
## **BLEConnect::disconnect**[](#bleconnect-disconnect)
### **Description**[](#id3)
Disconnect from targeted BLE device.
### **Syntax**[](#id4)
bool disconnect(uint8_t connId);
### **Parameters**[](#id5)
connId: connection ID for target device. Default value is 0.
### **Returns**[](#id6)
This function returns true if the operation is successful, otherwise false.
### **Example Code**[](#id7)
NA
Note
“BLEConnect.h” must be included to use the class function.
## **BLEConnect::setScanInterval**[](#bleconnect-setscaninterval)
### **Description**[](#id8)
Set the scan interval when searching for the targeted device.
### **Syntax**[](#id9)
void setScanInterval(uint16_t scanInt_ms);
### **Parameters**[](#id10)
scanInt_ms: scan interval in milliseconds.
- 3 to 10240.
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
NA
Note
Scan interval defines how often the scanning process is started. The value set for scanInt_ms must be equal or larger than the value set for scanWindow_ms. scanInt_ms value is defined in units of 625 microseconds. “BLEConnect.h” must be included to use the class function.
## **BLEConnect::setScanWindow**[](#bleconnect-setscanwindow)
### **Description**[](#id13)
Set the BLE scan window when searching for the targeted device to connect to.
### **Syntax**[](#id14)
void setScanWindow(uint16_t scanWindow_ms);
### **Parameters**[](#id15)
scanWindow_ms: scan window in milliseconds.
- 3 to 10240.
### **Returns**[](#id16)
NA
### **Example Code**[](#id17)
NA
Note
BLE scan window defines how long each interval should be scanned for. The value set for scanWindow_ms set must be equal or smaller than the value set for scanInt_ms. scanWindow_ms value is defined in units of 625 microseconds. “BLEConnect.h” must be included to use the class function.
## **BLEConnect::setConnInterval**[](#bleconnect-setconninterval)
### **Description**[](#id18)
Set the BLE connection interval duration.
### **Syntax**[](#id19)
void setConnInterval(uint16_t min_ms, uint16_t max_ms);
### **Parameters**[](#id20)
min_ms: minimum acceptable connection interval in milliseconds.
- 8 to 4000.
max_ms: maximum acceptable connection interval in milliseconds.
- 8 to 4000.
### **Returns**[](#id21)
NA
### **Example Code**[](#id22)
NA
Note
The BLE connection interval defines the period between successive connection events between a connected central and peripheral device. Even if there is no data to exchange, a connection event is required to maintain the connection. max_ms should be larger than or equal to min_ms. “BLEConnect.h” must be included to use the class function.
## **BLEConnect::setConnLatency**[](#bleconnect-setconnlatency)
### **Description**[](#id23)
Set the BLE connection slave latency value.
### **Syntax**[](#id24)
void setConnLatency(uint16_t latency);
### **Parameters**[](#id25)
latency: Connection slave latency value.
- 0 to 499.
### **Returns**[](#id26)
NA
### **Example Code**[](#id27)
NA
Note
The BLE connection slave latency defines the number of successive connection events a connected peripheral device can ignore without being considered as disconnected by the central device. “BLEConnect.h” must be included to use the class function.
## **BLEConnect::setConnTimeout**[](#bleconnect-setconntimeout)
### **Description**[](#id28)
Set the BLE connection timeout value.
### **Syntax**[](#id29)
void setConnTimeout(uint16_t timeout_ms);
### **Parameters**[](#id30)
timeout_ms: connection timeout in milliseconds.
- 100 to 32000.
### **Returns**[](#id31)
NA
### **Example Code**[](#id32)
NA
Note
The BLE connection timeout defines the duration a peripheral or central device must wait after a failed connection event to consider the connection broken. “BLEConnect.h” must be included to use the class function.
## **BLEConnect::updateConnParams**[](#bleconnect-updateconnparams)
### **Description**[](#id33)
Update a connected device with new connection parameters.
### **Syntax**[](#id34)
void updateConnParams(uint8_t conn_id);
### **Parameters**[](#id35)
conn_id: connection ID of targeted device to update connection parameters.
### **Returns**[](#id36)
NA
### **Example Code**[](#id37)
NA
Note
Update the connected device with new connection parameters such as connection interval, slave latency and timeout values. The connected device may reject the new values if it is unable to conform to them. “BLEConnect.h” must be included to use the class function.
## **BLEConnect::getConnInfo**[](#bleconnect-getconninfo)
### **Description**[](#id38)
Get connection information.
### **Syntax**[](#id39)
bool getConnInfo(uint8_t connId, T_GAP_CONN_INFO *pConnInfo);
### **Parameters**[](#id40)
connId: connection ID to device get connection information from.
pConnInfo: pointer to T_GAP_CONN_INFO structure to store obtained connection information.
### **Returns**[](#id41)
This function returns true if the connection information is successfully obtained. Otherwise, false.
### **Example Code**[](#id42)
NA
Note
“BLEConnect.h” must be included to use the class function.
## **BLEConnect::getConnAddr**[](#bleconnect-getconnaddr)
### **Description**[](#id43)
Get the Bluetooth address for a certain connection.
### **Syntax**[](#id44)
bool getConnAddr(uint8_t connId, uint8_t* addr, uint8_t* addrType);
### **Parameters**[](#id45)
connId: connection ID of device to get Bluetooth address of.
addr: pointer to 6 byte array to store retrieved Bluetooth address.
addrType: pointer to uint8_t variable to store retrieved Bluetooth address type.
### **Returns**[](#id46)
This function returns true if the connection address information is successfully obtained. Otherwise, false.
### **Example Code**[](#id47)
NA
Note
“BLEConnect.h” must be included to use the class function.
## **BLEConnect::getConnId**[](#bleconnect-getconnid)
### **Description**[](#id48)
Get the connection ID for a certain device.
### **Syntax**[](#id49)
int8_t getConnId(char* btAddr, uint8_t addrType);
int8_t getConnId(uint8_t* btAddr, uint8_t addrType);
int8_t getConnId(BLEAdvertData targetDevice);
### **Parameters**[](#id50)
char* btAddr: targeted device Bluetooth address expressed as a character string.
uint8_t* btAddr: pointer to a 6-byte array containing targeted device Bluetooth address.
targetDevice: advertising data packet scanned from targeted device.
addrType: Bluetooth address type of targeted device.
- GAP_REMOTE_ADDR_LE_PUBLIC
- GAP_REMOTE_ADDR_LE_RANDOM
### **Returns**[](#id51)
This function returns the requested connection ID. Else, returns -1 if failed to obtain connection ID.
### **Example Code**[](#id52)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
“BLEConnect.h” must be included to use the class function.
[ Previous](Class%20BLEClient.html)
[Next ](Class%20BLEDevice.html)
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