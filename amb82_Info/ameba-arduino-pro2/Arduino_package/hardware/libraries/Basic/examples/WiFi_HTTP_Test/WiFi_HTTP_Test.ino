/*
  WiFi HTTP Test - 測試網路連線
  連線 WiFi 後發送 HTTP 請求測試上網
*/

#include <WiFi.h>
#include <HttpClient.h>

char ssid[] = "JimmyMBP";
char password[] = "11223344";

void setup() {
    Serial.begin(115200);
    Serial.flush();
    delay(100);
    
    Serial.println("=== WiFi HTTP 測試 ===");
    Serial.flush();

    Serial.print("正在連線到 ");
    Serial.println(ssid);
    Serial.flush();
    
    WiFi.begin(ssid, password);
    
    Serial.println("等待連線...");
    Serial.flush();
    
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
        Serial.print("IP: ");
        Serial.println(WiFi.localIP());
        Serial.print("RSSI: ");
        Serial.print(WiFi.RSSI());
        Serial.println(" dBm");
        Serial.flush();
        delay(500);

        Serial.println("發送 HTTP 請求...");
        Serial.flush();

        WiFiClient wifiClient;
        HttpClient http(wifiClient);
        
        int err = http.get("example.com", 80, "/");
        if (err == 0) {
            Serial.println("HTTP 請求發送成功!");
            Serial.flush();
            err = http.responseStatusCode();
            Serial.print("Status code: ");
            Serial.println(err);
            Serial.flush();
            
            if (err > 0) {
                http.skipResponseHeaders();
                Serial.println("回應內容:");
                Serial.flush();
                int count = 0;
                while (http.available() && count < 300) {
                    char c = http.read();
                    Serial.print(c);
                    count++;
                }
                Serial.println("");
                Serial.println("=== 測試成功! 可以上網! ===");
            }
        } else {
            Serial.print("HTTP 請求失敗，錯誤碼: ");
            Serial.println(err);
        }
    } else {
        Serial.println("");
        Serial.println("WiFi 連線失敗!");
        Serial.print("連線狀態: ");
        Serial.println(WiFi.status());
    }
    Serial.flush();
}

void loop() {
    delay(5000);
    Serial.println("執行中... (按 RESET 重啟)");
    Serial.flush();
}
