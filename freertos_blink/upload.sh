#!/bin/bash
# Upload FreeRTOS binary to AMB82 Mini via UART
#
# Usage: ./upload.sh [port]
# Default port: /dev/cu.wchusbserial110

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
SDK_ROOT="${SCRIPT_DIR}/../amb82_Info/ameba-rtos-pro2"
BUILD_DIR="${SDK_ROOT}/project/realtek_amebapro2_v0_example/GCC-RELEASE/build"
UARTFWBURN="${SDK_ROOT}/tools/Pro2_PG_tool _v1.4.3/uartfwburn.darwin"
PORT="${1:-/dev/cu.wchusbserial110}"

FLASH_BIN="${BUILD_DIR}/flash_ntz.bin"
if [ ! -f "${FLASH_BIN}" ]; then
    echo "Error: ${FLASH_BIN} not found. Run ./build.sh first."
    exit 1
fi

SIZE=$(du -h "${FLASH_BIN}" | cut -f1)
echo "Uploading ${FLASH_BIN} (${SIZE}) to ${PORT}..."
echo ""
echo "⚠️  Make sure the board is in upload mode:"
echo "  1. Press and HOLD UART_DOWNLOAD"
echo "  2. Press and RELEASE RESET"
echo "  3. Release UART_DOWNLOAD"
echo ""
read -p "Press Enter when ready..."

chmod +x "${UARTFWBURN}"
"${UARTFWBURN}" -p "${PORT}" -f "${FLASH_BIN}" -b 2000000 -U -x 32 -r

echo ""
echo "Upload complete! Board will reset automatically."
