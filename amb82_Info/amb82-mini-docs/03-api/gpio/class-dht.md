Class DHT — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [GPIO](index.html)
- Class DHT
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/GPIO/Class DHT.rst)
# Class DHT[](#class-dht)
## **DHT Class**[](#dht-class)
### **Description**[](#description)
A class to use DHT temperature and humidity sensors.
### **Syntax**[](#syntax)
class DHT
### **Members**[](#members)
|**Public Constructors**
|
|
| DHT::DHT
|
Constructs a DHT object
|
|
| **Public Methods**
|
|
| DHT::begin
|
Initialize the DHT sensor
|
|
| DHT::readTemperature
|
Read temperature (Fahrenheit or
Celsius) from the DHT sensor
|
|
| DHT::convertCtoF
|
Convert a value from Celsius to
Fahrenheit
|
|
| DHT::convertFtoC
|
Convert a value from Fahrenheit to
Celsius
|
|
| DHT::readHumidity
|
Read humidity value from the DHT sensor
as percentage.
|
|
| DHT::computeHeatIndex
|
Compute the HeatIndex from the readings
(Using both Rothfusz and Steadman’s
equations)
|
|
| DHT::read
|
Check if the sensor is readable
|
|
## **DHT::DHT**[](#dht-dht)
### **Description**[](#id1)
Constructs a DHT object.
### **Syntax**[](#id2)
DHT(uint8_t pin, uint8_t type, uint8_t count);
### **Parameters**[](#parameters)
pin: selected GPIO pin. Default value is 8.
type: The DHT sensor type.
- DHT11, DHT22, or DHT21. Default is DHT11.
count: The count is ignored as the DHT reading algorithm adjusts itself based on the speed of the processor. Default value is 6 (Refer to function declaration in DHT.h)
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [DHT_Tester](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GPIO/examples/DHT_Tester/DHT_Tester.ino)
Note
“DHT.h” must be included to use the class function.
## **DHT::begin**[](#dht-begin)
### **Description**[](#id3)
Initialize the DHT sensor by setting up the sensor GPIO pin and set pull timings.
### **Syntax**[](#id4)
void begin(uint8_t usec);
### **Parameters**[](#id5)
usec: Optionally pass pull-up time (in microseconds) before DHT reading starts. Default value is 55 (Refer to function declaration in DHT.h)
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [DHT_Tester](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GPIO/examples/DHT_Tester/DHT_Tester.ino)
Note
“DHT.h” must be included to use the class function.
## **DHT::readTemperature**[](#dht-readtemperature)
### **Description**[](#id9)
Read temperature (Fahrenheit or Celsius) from the DHT sensor in selected scale.
### **Syntax**[](#id10)
float readTemperature(bool S, bool force);
### **Parameters**[](#id11)
S: Scale for temperature. Default value is False (Refer to function declaration in DHT.h)
- True (Fahrenheit)
- False (Celsius).
force: Enable or disable force mode. Default value is False (Refer to function declaration in DHT.h)
- True (Force mode)
- False (Disable force mode)
### **Returns**[](#id12)
This function returns the current temperature as a float value in selected scale.
### **Example Code**[](#id13)
Example: [DHT_Tester](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GPIO/examples/DHT_Tester/DHT_Tester.ino)
Note
“DHT.h” must be included to use the class function.
## **DHT::convertCtoF**[](#dht-convertctof)
### **Description**[](#id15)
Convert a temperature value from Celsius to Fahrenheit.
### **Syntax**[](#id16)
float convertCtoF(float c);
### **Parameters**[](#id17)
c: Temperature in Celsius.
### **Returns**[](#id18)
This function returns the temperature in Fahrenheit as a float number.
### **Example Code**[](#id19)
Example: [DHT_Tester](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GPIO/examples/DHT_Tester/DHT_Tester.ino)
Note
“DHT.h” must be included to use the class function.
## **DHT::convertFtoC**[](#dht-convertftoc)
### **Description**[](#id21)
Convert a temperature value from Fahrenheit to Celsius.
### **Syntax**[](#id22)
float convertFtoC(float f);
### **Parameters**[](#id23)
f: Temperature in Fahrenheit.
### **Returns**[](#id24)
This function returns the temperature in Celsius as a float number.
### **Example Code**[](#id25)
Example: [DHT_Tester](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GPIO/examples/DHT_Tester/DHT_Tester.ino)
Note
“DHT.h” must be included to use the class function.
## **DHT::readHumidity**[](#dht-readhumidity)
### **Description**[](#id27)
Read humidity value from the DHT sensor as percentage.
### **Syntax**[](#id28)
float readHumidity(bool force);
### **Parameters**[](#id29)
force: Enable or disable force mode. Default value is False (Refer to function declaration in DHT.h)
- True (Force mode)
- False (Disable force mode)
### **Returns**[](#id30)
This function returns current humidity value represented in float as percentage.
### **Example Code**[](#id31)
Example: [DHT_Tester](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GPIO/examples/DHT_Tester/DHT_Tester.ino)
Note
“DHT.h” must be included to use the class function. Reading temperature or humidity takes about 250 milliseconds. Sensor readings may also be up to 2 seconds.
## **DHT::computeHeatIndex**[](#dht-computeheatindex)
### **Description**[](#id33)
Compute the HeatIndex from the readings (Using both Rothfusz and Steadman’s equations). More details refer to [The Heat Index Equation](http://www.wpc.ncep.noaa.gov/html/heatindex_equation.shtml)
### **Syntax**[](#id34)
float computeHeatIndex(bool isFahrenheit);
float computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit = true);
### **Parameters**[](#id35)
temperature: The temperature value in selscted scale percentHumidity: humidity value in percentage.
isFahrenheit: choose temperature vale in Fahrenheit or Celsius. Default value is True.
- True (in Fahrenheit)
- False (Celsius)
### **Returns**[](#id36)
This function returns the heat index in Fahrenheit or Celsius as a float value.
### **Example Code**[](#id37)
Example: [DHT_Tester](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GPIO/examples/DHT_Tester/DHT_Tester.ino)
Note
“DHT.h” must be included to use the class function.
## **DHT::read**[](#dht-read)
### **Description**[](#id39)
Check if the sensor is readable.
### **Syntax**[](#id40)
bool read (bool force);
### **Parameters**[](#id41)
force: Enable or disable force mode. Default value is False (Refer to function declaration in DHT.h)
- True (Force mode)
- False (Disable force mode)
### **Returns**[](#id42)
This function returns whether the sensor is readable in every 2 seconds.
### **Example Code**[](#id43)
Example: [DHT_Tester](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/GPIO/examples/DHT_Tester/DHT_Tester.ino)
Note
“DHT.h” must be included to use the class function.
[ Previous](index.html)
[Next ](Class%20InterruptLock.html)
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