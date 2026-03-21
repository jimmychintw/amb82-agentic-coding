Class BLEDevice — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEDevice
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEDevice.rst)
# Class BLEDevice[](#class-bledevice)
## **BLEDevice Class**[](#bledevice-class)
### **Description**[](#description)
A class used for general control and management of BLE functions.
### **Syntax**[](#syntax)
class BLEDevice
### **Members**[](#members)
|**Public Constructors**
|
|
| The public constructor should not be used as this class is intended to
be a singleton class. Access member functions using the object instance
named BLE.
|
|
| **Public Methods**
|
|
| BLEDevice:: init
|
Initialize resources that are
required for BLE to function
|
|
| BLEDevice::deinit
|
Deinitialize all the operations for
BLE.
|
|
| BLEDevice::connected
|
Check if a BLE device is connected
|
|
| BLEDevice::setDeviceName
|
Set BLE Generic Access Profile
(GAP) device name
|
|
| BLEDevice::setDeviceAppearance
|
Set BLE Generic Access Profile
(GAP) device appearance
|
|
| BLEDevice::configAdvert
|
Configure BLE advertising
parameters
|
|
| BLEDevice::configScan
|
Configure BLE scan parameters
|
|
| BLEDevice::configConnection
|
Configure BLE connection parameters
|
|
| BLEDevice::configSecurity
|
Configure BLE bonding security
parameters
|
|
| BLEDevice::setScanCallback
|
Set callback function for BLE scan
results
|
|
| BLEDevice::beginCentral
|
Start BLE stack to operate as a
central device.
|
|
| BLEDevice::beginPeripheral
|
Start BLE stack to operate as a
peripheral device.
|
|
| BLEDevice::end
|
Stop the operation of BLE stack as
a peripheral or central device.
|
|
| BLEDevice::configServer
|
Configure BLE stack for services
|
|
| BLEDevice::addService
|
Add a service to the BLE stack
|
|
| BLEDevice::configClient
|
Configure BLE stack for clients
|
|
| BLEDevice::addClient
|
Add a new client to the BLE stack
|
|
| BLEDevice::getLocalAddr
|
Get local device Bluetooth address
|
|
## **BLEDevice:: init**[](#bledevice-init)
### **Description**[](#id1)
Initialize resources that are required for BLE to function.
### **Syntax**[](#id2)
void init(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
Call this member function first before using any other member functions in the BLEDevice class. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::deinit**[](#bledevice-deinit)
### **Description**[](#id3)
Deinitialize all the operations for BLE.
### **Syntax**[](#id4)
void deinit(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
Call this member function last after all other BLE operations have been terminated. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::connected**[](#bledevice-connected)
### **Description**[](#id8)
Check if a BLE device is connected.
### **Syntax**[](#id9)
bool connected(uint8_t connId);
### **Parameters**[](#id10)
connId: connection ID to check connection status.
### **Returns**[](#id11)
This function returns TRUE if BLE device is connected, otherwise false.
### **Example Code**[](#id12)
NA
Note
Peripheral mode should use connId = 0. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::setDeviceName**[](#bledevice-setdevicename)
### **Description**[](#id13)
Set the BLE Generic Access Profile (GAP) device name which will be visible after a connection is estabalished. The default device name is set as “AMEBA_BLE_DEV”.
### **Syntax**[](#id14)
void setDeviceName(String devName);
### **Parameters**[](#id15)
devName: desired device name expressed as a character string.
### **Returns**[](#id16)
NA
### **Example Code**[](#id17)
NA
Note
The GAP device name has a maximum length of 39 characters. Other devices can see this name after a BLE connection is established. This name is separate and different from the device name sent in a BLE advertisement, the names should be the same but are not required. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::setDeviceAppearance**[](#bledevice-setdeviceappearance)
### **Description**[](#id18)
Set the BLE Generic Access Profile (GAP) device appearance.
### **Syntax**[](#id19)
void setDeviceAppearance(uint16_t devAppearance);
### **Parameters**[](#id20)
devAppearance: desired device appearance expressed as a 16-bit unsigned integer.
### **Returns**[](#id21)
NA
### **Example Code**[](#id22)
NA
Note
Refer to Bluetooth SIG assigned device appearances at [https://www.bluetooth.com/specifications/gatt/characteristics/](https://www.bluetooth.com/specifications/gatt/characteristics/). “BLEDevice.h” must be included to use the class function.
## **BLEDevice::configAdvert**[](#bledevice-configadvert)
### **Description**[](#id23)
Configure BLE advertising parameters.
### **Syntax**[](#id24)
BLEAdvert* configAdvert(void);
### **Parameters**[](#id25)
NA
### **Returns**[](#id26)
This function returns a pointer to a BLEAdvert class instance for configuring BLE advertising parameters.
### **Example Code**[](#id27)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
Use this member function instead of creating a BLEAdvert class instance manually. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::configScan**[](#bledevice-configscan)
### **Description**[](#id29)
Configure BLE scanning parameters.
### **Syntax**[](#id30)
BLEScan* configScan(void);
### **Parameters**[](#id31)
NA
### **Returns**[](#id32)
This function returns a pointer to a BLEScan class instance for configuring BLE scanning parameters.
### **Example Code**[](#id33)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
Use this member function instead of creating a BLEScan class instance manually. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::configConnection**[](#bledevice-configconnection)
### **Description**[](#id34)
Configure BLE connection parameters.
### **Syntax**[](#id35)
BLEConnect* configConnection(void);
### **Parameters**[](#id36)
NA
### **Returns**[](#id37)
This function returns a pointer to a BLEConnect class instance for configuring BLE connection parameters.
### **Example Code**[](#id38)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
Use this member function instead of creating a BLEConnect class instance manually. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::configSecurity**[](#bledevice-configsecurity)
### **Description**[](#id39)
Configure BLE bonding security parameters.
### **Syntax**[](#id40)
BLESecurity* configSecurity(void);
### **Parameters**[](#id41)
NA
### **Returns**[](#id42)
This function returns a pointer to a BLESecurity class instance for configuring BLE bonding security parameters.
### **Example Code**[](#id43)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
Use this member function instead of creating a BLESecurity class instance manually “BLEDevice.h” must be included to use the class function.
## **BLEDevice::setScanCallback**[](#bledevice-setscancallback)
### **Description**[](#id44)
Set a callback function for processing BLE scan results.
### **Syntax**[](#id45)
void setScanCallback(void (*scanCB)(T_LE_CB_DATA*));
### **Parameters**[](#id46)
scanCB: a function that returns nothing and takes in a scan data pointer of type T_LE_CB_DATA.
### **Returns**[](#id47)
NA
### **Example Code**[](#id48)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
Use this member function to set a callback function that will be called for each BLE device scan result found. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::beginCentral**[](#bledevice-begincentral)
### **Description**[](#id50)
Start the BLE stack to operate as a central device.
### **Syntax**[](#id51)
void beginCentral(uint8_t connCount);
### **Parameters**[](#id52)
connCount: maximum number of allowed connected devices. If no argument is provided, default is maximum allowed connected devices for specific board.
### **Returns**[](#id53)
NA
### **Example Code**[](#id54)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
Use this member function to start the device to operate as a central BLE device, after other BLE parameters are set correctly. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::beginPeripheral**[](#bledevice-beginperipheral)
### **Description**[](#id56)
Start the BLE stack to operate as a peripheral device.
### **Syntax**[](#id57)
void beginPeripheral(void);
### **Parameters**[](#id58)
NA
### **Returns**[](#id59)
NA
### **Example Code**[](#id60)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
Use this member function to start the device to operate as a peripheral BLE device, after other BLE parameters are set correctly. “BLEDevice.h” must be included to use the class function.
## **BLEDevice:: end**[](#bledevice-end)
### **Description**[](#id62)
Stop the operation of BLE stack as a peripheral or central device.
### **Syntax**[](#id63)
void end(void);
### **Parameters**[](#id64)
NA
### **Returns**[](#id65)
NA
### **Example Code**[](#id66)
NA
Note
Use this member function to stop the device operating in either BLE peripheral mode or BLE central mode. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::configServer**[](#bledevice-configserver)
### **Description**[](#id67)
Configure the BLE stack for services.
### **Syntax**[](#id68)
void configServer(uint8_t maxServiceCount);
### **Parameters**[](#id69)
maxServiceCount: Maximum number of services that will run on the device.
### **Returns**[](#id70)
NA
### **Example Code**[](#id71)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
Use this member function before adding any service to the BLE stack. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::addService**[](#bledevice-addservice)
### **Description**[](#id73)
Add a new service to the BLE stack.
### **Syntax**[](#id74)
void addService(BLEService& newService);
### **Parameters**[](#id75)
newService: the service to be added, defined using a BLEService class object.
### **Returns**[](#id76)
NA
### **Example Code**[](#id77)
Example: [BLEBatteryService](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryService/BLEBatteryService.ino)
Note
“BLEDevice.h” must be included to use the class function.
## **BLEDevice::configClient**[](#bledevice-configclient)
### **Description**[](#id79)
Configure the BLE stack for clients.
### **Syntax**[](#id80)
void configClient(void);
### **Parameters**[](#id81)
NA
### **Returns**[](#id82)
NA
### **Example Code**[](#id83)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
Use this member function before adding any client to the BLE stack. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::addClient**[](#bledevice-addclient)
### **Description**[](#id85)
Add a new client to the BLE stack.
### **Syntax**[](#id86)
BLEClient* addClient(uint8_t connId);
### **Parameters**[](#id87)
connId: the connection ID of the connected device to create a client for.
### **Returns**[](#id88)
This function returns a pointer to a BLEClient class object, corresponding to the device with the specified connection ID, which can be used to access the services and characteristics on the connected device.
### **Example Code**[](#id89)
Example: [BLEBatteryClient](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEBatteryClient/BLEBatteryClient.ino)
Note
Only one client should be added per connected device. The BLEClient object and any service, characteristic, descriptor associated with the connected device will be deleted when the device is disconnected. “BLEDevice.h” must be included to use the class function.
## **BLEDevice::getLocalAddr**[](#bledevice-getlocaladdr)
### **Description**[](#id91)
Get local device Bluetooth address.
### **Syntax**[](#id92)
void getLocalAddr(uint8_t (&addr)[GAP_BD_ADDR_LEN]);
### **Parameters**[](#id93)
addr: 6 byte array to store local device Bluetooth address.
GAP_BD_ADDR_LEN: Default Bluetooth device address length of 6 bytes.
### **Returns**[](#id94)
NA
### **Example Code**[](#id95)
NA
Note
Local device address is only available after starting in central or peripheral mode. This function will return all zeros for the address if central or peripheral mode is not in operation. “BLEDevice.h” must be included to use the class function.
[ Previous](Class%20BLEConnect.html)
[Next ](Class%20BLEHIDDevice.html)
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