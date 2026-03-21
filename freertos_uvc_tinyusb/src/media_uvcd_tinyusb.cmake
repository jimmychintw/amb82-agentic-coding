# TinyUSB root path (relative to this cmake file's directory)
# NOTE: Run `git submodule add https://github.com/hathach/tinyusb.git lib/tinyusb`
#       inside freertos_uvc_tinyusb/ to populate this directory.
set(TINYUSB_ROOT ${CMAKE_CURRENT_LIST_DIR}/../lib/tinyusb)

# NOTE: Do NOT link libusbd.a from the Realtek SDK — it conflicts with TinyUSB
#       symbols (usbd_init, usbd_ep_write, etc.). Exclude it in the top-level
#       CMakeLists.txt or toolchain file if necessary.

### add lib ###
list(
	APPEND app_example_lib
)

### add flags ###
list(
	APPEND app_example_flags
)

### add header files ###
list (
	APPEND app_example_inc_path
	${TINYUSB_ROOT}/src
)

### add source file ###
list(
	APPEND app_example_sources
	app_example.c
	${TINYUSB_ROOT}/src/tusb.c
	${TINYUSB_ROOT}/src/common/tusb_fifo.c
	${TINYUSB_ROOT}/src/device/usbd.c
	${TINYUSB_ROOT}/src/device/usbd_control.c
	${TINYUSB_ROOT}/src/portable/synopsys/dwc2/dcd_dwc2.c
	${TINYUSB_ROOT}/src/portable/synopsys/dwc2/dwc2_common.c
	${TINYUSB_ROOT}/src/class/cdc/cdc_device.c
)
# Only prepend CMAKE_CURRENT_LIST_DIR to local source files (app_*.c).
# TinyUSB sources already use absolute paths via ${TINYUSB_ROOT}.
list(TRANSFORM app_example_sources PREPEND ${CMAKE_CURRENT_LIST_DIR}/ REGEX "^app_")
