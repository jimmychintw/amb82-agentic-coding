Class BLESecurity — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLESecurity
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLESecurity.rst)
# Class BLESecurity[](#class-blesecurity)
## **BLESecurity Class**[](#blesecurity-class)
### **Description**[](#description)
A class used for creating and managing BLE bonding security parameters.
### **Syntax**[](#syntax)
class BLESecurity
### **Members**[](#members)
|**Public Constructors**
|
|
| No public constructor is available as this class is intended to be a
singleton class. You can get a pointer to this class using
BLEDevice::configSecurity
|
|
| **Public Methods**
|
|
| BLESecurity::setPairable
|
Enable pairing and bonding after
BLE connection
|
|
| BLESecurity::setAuthFlags
|
Set BLE bonding security
requirements
|
|
| BLESecurity::setIOCapability
|
Set input and output
capabilities of the device
|
|
| BLESecurity::setSecReqEnable
|
Enable sending SMP security
request when BLE connected
|
|
| BLESecurity::setSecReqFlags
|
Set security request
requirements
|
|
| BLESecurity::setStaticPin
|
Configure device to use static
pin input for BLE bonding
|
|
| BLESecurity::
setPasskeyDisplayCallback
|
Set a user callback function for
passkey display during BLE
bonding
|
|
| BLESecurity::
setPasskeyInputCallback
|
Set a user callback function for
passkey input during BLE bonding
|
|
| BLESecurity::
setNumericComparisonCallback
|
Set a user callback function for
numeric comparison during BLE
bonding
|
|
## **BLESecurity::setPairable**[](#blesecurity-setpairable)
### **Description**[](#id1)
Enable pairing and bonding after BLE connection.
### **Syntax**[](#id2)
void setPairable(bool pairMode);
### **Parameters**[](#parameters)
pairMode: True to enable pairing and bonding, False to disable.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLESecurity.h” must be included to use the class function.
## **BLESecurity::setAuthFlags**[](#blesecurity-setauthflags)
### **Description**[](#id3)
Set BLE bonding security requirements.
### **Syntax**[](#id4)
void setAuthFlags(uint16_t authFlags);
### **Parameters**[](#id5)
authFlags: desired BLE bonding security requirements.
- GAP_AUTHEN_BIT_NONE
- GAP_AUTHEN_BIT_BONDING_FLAG
- GAP_AUTHEN_BIT_MITM_FLAG
- GAP_AUTHEN_BIT_SC_FLAG
- GAP_AUTHEN_BIT_SC_ONLY_FLAG
- GAP_AUTHEN_BIT_FORCE_BONDING_FLAG
Default value: GAP_AUTHEN_BIT_NONE
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [BLEHIDMouse](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEHIDMouse/BLEHIDMouse.ino)
Note
“BLESecurity.h” must be included to use the class function.
## **BLESecurity::setIOCapability**[](#blesecurity-setiocapability)
### **Description**[](#id9)
Set BLE device input and output capabilities.
### **Syntax**[](#id10)
void setIOCap(uint8_t ioCap);
### **Parameters**[](#id11)
ioCap: desired device input output capabilities. Default value is GAP_IO_CAP_NO_INPUT_NO_OUTPUT.
- GAP_IO_CAP_NO_INPUT_NO_OUTPUT
- GAP_IO_CAP_DISPLAY_ONLY
- GAP_IO_CAP_DISPLAY_YES_NO
- GAP_IO_CAP_KEYBOARD_ONLY
- GAP_IO_CAP_KEYBOARD_DISPLAY
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
NA
Note
The IO capabilities of the peripheral and central device will determine which bonding authentication method is used. “BLESecurity.h” must be included to use the class function.
## **BLESecurity::setSecReqEnable**[](#blesecurity-setsecreqenable)
### **Description**[](#id14)
Enable sending SMP security request when BLE connected.
### **Syntax**[](#id15)
void setSecReqEnable(bool secReq);
### **Parameters**[](#id16)
secReq: TRUE to enable, FALSE to disable. Default value is FALSE.
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
NA
Note
“BLESecurity.h” must be included to use the class function.
## **BLESecurity::setSecReqFlags**[](#blesecurity-setsecreqflags)
### **Description**[](#id19)
Set security request requirements.
### **Syntax**[](#id20)
void setSecReqFlags(uint16_t secReqFlags);
### **Parameters**[](#id21)
secReqFlags: desired security requirements. Default value is GAP_AUTHEN_BIT_NONE.
- GAP_AUTHEN_BIT_NONE
- GAP_AUTHEN_BIT_BONDING_FLAG
- GAP_AUTHEN_BIT_MITM_FLAG
- GAP_AUTHEN_BIT_SC_FLAG
- GAP_AUTHEN_BIT_SC_ONLY_FLAG
- GAP_AUTHEN_BIT_FORCE_BONDING_FLAG
### **Returns**[](#id22)
NA
### **Example Code**[](#id23)
NA
Note
“BLESecurity.h” must be included to use the class function.
## **BLESecurity::setStaticPin**[](#blesecurity-setstaticpin)
### **Description**[](#id24)
Configure device to use static pin input for BLE bonding.
### **Syntax**[](#id25)
void setStaticPin(uint32_t pin);
### **Parameters**[](#id26)
pin: BLE bonding static pin. Valid values are 6-digit integers.
- 000000 to 999999.
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
NA
Note
Using a static pin will enable BLE bonding and pairing, set the IO capability to GAP_IO_CAP_DISPLAY_ONLY and set the bonding security requirements flags to (GAP_AUTHEN_BIT_BONDING_FLAG | GAP_AUTHEN_BIT_MITM_FLAG | GAP_AUTHEN_BIT_SC_FLAG). “BLESecurity.h” must be included to use the class function.
## **BLESecurity::setPasskeyDisplayCallback**[](#blesecurity-setpasskeydisplaycallback)
### **Description**[](#id29)
Set a user callback function for passkey display during BLE bonding.
### **Syntax**[](#id30)
void setPasskeyDisplayCallback(void (*fCallback) (uint8_t conn_id, uint32_t passkey));
### **Parameters**[](#id31)
fCallback: A user callback function that returns void and takes two arguments.
conn_id: connection ID of connecting device.
passkey: bonding passkey to display to user to confirm connection.
### **Returns**[](#id32)
NA
### **Example Code**[](#id33)
NA
Note
“BLESecurity.h” must be included to use the class function.
## **BLESecurity::setPasskeyInputCallback**[](#blesecurity-setpasskeyinputcallback)
### **Description**[](#id34)
Set a user callback function for passkey input during BLE bonding.
### **Syntax**[](#id35)
void setPasskeyInputCallback(uint32_t (*fCallback) (uint8_t conn_id));
### **Parameters**[](#id36)
fCallback: A user callback function that takes no arguments and returns the bonding passkey entered by the user.
conn_id: connection ID of connecting device.
### **Returns**[](#id37)
NA
### **Example Code**[](#id38)
NA
Note
“BLESecurity.h” must be included to use the class function.
## **BLESecurity::setNumericComparisonCallback**[](#blesecurity-setnumericcomparisoncallback)
### **Description**[](#id39)
Set a user callback function for numeric comparison during BLE bonding.
### **Syntax**[](#id40)
void setNumericComparisonCallback(bool (*fCallback) (uint8_t conn_id, uint32_t passkey));
### **Parameters**[](#id41)
fCallback: A user callback function that takes two arguments and returns a Boolean to indicate user approval for the numeric comparison.
conn_id: connection ID of connecting device.
passkey: bonding passkey to display to user to confirm connection.
### **Returns**[](#id42)
NA
### **Example Code**[](#id43)
NA
Note
“BLESecurity.h” must be included to use the class function.
[ Previous](Class%20BLEScan.html)
[Next ](Class%20BLEService.html)
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