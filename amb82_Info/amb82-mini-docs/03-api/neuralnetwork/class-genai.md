Class GenAI — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [NeuralNetwork](index.html)
- Class GenAI
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/NeuralNetwork/Class GenAI.rst)
# Class GenAI[](#class-genai)
## **GenAI Class**[](#genai-class)
### **Description**[](#description)
A class used to call online GenAI API to perform various tasks.
### **Syntax**[](#syntax)
class GenAI
### **Members**[](#members)
|**Public Constructors**
|
|
| GenAI::GenAI
|
Constructs a GenAI object.
|
|
| **Public Methods**
|
|
| GenAI::openaivision
|
Send image to OpenAI server and receive response
|
|
| GenAI::geminivision
|
Send image to Gemini server and receive response
|
|
| GenAI::llamavision
|
Send image to Groq server and receive response
|
|
| GenAI::whisperaudio
|
Send audio to openAI or groq server and receive response
|
|
| GenAI::googletts
|
Perform TTS using Google TTS API and save audio to
SD card as MP3 file
|
|
| GenAI::geminiaudio
|
Send audio recording to Gemini server and receive response
|
|
| GenAI::geminivideo
|
Send video recording to Gemini server and receive response
|
|
## **GenAI::openaivision**[](#genai-openaivision)
### **Description**[](#id1)
Send image to OpenAI server and receive response.
### **Syntax**[](#id2)
String openaivision(String key, String model, String message, uint32_t img_addr, uint32_t img_len, WiFiSSLClient client);
### **Parameters**[](#parameters)
key: OpenAI API key
model: LLM model
message: Prompt message
img_addr: Captured image address
img_len: Size of the captured image
client: WiFi SSL Client object
### **Returns**[](#returns)
Response from LLM model
### **Example Code**[](#example-code)
Example: [GenAIVision](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/MultimediaAI/GenAIVision/GenAIVision.ino)
## **GenAI::geminivision**[](#genai-geminivision)
### **Description**[](#id3)
Send image to Gemini server and receive response.
### **Syntax**[](#id4)
String geminivision(String key, String model, String message, uint32_t img_addr, uint32_t img_len, WiFiSSLClient client);
### **Parameters**[](#id5)
key: Gemini API key
model: LLM model
message: Prompt message
img_addr: Captured image address
img_len: Size of the captured image
client: WiFi SSL Client object
### **Returns**[](#id6)
Response from LLM model
### **Example Code**[](#id7)
Example: [GenAIVision](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/MultimediaAI/GenAIVision/GenAIVision.ino)
## **GenAI::llamavision**[](#genai-llamavision)
### **Description**[](#id9)
Send image to OpenAI server and receive response.
### **Syntax**[](#id10)
String llamavision(String key, String model, String message, uint32_t img_addr, uint32_t img_len, WiFiSSLClient client);
### **Parameters**[](#id11)
key: Groq API key
model: LLM model
message: Prompt message
img_addr: Captured image address
img_len: Size of the captured image
client: WiFi SSL Client object
### **Returns**[](#id12)
Response from LLM model
### **Example Code**[](#id13)
Example: [GenAIVision](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/MultimediaAI/GenAIVision/GenAIVision.ino)
## **GenAI::whisperaudio**[](#genai-whisperaudio)
### **Description**[](#id15)
Send audio to openAI or groq server and receive response
### **Syntax**[](#id16)
String whisperaudio(String api_key, char* api_server, String api_path, String model, String filename, WiFiSSLClient client);
### **Parameters**[](#id17)
api_key: OpenAI or Groq API key
api_server: Online LLM API server
api_path: API endpoint
model: LLM model
filename: audio filename
client: WiFi SSL Client object
### **Returns**[](#id18)
Response from LLM model
### **Example Code**[](#id19)
Example: [GenAISpeech](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/MultimediaAI/GenAISpeech/GenAISpeech.ino)
## **GenAI::googletts**[](#genai-googletts)
### **Description**[](#id20)
Perform TTS using Google TTS API and save audio to SD card as MP3 file
### **Syntax**[](#id21)
void googletts(String filename_mp3, String message, String lang);
### **Parameters**[](#id22)
filename_mp3: Speech audio filename
message: Text message to perform TTS
lang: Language code
### **Returns**[](#id23)
NA
### **Example Code**[](#id24)
Example: [TextToSpeech](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/MultimediaAI/TextToSpeech/TextToSpeech.ino)
## **GenAI::geminiaudio**[](#genai-geminiaudio)
### **Description**[](#id25)
Send MP4 audio recording to Gemini server and receive response.
### **Syntax**[](#id26)
String geminiaudio(String apikey, String filename, String model, MP4Recording &mp4, String message, WiFiSSLClient client);
### **Parameters**[](#id27)
key: Gemini API key
filename: MP4 audio recording filename
model: LLM model
mp4: mp4 object parsing
message: Prompt message
client: WiFi SSL Client object
### **Returns**[](#id28)
Response from LLM model
### **Example Code**[](#id29)
Example: [GenAISpeech](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/MultimediaAI/GenAISpeech/GenAISpeech.ino)
## **GenAI::geminivideo**[](#genai-geminivideo)
### **Description**[](#id31)
Send MP4 video with audio recording to Gemini server and receive response.
### **Syntax**[](#id32)
String geminivideo(String apikey, String filename, String model, MP4Recording &mp4, String message, WiFiSSLClient client);
### **Parameters**[](#id33)
key: Gemini API key
filename: MP4 video recording filename
model: LLM model
mp4: mp4 object parsing
message: Prompt message
client: WiFi SSL Client object
### **Returns**[](#id34)
Response from LLM model
### **Example Code**[](#id35)
Example: [GenAIVideo](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/MultimediaAI/GenAIVideo/GenAIVideo.ino)
[ Previous](Class%20FaceDetectionRecognition.html)
[Next ](Class%20Image%20Classification.html)
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