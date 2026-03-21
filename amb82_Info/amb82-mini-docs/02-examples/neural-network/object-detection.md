# Object Detection

## Materials

- AMB82-mini x 1

## Example

In this example, we will be using Ameba Pro2 development board to detect 80 different kinds of objects such as person, bicycle, car, laptop etc using on-board camera sensor (JX-F37P).

The following examples show how Object Detection and On-Screen Display is used:

1. ObjectDetectionLoop
2. ObjectDetectionCallback

Open one of the Object Detection examples in File -> Examples -> AmebaNN -> ObjectDetectionLoop

Fill in the "ssid" with your WiFi network SSID and "pass" with the network password.

Select Neural Network (NN) task and models using `modelSelect()` function. This function takes 4 arguments: Neural Network task, Object Detection model, Face Detection model and Face Recognition model. Replace with "NA_MODEL" if they are not necessary.

Valid Neural Network task: OBJECT_DETECTION, FACE_DETECTION, FACE_RECOGNITION

Valid Object Detection model:
- YOLOv3: DEFAULT_YOLOV3TINY, CUSTOMIZED_YOLOV3TINY
- YOLOv4: DEFAULT_YOLOV4TINY, CUSTOMIZED_YOLOV4TINY
- YOLOv7: DEFAULT_YOLOV7TINY, CUSTOMIZED_YOLOV7TINY

Compile the code and upload it to Ameba. After pressing the Reset button, wait for the Ameba Pro 2 board to connect to the WiFi network. The board's IP address and network port number for RTSP will be shown in the Serial Monitor.

The result of detected objects can be validated using VLC. Open VLC media player, go to Media -> Open Network Stream, and enter `rtsp://{IPaddress}:{port}`.

A bounding box with its object name and confidence score will be drawn on the RTSP video stream to highlight the recognised objects.

The pretrained model can recognise 80 different types of objects in total. The objects can be found in ObjectClassList.h.

## Code Reference

You may adjust the video bitrate based on your WiFi network quality.