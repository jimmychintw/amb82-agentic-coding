Buzzer Play Melody — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [PWM](index.html)
- Buzzer Play Melody
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/PWM/Buzzer Play Melody.rst)
# Buzzer Play Melody[](#buzzer-play-melody)
## Materials[](#materials)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- Buzzer x 1
## Example[](#example)
A sound is composed of volume, tone and timbre. Volume is determined by the amplitude of the sound wave. Tone is determined by the frequency of the sound wave. Timbre is determined by the waveform of the sound wave.
In this example, we use PWM to control the buzzer to emit sound with desired tone. As PWM outputs square wave, if we wish to emit tone C4 (frequency=262Hz), we have to make PWM to output square wave with wavelength 1/262 = 3.8ms:
[](../../../../_images/image01217.png)
We use PWM to output sound wave with different frequency, so as to play music by the buzzer.
Connect the buzzer to the PWM output pin shown in the following diagrams.
**AMB82 MINI** wiring diagram:
[](../../../../_images/image02210.png)
Open the example code in Examples -> AmebaAnalog -> PWM_BuzzerPlayMelody
Compile and upload to Ameba, press the reset button. Then you can hear the buzzer playing music.
## Code Reference[](#code-reference)
Ameba implement the tone() and noTone() API of Arduino:
[https://www.arduino.cc/en/Reference/Tone](https://www.arduino.cc/en/Reference/Tone)
[https://www.arduino.cc/en/Reference/NoTone](https://www.arduino.cc/en/Reference/NoTone)
In the sample code, we initiate a melody array, which stores the tones to make. Another array, noteDurations, contains the length of each tone, 4 represents quarter note (equals to 3000ms/4 = 750ms, and plus an extra 30% time pause), 8 represents eighth note.
[ Previous](index.html)
[Next ](Servo%20Control.html)
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