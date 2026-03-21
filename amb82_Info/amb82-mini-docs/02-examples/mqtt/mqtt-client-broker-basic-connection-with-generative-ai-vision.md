Set up MQTT Client-Broker Basic Connection with Generative AI Vision — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [MQTT](index.html)
- Set up MQTT Client-Broker Basic Connection with Generative AI Vision
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/MQTT/Set up MQTT Client-Broker Basic Connection with Generative AI Vision.rst)
# Set up MQTT Client-Broker Basic Connection with Generative AI Vision[](#set-up-mqtt-client-broker-basic-connection-with-generative-ai-vision)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
## Example[](#example)
In this example, we will be connecting AMB82-mini to a MQTT-Broker that could display images, i.e. broker.mqttgo.io.
Open Generative AI Vision with MQTT example in File -> Examples -> AmebaMQTTClient -> MQTT_GenAIVision
[](../../../../_images/image01175.png)
Please modify “ssid” and “pass” according to your WiFi network SSID and password.
[](../../../../_images/image02170.png)
Create your API key and paste it in the following section. Please refer to [GenAIVision Example](https://ameba-doc-arduino-sdk.readthedocs-hosted.com/en/latest/ameba_pro2/amb82-mini/Example_Guides/Neural%20Network/Multimedia%20AI/Generative%20AI%20Vision.html) for more details on creating API.
[](../../../../_images/image03149.png)
Uncomment the vision prompt function according to your model.
[](../../../../_images/image04104.png)
Compile and upload the firmware to AMB82-mini.
Go to [MQTTGO.io](https://broker.mqttgo.io/) and connect to server.
Subscribe to the topics to receive the **message, image and response** published by AMB82-mini. Publish your prompt to a topic where AMB82-mini has subscribed to.
Note
Only message that starts with `p/` will be recognized as a prompt message, please insert “p/” before your prompt to trigger image capture and sending to Gen AI server.
You may refer to the snapshot below for prompt sending and response receiving over MQTT broker. **Kindly define your own topics to publish and subscribe.**
[](../../../../_images/image0580.png)
## Resources[](#resources)
MQTT GO Broker
[https://broker.mqttgo.io/](https://broker.mqttgo.io/)
openAI platform - openAI vision
[https://platform.openai.com/docs/guides/vision](https://platform.openai.com/docs/guides/vision)
Google AI Studio - Gemini vision
[https://ai.google.dev/gemini-api/docs/vision](https://ai.google.dev/gemini-api/docs/vision)
GroqCloud - Llama vision
[https://console.groq.com/docs/overview](https://console.groq.com/docs/overview)
[ Previous](Set%20up%20MQTT%20Client-Broker%20Basic%20Connection%20for%20Image%20Publishing.html)
[Next ](Set%20up%20MQTT%20Client-Broker%20Basic%20Connection.html)
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