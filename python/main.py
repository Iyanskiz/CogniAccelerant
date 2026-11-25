# CogniAccelerant - week 1 test
# Lights each LED one at a time, then shows a growing bar on the LED matrix.
# If this works, Python and the sketch are talking over Bridge.

from arduino.app_utils import *
import time

COLORS = ["red", "blue", "yellow", "green"]  # LEDs on pins D2, D3, D4, D5
level = 1


def loop():
    global level

    # Flash each LED for half a second
    for i, color in enumerate(COLORS):
        print("Lighting", color)
        Bridge.call("set_led", i, True)
        time.sleep(0.5)
        Bridge.call("set_led", i, False)

    # Show the level on the matrix, then go up by one (the matrix is 13 wide)
    print("Level", level)
    Bridge.call("show_level", level)
    level = level + 1 if level < 13 else 1

    time.sleep(1)


App.run(user_loop=loop)
