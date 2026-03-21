# OTA Class

## Description

A class used for updating firmware Over the Air (OTA) in local area network.

## Syntax

```cpp
class OTA
```

## Members

### Public Constructors

A public constructor should not be used as this class is intended to be a singleton class. Access member functions using the object instance named OTA.

### Public Methods

| Method | Description |
|--------|-------------|
| `OTA::start_OTA_threads` | Begin threading tasks for OTA firmware update |

## OTA::start_OTA_threads

### Description

To begin threading tasks for OTA firmware update.

### Syntax

```cpp
void start_OTA_threads(int port, char* server);
```

### Parameters

- `port`: Port number for the OTA HTTP server
- `server`: Pointer for OTA HTTP server IP address

### Returns

None

## Code Reference

Two threads are created:

**Thread 1**: Keep-alive connectivity check - Sends OTA state to server periodically.

**Thread 2**: Listen for OTA begin signal - Downloads firmware when `start_ota` signal is received.

## Example

```cpp
#include <OTA.h>

void setup() {
    // ... WiFi setup ...
    
    OTA.start_OTA_threads(5000, "192.168.1.100");
}

void loop() {
    // Main program
}
```

## Notes

- OTA mode must be enabled in Arduino IDE: Tools -> OTA Mode -> Enable
- NN Model should be set to load from SD card: Tools -> NN Model Load From -> SD Card
- A hidden check value called `timestamp` ensures the OTA firmware is newer than current firmware