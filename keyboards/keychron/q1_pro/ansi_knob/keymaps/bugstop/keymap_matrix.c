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

// status indicator with timeout
typedef struct IndicatorWithTimeout {
    uint16_t timeout;
    uint16_t timer;
    bool     activated;
} Indicator;

uint16_t indicator_elapsed(Indicator *i) {
    return timer_elapsed(i->timer);
}

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
    if (indicator_elapsed(i) > i->timeout) {
        indicator_deactivate(i);
    }
}

// tap/hold indicator
bool indicator_is_tapped(Indicator *i) {
    return indicator_is_active(i) && indicator_elapsed(i) >= TAP_MIN_ELAPSED;
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

// CAPS LOCK when tap, SECURE LOCK when hold
Indicator KC_CSLOCK_TAPPED = {500, 0, false};
// PO when tap, LS when hold
Indicator KC_LSPO_L_TAPPED = {200, 0, false};
// PC when tap, RC when hold
Indicator KC_RCPC_L_TAPPED = {200, 0, false};

// classified as tapped if hold within a given timeframe
void scan_key_timer(void) {
    if (indicator_is_active(&KC_CSLOCK_TAPPED)) {
        indicator_update(&KC_CSLOCK_TAPPED);
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
        if (indicator_is_active(&KC_CSLOCK_TAPPED)) {
            rgb_matrix_set_color(INDICATOR_INDEX_POWER, INDICATOR_YELLOW);
        } else {
            rgb_matrix_set_color(INDICATOR_INDEX_POWER, INDICATOR_GREEN);
        }
    } else {
        if (indicator_is_active(&SECURE_UNLOCKING)) {
            rgb_matrix_set_color(INDICATOR_INDEX_POWER, INDICATOR_YELLOW);
        } else {
            rgb_matrix_set_color(INDICATOR_INDEX_POWER, INDICATOR_RED);
        }
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
