/*
  RTSP Video Streaming - 超低延遲版
  連線 WiFi 後透過 RTSP 協定串流攝影機影像

  WiFi: JimmyMBP / 11223344
  
  使用方式：
  1. 上傳程式
  2. 開啟 VLC
  3. 輸入網址: rtsp://<IP_ADDRESS>:8555/live

  VLC 超低延遲設定：
  - Tools > Preferences > All > Input/Codecs > Network caching > 设为 0 ms
  - 播放時按 Ctrl+P 取消緩衝
*/

#include "WiFi.h"
#include "StreamIO.h"
#include "VideoStream.h"
#include "RTSP.h"

#define CHANNEL 0

// 保持原始解析度, 調低 FPS 減少緩衝
VideoSetting config(CHANNEL);
RTSP rtsp;
StreamIO videoStreamer(1, 1);

char ssid[] = "JimmyMBP";
char pass[] = "11223344";

void setup() {
    Serial.begin(115200);
    Serial.flush();
    delay(100);

    Serial.println("=== RTSP Video Streaming ===");
    Serial.flush();

    // 連線 WiFi
    Serial.print("正在連線到 ");
    Serial.println(ssid);
    Serial.flush();

    int status = WiFi.begin(ssid, pass);
    
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 30) {
        delay(500);
        Serial.print(".");
        Serial.flush();
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("WiFi 連線成功!");
        IPAddress ip = WiFi.localIP();
        Serial.print("IP 位址: ");
        Serial.println(ip);
        Serial.flush();
    } else {
        Serial.println("");
        Serial.println("WiFi 連線失敗!");
        return;
    }

    delay(500);
    Serial.println("");
    Serial.println("正在初始化攝影機...");
    Serial.flush();

    // 設定視訊格式 (720p, 20fps, H264)
    // 降低延遲: 調低 Bitrate
    config.setBitrate(1500000);  // 1.5Mbps - 較低延遲
    Camera.configVideoChannel(CHANNEL, config);
    Camera.videoInit();

    // 設定 RTSP - 低延遲模式
    rtsp.configVideo(config);
    rtsp.begin();

    // 設定資料流串流
    videoStreamer.registerInput(Camera.getStream(CHANNEL));
    videoStreamer.registerOutput(rtsp);
    
    if (videoStreamer.begin() != 0) {
        Serial.println("串流起始失敗!");
        return;
    }

    // 啟動影像通道
    Camera.channelBegin(CHANNEL);

    delay(500);
    printInfo();
}

void loop() {
    IPAddress ip = WiFi.localIP();
    Serial.print("RTSP: rtsp://");
    Serial.print(ip);
    Serial.println(":8555/live");
    Serial.flush();
    delay(5000);
}

void printInfo(void) {
    Serial.println("==================================");
    Serial.println("       RTSP 串流資訊       ");
    Serial.println("==================================");
    IPAddress ip = WiFi.localIP();
    Serial.print("RTSP 位址: rtsp://");
    Serial.print(ip);
    Serial.println(":8555/live");
    Serial.println("==================================");
    Camera.printInfo();
    rtsp.printInfo(ip.get_address());
    Serial.flush();
}
