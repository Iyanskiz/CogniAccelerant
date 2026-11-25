# CogniAccelerant

An adaptive Simon-style memory game on the Arduino UNO Q. Players repeat light and sound sequences using hand gestures and capacitive touch pads instead of buttons. The difficulty adjusts as they play, and each session logs memory span, accuracy and reaction time to a progress dashboard.

## How it's split up

- `python/main.py` runs on the UNO Q's Linux side. It decides what happens.
- `sketch/sketch.ino` runs on the STM32 chip. It controls the LEDs and the LED matrix when Python asks.
- The two talk to each other over Bridge.

## Week 1 test

Wiring (mini breadboard):

| LED | Pin |
| --- | --- |
| Red | D2 |
| Blue | D3 |
| Yellow | D4 |
| Green | D5 |

Each LED goes through its own resistor to GND.

To run it:

1. Open Arduino App Lab and create a new app.
2. Copy in `app.yaml`, `python/main.py`, `sketch/sketch.ino` and `sketch/sketch.yaml`.
3. Click Run.

What you should see: each LED lights up for half a second (red, blue, yellow, green), then a bar on the LED matrix grows by one column. The App Lab console prints which LED is on and the current level.
