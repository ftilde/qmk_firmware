#include QMK_KEYBOARD_H

enum custom_keycodes {
    VISUAL = SAFE_RANGE,
    VI_NRMH,
};

#define _QWERTY 0
#define _SPECIAL 1
#define _NUMS 2
#define _MEDIA 4

#define SPECIAL MO(_SPECIAL)
#define NUMS MO(_NUMS)
#define MEDIA MO(_MEDIA)

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
#define SCRNOFF RCTL(KC_ENTER)

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
    KC_LCTL, _______, NUMS   , KC_LALT,          VI_NRMH, KC_SPC ,KC_ESC,         KC_LCTL,KC_ENT , SPECIAL,          KC_RALT, _______, _______, MEDIA    \
  ),

  [_SPECIAL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,_______,                       _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILD, _______, _______, \
    _______, BCK_A_L, BCK_S_L, BCK_C_L, BCK_R_L, KC_BSLS,_______,                       _______, KC_PIPE, BCK_R_R, BCK_C_R, BCK_S_R, BCK_A_R, _______, \
    _______, KC_GRV , KC_EXLM, KC_UNDS, KC_MINS, KC_SCLN,_______,                       _______, KC_COLN, KC_PLUS, KC_EQL , KC_QUES, KC_SLSH, _______, \
    _______, _______, _______, _______,          NUMS   ,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  ),

  [_NUMS] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,_______,                       _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , \
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,_______,                       _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12 , \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  ),

  [_MEDIA] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, KC_MUTE, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, KC_MPLY, KC_MSTP, KC_VOLU, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_VOLD, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, KC_UP  , _______, SCRNOFF, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          KC_LEFT, KC_DOWN, KC_RGHT, _______  \
  ),
};

enum VI_MODE {
    MODE_INSERT,
    MODE_VISUAL,
    MODE_NORMAL,
};

static enum VI_MODE current_mode = MODE_INSERT;
static bool normal_mode_held = false;

void switch_mode(enum VI_MODE mode) {
    current_mode = mode;
}

enum VI_ACTION {
    VIA_NONE,
    VIA_DELETE,
    VIA_CHANGE,
    VIA_COPY,
};

void send_hex(uint32_t num, uint32_t width) {
    tap_code(KC_0);
    tap_code(KC_X);
    for(int i=0; i< width/4; i++) {
        uint16_t val = (num >> (width - 4)) & 0xf;
        if(val == 0) {
            tap_code(KC_0);
        } else if(val < 10) {
            tap_code(KC_1 + val - 1);
        } else {
            tap_code(KC_A + val - 10);
        }
        num <<= 4;
    }
    tap_code(KC_SPACE);
}


static enum VI_ACTION last_action = VIA_NONE;

uint16_t vi_translate_motion(uint16_t keycode) {
    switch (keycode) {
        case KC_N:
        case LCTL(KC_D):
            return KC_PGDN;
        case KC_P:
        case LCTL(KC_U):
            return KC_PGUP;
        case KC_H:
            return KC_LEFT;
        case KC_J:
            return KC_DOWN;
        case KC_K:
            return KC_UP;
        case KC_L:
            return KC_RGHT;
        case KC_0:
        case KC_UNDERSCORE:
            return KC_HOME;
        case KC_E:
        case KC_DOLLAR:
            return KC_END;
        case KC_W:
            return MV_R_W;
        case KC_B:
            return MV_L_W;

        // Swallow the rest
        default:
            return 0;
    }
}

bool vi_mode_common(uint16_t keycode, keyrecord_t *record) {
    uint16_t translated = vi_translate_motion(keycode);

    if(!translated) {
        if(!IS_MOD(keycode)) {
            last_action = VIA_NONE;
        }
        return true;
    }

    switch (last_action) {
        case VIA_CHANGE:
            if (!record->event.pressed) return false;
            switch_mode(MODE_INSERT);
            // Fall through intended here!
        case VIA_DELETE:
            if (!record->event.pressed) return false;
            register_code(KC_LSFT);
            tap_code16(translated);
            unregister_code(KC_LSFT);
            tap_code16(LCTL(KC_X));
            last_action = VIA_NONE;
            break;

        case VIA_COPY:
            if (!record->event.pressed) return false;
            register_code(KC_LSFT);
            tap_code16(translated);
            unregister_code(KC_LSFT);
            tap_code16(LCTL(KC_C));
            last_action = VIA_NONE;
            break;

        case VIA_NONE:
            if (record->event.pressed) {
                register_code16(translated);
            } else {
                unregister_code16(translated);
            }
            break;
    }

    return false;
}

bool vi_mode_normal(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_V:
            if (!record->event.pressed) return false;
            switch_mode(MODE_VISUAL);
            return false;
        case KC_ESC:
            if (!record->event.pressed) return false;
            last_action = VIA_NONE;
            return false;
        case KC_I:
            if (!record->event.pressed) return false;
            switch_mode(MODE_INSERT);
            return false;
        case KC_X:
            if (!record->event.pressed) return false;
            tap_code16(KC_DELETE);
            return false;
        case KC_P:
        case LSFT(KC_P):
            if (!record->event.pressed) return false;
            tap_code16(LCTL(KC_V));
            return false;
        case KC_C:
            if (!record->event.pressed) return false;
            last_action = VIA_CHANGE;
            return false;
        case KC_D:
            if (!record->event.pressed) return false;
            last_action = VIA_DELETE;
            return false;
        case KC_Y:
            if (!record->event.pressed) return false;
            last_action = VIA_COPY;
            return false;
        case KC_RALT:
        case KC_LALT:
            if (!record->event.pressed) return false;
            switch_mode(MODE_NORMAL);
            return false;
    }
    return true;
}

bool vi_mode_visual(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_D:
            if (!record->event.pressed) return false;
            tap_code16(LCTL(KC_X));
            switch_mode(MODE_NORMAL);
            return false;
        case KC_C:
            if (!record->event.pressed) return false;
            tap_code16(LCTL(KC_X));
            switch_mode(MODE_INSERT);
            return false;
        case KC_X:
            if (!record->event.pressed) return false;
            tap_code16(LCTL(KC_X));
            switch_mode(MODE_NORMAL);
            return false;
        case KC_Y:
            if (!record->event.pressed) return false;
            tap_code16(LCTL(KC_C));
            switch_mode(MODE_NORMAL);
            return false;
        case KC_ESC:
            if (!record->event.pressed) return false;
            switch_mode(MODE_NORMAL);
            return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    bool ismod = IS_MOD(keycode);
    if(!ismod) {
        keycode |= ((uint16_t)mods)<< 8;
    }
    clear_mods();

    bool res = true;

    switch (keycode) {
        case VI_NRMH:
            if (record->event.pressed) {
                normal_mode_held = true;
            } else {
                normal_mode_held = false;
            }
            res = false;
            goto end;
        case SPECIAL:
            if(record->event.pressed) {
                if (normal_mode_held) {
                    layer_on(_NUMS);
                    normal_mode_held = false;
                    res = false;
                    goto end;
                }
            } else {
                layer_off(_NUMS);
            }
            res = true;
            goto end;
    }
    if (current_mode == MODE_VISUAL) {
        res = vi_mode_visual(keycode, record);
        if(res) {
            register_code(KC_LSFT);
            res = vi_mode_common(keycode, record) && ismod;
            unregister_code(KC_LSFT);
        }
    } else if (current_mode == MODE_NORMAL || normal_mode_held) {
        res = vi_mode_normal(keycode, record) && vi_mode_common(keycode, record) && ismod;
    }

end:
    set_mods(mods);
    return res;
}
