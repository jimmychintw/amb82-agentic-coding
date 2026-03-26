#include "example_uvc_cam.h"
#include "ota_boot_target.h"

void app_example(void)
{
	ota_boot_target_fw1();
	example_uvc_cam();
}
