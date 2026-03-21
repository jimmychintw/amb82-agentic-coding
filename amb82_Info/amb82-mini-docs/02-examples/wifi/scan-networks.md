# Scan Networks

## Materials

- AMB82-mini x 1
- Antenna x 1

## Example

In this example, we use Ameba to scan available WiFi hotspots in the surroundings, and prints the SSID, encryption type, signal strength information of each detected hotspot.

First, make sure the correct Ameba development board is selected in Arduino IDE Tools -> Board

Open the "ScanNetworks" example in File -> Examples -> WiFi -> ScanNetworks

Then upload the sample code and press the reset button on Ameba. Afterwards, you can see "**Scan Networks**" message appears, with the detected WiFi hotspots and the information of each hotspot.

## Code Reference

- `WiFi.macAddress(mac)` - Get the MAC address of Ameba
- `WiFi.scanNetworks()` - Detect WiFi hotspots
- `WiFi.SSID(thisNet)` - Retrieve SSID of a network
- `WiFi.RSSI(thisNet)` - Get the signal strength
- `WiFi.encryptionType(thisNet)` - Get the encryption type