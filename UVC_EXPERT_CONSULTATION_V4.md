# AMB82 UVC macOS — Expert Consultation V4

## 重大進展：DMA 可以運作，數據已進入 TX FIFO，但最後一哩路失敗

### 目前達到的狀態

| 環節 | 狀態 |
|------|------|
| USB enumerate | ✅ |
| UVC PROBE/COMMIT | ✅ |
| SET_INTERFACE alt=1 | ✅ "stream on" |
| ep_enable 軟體配置 | ✅ (PCD fix) |
| EP3 DIEPCTL3 EPEna | ✅ bit 31=1 (手動寫入) |
| DMA address (aligned) | ✅ 32-byte aligned |
| DMA → TX FIFO transfer | ✅ TXFSTS3=0 (FIFO 滿) |
| **FIFO → USB bus** | **❌ Incomplete ISO IN (IISOIXFR)** |
| DIEPINT3 XFRC | ❌ 始終 0 |

### DMA 確實在運作的證據

```
TXFNUM=2 (wrong FIFO): TXFSTS3=0x00000200 (512 words free — FIFO 3 空)
TXFNUM=3 (correct FIFO): TXFSTS3=0x00000000 (0 words free — FIFO 3 滿!)
```

TXFNUM=3 時 DMA 成功把 1024 bytes 填入 TX FIFO 3。但硬體無法送出。

### GINTSTS 顯示 Incomplete ISO IN

```
GINTSTS = 0x04148028
  bit 22 (IPXFR/INCOMPL_SOIN) = 1
  bit 20 (IISOIXFR) = 1  ← Incomplete Isochronous IN Transfer
  bit 15 (ESUSP) = 0 or 1
  bit 5  (NPTXFE) = 1
  bit 3  (SOF) = 1       ← USB SOF 在跑，連線正常
```

**IISOIXFR 表示：host 發了 IN token，但 device 在指定的 frame 內沒有完成傳輸。**

### Even/Odd Frame Parity

我們的實作（仿 TinyUSB）：
```c
uint32_t frame_num = (*dsts >> 8) & 0x3FFF;
if (frame_num & 1) ctl |= (1u << 28);  // SEVNFRM — target even
else ctl |= (1u << 29);                 // SODDFRM — target odd
```

嘗試了：
1. **vTaskDelay retry** — IISO 每次都觸發（10ms 太慢）
2. **Busy-wait retry** — 8 次 fast retry，仍然每次 IISO
3. **Both parities** — flip 也沒用
4. **Single packet (1024B)** — 縮到最小也沒用

### Register Dump (TXFNUM=3, 1024B transfer)

```
DIEPCTL3  = 0x80C48400  → EPEna=1, TXFNUM=3, EPTYP=ISO, MPS=1024
DIEPTSIZ3 = 0x20080400  → MC=1, PKTCNT=1, XFRSIZ=1024
DIEPDMA3  = 0x70328980  → 32-byte aligned
DIEPINT3  = 0x00000000  → 沒有任何 EP3 interrupt

DTXF3     = 0x01000880  → TX FIFO 3: 256 words at 0x0880
TXFSTS3   = 0x00000000  → FIFO 滿 (data DMA'd in but not sent)

GAHBCFG   = 0x0000002F  → DMAEn=1, GlblIntrMsk=1
DAINTMSK  = 0x0001000B  → EP0,1,3 IN masked
GINTMSK   = 0xD03C3C06  → IEPInt=1, IISOIXFR not masked (bit 20=0)
```

### 所有已應用的 Fix

1. `dwc_otg_enable_global_interrupts` override — GAHBCFG bit 0
2. `GADGET_WRAPPER_TMP[0x00] = &gpcd` — PCD binding (in format change callback)
3. NOP `iso_ep_start` — firmware binary patch (避免 descriptor DMA crash)
4. 手動 ISO IN transfer — 直接寫 DIEPCTL3/DIEPTSIZ3/DIEPDMA3
5. DMA buffer 32-byte aligned — memcpy to aligned static buffer
6. TXFNUM=3 — 使用正確的 TX FIFO

### 核心問題

**TX FIFO 有數據（DMA 成功），但 DWC2 硬體不把它送到 USB bus 上。**

每個 microframe 都觸發 IISOIXFR (Incomplete ISO IN)。

### 假設

1. **Frame parity 計算正確但寫入時機太晚** — 我們在 task context 寫 register，可能延遲 > 1 microframe (125μs)
2. **libusbd.a 的 USB ISR 在干擾** — DAINTMSK 有 EP3，ISR 可能在 reset 我們的配置
3. **DWC2 periodic scheduler 問題** — ISO 需要額外的 periodic scheduling enable
4. **FIFO 滿但 data format 不對** — DWC2 可能需要特定的 ISO header 在 FIFO 中
5. **MC (Multi-Count) 設定問題** — MC=1 可能不夠，HS ISO 可能需要 MC=3

### 問題

**Q1: TXFSTS3=0 (FIFO 滿) 但 IISOIXFR 持續觸發，什麼情況會這樣？**

FIFO 有 data，host 有 IN token，但 "incomplete"。是 frame parity 問題、FIFO mapping 問題、還是 periodic scheduler 問題？

**Q2: 是否需要 disable DAINTMSK 的 EP3 bit 來防止 ISR 干擾？**

DAINTMSK=0x0001000B 表示 EP3 IN interrupt 被 mask。libusbd.a 的 ISR 會處理 EP3 事件。我們手動寫 register 可能跟 ISR 衝突。

**Q3: DWC2 Buffer DMA ISO IN 是否需要特殊的 periodic FIFO 配置？**

例如 HPTXFSIZ 或 periodic TX FIFO 相關 register？

**Q4: MC (Multi-Count) 對 HS ISO IN 的影響？**

我們設 MC=1。EP descriptor 的 wMaxPacketSize 如果有 additional transactions (bits 12:11)，MC 應該設成什麼？

**Q5: 我們的 approach（從 task context 手動寫 EP3 register）是否根本上不可行？**

是否必須在 USB ISR context 中（例如 SOF interrupt handler）做 ISO EP 的 per-frame programming？
