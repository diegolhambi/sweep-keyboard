#include "quantum.h"

enum layers {
  _COLEMAK,
  _GAME,
  _ACCENT,
  _SYMBOL,
  _NAV,
  _MISC,
};

enum combos {
    WF_ESC,
    XC_TAB,
    UY_DEL,
    PB_CAPS,
    COMMDOT_NAV,
    HDOT_ACCENT,
    PGUPUP_ESC,
};

enum td_keycodes {
    EXLM_LGUI,
    PLUS_LALT,
    DOLLAR_LCTL,
    LPRN_LSFT,

    MIN_LSFT,
    EQU_RCTL,
    UND_LALT,
    QUOTE_RGUI,
};

/* home row */

#define KC_LGUI_A MT(MOD_LGUI, KC_A)
#define KC_LALT_R MT(MOD_LALT, KC_R)
#define KC_LCTL_S MT(MOD_LCTL, KC_S)
#define KC_LSFT_T MT(MOD_LSFT, KC_T)

#define KC_RSFT_N MT(MOD_RSFT, KC_N)
#define KC_RCTL_E MT(MOD_RCTL, KC_E)
#define KC_LALT_I MT(MOD_LALT, KC_I)
#define KC_RGUI_O MT(MOD_RGUI, KC_O)

typedef enum {
    TD_TAP,
    TD_HOLD
} td_state_t;

typedef struct {
    uint8_t count;
    uint8_t type;
} td_tap_result;

typedef struct {
    uint16_t tap_kc;
    uint16_t hold_kc;
} td_th;


td_tap_result cur_dance(qk_tap_dance_state_t *state);

void td_finished(qk_tap_dance_state_t *state, void *user_data);
void td_reset(qk_tap_dance_state_t *state, void *user_data);