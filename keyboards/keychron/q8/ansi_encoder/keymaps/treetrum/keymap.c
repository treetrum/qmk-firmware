/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// clang-format off

enum layers{
    BASE,
    _FN1,
    HMDS,
    _FN2,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, TG(HMDS),
        KC_LCTL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_GRV,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,           KC_SPC,           MO(_FN1), MO(_FN1),         KC_SPC,            KC_RCMD,            KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_69(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,           KC_MPLY,
        RGB_TOG, _______,  _______,  _______, _______, _______,           _______, _______, KC_UP,   _______,  _______,  _______,  _______, _______, _______,
        _______, _______,  _______,  _______, _______, _______,           _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [HMDS] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, TG(HMDS),
        KC_LCTL, HOME_A,   HOME_S,   HOME_D,  HOME_F,  KC_G,              KC_H,    HOME_J,  HOME_K,  HOME_L,   HOME_SCLN,KC_QUOT,  KC_ENT,           KC_GRV,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,           KC_SPC,           MO(_FN2), MO(_FN2),         KC_SPC,            KC_RCMD,            KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN2] = LAYOUT_ansi_69(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,           KC_MPLY,
        RGB_TOG, _______,  _______,  _______, _______, _______,           _______, _______, KC_UP,   _______,  _______,  _______,  _______, _______, _______,
        _______, _______,  _______,  _______, _______, _______,           _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [HMDS] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN2] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)}
};
#endif // ENCODER_MAP_ENABLE
