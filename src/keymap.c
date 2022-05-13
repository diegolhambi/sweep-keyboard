#include QMK_KEYBOARD_H
#include "keymap.h"

#define td_th_count 8

static td_tap_result td_states[td_th_count] = {
    [EXLM]   = { .count = 0, .type = 0 },
    [PLUS]   = { .count = 0, .type = 0 },
    [DOLLAR] = { .count = 0, .type = 0 },
    [LPRN]   = { .count = 0, .type = 0 },

    [MIN] =   { .count = 0, .type = 0 },
    [EQU] =   { .count = 0, .type = 0 },
    [UND] =   { .count = 0, .type = 0 },
    [QUOTE] = { .count = 0, .type = 0 }
};

static const td_th td_th_defs[td_th_count] = {
    [EXLM]   = { .tap_kc = KC_EXCLAIM, .hold_kc = KC_LCTL },
    [PLUS]   = { .tap_kc = KC_PLUS,    .hold_kc = KC_LALT },
    [DOLLAR] = { .tap_kc = KC_DOLLAR,  .hold_kc = KC_LGUI },
    [LPRN]   = { .tap_kc = KC_LPRN,    .hold_kc = KC_LSFT },

    [MIN] =   { .tap_kc = KC_MINUS,      .hold_kc = KC_RSFT },
    [EQU] =   { .tap_kc = KC_EQUAL,      .hold_kc = KC_RGUI },
    [UND] =   { .tap_kc = KC_UNDERSCORE, .hold_kc = KC_LALT },
    [QUOTE] = { .tap_kc = KC_QUOTE,      .hold_kc = KC_RCTL }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
        KC_Q, KC_W, KC_F, KC_P, KC_B,        KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,
        HM_A, HM_R, HM_S, HM_T, KC_G,        KC_M, HM_N, HM_E,    HM_I,   HM_O,
        KC_Z, KC_X, KC_C, KC_D, KC_V,        KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
                  KC_SPACE, KC_BACKSPACE, KC_ENTER, TO(_SYMBOL)
    ),

    [_GAME] = LAYOUT(
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R,        ___, ___, ___, ___, KC_ESC,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F,        ___, ___, ___, ___, KC_RSFT,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V,        ___, ___, ___, ___, KC_RCTL,
                    KC_SPACE, KC_BACKSPACE, KC_ENTER, TO(_SYMBOL)
    ),

    [_ACCENT] = LAYOUT(
        ___, ___,      ___, ___,     ___,        ___, ___,      KC_DQUO, ___,     ___,
        ___, KC_GRAVE, ___, KC_TILD, ___,        ___, KC_QUOTE, ___,     KC_CIRC, ___,
        ___, ___,      ___, ___,     ___,        ___, ___,      ___,     ___,     ___,
                     TO(_COLEMAK), KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_SYMBOL] = LAYOUT(
        KC_1,     KC_2,     KC_3,       KC_4,     KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        TD(EXLM), TD(PLUS), TD(DOLLAR), TD(LPRN), KC_RPRN,        KC_PIPE, TD(MIN), TD(EQU), TD(UND), TD(QUOTE),
        KC_GRAVE, KC_BSLS,  KC_AT,      KC_LCBR,  KC_RCBR,        KC_RBRC, KC_LBRC, KC_COMM, KC_DOT,  TO(_MISC),
                                        TO(_COLEMAK), KC_TRNS, KC_ENTER, TO(_NAV)
    ),

    [_NAV] = LAYOUT(
        ___, KC_PAGE_UP, KC_UP,   KC_PAGE_DOWN, KC_HOME,        ___, ___,     ___,     ___,     KC_PRINT_SCREEN,
        ___, KC_LEFT,    KC_DOWN, KC_RIGHT,     ___,            ___, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL,
        ___, KC_TAB,     ___,     ___,          KC_END,         ___, ___,     ___,     ___,     ___,
                                         TO(_COLEMAK), KC_TRNS, KC_TRNS, ___
    ),

    [_MISC] = LAYOUT(
        KC_F1, KC_F4, KC_F7, KC_F10, ___,        DF(_GAME),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_F2, KC_F5, KC_F8, KC_F11, ___,        ___,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_F3, KC_F6, KC_F9, KC_F12, ___,        DF(_COLEMAK), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             TO(_COLEMAK), ___, ___, ___
    )
};

const uint16_t PROGMEM wf_combo[] =      {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] =      {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM uy_combo[] =      {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM pb_combo[] =      {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM hdot_combo[] =    {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM pgupup_combo[] =  {KC_PAGE_UP, KC_UP, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [WF_ESC] =      COMBO(wf_combo, KC_ESC),
    [XC_TAB] =      COMBO(xc_combo, KC_TAB),
    [UY_DEL] =      COMBO(uy_combo, KC_DEL),
    [PB_CAPS] =     COMBO(pb_combo, KC_CAPS),
    [COMMDOT_NAV] = COMBO(commdot_combo, TO(_NAV)),
    [HDOT_ACCENT] = COMBO(hdot_combo, OSL(_ACCENT)),
    [PGUPUP_ESC] =  COMBO(pgupup_combo, KC_ESC)
};

uint16_t default_tapping_term = TAPPING_TERM;

td_tap_result cur_dance(qk_tap_dance_state_t *state) {
    td_tap_result result;
    result.count = state->count;

    result.type = TD_TAP;

    if (result.count == 1 && state->pressed) {
        result.type = TD_HOLD;
    }

    return result;
}

void td_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t stateKeycode = state->keycode - QK_TAP_DANCE;
    td_states[stateKeycode] = cur_dance(state);

    switch(td_states[stateKeycode].type) {
        case TD_HOLD:
            register_code16(td_th_defs[stateKeycode].hold_kc);
            break;

        default:
            for (uint8_t i = 0; i < td_states[stateKeycode].count - 1; i++) {
                tap_code16(td_th_defs[stateKeycode].tap_kc);
            }

            register_code16(td_th_defs[stateKeycode].tap_kc);
            break;
    }
}

void td_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t stateKeycode = state->keycode - QK_TAP_DANCE;

    if (td_states[stateKeycode].type == TD_HOLD) {
        unregister_code16(td_th_defs[stateKeycode].hold_kc);
    } else {
        unregister_code16(td_th_defs[stateKeycode].tap_kc);
    }

    td_states[stateKeycode].count = 0;
    td_states[stateKeycode].type = 0;
    default_tapping_term = TAPPING_TERM;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [EXLM] =   ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
    [PLUS] =   ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
    [DOLLAR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
    [LPRN] =   ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),

    [MIN] =   ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
    [EQU] =   ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
    [UND] =   ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
    [QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
};