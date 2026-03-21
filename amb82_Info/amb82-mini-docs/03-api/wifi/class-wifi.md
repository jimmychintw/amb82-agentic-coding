Class WiFi — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [WiFi](index.html)
- Class WiFi
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/WiFi/Class WiFi.rst)
# Class WiFi[](#class-wifi)
## **WiFiClass Class**[](#wificlass-class)
### **Description**[](#description)
A class of WiFi and network implementation for Ameba.
### **Syntax**[](#syntax)
class WiFiClass
### **Members**[](#members)
|**Public Constructors**
|
|
| WiFiClass::WiFiClass
|
Constructs a WiFiClass object and
initializes the Wi-Fi libraries and
network settings
|
|
| **Public Methods**
|
|
| WiFiClass::firmwareVersion
|
Get firmware version
|
|
| WiFiClass::begin
|
Start Wi-Fi connection for OPEN/ WEP/
with passphrase networks.
|
|
| WiFiClass::enableConcurrent
|
Set concurrent mode (AP + Station)
|
|
| WiFiClass::config
|
Configure network IP settings
|
|
| WiFiClass::setDNS
|
Set the DNS server IP address to use
|
|
| WiFiClass::disconnect
|
Disconnect from the network
|
|
| WiFiClass::macAddress
|
Get the interface MAC address
|
|
| WiFiClass::localIP
|
Get the interface IP address
|
|
| WiFiClass::subnetMask
|
Get the interface subnet mask address
|
|
| WiFiClass::gatewayIP
|
Get the interface gateway IP address.
|
|
| WiFiClass::SSID
|
Get the current SSID associated with the
network
|
|
| WiFiClass::BSSID
|
Get the current BSSID associated with
the network
|
|
| WiFiClass::RSSI
|
Get the current RSSI (Received Signal
Strength in dBm) associated with the
network
|
|
| WiFiClass::encryptionType
|
Get the encryption type associated with
the network
|
|
| WiFiClass::scanNetworks
|
Start scanning for available Wi-Fi
networks
|
|
| WiFiClass::SSID
|
Get the SSID discovered during the
network scan
|
|
| WiFiClass::encryptionType
|
Get the encryption type of the networks
discovered from scanNetworks
|
|
| WiFiClass::encryptionTypeEx
|
Get the security type and encryption
type of the networks discovered from
scanNetworks
|
|
| WiFiClass::RSSI
|
Get the RSSI of the networks discovered
from scanNetworks
|
|
| WiFiClass::status
|
Get Connection status
|
|
| WiFiClass::hostByName
|
Resolve the given hostname to an IP
address
|
|
| WiFiClass::apbegin
|
Start AP mode
|
|
| WiFiClass::disablePowerSave
|
Disable Wi-Fi Power Save mode
|
|
| WiFiClass:: setHostname
|
Set the hostname for an IP address
|
|
## **WiFiClass::WiFiClass**[](#wificlass-wificlass)
### **Description**[](#id1)
Constructs a WiFiClass object and initializes the Wi-Fi libraries and network settings.
### **Syntax**[](#id2)
WiFiClass(void);
### **Parameters**[](#parameters)
NA
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
NA
Note
An instance of WiFiClass is created as WiFi inside WiFi.h and is extern for direct use. “WiFi.h” must be included to use the class function.
## **WiFiClass::firmwareVersion**[](#wificlass-firmwareversion)
### **Description**[](#id3)
Get WiFi firmware version that is compatible to Arduino.
### **Syntax**[](#id4)
char* firmwareVersion(void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
This function returns WiFi firmware version, default “1.0.0”.
### **Example Code**[](#id7)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA_Security/WPA_Security.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::begin**[](#wificlass-begin)
### **Description**[](#id8)
Start Wi-Fi connection for OPEN/ WEP/ with passphrase networks.
### **Syntax**[](#id9)
int begin(char* ssid);
int begin(char* ssid, uint8_t key_idx, const char* key);
int begin(char* ssid, const char *passphrase);
### **Parameters**[](#id10)
ssid: Pointer to the SSID string.
key_idx: The key index to set and only needed for WEP mode.
- 0 - 3 (Default value is 0)
key: Key input buffer.
passphrase: Valid characters in a passphrase must be ASCII decimal value.
- 32 - 126
### **Returns**[](#id11)
This function returns the Wi-Fi status.
### **Example Code**[](#id12)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA_Security/WPA_Security.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::enableConcurrent**[](#wificlass-enableconcurrent)
### **Description**[](#id14)
Set Concurrent mode (AP + Station).
### **Syntax**[](#id15)
void enableConcurrent(void);
### **Parameters**[](#id16)
NA
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
Example: [ConcurrentMode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConcurrentMode/ConcurrentMode.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::config**[](#wificlass-config)
### **Description**[](#id19)
Configure network settings including the IP address of local host, DNS server, default gateway and subnet, for the Wi-Fi network.
### **Syntax**[](#id20)
void config(IPAddress local_ip);
void config(IPAddress local_ip, IPAddress dns_server);
void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet);
### **Parameters**[](#id21)
local_ip: Local device IP address to use on the network
dns_server: IP address of the DNS server to use
gateway: IP address of the gateway device on the network
subnet: Subnet mask for the network, expressed as an IP address
### **Returns**[](#id22)
NA
### **Example Code**[](#id23)
NA
Note
This will disable the DHCP client when connecting to a network and will require the network accepts a static IP. The configured IP addresses will also apply to AP mode, but the DHCP server will not be disabled in AP mode. “WiFi.h” must be included to use the class function.
## **WiFiClass::setDNS**[](#wificlass-setdns)
### **Description**[](#id24)
Set the IP address for DNS servers.
### **Syntax**[](#id25)
void setDNS(IPAddress dns_server1);
void setDNS(IPAddress dns_server1, IPAddress dns_server2);
### **Parameters**[](#id26)
dns_server1: IP address for DNS server 1
dns_server2: IP address for DNS server 2
### **Returns**[](#id27)
NA
### **Example Code**[](#id28)
NA
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::disconnect**[](#wificlass-disconnect)
### **Description**[](#id29)
Disconnect from the network.
### **Syntax**[](#id30)
int disconnect (void);
### **Parameters**[](#id31)
NA
### **Returns**[](#id32)
This function returns an integer value of 6, corresponding to “WL_DISCONNECTED” in the ‘wl_status_t’ enumeration, that represents the WiFi disconnected state.
### **Example Code**[](#id33)
NA
Note
“WiFi.h” must be included to use the class function. ‘wl_status_t’ enumeration consists of the following Wi-Fi status, WL_NO_SHIELD, WL_IDLE_STATUS, WL_NO_SSID_AVAIL, WL_SCAN_COMPLETED, WL_CONNECTED, WL_CONNECT_FAILED, WL_CONNECTION_LOST, WL_DISCONNECTED.
## **WiFiClass::macAddress**[](#wificlass-macaddress)
### **Description**[](#id34)
Get the interface MAC address.
### **Syntax**[](#id35)
uint8_t* macAddress(uint8_t* mac)
### **Parameters**[](#id36)
mac: an array of to store MAC address (in 8-bit unsigned integer).
### **Returns**[](#id37)
This function returns uint8_t array containing the macAddress with length WL_MAC_ADDR_LENGTH (6 bit).
### **Example Code**[](#id38)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA_Security/WPA_Security.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::localIP**[](#wificlass-localip)
### **Description**[](#id40)
Get the interface IP address.
### **Syntax**[](#id41)
IPAddress localIP(void);
### **Parameters**[](#id42)
NA
### **Returns**[](#id43)
This function returns the IP address of the interface.
### **Example Code**[](#id44)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA_Security/WPA_Security.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::subnetMask**[](#wificlass-subnetmask)
### **Description**[](#id46)
Get the interface subnet mask address.
### **Syntax**[](#id47)
IPAddress subnetMask(void);
### **Parameters**[](#id48)
NA
### **Returns**[](#id49)
This function returns subnet mask address of the interface.
### **Example Code**[](#id50)
Example: [ConnectToWiFi/NoEncryption](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/NoEncryption)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::gatewayIP**[](#wificlass-gatewayip)
### **Description**[](#id51)
Get the interface gateway IP address.
### **Syntax**[](#id52)
IPAddress gatewayIP(void);
### **Parameters**[](#id53)
NA
### **Returns**[](#id54)
This function returns the gateway IP address of interface.
### **Example Code**[](#id55)
Example: [ConnectToWiFi/NoEncryption](https://github.com/Ameba-AIoT/ameba-arduino-pro2/tree/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/NoEncryption)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::SSID**[](#wificlass-ssid)
### **Description**[](#id57)
Get the current SSID (Service Set Identifier) associated with the network.
### **Syntax**[](#id58)
char* SSID(void);
### **Parameters**[](#id59)
NA
### **Returns**[](#id60)
This function returns current SSID associate with the network.
### **Example Code**[](#id61)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA_Security/WPA_Security.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::BSSID**[](#wificlass-bssid)
### **Description**[](#id63)
Get the current BSSID (Basic Service Set Identifier) associated with the network.
### **Syntax**[](#id64)
uint8_t* BSSID(uint8_t* bssid)
### **Parameters**[](#id65)
bssid: an array to store bssid (8-bit unsigned integer)
### **Returns**[](#id66)
This function returns the uint8_t array storing BSSID with length WL_MAC_ADDR_LENGTH (6 bit).
### **Example Code**[](#id67)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA_Security/WPA_Security.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::RSSI**[](#wificlass-rssi)
### **Description**[](#id69)
Get the current RSSI (Received Signal Strength in dBm) associated with the network.
### **Syntax**[](#id70)
int32_t RSSI(void);
### **Parameters**[](#id71)
NA
### **Returns**[](#id72)
This function returns the current RSSI as a 32-bit signed value.
### **Example Code**[](#id73)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA_Security/WPA_Security.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::encryptionType**[](#wificlass-encryptiontype)
### **Description**[](#id75)
Get the encryption type associated with the network.
### **Syntax**[](#id76)
uint8_t encryptionType(void);
### **Parameters**[](#id77)
NA
### **Returns**[](#id78)
This function returns an integer value corresponding to the current encryption type of the Wi-Fi connection in the ‘wl_enc_type’ enumeration.
### **Example Code**[](#id79)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA_Security/WPA_Security.ino)
Note
“WiFi.h” must be included to use the class function. ‘wl_enc_type’ enumeration consists of the following encryption type - ENC_TYPE_WEP, ENC_TYPE_WPA, ENC_TYPE_WPA3, ENC_TYPE_WPA2, ENC_TYPE_NONE and ENC_TYPE_AUTO.
## **WiFiClass::scanNetworks**[](#wificlass-scannetworks)
### **Description**[](#id81)
Start scanning for available WiFi networks.
### **Syntax**[](#id82)
int8_t scanNetworks(void);
### **Parameters**[](#id83)
NA
### **Returns**[](#id84)
This function returns the number of discovered networks as an 8-bit integer.
### **Example Code**[](#id85)
Example: [ScanNetworks](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ScanNetworks/ScanNetworks.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::SSID**[](#id86)
### **Description**[](#id87)
Get the SSID (Service Set Identifier) discovered during the network scan.
### **Syntax**[](#id88)
char* SSID(uint8_t networkItem);
### **Parameters**[](#id89)
networkItem: Specify the network item that retrieves the information required. Network item indicates the index of scanNetwork result that stored in the network scan list array arranging in RSSI descending order.
### **Returns**[](#id90)
This function returns the SSID string of the specified network item on the network scan list.
### **Example Code**[](#id91)
Example: [ScanNetworks](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ScanNetworks/ScanNetworks.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::encryptionType**[](#id93)
### **Description**[](#id94)
Get the encryption type of the networks discovered from scanNetworks.
### **Syntax**[](#id95)
uint8_t encryptionType(uint8_t networkItem);
### **Parameters**[](#id96)
networkItem: Specify the network item that retrieves the information required. Network item indicates the index of scanNetwork result that stored in the network scan list array arranging in RSSI descending order.
### **Returns**[](#id97)
This function returns an integer value corresponding to the current Wi-Fi encryption type of the specified item on the network scanned list in the ‘wl_enc_type’ enumeration.
### **Example Code**[](#id98)
Example: [ScanNetworks](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ScanNetworks/ScanNetworks.ino)
Note
“WiFi.h” must be included to use the class function. ‘wl_enc_type’ enumeration consists of the following encryption type - ENC_TYPE_WEP, ENC_TYPE_WPA, ENC_TYPE_WPA3, ENC_TYPE_WPA2, ENC_TYPE_NONE and ENC_TYPE_AUTO.
## **WiFiClass::encryptionTypeEx**[](#wificlass-encryptiontypeex)
### **Description**[](#id100)
Get the security type and encryption type of the networks discovered from scanNetworks.
### **Syntax**[](#id101)
uint32_t encryptionTypeEx(uint8_t networkItem);
### **Parameters**[](#id102)
networkItem: specify the network item that retrieves the information required. Network item indicates the index of scanNetwork result that stored in the network scan list array arranging in RSSI descending order.
### **Returns**[](#id103)
This function returns security and encryption type of the specified item on the network scanned list.
### **Example Code**[](#id104)
Example: [ScanNetworks](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ScanNetworks/ScanNetworks.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::RSSI**[](#id106)
### **Description**[](#id107)
Get the RSSI of the networks discovered from scanNetworks.
### **Syntax**[](#id108)
int32_t RSSI(uint8_t networkItem);
### **Parameters**[](#id109)
networkItem: specify the network item that retrieves the information required. Network item indicates the index of scanNetwork result that stored in the network scan list array arranging in RSSI descending order.
### **Returns**[](#id110)
This function returns the signed value of RSSI of the specified item on the network scanned list.
### **Example Code**[](#id111)
Example: [ScanNetworks](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ScanNetworks/ScanNetworks.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::status**[](#wificlass-status)
### **Description**[](#id113)
Get the connection status.
### **Syntax**[](#id114)
uint8_t status(void);
### **Parameters**[](#id115)
NA
### **Returns**[](#id116)
This function returns an integer value of 3 corresponding to “WL_CONNECTED” in the ‘wl_status_t’ enumeration, if Wi-Fi is connected. Else returns integer value of 6, corresponding to “WL_DISCONNECTED” in the ‘wl_status_t’ enumeration, that represents the WiFi disconnected state.
### **Example Code**[](#id117)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA_Security/WPA_Security.ino)
Note
“WiFi.h” must be included to use the class function. ‘wl_status_t’ enumeration consists of the following Wi-Fi status, WL_NO_SHIELD, WL_IDLE_STATUS, WL_NO_SSID_AVAIL, WL_SCAN_COMPLETED, WL_CONNECTED, WL_CONNECT_FAILED, WL_CONNECTION_LOST, WL_DISCONNECTED.
## **WiFiClass::hostByName**[](#wificlass-hostbyname)
### **Description**[](#id119)
Resolve the given hostname to an IP address.
### **Syntax**[](#id120)
int hostByName(const char* aHostname, IPAddress& aResult);
### **Parameters**[](#id121)
aHostname: Name to be resolved
aResult: IPAddress structure to store the returned IP address
### **Returns**[](#id122)
The function returns “WL_SUCCESS” if a host name was successfully converted to an IPv4 address, else, it will return as “WL_FAILURE”.
### **Example Code**[](#id123)
NA
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::apbegin**[](#wificlass-apbegin)
### **Description**[](#id124)
Set to Wi-Fi AP (Access Point) mode.
### **Syntax**[](#id125)
int apbegin(char* ssid, char* channel, uint8_t hidden_ssid);
int apbegin(char* ssid, char* password, char* channel, uint8_t hidden_ssid);
### **Parameters**[](#id126)
ssid: SSID of the AP network
channel: AP’s channel (Default value is 1)
password: AP’s password
hidden_ssid: hidden SSID value (Default value is 0)
### **Returns**[](#id127)
This function returns the status of AP.
### **Example Code**[](#id128)
Example: [CreateWiFiAP](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/CreateWiFiAP/CreateWiFiAP.ino)
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass::disablePowerSave**[](#wificlass-disablepowersave)
### **Description**[](#id129)
Disable the WiFi driver Power Save mode.
### **Syntax**[](#id130)
int disablePowerSave(void);
### **Parameters**[](#id131)
NA
### **Returns**[](#id132)
This function returns “0” if PowerSave disable successfully, else “-1” if error occurs.
### **Example Code**[](#id133)
NA
Note
“WiFi.h” must be included to use the class function.
## **WiFiClass:: setHostname**[](#wificlass-sethostname)
### **Description**[](#id134)
Set the hostname for an IP address
### **Syntax**[](#id135)
void setHostname(const char* hostname);
### **Parameters**[](#id136)
Hostname: Name to be set
### **Returns**[](#id137)
NA
### **Example Code**[](#id138)
NA
[ Previous](index.html)
[Next ](Class%20WiFiClient.html)
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