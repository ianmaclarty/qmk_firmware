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

enum preonic_keycodes {
  LT_NUM = SAFE_RANGE,
  LT_FN,
  LT_CAPS,
};

enum preonic_layers {
  _BASE,
  _LOWER,
  _CAPS,
  _ADJUST,
  _FUNCTION,
  _NUMBERS,
  _MIDI,
  _ROOT,
  _RESET,
};

#define TRNS KC_TRANSPARENT
#define VOLUP KC_AUDIO_VOL_UP
#define VOLDOWN KC_AUDIO_VOL_DOWN
#define VOLMUTE KC_AUDIO_MUTE

#define BLACK {0, 0, 0}
#define GREEN {0, 255, 0}
#define RED {255, 0, 0}
#define BLUE {0, 16, 255}
#define WHITE {255, 255, 255}
#define YELLOW {255, 255, 0}
#define PINK {255, 0, 128}
#define ORANGE {255, 128, 0}
#define AQUA {0, 255, 128}
#define PURPLE {128, 0, 255}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_preonic_grid( 
  KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLASH,
  KC_LCTL, KC_LGUI, KC_LALT, LT_FN,   LT_NUM,  KC_SPC,  KC_SPC,  KC_RSFT, KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT
),

[_CAPS] = LAYOUT_preonic_grid(
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,
    KC_GRAVE,   TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_SLASH,   TRNS,
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS
),

[_FUNCTION] = LAYOUT_preonic_grid(
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_KP_7,    KC_KP_8,    KC_KP_9,    TRNS,       KC_PGUP,
    TG(_RESET), TRNS,       TRNS,       TRNS,       RGB_TOG,    TRNS,       TRNS,       KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PSCREEN, KC_PGDOWN,
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_KP_1,    KC_KP_2,    KC_KP_3,    TRNS,       TRNS,
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_KP_0,    TRNS,       TRNS,       TRNS,       TRNS,
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       VOLDOWN,    VOLMUTE,    VOLUP
),

[_NUMBERS] = LAYOUT_preonic_grid(
    KC_F12,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,    
    KC_DELETE,  KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_PIPE,
    TRNS,       KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINUS,   KC_EQUAL,   TRNS,
    TRNS,       KC_LCBR,    KC_RCBR,    KC_LBRACKET,KC_RBRACKET,TRNS,       TRNS,       KC_LPRN,    KC_RPRN,    KC_UNDS,    KC_PLUS,    KC_BSLASH,
    TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_NO,      TRNS,       TRNS,       KC_HOME,    TRNS,       KC_END
),

[_RESET] = LAYOUT_preonic_grid(
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),    
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), RESET,      TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),     
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),    
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),     
    TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET) 
)

};

static void handle_layer_toggle(uint16_t keycode, keyrecord_t *record, int layer) {
    if (record->event.pressed) {
        layer_on(layer);
    } else {
        layer_off(layer);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool unhandled = true;
    switch (keycode) {
        case LT_NUM:
            handle_layer_toggle(keycode, record, _NUMBERS);
            unhandled = false;
            break;
        case LT_CAPS:
            if (record->event.pressed) {
                register_code(KC_RSHIFT);
            } else {
                unregister_code(KC_RSHIFT);
            }
            handle_layer_toggle(keycode, record, _CAPS);
            unhandled = false;
            break;
        case LT_FN:
            handle_layer_toggle(keycode, record, _FUNCTION);
            unhandled = false;
            break;
    }
    return unhandled;
}