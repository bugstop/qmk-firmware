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

#include "keymap_user.h"

// SECURE LOCK when hold
uint16_t KC_SECURE_timer  = 0;
bool     KC_SECURE_tapped = false;

// PO when tap, LS when hold
uint16_t KC_LSPO_L_timer  = 0;
bool     KC_LSPO_L_tapped = false;

// PC when tap, RC when hold
uint16_t KC_RCPC_L_timer  = 0;
bool     KC_RCPC_L_tapped = false;

// The very important timer.
void scan_key_timer(void) {
    if (KC_SECURE_tapped) {
        if (timer_elapsed(KC_SECURE_timer) > 1000) {
            KC_SECURE_tapped = false;
        }
    }
    if (KC_LSPO_L_tapped) {
        if (timer_elapsed(KC_LSPO_L_timer) > 200) {
            KC_LSPO_L_tapped = false;
        }
    }
    if (KC_RCPC_L_tapped) {
        if (timer_elapsed(KC_RCPC_L_timer) > 200) {
            KC_RCPC_L_tapped = false;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // keyboard locked
    if (secure_is_locked()) {
        secure_request_unlock();
        return false;
    }

    // unlocked
    switch (keycode) {
        case KC_SECURE:
            if (record->event.pressed) {
                KC_SECURE_timer = timer_read();
            } else {
                if (!KC_SECURE_tapped) {
                    secure_lock();
                }
            }
            break;
        case KC_EN_CN:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_SPC);
                unregister_code(KC_LCTL);
            } else {
                unregister_code(KC_SPC);
            }
            break;
        case KC_LSPO_L:
            if (record->event.pressed) {
                KC_LSPO_L_timer = timer_read();
                KC_LSPO_L_tapped = true;
                register_code(KC_LSFT);
            } else {
                // Left Shift when held, ( when tapped
                if (KC_LSPO_L_tapped) {
                    tap_code(KC_9); // (
                }
                unregister_code(KC_LSFT);
            }
            break;
        case KC_RCPC_L:
            if (record->event.pressed) {
                KC_RCPC_L_timer = timer_read();
                KC_RCPC_L_tapped = true;
                if (layer_state_is(L_CAPS)) {
                    layer_on(L_BOTH);
                } else {
                    layer_on(L_RSFT);
                }
            } else {
                // Right Control when held, ) when tapped
                if (layer_state_is(L_BOTH)) {
                    layer_off(L_BOTH);
                } else {
                    layer_off(L_RSFT);
                }
                if (KC_RCPC_L_tapped) {
                    register_code(KC_RSFT);
                    tap_code(KC_0); // )
                    unregister_code(KC_RSFT);
                }
            }
            break;
        default:
            // Space Cadet suppressed
            KC_LSPO_L_tapped = false;
            KC_RCPC_L_tapped = false;
            // Process all other keycodes normally
            return true;
    }
    return false;  // Skip all further processing of this key
}

// auto shift functions
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        // SPECIAL except TAB
        case KC_MINUS ... KC_SLASH:
        case KC_NONUS_BACKSLASH:
            return true;
        default:
            return false;
    }
}

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case AUTO_SHIFT_NUMERIC:
            return get_generic_autoshift_timeout() + 100;
        case AUTO_SHIFT_SPECIAL:
            return get_generic_autoshift_timeout() + 30;
        case AUTO_SHIFT_ALPHA:
        default:
            return get_generic_autoshift_timeout();
    }
}

// leader key functions
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    // TODO
    if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("QMK is awesome.");
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }
}
