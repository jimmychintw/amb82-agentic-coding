Set up MQTT Client over TLS — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [MQTT](index.html)
- Set up MQTT Client over TLS
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/MQTT/Set up MQTT Client over TLS.rst)
# Set up MQTT Client over TLS[](#set-up-mqtt-client-over-tls)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
In this example, Ameba connect to a MQTT broker using TLS authentication. Then, send messages as a publisher and receive messages as a subscriber.
Open example at File -> Examples -> AmebaMQTTClient -> MQTT_TLS
Please modify the WiFi-related parameters and MQTT parameters.
[](../../../../_images/image01173.png)
- “ssid” is the network SSID for internet access.
- “pass” is the network password for internet access.
- The “mqttServer” refers to the MQTT-Broker, there is free MQTT
sandbox “test.mosquitto.org” for testing.
- “clientId” is an identifier for MQTT-Broker to identify the connected
device.
- “publishTopic” is the topic of the published message. It is
“outTopic” in the example. The devices that subscribed to “outTopic”
will receive the message.
- “publishPayload” is the content to be published.
- “subscribeTopic” is to tell MQTT-broker which topic to subscribe to
by the board.
Next, compile the code and upload it to Ameba. Press the reset button,
then open the serial monitor.
[](../../../../_images/image02168.png)
After Ameba is connected to MQTT server, it sends the message “hello world” to “outTopic”. To see the message, use another MQTT client. Refer to the MQTT_Basic example guide on how to setup a PC-based MQTT client.
In addition to use TLS client authentication to server authentication, it requires to generate an OpenSSL private key and obtain a signed certificate from the server. For testing purposes, signed certificates can be obtained from test.mosquitto.org by following the guide at [https://test.mosquitto.org/ssl/](https://test.mosquitto.org/ssl/).
Replace the character strings “certificateBuff” and “privateKeyBuff” with the signed certificate and OpenSSL private key, ensuring that they are formatted the same way as the shown in the example code. Set “MQTT_TLS_SERVER_AUTH” to be “1”.
[](../../../../_images/image03147.png)
[ Previous](index.html)
[Next ](Set%20up%20MQTT%20Client-Broker%20Authenticated%20Connection%20with%20Publish%20in%20Callback.html)
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