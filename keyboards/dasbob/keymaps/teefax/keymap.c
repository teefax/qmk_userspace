#include QMK_KEYBOARD_H

enum dasbob_layers {
  _QWERTY,
  _SYMBOLS,
  _NUM_FN,
  _NAV,
};

enum combos {
    RTHUMBS,
    LTHUMBS,
};

// combos for layer locking with opposite thumb keys
const uint16_t PROGMEM layerlock_right_combo1[] = {LT(_NAV, KC_BSPC), KC_ENTER, COMBO_END};
const uint16_t PROGMEM layerlock_right_combo2[] = {KC_BSPC, KC_ENTER, COMBO_END};

const uint16_t PROGMEM layerlock_left_combo1[] = {LT(_SYMBOLS,KC_ESC), LT(_NUM_FN, KC_SPACE), COMBO_END};
const uint16_t PROGMEM layerlock_left_combo2[] = {LT(_SYMBOLS,KC_ESC), KC_SPACE, COMBO_END};
const uint16_t PROGMEM layerlock_left_combo3[] = {KC_ESC, LT(_NUM_FN, KC_SPACE), COMBO_END};
const uint16_t PROGMEM layerlock_left_combo4[] = {KC_ESC, KC_SPACE, COMBO_END};

combo_t key_combos[] = {
    [RTHUMBS] = COMBO(layerlock_right_combo1, QK_LAYER_LOCK),
    [RTHUMBS] = COMBO(layerlock_right_combo2, QK_LAYER_LOCK),
    [LTHUMBS] = COMBO(layerlock_left_combo1, QK_LAYER_LOCK),
    [LTHUMBS] = COMBO(layerlock_left_combo2, QK_LAYER_LOCK),
    [LTHUMBS] = COMBO(layerlock_left_combo3, QK_LAYER_LOCK),
    [LTHUMBS] = COMBO(layerlock_left_combo4, QK_LAYER_LOCK),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_3(
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                  'X', 'X', 'X',  'X', 'X', 'X'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │DEL├───┐           ┌───┤ESC│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘
      *               └───│LOW│   │RSE├───┘
      *                   └───┘   └───┘
      */


    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,       /* | */     KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
        KC_A,           LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,                   KC_H,           RSFT_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   KC_SCLN,
        LGUI_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,                   KC_N,           KC_M,           KC_COMM,        KC_DOT,         RGUI_T(KC_SLSH),

                                    KC_TAB,     LT(_SYMBOLS,KC_ESC),        LT(_NUM_FN, KC_SPACE),              LT(_NAV, KC_BSPC),        KC_ENTER,           KC_DEL
    ),

    [_SYMBOLS] = LAYOUT_split_3x5_3(
       KC_GRV,          KC_TILD,                KC_EXLM,            KC_AT,          KC_HASH,    /* | */         KC_DOLLAR,      KC_PERCENT,         KC_CIRC,            KC_AMPR,                KC_ASTR,
       KC_UNDS,         KC_LEFT_CURLY_BRACE,    KC_LEFT_BRACKET,    KC_LEFT_PAREN,  KC_UP,                      KC_RIGHT,       KC_RIGHT_PAREN,     KC_RIGHT_BRACKET,   KC_RIGHT_CURLY_BRACE,   KC_DOUBLE_QUOTE,
       KC_KP_SLASH,     KC_KP_EQUAL,            KC_KP_MINUS,        KC_KP_PLUS,     KC_LEFT,                    KC_DOWN,        KC_BACKSLASH,       KC_PIPE,            KC_QUOTE,               LSFT(LALT(KC_8)),

                                    KC_TAB,     LT(_SYMBOLS,KC_ESC),        KC_SPACE,              KC_BSPC,        KC_ENTER,           KC_DEL
    ),

    [_NUM_FN] = LAYOUT_split_3x5_3(
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_SYSTEM_SLEEP,        /* | */     KC_KP_EQUAL,    KC_KP_7,    KC_KP_8,    KC_KP_9,            KC_KP_ASTERISK,
        KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_SYSTEM_WAKE,                     KC_KP_DOT,      KC_KP_4,    KC_KP_5,    RALT_T(KC_KP_6),    KC_KP_MINUS,
        KC_F9,  KC_F10, KC_F11, KC_F12, KC_KP_SLASH,                        KC_KP_0,        KC_KP_1,    KC_KP_2,    KC_KP_3,            KC_KP_PLUS,

                                    KC_TAB,     KC_ESC,        LT(_NUM_FN, KC_SPACE),              KC_BSPC,        KC_ENTER,           KC_DEL
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,       QK_MOUSE_BUTTON_3,      KC_HOME,                KC_END,    /* | */      KC_PRINT_SCREEN,    RGUI(KC_LEFT_BRACKET),  QK_MOUSE_BUTTON_3,      RGUI(KC_RIGHT_BRACKET), KC_KB_VOLUME_UP,
        KC_LEFT_SHIFT,      QK_MOUSE_WHEEL_LEFT,    QK_MOUSE_WHEEL_UP,      QK_MOUSE_WHEEL_RIGHT,   KC_UP,                  KC_RIGHT,           QK_MOUSE_CURSOR_LEFT,   QK_MOUSE_CURSOR_UP,     QK_MOUSE_CURSOR_RIGHT,  KC_KB_VOLUME_DOWN,
        KC_LEFT_CTRL,       QK_MOUSE_BUTTON_2,      QK_MOUSE_WHEEL_DOWN,    QK_MOUSE_BUTTON_1,      KC_LEFT,                KC_DOWN,            QK_MOUSE_BUTTON_1,      QK_MOUSE_CURSOR_DOWN,   QK_MOUSE_BUTTON_2,      KC_KB_MUTE,

                                    KC_TAB,     KC_ESC,        KC_SPACE,              LT(_NAV, KC_BSPC),        KC_ENTER,           KC_DEL
    ),


};
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_0; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        static const char PROGMEM runqmk_logo[] = {0,0,0,0,152,152,152,152,152,152,24,24,24,
        152,152,24,24,24,152,152,24,24,152,152,24,24,24,152,152,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,127,127,13,13,29,63,103,64,0,63,127,96,96,96,127,63,0,0,127,127,7,12,56,
        127,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,252,134,198,198,252,120,0,0,254,254,
        60,224,224,60,254,254,0,254,254,16,24,124,230,130,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,24,24,25,25,25,25,27,24,24,25,25,24,25,25,24,25,25,24,25,25,24,24,24,24,25,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0};


        oled_write_raw_P(runqmk_logo, sizeof(runqmk_logo));

        led_t led_usb_state = host_keyboard_led_state();
        oled_set_cursor(6, 3);
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUM") : PSTR(""), false);
        oled_set_cursor(6, 2);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
        oled_set_cursor(6, 0);
        oled_write_P(PSTR("by GroooveBob"), false);
            oled_set_cursor(6, 1);
            oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SYMBOLS:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("SYM\n"), false);
            break;
        case _NUM_FN:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("NUM\n"), false);
            break;
        case _NAV:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("NAV\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_set_cursor(6, 1);
        oled_write_ln_P(PSTR("Undefined"), false);
    }
    } else {
        static const char PROGMEM dasbob_logo[] = {
        0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,128,128,128,192,192,192,192,192,192,192,192,192,192,192,128,128,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,128,128,128,128,128,192,192,192,192,192,  0,  0,  0,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,
        0,  0,126,127,255,255,255,255,255,255,255,199,247,255,255,255,255,255,255,255,255,127,252,255,255,255,255,255,255,255,255,255, 15,127,255,255,255,255,255,255,255,255,254,248,  0,126,127,255,255,255,255,255,255,255,199,247,255,255,255,255,255,255,255,255,127,126,255,255,255,255,255,255,255,255,239,239,239,239,207,223,223,223,159, 63,  0,  7, 63,255,255,255,255,255,255,255,254, 14,254,255,255,255,255,255,255,255, 63,241,252,254,255,255,255,255,255,255,255, 31,255,255,255,255,255,255,255,255,255,255,128,  0,
        0,  0,126,255,255,255,255,255,255,255,255,227,255,255,255,255,255,255,255,255,255,  0, 15, 63,127,255,255,255,255,255,255,255,248,255,255,255,255,255,255,255,255,127, 63,  7,  0,126,255,255,255,255,255,255,255,255,227,255,255,255,255,255,255,255,255,255,128,252,253,249,249,251,251,251,251,251,255,255,255,255,255,255,255,255,127, 30,  0,  0,  0,  3, 31,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  7,  0, 63,255,255,255,255,255,255,255,255,255,248,255,255,255,255,255,255,255,255,255,255,255,  0,
        0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,
        };
        oled_write_raw_P(dasbob_logo, sizeof(dasbob_logo));
    }
    return false;
}
#endif
