# AMB82-MINI WiFi OTA System

**OTA Architecture Version: 1.1.0**

完全不碰板子的遠端 firmware 更新系統。透過 ESP32-S3 控制 AMB82-MINI 的 OTA 模式切換與硬體 Reset，實現 WiFi 無線燒錄。

查詢版本：`curl http://192.168.3.32/status` → `ota_arch_ver` 欄位

## 系統架構

```
┌──────────────┐    WiFi HTTP     ┌──────────────────┐
│              │  ← ← ← ← ← ←   │                  │
│   Mac / PC   │   curl 指令      │  ESP32-S3 OTA    │
│              │  → → → → → → →  │  Controller      │
│  (開發端)     │   192.168.3.32   │  (Hiwonder       │
│              │                  │   S3-Cam V1.0)   │
└──────┬───────┘                  └────┬────┬────────┘
       │                               │    │
       │ WiFi HTTP                GPIO48│    │GPIO47
       │ 192.168.3.82:8080        (SDA)│    │(SCL)
       │                               │    │
┌──────▼───────────────────────────────▼────▼────────┐
│                  AMB82-MINI                         │
│                                                     │
│  ┌─────────────────┐    ┌─────────────────────┐    │
│  │ FW1 (0x060000)  │    │ FW2 (0x520000)      │    │
│  │ OTA Manager     │───▶│ Main Firmware        │    │
│  │                 │    │ (使用者應用程式)       │    │
│  │ - GPIO 讀取     │    │                       │    │
│  │ - WiFi HTTP OTA │    │ FreeRTOS / Arduino    │    │
│  │ - Flash 寫入    │    │ 完全不含 OTA 程式碼    │    │
│  │ - CRC32 驗證    │    │                       │    │
│  └─────────────────┘    └─────────────────────┘    │
│                                                     │
│  PF1 (pin 10) ← OTA_PIN    CHIP_EN (pin 18) ← RST │
└─────────────────────────────────────────────────────┘
```

## 三個角色

| 角色 | 硬體 | 職責 |
|------|------|------|
| **ESP32 OTA Controller** | Hiwonder S3-Cam V1.0 | WiFi HTTP API，控制 AMB82 的 OTA/Reset GPIO |
| **OTA Manager (FW1)** | AMB82-MINI flash 0x060000 | 開機守門員：讀 GPIO 決定 OTA 或跳轉 FW2，永不被覆寫 |
| **Main Firmware (FW2)** | AMB82-MINI flash 0x520000 | 使用者應用程式，透過 OTA 更新，不含任何 OTA 程式碼 |

## 硬體接線

### 接線表

| S3-Cam Connector | → | AMB82-MINI | 用途 |
|---|---|---|---|
| **5V** | → | **V_USB** (pin 17) | ESP32 供電 |
| **GND** | → | **GND** (pin 19) | 共地 |
| **SDA** (GPIO48) | → | **PF1** (pin 10) | OTA_PIN：HIGH=OTA, LOW=正常 |
| **SCL** (GPIO47) | → | **CHIP_EN** (pin 18) | Reset：拉 LOW 觸發硬體 reset |

共 4 條線。ESP32 由 AMB82 的 V_USB 供電，不需要額外電源。

### 重要：Hiwonder S3-Cam Pin Mapping

Hiwonder S3-Cam V1.0 的 pinout 圖與實際 GPIO 編號不一致。
根據原理圖 (SCH_S3-Cam V1.0.pdf)，connector 實際對應：

| Connector 標示 | 實際 ESP32 GPIO |
|---|---|
| SCL | GPIO47 |
| SDA | GPIO48 |
| TX | GPIO43 |
| RX | GPIO44 |

**左側排針 GPIO12-15 全部內部連接 camera，不可外接。**

### Flash 分區配置

```
16MB NOR Flash
┌──────────────────────────────────────────────┐
│ 位址        大小      用途                     │
├──────────────────────────────────────────────┤
│ 0x000000    36KB     系統保留 (partition table) │
│ 0x009000    156KB    BL_PRI (Bootloader)       │
│ 0x030000    156KB    BL_SEC (Bootloader 2)     │
│ 0x060000    4MB      FW1 = OTA Manager         │
│ 0x460000    768KB    ISP_IQ (相機校正資料)      │
│ 0x520000    4MB      FW2 = Main Firmware (OTA)  │
│ 0x920000    ~5.9MB   NN_MDL (神經網路模型)      │
│ 0xFC0000    4KB      MP (製造資料)              │
└──────────────────────────────────────────────┘
```

## 開機流程

### 正常開機（OTA_PIN = LOW）

```
上電 → Bootloader → FW1 (OTA Manager)
  → 讀 PF1 = LOW
  → 切換 OTA signature 到 FW2
  → Reboot
  → Bootloader → FW2 (Main Firmware)
  → FW2 啟動，切回 FW1 signature
  → Main Firmware 執行
```

延遲約 3-4 秒（多一次 reboot）。

### OTA 更新

```
Mac 端執行：
  curl -X POST http://192.168.3.32/ota        ← ESP32 拉 OTA_PIN HIGH + reset AMB82

AMB82 重啟：
  → Bootloader → FW1 (OTA Manager)
  → 讀 PF1 = HIGH → 進入 OTA 模式
  → 連接 WiFi → 啟動 HTTP Server (port 8080)
  → 等待 firmware 上傳

Mac 端執行：
  curl -X POST --data-binary @firmware.bin http://192.168.3.82:8080/ota
  → OTA Manager 接收 → 寫入 FW2 → CRC32 驗證

Mac 端執行：
  curl -X POST http://192.168.3.32/normal      ← ESP32 拉 OTA_PIN LOW + reset AMB82

AMB82 重啟：
  → FW1 → 讀 PF1 = LOW → 切到 FW2 → reboot → 新 firmware 執行
```

### 異常恢復

| 情境 | 處理 |
|------|------|
| Main Firmware 當機 | `curl -X POST http://192.168.3.32/reset` |
| OTA 傳輸中斷 | FW1 完好，重新上傳即可 |
| FW2 crash loop | ESP32 拉回 OTA 模式：`curl -X POST http://192.168.3.32/ota` |
| ESP32 沒回應 | 手動按 AMB82 RESET 按鈕 |

## 使用手冊

### 前置條件

- AMB82-MINI 已燒入 OTA Manager (FW1)
- ESP32 S3-Cam 已燒入 OTA Controller
- 4 條線已接好
- Mac 和兩塊板子在同一個 WiFi 網路
- FW2 已加入 `ota_boot_target_fw1()`（見下方「編譯 FreeRTOS Firmware」）

### 網路資訊

| 裝置 | IP | Port | 用途 |
|------|-----|------|------|
| ESP32 OTA Controller | 192.168.3.32 (Static) | 80 | 控制 API |
| AMB82 OTA Manager | 192.168.3.82 (Static) | 8080 | Firmware 上傳 |

WiFi: SSID `JimmyAXPro` / Password `23640966`

### 一鍵燒錄

```bash
#!/bin/bash
# flash_ota.sh — WiFi OTA 燒錄
ESP32_IP="192.168.3.32"
AMB82_IP="192.168.3.82"
FIRMWARE="$1"

if [ -z "$FIRMWARE" ]; then
    echo "Usage: ./flash_ota.sh <firmware.bin>"
    exit 1
fi

echo "[1/4] 切換 AMB82 到 OTA 模式..."
curl -s -X POST http://$ESP32_IP/ota
sleep 5

echo "[2/4] 等待 OTA Manager..."
for i in $(seq 1 15); do
    if curl -s --max-time 1 http://$AMB82_IP:8080/ > /dev/null 2>&1; then
        echo " Ready!"
        break
    fi
    sleep 1
done

echo "[3/4] 上傳 firmware ($(du -h $FIRMWARE | cut -f1))..."
curl -X POST --data-binary @$FIRMWARE http://$AMB82_IP:8080/ota
echo ""

echo "[4/4] 切回正常模式..."
sleep 1
curl -s -X POST http://$ESP32_IP/normal
echo ""
echo "Done! AMB82 正在啟動新 firmware..."
sleep 8
ping -c 3 $AMB82_IP
```

### 手動操作

```bash
# 查看 ESP32 狀態
curl http://192.168.3.32/status

# 查看 AMB82 OTA 狀態（OTA 模式下）
curl http://192.168.3.82:8080/

# 切換到 OTA 模式
curl -X POST http://192.168.3.32/ota

# 上傳 firmware
curl -X POST --data-binary @firmware.bin http://192.168.3.82:8080/ota

# 驗證 FW2 CRC
curl http://192.168.3.82:8080/verify

# 切回正常模式
curl -X POST http://192.168.3.32/normal

# 純 Reset（不進 OTA）
curl -X POST http://192.168.3.32/reset
```

### 編譯 FreeRTOS Firmware (FW2)

**重要：FW2 必須在啟動時呼叫 `ota_boot_target_fw1()`**，確保下次 reboot 回到 FW1。

1. 把 `ota_boot_target.h` 複製（或 symlink）到你的 FW2 專案 src 目錄
2. 在 `app_example()` 最前面加入：

```c
#include "ota_boot_target.h"

void app_example(void)
{
    ota_boot_target_fw1();  // 確保下次 reboot → FW1
    // ... 你的應用程式 ...
}
```

> Bootloader 根據 OTA signature 決定載入 FW1 或 FW2。
> `ota_boot_target_fw1()` 會破壞 FW2 的 signature，讓 bootloader fallback 到 FW1。
> FW1 在跳 FW2 前會自動恢復 FW2 signature。

編譯：

```bash
cd freertos_your_project
./build.sh
```

上傳用的 binary 是 `firmware_ntz.bin`（純 firmware，不是 flash_ntz.bin）。

### 編譯 ESP32 OTA Controller

```bash
# 編譯
arduino-cli compile -b esp32:esp32:esp32s3 esp32_ota_controller/

# USB 上傳（需擴展板）
arduino-cli upload -b esp32:esp32:esp32s3 -p /dev/cu.wchusbserial10 esp32_ota_controller/

# WiFi OTA 上傳（不需擴展板）
arduino-cli upload -b esp32:esp32:esp32s3 --port 192.168.3.32 esp32_ota_controller/
```

### USB 救磚（緊急恢復）

當 FW2 crash loop 導致板子無回應時：

1. **拔掉 SCL → CHIP_EN 線**（避免干擾 upload mode）
2. AMB82 進 upload mode：按住 UART_DOWNLOAD → 按 RESET → 放 UART_DOWNLOAD
3. 燒錄 OTA Manager：
   ```bash
   cd freertos_ota_manager
   ./upload.sh /dev/cu.wchusbserial1130
   ```
4. 接回 SCL → CHIP_EN 線

## ESP32 HTTP API 參考

### GET /status

```json
{
  "ota_arch_ver": "1.1.0",
  "esp32": "online",
  "amb82_mode": "normal",
  "ota_pin": 0,
  "uptime": 52,
  "ip": "192.168.3.32",
  "rssi": -30,
  "heap": 254976
}
```

### POST /ota
拉 OTA_PIN HIGH → pulse CHIP_EN reset。AMB82 重啟進 OTA 模式。

### POST /normal
拉 OTA_PIN LOW → pulse CHIP_EN reset。AMB82 重啟進正常模式。

### POST /reset
維持 OTA_PIN 不變 → pulse CHIP_EN reset。純重啟。

## AMB82 OTA Manager HTTP API 參考（port 8080）

### GET /
```json
{"mode":"ota","busy":0,"fw2_size":2777088,"fw2_crc":"0x22515884","heap":78207200}
```

### POST /ota
接收 firmware binary，streaming 寫入 FW2 (0x520000)，CRC32 驗證。
```json
{"status":"ok","size":2777088,"crc":"0x22515884"}
```

限制：100KB ~ 4MB。

### GET /verify
```json
{"fw2_crc":"0x22515884","fw2_size":2777088}
```

## GPIO 控制邏輯

| 動作 | OTA_PIN (GPIO48/SDA) | RESET_PIN (GPIO47/SCL) | 結果 |
|------|---------------------|----------------------|------|
| 正常待機 | LOW | HIGH-Z (INPUT) | AMB82 正常運行 |
| 觸發 OTA | → HIGH | LOW pulse 100ms → INPUT | AMB82 重啟進 OTA 模式 |
| 觸發 Normal | → LOW | LOW pulse 100ms → INPUT | AMB82 重啟進正常模式 |
| 純 Reset | 維持 LOW | LOW pulse 100ms → INPUT | AMB82 重啟 |

## 效能數據

| 指標 | 數值 |
|------|------|
| OTA 上傳速度 | ~200 KB/s |
| 2.6MB firmware 上傳時間 | ~13 秒 |
| FW1 → FW2 切換時間 | ~4 秒 |
| OTA 全流程（上傳+切換） | ~20 秒 |
| USB Serial 上傳速度（比較） | ~130 KB/s |

## 專案結構

```
amb82_OTA/
├── ota_readme.md                  ← 本文件（使用手冊）
├── ota_boot_target.h              ← FW2 用的 helper（複製到 FW2 專案）
├── OTA_Proposal.md                ← 原始設計 proposal
├── wifi.md                        ← WiFi 設定
├── SCH_S3-Cam V1.0.pdf            ← ESP32 S3-Cam 原理圖
│
├── esp32_ota_controller/          ← ESP32 OTA Controller
│   ├── esp32_ota_controller.ino   ← Arduino sketch
│   └── README.md                  ← ESP32 文檔
│
├── freertos_ota_manager/          ← AMB82 OTA Manager (FW1)
│   ├── src/
│   │   ├── app_example.c          ← OTA Manager 主程式
│   │   └── ota_manager.cmake
│   ├── build.sh
│   └── upload.sh
│
├── test_wifi_freertos/            ← FreeRTOS WiFi 測試 (FW2 範例)
│   ├── src/
│   │   ├── app_example.c
│   │   └── wifi_test.cmake
│   └── build.sh
│
├── test_wifi_arduino/             ← Arduino WiFi 測試 (FW2 範例)
│   └── test_wifi_arduino.ino
│
└── esp32_pin_finder/              ← GPIO Pin 偵測工具
    └── esp32_pin_finder.ino
```

## 已知限制

1. **Arduino FW2 相容性** — Arduino SDK 的 VOE 預分配在 FW2 位置會 crash（NN_SIZE=36MB 導致 DDR 不足）。FreeRTOS FW2 正常運作。
2. **燒錄需拔線** — USB 燒錄 AMB82 時需暫時拔掉 SCL → CHIP_EN 線。

## 未來擴充

1. **NN Model OTA via SD Card** — OTA Manager 加 `POST /model` endpoint，將 model 寫入 SD Card，FW2 從 SD Card 載入。適合頻繁換 model 的實驗場景。
2. **ESP32 Health Check** — ESP32 在切換 FW2 後自動 ping，無回應則拉回 OTA 模式。
3. **OTA 速度進一步優化** — 調整 lwIP TCP buffer size 提升 WiFi 傳輸吞吐量。
