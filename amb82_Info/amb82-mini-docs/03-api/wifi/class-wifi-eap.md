Class WiFi_eap — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [WiFi](index.html)
- Class WiFi_eap
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/WiFi/Class WiFi_eap.rst)
# Class WiFi_eap[](#class-wifi-eap)
## **WiFi_eapClass Class**[](#wifi-eapclass-class)
### **Description**[](#description)
A class of WiFi EAP and network implementation for Ameba.
### **Syntax**[](#syntax)
class WiFi_eapClass
### **Members**[](#members)
|**Public Constructors**
|
|
| WiFi_eapClass::WiFi_eapClass
|
Constructs a WiFi_eapClass object and
initializes the Wi-Fi libraries and
network settings
|
|
| WiFi_eapClass::~ WiFi_eapClass
|
Deconstructs a WiFi_eapClass object
|
|
| **Public Methods**
|
|
| WiFi_eapClass::begin
|
Start Wi-Fi EAP connection
|
|
## **WiFi_eapClass::WiFi_eapClass**[](#wifi-eapclass-wifi-eapclass)
### **Description**[](#id1)
Constructs a WiFi_eapClass object and initializes the Wi-Fi libraries and network settings.
### **Syntax**[](#id2)
WiFi_eapClass(void);
WiFi_eapClass(char *method, char *ssid, char *identity, char *password, const unsigned char *client_cert, const unsigned char *client_key, const unsigned char *ca_cert);
### **Parameters**[](#parameters)
method: Pointer to the EAP connection method string.
ssid: Pointer to the SSID string.
identity: Pointer to the ID string.
password: Pointer to the password string.
client_cert: Pointer to the client certificate string.
client_key: Pointer to the client private key string.
ca_cert: Pointer to the CA certificate string.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
NA
Note
An instance of WiFi_eapClass is created as WiFi_eap inside WiFi_eap.h and is extern for direct use. “WiFi_eap.h” must be included to use the class function.
## **WiFi_eapClass::begin**[](#wifi-eapclass-begin)
### **Description**[](#id3)
Start Wi-Fi connection for OPEN/ WEP/ with passphrase networks.
### **Syntax**[](#id4)
int begin(void);
int begin(char *method, char *ssid, char *identity, char *password, const unsigned char *client_cert, const unsigned char *client_key, const unsigned char *ca_cert);
### **Parameters**[](#id5)
method: Pointer to the EAP connection method string.
ssid: Pointer to the SSID string.
identity: Pointer to the ID string.
password: Pointer to the password string.
client_cert: Pointer to the client certificate string.
client_key: Pointer to the client private key string.
ca_cert: Pointer to the CA certificate string.
### **Returns**[](#id6)
This function returns the Wi-Fi eap status.
### **Example Code**[](#id7)
Example: [ConnectToWiFi/WPA_Security](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/WiFi/examples/ConnectToWiFi/WPA2_Enterprise/WPA2_Enterprise.ino)
Note
“WiFi_eap.h” must be included to use the class function.
[ Previous](Class%20WiFiUdp.html)
[Next ](../Wire/index.html)
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