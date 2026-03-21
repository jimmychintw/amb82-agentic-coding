# Connect to WiFi

## Materials

- AMB82-mini x 1

## Example

### Introduction

There are 4 encryption types of WiFi connection in this guide:

- "OPEN" - No password needed
- "WPA" - Requires correct password
- "WEP" - Requires hexadecimal password and keyindex
- "WPA2-EAP" - WPA2-Enterprise with EAP authentication (TLS, PEAP, TTLS)

### Open (WiFi connection without password)

Open example in File -> Examples -> WiFi -> ConnectToWiFi -> NoEncryption

In the sample code, modify "ssid" to be the same as the WiFi SSID to be connected to.

Next, upload the sample code, and press the reset button on Ameba. Then you will see a message "You're connected to the networkSSID: XXXXX", and the information of this WiFi connection is printed in the serial monitor every 10 seconds.

### WiFi connection with WPA encryption

Open example in File -> Examples -> WiFi -> ConnectToWiFi -> WPA_Security

In the sample code, modify "ssid" to the WiFi SSID and "pass" to the network password.

If you prefer to enter your SSID & password in the Serial monitor while the program is running, uncomment `#define MANUAL_INPUT` at the top of the file.

### WiFi connection with WEP encryption

Open example in File -> Examples -> WiFi -> ConnectToWiFi -> WEP_Security

In the sample code, modify "ssid" to the SSID, "key" to the hexadecimal password, "keyIndex" to your key index number.

### WiFi connection with WPA2-Enterprise

Open example in File -> Examples -> WiFi -> ConnectToWiFi -> WPA2_Enterprise

In the sample code:
- eap_method: EAP connection method "tls", "peap", "ttls"
- ssid: The network SSID
- identity: The network identity
- pass: The network password
- client_cert: Client certificate from EAP server
- client_key: Client key from EAP server
- ca_cert: CA certificate from EAP server

## Code Reference

- `WiFi.begin()` - Start Wi-Fi connection
- `WiFi.SSID()` - Get SSID of current connected network
- `WiFi.RSSI()` - Get signal strength
- `WiFi.encryptionType()` - Get encryption type
- `WiFi.BSSID()` - Get MAC address of router
- `WiFi.macAddress()` - Get MAC address of Ameba
- `WiFi.localIP()` - Get IP address of Ameba
- `WiFi.subnetMask()` - Get subnet mask
- `WiFi.gatewayIP()` - Get gateway IP address