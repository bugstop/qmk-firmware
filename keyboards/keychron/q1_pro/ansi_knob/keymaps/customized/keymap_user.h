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
    L_QWERTY,      // layer 1: qwerty layout, active if 'mac' is selected
    L_LIGHTS,      // layer 2: lights control and special keys
    L_COLEMAK,     // layer 3: colemak layout, active if 'win' is selected
    L_CAPS,        // layer 4: [CAPS] shortcuts and macros
    L_RSFT,        // layer 5: [RSFT] shortcuts and macros
    L_BOTH,        // layer 6: [CAPS & RSFT]
    L_VIMRC,       // layer 7: some vim codes from my vimrc
    L_MOUSE,       // layer 8: mouse control
    L_MOUSE_INPUT, // layer 9: mouse mode input
};

enum custom_keycodes {
    MY_LANG_LOCK = QK_KB_0,
    MY_MO_LSPO,
    MY_MO_RCPC,
};

// clang-format on
