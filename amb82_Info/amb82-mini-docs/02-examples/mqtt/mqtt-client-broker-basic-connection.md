Set up MQTT Client-Broker Basic Connection — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [MQTT](index.html)
- Set up MQTT Client-Broker Basic Connection
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/MQTT/Set up MQTT Client-Broker Basic Connection.rst)
# Set up MQTT Client-Broker Basic Connection[](#set-up-mqtt-client-broker-basic-connection)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
MQTT (Message Queuing Telemetry Transport) is a protocol proposed by IBM and Eurotech. The introduction in MQTT Official Website:
MQTT is a machine-to-machine (M2M)/”Internet of Things” connectivity protocol. It was designed as an extremely lightweight publish/subscribe messaging transport.We can say MQTT is a protocol designed for IoT. MQTT is based on TCP/IP and transmits/receives data via publish/subscribe.
Please refer to the figure below:
[](../../../../_images/image01174.png)
In the operation of MQTT, there are several roles:
- Publisher: Usually publishers are the devices equipped with sensors
(ex. Ameba). Publishers uploads the data of the sensors to
MQTT-Broker, which serves as a database with MQTT service.
- Subscriber: Subscribers are referred to the devices which receive and
observe messages, such as a laptop or a mobile phone.
- Topic: Topic is used to categorize the messages, for example the
topic of a message can be “PM2.5” or “Temperature”. Subscribers can
choose messages of which topics they want to receive.
This example shows how to connect Ameba to MQTT-Broker.
Then, send messages as publisher and receive messages from MQTT-Broker as
subscriber.
**MQTT_Basic example**
Open the MQTT example File -> Examples -> AmebaMQTTClient -> MQTT_Basic
Please modify some WiFi-related parameter and some information related to MQTT:
[](../../../../_images/image02169.png)
- “ssid” is the network SSID for internet access.
- “pass” is the network password for internet access.
- “mqttServer” refers to the MQTT-Broker, there is free MQTT sandbox
“test.mosquitto.org” for testing.
- “clientId” is an identifier for MQTT-Broker to identify the connected
device.
- “publishTopic” is the topic of the published message in the example
it is “outTopic”. The devices that subscribed to “outTopic” will
receive the message.
- “publishPayload” is the content to be published.
- “subscribeTopic” is to tell MQTT-broker which topic to subscribe to
by the board.
Next, compile the code and upload it to Ameba. Press the reset button, then open the serial monitor.
[](../../../../_images/image03148.png)
After Ameba is connected to MQTT server, it sends the message “hello world” to “outTopic”. To see the message, another MQTT client needs to be set up.
The “MQTT Explore” is an all-platform application that can be set as the MQTT client. Refer to the website [http://mqtt-explorer.com/](http://mqtt-explorer.com/).
Click “Connections” at top left to start a new connection setup. “Name” can be customized. Set “Host” as “test.mosquitto.org”.
[](../../../../_images/image04103.png)
Click “ADVANCED” at bottom for topic setup. Use “outTopic” that same as “publishTopic” of the board. Click “ADD” then “BACK”.
[](../../../../_images/image0579.png)
Click “CONNECT”. The “hello world” message show up at left side. At right side, under “Publish” use “inTopic” same as “subscribeTopic” of the board. Choose “raw” and input “Text hello Ameba”, then click “PUBLISH”. The board will receive the MQTT Explorer published raw message. Note, because of the host is a free public host, the board may receive unexpected messages.
[](../../../../_images/image0669.png)
[](../../../../_images/image0764.png)
[ Previous](Set%20up%20MQTT%20Client-Broker%20Basic%20Connection%20with%20Generative%20AI%20Vision.html)
[Next ](../Multimedia/index.html)
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