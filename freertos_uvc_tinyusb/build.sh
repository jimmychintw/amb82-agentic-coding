#!/bin/bash
# Build FreeRTOS TinyUSB UVC+UAC example using AMB82 SDK build system
#
# Usage: ./build.sh [clean]

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
SDK_ROOT="${SCRIPT_DIR}/../amb82_Info/ameba-rtos-pro2"
GCC_RELEASE="${SDK_ROOT}/project/realtek_amebapro2_v0_example/GCC-RELEASE"
BUILD_DIR="${GCC_RELEASE}/build"

# Use Realtek ASDK-10.3.0 toolchain (required by SDK, newer GCC versions cause build errors)
REALTEK_TOOLCHAIN="$HOME/Library/Arduino15/packages/realtek/tools/ameba_pro2_toolchain/1.0.1-p1/bin"
if [ -d "$REALTEK_TOOLCHAIN" ]; then
    export PATH="$REALTEK_TOOLCHAIN:$PATH"
    echo "  Toolchain: $(arm-none-eabi-gcc --version | head -1)"
else
    echo "WARNING: Realtek toolchain not found at $REALTEK_TOOLCHAIN"
    echo "         Using system arm-none-eabi-gcc: $(arm-none-eabi-gcc --version | head -1)"
    echo "         SDK requires GCC 10.3.0 — build may fail with newer versions"
fi

# Symlink our example into SDK's component/example/
EXAMPLE_NAME="media_uvcd_tinyusb"
EXAMPLE_LINK="${SDK_ROOT}/component/example/${EXAMPLE_NAME}"

if [ "$1" = "clean" ]; then
    echo "Cleaning build..."
    rm -rf "${BUILD_DIR}"
    rm -f "${EXAMPLE_LINK}"
    echo "Done."
    exit 0
fi

# Create symlink to our example source
if [ ! -L "${EXAMPLE_LINK}" ]; then
    echo "Linking example: ${SCRIPT_DIR}/src -> ${EXAMPLE_LINK}"
    ln -sf "${SCRIPT_DIR}/src" "${EXAMPLE_LINK}"
fi

# Build
echo "Building FreeRTOS TinyUSB UVC+UAC example..."
echo "  SDK: ${SDK_ROOT}"
echo "  Build dir: ${BUILD_DIR}"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

# Configure with our example
cmake .. -G "Unix Makefiles" \
    -DCMAKE_TOOLCHAIN_FILE="${GCC_RELEASE}/toolchain.cmake" \
    -DEXAMPLE=${EXAMPLE_NAME}

# Build
cmake --build . -- -j$(sysctl -n hw.ncpu 2>/dev/null || nproc)

echo ""
echo "Build complete!"
if [ -f "flash_ntz.bin" ]; then
    SIZE=$(du -h flash_ntz.bin | cut -f1)
    echo "  Binary: flash_ntz.bin (${SIZE})"
    echo "  Upload: ./upload.sh"
fi
