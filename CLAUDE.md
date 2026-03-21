# AMB82 Agentic Coding Project

## 開發規則

### Firmware 必備功能
所有 firmware build 都**必須**包含以下功能：
1. **OTA Server** — WiFi HTTP OTA 更新（port 8080），呼叫 `ota_server_start()`
2. **Software Reset** — 透過 `curl -X POST http://<IP>:8080/reboot` 或 AT 命令可遠端重啟
3. **USB Patch** — `dwc_otg_enable_global_interrupts` weak symbol override（解決 GAHBCFG bit 0 問題）

### OTA 開發流程
```bash
# Build
cmake --build . --target flash

# WiFi OTA 上傳（不需按按鈕）
curl -X POST --data-binary @firmware.bin http://192.168.3.112:8080/ota

# 遠端重啟
curl -X POST http://192.168.3.112:8080/reboot

# 查看狀態
curl http://192.168.3.112:8080/
```

### 硬體限制
- AMB82-MINI 的 **UART 線和 OTG 線不能同時接到 Mac**（會導致 OTG enumerate 失敗）
- 開發時只接 OTG 線，用 WiFi OTA 更新
- 只有第一次燒錄需要 UART

### Build 注意事項
- 必須使用 Arduino toolchain：`PATH="/Users/jimmy/Library/Arduino15/packages/realtek/tools/ameba_pro2_toolchain/1.0.1-p1/bin:$PATH"`
- UVC build 需要 `-DEXAMPLE=media_uvcd -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake`
- Sensor 型號：**F37**（`#define USE_SENSOR SENSOR_F37` in sensor.h）
- WiFi SSID: `JimmyAXPro`, Password: `23640966`

### 共用 Patch 檔案
- `component/example/media_uvcd/usb_patch.c` — USB override + OTA start
- 每個 example 的 cmake 都要加入 `usb_patch.c`
- 每個 example 的 main 都要呼叫 `usb_patch_start_ota()`
