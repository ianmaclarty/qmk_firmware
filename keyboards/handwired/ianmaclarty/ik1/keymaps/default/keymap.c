#include QMK_KEYBOARD_H

#define TAB1 LT(1, KC_TAB)
#define ENT2 LT(2, KC_ENT)
#define BSSFT MT(MOD_RSFT,KC_BSPC)
#define FN MO(3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_split_4x6_5(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
KC_GRV,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                               KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                               KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                        KC_LALT,    KC_LGUI,    KC_LCTL,    TAB1,       KC_SPC,     BSSFT,      ENT2,       KC_RCTL,    KC_RGUI,    KC_RALT
),

[1] = LAYOUT_split_4x6_5(
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
_______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_TILD,                            _______,    KC_7,       KC_8,       KC_9,       _______,    _______,
_______,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_GRV,                             KC_MINS,    KC_4,       KC_5,       KC_6,       KC_PIPE,    _______,
_______,    KC_F11,     KC_F12,     _______,    _______,    _______,                            KC_DOT,     KC_1,       KC_2,       KC_3,       KC_BSLS,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,    KC_0,       KC_0,       KC_0,       KC_DOT
),


[2] = LAYOUT_split_4x6_5(
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
_______,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    _______,                            KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     _______,    _______,
_______,    KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    _______,                            KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,
_______,    KC_F11,     KC_F12,     KC_LPRN,    KC_RPRN,    _______,                            _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),
                             
[3] = LAYOUT_split_4x6_5(
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     _______,                            _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),
                             
};