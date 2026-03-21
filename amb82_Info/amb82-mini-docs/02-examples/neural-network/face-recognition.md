# Face Recognition

## Materials

- AMB82-mini x 1

## Example

In this example, we will be using Ameba Pro2 development board to recognize detected faces.

Open face recognition examples in File -> Examples -> AmebaNN -> RTSPFaceRecognition

Fill in the "ssid" with your WiFi network SSID and "pass" with the network password.

Select Neural Network (NN) task and models using `modelSelect()` function. This function takes 4 arguments: Neural Network task, Object Detection model, Face Detection model and Face Recognition model.

Compile the code and upload it to Ameba. After pressing the Reset button, wait for the board to connect to the WiFi network. The board's IP address and network port number for RTSP will be shown in the Serial Monitor.

The result of face recognition can be validated using VLC. Open VLC media player, and go to Media -> Open Network Stream, enter `rtsp://{IPaddress}:{port}`.

The faces detected by the face recognition neural network model are initially labelled as "unknown", faces need to be first registered with a name before they can be recognized.

**To register a face:**

Note: Multiple faces can be registered. However, when registering a face, ensure that there is only one face in the frame.

To register a face, aim the camera to a targeted face and enter **"REG={Name}"** to give the targeted face a name. For example, "REG=SAM".

**To remove a specific registered face:**

Enter the command **"DEL={Name}"** to delete a certain registered face. For example, "DEL=SAM".

**To reset all registered faces:**

Enter the command **"RESET"** to forget all previously registered faces.

**To backup and restore registered faces:**

Enter the command **"BACKUP"** to save a copy of registered faces to flash. Enter the command **"RESTORE"** to load registered faces from flash.

## Code Reference

You may adjust the video bitrate based on your WiFi network quality.