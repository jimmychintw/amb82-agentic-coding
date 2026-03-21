# AMB82-MINI (RTL8735B) 文檔總索引

本目錄包含 Ameba Arduino SDK 中所有關於 AMB82-MINI (RTL8735B) 的完整文檔。

## 文檔來源

- 官方文檔：https://ameba-doc-arduino-sdk.readthedocs-hosted.com/en/latest/ameba_pro2/amb82-mini/
- 抓取日期：2026-03-13

## 目錄結構

```
amb82-mini-docs/
├── 00-index.md                  # 本文件
├── 01-getting-started/          # 入門指南
│   └── getting-started.md
├── 02-examples/                 # 範例指南
│   ├── basic/
│   ├── ble/
│   ├── e-paper/
│   ├── file-system/
│   ├── flash-memory/
│   ├── gpio/
│   ├── gtimer/
│   ├── http/
│   ├── i2c/
│   ├── mqtt/
│   ├── multimedia/
│   ├── multithreading/
│   ├── neural-network/
│   ├── ntp/
│   ├── ota/
│   ├── poc/
│   ├── powermode/
│   ├── pwm/
│   ├── qr-code-scanner/
│   ├── rtc/
│   ├── spi/
│   ├── usb/
│   ├── watchdog/
│   ├── wifi/
│   └── ws2812b/
├── 03-api/                      # API 文檔
│   ├── analog/
│   ├── ble/
│   ├── filesystem/
│   ├── flashmemory/
│   ├── gpio/
│   ├── gtimer/
│   ├── http/
│   ├── multimedia/
│   ├── multithreading/
│   ├── neuralnetwork/
│   ├── ntpclient/
│   ├── ota/
│   ├── powermode/
│   ├── rtc/
│   ├── spi/
│   ├── usb/
│   ├── watchdog/
│   ├── wifi/
│   ├── wire/
│   └── ws2812b/
└── 04-other-guides/             # 其他指南
    └── ai-related/
```

## 快速導航

### 入門指南 (01-getting-started)
- [Getting Started](01-getting-started/getting-started.md) - 環境設定、開發板介紹、第一個範例

### 範例指南 (02-examples)

#### WiFi 範例
- Connect to WiFi - 連接 WiFi（支援 OPEN/WPA/WEP/WPA2-EAP）
- Scan Networks - 掃描可用網路
- Create WiFi AP - 建立 WiFi 熱點
- Simple TCP Server - 簡易 TCP 伺服器
- Concurrent Mode - AP + Station 並行模式

#### BLE 範例
- BLE Battery Service/Client - 電池服務
- BLE Beacon - iBeacon/AltBeacon
- BLE Scan - 掃描 BLE 設備
- BLE UART Service - UART 服務
- HID Keyboard/Mouse/Gamepad - 人機介面裝置
- WiFi Config Service - WiFi 配置服務

#### 多媒體範例
- RTSP Streaming - 即時串流
- MP4 Recording - MP4 錄製
- Motion Detection - 移動偵測

#### 類神經網路範例
- Object Detection - 物件偵測（支援 80 種物件）
- Face Recognition - 臉部辨識
- Face Detection - 臉部偵測
- Image Classification - 影像分類
- Audio Classification - 音訊分類

#### GPIO 範例
- Interrupt Control LED - 中斷控制 LED
- DHT Sensor - 溫濕度感測器

#### 檔案系統範例
- SD Card Read/Write - SD 卡讀寫
- File Operations - 檔案操作

#### OTA 範例
- Over-the-Air Firmware Update - 無線韌體更新

### API 文檔 (03-api)

#### WiFi API
- `WiFi.begin()` - 連接 WiFi
- `WiFi.scanNetworks()` - 掃描網路
- `WiFi.localIP()` - 取得 IP 位址
- `WiFi.apbegin()` - 建立 AP 模式

#### BLE API
- `BLEDevice.init()` - 初始化 BLE
- `BLE.configAdvert()` - 配置廣播
- `BLE.configServer()` - 配置服務

#### 多媒體 API
- `VideoSetting` - 影像設定
- `CameraSetting` - 相機設定（亮度、對比、曝光等）
- `RTSP` - RTSP 串流

#### 類神經網路 API
- `NNObjectDetection` - 物件偵測
- `ObjectDetectionResult` - 偵測結果

#### 電源管理 API
- `PMClass.begin()` - 設定電源模式
- `PMClass.start()` - 啟動電源模式

## 硬體規格

### 晶片規格
| 項目 | 規格 |
|------|------|
| 晶片 | Realtek RTL8735B |
| CPU | ARM Cortex-M33 + DSP + NPU，500 MHz |
| Flash | 16 MB |
| DDR | 128 MB |

### 支援的攝影機感測器
F37、F53、GC2053、GC4653、GC5035、IMX307、IMX327、IMX662、OV9734、PS5268、SC2336

## 相關資源

- [Ameba Arduino SDK](https://www.amebaiot.com/en/ameba-arduino-summary/)
- [GitHub](https://github.com/Ameba-AIoT/ameba-arduino-pro2)
- [論壇](https://forum.amebaiot.com/)
- [FAQ](https://forum.amebaiot.com/t/welcome-to-ameba-faq/1748)