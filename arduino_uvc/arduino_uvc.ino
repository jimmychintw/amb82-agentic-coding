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

    Serial.println("=== BEFORE BEGIN - DUMPING REGISTERS ===");
    delay(3000);  // Wait for USB enumeration before begin()
    dumpDWC2();

    usb_uvcd.begin(camera_uvcd.getStream(STREAM_CHANNEL), videoStreamer.linker, STREAM_CHANNEL);

    Serial.println("UVC Camera started!");
}

void printHex(const char* name, uint32_t off)
{
    uint32_t val = *(volatile uint32_t*)(0x400C0000UL + off);
    char buf[48];
    snprintf(buf, sizeof(buf), "%s=0x%08lX", name, (unsigned long)val);
    Serial.println(buf);
}

void dumpDWC2()
{
    Serial.println();
    Serial.println("=== GOLDEN DUMP ===");
    printHex("GOTGCTL  ", 0x000); printHex("GAHBCFG  ", 0x008);
    printHex("GUSBCFG  ", 0x00C); printHex("GRSTCTL  ", 0x010);
    printHex("GINTSTS  ", 0x014); printHex("GINTMSK  ", 0x018);
    printHex("GRXFSIZ  ", 0x024); printHex("GNPTXFSIZ", 0x028);
    printHex("GSNPSID  ", 0x040); printHex("GHWCFG2  ", 0x048);
    printHex("DCFG     ", 0x800); printHex("DCTL     ", 0x804);
    printHex("DSTS     ", 0x808); printHex("DIEPMSK  ", 0x810);
    printHex("DOEPMSK  ", 0x814); printHex("DAINTMSK ", 0x81C);
    printHex("DOEPCTL0 ", 0xB00); printHex("DOEPTSIZ0", 0xB10);
    printHex("DOEPDMA0 ", 0xB14); printHex("DIEPCTL0 ", 0x900);
    printHex("DIEPTSIZ0", 0x910); printHex("DIEPDMA0 ", 0x914);
    printHex("PCGCCTL  ", 0xE00); printHex("ADDON    ", 0x30004);
    printHex("GDFIFOCFG", 0x05C); printHex("DIEPTXF1 ", 0x104);
    printHex("DIEPTXF2 ", 0x108);
    Serial.println("=== END GOLDEN ===");
}

void loop()
{
    static int dumped = 0;
    if (!dumped) {
        delay(5000);  // Wait 5s for enumeration to complete
        dumpDWC2();
        dumped = 1;
    }
    delay(1000);
}
