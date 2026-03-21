# Online AI Model Conversion Guide

Note: Please Log in to access the page at https://www.amebaiot.com/en/amebapro2-ai-convert-model/

## Supported Models

| Models | Basic Functions | Required Files |
|--------|-----------------|----------------|
| yolov3-tiny, darknet | Object Detection | ".cfg", ".weights" |
| yolov4-tiny, darknet | Object Detection | ".cfg", ".weights" |
| yolov7-tiny, darknet | Object Detection | ".cfg", ".weights" |
| yolov7-tiny, pytorch | Object Detection | ".pt" |
| scrfd/mobilefacenet | Face Detection & Recognition | ".pt" or ".onnx" |
| yamnet | Sound Classification | ".h5" |
| CNN Gray/RGB | Image Classification | ".h5" or ".onnx" |

The quantize images are optional for uploading (up to 10).

## CNN Gray/RGB Instructions

For CNN Gray/RGB, please refer to the following instructions to get the correct converted models:

1. When training model: supported tensorflow version up to 2.14.1

2. When saving model: set flag as "include_optimizer=False"

## After AI Model Conversion

There will be download link sent out by email.

For more information, please refer to the Customized AI model Installation Guide at https://www.amebaiot.com/en/ameba-arduino-summary/

## Additional References

- AMB82 MobileFaceNet Convert To ONNX: https://www.amebaiot.com/amebapro2-mobilefacenet-convert-to-onnx
- AMB82 SCRFD Convert To ONNX: https://www.amebaiot.com/amebapro2-scrfd-convert-to-onnx