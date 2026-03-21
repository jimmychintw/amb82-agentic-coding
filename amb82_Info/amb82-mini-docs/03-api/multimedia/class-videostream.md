Class VideoStream — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multimedia](index.html)
- Class VideoStream
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multimedia/Class VideoStream.rst)
# Class VideoStream[](#class-videostream)
## **CameraSetting Class**[](#camerasetting-class)
### **Description**[](#description)
A class used to configure parameters for the camera sensor.
### **Syntax**[](#syntax)
class CameraSetting
### **Members**[](#members)
|**Public Constructors**
|
|
| CameraSetting::CameraSetting
|
Constructs a CameraSetting object and
set the parameters needed for camera
sensor.
|
|
| **Public Methods**
|
|
| CameraSetting::setBrightness
|
Set the brightness value of the image.
|
|
| CameraSetting::getBrightness
|
Get the current brightness value.
|
|
| CameraSetting::setContrast
|
Set the contrast value of the image.
|
|
| CameraSetting::getContrast
|
Get the current contrast value.
|
|
| CameraSetting::setSaturation
|
Set the saturation value of the image.
|
|
| CameraSetting::getSaturation
|
Get the current saturation value.
|
|
| CameraSetting::setSharpness
|
Set the sharpness value of the image.
|
|
| CameraSetting::getSharpness
|
Get the current sharpness value.
|
|
| CameraSetting::setLDC
|
Enable or Disable Lens Distortion
Correction (LDC).
|
|
| CameraSetting::getLDC
|
Get the current LDC value.
|
|
| CameraSetting::setWDR
|
Enable or Disable WDR mode.
|
|
| CameraSetting::getWDR
|
Get current WDR mode.
|
|
| CameraSetting::setWDRLevel
|
Set WDR level.
|
|
| CameraSetting::getWDRLevel
|
Get current WDR level.
|
|
| CameraSetting::setExposureMode
|
Set Exposure mode in Auto or Manual
mode.
|
|
| CameraSetting::getExposureMode
|
Get current exposure mode.
|
|
| CameraSetting::setExposureTime
|
Set exposure time.
|
|
| CameraSetting::getExposureTime
|
Get current exposure time.
|
|
| CameraSetting::setAEGain
|
Set exposure gain value.
|
|
| CameraSetting::getAEGain
|
Get current exposure gain value.
|
|
| CameraSetting::setPowerLineFreq
|
Enable or Disable Power Line Frequency
(Anti-flicker mode).
|
|
| CameraSetting::getPowerLineFreq
|
Get current Power Line Frequency.
|
|
| CameraSetting::setAWB
|
Set White Balance mode in Auto or
Manual mode.
|
|
| CameraSetting::getAWB
|
Get current White Balance mode.
|
|
| CameraSetting::getWBTemp
|
Get current White Balance Temperature.
|
|
| CameraSetting::setRedBalance
|
Set red balance value.
|
|
| CameraSetting::getRedBalance
|
Get red balance value.
|
|
| CameraSetting::setBlueBalance
|
Set blue balance value.
|
|
| CameraSetting::getBlueBalance
|
Get blue balance value.
|
|
| CameraSetting::setGrayMode
|
Set Gray mode.
|
|
| CameraSetting::getGrayMode
|
Get current mode, gray or color.
|
|
| CameraSetting::setDayNightMode
|
Set Day or Night mode.
|
|
| CameraSetting::getDayNightMode
|
Get current mode, day, or night.
|
|
| CameraSetting::setMinFPS
|
Set minimum frame per second.
|
|
| CameraSetting::getMinFPS
|
Get minimum frame per second.
|
|
| CameraSetting::reset
|
Reset all the values to default value.
|
|
## **CameraSetting::setBrightness**[](#camerasetting-setbrightness)
### **Description**[](#id1)
Set the brightness value of the image.
### **Syntax**[](#id2)
void setBrightness (int value);
### **Parameters**[](#parameters)
value: Preferred brightness value.
- -64 to 64 (Default value is 0)
### **Returns**[](#returns)
NA
### **Example Code**[](#example-code)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getBrightness**[](#camerasetting-getbrightness)
### **Description**[](#id3)
Get the current brightness value.
### **Syntax**[](#id4)
void setBrightness (void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
NA
### **Example Code**[](#id7)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setContrast**[](#camerasetting-setcontrast)
### **Description**[](#id9)
Set the contrast value of the image.
### **Syntax**[](#id10)
void setContrast (int value);
### **Parameters**[](#id11)
value: Preferred contrast value.
- 0 to 100 (Default value is 50)
### **Returns**[](#id12)
NA
### **Example Code**[](#id13)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getContrast**[](#camerasetting-getcontrast)
### **Description**[](#id15)
Get the current contrast value.
### **Syntax**[](#id16)
void getContrast (void);
### **Parameters**[](#id17)
NA
### **Returns**[](#id18)
NA
### **Example Code**[](#id19)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setSaturation**[](#camerasetting-setsaturation)
### **Description**[](#id21)
Set the saturation value of the image.
### **Syntax**[](#id22)
void setSaturation (int value);
### **Parameters**[](#id23)
value: Preferred saturation value.
- 0 to 100 (Default value is 50)
### **Returns**[](#id24)
NA
### **Example Code**[](#id25)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getSaturation**[](#camerasetting-getsaturation)
### **Description**[](#id27)
Get the current saturation value.
### **Syntax**[](#id28)
void getSaturation (void);
### **Parameters**[](#id29)
NA
### **Returns**[](#id30)
NA
### **Example Code**[](#id31)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setSharpness**[](#camerasetting-setsharpness)
### **Description**[](#id33)
Set the sharpness value of the image.
### **Syntax**[](#id34)
void setSharpness (int value);
### **Parameters**[](#id35)
value: Preferred sharpness value.
- 0 to 100 (Default value is 50)
### **Returns**[](#id36)
NA
### **Example Code**[](#id37)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getSharpness**[](#camerasetting-getsharpness)
### **Description**[](#id39)
Get the current sharpness value.
### **Syntax**[](#id40)
void getSharpness (void);
### **Parameters**[](#id41)
NA
### **Returns**[](#id42)
NA
### **Example Code**[](#id43)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setLDC**[](#camerasetting-setldc)
### **Description**[](#id45)
Enable or Disable Lens Distortion Correction (LDC).
### **Syntax**[](#id46)
void setLDC (int enable);
### **Parameters**[](#id47)
enable: Enable or Disable LDC.
- 0 (Disabled. Default value)
- 1 (Enabled)
### **Returns**[](#id48)
NA
### **Example Code**[](#id49)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getLDC**[](#camerasetting-getldc)
### **Description**[](#id51)
Get the current LDC value.
### **Syntax**[](#id52)
void getLDC (void);
### **Parameters**[](#id53)
NA
### **Returns**[](#id54)
NA
### **Example Code**[](#id55)
Example: [ISPControl/ImageTuning](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/ImageTuning/ImageTuning.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setWDR**[](#camerasetting-setwdr)
### **Description**[](#id57)
Enable or Disable WDR mode.
### **Syntax**[](#id58)
void setWDR (int enable);
### **Parameters**[](#id59)
enable: Preferred WDR mode. If WDR mode is enabled, Manual or Auto mode can be chosen.
- 0 (Disabled. Default value)
- 1 (Manual)
- 2 (Auto)
### **Returns**[](#id60)
NA
### **Example Code**[](#id61)
Example: [ISPControl/WideDynamicRange](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WideDynamicRange/WideDynamicRange.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getWDR**[](#camerasetting-getwdr)
### **Description**[](#id62)
Get current WDR mode.
### **Syntax**[](#id63)
void getWDR (void);
### **Parameters**[](#id64)
NA
### **Returns**[](#id65)
NA
### **Example Code**[](#id66)
Example: [ISPControl/WideDynamicRange](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WideDynamicRange/WideDynamicRange.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setWDRLevel**[](#camerasetting-setwdrlevel)
### **Description**[](#id68)
Set WDR level.
### **Syntax**[](#id69)
void setWDRLevel (int value);
### **Parameters**[](#id70)
value: Preferred WDR level.
- 50 - 100 (Default value is 50)
### **Returns**[](#id71)
NA
### **Example Code**[](#id72)
Example: [ISPControl/WideDynamicRange](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WideDynamicRange/WideDynamicRange.ino)
Note
“VideoStream.h” must be included to use the class function. WDR level can only be modified, and changes can be seen on image if WDR mode is set to manual mode before calling setWDRLevel() function.
## **CameraSetting::getWDRLevel**[](#camerasetting-getwdrlevel)
### **Description**[](#id74)
Get current WDR level.
### **Syntax**[](#id75)
void getWDRLevel (void);
### **Parameters**[](#id76)
NA
### **Returns**[](#id77)
NA
### **Example Code**[](#id78)
Example: [ISPControl/WideDynamicRange](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WideDynamicRange/WideDynamicRange.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setExposureMode**[](#camerasetting-setexposuremode)
### **Description**[](#id80)
Set Exposure mode in Auto or Manual mode.
### **Syntax**[](#id81)
void setExposureMode (int enable);
### **Parameters**[](#id82)
enable: Enable exposure mode in Manual or Auto mode.
- 0 (Manual)
- 1 (Auto. Default value)
### **Returns**[](#id83)
NA
### **Example Code**[](#id84)
Example: [ISPControl/Exposure](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Exposure/Exposure.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getExposureMode**[](#camerasetting-getexposuremode)
### **Description**[](#id85)
Get current exposure mode.
### **Syntax**[](#id86)
void getExposureMode (void);
### **Parameters**[](#id87)
NA
### **Returns**[](#id88)
NA
### **Example Code**[](#id89)
Example: [ISPControl/Exposure](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Exposure/Exposure.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setExposureTime**[](#camerasetting-setexposuretime)
### **Description**[](#id91)
Set exposure time.
### **Syntax**[](#id92)
void setExposureTime (int time);
### **Parameters**[](#id93)
time: Preferred exposure time in us.
- time <= 33333
### **Returns**[](#id94)
NA
### **Example Code**[](#id95)
Example: [ISPControl/Exposure](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Exposure/Exposure.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getExposureTime**[](#camerasetting-getexposuretime)
### **Description**[](#id97)
Get current exposure time.
### **Syntax**[](#id98)
void getExposureTime (void);
### **Parameters**[](#id99)
NA
### **Returns**[](#id100)
NA
### **Example Code**[](#id101)
Example: [ISPControl/Exposure](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Exposure/Exposure.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setAEGain**[](#camerasetting-setaegain)
### **Description**[](#id103)
Set exposure gain value.
### **Syntax**[](#id104)
void setAEGain (int value);
### **Parameters**[](#id105)
value: Preferred exposure gain.
- 256 to 32768
### **Returns**[](#id106)
NA
### **Example Code**[](#id107)
Example: [ISPControl/Exposure](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Exposure/Exposure.ino)
Note
“VideoStream.h” must be included to use the class function. AE gain can only be modified, and changes can be seen on image if Exposure mode is set to manual mode before calling setAEGain() function.
## **CameraSetting::getAEGain**[](#camerasetting-getaegain)
### **Description**[](#id109)
Get current exposure gain value.
### **Syntax**[](#id110)
void getAEGain (void);
### **Parameters**[](#id111)
NA
### **Returns**[](#id112)
NA
### **Example Code**[](#id113)
Example: [ISPControl/Exposure](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Exposure/Exposure.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setPowerLineFreq**[](#camerasetting-setpowerlinefreq)
### **Description**[](#id115)
Enable or Disable Power Line Frequency (Anti-flicker mode).
### **Syntax**[](#id116)
void setPowerLineFreq (int enable);
### **Parameters**[](#id117)
enable: Enable or disable power line frequency. If power line frequency is enabled, power line frequency can be set as auto or choose from different frequencies (50Hz, 60Hz).
- 0 (Disable)
- 1 (50Hz)
- 2 (60Hz)
- 3 (Auto. Default value)
### **Returns**[](#id118)
NA
### **Example Code**[](#id119)
Example: [ISPControl/Exposure](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Exposure/Exposure.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getPowerLineFreq**[](#camerasetting-getpowerlinefreq)
### **Description**[](#id121)
Get current Power Line Frequency.
### **Syntax**[](#id122)
void getPowerLineFreq (void);
### **Parameters**[](#id123)
NA
### **Returns**[](#id124)
NA
### **Example Code**[](#id125)
Example: [ISPControl/Exposure](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Exposure/Exposure.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setAWB**[](#camerasetting-setawb)
### **Description**[](#id127)
Set White Balance mode in Auto or Manual mode.
### **Syntax**[](#id128)
void setAWB (int enable);
### **Parameters**[](#id129)
enable: Enable white balance mode in Manual or Auto mode.
- 0 (Manual Temperature)
- 1 (Auto. Default value)
### **Returns**[](#id130)
NA
### **Example Code**[](#id131)
Example: [ISPControl/WhiteBalance](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WhiteBalance/WhiteBalance.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getAWB**[](#camerasetting-getawb)
### **Description**[](#id132)
Get current White Balance mode.
### **Syntax**[](#id133)
void getAWB (void);
### **Parameters**[](#id134)
NA
### **Returns**[](#id135)
NA
### **Example Code**[](#id136)
Example: [ISPControl/WhiteBalance](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WhiteBalance/WhiteBalance.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getWBTemp**[](#camerasetting-getwbtemp)
### **Description**[](#id138)
Get current White Balance Temperature.
### **Syntax**[](#id139)
void getWBTemp (void);
### **Parameters**[](#id140)
NA
### **Returns**[](#id141)
NA
### **Example Code**[](#id142)
Example: [ISPControl/WhiteBalance](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WhiteBalance/WhiteBalance.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setRedBalance**[](#camerasetting-setredbalance)
### **Description**[](#id144)
Set red balance value.
### **Syntax**[](#id145)
void setRedBalance (int value);
### **Parameters**[](#id146)
value: Preferred red balance value based on 256.
- 256 to 2047
### **Returns**[](#id147)
NA
### **Example Code**[](#id148)
Example: [ISPControl/WhiteBalance](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WhiteBalance/WhiteBalance.ino)
Note
“VideoStream.h” must be included to use the class function. Red Balance value can only be modified, and changes can be seen on image if white balance mode is set to manual mode before calling setRedBalance() function.
## **CameraSetting::getRedBalance**[](#camerasetting-getredbalance)
### **Description**[](#id150)
Get current red balance value.
### **Syntax**[](#id151)
void getRedBalance (void);
### **Parameters**[](#id152)
NA
### **Returns**[](#id153)
NA
### **Example Code**[](#id154)
Example: [ISPControl/WhiteBalance](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WhiteBalance/WhiteBalance.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setBlueBalance**[](#camerasetting-setbluebalance)
### **Description**[](#id156)
Set blue balance value.
### **Syntax**[](#id157)
void setBlueBalance (int value);
### **Parameters**[](#id158)
value: Preferred blue balance value based on 256.
- 256 to 2047
### **Returns**[](#id159)
NA
### **Example Code**[](#id160)
Example: [ISPControl/WhiteBalance](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WhiteBalance/WhiteBalance.ino)
Note
“VideoStream.h” must be included to use the class function. Blue Balance value can only be modified, and changes can be seen on image if white balance mode is set to manual mode before calling setBlueBalance() function.
## **CameraSetting::getBlueBalance**[](#camerasetting-getbluebalance)
### **Description**[](#id162)
Get current blue balance value.
### **Syntax**[](#id163)
void getBlueBalance (void);
### **Parameters**[](#id164)
NA
### **Returns**[](#id165)
NA
### **Example Code**[](#id166)
Example: [ISPControl/WhiteBalance](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/WhiteBalance/WhiteBalance.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setGrayMode**[](#camerasetting-setgraymode)
### **Description**[](#id168)
Set Gray mode.
### **Syntax**[](#id169)
void setGrayMode (int enable);
### **Parameters**[](#id170)
enable: Enable gray mode.
- 0 (Color mode. Default value)
- 1 (Gray mode)
### **Returns**[](#id171)
NA
### **Example Code**[](#id172)
Example: [ISPControl/Mode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Mode/Mode.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getGrayMode**[](#camerasetting-getgraymode)
### **Description**[](#id173)
Get current mode, gray or color.
### **Syntax**[](#id174)
void getGrayMode (void);
### **Parameters**[](#id175)
NA
### **Returns**[](#id176)
NA
### **Example Code**[](#id177)
Example: [ISPControl/Mode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Mode/Mode.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setDayNightMode**[](#camerasetting-setdaynightmode)
### **Description**[](#id179)
Set Day or Night mode.
### **Syntax**[](#id180)
void setDayNightMode (int enable);
### **Parameters**[](#id181)
enable: Enable day or night mode.
- 0 (Day mode. Default value)
- 1 (Night mode)
### **Returns**[](#id182)
NA
### **Example Code**[](#id183)
Example: [ISPControl/Mode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Mode/Mode.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getDayNightMode**[](#camerasetting-getdaynightmode)
### **Description**[](#id185)
Get current mode, day or night.
### **Syntax**[](#id186)
void getDayNightMode (void);
### **Parameters**[](#id187)
NA
### **Returns**[](#id188)
NA
### **Example Code**[](#id189)
Example: [ISPControl/Mode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Mode/Mode.ino)
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::setMinFPS**[](#camerasetting-setminfps)
### **Description**[](#id191)
Set the minimum frame per second of sensor.
### **Syntax**[](#id192)
void setMinFPS (int value);
### **Parameters**[](#id193)
value: preferred minimum frame per second (range: 1 to 30)
### **Returns**[](#id194)
NA
### **Example Code**[](#id195)
NA
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::getMinFPS**[](#camerasetting-getminfps)
### **Description**[](#id196)
Get the minimum frame per second of sensor.
### **Syntax**[](#id197)
void getMinFPS (void);
### **Parameters**[](#id198)
NA
### **Returns**[](#id199)
NA
### **Example Code**[](#id200)
NA
Note
“VideoStream.h” must be included to use the class function.
## **CameraSetting::reset**[](#camerasetting-reset)
### **Description**[](#id201)
Reset all the values to default value.
### **Syntax**[](#id202)
void reset (void);
### **Parameters**[](#id203)
NA
### **Returns**[](#id204)
NA
### **Example Code**[](#id205)
Example: [ISPControl/Mode](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/ISPControl/Mode/Mode.ino)
Note
“VideoStream.h” must be included to use the class function.
## **VideoSetting Class**[](#videosetting-class)
### **Description**[](#id207)
A class used to configure parameters for video streams.
### **Syntax**[](#id208)
class VideoSetting
### **Members**[](#id209)
| **Public Constructors**
|
|
| VideoSetting::VideoSetting
|
Constructs a VideoSetting object and
set the parameters needed for video
streams.
|
|
| **Public Methods**
|
|
| VideoSetting::setBitrate
|
Configure bitrate for H264 and H265
video encoder.
|
|
| VideoSetting::setJpegQuality
|
Configure quality level for JPEG
snapshots.
|
|
| VideoSetting::setRotation
|
Configure orientation for H264, H265
video and JPEG encoders.
|
|
| VideoSetting::width
|
Get current configured video stream
width.
|
|
| VideoSetting::height
|
Get current configured video stream
height.
|
|
| VideoSetting::fps
|
Get current configured video stream fps
(frame per second).
|
|
## **VideoSetting::VideoSetting**[](#videosetting-videosetting)
### **Description**[](#id210)
Constructs a VideoSetting object and sets the parameters needed for video streams, such as resolution, frame rate per second (fps), bit rate per second (bps), encoder type.
### **Syntax**[](#id211)
VideoSetting(uint8_t preset);
VideoSetting(uint8_t resolution, uint8_t fps, uint8_t encoder, uint8_t snapshot);
VideoSetting(uint16_t w, uint16_t h, uint8_t fps, uint8_t encoder, uint8_t snapshot);
### **Parameters**[](#id212)
preset: Select one out of 3 preset video stream settings.
- 0 (Default value)
- 1
- 2
resolution: Video resolution.
- VIDEO_HD
- VIDEO_FHD
fps: Frame rate in frames per second.
encoder: Video encoder format to use.
- VIDEO_HEVC
- VIDEO_H264
- VIDEO_JPEG
snapshot: Enable or disable snapshot function.
w: Width in pixels.
h: Height in pixels.
### **Returns**[](#id213)
NA
### **Example Code**[](#id214)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“VideoStream.h” must be included to use the class function.
Preset configurations:
**Preset 0:**
resolution: VIDEO_FHD
fps: 30
bps: 2 * 1024 * 1024
encoder: VIDEO_H264
snapshot: 0
**Preset 1:**
resolution: VIDEO_HD
fps: 30
bps: 2 * 1024 * 1024
encoder: VIDEO_H264
snapshot: 0
**Preset 2:**
resolution: VIDEO_FHD
fps: 30
bps: 2 * 1024 * 1024
encoder: VIDEO_JPEG
snapshot: 0
## **VideoSetting::setBitrate**[](#videosetting-setbitrate)
### **Description**[](#id215)
Configure bitrate for H264 and H265 video encoder.
### **Syntax**[](#id216)
void setBitrate(uint32_t bitrate);
### **Parameters**[](#id217)
bitrate: desired video encoder bitrate. Values range from 1Mbps (1024 * 1024) to 50Mbps (50 * 1024 * 1024).
- 1 to 50 (Default value is 4Mbps)
### **Returns**[](#id218)
NA
### **Example Code**[](#id219)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“VideoStream.h” must be included to use the class function. The default value of 4Mbps is a suitable balance of video quality and file size. For RTSP streaming, it is recommended that the bitrate is lowered to 2Mbps to account for possible network congestion.
## **VideoSetting::setJpegQuality**[](#videosetting-setjpegquality)
### **Description**[](#id221)
Configure quality level for JPEG snapshots.
### **Syntax**[](#id222)
void setJpegQuality(uint8_t quality);
### **Parameters**[](#id223)
quality: desired JPEG image quality level.
- 1 to 9 (Worst to best. Default value is 5)
### **Returns**[](#id224)
NA
### **Example Code**[](#id225)
NA
Note
“VideoStream.h” must be included to use the class function. A lower quality results in a reduced file size, while a quality level of 9 may result in large file sizes without a significant improvements in image quality.
## **VideoSetting::setRotation**[](#videosetting-setrotation)
### **Description**[](#id226)
Configure orientation for H264, H265 video and JPEG encoders.
### **Syntax**[](#id227)
void setRotation(int angle);
### **Parameters**[](#id228)
angle: desired rotation angle represented by numerical values.
- 0 (No rotation. Default value)
- 1 (90 degree to right)
- 2 (90 degree to left)
- 3 (180 degree)
### **Returns**[](#id229)
NA
### **Example Code**[](#id230)
NA
Note
“VideoStream.h” must be included to use the class function.
## **VideoSetting::width**[](#videosetting-width)
### **Description**[](#id231)
Get current configured video stream width.
### **Syntax**[](#id232)
uint16_t width(void);
### **Parameters**[](#id233)
NA
### **Returns**[](#id234)
This function returns the current configured video stream width.
### **Example Code**[](#id235)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“VideoStream.h” must be included to use the class function.
## **VideoSetting::height**[](#videosetting-height)
### **Description**[](#id236)
Get current configured video stream height.
### **Syntax**[](#id237)
uint16_t height(void);
### **Parameters**[](#id238)
NA
### **Returns**[](#id239)
This function returns the current configured video stream height.
### **Example Code**[](#id240)
Example: [MotionDetection/LoopPostProcessing](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/MotionDetection/LoopPostProcessing/LoopPostProcessing.ino)
Note
“VideoStream.h” must be included to use the class function.
## **VideoSetting::fps**[](#videosetting-fps)
### **Description**[](#id242)
Get current configured video stream fps (frame per second).
### **Syntax**[](#id243)
uint16_t fps(void);
### **Parameters**[](#id244)
NA
### **Returns**[](#id245)
This function returns the current configured video stream fps.
### **Example Code**[](#id246)
NA
Note
“VideoStream.h” must be included to use the class function.
## **Video Class**[](#video-class)
### **Description**[](#id247)
A class used to configure and initialize the camera to generate video data streams.
### **Syntax**[](#id248)
class Video
### **Members**[](#id249)
| **Public Constructors**
|
|
| Video::Video
|
Construct a Video object.
|
|
| **Public Methods**
|
|
| Video::configVideoChannel
|
Configure video stream channel.
|
|
| Video::camInit
|
Initialization of camera sensor using
existing configurations.
|
|
| Video::camDeinit
|
Deinitialization of camera sensor
|
|
| Video::videoInit
|
Initialization of video streams using
existing configurations.
|
|
| Video::videoDeinit
|
Deinitialization of video stream module
for a specific channel.
|
|
| Video::channelBegin
|
Start video streaming on a specific
channel.
|
|
| Video::channelEnd
|
Stop video streaming on a specific
channel.
|
|
| Video::getStream
|
Get video data stream to provide as an
input for other data stream consumers.
|
|
| Video::getImage
|
Enable snapshot function.
|
|
| Video::setFPS
|
Set camera video max FPS.
|
|
| Video::printInfo
|
Print out current configuration of
video channels.
|
|
| Video::videostream_status
|
Retrieve video stream module contents
from specific channel and pass for
checking on UVC connection status.
|
|
| Video::setQLen
|
Set camera video max queue length.
|
|
| Video::cameraOpenStatus
|
Camera sensor connection status
check after video open.
|
|
## **Video::configVideoChannel**[](#video-configvideochannel)
### **Description**[](#id250)
Configure video stream channel parameters using VideoSetting class object.
### **Syntax**[](#id251)
void configVideoChannel(int ch, VideoSetting& config);
### **Parameters**[](#id252)
ch: Channel to configure.
- 0
- 1
- 2
config: VideoSetting object.
### **Returns**[](#id253)
NA
### **Example Code**[](#id254)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“VideoStream.h” must be included to use the class function.
## **Video::camInit**[](#video-caminit)
### **Description**[](#id256)
Initialize camera sensor using configuration from CameraSetting object.
### **Syntax**[](#id257)
void cameraInit(CameraSetting& config);
### **Parameters**[](#id258)
config: CameraSetting object.
### **Returns**[](#id259)
NA
### **Example Code**[](#id260)
NA
Note
“VideoStream.h” must be included to use the class function.
## **Video::camDeinit**[](#video-camdeinit)
### **Description**[](#id261)
Deinitialize camera sensor.
### **Syntax**[](#id262)
void cameraDeinit(void);
### **Parameters**[](#id263)
NA
### **Returns**[](#id264)
NA
### **Example Code**[](#id265)
NA
Note
“VideoStream.h” must be included to use the class function.
## **Video::videoInit**[](#video-videoinit)
### **Description**[](#id266)
Initialization of video streams from camera using existing configurations.
### **Syntax**[](#id267)
void videoInit(void);
### **Parameters**[](#id268)
NA
### **Returns**[](#id269)
NA
### **Example Code**[](#id270)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“VideoStream.h” must be included to use the class function.
## **Video::videoDeinit**[](#video-videodeinit)
### **Description**[](#id272)
Deinitialization of all video streams.
### **Syntax**[](#id273)
void videoDeinit(void);
### **Parameters**[](#id274)
NA
### **Returns**[](#id275)
NA
### **Example Code**[](#id276)
NA
Note
“VideoStream.h” must be included to use the class function.
## **Video::channelBegin**[](#video-channelbegin)
### **Description**[](#id277)
Start video streaming on a specific channel.
### **Syntax**[](#id278)
void channelBegin(int ch);
### **Parameters**[](#id279)
ch: channel to start streaming. Default channel is 0.
### **Returns**[](#id280)
NA
### **Example Code**[](#id281)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“VideoStream.h” must be included to use the class function.
## **Video::channelEnd**[](#video-channelend)
### **Description**[](#id283)
Stop video streaming on a specific channel.
### **Syntax**[](#id284)
void channelEnd(int ch);
### **Parameters**[](#id285)
ch: channel to stop streaming. Default channel is 0.
### **Returns**[](#id286)
NA
### **Example Code**[](#id287)
NA
Note
“VideoStream.h” must be included to use the class function.
## **Video::getStream**[](#video-getstream)
### **Description**[](#id288)
Get video data stream to provide as an input for other data stream consumers.
### **Syntax**[](#id289)
MMFModule getStream(int ch);
### **Parameters**[](#id290)
ch: channel to get data stream of. Default channel is 0.
### **Returns**[](#id291)
This function returns the video data stream.
### **Example Code**[](#id292)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“VideoStream.h” must be included to use the class function.
## **Video::getImage**[](#video-getimage)
### **Description**[](#id294)
Take a snapshot.
### **Syntax**[](#id295)
void getImage(int ch, uint32_t* addr, uint32_t* len);
### **Parameters**[](#id296)
ch: Video stream channel to take a snapshot from.
addr: A pointer to a 32-bit unsigned integer to store the image address.
len: A pointer to a 32-bit unsigned integer to store the image length.
### **Returns**[](#id297)
NA
### **Example Code**[](#id298)
Example: [CaptureJPEG/HTTPDisplayJPEG](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/CaptureJPEG/HTTPDisplayJPEG/HTTPDisplayJPEG.ino)
Note
“VideoStream.h” must be included to use the class function.
## **Video::setFPS**[](#video-setfps)
### **Description**[](#id299)
Set camera video max FPS.
### **Syntax**[](#id300)
void setFPS(int fps);
### **Parameters**[](#id301)
fps: max frame rate in frames per second for camera.
### **Returns**[](#id302)
NA
### **Example Code**[](#id303)
NA
Note
“VideoStream.h” must be included to use the class function.
## **Video::printInfo**[](#video-printinfo)
### **Description**[](#id304)
Print out current configuration of video channels.
### **Syntax**[](#id305)
void printInfo(void);
### **Parameters**[](#id306)
NA
### **Returns**[](#id307)
NA
### **Example Code**[](#id308)
Example: [StreamRTSP/VideoOnly](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/Multimedia/examples/StreamRTSP/VideoOnly/VideoOnly.ino)
Note
“VideoStream.h” must be included to use the class function.
## **Video::videostream_status**[](#video-videostream-status)
### **Description**[](#id310)
Retrieve video stream module contents from specific channel and pass for checking on UVC connection status.
### **Syntax**[](#id311)
int videostream_status(int ch);
### **Parameters**[](#id312)
ch: Channel to configure.
- 0
- 1
- 2
### **Returns**[](#id313)
This function returns 1 if the UVC device is connected to PC, 0 otherwise.
### **Example Code**[](#id314)
Example: [UVCDObjectDetectionLoop](https://github.com/Ameba-AIoT/ameba-arduino-pro2/blob/dev/Arduino_package/hardware/libraries/NeuralNetwork/examples/UVCDObjectDetectionLoop/UVCDObjectDetectionLoop.ino)
Note
“VideoStream.h” must be included to use the class function.
## **Video::setQLen**[](#video-setqlen)
### **Description**[](#id315)
Set camera video max queue length. Use it before process “Video::channelBegin”.
### **Syntax**[](#id316)
void setQLen(int ch, int len);
### **Parameters**[](#id317)
ch: Channel to configure.
- 0
- 1
- 2
len: The queue length.
- 15 * 3
### **Returns**[](#id318)
NA
### **Example Code**[](#id319)
NA
Note
“VideoStream.h” must be included to use the class function.
## **Video::cameraOpenStatus**[](#video-cameraopenstatus)
### **Description**[](#id320)
For video open status check to verify camera sensor connection. Use it after calling “Video::channelBegin”.
### **Syntax**[](#id321)
int cameraOpenStatus(void);
### **Parameters**[](#id322)
NA
### **Returns**[](#id323)
0: No video opened, check sensor connection
1: Video is opened
### **Example Code**[](#id324)
NA
Note
“VideoStream.h” must be included to use the class function.
[ Previous](Class%20StreamIO.html)
[Next ](Class%20VideoStreamOverlay.html)
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