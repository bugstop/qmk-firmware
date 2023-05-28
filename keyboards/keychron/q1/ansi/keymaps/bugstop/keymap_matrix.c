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

#include "keymap_user.c"

// for rgb indicator when unlocking
uint16_t SECURE_UNLOCK_timer  = 0;
bool     SECURE_UNLOCK_tapped = false;

void scan_secure_timer(void) {
    if (SECURE_UNLOCK_tapped) {
        if (timer_elapsed(SECURE_UNLOCK_timer) > SECURE_UNLOCK_TIMEOUT) {
            SECURE_UNLOCK_tapped = false;
        }
    } else if (secure_is_unlocking()) {
            SECURE_UNLOCK_timer = timer_read();
            SECURE_UNLOCK_tapped = true;
    }
}

// rgb matrix
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (secure_is_unlocked()) {
        rgb_matrix_set_color(13, 0x55, 0xFF, 0x11);
    } else if (SECURE_UNLOCK_tapped) {
        rgb_matrix_set_color(13, RGB_ORANGE);
    } else {
        rgb_matrix_set_color(13, 0xFF, 0x00, 0x00);
    }

    return false;
}

// on ready
void matrix_init_user(void) {
    secure_request_unlock();
};

// loop scan
void matrix_scan_user(void) {
    scan_secure_timer();
    scan_key_timer();
}
