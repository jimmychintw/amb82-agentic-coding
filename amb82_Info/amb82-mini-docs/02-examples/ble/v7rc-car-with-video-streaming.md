# V7RC Car With Video Streaming

## Materials

- AMB82-mini x 1
- Android / iOS mobile phone x1
- L9110S Servo Motor Controller x1
- TT Motor x2

## Example

### Introduction

In this example, we will use Ameba Pro2 as the BLE Peripheral device and the servo motor controller to communicate with the V7RC mobile app. Besides, video will be streamed from the on-board camera sensor (JXF37P) to V7RC mobile app via RTSP (Real Time Streaming Protocol). V7RC is a remote controller APP that provides two kinds of control UI: one is 2 channels for RC cars, and the other is 4 channels for tanks and bulldozers.

### Procedure

**1. Setup RTSP Streaming**

Open the example, Files -> Examples -> AmebaBLE -> BLEV7RC_CAR_VIDEO

Since the video receiving end is mobile devices, set the video resolution to VIDEO_D1 (720x480) to limit the video receiving latency.

Fill in the "ssid" with your WiFi network SSID and "pass" with the network password. Use 5G network for lower latency.

Compile the code and upload it to Ameba. After pressing the Reset button, wait for the board to connect to the Wi-Fi network. The board's IP address and network port number for RTSP will be shown in the Serial Monitor.

Download V7RC APP:
- Android Users: https://play.google.com/store/apps/details?id=com.v7idea.v7rcliteandroidsdkversion
- iPhone Users: https://apps.apple.com/nz/app/v7rc/id1390983964

Upon the completion of the APP installation, make sure your smart phone is connected to the same network as the Ameba Pro2 board for streaming. Open V7RC APP and select "Control Centre":

Under NETWORK section, select "WIFI". Under CAMERA section select "RTSP". Key in "rtsp://{IPaddress}:{port}" as the Network URL.

**2. Establish BLE Connection**

Open V7RC APP and select "Control Centre". Under NETWORK section, select "BLE". Click DEVICE, and select AMEBA_BLE_DEV and click "LINK" button to connect to your Ameba board.

**3. Setup Servo Motors**

Connect two servo motors to L9110S servo controller using predefined pins:
- MotoA_1A (GPIO 16) - Control MotorA direction
- MotoA_1B (PWM pin 7) - Control MotorA speed
- MotoB_1A (GPIO 17) - Control MotorB direction
- MotoB_1B (PWM pin 8) - Control MotorB speed

## Code Reference

1. `ParseCMDString(String cmd)` is a customized function to process commands from V7RC App: "SS2", "SS4", "SRT", "SR2", and "SRV".

2. Recommended video settings for V7RC RTSP streaming:
   - VideoSetting config(VIDEO_HD, CAM_FPS, VIDEO_H264, 0); // 1280x720
   - VideoSetting config(VIDEO_D1, CAM_FPS, VIDEO_H264, 0); // 720x480