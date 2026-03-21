# Create WiFi AP

## Materials

- AMB82-mini x 1

## Example

### Introduction

In AP mode, Ameba can accept at most 3 station connections, and can be set to open mode or WPA2 mode.

In this example, we turn on the AP mode of Ameba and connect station to Ameba.

### Procedure

Open example, File -> Examples -> WiFi -> CreateWiFiAP

In the highlighted code snippet, fill in your SSID, PASSWORD and CHANNEL.

If you prefer to enter your SSID & password in the Serial monitor while the program is running, uncomment `#define MANUAL_INPUT` at the top of the file.

The code highlighted is the API we used to turn on the AP mode in security mode.

If you want to turn on the AP mode in open mode, please modify the code to `status = WiFi.apbegin(ssid, channel);`

Then upload the sample code and press reset, and you can see related information shown in serial monitor.

The messages shown in serial monitor when stations connect to Ameba AP in open mode and security mode will be displayed accordingly.