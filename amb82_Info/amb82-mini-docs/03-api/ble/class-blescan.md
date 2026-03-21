Class BLEScan — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [BLE](index.html)
- Class BLEScan
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/BLE/Class BLEScan.rst)
# Class BLEScan[](#class-blescan)
## **BLEScan Class**[](#blescan-class)
### **Description**[](#description)
A class used for managing BLE scanning settings.
### **Syntax**[](#syntax)
class BLEScan
### **Members**[](#members)
|**Public Constructors**
|
|
| No public constructor is available as this class is intended to be a
singleton class. You can get a pointer to this class using
BLEDevice::configScan
|
|
| **Public Methods**
|
|
| BLEScan::updateScanParams
|
Update the lower Bluetooth
stack with the current scan
settings
|
|
| BLEScan::startScan
|
Start a BLE scan
|
|
| BLEScan::stopScan
|
Stop a BLE scan
|
|
| BLEScan::setScanMode
|
Set the BLE scanning mode
|
|
| BLEScan::setScanInterval
|
Set the BLE scanning interval
|
|
| BLEScan::setScanWindow
|
Set the BLE scanning window
|
|
| BLEScan::setScanDuplicateFilter
|
Set the BLE scan duplicate
filter
|
|
| BLEScan::scanInProgress
|
Check if a scan is currently in
progress
|
|
| BLEScan::printScanInfo
|
Print out scanned information
|
|
## **BLEScan::updateScanParams**[](#blescan-updatescanparams)
### **Description**[](#id1)
Update the lower Bluetooth stack with the current scan settings.
### **Syntax**[](#id2)
void updateScanParams(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
Stop any scans in progress first before using this function. “BLEScan.h” must be included to use the class function.
## **BLEScan::startScan**[](#blescan-startscan)
### **Description**[](#id3)
Start BLE scanning.
### **Syntax**[](#id4)
void startScan(void);
void startScan(uint32_t scanDuration_ms);
### **Parameters**[](#id5)
scanDuration: BLE scan will stop after scanDuration milliseconds.
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
Set the scan parameters first before starting a scan. BLE scans will occur continuously for the duration set with BLEDevice::setScanWindow() and will repeat with a time interval set with BLEDevice::setScanInterval(). Call this member function without an argument to start scanning until BLEDevice::stopScan() is called. “BLEScan.h” must be included to use the class function.
## **BLEScan::stopScan**[](#blescan-stopscan)
### **Description**[](#id9)
Stop BLE scanning.
### **Syntax**[](#id10)
void stopScan(void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
NA
Note
“BLEScan.h” must be included to use the class function.
## **BLEScan::setScanMode**[](#blescan-setscanmode)
### **Description**[](#id14)
Set the BLE scanning mode.
### **Syntax**[](#id15)
void setScanMode(uint8_t scanMode);
### **Parameters**[](#id16)
scanMode: GAP_SCAN_MODE_PASSIVE for passive scanning, GAP_SCAN_MODE_ACTIVE for active scanning. Default value is GAP_SCAN_MODE_ACTIVE.
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
Active scanning will request for scan response packets after discovering an advertising device. Passive scanning will only capture advertising data packets. “BLEScan.h” must be included to use the class function.
## **BLEScan::setScanInterval**[](#blescan-setscaninterval)
### **Description**[](#id20)
Set the BLE scanning interval.
### **Syntax**[](#id21)
void setScanInterval(uint16_t scanInt_ms);
### **Parameters**[](#id22)
scanInt_ms: scan interval in milliseconds. Default value is 40.
- 3 to 10240.
### **Returns**[](#id23)
NA
### **Example Code**[](#id24)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
A BLE scan will repeat with a time interval set with this member function. “BLEScan.h” must be included to use the class function.
## **BLEScan::setScanWindow**[](#blescan-setscanwindow)
### **Description**[](#id26)
Set the BLE scanning window.
### **Syntax**[](#id27)
void setScanWindow(uint16_t scanWindow_ms);
### **Parameters**[](#id28)
scanWindow_ms: scan window in milliseconds. Default value is 30.
- 3 to 10240.
### **Returns**[](#id29)
NA
### **Example Code**[](#id30)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
A BLE scan will scan continuously for a window duration set with this member function. The scan window should be less than or equal to the scan interval. “BLEScan.h” must be included to use the class function.
## **BLEScan::setScanDuplicateFilter**[](#blescan-setscanduplicatefilter)
### **Description**[](#id32)
Set the scan duplicate filter.
### **Syntax**[](#id33)
void setScanDuplicateFilter(bool dupeFilter);
### **Parameters**[](#id34)
dupeFilter: TRUE to enable duplicate filtering. Enabled by default.
### **Returns**[](#id35)
NA
### **Example Code**[](#id36)
NA
Note
Enabling duplicate filters will ignore scan results for devices already discovered previously. “BLEScan.h” must be included to use the class function.
## **BLEScan::scanInProgress**[](#blescan-scaninprogress)
### **Description**[](#id37)
Check if scanning is currently in progress.
### **Syntax**[](#id38)
bool scanInProgress(void);
### **Parameters**[](#id39)
NA
### **Returns**[](#id40)
This function returns TRUE if BLE scanning is in progress.
### **Example Code**[](#id41)
NA
Note
“BLEScan.h” must be included to use the class function.
## **BLEScan::printScanInfo**[](#blescan-printscaninfo)
### **Description**[](#id42)
Parse and print out scanned information.
### **Syntax**[](#id43)
void printScanInfo(T_LE_CB_DATA* p_data);
### **Parameters**[](#id44)
p_data: pointer to scan data of type T_LE_CB_DATA
### **Returns**[](#id45)
NA
### **Example Code**[](#id46)
Example: [BLEScan](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/BLE/examples/BLEScan/BLEScan.ino)
Note
Use this member function to parse the various fields of received advertisement data packets and print the results out to the serial monitor. “BLEScan.h” must be included to use the class function.
[ Previous](Class%20BLERemoteService.html)
[Next ](Class%20BLESecurity.html)
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