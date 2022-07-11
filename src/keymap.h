#include "quantum.h"

enum layers {
    _COLEMAK,
    _SYMBOL,
    _EXTENDED,
    _SYMBOL_ALT,
    _FUNCTION,
};

/* home row */

#define HM_A MT(MOD_LCTL, KC_A)
#define HM_R MT(MOD_LALT, KC_R)
#define HM_S MT(MOD_LGUI, KC_S)
#define HM_T MT(MOD_LSFT, KC_T)

#define HM_N MT(MOD_RSFT, KC_N)
#define HM_E MT(MOD_RGUI, KC_E)
#define HM_I MT(MOD_LALT, KC_I)
#define HM_O MT(MOD_RCTL, KC_O)