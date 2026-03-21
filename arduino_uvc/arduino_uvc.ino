#include "StreamIO.h"
#include "VideoStream.h"
#include "UVCD.h"

#define STREAM_CHANNEL 0

VideoSetting stream_config(USB_UVCD_STREAM_PRESET);
Video camera_uvcd;

UVCD usb_uvcd;

StreamIO videoStreamer(1, 1);

void setup()
{
    Serial.begin(115200);

    camera_uvcd.configVideoChannel(STREAM_CHANNEL, stream_config);
    camera_uvcd.videoInit(STREAM_CHANNEL);

    usb_uvcd.configVideo(stream_config);

    videoStreamer.registerInput(camera_uvcd.getStream(STREAM_CHANNEL));
    videoStreamer.registerOutput(usb_uvcd);
    if (videoStreamer.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }

    camera_uvcd.channelBegin(STREAM_CHANNEL);
    usb_uvcd.begin(camera_uvcd.getStream(STREAM_CHANNEL), videoStreamer.linker, STREAM_CHANNEL);

    Serial.println("UVC Camera started!");
}

void loop()
{
    delay(1000);
}
