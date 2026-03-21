Set up MQTT Client-Broker Authenticated Connection — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [MQTT](index.html)
- Set up MQTT Client-Broker Authenticated Connection
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/MQTT/Set up MQTT Client-Broker Authenticated Connection.rst)
# Set up MQTT Client-Broker Authenticated Connection[](#set-up-mqtt-client-broker-authenticated-connection)
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
This example shows how to connect Ameba to MQTT-Broker with authentication.
Then send messages as publisher and receive messages from MQTT-Broker as
subscriber.
**MQTT_Auth example**
Open the MQTT example File -> Examples -> AmebaMQTTClient -> MQTT_Auth
Please modify some WiFi-related parameter and some information related to MQTT:
[](../../../../_images/image0854.png)
- “mqttServer” refers to the MQTT-Broker. The MQTT auth host setup may request service from online paid service. There is also local server setup for testing, refer to 3rd party [Tutorials](https://m-ichae-l.github.io/Public-tutorial/docs/local_emqx_mqtt_server.html)
- “clientId” is an identifier for MQTT-Broker to identify the connected
device. In this case, it is the registered device name.
- “clientUser” is the authentication username. In this case, it is the
login username of Realtek IoT/Wi-Fi MCU Solutions website. Note, it
will be unable to receive message if use the email as “clientUser”.
- “clientPass” is the authentication password. In this case, it is the
login password of Realtek IoT/Wi-Fi MCU Solutions website.
- The other parameters are same as previous.
Next, compile the code and upload it to Ameba. Press the reset button, then open the serial monitor. After Ameba is connected to MQTT server, it sends the message “hello world” to “outTopic”. To see the message, another MQTT client needs to be set up.
Start the MQTT Explore, and setup the auth connection.
Click “Connections” at top left to start a new connection setup. “Name” can be customized. Set “Host” as the server IP address (or domain name). “Username” and “Password” are same as “clientUser” and “clientPass”.
[](../../../../_images/image0950.png)
Click “ADVANCED” at bottom for topic setup. Use “outTopic” that same as “publishTopic” of the board. Click “ADD” then “BACK”.
Click “CONNECT”. The “hello world” message show up at left side. At right side, under “Publish” use “inTopic” same as “subscribeTopic” of the board. Choose “raw” and input “Text hello Ameba”, then click “PUBLISH”. The board will receive the MQTT Explorer published raw message. Note, “hello world” sometimes is not shown up because the boards connect to MQTT broker before the MQTT Explorer.
[](../../../../_images/image1046.png)
[](../../../../_images/image1136.png)
[ Previous](Set%20up%20MQTT%20Client-Broker%20Authenticated%20Connection%20with%20Publish%20in%20Callback.html)
[Next ](Set%20up%20MQTT%20Client-Broker%20Basic%20Connection%20for%20Image%20Publishing.html)
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