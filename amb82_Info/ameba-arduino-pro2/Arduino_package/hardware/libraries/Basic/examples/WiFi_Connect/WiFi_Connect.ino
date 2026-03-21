/*
  WiFi Connect - WiFi 連線範例
  連線到指定的 WiFi 網路

  SSID: JimmyMBP
  Password: 11223344
*/

#include <WiFi.h>

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        ;  // 等待序列阜就緒
    }

    Serial.println("正在連線到 WiFi...");
    
    WiFi.begin("JimmyMBP", "11223344");
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("");
    Serial.println("WiFi 連線成功!");
    Serial.print("IP 位址: ");
    Serial.println(WiFi.localIP());
    Serial.print("訊號強度: ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
}

void loop() {
    // 已連線，無需重複連線
    delay(1000);
}
