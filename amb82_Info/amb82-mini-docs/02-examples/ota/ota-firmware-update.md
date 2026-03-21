# Ameba Over-the-Air Firmware Update

## Materials

- AMB82-mini x 1
- Set up of Web UI in a PC

## Example

In this example, we use a web UI to upload firmware to one or more AMB82 Mini.

For the instructions to set up web UI for AmebaPro2 OTA: Web UI, please refer to:
https://github.com/Ameba-AioT/ameba-OTA-UI

If Ameba OTA Web UI is set up successfully in your PC, you will see the webpage on http://localhost:3000/

To begin, open the OTA example in Arduino IDE. File -> Examples -> AmebaOTA -> OTA

Before compiling and upload the example, please complete the following steps:

1. Set NN Model Load From SD Card. Tools -> NN Model Load From -> SD Card

2. Enable the OTA mode. Tools -> OTA Mode -> Enable

3. Modify the SSID and password according to your AP. Your PC and AMB82 Mini should be connecting to the same local area network.

4. Modify the port number and IP address according to your HTTP server.

Now, compile and upload this example into each and every board that you have.

Once uploaded, press reset button and get the IP address of the individual AMB82 Mini on serial monitor.

Then, go to Ameba OTA Web UI http://localhost:3000/ to view the connected device(s).

In this tutorial, we will be uploading a NTPClient sketch via OTA. Open the NTPClient example. Include the header file `OTA.h` and at the end of setup function, add in the API `start_OTA_threads` and define the port number and IP address.

Before compiling, remember to set NN Model to load from SD card and enable OTA mode.

Compile the modified NTPClient sketch, DO NOT upload after compilation.

Once compilation is done, look for `ota.bin` file in:
- Windows: C:\Users\<username>\AppData\Local\Arduino15\packages\realtek\tools\ameba_pro2_tools\<version>
- Linux: ~/.arduino15/packages/realtek/tools/ameba_pro2_tools/<version>

Upload `ota.bin` to the webpage UI for OTA transfer to AMB82.

Select the device(s) to perform OTA transfer and click "Start OTA" to begin OTA transfer.

The board will automatically reboot with the OTA transferred firmware once download progress is completed.

## Code Reference

**Multithreading:**

Two threads are written in `start_OTA_threads()` to ensure successful OTA update.

Thread 1: For the purpose of connectivity check, the OTA state is sent to the server from AMB82 Mini board.

Thread 2: To listen for the OTA begin signal from server, once `start_ota` signal is received, AMB82 Mini will request for the firmware to be downloaded via OTA.