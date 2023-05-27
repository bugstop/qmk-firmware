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

#pragma once

// clang-format off

enum layers{
    L_QWERTY_BASE,  // layer 1: qwerty layout, active if 'mac' is selected
    L_NO_USE,       // layer 2: DO NOT USE this layer: buggy... not functioning when 'win' is selected
    L_COLEMAK_BASE, // layer 3: colemak layout, active if 'win' is selected
    L_SHORTCUTS_A,  // layer 4: [CAPS] shotcuts and macros
    L_SHORTCUTS_B,  // layer 5: [RSFT] shotcuts and macros
    L_SHORTCUTS_C,  // layer 6: [CAPS & RSFT] shotcuts and macros
    L_LIGHTS,       // layer 7: lights control
};

enum custom_keycodes {
    KC_SWITCH_LANG = QK_KB_0,
    KC_LSFT_PO,
    KC_RCTL_PC,
    KC_JB_FORMAT,
};

// clang-format on
