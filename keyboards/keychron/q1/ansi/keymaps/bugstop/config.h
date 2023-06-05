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

// rgb
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE  133 // 255 * 188deg
#define RGB_MATRIX_DEFAULT_SAT  230 // 255 * 0.9
#define RGB_MATRIX_DEFAULT_VAL  255 // 255 * 1.0

// prevent macro loop
#define DYNAMIC_MACRO_NO_NESTING

// auto shift
#define AUTO_SHIFT_TIMEOUT 150
#define AUTO_SHIFT_TIMEOUT_PER_KEY
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_SPECIAL

// leader key
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350

// mouse keys
#define MK_3_SPEED
#define MK_C_OFFSET_0 2
#define MK_C_OFFSET_1 8
#define MK_C_OFFSET_2 32

// secure passcode
#define SECURE_IDLE_TIMEOUT 0
#define SECURE_UNLOCK_TIMEOUT 1500
#define SECURE_UNLOCK_SEQUENCE { { 3, 1 }, { 3, 2 }, { 3, 3 }, { 3, 4 } }
