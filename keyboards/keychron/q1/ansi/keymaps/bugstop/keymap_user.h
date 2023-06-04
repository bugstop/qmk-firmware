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

#include QMK_KEYBOARD_H

#pragma once

// clang-format off

enum layers{
    L_QWERTY,  // layer 1: qwerty layout, active if 'mac' is selected
    L_LIGHTS,  // layer 2: lights control and special keys
               //   ↑  buggy... not functioning when 'win' is selected
    L_COLEMAK, // layer 3: colemak layout, active if 'win' is selected
    L_CAPS,    // layer 4: [CAPS] shortcuts and macros
    L_RSFT,    // layer 5: [RSFT] shortcuts and macros
    L_BOTH,    // layer 6: [CAPS & RSFT]
};

enum custom_keycodes {
    KC_CSLOCK = QK_KB_0,
    KC_LSPO_L,
    KC_RCPC_L,
};

// clang-format on
