#include QMK_KEYBOARD_H

#define _base 0
#define _lone 1
#define _ltwo 2
#define _lthree 3

enum combo_events { COMBO_BSPC, COMBO_ENT, COMBO_TAB, COMBO_ESC, COMBO_DEL };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_base]   = LAYOUT_625(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, LT(2, KC_QUOTE), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, LT(3, KC_UP), KC_MUTE, KC_LGUI, KC_LALT, KC_GRV, LT(1, KC_SPC), KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT),
                                                              [_lone]   = LAYOUT_625(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_ESC, KC_BSLASH, KC_QUOTE, KC_MINUS, KC_EQL, KC_G, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCOLON, KC_QUOTE, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, KC_UP, KC_TRNS, KC_LGUI, KC_LALT, KC_GRV, KC_NO, KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT),
                                                              [_ltwo]   = LAYOUT_625(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_ESC, KC_PIPE, KC_DQUO, KC_UNDS, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_PIPE, KC_BSLASH, KC_SCOLON, KC_NO, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, KC_UP, KC_TRNS, KC_LGUI, KC_LALT, KC_GRV, KC_SPC, KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT),
                                                              [_lthree] = LAYOUT_625(RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

#ifdef OLED_DRIVER_ENABLE

void render_layer_state(void) {
    oled_write_ln(PSTR("LAYER"), false);
    oled_write_ln(PSTR("L1"), layer_state_is(1));
    oled_write_ln(PSTR("L2"), layer_state_is(2));
    oled_write_ln(PSTR("L3"), layer_state_is(3));
    oled_write_ln(PSTR(" "), false);
}

void render_keylock_status(led_t led_state) {
    oled_write_ln(PSTR("Lock:"), false);
    oled_write(PSTR("N"), led_state.num_lock);
    oled_write(PSTR("C"), led_state.caps_lock);
    oled_write_ln(PSTR("S"), led_state.scroll_lock);
    oled_write_ln(PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln(PSTR("Mods:"), false);
    oled_write(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_ln(PSTR("G"), (modifiers & MOD_MASK_GUI));
    oled_write_ln(PSTR(" "), false);
}

void oled_task_user(void) {
    // void oled_write_pixel(uint8_t x, uint8_t y, bool on);

    render_layer_state();
    render_keylock_status(host_keyboard_led_state());
    render_mod_status(get_mods() | get_oneshot_mods());
}

#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

void keyboard_post_init_user(void) { eeconfig_init(); }

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_ent[]  = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_tab[]  = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[]  = {KC_S, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {[COMBO_BSPC] = COMBO(combo_bspc, KC_BSPC), [COMBO_ENT] = COMBO(combo_ent, KC_ENT), [COMBO_TAB] = COMBO(combo_tab, KC_TAB), [COMBO_ESC] = COMBO(combo_esc, KC_ESC), [COMBO_DEL] = COMBO(combo_del, KC_DEL)};
#endif
