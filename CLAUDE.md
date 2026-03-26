# AMB82 Agentic Coding Project

## 開發規則

### Firmware 必備功能
所有 firmware build (FW2) 都**必須**包含以下功能：
1. **OTA Boot Target** — 啟動時呼叫 `ota_boot_target_fw1()`，確保 reboot 回 FW1
2. **USB Patch** — `dwc_otg_enable_global_interrupts` weak symbol override（解決 GAHBCFG bit 0 問題）

> FW2 不再包含 OTA Server，OTA 由 FW1 (OTA Manager) 處理。

### OTA 架構（v1.1.0）
- **ESP32-S3 OTA Controller** (192.168.3.32) — 控制 AMB82 的 OTA/Reset GPIO
- **AMB82 FW1** (0x060000) — OTA Manager，讀 GPIO 決定 OTA 或跳轉 FW2
- **AMB82 FW2** (0x520000) — 主應用 firmware，透過 OTA 更新
- 詳細文件：`ota_readme.md`

### OTA 開發流程
```bash
# Build
cmake --build . --target flash
# 上傳用的 binary 是 firmware_ntz.bin（不是 flash_ntz.bin）

# 一鍵 WiFi OTA 燒錄
./flash_ota.sh firmware_ntz.bin

# 或手動操作：
# 1. 切換到 OTA 模式
curl -X POST http://192.168.3.32/ota
# 2. 等待 ~5 秒後上傳 firmware
curl -X POST --data-binary @firmware_ntz.bin http://192.168.3.82:8080/ota
# 3. 切回正常模式
curl -X POST http://192.168.3.32/normal

# 查看 ESP32 狀態
curl http://192.168.3.32/status
# 純 Reset（不進 OTA）
curl -X POST http://192.168.3.32/reset
```

### 硬體限制
- AMB82-MINI 的 **UART 線和 OTG 線可以同時接到 Mac**
- UART 用於 serial console 監看開機 log 和 debug
- OTG 用於 USB 裝置功能（如 UVC）
- WiFi OTA 用於更新 firmware，不需拔線

### Build 注意事項
- 必須使用 Arduino toolchain：`PATH="/Users/jimmy/Library/Arduino15/packages/realtek/tools/ameba_pro2_toolchain/1.0.1-p1/bin:$PATH"`
- UVC build 需要 `-DEXAMPLE=media_uvcd -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake`
- Sensor 型號：**F37**（`#define USE_SENSOR SENSOR_F37` in sensor.h）
- WiFi SSID: `JimmyAXPro`, Password: `23640966`

### 共用檔案
- `component/example/media_uvcd/usb_patch.c` — USB override（dwc_otg weak symbol）
- `ota_boot_target.h` — FW2 啟動時呼叫 `ota_boot_target_fw1()`，複製到 FW2 專案 src 目錄
- 每個 example 的 cmake 都要加入 `usb_patch.c`
- 每個 example 的 main 最前面要呼叫 `ota_boot_target_fw1()`
