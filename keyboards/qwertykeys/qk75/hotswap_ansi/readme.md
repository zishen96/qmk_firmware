# qk75 - ANSI PCB

![qk75]()

A 75% made by Qwertykeys.

* Keyboard Maintainer: [Qwertykeys](https://github.com/owlab-git)
* Hardware Supported: qk75 ANSI PCB
* Hardware Availability: 

Make example for this keyboard (after setting up your build environment):
* `make qwertykeys/qk75/hotswap_ansi:default`
* `qmk compile -kb <keyboard> -km <keymap>`

Flashing example for this keyboard:

* `make qwertykeys/qk75/hotswap_ansi:default:flash`
* `qmk flash -kb <keyboard> <.bin file>`


## Bootloader 
    Hold down __`B`__ while plugging in the board
    or
    Press the physical reset button on the bottom side of the PCB (labeled SW1)

## Troubleshooting
### Flashing fails due to bootloader not detected or LIBUSB error:
* Run in bootloader mode
* Run Zadig to update firmware to install WinUSB driver (v6.1.7600.16385) 
* Flash the default .bin file

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
