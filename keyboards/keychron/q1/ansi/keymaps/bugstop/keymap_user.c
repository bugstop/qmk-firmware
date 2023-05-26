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

uint16_t KC_LSFT_PO_timer = 0;
bool KC_LSFT_PO_active = false;

uint16_t KC_RCTL_PC_timer = 0;
bool KC_RCTL_PC_active = false;

// The very important timer.
void matrix_scan_user(void) {
    if (KC_LSFT_PO_active) {
        if (timer_elapsed(KC_LSFT_PO_timer) > 200) {
            KC_LSFT_PO_active = false;
        }
    }
    if (KC_RCTL_PC_active) {
        if (timer_elapsed(KC_RCTL_PC_timer) > 200) {
            KC_RCTL_PC_active = false;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                // when keycode is pressed
                host_consumer_send(0x29F);
            } else {
                // when keycode is released
                host_consumer_send(0);
            }
            break;
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            break;
        case KC_SWITCH_LANG:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_SPC);
                unregister_code(KC_LCTL);
            } else {
                unregister_code(KC_SPC);
            }
            break;
        case KC_JB_FORMAT:
            if (record->event.pressed) {
                register_code(KC_LOPT);
                register_code(KC_LCMD);
                tap_code(KC_L);
            } else {
                unregister_code(KC_LOPT);
                unregister_code(KC_LCMD);
            }
            break;
        case KC_LSFT_PO:
            if (record->event.pressed) {
                KC_LSFT_PO_timer = timer_read();
                KC_LSFT_PO_active = true;
                register_code(KC_LSFT);
            } else {
                // Left Shift when held, ( when tapped
                if (KC_LSFT_PO_active) {
                    tap_code(KC_9); // (
                }
                unregister_code(KC_LSFT);
            }
            break;
        case KC_RCTL_PC:
            if (record->event.pressed) {
                KC_RCTL_PC_timer = timer_read();
                KC_RCTL_PC_active = true;
                if (layer_state_is(L_SHORTCUTS_A)) {
                    layer_on(L_SHORTCUTS_C);
                } else {
                    layer_on(L_SHORTCUTS_B);
                }
            } else {
                // Right Control when held, ) when tapped
                if (layer_state_is(L_SHORTCUTS_C)) {
                    layer_off(L_SHORTCUTS_C);
                } else {
                    layer_off(L_SHORTCUTS_B);
                }
                if (KC_RCTL_PC_active) {
                    register_code(KC_RSFT);
                    tap_code(KC_0); // )
                    unregister_code(KC_RSFT);
                }
            }
            break;
        default:
            // Space Cadet suppressed
            KC_LSFT_PO_active = false;
            KC_RCTL_PC_active = false;
            return true;  // Process all other keycodes normally
    }
    return false;  // Skip all further processing of this key
}

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
