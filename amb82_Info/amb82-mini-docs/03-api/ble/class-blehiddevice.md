Class BLEHIDDevice — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEHIDDevice
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEHIDDevice.rst)
# Class BLEHIDDevice[](#class-blehiddevice)
## **BLEHIDDevice Class**[](#blehiddevice-class)
### **Description**[](#description)
A class used for creating and managing HID over GATT Profile (HOGP) services.
### **Syntax**[](#syntax)
class BLEHIDDevice
### **Members**[](#members)
|**Public Constructors**
|
|
| The public constructor should not be used as this class is intended to
be a singleton class. Access member functions using the object instance
named BLEHIDDev.
|
|
| **Public Methods**
|
|
| BLEHIDDevice::init
|
Initialize the HID Device
Profile by creating the
required services and
characteristics
|
|
| BLEHIDDevice::setNumOutputReport
|
Set the number of HID output
reports to be generated.
|
|
| BLEHIDDevice::setNumInputReport
|
Set the number of HID input
reports to be generated.
|
|
| BLEHIDDevice::setReportMap
|
Set the HID report map
characteristics with a HID
report descriptor
|
|
| BLEHIDDevice::inputReport
|
Send a HID input report to
connected device
|
|
| BLEHIDDevice::
setOutputReportCallback
|
Set a user callback function
for receiving HID output
reports
|
|
| BLEHIDDevice::bootKeyboardReport
|
Send a HID boot keyboard input
report to connected device
|
|
| BLEHIDDevice::setHidInfo
|
Set HID info of the HID service
|
|
| BLEHIDDevice::setBattLevel
|
Set battery level info of the
Battery service
|
|
| BLEHIDDevice::setPNPInfo
|
Set PNP information of the
Device Information service
|
|
| BLEHIDDevice::setManufacturerString
|
Set manufacturer information of
the Device Information service
|
|
| BLEHIDDevice::setModelString
|
Set model information of the
Device Information service
|
|
| BLEHIDDevice::hidService
|
Get reference to HID service
|
|
| BLEHIDDevice::devInfoService
|
Get reference to Device
Information service
|
|
| BLEHIDDevice::battService
|
Get reference to Battery
service
|
|
## **BLEHIDDevice::init**[](#blehiddevice-init)
### **Description**[](#id1)
Initialize the HID Device profile by creating the required services and characteristics.
### **Syntax**[](#id2)
void init(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEHIDGamepad](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDGamepad/BLEHIDGamepad.ino)
Note
The HID Device object should be initialized before any HID reports can be sent. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::setNumOutputReport**[](#blehiddevice-setnumoutputreport)
### **Description**[](#id3)
Set the number of HID output reports to be generated.
### **Syntax**[](#id4)
void setNumOutputReport (uint8_t numOutputReports);
### **Parameters**[](#id5)
numOutputReports: number of output reports.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
The number of output reports should be set before BLEHIDDevice init() function is called.The default number of HID output report to be generated is 1 if it is not set. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::setNumInputReport**[](#blehiddevice-setnuminputreport)
### **Description**[](#id8)
Set the number of HID input reports to be generated.
### **Syntax**[](#id9)
void setNumInputReport (uint8_t numInputReports);
### **Parameters**[](#id10)
numInputReports: number of input reports.
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
NA
Note
The number of input reports should be set before BLEHIDDevice init() function is called.The default number of HID input report to be generated is 3 if it is not set. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::setReportMap**[](#blehiddevice-setreportmap)
### **Description**[](#id13)
Set the HID report map characteristics with a HID report descriptor.
### **Syntax**[](#id14)
void setReportMap (uint8_t* report_map, uint16_t len);
### **Parameters**[](#id15)
report_map: pointer to HID report descriptor.
len: HID report descriptor length in bytes.
### **Returns**[](#id16)
NA
### **Example Code**[](#id17)
Example: [BLEHIDGamepad](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDGamepad/BLEHIDGamepad.ino)
Note
The HID report map characteristic can only be configured after BLEHIDDevice init() function is called.
HID report descriptor is a hard coded array of bytes that describe the device’s data packets. For example, how many packets the device supports, how large are the packets and the purpose of each byte and bit in the packets.
For more information on HID report descriptor, refer to [https://eleccelerator.com/tutorial-about-usb-hid-report-descriptors/](https://eleccelerator.com/tutorial-about-usb-hid-report-descriptors/).
“BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::inputReport**[](#blehiddevice-inputreport)
### **Description**[](#id19)
Send a HID input report to connected device.
### **Syntax**[](#id20)
void inputReport (uint8_t reportID, uint8_t* data, uint16_t len, uint8_t conn_id);
### **Parameters**[](#id21)
reportID: HID report ID of input report.
data: pointer to the HID input report data to be sent.
len: length of HID input report data in bytes.
conn_id: connection ID of device that the HID report will be sent to.
### **Returns**[](#id22)
NA
### **Example Code**[](#id23)
NA
Note
HID input reports can only be sent after BLEHIDDevice init() function has been called. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::setOutputReportCallback**[](#blehiddevice-setoutputreportcallback)
### **Description**[](#id24)
Set a user callback function for receiving HID output report data.
### **Syntax**[](#id25)
void setOutputReportCallback (uint8_t reportID, void (*fCallback) (BLECharacteristic* chr, uint8_t conn_id));
### **Parameters**[](#id26)
reportID: HID report ID of output report
chr: BLECharacteristic class object containing received HID output report data.
conn_id: connection ID of the device that send out HID report data.
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
NA
Note
Setting a user callback function for output reports can only occur after BLEHIDDevice init() function has been called. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::bootKeyboardReport**[](#blehiddevice-bootkeyboardreport)
### **Description**[](#id29)
Send a HID boot keyboard input report to connected device.
### **Syntax**[](#id30)
void bootKeyboardReport (uint8_t* data, uint16_t len, uint8_t conn_id);
### **Parameters**[](#id31)
data: pointer to the HID input report data to be sent.
len: length of HID input report data in bytes.
conn_id: connection ID of device that the HID input report will be sent to.
### **Returns**[](#id32)
NA
### **Example Code**[](#id33)
NA
Note
By default, the HID service Protocol Mode characteristic has boot mode disabled. To send boot keyboard input reports, the Protocol Mode characteristic needs to have boot mode enabled. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::setHidInfo**[](#blehiddevice-sethidinfo)
### **Description**[](#id34)
Set HID information such as HID class specification version, country code and flags for HID service.
### **Syntax**[](#id35)
void setHidInfo (uint16_t bcd, uint8_t country, uint8_t flags);
### **Parameters**[](#id36)
bcd: 16-bit unsigned integer representing version number of base USB HID Specification implemented by HID Device.
country: 8-bit integer identifying country HID Device hardware is localized for. Most hardware is not localized (value 0x00).
flags: Bit flags indicating remote-wake capability and advertising when bonded but not connected.
### **Returns**[](#id37)
NA
### **Example Code**[](#id38)
NA
Note
For detailed information on the characteristic, refer to Bluetooth SIG HID Service specifications. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::setBattLevel**[](#blehiddevice-setbattlevel)
### **Description**[](#id39)
Set battery level data of the Battery service.
### **Syntax**[](#id40)
void setBattLevel (uint8_t level);
### **Parameters**[](#id41)
level: battery level expressed as % of full charge.
### **Returns**[](#id42)
NA
### **Example Code**[](#id43)
NA
Note
Battery level is set to 100% by default. For detailed information refer to Bluetooth SIG Battery service specifications. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::setPNPInfo**[](#blehiddevice-setpnpinfo)
### **Description**[](#id44)
Set PNP data of the Device Information service.
### **Syntax**[](#id45)
void setPNPInfo (uint8_t sig, uint16_t vid, uint16_t pid, uint16_t version);
### **Parameters**[](#id46)
sig: The Vendor ID Source field designates which organization assigned the value used in the Vendor ID field value.
vid: The Vendor ID field is intended to uniquely identify the vendor of the device.
pid: The Product ID field is intended to distinguish between different products made by the vendor.
version: The Product Version field is a numeric expression identifying the device release number in Binary-Coded Decimal.
### **Returns**[](#id47)
NA
### **Example Code**[](#id48)
NA
Note
By default, sig and vid are configured to indicate Realtek as the vendor. For detailed information refer to Bluetooth SIG Device Information service specifications. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::setManufacturerString**[](#blehiddevice-setmanufacturerstring)
### **Description**[](#id49)
Set manufacturer information of the Device Information service.
### **Syntax**[](#id50)
void setManufacturerString (const char* manufacturer);
### **Parameters**[](#id51)
manufacturer: pointer to character string containing manufacturer name.
### **Returns**[](#id52)
NA
### **Example Code**[](#id53)
NA
Note
Manufacturer is set to “Realtek” by default. For detailed information refer to Bluetooth SIG Device Information service specifications. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::setModelString**[](#blehiddevice-setmodelstring)
### **Description**[](#id54)
Set model information of the Device Information service.
### **Syntax**[](#id55)
void setModelString (const char* model);
### **Parameters**[](#id56)
model: pointer to character string containing device model info.
### **Returns**[](#id57)
NA
### **Example Code**[](#id58)
NA
Note
Model is set to “Ameba_BLE_HID” by default. For detailed information refer to Bluetooth SIG Device Information service specifications. “BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::hidService**[](#blehiddevice-hidservice)
### **Description**[](#id59)
Get reference to HID service.
### **Syntax**[](#id60)
BLEService& hidService (void);
### **Parameters**[](#id61)
NA
### **Returns**[](#id62)
This function returns a pointer to the BLEService class object for the HID service.
### **Example Code**[](#id63)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::devInfoService**[](#blehiddevice-devinfoservice)
### **Description**[](#id64)
Get reference to Device Information service.
### **Syntax**[](#id65)
BLEService& devInfoService (void);
### **Parameters**[](#id66)
NA
### **Returns**[](#id67)
This function returns a pointer to the BLEService class object for the Device Information service.
### **Example Code**[](#id68)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLEHIDDevice.h” must be included to use the class function.
## **BLEHIDDevice::battService**[](#blehiddevice-battservice)
### **Description**[](#id70)
Get reference to Battery service.
### **Syntax**[](#id71)
BLEService& battService (void);
### **Parameters**[](#id72)
NA
### **Returns**[](#id73)
This function returns a pointer to the BLEService class object for the Battery service.
### **Example Code**[](#id74)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLEHIDDevice.h” must be included to use the class function.
[ Previous](Class%20BLEDevice.html)
[Next ](Class%20BLEHIDGamepad.html)
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