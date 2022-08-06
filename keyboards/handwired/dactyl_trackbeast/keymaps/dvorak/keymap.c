#include QMK_KEYBOARD_H
#include "config.h"

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT

#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(
    KC_ESC, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,                       KC_F, KC_G, KC_C, KC_R, KC_L, KC_MINS,
    KC_TAB, KC_A, KC_O, KC_E, KC_U, KC_I,                               KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH,
    TT(1), KC_SCLN, KC_Q, KC_J, KC_K, KC_X,                             KC_B, KC_M, KC_W, KC_V, KC_Z, KC_BSLS,
            LCTL_T(KC_LCBR), LALT_T(KC_RCBR), KC_MS_BTN1,KC_MS_BTN3 ,                  RCTL_T(KC_LPRN), RALT_T(KC_RPRN),
                    LCTL(KC_S),  KC_LGUI ,                                KC_SFTENT ,  KC_SPC,
                    KC_BSPC  , KC_DEL  ,                                  TT(1), KC_BSPC
    ),
[_LAYER1] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                       KC_RBRC, KC_5, KC_8, KC_9,KC_RSFT , KC_PLUS,
    KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                    KC_MINS, KC_4, KC_5, KC_6, KC_MINS, KC_PIPE,
    TT(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,KC_LSFT,               KC_EQL, KC_1, KC_2, KC_3, KC_EQL, KC_UNDS,
            LCTL(KC_D), KC_PSCR, KC_MS_BTN1, KC_BTN3,                                KC_0, KC_TRNS,
                            KC_UP, KC_PGUP,                     LCTL(KC_X),LCTL(KC_C) ,
                            KC_DOWN, KC_PGDN,          TT(2), LCTL(KC_V)
    ),
[_LAYER2] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,               KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_LPRN,     KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_VOLU,
    TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
           KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, /*QK_BOOT*/                    KC_EQL, KC_MUTE,
                            KC_TRNS, KC_TRNS,                     KC_TRNS, QK_BOOT, /*QK_BOOT*/
                            KC_TRNS, KC_TRNS,           TO(0), KC_TRNS
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}


#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    // dprint("Render logo");
    oled_write_P(qmk_logo, false);

}

bool oled_task_user(void) {
    print("oled_task_user");
    render_logo();

    switch (get_highest_layer(layer_state)) {
        case _LAYER0:
            oled_write_ln_P(PSTR("_LAYER0"), false);
            break;
        case _LAYER1:
            oled_write_ln_P(PSTR("_LAYER1"), false);
            break;
        case _LAYER2:
            oled_write_ln_P(PSTR("_LAYER2"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    return false;
}
#endif


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=false;
  debug_keyboard=false;
  debug_mouse=false;
    #ifdef POINTING_DEVICE_ENABLE
        pointing_device_set_cpi(800);  // applies to both sensors
    #endif
}
