# Quantum Mechanical Keyboard Firmware

This repo is for maintaining my personal keyboard firmware.

Please note that I am using the [Colemak](https://colemak.com/) keyboard layout.

## Build Firmware

Firmwares are built automatically using [GitHub Actions](https://github.com/features/actions). To make your own firmware, you may want to check out [this script](https://github.com/bugstop/qmk-firmware/blob/main/.github/workflows/build_firmware.yml) to config GitHub Actions, which runs both on Ubuntu and MacOS. The firmware size differs slightly on different platforms, and I guess it is because of the x86 and arm architecture. Then, use [QMK Toolbox](https://github.com/qmk/qmk_toolbox) to flash the firmware to keyboards.

## Keyboard Models

### [Keychron Q1](https://www.keychron.com/products/keychron-q1)

**QMK Files:** [ANSI Keymaps](https://github.com/bugstop/qmk-firmware/tree/Keychron-Q1/keyboards/keychron/q1/ansi/keymaps/bugstop), latest firmware can be downloaded [here](https://github.com/bugstop/qmk-firmware/actions/workflows/build_in_docker.yml).<br>
Flash information: ATmega32U4, `qmk_keychron_q1_*.hex`

### [Keychron K3 Pro](https://www.keychron.com/collections/all-keyboards/products/keychron-k3-pro-qmk-via-wireless-custom-mechanical-keyboard)

**QMK Files:** [ANSI Keymaps (RGB version)](https://github.com/bugstop/qmk-firmware/tree/Keychron-K3Pro/keyboards/keychron/k3_pro/ansi/rgb/keymaps/bugstop), latest firmware can be downloaded [here](https://github.com/bugstop/qmk-firmware/actions/workflows/build_on_macos.yml).<br>
Flash information: STM32L432, `qmk_keychron_q3pro_*.bin`

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
