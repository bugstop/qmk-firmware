# Quantum Mechanical Keyboard Firmware

This repo is for maintaining my personal keyboard firmware.

Please note that I am using the [Colemak](https://colemak.com/) keyboard layout.

## Firmware Files

Firmware are built automatically using [GitHub Actions](https://github.com/features/actions). Latest files can be downloaded [here](https://github.com/bugstop/qmk-firmware/actions/workflows/build_in_docker.yml).

To make your own firmware, you may want to check out [this script](https://github.com/bugstop/qmk-firmware/blob/main/.github/workflows/build_firmware.yml) to run GitHub Actions. Then, use [QMK Toolbox](https://github.com/qmk/qmk_toolbox) to flash the firmware to keyboards.

## Keyboard Models

### [Keychron Q1](https://www.keychron.com/products/keychron-q1)

Layout: [ANSI Keymaps](https://github.com/bugstop/qmk-firmware/tree/Keychron-Q1/keyboards/keychron/q1/ansi/keymaps/bugstop)<br>
Flash information: MCU ATmega32U4, `keychron_q1_ansi_bugstop_*.hex`

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
