#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

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
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _NUMBERS,
  _MIDI,
  _ROOT,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TRNS KC_TRANSPARENT
#define VOLUP KC_AUDIO_VOL_UP
#define VOLDOWN KC_AUDIO_VOL_DOWN
#define VOLMUTE KC_AUDIO_MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
        KC_ESCAPE,  KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPACE,
        KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KC_ENTER,
        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_UP,      KC_RSHIFT,
        KC_LCTRL,   KC_LGUI,    KC_LALT,    MO(5),      LOWER,      KC_SPACE,   KC_NO,      RAISE,      MO(4),      KC_LEFT,    KC_DOWN,    KC_RIGHT
    ),

    [_LOWER] = LAYOUT_planck_grid(
        KC_GRAVE,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       TRNS,
        KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINUS,   KC_EQUAL,   KC_BSLASH,
        TRNS,       KC_QUES,    KC_SLASH,   KC_LCBR,    KC_LBRACKET,KC_LPRN,    KC_RPRN,    KC_RBRACKET,KC_RCBR,    KC_UNDS,    KC_PLUS,    KC_PIPE,
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_NO,      TRNS,       TRNS,       TRNS,       TRNS,       TRNS
    ),

    [_RAISE] = LAYOUT_planck_grid(
        KC_DELETE,  RSFT(KC_Q), RSFT(KC_W), RSFT(KC_E), RSFT(KC_R), RSFT(KC_T), LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I), LSFT(KC_O), LSFT(KC_P), TRNS,
        RSFT(KC_TAB),RSFT(KC_A),RSFT(KC_S), RSFT(KC_D), RSFT(KC_F), RSFT(KC_G), LSFT(KC_H), LSFT(KC_J), LSFT(KC_K), LSFT(KC_L), KC_COLN,    KC_QUOTE,
        TRNS,       RSFT(KC_Z), RSFT(KC_X), RSFT(KC_C), RSFT(KC_V), RSFT(KC_B), LSFT(KC_N), LSFT(KC_M), KC_LABK,    KC_RABK,    KC_DQUO,    TRNS,
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_NO,      TRNS,       TRNS,       TRNS,       TRNS,       TRNS
    ),

    [_ADJUST] = LAYOUT_planck_grid(
        TG(_MIDI),  TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,
        TRNS,       TRNS,       AU_ON,      AU_OFF,     AU_TOG,     TRNS,       TRNS,       RGB_TOG,    RGB_VAI,    RGB_VAD,    TRNS,       RESET,
        TRNS,       TRNS,       MU_ON,      MU_OFF,     MU_TOG,     TRNS,       TRNS,       RGB_MOD,    RGB_HUI,    RGB_HUD,    TRNS,       TRNS,
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_NO,      TRNS,       TRNS,       TRNS,       TRNS,       TRNS
    ),

    [_FUNCTION] = LAYOUT_planck_grid(
        KC_PSCREEN, KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_KP_7,    KC_KP_8,    KC_KP_9,
        TRNS,       KC_PGDOWN,  KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_KP_4,    KC_KP_5,    KC_KP_6,
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_KP_1,    KC_KP_2,    KC_KP_3,
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_NO,      TRNS,       TRNS,       KC_KP_0,    KC_KP_DOT,  KC_NUMLOCK
    ),

    [_NUMBERS] = LAYOUT_planck_grid(
        TRNS,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       TRNS,
        TRNS,       KC_4,       KC_5,       KC_6,       TRNS,       TRNS,       TRNS,       KC_4,       KC_5,       KC_6,       TRNS,       TRNS,
        TRNS,       KC_7,       KC_8,       KC_9,       KC_0,       TRNS,       TRNS,       KC_1,       KC_2,       KC_3,       TRNS,       TRNS,
        TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       TRNS,       KC_NO,      KC_0,       KC_DOT,     VOLDOWN,    VOLMUTE,    VOLUP
    ),

    [_MIDI] = LAYOUT_planck_grid(
        MI_D,       MI_F,       MI_Gs,      MI_B,       MI_D_1,     MI_F_1,     MI_Gs_1,    MI_B_1,     MI_D_2,     MI_F_2,     MI_Gs_2,    MI_B_2,       
        MI_Cs,      MI_E,       MI_G,       MI_As,      MI_Cs_1,    MI_E_1,     MI_G_1,     MI_As_1,    MI_Cs_2,    MI_E_2,     MI_G_2,     MI_As_2,      
        MI_C,       MI_Ds,      MI_Fs,      MI_A,       MI_C_1,     MI_Ds_1,    MI_Fs_1,    MI_A_1,     MI_C_2,     MI_Ds_2,    MI_Fs_2,    MI_A_2,       
        TG(_MIDI),  MO(_ROOT),  MI_BENDD,   MI_BENDU,   MI_OCTD,    MI_MOD,     KC_NO,      MI_OCTU,    MI_SUS,     MI_MODSD,    MI_ALLOFF, MI_MODSU
    ),

    [_ROOT] = LAYOUT_planck_grid(
        ROOT_D,     ROOT_F,     ROOT_Gs,    ROOT_B,     ROOT_D,     ROOT_F,     ROOT_Gs,    ROOT_B,     ROOT_D,     ROOT_F,     ROOT_Gs,    ROOT_B,       
        ROOT_Cs,    ROOT_E,     ROOT_G,     ROOT_As,    ROOT_Cs,    ROOT_E,     ROOT_G,     ROOT_As,    ROOT_Cs,    ROOT_E,     ROOT_G,     ROOT_As,      
        ROOT_C,     ROOT_Ds,    ROOT_Fs,    ROOT_A,     ROOT_C,     ROOT_Ds,    ROOT_Fs,    ROOT_A,     ROOT_C,     ROOT_Ds,    ROOT_Fs,    ROOT_A,       
        TRNS,       TRNS,       TRNS,       TRNS,       MI_CHD,     TRNS,       KC_NO,      MI_CHU,       TRNS,       MI_TRNSD,   MI_TRNS_0,  MI_TRNSU
    ), 
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define BLACK {0, 0, 0}
#define DARKGREY {50, 50, 50}
#define LIGHTGREY {150, 150, 150}
#define GREEN {0, 255, 0}
#define RED {255, 0, 0}
#define BLUE {0, 0, 255}
#define WHITE {255, 255, 255}
#define YELLOW {255,255,0}
#define MAGENTA {255, 0, 255}
#define ORANGE {255, 128, 0}
#define CYAN {0, 255, 255}
#define PINK {255, 100, 100}
#define BROWN {70, 50, 0}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_LOWER] = { 
        GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      BLACK, 
        GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN, 
        BLACK,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      GREEN,      BLACK, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  BLACK,      BLACK,      BLACK,      BLACK,      BLACK },

    [_RAISE] = { 
        ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     BLACK, 
        BLACK,      ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE, 
        BLACK,      ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     ORANGE,     BLACK, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  BLACK,      BLACK,      BLACK,      BLACK,      BLACK },

    [_ADJUST] = { 
        BLUE,       BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK, 
        BLACK,      BLACK,      YELLOW,     YELLOW,     YELLOW,     BLACK,      BLACK,      YELLOW,     YELLOW,     YELLOW,     BLACK,      RED, 
        BLACK,      BLACK,      YELLOW,     YELLOW,     YELLOW,     BLACK,      BLACK,      YELLOW,     YELLOW,     YELLOW,     BLACK,      BLACK, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  BLACK,      BLACK,      BLACK,      BLACK,      BLACK },

    [_FUNCTION] = { 
        BLUE,       RED,        RED,        WHITE,      RED,        BLUE,       BLUE,       BLUE,       BLUE,       RED,        RED,        RED, 
        BLACK,      RED,        WHITE,      WHITE,      WHITE,      BLUE,       BLUE,       BLUE,       BLUE,       RED,        RED,        RED, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLUE,       BLUE,       BLUE,       BLUE,       RED,        RED,        RED, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  BLACK,      BLACK,      RED,        RED,        WHITE },

    [_NUMBERS] = {
        BLACK,      MAGENTA,    MAGENTA,    MAGENTA,    MAGENTA,    MAGENTA,    MAGENTA,    MAGENTA,    MAGENTA,    MAGENTA,    MAGENTA,    BLACK, 
        BLACK,      MAGENTA,    MAGENTA,    MAGENTA,    BLACK,      BLACK,      BLACK,      MAGENTA,    MAGENTA,    MAGENTA,    BLACK,      BLACK, 
        BLACK,      MAGENTA,    MAGENTA,    MAGENTA,    MAGENTA,    BLACK,      BLACK,      MAGENTA,    MAGENTA,    MAGENTA,    BLACK,      BLACK, 
        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  MAGENTA,    MAGENTA,    WHITE,      WHITE,      WHITE },

    [_MIDI] = {
        BLACK,      BLACK,      WHITE,      BLACK,      BLACK,      BLACK,      WHITE,      BLACK,      BLACK,      BLACK,      WHITE,      BLACK,      
        WHITE,      BLACK,      BLACK,      WHITE,      WHITE,      BLACK,      BLACK,      WHITE,      WHITE,      BLACK,      BLACK,      WHITE,      
        BLACK,      WHITE,      WHITE,      BLACK,      BLACK,      WHITE,      WHITE,      BLACK,      BLACK,      WHITE,      WHITE,      BLACK,      
        RED,        BLACK,      BLACK,      BLACK,      BLACK,      BLACK,                  BLACK,      BLACK,      BLACK,      BLACK,      BLACK },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    RGB rgb = {
      .r = pgm_read_byte(&ledmap[layer][i][0]),
      .g = pgm_read_byte(&ledmap[layer][i][1]),
      .b = pgm_read_byte(&ledmap[layer][i][2]),
    };
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }
}

const uint8_t PROGMEM note_colors[][3] = {
    WHITE,
    BLACK,
    GREEN,
    BLUE,
    MAGENTA,
    GREEN,
    BLACK,
    YELLOW,
    BLUE,
    MAGENTA,
    BLUE,
    MAGENTA,
};

static int midi_root = 0;

void set_midi_layer_color(void) {
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
    case _RAISE:
    case _ADJUST:
    case _FUNCTION:
    case _NUMBERS:
      set_layer_color(layer);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
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
            return false;
        }
    return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
