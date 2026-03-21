# WiFiClass Class

## Description

A class of WiFi and network implementation for Ameba.

## Syntax

```cpp
class WiFiClass
```

## Members

### Public Constructors

| Constructor | Description |
|-------------|-------------|
| `WiFiClass::WiFiClass` | Constructs a WiFiClass object and initializes the Wi-Fi libraries and network settings |

### Public Methods

| Method | Description |
|--------|-------------|
| `WiFiClass::firmwareVersion` | Get firmware version |
| `WiFiClass::begin` | Start Wi-Fi connection for OPEN/ WEP/ with passphrase networks |
| `WiFiClass::enableConcurrent` | Set concurrent mode (AP + Station) |
| `WiFiClass::config` | Configure network IP settings |
| `WiFiClass::setDNS` | Set the DNS server IP address to use |
| `WiFiClass::disconnect` | Disconnect from the network |
| `WiFiClass::macAddress` | Get the interface MAC address |
| `WiFiClass::localIP` | Get the interface IP address |
| `WiFiClass::subnetMask` | Get the interface subnet mask address |
| `WiFiClass::gatewayIP` | Get the interface gateway IP address |
| `WiFiClass::SSID` | Get the current SSID associated with the network |
| `WiFiClass::BSSID` | Get the current BSSID associated with the network |
| `WiFiClass::RSSI` | Get the current RSSI (Received Signal Strength in dBm) |
| `WiFiClass::encryptionType` | Get the encryption type associated with the network |
| `WiFiClass::scanNetworks` | Start scanning for available Wi-Fi networks |
| `WiFiClass::status` | Get Connection status |
| `WiFiClass::hostByName` | Resolve the given hostname to an IP address |
| `WiFiClass::apbegin` | Start AP mode |
| `WiFiClass::disablePowerSave` | Disable Wi-Fi Power Save mode |
| `WiFiClass::setHostname` | Set the hostname for an IP address |

## WiFiClass::begin

### Description

Start Wi-Fi connection for OPEN/ WEP/ with passphrase networks.

### Syntax

```cpp
int begin(char* ssid);
int begin(char* ssid, uint8_t key_idx, const char* key);
int begin(char* ssid, const char *passphrase);
```

### Parameters

- `ssid`: Pointer to the SSID string
- `key_idx`: The key index to set (0-3, default 0) for WEP mode
- `key`: Key input buffer
- `passphrase`: Valid characters ASCII decimal value 32-126

### Returns

The Wi-Fi status.

## WiFiClass::scanNetworks

### Description

Start scanning for available WiFi networks.

### Syntax

```cpp
int8_t scanNetworks(void);
```

### Returns

The number of discovered networks as an 8-bit integer.

## WiFiClass::localIP

### Description

Get the interface IP address.

### Syntax

```cpp
IPAddress localIP(void);
```

### Returns

The IP address of the interface.

## WiFiClass::macAddress

### Description

Get the interface MAC address.

### Syntax

```cpp
uint8_t* macAddress(uint8_t* mac)
```

### Parameters

- `mac`: An array to store MAC address (6 bytes)

### Returns

uint8_t array containing the MAC address.

## WiFiClass::apbegin

### Description

Set to Wi-Fi AP (Access Point) mode.

### Syntax

```cpp
int apbegin(char* ssid, char* channel, uint8_t hidden_ssid);
int apbegin(char* ssid, char* password, char* channel, uint8_t hidden_ssid);
```

### Parameters

- `ssid`: SSID of the AP network
- `channel`: AP's channel (default 1)
- `password`: AP's password
- `hidden_ssid`: hidden SSID value (default 0)

### Returns

The status of AP.