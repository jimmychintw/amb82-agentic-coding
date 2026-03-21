Class VideoStreamOverlay — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class VideoStreamOverlay
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class VideoStreamOverlay.rst)
# Class VideoStreamOverlay[](#class-videostreamoverlay)
## **VideoStreamOverlay Class**[](#videostreamoverlay-class)
### **Description**[](#description)
VideoStreamOverlay also known as On-Screen Display (OSD) that allows contents such as texts and shapes to be displayed on video streams. VideoStreamOverlay class is used to draw on video streams.
### **Syntax**[](#syntax)
class VideoStreamOverlay
### **Members**[](#members)
|**Public Constructors**
|
|
| VideoStreamOverlay::VideoStreamOverlay
|
Constructs a VideoStreamOverlay
object.
|
|
| **Public Methods**
|
|
| VideoStreamOverlay::configVideo
|
Configure input video stream
parameters.
|
|
| VideoStreamOverlay:: configTextSize
|
Configure text width and height
shown on OSD.
|
|
| VideoStreamOverlay:: createBitmap
|
Create bitmap on video streams.
|
|
| VideoStreamOverlay::begin
|
Enable OSD and start drawing on
top of video streams.
|
|
| VideoStreamOverlay::end
|
Stop OSD drawing on all video
streams.
|
|
| VideoStreamOverlay::endChannel
|
Stop OSD drawing on specified
video stream.
|
|
| VideoStreamOverlay::getTextHeight
|
Get current configuration of
OSD text height.
|
|
| VideoStreamOverlay::getTextWidth
|
Get current configuration of
OSD text width.
|
|
| VideoStreamOverlay::color
|
Convert ARGB color values into
a format compatible for OSD
use.
|
|
| VideoStreamOverlay::drawLine
|
Draw a line in OSD frame
buffer.
|
|
| VideoStreamOverlay::drawPoint
|
Draw a point in OSD frame
buffer.
|
|
| VideoStreamOverlay::drawRect
|
Draw a rectangle on OSD frame
buffer.
|
|
| VideoStreamOverlay::drawText
|
Draw text on OSD frame buffer.
|
|
| VideoStreamOverlay::drawPlus
|
Draw “+” on OSD frame buffer.
|
|
| VideoStreamOverlay::update
|
Update OSD and display drawings
on video streams.
|
|
| VideoStreamOverlay::initOSDBitmapPos
|
Set image position on video
stream.
|
|
| VideoStreamOverlay::initOSDBitmapBlk
|
Set block index of image
on video stream.
|
|
| VideoStreamOverlay::initOSDBitmapBuf
|
Set buffer containing image data
and its length
|
|
| VideoStreamOverlay::resizeWidth
|
Get resized width of image for
overlaying on a video stream.
|
|
| VideoStreamOverlay::resizeHeight
|
Get resized height of image for
overlaying on a video stream.
|
|
| VideoStreamOverlay::heapsizeCal
|
Get heapsize for an image
overlay given its resized
dimensions and color format.
|
|
| VideoStreamOverlay::drawImage
|
Draw image on OSD frame buffer.
|
|
| VideoStreamOverlay::displayImage
|
Update OSD and display images
on video streams.
|
|
## **VideoStreamOverlay::configVideo**[](#videostreamoverlay-configvideo)
### **Description**[](#id1)
Configure input video stream parameters.
### **Syntax**[](#id2)
void configVideo(int ch, VideoSetting& config);
### **Parameters**[](#parameters)
ch: Channel to configure.
- 0
- 1
- 2
config: VideoSetting object.
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
OSD only supports channel 0, 1 and 2. “VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::configTextSize**[](#videostreamoverlay-configtextsize)
### **Description**[](#id3)
Configure text width and height shown on OSD.
### **Syntax**[](#id4)
void configTextSize(int ch, int text_width, int text_height);
### **Parameters**[](#id5)
ch: Channel to configure.
- 0
- 1
- 2
text_width: Text width in pixels. (Default value is 16)
text_height: Text height in pixels (Default value is 32)
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
NA
Note
“VideoStreamOverlay.h” must be included to use the class function. Text size should be configured before OSD is started using begin().
## **VideoStreamOverlay::createBitmap**[](#videostreamoverlay-createbitmap)
### **Description**[](#id8)
Create bitmap on video streams.
### **Syntax**[](#id9)
void createBitmap (int ch, int idx = 0);
### **Parameters**[](#id10)
ch: Channel to configure.
- 0
- 1
- 2
idx: Layer index of OSD.
- 0 to 5 (Default value is 0)
### **Returns**[](#id11)
NA
### **Example Code**[](#id12)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::begin**[](#videostreamoverlay-begin)
### **Description**[](#id14)
Enable OSD and start drawing on top of video streams.
### **Syntax**[](#id15)
void begin(void);
void begin(VideoSetting &config, int ch, int idx = 0);
### **Parameters**[](#id16)
ch: Channel to enable OSD.
- 0
- 1
- 2
config: VideoSetting object.
idx: Layer index of OSD.
### **Returns**[](#id17)
NA
### **Example Code**[](#id18)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::end**[](#videostreamoverlay-end)
### **Description**[](#id20)
Stop OSD drawing on all video streams.
### **Syntax**[](#id21)
void end(void);
### **Parameters**[](#id22)
NA
### **Returns**[](#id23)
NA
### **Example Code**[](#id24)
NA
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::endChannel**[](#videostreamoverlay-endchannel)
### **Description**[](#id25)
Stop OSD drawing on specified video stream.
### **Syntax**[](#id26)
void endChannel(int ch);
### **Parameters**[](#id27)
ch: Channel to stop.
- 0
- 1
- 2
### **Returns**[](#id28)
NA
### **Example Code**[](#id29)
NA
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::getTextHeight**[](#videostreamoverlay-gettextheight)
### **Description**[](#id30)
Get current configuration of OSD text height.
### **Syntax**[](#id31)
int getTextHeight(int ch);
### **Parameters**[](#id32)
ch: Channel to get the OSD text’s height.
- 0
- 1
- 2
### **Returns**[](#id33)
This function returns the OSD text’s height on selected channel.
### **Example Code**[](#id34)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::getTextWidth**[](#videostreamoverlay-gettextwidth)
### **Description**[](#id35)
Get current configuration of OSD text width.
### **Syntax**[](#id36)
int getTextWidth(int ch);
### **Parameters**[](#id37)
ch: Channel to get the OSD text’s width.
- 0
- 1
- 2
### **Returns**[](#id38)
This function returns the OSD text’s width on the selected channel.
### **Example Code**[](#id39)
NA
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::color**[](#videostreamoverlay-color)
### **Description**[](#id40)
Convert ARGB color values into a format compatible for OSD use.
### **Syntax**[](#id41)
uint32_t color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xff);
### **Parameters**[](#id42)
red: Intensity level of red color expressed as an 8-bit unsigned integer.
- 0 to 255
green: Intensity level of green color expressed as an 8-bit unsigned integer.
- 0 to 255
blue: Intensity level of blue color expressed as an 8-bit unsigned integer.
- 0 to 255
alpha: Transparency of color expressed as an 8-bit unsigned integer.
- 0 to 255 (Default value is 255. This value is optional)
### Returns[](#id43)
This function returns the ARGB value in a format compatible for OSD use.
### **Example Code**[](#id44)
NA
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::drawLine**[](#videostreamoverlay-drawline)
### **Description**[](#id45)
Draw a line in OSD frame buffer.
### **Syntax**[](#id46)
void drawLine(int ch, int xmin, int ymin, int xmax, int ymax, int line_width, uint32_t color, int idx = 0);
### **Parameters**[](#id47)
ch: Channel to draw on.
- 0
- 1
- 2
xmin: x coordinate of the top left corner.
ymin: y coordinate of the top left corner.
xmax: x coordinate of the bottom right corner.
ymax: y coordinate of bottom right corner.
line_width: Width of a line.
color: Color of the line.
idx: Layer index of OSD.
- 0 to 5 (Default value is 0)
### **Returns**[](#id48)
NA
### **Example Code**[](#id49)
NA
Note
VideoStreamOverlay::update() needs to be called for drawings to be shown on the video streams. “VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::drawPoint**[](#videostreamoverlay-drawpoint)
### **Description**[](#id50)
Draw a point in OSD frame buffer.
### **Syntax**[](#id51)
void VideoStreamOverlay::drawPoint(int ch, int xmin, int ymin, int point_width, uint32_t color, int idx = 0);
### **Parameters**[](#id52)
ch: Channel to draw on.
- 0
- 1
- 2
xmin: x coordinate of the point
ymin: y coordinate of the point
point_width: size of the point.
color: Color of the point.
idx: Layer index of OSD.
- 0 to 5 (Default value is 0)
### **Returns**[](#id53)
NA
### **Example Code**[](#id54)
Example: [RTSPFaceDetection](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/RTSPFaceDetection/RTSPFaceDetection.ino)
Note
VideoStreamOverlay::update() needs to be called for drawings to be shown on the video streams. “VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::drawRect**[](#videostreamoverlay-drawrect)
### **Description**[](#id56)
Draw a rectangle on OSD frame buffer.
### **Syntax**[](#id57)
void drawRect(int ch, int xmin, int ymin, int xmax, int ymax, int line_width, uint32_t color, int idx = 0);
### **Parameters**[](#id58)
ch: Channel to draw rectangle on.
- 0
- 1
- 2
xmin: x coordinate of the top left corner.
ymin: y coordinate of the top left corner.
xmax: x coordinate of the bottom right corner.
ymax: y coordinate of bottom right corner.
line_width: Width of a rectangle’s border.
color: Color of the rectangle.
idx: Layer index of OSD.
- 0 to 5 (Default value is 0)
### **Returns**[](#id59)
NA
### **Example Code**[](#id60)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
VideoStreamOverlay::update() needs to be called for drawings to be shown on the video streams. “VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::drawText**[](#videostreamoverlay-drawtext)
### **Description**[](#id62)
Draw text on OSD frame buffer.
### **Syntax**[](#id63)
void drawText(int ch, int xmin, int ymin, const char *text_string, uint32_t color, int idx = 0);
### **Parameters**[](#id64)
ch: Channel to draw text on.
- 0
- 1
- 2
xmin: x coordinate of top left corner of text box.
ymin: y coordinate of top left corner of text box.
text_string: pointer to a character array containing the text to be displayed.
color: Color of the text.
idx: Layer index of OSD.
- 0 to 5 (Default value is 0)
### **Returns**[](#id65)
NA
### **Example Code**[](#id66)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
VideoStreamOverlay::update() needs to be called for drawings to be shown on the video streams. “VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::drawPlus**[](#videostreamoverlay-drawplus)
### **Description**[](#id68)
Draw “+” on OSD frame buffer.
### **Syntax**[](#id69)
void drawPlus(int ch, int x_center, int y_center, int L, int line_width, uint32_t color, int idx = 0);
### **Parameters**[](#id70)
ch: Channel to draw text on.
- 0
- 1
- 2
xmin: x coordinate of the center of the plus symbol.
ymin: y coordinate of the center of the plus symbol.
L:  Length of each arm of the plus symbol.
line width: Thickness of the lines of the plus symbol.
color: Color of the text.
idx: Layer index of OSD.
- 0 to 5 (Default value is 0)
### **Returns**[](#id71)
NA
### **Example Code**[](#id72)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
VideoStreamOverlay::update() needs to be called for drawings to be shown on the video streams. “VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::update**[](#videostreamoverlay-update)
### **Description**[](#id74)
Update OSD and display drawings on video streams.
### **Syntax**[](#id75)
void update(int ch, int idx = 0);
### **Parameters**[](#id76)
ch: Channel to display drawings.
- 0
- 1
- 2
idx: Layer index of OSD.
- 0 to 5 (Default value is 0)
### **Returns**[](#id77)
NA
### **Example Code**[](#id78)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::initOSDBitmapPos**[](#videostreamoverlay-initosdbitmappos)
### **Description**[](#id80)
Set image position on video stream.
### **Syntax**[](#id81)
void initOSDBitmapPos(osd_pict_st *bmp_info, int chn_id, uint32_t start_x, uint32_t start_y, uint32_t width, uint32_t height);
### **Parameters**[](#id82)
bmp_info: Pointer to osd_pict_st structure which contains information about an OSD image.
chn_id: Channel used.
start_x: x-coordinate for the starting position of the image on the video stream.
start_y: y-coordinate for the starting position of the bitmap on the video stream.
width: Width of the image
height: Height of the image
### **Returns**[](#id83)
NA
### **Example Code**[](#id84)
NA
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::initOSDBitmapBlk**[](#videostreamoverlay-initosdbitmapblk)
### **Description**[](#id85)
Set block index of image on video stream.
### **Syntax**[](#id86)
void initOSDBitmapBlk(osd_pict_st *bmp_info, int blk_idx, enum rts_osd2_blk_fmt blk_fmt, uint32_t clr_1bpp);
### **Parameters**[](#id87)
bmp_info: Pointer to osd_pict_st structure which contains information about an OSD image.
blk_idx: Block index for each image (Valid value 0-23).
blk_fmt: Specifies the format of the block.
clr_1bpp: Set the RGB color when format is RTS_OSD2_BLK_FMT_1BP.
### **Returns**[](#id88)
NA
### **Example Code**[](#id89)
NA
Note
“VideoStreamOverlay.h” must be included to use the class function. Each image requires setting a new block index.
## **VideoStreamOverlay::initOSDBitmapBuf**[](#videostreamoverlay-initosdbitmapbuf)
### **Description**[](#id90)
Set buffer containing image data and its length.
### **Syntax**[](#id91)
void initOSDBitmapBuf(osd_pict_st *bmp_info, uint8_t *buf, uint32_t buf_len);
### **Parameters**[](#id92)
bmp_info: Pointer to osd_pict_st structure which contains information about an OSD image.
buf: pointer to a buffer containing the raw image data
buf_len: The length of buffer, specifying the size of the data buffer in bytes.
### **Returns**[](#id93)
NA
### **Example Code**[](#id94)
NA
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::resizeWidth**[](#videostreamoverlay-resizewidth)
### **Description**[](#id95)
Get resized width of image for overlaying on a video stream.
### **Syntax**[](#id96)
int resizeWidth(int pict_width, int pict_scaling_up_factor, int pict_scaling_down_factor);
### **Parameters**[](#id97)
pict_width: The original width of the image.
pict_scaling_up_factor: The factor by which to scale up the width.
pict_scaling_down_factor: The factor by which to scale down the width.
### **Returns**[](#id98)
This function returns the calculated resized width.
### **Example Code**[](#id99)
Example: [VideoOSDImage](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/VideoOSDImage/VideoOSDImage.ino)
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::resizeHeight**[](#videostreamoverlay-resizeheight)
### **Description**[](#id100)
Get resized height of image for overlaying on a video stream.
### **Syntax**[](#id101)
int resizeHeight(int pict_height, int pict_scaling_up_factor, int pict_scaling_down_factor);
### **Parameters**[](#id102)
pict_height: The original height of the image.
pict_scaling_up_factor: The factor by which to scale up the height.
pict_scaling_down_factor: The factor by which to scale down the height.
### **Returns**[](#id103)
This function returns the calculated resized height.
### **Example Code**[](#id104)
Example: [VideoOSDImage](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/VideoOSDImage/VideoOSDImage.ino)
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::heapsizeCal**[](#videostreamoverlay-heapsizecal)
### **Description**[](#id106)
Get heapsize of an image given its resized dimensions and color format.
### **Syntax**[](#id107)
unsigned int heapsizeCal(int resize_width, int resize_height, rts_osd2_blk_fmt image_format);
### **Parameters**[](#id108)
resize_width: The resized width of an image.
resize_height: The height width of an image.
image_format: The color format of an image.
### **Returns**[](#id109)
This function returns the calculated heapsize as an unsigned int.
### **Example Code**[](#id110)
Example: [VideoOSDImage](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/VideoOSDImage/VideoOSDImage.ino)
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::drawImage**[](#videostreamoverlay-drawimage)
### **Description**[](#id112)
Draw image on OSD frame buffer.
### **Syntax**[](#id113)
void drawImage(int ch, unsigned char *osd_array[], osd_pict_st pict_osd_buffer, unsigned int heapsize, void *pict_name, int pict_width, int pict_height, rts_osd2_blk_fmt pict_format, int resize_width, int resize_height, int start_x, int start_y, int pict_blk_idx)
### **Parameters**[](#id114)
ch: Channel used to draw image on.
osd_array: A pointer array that use to hold overlay data for the image that will be drawn.
pict_osd_buffer: A structure contains metadata associated with the image.
heapsize: Calculated heap size necessary to store the image data.
pict_name: A  pointer that reference a name or identifier for the image.
pict_width: Original width of image.
pict_height: Original height of image.
pict_format: Color format of image.
resize_width: Resized width of image.
resize_height: Resized height of image.
start_x: starting x coordinate on the video stream where the image should be displayed.
start_y: starting y coordinate on the video stream where the image should be displayed.
pict_blk_idx: Block index for the image. (Valid value: 0-23)
### **Returns**[](#id115)
NA
### **Example Code**[](#id116)
Example: [VideoOSDImage](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/VideoOSDImage/VideoOSDImage.ino)
Note
“VideoStreamOverlay.h” must be included to use the class function.
## **VideoStreamOverlay::displayImage**[](#videostreamoverlay-displayimage)
### **Description**[](#id118)
Update OSD and display images on video streams.
### **Syntax**[](#id119)
void displayImage(int ch)
### **Parameters**[](#id120)
ch: Channel to display image.
### **Returns**[](#id121)
NA
### **Example Code**[](#id122)
Example: [VideoOSDImage](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/VideoOSDImage/VideoOSDImage.ino)
Note
“VideoStreamOverlay.h” must be included to use the class function. Each image requires setting a new block index.
[ Previous](Class%20VideoStream.html)
[Next ](Class%20WebSocketViewer.html)
[
](https://github.com/search?q=topic%3Aarduino+org%3AAmeba-AIoT&type=Repositories)
[
](https://www.youtube.com/@amebaiot7033)
[
](https://www.facebook.com/groups/amebaioten)
[
](https://www.facebook.com/groups/AmebaIoT)
[
](https://space.bilibili.com/457777430)
© Copyright 2026 Realtek Semiconductor Corp. All rights reserved.