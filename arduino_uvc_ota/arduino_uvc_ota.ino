/*
 * Arduino UVC + WiFi OTA Server
 * - USB UVC webcam functionality
 * - WiFi OTA server on port 8080 for firmware updates
 * - Compatible with FreeRTOS OTA (same flash partition)
 *
 * OTA Usage:
 *   curl -X POST --data-binary @firmware.bin http://<IP>:8080/ota
 *   curl -X POST http://<IP>:8080/reboot
 *   curl http://<IP>:8080/
 */

#include "StreamIO.h"
#include "VideoStream.h"
#include "UVCD.h"
#include "WiFi.h"
extern "C" {
#include "flash_api.h"
#include "sys_api.h"
#include "device_lock.h"
}

// WiFi credentials
char ssid[] = "JimmyAXPro";
char pass[] = "23640966";

// OTA server
WiFiServer otaServer(8080);
#define OTA_BUF_SIZE 4096
#define PT_FW1_ADDR_OFFSET 0x14

// UVC
#define STREAM_CHANNEL 0
VideoSetting stream_config(USB_UVCD_STREAM_PRESET);
Video camera_uvcd;
UVCD usb_uvcd;
StreamIO videoStreamer(1, 1);

// Forward declarations
void handleOTA(WiFiClient &client, uint8_t *buf, int bufLen);
void sendResponse(WiFiClient &client, int code, const char *status, const char *body);

void setup()
{
    Serial.begin(115200);
    Serial.println("\n=== Arduino UVC + OTA ===");

    // Connect WiFi
    int wifiStatus = WL_IDLE_STATUS;
    while (wifiStatus != WL_CONNECTED) {
        Serial.print("Connecting to WiFi: ");
        Serial.println(ssid);
        wifiStatus = WiFi.begin(ssid, pass);
        delay(2000);
    }
    Serial.print("WiFi connected, IP: ");
    Serial.println(WiFi.localIP());

    // Start OTA server
    otaServer.begin();
    Serial.println("OTA server on port 8080");
    Serial.print("  Upload: curl -X POST --data-binary @firmware.bin http://");
    Serial.print(WiFi.localIP());
    Serial.println(":8080/ota");

    // Configure UVC
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

    Serial.println("UVC started. Ready.");
}

void loop()
{
    // Handle OTA HTTP requests
    WiFiClient client = otaServer.available();
    if (client) {
        Serial.println("[OTA] Client connected");
        uint8_t buf[OTA_BUF_SIZE];
        int len = 0;

        // Read HTTP request (with timeout)
        unsigned long start = millis();
        while (client.connected() && (millis() - start < 5000)) {
            if (client.available()) {
                int n = client.read(buf + len, sizeof(buf) - len);
                if (n > 0) len += n;
                // Check if we have the full headers
                if (len >= 4) {
                    // Look for \r\n\r\n
                    for (int i = 0; i < len - 3; i++) {
                        if (buf[i] == '\r' && buf[i+1] == '\n' && buf[i+2] == '\r' && buf[i+3] == '\n') {
                            goto headers_done;
                        }
                    }
                }
                if (len >= (int)sizeof(buf) - 1) goto headers_done;
            }
            delay(1);
        }
        headers_done:

        buf[len < (int)sizeof(buf) ? len : (int)sizeof(buf) - 1] = '\0';

        // Parse request
        if (strstr((char*)buf, "GET / ") != NULL) {
            // Status page
            char body[256];
            IPAddress ip = WiFi.localIP();
            snprintf(body, sizeof(body),
                "<html><body><h2>AMB82 Arduino UVC+OTA</h2>"
                "<p>IP: %d.%d.%d.%d</p>"
                "<p>Free heap: %u bytes</p>"
                "<hr>"
                "<p>POST /ota - Upload firmware.bin</p>"
                "<p>POST /reboot - Reboot device</p>"
                "</body></html>",
                ip[0], ip[1], ip[2], ip[3],
                (unsigned)xPortGetFreeHeapSize());
            sendResponse(client, 200, "OK", body);
        }
        else if (strstr((char*)buf, "POST /reboot") != NULL) {
            sendResponse(client, 200, "OK", "Rebooting...\n");
            delay(500);
            sys_reset();
        }
        else if (strstr((char*)buf, "POST /ota") != NULL) {
            handleOTA(client, buf, len);
        }
        else {
            sendResponse(client, 404, "Not Found", "Unknown endpoint\n");
        }

        delay(10);
        client.stop();
    }

    delay(10);
}

void sendResponse(WiFiClient &client, int code, const char *status, const char *body)
{
    client.print("HTTP/1.1 ");
    client.print(code);
    client.print(" ");
    client.println(status);
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.print("Content-Length: ");
    client.println(strlen(body));
    client.println();
    client.print(body);
}

void handleOTA(WiFiClient &client, uint8_t *initial_buf, int initial_len)
{
    flash_t flash_obj;
    uint32_t fw_addr = 0;
    int content_length = 0;

    // Parse Content-Length
    char *cl = strstr((char*)initial_buf, "Content-Length:");
    if (!cl) cl = strstr((char*)initial_buf, "content-length:");
    if (!cl) {
        sendResponse(client, 400, "Bad Request", "Missing Content-Length\n");
        return;
    }
    content_length = atoi(cl + 15);
    Serial.print("[OTA] Firmware size: ");
    Serial.println(content_length);

    if (content_length < 100*1024 || content_length > 8*1024*1024) {
        sendResponse(client, 400, "Bad Request", "Invalid firmware size\n");
        return;
    }

    // Read FW1 address from partition table
    device_mutex_lock(RT_DEV_LOCK_FLASH);
    flash_read_word(&flash_obj, PT_FW1_ADDR_OFFSET, &fw_addr);
    device_mutex_unlock(RT_DEV_LOCK_FLASH);

    if (fw_addr == 0 || fw_addr == 0xFFFFFFFF) {
        sendResponse(client, 500, "Internal Server Error", "Bad FW1 address\n");
        return;
    }
    Serial.print("[OTA] FW1 addr: 0x");
    Serial.println(fw_addr, HEX);

    // Find body start
    char *body = strstr((char*)initial_buf, "\r\n\r\n");
    if (!body) {
        sendResponse(client, 400, "Bad Request", "Malformed request\n");
        return;
    }
    body += 4;
    int body_offset = body - (char*)initial_buf;
    int body_in_buf = initial_len - body_offset;

    // Allocate sector buffer
    uint8_t *sector_buf = (uint8_t *)malloc(OTA_BUF_SIZE);
    if (!sector_buf) {
        sendResponse(client, 500, "Internal Server Error", "Out of memory\n");
        return;
    }

    int total_written = 0;
    int sector_pos = 0;
    uint32_t write_addr = fw_addr;

    // Process body data already in buffer
    if (body_in_buf > 0) {
        memcpy(sector_buf, body, body_in_buf);
        sector_pos = body_in_buf;
    }

    // Flush full sectors and read more data
    while (total_written + sector_pos < content_length) {
        // Write full sector
        if (sector_pos >= OTA_BUF_SIZE) {
            device_mutex_lock(RT_DEV_LOCK_FLASH);
            flash_erase_sector(&flash_obj, write_addr);
            flash_burst_write(&flash_obj, write_addr, OTA_BUF_SIZE, sector_buf);
            device_mutex_unlock(RT_DEV_LOCK_FLASH);
            write_addr += OTA_BUF_SIZE;
            total_written += OTA_BUF_SIZE;
            sector_pos = 0;

            if (total_written % (256*1024) == 0) {
                Serial.print("[OTA] ");
                Serial.print(total_written / 1024);
                Serial.println("KB written");
            }
        }

        // Read more from network
        if (client.available()) {
            int space = OTA_BUF_SIZE - sector_pos;
            int n = client.read(sector_buf + sector_pos, space);
            if (n > 0) sector_pos += n;
        } else if (!client.connected()) {
            break;
        } else {
            delay(1);
        }
    }

    // Write remaining data
    if (sector_pos > 0) {
        // Pad to sector boundary
        if (sector_pos < OTA_BUF_SIZE) {
            memset(sector_buf + sector_pos, 0xFF, OTA_BUF_SIZE - sector_pos);
        }
        device_mutex_lock(RT_DEV_LOCK_FLASH);
        flash_erase_sector(&flash_obj, write_addr);
        flash_burst_write(&flash_obj, write_addr, OTA_BUF_SIZE, sector_buf);
        device_mutex_unlock(RT_DEV_LOCK_FLASH);
        total_written += sector_pos;
    }

    free(sector_buf);

    Serial.print("[OTA] Total written: ");
    Serial.print(total_written);
    Serial.println(" bytes");

    sendResponse(client, 200, "OK", "OTA OK, rebooting...\n");
    delay(500);
    sys_reset();
}
