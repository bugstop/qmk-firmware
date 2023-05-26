/* Copyright 2023 @ Muhan Li
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// bugstop keymap directory created in:
// ./qmk_firmware/keyboards/keychron/q1/rev_0100/keymaps/bugstop
// Compile a firmware with your new keymap by typing:
// qmk compile -kb keychron/q1/rev_0100 -km bugstop

#include QMK_KEYBOARD_H
#include "keymap_user.h"
#include "keymap_user.c"

#define KC_TASK  LGUI(KC_TAB)
#define KC_FLXP  LGUI(KC_E)
#define KC_MCTL  KC_MISSION_CONTROL
#define KC_LPAD  KC_LAUNCHPAD
#define KC_LANG  KC_SWITCH_LANG
#define KC_JBFMT KC_JB_FORMAT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_QWERTY_BASE] = LAYOUT_ansi_82(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,MO(L_LIGHTS),KC_LANG,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_DEL,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
LT(L_SHORTCUTS_A, KC_BSPC), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_PGDN,
        KC_LSFT_PO,         KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RCTL_PC,         KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                       KC_INS,   KC_HOME,  KC_END,             KC_LEFT,  KC_DOWN,  KC_RGHT
// win: KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                       KC_RALT,  MO(L_LIGHTS),       KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [L_NO_USE] = LAYOUT_ansi_82(
        KC_TRNS,            KC_BRID,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [L_COLEMAK_BASE] = LAYOUT_ansi_82(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,MO(L_LIGHTS),KC_LANG,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_DEL,
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
LT(L_SHORTCUTS_A, KC_BSPC), KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,  KC_ENT,             KC_PGDN,
        KC_LSFT_PO,         KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RCTL_PC,         KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                       KC_INS,   KC_HOME,  KC_END,             KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [L_SHORTCUTS_A] = LAYOUT_ansi_82(
        KC_TRNS,            KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  G(KC_Q),  G(KC_W),  G(KC_F),  G(KC_P),  G(KC_G),  G(KC_J),  G(KC_L),  G(KC_U),  G(KC_Y),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,            G(KC_A),  G(KC_R),  G(KC_S),  G(KC_T),  G(KC_D),  G(KC_H),  G(KC_N),  G(KC_E),  G(KC_I),  G(KC_O),  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,            G(KC_Z),  G(KC_X),  G(KC_C),  G(KC_V),  G(KC_B),  G(KC_K),  G(KC_M),  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_RCTL_PC,         KC_UP,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                G(KC_SPC),                    KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [L_SHORTCUTS_B] = LAYOUT_ansi_82(
        KC_TRNS,            KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  C(KC_Q),  C(KC_W),  C(KC_F),  C(KC_P),  C(KC_G),  C(KC_J),  C(KC_L),  C(KC_U),  C(KC_Y),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
LT(L_SHORTCUTS_C, KC_BSPC), C(KC_A),  C(KC_R),  C(KC_S),  C(KC_T),  C(KC_D),  C(KC_H),  C(KC_N),  C(KC_E),  C(KC_I),  C(KC_O),  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,            C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  C(KC_B),  C(KC_K),  C(KC_M),  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                A(KC_V),                      KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [L_SHORTCUTS_C] = LAYOUT_ansi_82(
        KC_TRNS,            KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [L_LIGHTS] = LAYOUT_ansi_82(
// win: KC_TRNS,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,
        KC_TRNS,            KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

};
