#include "WiFi.h"
#include "StreamIO.h"
#include "VideoStream.h"
#include "RTSP.h"

#define STREAM_CHANNEL 0

VideoSetting config(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0);
RTSP rtsp;
StreamIO videoStreamer(1, 1);
char ssid[] = "JimmyAXPro";
char pass[] = "23640966";

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");
    Serial.println(WiFi.localIP());

    Camera.configVideoChannel(STREAM_CHANNEL, config);
    Camera.videoInit();

    rtsp.configVideo(config);
    rtsp.begin();

    videoStreamer.registerInput(Camera.getStream(STREAM_CHANNEL));
    videoStreamer.registerOutput(rtsp);
    if (videoStreamer.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }

    Camera.channelBegin(STREAM_CHANNEL);
    Serial.println("RTSP started!");
}

void loop()
{
    delay(1000);
}
