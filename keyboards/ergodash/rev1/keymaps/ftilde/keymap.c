#include QMK_KEYBOARD_H

enum custom_keycodes {
    VISUAL = SAFE_RANGE,
    VI_RSET,
    VI_DEL,
};

#define _QWERTY 0
#define _SPECIAL 1
#define _MOVE 2

#define SPECIAL MO(_SPECIAL)
#define MOVE MO(_MOVE)

// BCK_C = Bracket round
#define BCK_R_L LSFT(KC_9)
#define BCK_R_R LSFT(KC_0)
// BCK_C = Bracket curly
#define BCK_C_L LSFT(KC_LBRC)
#define BCK_C_R LSFT(KC_RBRC)
// BCK_S = Bracket square
#define BCK_S_L KC_LBRC
#define BCK_S_R KC_RBRC
// BCK_A = Bracket angled
#define BCK_A_L LSFT(KC_COMM)
#define BCK_A_R LSFT(KC_DOT)

#define MV_R_W LCTL(KC_RIGHT)
#define MV_L_W LCTL(KC_LEFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, _______, _______, KC_LALT,          MOVE   , KC_SPC ,KC_ESC,         KC_LCTL,KC_ENT , SPECIAL,          KC_RALT, _______, _______, KC_RGHT  \
  ),

  [_SPECIAL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_AT  , KC_HASH, KC_DLR , KC_PERC,_______,                       _______, KC_TILD, KC_AMPR, KC_ASTR, KC_CIRC, _______, _______, \
    _______, BCK_A_L, BCK_S_L, BCK_C_L, BCK_R_L, KC_BSLS,_______,                       _______, KC_PIPE, BCK_R_R, BCK_C_R, BCK_S_R, BCK_A_R, _______, \
    _______, KC_GRV , KC_EXLM, KC_UNDS, KC_MINS, KC_SCLN,_______,                       _______, KC_COLN, KC_PLUS, KC_EQL , KC_QUES, KC_SLSH, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  ),

  [_MOVE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, KC_HOME, _______, \
    _______, _______, MV_R_W , KC_END , _______, _______,_______,                       _______, _______, _______, KC_PGUP, _______, _______, _______, \
    _______, _______, _______, VI_DEL , _______, _______,_______,                       _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_END , _______, \
    _______, _______, KC_DEL , _______, VISUAL , MV_L_W ,_______,                       _______, _______, KC_PGDN, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,VI_RSET,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

enum VI_MODE {
    MODE_HOLD,
    MODE_VISUAL,
    MODE_NORMAL,
};

static enum VI_MODE current_mode = MODE_HOLD;

void switch_mode(enum VI_MODE mode) {
    switch(mode) {
        case MODE_HOLD:
            unregister_code(KC_LSFT);
            layer_off(_MOVE);
            break;
        case MODE_VISUAL:
            register_code(KC_LSFT);
            layer_on(_MOVE);
            break;
        case MODE_NORMAL:
            unregister_code(KC_LSFT);
            layer_on(_MOVE);
            break;
    }
    current_mode = mode;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOVE:
            if (record->event.pressed) {
                layer_on(_MOVE);
            } else if(current_mode == MODE_HOLD) {
                layer_off(_MOVE);
            }
            return false;
        case VI_DEL:
            if (record->event.pressed) {
                switch(current_mode) {
                    case MODE_VISUAL:
                        tap_code(KC_DEL);
                        switch_mode(MODE_NORMAL);
                        break;
                    case MODE_NORMAL:
                        break;
                    case MODE_HOLD:
                        break;
                }
            }
            return false;
        case VISUAL:
            if (record->event.pressed) {
                switch_mode(MODE_VISUAL);
            }
            return false;
        case VI_RSET:
            if (record->event.pressed) {
                switch(current_mode) {
                    case MODE_VISUAL:
                        switch_mode(MODE_NORMAL);
                        break;
                    case MODE_NORMAL:
                        switch_mode(MODE_HOLD);
                        break;
                    case MODE_HOLD:
                        break;
                }
            }
            return false;
    }
    return true;
}
