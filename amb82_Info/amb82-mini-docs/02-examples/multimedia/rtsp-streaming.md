# RTSP Streaming

## Materials

- AMB82-mini x 1

## Example

In this example, we will use the Ameba Pro2 board to stream video and audio data from the on-board camera sensor (JX-F37P) and audio codec to a computer via RTSP (Real Time Streaming Protocol).

The following examples shows different use cases of RTSP streaming:

1. VideoOnly
2. SingleVideoWithAudio
3. DoubleVideo
4. DoubleVideoWithAudio

Fill in the "ssid" with your WiFi network SSID and "pass" with the network password.

Compile the code and upload it to Ameba. After pressing the Reset button, wait for the Ameba Pro 2 board to connect to the WiFi network. The board's IP address and network port number for RTSP will be shown in the Serial Monitor.

Download VLC media player from: https://www.videolan.org/vlc/

Upon the completion of the software installation, open VLC media player, and go to Media -> Open Network Stream

Make sure your PC is connected to the same network as the Ameba Pro2 board for streaming. Since RTSP is used as the streaming protocol, key in `rtsp://{IPaddress}:{port}` as the Network URL in VLC media player, replacing {IPaddress} with the IP address of your Ameba Pro2 board, and {port} with the RTSP port shown in Serial Monitor (e.g., rtsp://192.168.1.154:554). The default RTSP port number is 554. In the case of two simultaneous RTSP streams, the second port number defaults to 555.

You may choose to change the caching time in "Show more options". A lower cache time will result in reduced video latency but may introduce playback stuttering.

Next, click "Play" to start RTSP streaming. The video stream from the camera will be shown in VLC media player. Meanwhile, in your Serial Monitor, the message "rtp started (UDP)" will appear.

## Stream Details

| Example | Description |
|---------|-------------|
| StreamRTSPVideoOnly | Single RTSP stream of video only, on port 554 |
| StreamRTSPSingleVideoWithAudio | Single RTSP stream of video and audio, on port 554 |
| StreamRTSPDoubleVideo | Two RTSP streams of video only, on ports 554 and 555 |
| StreamRTSPDoubleVideoWithAudio | Two RTSP streams of video and audio, on ports 554 and 555 |

## Code Reference

The camera can produce 3 simultaneous video stream channels, with the default configuration for each channel:

- Channel 0: 1920 x 1080, 30FPS, H264 format
- Channel 1: 1280 x 720, 30FPS, H264 format
- Channel 2: 1280 x 720, 30FPS, MJPEG format

You may adjust the video bitrate based on your WiFi network quality.