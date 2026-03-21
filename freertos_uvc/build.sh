#!/bin/bash
set -e
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
SDK_ROOT="${SCRIPT_DIR}/../amb82_Info/ameba-rtos-pro2"
GCC_RELEASE="${SDK_ROOT}/project/realtek_amebapro2_v0_example/GCC-RELEASE"
BUILD_DIR="${GCC_RELEASE}/build_uvc_dump"
EXAMPLE_NAME="media_uvcd"

REALTEK_TOOLCHAIN="$HOME/Library/Arduino15/packages/realtek/tools/ameba_pro2_toolchain/1.0.1-p1/bin"
if [ -d "$REALTEK_TOOLCHAIN" ]; then
    export PATH="$REALTEK_TOOLCHAIN:$PATH"
fi

EXAMPLE_LINK="${SDK_ROOT}/component/example/${EXAMPLE_NAME}"
if [ "$1" = "clean" ]; then
    rm -rf "${BUILD_DIR}" && rm -f "${EXAMPLE_LINK}" && echo "Done." && exit 0
fi
[ ! -L "${EXAMPLE_LINK}" ] && ln -sf "${SCRIPT_DIR}" "${EXAMPLE_LINK}"
mkdir -p "${BUILD_DIR}" && cd "${BUILD_DIR}"
cmake .. -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE="${GCC_RELEASE}/toolchain.cmake" -DEXAMPLE=${EXAMPLE_NAME}
cmake --build . -- -j$(sysctl -n hw.ncpu 2>/dev/null || nproc)
