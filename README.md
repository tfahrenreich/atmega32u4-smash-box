# atmega32u4-smash-box
in `.platformio/platforms/atmelavr/builder/frameworks/arduino.py`
```
   # replace lines 63-64
        ("USB_VID", board.get("build.hwids")[0][0]),
        ("USB_PID", board.get("build.hwids")[0][1]),
    # with
        ("USB_VID", board.get("build.hwids")[0][0]),
        ("USB_PID", board.get("build.hwids")[0][1]),
```