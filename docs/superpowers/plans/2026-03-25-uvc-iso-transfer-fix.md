# UVC ISO Transfer Fix — 逐步攻略計畫

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** 解決 AMB82 DWC2 USB controller 在 macOS 上 ISO IN 傳輸失敗（TX FIFO → USB bus）的問題，讓 UVC webcam 功能正常運作。

**Architecture:** 採用逐步降級策略（Option D），從最低成本的暫存器修改開始，逐步嘗試更大幅度的方案。每步都有明確的 go/no-go 判斷標準，不超過 timebox。

**Tech Stack:** AMB82-Mini (ARM Cortex-A32), DWC2 OTG USB controller, FreeRTOS, Buffer DMA mode, WiFi OTA 部署

**關鍵暫存器位址：**
| Register | Address | Description |
|----------|---------|-------------|
| DCFG | 0x400C0800 | Device Configuration |
| DCTL | 0x400C0804 | Device Control |
| DSTS | 0x400C0808 | Device Status |
| DAINTMSK | 0x400C081C | Device All EP Interrupt Mask |
| DIEPCTL3 | 0x400C0960 | EP3 IN Control |
| DIEPINT3 | 0x400C0968 | EP3 IN Interrupt |
| DIEPTSIZ3 | 0x400C0970 | EP3 IN Transfer Size |
| DIEPDMA3 | 0x400C0974 | EP3 IN DMA Address |
| GINTSTS | 0x400C0014 | Global Interrupt Status |

**開發流程：** 修改 → `cmake --build . --target flash` → `./flash_ota.sh firmware_ntz.bin` → UART 觀察 log

**關鍵檔案：**
- `amb82_Info/ameba-rtos-pro2/component/media/mmfv2/module_uvcd.c` — ISO 傳輸核心邏輯
- `amb82_Info/ameba-rtos-pro2/component/example/media_uvcd/usb_patch.c` — USB weak symbol overrides
- `freertos_uvc/example_uvc_cam.c` — 應用層 MMF2 pipeline
- `freertos_uvc/example_uvc_cam.h` — UVC 配置參數

**重要注意事項：**
1. **Phase 修改是累積的** — 每個 Phase 保留前面所有 Phase 的修改（例如 Phase 3 保留 Phase 2 的 IFrmNum=1）
2. **DCache Maintenance** — ARM Cortex-A32 上 DMA buffer 必須做 cache flush，所有 DMA 傳輸前需呼叫 `DCache_Clean((uint32_t)data, size)`
3. **DCTL 寫入注意** — DCTL 暫存器有 write-only 自清除位元（bit 7/9/10），避免 read-modify-write 意外觸發

---

## Phase 1: 暫存器診斷 Dump（10 分鐘）

**目的：** 在動手修改之前，先確認 DCTL 和 DCFG 的實際值，建立 baseline。

### Task 1.1: 加入 DCTL/DCFG Diagnostic Dump

**Files:**
- Modify: `amb82_Info/ameba-rtos-pro2/component/media/mmfv2/module_uvcd.c:117-133`

**判斷標準：** 純診斷，必定成功。取得 register 值作為後續修改的依據。

- [ ] **Step 1: 在 uvcd_handle 的 "First active" 區塊加入 register dump**

在 `module_uvcd.c` 的 `if (n == 0)` 區塊（第 121 行後），加入以下 diagnostic：

```c
if (n == 0) {
    printf("[UVCD] First active, waiting for stream on...\n");
    vTaskDelay(100);

    /* === Phase 1 Diagnostic: Dump key registers before any modification === */
    volatile uint32_t *dcfg_r = (volatile uint32_t *)(0x400C0000 + 0x800);
    volatile uint32_t *dctl_r = (volatile uint32_t *)(0x400C0000 + 0x804);
    volatile uint32_t *dsts_r = (volatile uint32_t *)(0x400C0000 + 0x808);
    uint32_t dcfg_val = *dcfg_r;
    uint32_t dctl_val = *dctl_r;
    uint32_t dsts_val = *dsts_r;
    printf("[DIAG] DCFG=0x%08X DevSpd=%d DescDMA=%d EPMisCnt=%d\n",
        dcfg_val, dcfg_val & 0x3, (dcfg_val >> 23) & 1, (dcfg_val >> 18) & 0x1F);
    printf("[DIAG] DCTL=0x%08X IFrmNum=%d GNPINNakSts=%d SftDiscon=%d GMC=%d\n",
        dctl_val, (dctl_val >> 15) & 1, (dctl_val >> 2) & 1, (dctl_val >> 1) & 1,
        (dctl_val >> 13) & 3);
    printf("[DIAG] DSTS=0x%08X EnumSpd=%d SOFFN=%d\n",
        dsts_val, (dsts_val >> 1) & 0x3, (dsts_val >> 8) & 0x3FFF);

    /* Existing code continues... */
    volatile uint32_t *daintmsk_r = (volatile uint32_t *)(0x400C0000 + 0x81C);
    // ...
```

- [ ] **Step 2: Build and deploy**

```bash
cd /Users/jimmy/Projects/amb82_agentic_coding/amb82_Info/ameba-rtos-pro2
PATH="/Users/jimmy/Library/Arduino15/packages/realtek/tools/ameba_pro2_toolchain/1.0.1-p1/bin:$PATH" cmake --build build -j4 --target flash
cd /Users/jimmy/Projects/amb82_agentic_coding && ./flash_ota.sh amb82_Info/ameba-rtos-pro2/build/firmware_ntz.bin
```

- [ ] **Step 3: 開啟 macOS 相機 app，從 UART 讀取 diagnostic 輸出**

預期輸出（範例）：
```
[DIAG] DCFG=0x00000000 DevSpd=0 DescDMA=0 EPMisCnt=0
[DIAG] DCTL=0x00000000 IFrmNum=0 GNPINNakSts=0 SftDiscon=0 GMC=0
[DIAG] DSTS=0x00000006 EnumSpd=0 SOFFN=xxx
```

**記錄這些值！** 後續每個 Phase 都要比較。

---

## Phase 2: DCTL.IFrmNum = 1（30 分鐘 timebox）

**目的：** 設定 DCTL bit 15 "Ignore Frame Number"，繞過 even/odd frame parity 匹配問題。
**假說：** Frame parity 從 task context 寫入永遠來不及匹配，IFrmNum=1 可以讓 packet engine 無條件發送。

### Task 2.1: 設定 DCTL.IFrmNum = 1

**Files:**
- Modify: `amb82_Info/ameba-rtos-pro2/component/media/mmfv2/module_uvcd.c:121-133`

**Go/No-go：** 如果 UART 出現 `XFRC`（Transfer Complete），表示成功 → 繼續優化。如果仍然只有 IISOIXFR → 進入 Phase 3。

- [ ] **Step 1: 在 diagnostic dump 之後、EP3 DAINTMSK 修改之前，加入 IFrmNum 設定**

```c
    /* === Phase 2: Set DCTL.IFrmNum = 1 (Ignore Frame Number for ISO EPs) === */
    printf("[FIX] Setting DCTL.IFrmNum=1 (ignore frame number)...\n");
    uint32_t dctl_new = *dctl_r | (1u << 15);
    *dctl_r = dctl_new;
    printf("[FIX] DCTL: 0x%08X -> 0x%08X (IFrmNum=%d)\n",
        dctl_val, *dctl_r, (*dctl_r >> 15) & 1);
```

- [ ] **Step 2: 既然有 IFrmNum，移除 frame parity 設定邏輯（簡化 DIEPCTL programming）**

在 `uvcd_handle` 的 EP3 programming 區塊（約第 171-188 行），修改為：

```c
    /* 4. Program DIEPCTL: EPEna + CNAK + correct TXFNUM */
    uint32_t ctl = *ep3_ctl;
    /* Clear previous frame parity bits and TXFNUM */
    ctl &= ~((1u << 28) | (1u << 29) | (0xFu << 22));
    /* Set TXFNUM=3 */
    ctl |= (3u << 22);
    /* With IFrmNum=1, no need to set SEVNFRM/SODDFRM */
    ctl |= (1u << 31) | (1u << 26);  /* EPEna + CNAK */
    *ep3_ctl = ctl;
```

- [ ] **Step 3: Build, deploy, test**

```bash
cd /Users/jimmy/Projects/amb82_agentic_coding/amb82_Info/ameba-rtos-pro2
PATH="/Users/jimmy/Library/Arduino15/packages/realtek/tools/ameba_pro2_toolchain/1.0.1-p1/bin:$PATH" cmake --build build -j4 --target flash
cd /Users/jimmy/Projects/amb82_agentic_coding && ./flash_ota.sh amb82_Info/ameba-rtos-pro2/build/firmware_ntz.bin
```

- [ ] **Step 4: 驗證 — 打開 macOS 相機 app，觀察 UART log**

成功指標：`[UVCD#0] 🎉 XFRC at w=N!`
失敗指標：`[UVCD#0] 5s timeout, no XFRC`

---

## Phase 3: 清除 Global IN NAK + EPMisCnt 調整（30 分鐘 timebox）

**目的：** 排除 Global IN NAK 阻擋 ISO 傳輸的可能性，並增加 EP Mismatch Count 容忍度。
**前提：** Phase 2 失敗才進入此 Phase。如果 Phase 2 成功，跳到 Phase 7。

### Task 3.1: 清除 Global IN NAK

**Files:**
- Modify: `amb82_Info/ameba-rtos-pro2/component/media/mmfv2/module_uvcd.c:121-133`

- [ ] **Step 1: 在 IFrmNum 設定之後加入 NAK 清除**

```c
    /* === Phase 3a: Clear Global Non-Periodic IN NAK === */
    /* NOTE: DCTL has write-only self-clearing bits (7,9,10).
     * Use direct write instead of read-modify-write to avoid
     * accidentally triggering SGNPINNAK/SGOUTNAK/CGOUTNAK. */
    if ((*dctl_r >> 2) & 1) {
        printf("[FIX] GNPINNakSts is ACTIVE — clearing...\n");
        *dctl_r = (1u << 8);  /* CGNPINNAK only — direct write, not read-modify-write */
        vTaskDelay(1);
        printf("[FIX] After clear: DCTL=0x%08X GNPINNakSts=%d\n",
            *dctl_r, (*dctl_r >> 2) & 1);
    } else {
        printf("[DIAG] GNPINNakSts already clear — OK\n");
    }
```

- [ ] **Step 2: Build, deploy, test**

- [ ] **Step 3: 驗證 — 觀察 GNPINNakSts 是否為 active，以及清除後是否有 XFRC**

### Task 3.2: 增加 DCFG.EPMisCnt

- [ ] **Step 1: 設定 EPMisCnt 為最大值 (0x1F)**

```c
    /* === Phase 3b: Increase EPMisCnt to maximum === */
    uint32_t dcfg_new = *dcfg_r;
    uint32_t old_epmiscnt = (dcfg_new >> 18) & 0x1F;
    dcfg_new = (dcfg_new & ~(0x1F << 18)) | (0x1F << 18);
    *dcfg_r = dcfg_new;
    printf("[FIX] DCFG.EPMisCnt: %d -> %d\n", old_epmiscnt, (*dcfg_r >> 18) & 0x1F);
```

- [ ] **Step 2: Build, deploy, test**

- [ ] **Step 3: 驗證 — 觀察是否有 XFRC**

**Go/No-go：** 如果成功 → Phase 7。如果失敗 → Phase 4。

---

## Phase 4: DCTL.GMC 調整 + DCTL.EnContOnBNA（20 分鐘 timebox）

**目的：** 嘗試 Global Multi Count 和 BNA continuation 設定。
**前提：** Phase 2+3 都失敗才進入。

### Task 4.1: 設定 GMC 和 EnContOnBNA

**Files:**
- Modify: `amb82_Info/ameba-rtos-pro2/component/media/mmfv2/module_uvcd.c`

- [ ] **Step 1: 設定 DCTL.GMC=1 和 DCTL.EnContOnBNA=1**

```c
    /* === Phase 4: GMC and EnContOnBNA === */
    uint32_t dctl_p4 = *dctl_r;
    /* GMC (bits 13-14) = 1 (single packet per frame) */
    dctl_p4 = (dctl_p4 & ~(3u << 13)) | (1u << 13);
    /* EnContOnBNA (bit 17) = 1 */
    dctl_p4 |= (1u << 17);
    *dctl_r = dctl_p4;
    printf("[FIX] DCTL GMC=%d EnContOnBNA=%d\n",
        (*dctl_r >> 13) & 3, (*dctl_r >> 17) & 1);
```

- [ ] **Step 2: Build, deploy, test**

- [ ] **Step 3: 驗證**

**Go/No-go：** 成功 → Phase 7。失敗 → Phase 5。

---

## Phase 5: Full Speed ISO Mode（1-2 小時 timebox）

**目的：** 強制 USB 進入 Full Speed 模式，去除 HS microframe/high-bandwidth 的所有複雜性。
**假說：** 如果 FS ISO 能成功，證明整條路是通的，問題只在 HS ISO 的 timing/parity。
**前提：** Phase 2-4 都失敗才進入。

### Task 5.1: 修改 DCFG.DevSpd 強制 Full Speed

**Files:**
- Modify: `amb82_Info/ameba-rtos-pro2/component/media/mmfv2/module_uvcd.c` (uvcd_create 函式)
- Modify: `amb82_Info/ameba-rtos-pro2/component/media/mmfv2/module_uvcd.c` (uvcd_handle 函式)

**重要：** DevSpd 必須在 USB init 之前或非常早期設定。最安全的位置是在 `_usb_init()` 呼叫之後、`wait_usb_ready()` 之前。但由於 `_usb_init()` 內部可能已經配置 DCFG，我們需要在 usb_patch.c 裡用 weak symbol 來確保更早的覆蓋。

- [ ] **Step 1: 在 usb_patch.c 加入 DCFG DevSpd override**

```c
/* Force Full Speed mode for ISO transfer debugging.
 * DevSpd=1: Full Speed using HS PHY (48MHz)
 * Must be called early, before USB enumeration completes. */
void usb_patch_force_full_speed(void)
{
    volatile uint32_t *dcfg = (volatile uint32_t *)(0x400C0000 + 0x800);
    uint32_t val = *dcfg;
    uint32_t old_spd = val & 0x3;
    val = (val & ~0x3u) | 0x1u;  /* DevSpd = 1 (FS on HS PHY) */
    *dcfg = val;
    printf("[USB] DCFG DevSpd: %d -> %d (forced Full Speed)\n", old_spd, *dcfg & 0x3);
}
```

- [ ] **Step 2: 在 dwc_otg_enable_global_interrupts override 中呼叫（最早時機）**

DevSpd 必須在 USB reset/enumeration 之前設定。最安全的位置是在 `usb_patch.c` 的 `dwc_otg_enable_global_interrupts` override 裡，這是 USB init 過程中最早的 hook point：

在 `usb_patch.c` 的 `dwc_otg_enable_global_interrupts()` 結尾加入：

```c
void dwc_otg_enable_global_interrupts(void *core_if)
{
    uint32_t *regs_ptr = (uint32_t *)((uint8_t *)core_if + 4);
    uint32_t base_offset = *regs_ptr;
    uint32_t gahb_offset = base_offset + 8;
    uint32_t val = HAL_OTG_READ32(gahb_offset);
    printf("[USB] enable_global_interrupts: GAHBCFG 0x%08X -> 0x%08X\n", val, val | 1);
    HAL_OTG_WRITE32(gahb_offset, val | 1);

    /* Phase 5: Force Full Speed BEFORE enumeration */
    usb_patch_force_full_speed();
}
```

- [ ] **Step 3: 調整 ISO 傳輸參數適應 Full Speed**

在 `uvcd_handle` 中修改：

```c
    /* Full Speed ISO: max 1023 bytes/packet, 1 packet/frame, no MC */
    uint32_t size = 2;       /* still minimal for testing */
    uint32_t mps = 1023;     /* FS ISO max */
    uint32_t pkt_cnt = 1;

    /* ... */

    /* 2. Set transfer size: MC=1 (FS has no multi-count) */
    *ep3_tsiz = (1u << 29) | (pkt_cnt << 19) | size;
```

- [ ] **Step 4: Build, deploy, test**

- [ ] **Step 5: 驗證 — 用 `system_profiler SPUSBDataType` 確認裝置以 Full Speed enumerate**

預期看到 `Speed: Up to 12 Mb/s` 而非 `480 Mb/s`。

- [ ] **Step 6: 開啟相機 app，觀察 UART log 是否有 XFRC**

**Go/No-go：**
- FS ISO 成功 → 問題確認為 HS ISO specific，Phase 7 優化
- FS ISO 也失敗 → 問題更根本，直接進 Phase 6（Bulk UVC）

---

## Phase 6: Bulk UVC Mode（2-4 小時 timebox）

**目的：** 完全繞過 ISO 傳輸，改用 Bulk endpoint 實現 UVC。
**前提：** Phase 5 也失敗，或直接選擇此方案作為保底。
**注意：** 這是最大幅度的改動，需要修改 USB descriptor。

### Task 6.1: 修改 USB Descriptor — EP3 改為 Bulk

**Files:**
- Modify: `amb82_Info/ameba-rtos-pro2/component/usb/usb_class/device/class/uvc/inc/usbd_uvc_desc.h` 或對應的 descriptor 定義檔

- [ ] **Step 1: 找到 EP3 descriptor 定義**

搜尋 `bEndpointAddress = 0x83` (EP3 IN) 的 descriptor，將 `bmAttributes` 從 `0x05` (Isochronous) 改為 `0x02` (Bulk)。

```c
/* Before: Isochronous */
.bmAttributes = 0x05,       /* ISO, Async, Data */
.wMaxPacketSize = 0x1400,   /* 3 × 1024 = 3072 (high-bandwidth) */

/* After: Bulk */
.bmAttributes = 0x02,       /* Bulk */
.wMaxPacketSize = 0x0200,   /* 512 (HS Bulk max) */
```

- [ ] **Step 2: 修改 alt setting — Bulk 不需要 alt=0/alt=1 切換**

UVC Bulk 模式通常只有一個 alt setting（alt=0 就有 endpoint）。需要調整 streaming interface descriptor。

- [ ] **Step 3: 修改 uvcd_handle 的傳輸邏輯**

Bulk 傳輸比 ISO 簡單得多：

```c
    /* Bulk IN transfer */
    *ep3_int = 0xFF;  /* Clear interrupts */
    *ep3_tsiz = (pkt_cnt << 19) | size;  /* No MC field for Bulk */
    *ep3_dma = (uint32_t)data;

    uint32_t ctl = *ep3_ctl;
    ctl &= ~(0xFu << 22);
    ctl |= (3u << 22);  /* TXFNUM=3 */
    ctl |= (1u << 31) | (1u << 26);  /* EPEna + CNAK */
    *ep3_ctl = ctl;
```

- [ ] **Step 4: Build, deploy, test**

- [ ] **Step 5: 驗證 — macOS 是否將裝置識別為 Bulk UVC，是否有 XFRC**

**Go/No-go：** Bulk 是最保底的方案，如果 Bulk 也失敗，問題可能在更底層（USB PHY 或 libusbd.a 的根本問題）。

---

## Phase 7: 成功後優化

**前提：** 任何 Phase 出現 XFRC → 進入此階段。

### Task 7.1: 發送完整 JPEG Frame

- [ ] **Step 1: 將 transfer size 從 2 bytes 改回完整 test_jpeg_data (12463 bytes)**
- [ ] **Step 2: 測試 macOS 是否能收到並顯示綠色畫面**

### Task 7.2: 移除 Diagnostic Log

- [ ] **Step 1: 移除或 `#if 0` 大量的 printf diagnostic**
- [ ] **Step 2: 保留關鍵錯誤 log**

### Task 7.3: 接入真實 Camera Sensor

- [ ] **Step 1: 把 array_module (test pattern) 換成 video_module (F37 sensor)**
- [ ] **Step 2: 測試即時影像串流**

### Task 7.4: 記錄成功方案

- [ ] **Step 1: 更新 CLAUDE.md 記錄 working configuration**
- [ ] **Step 2: 更新 memory 檔案**
- [ ] **Step 3: Commit working code**

---

## 決策流程圖

```
Phase 1 (Diagnostic Dump)
    │
    ▼
Phase 2 (DCTL.IFrmNum=1) ──── XFRC? ──→ Phase 7 (優化)
    │ no
    ▼
Phase 3 (Clear NAK + EPMisCnt) ── XFRC? ──→ Phase 7
    │ no
    ▼
Phase 4 (GMC + EnContOnBNA) ── XFRC? ──→ Phase 7
    │ no
    ▼
Phase 5 (Full Speed ISO) ──── XFRC? ──→ Phase 7
    │ no
    ▼
Phase 6 (Bulk UVC) ──── XFRC? ──→ Phase 7
    │ no
    ▼
    ⚠️ 需要重新評估：USB PHY / libusbd.a 根本問題
```

## 時間預估

| Phase | Timebox | 累計 |
|-------|---------|------|
| Phase 1: Diagnostic | 10 min | 10 min |
| Phase 2: IFrmNum | 30 min | 40 min |
| Phase 3: NAK + EPMisCnt | 30 min | 70 min |
| Phase 4: GMC + BNA | 20 min | 90 min |
| Phase 5: Full Speed ISO | 1-2 hr | ~3 hr |
| Phase 6: Bulk UVC | 2-4 hr | ~6 hr |
| Phase 7: 優化 | 1-2 hr | ~8 hr |

**最佳情況：** Phase 2 就成功 → 40 分鐘搞定
**最差情況：** Phase 6 才成功 → ~6 小時
