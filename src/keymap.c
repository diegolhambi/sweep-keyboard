#include QMK_KEYBOARD_H
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
        KC_Q, KC_W, KC_F, KC_P, KC_B,        KC_J, KC_L, KC_U,    KC_Y,   KC_QUOT,
        HM_A, HM_R, HM_S, HM_T, KC_G,        KC_M, HM_N, HM_E,    HM_I,   HM_O,
        KC_Z, KC_X, KC_C, KC_D, KC_V,        KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
                        KC_SPC, KC_BSPC, LT(_EXTENDED, KC_ENT), TO(_SYMBOL)
    ),

    [_SYMBOL] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_SCLN, KC_COLN,        KC_EQL,  KC_7, KC_8, KC_9, KC_PLUS,
        KC_BSLS, KC_PIPE, KC_LCBR, KC_LPRN, KC_LBRC,        KC_ASTR, KC_4, KC_5, KC_6, KC_MINS,
        KC_DLR,  KC_UNDS, KC_RCBR, KC_RPRN, KC_RBRC,        KC_0,    KC_1, KC_2, KC_3, KC_SLSH,
                  TO(_COLEMAK), LT(_FUNCTION, KC_BSPC), LT(_EXTENDED, KC_ENT), MO(_SYMBOL_ALT)
    ),

    [_EXTENDED] = LAYOUT(
        KC_ESC, KC_HOME, KC_UP,   KC_END,   KC_PGUP,        KC_PSCR,    LALT(KC_LEFT), LGUI(KC_F),    LALT(KC_RIGHT), KC_CAPS,
        KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,        ___,        KC_LSFT,       KC_LGUI,       KC_LALT,        KC_LCTL,
        ___,    ___,     KC_TAB,  ___,      ___,            LGUI(KC_V), SCMD(KC_K),    LGUI(KC_C),    LGUI(KC_X),     LGUI(KC_Z),
                                       KC_SPC, KC_BSPC, KC_TRNS, ___
    ),
    
    [_SYMBOL_ALT] = LAYOUT(
        ___, ___, ___, ___, ___,        ___, KC_AMPR, KC_GRV,  KC_TILD, ___,
        ___, ___, ___, ___, ___,        ___, KC_DLR,  KC_PERC, KC_CIRC, ___,
        ___, ___, ___, ___, ___,        ___, KC_EXLM, KC_AT,   KC_HASH, ___,
                    TO(_COLEMAK), KC_TRNS, KC_ENT, KC_TRNS
    ),

    [_FUNCTION] = LAYOUT(
        ___,     ___,     ___,     ___,     ___,        KC_F12, KC_F7, KC_F8, KC_F9, ___,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, ___,        KC_F11, KC_F4, KC_F5, KC_F6, ___,
        ___,     ___,     ___,     ___,     ___,        KC_F10, KC_F1, KC_F2, KC_F3, ___,
                                    ___, KC_TRNS, ___, ___
    ),
};
