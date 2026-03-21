# DHT over BLE UART

## Materials

- AMB82-mini x 1
- DHT11 or DHT22 or DHT21
- Android / iOS smartphone

## Example

### Introduction

In this example, the data obtained from a DHT temperature and humidity sensor are transmitted over a BLE UART service to a smartphone. Refer to the other examples for detailed explanations of using the DHT sensor and the BLE UART service.

### Procedure

Take note that if you are using a DHT sensor that is not mounted on a PCB, you will have to add in a 10K Ohm pull up resistor.

Connect the DHT sensor to the Ameba board following the diagram.

**AMB82 MINI:**

DHT sensor not mounted on a PCB board - Connect with 10K pull-up resistor

DHT sensor mounted on a PCB board - Direct connection

Ensure that a compatible BLE UART app is installed on your smartphone:
- Google Play Store: https://play.google.com/store/apps/details?id=com.adafruit.bluefruit.le.connect
- Apple App Store: https://apps.apple.com/us/app/bluefruit-connect/id830125974

Open the example, Files -> Examples -> AmebaBLE -> DHT_over_BLEUart

Upload the code and press the reset button on Ameba once the upload is finished.

Open the app on your smartphone, scan and connect to the Ameba board shown as "AMEBA_BLE_DEV" and choose the UART function in the app.

After starting the UART function, notifications should be received every 5 seconds containing the measured temperature and humidity.