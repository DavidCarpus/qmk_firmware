#include QMK_KEYBOARD_H
#include "config.h"

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)
#define SFT_DOT  SFT_T(KC_DOT)
#define SFT_SEMI  SFT_T(KC_SEMICOLON)


#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// Thelios: /home/dcarpus/Code/home/Keyboard/qmk_firmware/keyboards/handwired/dactyl_manuform/5x7/keymaps/left/keymap.c

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (dvorak)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   '  |   ,  |   .  |   p  |   y  |                             |   f  |   g  |   c  |   r  |   l  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   o  |   e  |   u  |   i  |                             |   d  |   h  |   t  |   n  |   s  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   b  |   m  |   w  |   v  |   z  | SHFT |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  | RAISE| SPC  |                                           | PLUS | EQL  |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |  GRV | HOME |                             | LGUI | DEL  |
     *                             |------+------|                             |------+------|
     *                             | BACK | TAB  |                             | END  | LALT |
     *                             +-------------+                             +-------------+
     */
    [_BASE] = LAYOUT_ortho5x6(
        KC_ESC,  KC_QUOTE, KC_COMM, KC_DOT,  KC_P,    KC_Y,               KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_MINS,
        KC_TAB,  KC_A,     KC_O,    KC_E,    KC_U,    KC_I,               KC_D,    KC_H,    KC_T,    KC_N,   KC_S,  KC_QUOT,
        KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,               KC_B,    KC_M,    KC_W,    KC_V,   KC_Z,  KC_BSLS,
                           KC_LBRC, KC_RBRC, RAISE,   KC_SPC,                               KC_PLUS, KC_EQL,
                                            KC_GRV,  KC_HOME,             KC_LGUI,  KC_DEL,
                                            KC_BSPC, KC_TAB,              KC_END, KC_LALT
    ),

    [_LOWER] = LAYOUT_ortho5x6(
        _______, _______, _______, _______, _______, KC_LBRC,             KC_RBRC, KC_P7,   KC_P8,   KC_P9,   QK_BOOT,   KC_PLUS,
        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LPRN,             KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS, KC_PIPE,
        _______, _______, _______, _______, _______, _______,             _______, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_UNDS,
                          _______, KC_PSCR, _______, _______,                               _______, KC_P0,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
    ),

    [_RAISE] = LAYOUT_ortho5x6(
        _______, QK_BOOT,   _______, _______, _______, KC_LBRC,             KC_RBRC, _______, KC_NLCK, KC_INS,  KC_SLCK, KC_MUTE,
        _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_LPRN,             KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, KC_VOLD,
                          _______, _______,  _______, _______,                               KC_EQL,  _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
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
    dprint("Render logo");
    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    print("oled_task_user");
    render_logo();
    return false;
}

#endif

// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
// //   debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// }