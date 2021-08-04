#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define SPFN1 LT(_FN1, KC_SPACE)
#define BSFN2 LT(_FN2, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,             KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_FN1,  SPFN1,            BSFN2,                     KC_RGUI, KC_RALT, KC_FN2,  KC_RCTL
  ),

  [_FN1] = LAYOUT(
   _______,  _______,   _______,   _______,     _______,     _______,    _______,     _______,     _______,     _______,     _______,  _______,
     _______,    _______,  _______,  _______,  _______,  _______,  _______, _______,     _______,     _______,     _______,          _______,
     _______,  _______, _______,  _______,  _______,  _______,  _______,           _______,    _______,    _______,     _______,   _______,
     _______, _______, _______, _______, _______,           _______,                    _______,     _______,  _______, _______,
  ),

  [_FN2] = LAYOUT(
    _______, _______,_______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______,                   _______, _______, _______, _______
  )

};
