/*
  LED Blink - 閃燈範例
  控制開發板上的藍色 LED 閃爍

  硬體：AMB82-MINI
  LED： D23 (藍色 LED，LED_BUILTIN)
*/

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}
