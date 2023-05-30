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

#include "keymap_matrix.h"

// tap/hold indicator
typedef struct IndicatorWithTimeout {
    uint16_t timeout;
    uint16_t timer;
    bool     activated;
} Indicator;

bool indicator_is_active(Indicator *i) {
    return i->activated;
}

void indicator_activate(Indicator *i) {
    i->timer = timer_read();
    i->activated = true;
}

void indicator_deactivate(Indicator *i) {
    i->activated = false;
}

void indicator_update(Indicator *i) {
    uint16_t cost = timer_elapsed(i->timer);
    if (cost > i->timeout) {
        indicator_deactivate(i);
    }
}

// for rgb indicator when unlocking
Indicator SECURE_UNLOCKING = {SECURE_UNLOCK_TIMEOUT, 0, false};

// indicate the unlocking status
// do not give information on failed attempts
void scan_secure_timer(void) {
    if (indicator_is_active(&SECURE_UNLOCKING)) {
        indicator_update(&SECURE_UNLOCKING);
    } else if (secure_is_unlocking()) {
        indicator_activate(&SECURE_UNLOCKING);
    }
}

void lock_system_and_keyboard(void) {
    secure_lock();
    switch(detected_host_os()) {
    case OS_MACOS:
    case OS_IOS:
        tap_code16(LCTL(LCMD(KC_Q)));;
        break;
    case OS_WINDOWS:
        tap_code16(LWIN(KC_L));
        break;
    case OS_LINUX:
        tap_code16(LCTL(LALT(KC_L)));;
        break;
    default:
        break;
    }
}

// SECURE LOCK when hold
Indicator KC_SECURE_TAPPED = {500, 0, false};
// PO when tap, LS when hold
Indicator KC_LSPO_L_TAPPED = {200, 0, false};
// PC when tap, RC when hold
Indicator KC_RCPC_L_TAPPED = {200, 0, false};

// classified as tapped if hold within a given timeframe
void scan_key_timer(void) {
    if (indicator_is_active(&KC_SECURE_TAPPED)) {
        indicator_update(&KC_SECURE_TAPPED);
    }
    if (indicator_is_active(&KC_LSPO_L_TAPPED)) {
        indicator_update(&KC_LSPO_L_TAPPED);
    }
    if (indicator_is_active(&KC_RCPC_L_TAPPED)) {
        indicator_update(&KC_RCPC_L_TAPPED);
    }
}

// rgb matrix
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // secure lock indicator
    if (secure_is_unlocked()) {
        rgb_matrix_set_color(0, 0x30, 0xD0, 0x10);
    } else if (indicator_is_active(&SECURE_UNLOCKING)) {
        rgb_matrix_set_color(0, 0xFF, 0x66, 0x00);
    } else {
        rgb_matrix_set_color(0, 0xFF, 0x00, 0x00);
    }

    // caps word indicator
    if (is_caps_word_on()) {
        rgb_matrix_set_color(73, 0x30, 0xD0, 0x10);
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
