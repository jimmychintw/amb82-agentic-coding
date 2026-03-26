#!/bin/bash
# flash_ota.sh — AMB82 WiFi OTA 一鍵燒錄
#
# Usage: ./flash_ota.sh <firmware.bin>
#
# 自動執行：OTA 模式 → 上傳 → 切回正常 → Ping 驗證

set -e

ESP32_IP="192.168.3.32"
AMB82_IP="192.168.3.82"
FIRMWARE="$1"

if [ -z "$FIRMWARE" ]; then
    echo "Usage: ./flash_ota.sh <firmware.bin>"
    echo ""
    echo "Example:"
    echo "  ./flash_ota.sh test_fw_freertos.bin"
    exit 1
fi

if [ ! -f "$FIRMWARE" ]; then
    echo "Error: $FIRMWARE not found"
    exit 1
fi

SIZE=$(du -h "$FIRMWARE" | cut -f1)
echo "=== AMB82 WiFi OTA Flash ==="

# Check OTA system version
OTA_VER=$(curl -s --max-time 2 http://$ESP32_IP/status 2>/dev/null | grep -o '"ota_arch_ver":"[^"]*"' | cut -d'"' -f4)
if [ -n "$OTA_VER" ]; then
    echo "OTA Arch Version: $OTA_VER"
else
    echo "Warning: Cannot reach ESP32 OTA Controller"
    exit 1
fi

echo "Firmware: $FIRMWARE ($SIZE)"
echo ""

# Step 1: OTA mode
echo "[1/4] Switching AMB82 to OTA mode..."
curl -s -X POST http://$ESP32_IP/ota > /dev/null
echo " OK"

# Step 2: Wait for OTA Manager
echo -n "[2/4] Waiting for OTA Manager"
for i in $(seq 1 20); do
    if curl -s --max-time 1 http://$AMB82_IP:8080/ > /dev/null 2>&1; then
        echo " Ready!"
        break
    fi
    echo -n "."
    sleep 1
    if [ $i -eq 20 ]; then
        echo " TIMEOUT"
        echo "Error: AMB82 OTA Manager not responding"
        exit 1
    fi
done

# Step 3: Upload firmware
echo "[3/4] Uploading firmware..."
RESULT=$(curl -s -X POST --data-binary @"$FIRMWARE" http://$AMB82_IP:8080/ota)
echo "  $RESULT"

# Check result
if echo "$RESULT" | grep -q '"status":"ok"'; then
    echo "  Upload + CRC verification passed!"
else
    echo "  Upload FAILED"
    exit 1
fi

# Step 4: Normal mode
echo "[4/4] Switching to normal mode..."
sleep 1
curl -s -X POST http://$ESP32_IP/normal > /dev/null
echo " OK"

# Wait and verify
echo ""
echo "Waiting for FW2 to boot..."
sleep 10
echo "Ping test:"
ping -c 3 $AMB82_IP 2>/dev/null && echo "" && echo "=== OTA Success! ===" || echo "Ping failed (FW2 may not have WiFi or different IP)"
