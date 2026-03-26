# UVC 下次 Session 進攻計畫

## 目標

讓 `ep_enable` 的原版 state check 在 `fun_set_alt` 時通過，EP3 被正確 enable，frame 送達 macOS。

## 已知條件

```
ep_enable 內部邏輯：
  r3 = 某個 global struct 指標（從 literal pool 載入）
  if (r3[0x24] == 0) → "bogus device state" 失敗
  if (r3[0x14] == 0) → "bogus device state" 失敗
  else → 呼叫 dwc_otg_pcd_ep_enable → 成功

fun_set_alt 流程：
  1. change_parm_cb     → 我們可控
  2. usb_ep_disable
  3. usb_ep_enable → ep_enable → 失敗（struct[0x24]=0）
  4. alloc_iso_request
  5. iso_ep_start       → Bus Fault（DMA 問題）
  6. return

已知：
- ep_enable 在 linked binary 的位址：0x701c3300
- literal pool 在 ep_enable + 0xe4 = 0x701c33e4
- 反組譯在 /tmp/libusbd_disasm.txt
- linked binary: build_uvc_dump/application/application.ntz.axf
- nm.map: build_uvc_dump/application/application.ntz.nm.map
```

---

## Step 1：找出 struct[0x24] 的身份

### 1.1 讀取 literal pool 的值

**做法：**
```bash
# 從 axf 讀取 0x701c33e4 位址的 4 bytes（little-endian pointer）
arm-none-eabi-objdump -s --start-address=0x701c33e4 --stop-address=0x701c33e8 application.ntz.axf
```
這會給我們 struct 的記憶體位址 X。

**驗證：**
- 應該得到一個 0x70xxxxxx 或 0x20xxxxxx 的地址

### 1.2 從 .nm.map 找 symbol name

**做法：**
```bash
# 在 nm.map 搜尋地址 X
grep "X" application.ntz.nm.map
```

**驗證：**
- 應該找到一個 global variable symbol（例如 `usb_gadget`, `pcd_struct`, `dwc_otg_device` 等）

### 1.3 從 header 找 struct 定義

**做法：**
- 用 symbol name 在 SDK 搜尋 struct 定義
- 確認 offset 0x14 和 0x24 分別是什麼 field
- 例如如果是 `usb_gadget_driver`，offset 0x24 可能是 `driver` pointer

**驗證：**
- 能指出 struct[0x14] 和 struct[0x24] 的 field name 和預期值

### 1.4 Runtime 確認值

**做法：**
在 `usb_patch.c` 的 `dwc_otg_enable_global_interrupts` override（每次 USB init 都會被呼叫）中，加印 struct 的值：
```c
// 已知 struct 地址 X
volatile uint32_t *s = (volatile uint32_t *)X;
printf("[STRUCT] [0x14]=0x%08X [0x24]=0x%08X\n",
       *(volatile uint8_t *)((uint8_t*)s + 0x14),
       s[0x24/4]);
```

同時在 `example_uvc_cam.c` 的 format change callback 中也印一次，確認 fun_set_alt 時的值。

**驗證：**
- 初始化時：struct[0x24] 應該是 0（對應 ep_enable 失敗）
- fun_set_alt 時：確認 struct[0x24] 是否仍是 0，以及其他 field 的值

### Step 1 完成標準
- 知道 struct 的 symbol name
- 知道 struct[0x14] 和 struct[0x24] 的 field name
- 知道它們在 init 和 set_alt 時的實際值
- 知道它們的預期值（讓 ep_enable 通過需要什麼）

---

## Step 2：修改 struct 讓 ep_enable 通過

### 2.1 方案選擇（基於 Step 1 結果）

#### 2.1a 如果 struct[0x24] 是 driver pointer
**做法：**
- struct[0x24] 可能在 SET_CONFIGURATION 時被設定
- macOS 有送 SET_CONFIGURATION，但可能 Realtek driver 沒正確處理
- 在 format change callback 手動寫入 struct[0x24] = 任何非零值（例如 struct 自己的地址）

#### 2.1b 如果 struct[0x14] 是 USB device state enum
**做法：**
- 常見值：USB_STATE_CONFIGURED = 某個 enum 值（通常 3 或 4）
- 在 format change callback 手動寫入正確的 state 值

#### 2.1c 如果兩個 field 都依賴其他初始化
**做法：**
- 追蹤是誰寫這些 field（搜尋 symbol 的 reference）
- 找出初始化順序問題，在正確時機觸發

### 2.2 實作

**做法：**
在 `example_uvc_cam.c` 的 format change handler（`uvcd_change_format_resolution` callback 之後的主迴圈）中：
```c
// 在 rtw_down_sema 返回後（format change 觸發）
volatile uint8_t *state = (volatile uint8_t *)(STRUCT_ADDR + 0x14);
volatile uint32_t *driver = (volatile uint32_t *)(STRUCT_ADDR + 0x24);
if (*driver == 0) {
    *driver = STRUCT_ADDR;  // 設為非零
    printf("[FIX] Set struct[0x24] = 0x%08X\n", *driver);
}
if (*state == 0) {
    *state = CONFIGURED_VALUE;
    printf("[FIX] Set struct[0x14] = %d\n", *state);
}
```

**注意：** format change callback 是在 fun_set_alt **裡面**被呼叫的（step 1），而 ep_enable 在 step 3。所以我們設的值會在 ep_enable 之前生效。

但要確認：callback 的執行是同步的嗎？從反組譯看，`fun_set_alt` offset 0x38 `blx r3` 呼叫 callback，callback 執行 `rtw_up_sema`，然後 callback 返回，fun_set_alt 繼續。

問題：`rtw_up_sema` 喚醒的是 `uvc_cam_init` 裡的 `rtw_down_sema` 主迴圈。主迴圈在另一個 task 裡。它不會在 callback return 之前執行（除非 priority 更高）。

**更好的做法：** 直接在 callback function 本身修改 struct：

```c
void uvcd_change_format_resolution(void *ctx)
{
    // 在 sema up 之前修改 struct
    volatile uint32_t *driver = (volatile uint32_t *)(STRUCT_ADDR + 0x24);
    if (*driver == 0) {
        *driver = (uint32_t)STRUCT_ADDR;
    }
    volatile uint8_t *state = (volatile uint8_t *)(STRUCT_ADDR + 0x14);
    if (*state == 0) {
        *state = CONFIGURED_VALUE;
    }
    rtw_up_sema_from_isr(&uvc_format_ptr->uvcd_change_sema);
}
```

這樣在 callback 返回後，fun_set_alt 繼續到 step 3 `usb_ep_enable` → `ep_enable` 時，struct 已經被修改了。

### 2.3 驗證

**測試 A：不搭配任何 binary patch**
- Build → OTA → 觸發 streaming
- 觀察 serial log：
  - `[FIX]` log 有印出（struct 被修改）
  - `bogus device state` 是否消失
  - EP3 DIEPCTL3 bit 31 是否為 1
- 預期結果：ep_enable 通過，但 iso_ep_start 可能仍 Bus Fault

**測試 B：搭配 NOP iso_ep_start binary patch**
- 同上但 patch firmware binary 的 iso_ep_start
- 預期結果：ep_enable 通過 + 不 crash

### Step 2 完成標準
- Serial log 確認 struct 值被成功修改
- `bogus device state` 不再出現
- EP3 DIEPCTL3 在 set_alt 後 bit 31 = 1（EPEna）

---

## Step 3：完整 streaming 測試

### 3.1 測試 SDK queue API 流程

**前提：** Step 2 完成，EP3 已 enable

**做法：**
使用現有的 MMF2 pipeline（array → SISO → uvcd），不需要手動 DMA。
`uvcd_handle` 呼叫：
```
out_stream_queue → fill payload → put_in_stream_queue → wait_frame_down
```

**驗證：**
```
[UVCD] frame#0
[UVCD] frame#1
[UVCD] frame#2
...
```
如果 `wait_frame_down` 不再卡住，代表 DMA transfer 正常完成。

### 3.2 測試 macOS 收到 frame

**做法：**
```bash
ffmpeg -f avfoundation -framerate 10 -video_size 1920x1080 -i "0" -frames:v 5 -y /tmp/uvc_test.mp4
```

**驗證 A：** ffmpeg 正常結束，`/tmp/uvc_test.mp4` > 0 bytes
**驗證 B：** `ffprobe /tmp/uvc_test.mp4` 顯示 video stream
**驗證 C：** Photo Booth 顯示綠色畫面

### 3.3 持續 streaming 穩定性

**做法：**
```bash
ffmpeg -f avfoundation -framerate 10 -i "0" -t 60 -y /tmp/uvc_60s.mp4
```

**驗證：**
- 60 秒內不 crash
- Serial log 持續有 frame 輸出
- Video 可播放

### 3.4 如果 wait_frame_down 仍然卡住

**備案 A：手動 DMA**
- 在 uvcd_handle 中不用 SDK queue API
- 每個 frame 手動：
  1. 設 DIEPTSIZ3 = packet count + size
  2. 設 DIEPDMA3 = data address
  3. 設 DIEPCTL3 EPEna + CNAK
  4. 等 DIEPINT3 XFRC

**備案 B：確認 macOS IN token**
- 用 `log stream --predicate 'subsystem == "com.apple.usb"'` 看 macOS USB log
- 確認 macOS 是否在 schedule IN token 到 EP3

### Step 3 完成標準
- ffmpeg 成功擷取 video ≥ 1 frame
- Photo Booth 看到綠色畫面
- 連續 streaming 60 秒不 crash

---

## 時間估計

| Step | 任務 | 預估 |
|------|------|------|
| 1.1-1.3 | 找 struct symbol | 15 分鐘 |
| 1.4 | Runtime 確認 | 15 分鐘（build + OTA + test）|
| 2.1-2.2 | 修改 struct | 15 分鐘 |
| 2.3 | 驗證 ep_enable | 15 分鐘（build + OTA + test）|
| 3.1 | SDK queue API 測試 | 15 分鐘 |
| 3.2 | ffmpeg 測試 | 10 分鐘 |
| 3.3 | 穩定性測試 | 10 分鐘 |
| **Total** | | **~1.5 小時**（順利的話）|

## 失敗時轉進

如果 Step 2 無法讓 ep_enable 通過（struct 修改無效或有其他 check）：
→ 轉到 Module A 方案 C（binary patch `fun_set_alt` 跳過 `usb_ep_enable` 呼叫，改在 callback 中手動設定 EP3 register）

如果 Step 3 的 wait_frame_down 仍卡住（EP3 enable 但 DMA 不動）：
→ 轉到手動 DMA 方案（繞過 SDK queue API，直接驅動 DWC2 register）

如果 macOS 收到 USB data 但 UVC 解碼失敗（ffmpeg hang）：
→ 檢查 UVC payload header 格式，可能需要手動加 2-byte UVC header

如果以上全部失敗：
→ 轉到 WiFi RTSP streaming 方案（AMB82 SDK 原生支援，不需要 USB）
