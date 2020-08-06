#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ROOT_C,
  ROOT_Cs,
  ROOT_D,
  ROOT_Ds,
  ROOT_E,
  ROOT_F,
  ROOT_Fs,
  ROOT_G,
  ROOT_Gs,
  ROOT_A,
  ROOT_As,
  ROOT_B,
  LT_NUM,
  LT_FN,
  LT_CAPS,
};

enum planck_layers {
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
#define BLUE {0, 0, 255}
#define WHITE {255, 255, 255}
#define YELLOW {255, 255, 0}
#define PINK {255, 0, 128}
#define ORANGE {255, 128, 0}
#define AQUA {0, 255, 128}
#define PURPLE {128, 0, 255}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
        KC_ESCAPE,  KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPACE,
        KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KC_ENTER,
        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_UP,      KC_END,
        KC_LCTRL,   KC_LGUI,    KC_LALT,    LT_FN,      LT_NUM,     KC_SPACE,   KC_NO,      LT_CAPS,    KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT
    ),

    [_LOWER] = LAYOUT_planck_grid(
        KC_GRAVE,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       TRNS,
        KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINUS,   KC_EQUAL,   KC_BSLASH,
        TRNS,       KC_QUES,    KC_SLASH,   KC_LCBR,    KC_LBRACKET,KC_LPRN,    KC_RPRN,    KC_RBRACKET,KC_RCBR,    KC_UNDS,    KC_PLUS,    KC_PIPE,
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_NO,      TRNS,       TRNS,       TRNS,       TRNS,       TRNS
    ),

    [_CAPS] = LAYOUT_planck_grid(
        KC_DELETE,  RSFT(KC_Q), RSFT(KC_W), RSFT(KC_E), RSFT(KC_R), RSFT(KC_T), LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I),     LSFT(KC_O),     LSFT(KC_P),     TRNS,
        RSFT(KC_TAB),RSFT(KC_A),RSFT(KC_S), RSFT(KC_D), RSFT(KC_F), RSFT(KC_G), LSFT(KC_H), LSFT(KC_J), LSFT(KC_K),     LSFT(KC_L),     KC_COLN,        KC_QUOTE,
        TRNS,       RSFT(KC_Z), RSFT(KC_X), RSFT(KC_C), RSFT(KC_V), RSFT(KC_B), LSFT(KC_N), LSFT(KC_M), KC_LABK,        KC_RABK,        LSFT(KC_UP),    LSFT(KC_END),
        TRNS,       TRNS,       TRNS,       TRNS,       KC_BSPACE,  KC_UNDS,    KC_NO,      TRNS,       LSFT(KC_HOME),  LSFT(KC_LEFT),  LSFT(KC_DOWN),  LSFT(KC_RIGHT)
    ),

    [_ADJUST] = LAYOUT_planck_grid(
        TG(_MIDI),  TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,
        TRNS,       TRNS,       AU_ON,      AU_OFF,     AU_TOG,     TRNS,       TRNS,       RGB_TOG,    RGB_VAI,    RGB_VAD,    TRNS,       RESET,
        TRNS,       TRNS,       MU_ON,      MU_OFF,     MU_TOG,     TRNS,       TRNS,       RGB_MOD,    RGB_HUI,    RGB_HUD,    TRNS,       TRNS,
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_NO,      TRNS,       TRNS,       TRNS,       TRNS,       TRNS
    ),

    [_FUNCTION] = LAYOUT_planck_grid(
        TRNS,       KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_SLASH,    KC_NUMLOCK, KC_PSCREEN, TG(_RESET),
        TRNS,       KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_ASTERISK, KC_KP_ENTER,RGB_TOG,    TRNS,
        TRNS,       KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_KP_MINUS,    TRNS,       RGB_MOD,    TG(_MIDI),
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_KP_0,    KC_NO,      KC_KP_DOT,  KC_KP_PLUS,     VOLDOWN,    VOLMUTE,    VOLUP
    ),

    [_NUMBERS] = LAYOUT_planck_grid(
        KC_GRAVE,   KC_LCBR,    KC_1,       KC_2,       KC_3,       KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_EQUAL,   KC_RCBR,    TRNS,
        KC_TILD,    KC_LPRN,    KC_4,       KC_5,       KC_6,       KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINUS,   KC_RPRN,    KC_DQUO,
        TRNS,       KC_LBRACKET,KC_7,       KC_8,       KC_9,       KC_QUES,    KC_BSLASH,  KC_PIPE,    KC_SLASH,   KC_PLUS,    KC_RBRACKET,KC_PGUP,
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_0,       KC_NO,      KC_DELETE,  TRNS,       TRNS,       TRNS,       KC_PGDOWN
    ),

    [_MIDI] = LAYOUT_planck_grid(
        MI_D,       MI_F,       MI_Gs,      MI_B,       MI_D_1,     MI_F_1,     MI_Gs_1,    MI_B_1,     MI_D_2,     MI_F_2,     MI_Gs_2,    MI_B_2,       
        MI_Cs,      MI_E,       MI_G,       MI_As,      MI_Cs_1,    MI_E_1,     MI_G_1,     MI_As_1,    MI_Cs_2,    MI_E_2,     MI_G_2,     MI_As_2,      
        MI_C,       MI_Ds,      MI_Fs,      MI_A,       MI_C_1,     MI_Ds_1,    MI_Fs_1,    MI_A_1,     MI_C_2,     MI_Ds_2,    MI_Fs_2,    MI_A_2,       
        TG(_MIDI),  MO(_ROOT),  MI_BENDD,   MI_BENDU,   MI_OCTD,    MI_MOD,     KC_NO,      MI_OCTU,    MI_SUS,     MI_MODSD,   MI_ALLOFF,  MI_MODSU
    ),

    [_ROOT] = LAYOUT_planck_grid(
        ROOT_D,     ROOT_F,     ROOT_Gs,    ROOT_B,     ROOT_D,     ROOT_F,     ROOT_Gs,    ROOT_B,     ROOT_D,     ROOT_F,     ROOT_Gs,    ROOT_B,       
        ROOT_Cs,    ROOT_E,     ROOT_G,     ROOT_As,    ROOT_Cs,    ROOT_E,     ROOT_G,     ROOT_As,    ROOT_Cs,    ROOT_E,     ROOT_G,     ROOT_As,      
        ROOT_C,     ROOT_Ds,    ROOT_Fs,    ROOT_A,     ROOT_C,     ROOT_Ds,    ROOT_Fs,    ROOT_A,     ROOT_C,     ROOT_Ds,    ROOT_Fs,    ROOT_A,       
        TRNS,       TRNS,       TRNS,       TRNS,       MI_CHD,     TRNS,       KC_NO,      MI_CHU,     TRNS,       MI_TRNSD,   MI_TRNS_0,  MI_TRNSU
    ),

    [_RESET] = LAYOUT_planck_grid(
        TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), RESET,      TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),     
        TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),    
        TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET),     
        TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET), TG(_RESET) 
    )
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_LOWER] = { 
        GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      BLACK, 
        GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN, 
        BLACK,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  BLACK,      BLACK,      BLACK,      BLACK,      BLACK },

    [_CAPS] = {
        RED,        ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     BLACK, 
        BLACK,      ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE, 
        BLACK,      ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     YELLOW,     YELLOW, 
        BLACK,      BLACK,      BLACK,      BLACK,      RED,        ORANGE,                 BLACK,      YELLOW,     YELLOW,     YELLOW,     YELLOW },

    [_ADJUST] = { 
        BLUE,       BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK, 
        BLACK,      BLACK,      YELLOW,     YELLOW,     YELLOW,     BLACK,      BLACK,      YELLOW,     YELLOW,     YELLOW,     BLACK,      RED, 
        BLACK,      BLACK,      YELLOW,     YELLOW,     YELLOW,     BLACK,      BLACK,      YELLOW,     YELLOW,     YELLOW,     BLACK,      BLACK, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  BLACK,      BLACK,      BLACK,      BLACK,      BLACK },

    [_FUNCTION] = { 
        BLACK,      PINK,       PINK,       PINK,       PINK,       BLUE,       BLUE,       BLUE,       BLUE,       AQUA,       GREEN,      RED, 
        BLACK,      PINK,       PINK,       PINK,       PINK,       BLUE,       BLUE,       BLUE,       BLUE,       BLUE,       YELLOW,     BLACK, 
        BLACK,      PINK,       PINK,       PINK,       PINK,       BLUE,       BLUE,       BLUE,       BLUE,       BLACK,      YELLOW,     ORANGE, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLUE,                   BLUE,       BLUE,       WHITE,      WHITE,      WHITE },

    [_NUMBERS] = {
        GREEN,      PINK,       AQUA,       AQUA,       AQUA,       GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      PINK,       BLACK, 
        GREEN,      PINK,       AQUA,       AQUA,       AQUA,       GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      PINK,       GREEN, 
        BLACK,      PINK,       AQUA,       AQUA,       AQUA,       GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      PINK,       BLUE, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      AQUA,                   RED,        BLACK,      BLACK,      BLACK,      BLUE },

    [_MIDI] = {
        BLACK,      BLACK,      WHITE,      BLACK,      BLACK,      BLACK,      WHITE,      BLACK,      BLACK,      BLACK,      WHITE,      BLACK,      
        WHITE,      BLACK,      BLACK,      WHITE,      WHITE,      BLACK,      BLACK,      WHITE,      WHITE,      BLACK,      BLACK,      WHITE,      
        BLACK,      WHITE,      WHITE,      BLACK,      BLACK,      WHITE,      WHITE,      BLACK,      BLACK,      WHITE,      WHITE,      BLACK,      
        RED,        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  BLACK,      BLACK,      BLACK,      BLACK,      BLACK },
    
    [_RESET] = {
        BLACK,      BLACK,      BLACK,      BLACK,      RED,        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,     
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,     
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,     
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  BLACK,      BLACK,      BLACK,      BLACK,      BLACK }
};

static bool num_lock = false;

static void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    RGB rgb = {
      .r = pgm_read_byte(&ledmap[layer][i][0]),
      .g = pgm_read_byte(&ledmap[layer][i][1]),
      .b = pgm_read_byte(&ledmap[layer][i][2]),
    };
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }
}

void set_fn_layer_color(int layer) {
    set_layer_color(layer);
    if (num_lock) {
        rgb_matrix_set_color(9, 255, 255, 255);
    }
}

const uint8_t PROGMEM note_colors[][3] = {
    WHITE,
    BLACK,
    GREEN,
    BLUE,
    PINK,
    GREEN,
    BLACK,
    YELLOW,
    BLUE,
    PINK,
    BLUE,
    PINK
};

static int midi_root = 0;

static void set_midi_layer_color(void) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 0;
        if (i < 36) {
            int note = (i % 4) * 3 + (2 - (i / 12));
            note -= midi_root;
            if (note < 0) {
                note += 12;
            }
            r = pgm_read_byte(&note_colors[note][0]);
            g = pgm_read_byte(&note_colors[note][1]);
            b = pgm_read_byte(&note_colors[note][2]);
        } else {
            r = pgm_read_byte(&ledmap[_MIDI][i][0]);
            g = pgm_read_byte(&ledmap[_MIDI][i][1]);
            b = pgm_read_byte(&ledmap[_MIDI][i][2]);
        }
        rgb_matrix_set_color(i, r, g, b);
    }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  int layer = biton32(layer_state);
  switch (layer) {
    case _LOWER:
    case _CAPS:
    case _ADJUST:
    case _NUMBERS:
    case _RESET:
      set_layer_color(layer);
      break;
    case _FUNCTION:
      set_fn_layer_color(layer);
      break;  
    case _MIDI:
    case _ROOT:
      set_midi_layer_color();
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

static uint16_t last_pressed_key = 0;
static uint8_t tap_count = 0;
static uint16_t tap_timer = 0;

static void handle_layer_toggle(uint16_t keycode, keyrecord_t *record, int layer) {
    if (record->event.pressed) {
        layer_invert(layer);
    } else {
        if (tap_count <= 1) {
            layer_off(layer);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool unhandled = true;
    if (!record->event.pressed) {
        if (keycode == last_pressed_key && timer_elapsed(tap_timer) < 200) {
            tap_count++;
            tap_timer = timer_read();
        } else {
            tap_count = 0;
        }
    }
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            unhandled = false;
            break;
        case ROOT_C:
        case ROOT_Cs:
        case ROOT_D:
        case ROOT_Ds:
        case ROOT_E:
        case ROOT_F:
        case ROOT_Fs:
        case ROOT_G:
        case ROOT_Gs:
        case ROOT_A:
        case ROOT_As:
        case ROOT_B:
            if (record->event.pressed) {
                midi_root = keycode - ROOT_C;
            }
            unhandled = false;
            break;
        case LT_NUM:
            handle_layer_toggle(keycode, record, _NUMBERS);
            unhandled = false;
            break;
        case LT_CAPS:
            handle_layer_toggle(keycode, record, _CAPS);
            unhandled = false;
            break;
        case LT_FN:
            handle_layer_toggle(keycode, record, _FUNCTION);
            unhandled = false;
            break;
    }
    if (record->event.pressed) {
        if (keycode != last_pressed_key || timer_elapsed(tap_timer) > 300) {
            tap_count = 0;
        }
        last_pressed_key = keycode;
        tap_timer = timer_read();
    }
    return unhandled;
}

bool led_update_user(led_t led_state) {
    num_lock = led_state.num_lock;
    return true;
}