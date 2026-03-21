================================================================================
  AMB82 Mini FreeRTOS UVC Camera Example
  把 AMB82 Mini 變成 USB 攝影機 (UVC Device)
================================================================================

功能說明
~~~~~~~~
  透過 USB OTG 介面將 AMB82 Mini 的攝影機畫面傳送到 PC，
  PC 端會辨識為標準 USB 攝影機 (UVC Class)。

  支援格式: MJPEG (相容性最佳，適用 VLC/Zoom/OBS/Google Meet)
  解析度:   1920x1080 (FHD)
  幀率:     24 FPS

架構概覽
~~~~~~~~
  Camera Sensor (MIPI CSI)
       |
  [ISP Video Module] -- H264/MJPEG 編碼
       |
  [SISO Linker] -- 單輸入單輸出
       |
  [UVC Device Module] -- USB 傳輸
       |
  PC (USB Host) -- 辨識為 USB 攝影機

檔案說明
~~~~~~~~
  app_example.c       - 進入點，呼叫 UVC 初始化
  example_uvc_cam.h   - 參數配置 (解析度/幀率/編碼格式)
  example_uvc_cam.c   - 主程式，建立 MMF pipeline

編譯方式
~~~~~~~~
  在 ameba-rtos-pro2 SDK 中:

  cd project/realtek_amebapro2_v0_example/GCC-RELEASE
  mkdir build && cd build
  cmake .. -G"Unix Makefiles" \
    -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake \
    -DEXAMPLE=media_uvcd
  make -j$(nproc)

  注意: 需將本範例檔案複製到 SDK 的 component/example/media_uvcd/ 目錄下，
        或修改 cmake 指向本目錄。

使用方式
~~~~~~~~
  1. 燒錄韌體到 AMB82 Mini
  2. Micro USB 接 PC (供電 + Serial Monitor)
  3. USB OTG 接 PC (影像傳輸)
  4. PC 會辨識出 USB 攝影機
  5. 開啟任意攝影機應用 (VLC / Zoom / OBS / PotPlayer)

AT 指令
~~~~~~~
  UVCD  - 停止 UVC 串流
  UVCE  - 重新啟動 UVC 串流
