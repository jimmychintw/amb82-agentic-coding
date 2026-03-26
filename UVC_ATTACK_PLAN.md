# AMB82 UVC macOS 攻克計畫

**目標：讓 AMB82-MINI 在 macOS 上作為 USB UVC Camera 串流 MJPEG 影像**

**現況：USB enumerate ✅ → streaming negotiation ✅ → EP3 isochronous transfer ❌**

---

## 問題定位

macOS host 成功完成 UVC descriptor negotiation（PROBE → COMMIT → SET_INTERFACE alt=1），
但 EP3 IN isochronous endpoint 從未被 Realtek USB driver 正確 enable，
導致 macOS 不發 IN token，frame 永遠到不了 host。

根因：`libusbd.a`（閉源）的 `ep_enable()` 函式在 device state 檢查時失敗
（`"bogus device state"`），拒絕 enable EP3。

---

## 攻克模組拆分

```
Module A: 讓 EP3 被正確 enable
Module B: 確認 DMA transfer 正常運作
Module C: 確認 macOS 收到並解碼 MJPEG frame
Module D: 從 test pattern 切換到真實 camera sensor
```

每個 Module 都有：方案、備案、驗證方式。

---

## Module A：讓 EP3 被正確 enable

**這是最關鍵的一步，解決了整個問題就通了。**

### 方案 A1：Binary patch `libusbd.a`（推薦，最精準）

**做法：**
1. `objdump -d libusbd.a` 反組譯 `ep_enable` 函式
2. 找到 "bogus device state" 的條件分支（比較 device state → branch if not configured）
3. NOP 掉那個條件跳轉，讓 ep_enable 不管 state 都繼續執行
4. 重新打包 `libusbd.a`

**驗證：**
- Serial log 不再出現 `"bogus device state"`
- `DIEPCTL3` 在 `set_alt alt=1` 後 bit 31 (EPEna) = 1

**風險：** 移除 state check 可能在某些情境下造成問題（例如 USB reset 時 enable EP）
**緩解：** 可以只 patch EP3 的分支，保留其他 EP 的 state check

### 方案 A2：Override `ep_enable` weak symbol（已嘗試，需改進）

**做法：**
1. 先用 `objdump` 確認 `ep_enable` 的完整參數和內部邏輯
2. 用 function pointer 保存原版 `ep_enable` 的地址（從 .map 取得 `0x701c3300`）
3. Override 裡：對非 EP3 呼叫用 function pointer call 原版，對 EP3 做特殊處理

**驗證：** 同 A1

**上次失敗原因：** 直接呼叫 `dwc_otg_pcd_ep_enable` 但它收到 NULL descriptor 時行為不對
**改進：** 用 function pointer `((int(*)(void*,void*))0x701c3300)` 跳回原版位址

### 方案 A3：在 format change callback 中手動 enable EP3

**做法：**
1. 修改 `example_uvc_cam.c` 的 format change 處理
2. 當偵測到 `set_alt alt=1`（uvc_status 變為 1）時，直接寫 DWC2 register enable EP3
3. 配合 `module_uvcd.c` 在 `uvcd_handle` 第一次進入時 delay 等 EP3 ready

**驗證：** 同 A1

**限制：** 手動 enable EP3 後 macOS 仍可能不發 IN token（因為 USB protocol 層面 SET_INTERFACE 的 ACK 可能有問題）

### 方案 A4：Patch `fun_set_alt` 在 `libusbd.a`

**做法：**
1. 反組譯 `fun_set_alt`（0x701c87dc），找到它呼叫 `usb_ep_enable` 的位置
2. 確認 `usb_ep_enable` 是否因為 ep_enable 失敗而 skip 了後續的 alloc_iso_request
3. 如果是，NOP 掉 error check，讓流程繼續

**驗證：** 同 A1

### 無解時轉進

如果所有 A 方案都失敗（EP3 enable 了但 macOS 仍不發 IN token）：

**轉進 A-ALT：USB 協議層抓包分析**
- 用 Wireshark + macOS USB tracing（`sudo log stream --predicate 'subsystem == "com.apple.usb"'`）
- 或用 USB 硬體分析儀抓 SET_INTERFACE 的實際 response
- 確認 device 是否回了 STALL 而不是 ACK

---

## Module B：確認 DMA transfer 正常運作

**前提：Module A 完成，EP3 已 enable**

### 方案 B1：SDK queue API（標準流程）

**做法：** 使用現有的 MMF2 pipeline（已實作完成）
- `array_module` 送 test_jpeg_data
- `SISO` link 到 `uvcd_module`
- `uvcd_handle` 呼叫 `uvc_video_out/put_stream_queue` + `usbd_wait_frame_down`

**驗證：**
- `DIEPINT3` 出現 bit 0 (XFRC) — Transfer Complete
- `wait_frame_down` 正常返回
- Serial log 顯示 frame 送出

### 方案 B2：手動 DMA（已有 prototype）

**做法：** 直接寫 DIEPTSIZ3 + DIEPDMA3 + DIEPCTL3，繞過 SDK queue API

**驗證：**
- `DIEPINT3` 出現 XFRC
- 可在 `DIEPINT3` 用 polling 或 interrupt 確認

### 無解時轉進

如果 DMA 設定正確但 XFRC 始終不出現：

**轉進 B-ALT：改用 Slave mode（非 DMA）**
- DWC2 支援 non-DMA 模式，直接寫 TX FIFO
- 效率低但可以繞過 DMA 問題
- 需要手動管理 packet fragmentation

---

## Module C：確認 macOS 收到並解碼 MJPEG frame

**前提：Module B 完成，DMA transfer 正常**

### 方案 C1：ffmpeg 擷取測試

```bash
ffmpeg -f avfoundation -framerate 10 -video_size 1920x1080 -i "0" -frames:v 5 -y /tmp/uvc_test.mp4
```

**驗證：**
- `/tmp/uvc_test.mp4` 有內容（> 0 bytes）
- `ffprobe` 顯示 video stream
- 播放看到綠色畫面

### 方案 C2：Photo Booth / QuickTime Player

**驗證：** 打開 app，選擇 "USB UVC CLASS"，看到綠色畫面

### 方案 C3：USB packet 分析

如果 ffmpeg 卡住（收不到 frame）：
- 用 `log stream --predicate 'subsystem == "com.apple.usb"'` 看 macOS USB log
- 確認 UVC payload header 格式是否正確（需要 UVC 1.0 header: 2 bytes header + JPEG data）

### 無解時轉進

如果 macOS 收到 USB data 但 UVC 解碼失敗：

**轉進 C-ALT：確認 UVC payload format**
- UVC 規格要求每個 isochronous packet 前面有 2-12 bytes 的 UVC payload header
- Realtek SDK 的 `libusbd.a` 應該會自動加，但需要確認
- 如果沒加，需要在 `uvcd_handle` 裡手動加 header

---

## Module D：從 test pattern 切換到真實 camera sensor

**前提：Module C 完成，test pattern 在 macOS 可見**

### 方案 D1：替換 array_module 為 video_module

**做法：**
1. 把 `example_uvc_cam.c` 的 `array_module` 替換為 `video_module`
2. 設定 F37 sensor 參數
3. 用 `CMD_VIDEO_SET_PARAMS` + `CMD_VIDEO_APPLY` 啟動 camera
4. SISO link: `video_module` → `uvcd_module`

**驗證：** macOS 看到真實 camera 畫面

### 方案 D2：先用 snapshot 模式

**做法：**
1. 用 `CMD_VIDEO_SNAPSHOT` 模式，sensor 只輸出 JPEG snapshot
2. 比連續 streaming 簡單，先確認 sensor → USB 通道

### 無解時轉進

**轉進 D-ALT：WiFi RTSP 串流**
- AMB82 SDK 有成熟的 RTSP streaming example
- 如果 USB UVC 的 macOS 問題最終無法解決，改用 WiFi RTSP 是可用的替代方案
- 延遲會高一些（~100-200ms vs USB ~30ms）

---

## 執行優先順序

```
[現在] Module A (EP3 enable) ← 最關鍵的阻塞點
  ↓ 成功
Module B (DMA transfer) ← 可能自動解決（SDK queue API 本來就對）
  ↓ 成功
Module C (macOS 解碼) ← 可能自動解決（SDK 有 UVC header）
  ↓ 成功
Module D (真實 sensor) ← 相對簡單的 code 替換
  ↓ 成功
🎉 AMB82 macOS UVC Camera 完成
```

## 已完成的嘗試（2026-03-25 凌晨）

### 已完成 ✅
1. 反組譯 libusbd.a — ep_enable, fun_set_alt, iso_ep_start, alloc_iso_request 完整分析
2. Binary patch ep_enable struct[0x14] bypass — 成功但 struct[0x24] 仍攔截
3. Binary patch ep_enable 完全 bypass — 破壞 USB enumeration
4. Binary patch NOP iso_ep_start — 防止 Bus Fault
5. 發現必須 patch firmware_ntz.bin（linked binary），不能 patch .a（linker 覆蓋）

### 最佳結果
- ep_enable struct[0x14] bypass + NOP iso_ep_start = **沒有 crash，stream on 成功**
- 但 EP3 仍然沒 enable（struct[0x24]=0 在 init 和 set_alt 時都是 0）

## 下次 Session 的執行步驟

### Step 1：找出 struct[0x24] 的 symbol name（30 分鐘）
```
ep_enable 的 literal pool offset 0xe4 指向一個 global struct
在 linked binary 中：ep_enable @ 0x701c3300 → literal @ 0x701c33e4
objdump --section-headers 找到 0x701c33e4 指向什麼 symbol
```
目標：找到 struct 的 symbol name 和地址，理解 struct[0x24] 是什麼

### Step 2：在 format change callback 中設定 struct[0x24]（30 分鐘）
- 如果 struct[0x24] 是某個 driver pointer，可能只需要在正確時機設定它
- 在 `uvcd_change_format_resolution` callback 中寫入正確的值
- 讓原版 ep_enable 的 state check 通過

### Step 3：搭配 NOP iso_ep_start 測試（30 分鐘）
- ep_enable 成功 + NOP iso_ep_start = 不 crash
- 然後由 uvcd_handle 的 SDK queue API 處理 frame delivery
- 觀察 EP3 register 是否被 dwc_otg_pcd_ep_enable 正確配置

### 備案：手動 DMA + NOP iso_ep_start
- 在 uvcd_handle 裡等 fun_set_alt 完成
- 手動設定 EP3 register（DIEPCTL3 + DIEPTSIZ3 + DIEPDMA3）
- 每個 frame 手動驅動 DMA transfer

---

## 風險評估

| 風險 | 機率 | 影響 | 緩解 |
|------|------|------|------|
| Binary patch 破壞其他功能 | 中 | 高 | 保留 .bak，只 patch 最小範圍 |
| EP3 enable 後 macOS 仍不發 IN token | 中 | 高 | USB 抓包分析，確認 SET_INTERFACE ACK |
| UVC payload header 缺失 | 低 | 中 | 手動加 2-byte header |
| DMA 地址對齊問題 | 低 | 中 | 用 aligned buffer |
| Realtek SDK 限制無法繞過 | 低 | 高 | 轉進 WiFi RTSP 方案 |
