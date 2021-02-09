/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

// enum preonic_keycodes {
//   LT_NUM = SAFE_RANGE,
//   LT_FN,
//   LT_CAPS,
// };

enum preonic_layers {
  _BASE,
  _FN,
  _RESET,
};

#define TRNS KC_TRANSPARENT
#define VOLUP KC_AUDIO_VOL_UP
#define VOLDOWN KC_AUDIO_VOL_DOWN
#define VOLMUTE KC_AUDIO_MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_preonic_grid( 
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
    KC_GRAVE,   KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_SLASH,
    KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_UP,      KC_RSFT,
    KC_LCTL,    MO(_FN),    KC_LALT,    KC_LGUI,    KC_SPC,     KC_SPC,     KC_SPC,     KC_SPC,     KC_ENT,     KC_LEFT,    KC_DOWN,    KC_RIGHT
),

[_FN] = LAYOUT_preonic_grid(
    KC_DELETE,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     TRNS,
    TG(_RESET), KC_F11,     KC_F12,     KC_KP_7,    KC_KP_8,    KC_KP_9,    TRNS,       KC_LCBR,    KC_RCBR,    KC_UNDS,    KC_PLUS,    KC_BSLASH,
    TRNS,       VOLUP,      KC_PSCREEN, KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_EXLM,    KC_LBRACKET,KC_RBRACKET,KC_MINUS,   KC_EQUAL,   KC_PIPE,
    TRNS,       VOLDOWN,    VOLMUTE,    KC_KP_1,    KC_KP_2,    KC_KP_3,    TRNS,       KC_LPRN,    KC_RPRN,    TRNS,       KC_PGUP,    TRNS,
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_HOME,    KC_PGDOWN,  KC_END
),

[_RESET] = LAYOUT_preonic_grid(
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),    
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), RESET,      TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),     
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),    
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),     
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET) 
)

};