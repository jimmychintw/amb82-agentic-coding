# BLEDevice Class

## Description

A class used for general control and management of BLE functions.

## Syntax

```cpp
class BLEDevice
```

## Members

### Public Constructors

The public constructor should not be used as this class is intended to be a singleton class. Access member functions using the object instance named BLE.

### Public Methods

| Method | Description |
|--------|-------------|
| `BLEDevice::init` | Initialize resources required for BLE |
| `BLEDevice::deinit` | Deinitialize all operations for BLE |
| `BLEDevice::connected` | Check if a BLE device is connected |
| `BLEDevice::setDeviceName` | Set BLE GAP device name |
| `BLEDevice::setDeviceAppearance` | Set BLE GAP device appearance |
| `BLEDevice::configAdvert` | Configure BLE advertising parameters |
| `BLEDevice::configScan` | Configure BLE scan parameters |
| `BLEDevice::configConnection` | Configure BLE connection parameters |
| `BLEDevice::configSecurity` | Configure BLE bonding security parameters |
| `BLEDevice::setScanCallback` | Set callback function for BLE scan results |
| `BLEDevice::beginCentral` | Start BLE stack as central device |
| `BLEDevice::beginPeripheral` | Start BLE stack as peripheral device |
| `BLEDevice::end` | Stop BLE stack operation |
| `BLEDevice::configServer` | Configure BLE stack for services |
| `BLEDevice::addService` | Add a service to BLE stack |
| `BLEDevice::configClient` | Configure BLE stack for clients |
| `BLEDevice::addClient` | Add a new client to BLE stack |
| `BLEDevice::getLocalAddr` | Get local device Bluetooth address |

## BLEDevice::init

### Description

Initialize resources that are required for BLE to function.

### Syntax

```cpp
void init(void);
```

## BLEDevice::configAdvert

### Description

Configure BLE advertising parameters.

### Syntax

```cpp
BLEAdvert* configAdvert(void);
```

### Returns

A pointer to a BLEAdvert class instance.

## BLEDevice::beginPeripheral

### Description

Start the BLE stack to operate as a peripheral device.

### Syntax

```cpp
void beginPeripheral(void);
```

## BLEDevice::beginCentral

### Description

Start the BLE stack to operate as a central device.

### Syntax

```cpp
void beginCentral(uint8_t connCount);
```

### Parameters

- `connCount`: Maximum number of allowed connected devices

## BLEDevice::configServer

### Description

Configure the BLE stack for services.

### Syntax

```cpp
void configServer(uint8_t maxServiceCount);
```

### Parameters

- `maxServiceCount`: Maximum number of services that will run on the device

## BLEDevice::addService

### Description

Add a new service to the BLE stack.

### Syntax

```cpp
void addService(BLEService& newService);
```

### Parameters

- `newService`: The service to be added

## BLEDevice::configClient

### Description

Configure the BLE stack for clients.

### Syntax

```cpp
void configClient(void);
```

## BLEDevice::addClient

### Description

Add a new client to the BLE stack.

### Syntax

```cpp
BLEClient* addClient(uint8_t connId);
```

### Parameters

- `connId`: The connection ID of the connected device

### Returns

A pointer to a BLEClient class object.