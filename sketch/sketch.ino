// CogniAccelerant sketch (runs on the STM32 chip)
// Python makes all the decisions. This file just does what Python asks:
// turn LEDs on or off, and draw on the LED matrix.

#include "Arduino_RouterBridge.h"
#include <Arduino_LED_Matrix.h>

// LED pins in order: red, blue, yellow, green
const int LED_PINS[4] = {2, 3, 4, 5};

Arduino_LED_Matrix matrix;
uint8_t frame[8 * 13];  // 8 rows x 13 columns, each 0 (off) to 7 (brightest)

// Python calls this to turn one LED on or off (led is 0 to 3)
void set_led(int led, bool on) {
  if (led < 0 || led > 3) return;
  digitalWrite(LED_PINS[led], on ? HIGH : LOW);
}

// Python calls this to show the level as a bar of lit columns (1 to 13)
void show_level(int level) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 13; col++) {
      frame[row * 13 + col] = (col < level) ? 7 : 0;
    }
  }
  matrix.draw(frame);
}

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }

  matrix.begin();
  matrix.setGrayscaleBits(3);  // brightness goes from 0 to 7
  matrix.clear();

  Bridge.begin();
  Bridge.provide_safe("set_led", set_led);
  Bridge.provide_safe("show_level", show_level);
}

void loop() {
  // Nothing here. The functions above run whenever Python calls them.
}
