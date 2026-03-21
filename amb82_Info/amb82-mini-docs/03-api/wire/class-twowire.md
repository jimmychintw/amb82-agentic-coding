Class TwoWire — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Wire](index.html)
- Class TwoWire
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Wire/Class TwoWire.rst)
# Class TwoWire[](#class-twowire)
## **TwoWire Class**[](#twowire-class)
### **Description**[](#description)
A class of I2C API.
### **Syntax**[](#syntax)
class TwoWire
### **Members**[](#members)
|**Public Constructors**
|
|
| TwoWire::TwoWire
|
Constructs a TwoWire object
|
|
| **Public Methods**
|
|
| TwoWire::begin
|
Initialize I2C master/slave
|
|
| TwoWire::end
|
Deinitialize I2C master/slave
|
|
| TwoWire::setClock
|
Set I2C clock frequency
|
|
| TwoWire::beginTransmission
|
Begin I2C transmission
|
|
| TwoWire::endTransmission
|
Stop I2C transmission
|
|
| TwoWire::requestFrom
|
Set I2C requestFrom
|
|
| TwoWire::write
|
Write data to I2C
|
|
| TwoWire::available
|
Check if I2C is available
|
|
| TwoWire::read
|
Read data from I2C
|
|
| TwoWire::peek
|
Read peek from I2C
|
|
| TwoWire::flush
|
Do nothing, use, and transmission(..)
to force data transfer
|
|
| TwoWire::onReceive
|
Callback function when I2C on receive
|
|
| TwoWire::onRequest
|
Callback function when I2C on request
|
|
| TwoWire::slaveWrite
|
Send data as a slave device
|
|
## **TwoWire::TwoWire**[](#twowire-twowire)
### **Description**[](#id1)
Constructs a TwoWire object.
### **Syntax**[](#id2)
TwoWire(void *pWireObj, uint32_t dwSDAPin, uint32_t dwSCLPin);
### **Parameters**[](#parameters)
pWireObj: Pointer to the Wire object.
dwSDAPin: Pin name (from pinmap) to be set as SDA pin.
dwSCLPin: Pin name (from pinmap) to be set as SCL pin.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [MasterSendData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterSendData/MasterSendData.ino)
Note
“Wire.h” must be included to use the class function.
## **TwoWire::begin**[](#twowire-begin)
### **Description**[](#id3)
Initialize I2C master/slave. To use in I2C master, no argument should be passed in, otherwise I2C will be in slave mode.
### **Syntax**[](#id4)
void begin (void);
void begin (uint8_t address = 0);
void begin (int address);
### **Parameters**[](#id5)
address: Set the I2C slave address value.
- 0 - 127
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [MasterSendData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterSendData/MasterSendData.ino)
Note
“Wire.h” must be included to use the class function. When configured as I2C slave, begin() will also configure and enable I2C interrupt and attach user callback to be used in the I2C interrupt service routine.
## **TwoWire::end**[](#twowire-end)
### **Description**[](#id9)
This function is used to de-initialise the I2C device.
### **Syntax**[](#id10)
void end (void);
### **Parameters**[](#id11)
NA
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [MasterSendData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterSendData/MasterSendData.ino)
Note
“Wire.h” must be included to use the class function.
## **TwoWire::setClock**[](#twowire-setclock)
### **Description**[](#id15)
Set I2C clock frequency.
### **Syntax**[](#id16)
void setClock(uint32_t frequency);
### **Parameters**[](#id17)
frequency: Set user defined I2C clock frequency (Hz). Default value is 100000.
### **Returns**[](#id18)
NA
### **Example Code**[](#id19)
Example: [MasterSendData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterSendData/MasterSendData.ino)
Note
“Wire.h” must be included to use the class function.
## **TwoWire::beginTransmission**[](#twowire-begintransmission)
### **Description**[](#id21)
Begin I2C transmission to device.
### **Syntax**[](#id22)
void beginTransmission (uint8_t address);
void beginTransmission (int address);
### **Parameters**[](#id23)
address: The transmission address.
### **Returns**[](#id24)
NA
### **Example Code**[](#id25)
Example: [MasterSendData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterSendData/MasterSendData.ino)
Note
“Wire.h” must be included to use the class function.
## **TwoWire::endTransmission**[](#twowire-endtransmission)
### **Description**[](#id27)
This function ends a transmission to a peripheral device that was begun by beginTransmission() and transmits the bytes that were queued by write().
### **Syntax**[](#id28)
uint8_t endTransmission (uint8_t sendStop);
uint8_t endTransmission (void);
### **Parameters**[](#id29)
sendStop: Set to True to end transmission after data is transferred from master to slave, and releasing the I2C bus. Set to False will send a restart keeping the connection active.
- true  (Default value)
- false
### **Returns**[](#id30)
This function returns 0 if successful, else returns 1 indicating error.
### **Example Code**[](#id31)
Example: [MasterSendData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterSendData/MasterSendData.ino)
Note
Originally, ‘endTransmission’ was an f(void) function. It has been modified to take one parameter indicating whether a STOP should be performed on the bus. Calling endTransmission(false) allows a sketch to perform a repeated start. If the input parameter is void, this provides backward compatibility with the original definition, and expected behavior, of endTransmission. “Wire.h” must be included to use the class function.
Warning
Nothing in the library keeps track of whether the bus tenure has been properly ended with a STOP. It is very possible to leave the bus in a hung state if no call to endTransmission(true) is made. Some I2C devices will behave oddly if they do not see a STOP.
## **TwoWire::requestFrom**[](#twowire-requestfrom)
### **Description**[](#id33)
I2C master request data sending from I2C slave device.
### **Syntax**[](#id34)
uint8_t requestFrom (uint8_t address, uint8_t quantity, uint8_t sendStop);
uint8_t requestFrom (uint8_t address, uint8_t quantity);
uint8_t requestFrom(int address, int quantity);
uint8_t requestFrom (int address, int quantity, int sendStop);
### **Parameters**[](#id35)
address: The I2C slave address of the device to request bytes from.
quantity: The number of data (in byte) that to be received from I2C slave device.
sendStop: Set to True to end transmission after data is transferred from master to slave, and releasing the I2C bus. Set to False will send a restart keeping the connection active.
- true  (Default value)
- false
### **Returns**[](#id36)
This function returns the length of data received as an int if successful, else returns error.
### **Example Code**[](#id37)
Example: [MasterReceiveData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterReceiveData/MasterReceiveData.ino)
Note
“Wire.h” must be included to use the class function.
## **TwoWire::write**[](#twowire-write)
### **Description**[](#id38)
Write data to I2C master transmission buffer.
### **Syntax**[](#id39)
size_t write (uint8_t data);
size_t write (const uint8_t *data, size_t quantity);
### **Parameters**[](#id40)
data: The data in 8-bit is to be transmitted from I2C master to slave.
quantity: The number of data in 8-bit to be transmitted.
### **Returns**[](#id41)
size_t write (uint8_t data);
Returns 1 if successful, else returns 0.
size_t write (const uint8_t *data, size_t quantity);
Returns the number of bytes to be transmitted. (Reading this number is optional)
### **Example Code**[](#id42)
Example: [MasterSendData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterSendData/MasterSendData.ino)
Note
“Wire.h” must be included to use the class function.
## **TwoWire::available**[](#twowire-available)
### **Description**[](#id44)
This function returns the number of bytes available for retrieval with read().
### **Syntax**[](#id45)
virtual int available(void);
### **Parameters**[](#id46)
NA
### **Returns**[](#id47)
This function returns the number of bytes available for reading.
### **Example Code**[](#id48)
Example: [MasterReceiveData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterReceiveData/MasterReceiveData.ino)
Note
This function should be called on a controller device after a call to requestFrom() or on a peripheral inside the onReceive() handler. available() inherits from the Stream utility class. “Wire.h” must be included to use the class function.
## **TwoWire::read**[](#twowire-read)
### **Description**[](#id50)
This function reads a byte that was transmitted from a peripheral device to a controller device after a call to requestFrom() or was transmitted from a controller device to a peripheral device.
### **Syntax**[](#id51)
virtual int read(void);
### **Parameters**[](#id52)
NA
### **Returns**[](#id53)
This function returns the next data in byte read from receiver buffer.
### **Example Code**[](#id54)
Example: [MasterReceiveData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterReceiveData/MasterReceiveData.ino)
Note
“Wire.h” must be included to use the class function.
## **TwoWire::peek**[](#twowire-peek)
### **Description**[](#id56)
This function reads a byte that currently transmitted from a peripheral device to a controller device.
### **Syntax**[](#id57)
virtual int peek(void);
### **Parameters**[](#id58)
NA
### **Returns**[](#id59)
This function returns the current data read from receiver buffer. Otherwise, “-1”.
### **Example Code**[](#id60)
Example: [MasterReceiveData](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Wire/examples/MasterReceiveData/MasterReceiveData.ino)
Note
“Wire.h” must be included to use the class function.
## **TwoWire::flush**[](#twowire-flush)
### **Description**[](#id62)
An empty API that does nothing, use endTransmission() to force data transfer.
### **Syntax**[](#id63)
virtual void flush(void);
### **Parameters**[](#id64)
NA
### **Returns**[](#id65)
NA
### **Example Code**[](#id66)
NA
Note
“Wire.h” must be included to use the class function.
## **TwoWire::onReceive**[](#twowire-onreceive)
### **Description**[](#id67)
This function registers a function to be called when a peripheral device receives a transmission from a controller device.
### **Syntax**[](#id68)
void TwoWire::onReceive (void(*function)(int));
### **Parameters**[](#id69)
function: The callback function to be called when the peripheral device receives data; this should take a single int parameter (the number of bytes read from the controller device) and return nothing.
### **Returns**[](#id70)
NA
### **Example Code**[](#id71)
NA
Note
“Wire.h” must be included to use the class function.
## **TwoWire::onRequest**[](#twowire-onrequest)
### **Description**[](#id72)
This function registers a function to be called when a controller device requests data from a peripheral device.
### **Syntax**[](#id73)
void onRequest (void(*function)(void));
### **Parameters**[](#id74)
function: the function to be called, takes no parameters and returns nothing.
### **Returns**[](#id75)
NA
### **Example Code**[](#id76)
NA
Note
“Wire.h” must be included to use the class function.
## **TwoWire::slaveWrite**[](#twowire-slavewrite)
### **Description**[](#id77)
Send data as a slave device, note that this API only work when device is configured as I2C slave (see begin()).
### **Syntax**[](#id78)
size_t slaveWrite(int buffer);
size_t slaveWrite(char *buffer);
size_t slaveWrite(uint8_t *buffer, size_t len);
### **Parameters**[](#id79)
buffer: Data container that can be an integer or a character pointer.
Len: The length of the data buffer.
### **Returns**[](#id80)
This function returns true if successful, else returns false.
### **Example Code**[](#id81)
NA
Note
“Wire.h” must be included to use the class function. This function can only be called if the device is in slave mode and after user has registered a requestEvent using onRequest().
[ Previous](index.html)
[Next ](../WS2812B/index.html)
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