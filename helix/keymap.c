/* Copyright 2020 yushakobo
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

#define MK_COMBINED

enum layer_names {
  _MENU = 0,
  _QWERTY,
  _COLEDH,
  _NUMROW,
  _NUMPAD,
  _NAV,
  _VIM,
  _MOUS,
  _FN,
};

#define MENU   TO(_MENU)
#define QWERTY TO(_QWERTY)
#define COLEDH TO(_COLEDH)
#define NUMROW MO(_NUMROW)
#define NUMPAD MO(_NUMPAD)
#define NAV    MO(_NAV)
#define VIM    MO(_VIM)
#define MOUS   MO(_MOUS)
#define FN     MO(_FN)

enum { 
  UNDO = SAFE_RANGE, 
  REDO, 
  SLCTALL, 
  CUT, 
  COPY, 
  PASTE, 
  VUNDO, 
  VREDO, 
  VDEL, 
  VYANK, 
  VPASTE,
  VWDEL,
  VWYANK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MENU] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, QWERTY,  COLEDH,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_QWERTY] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, NUMPAD,  NUMROW,  KC_LALT, KC_SPC,  _______, _______, KC_SPC,  NAV,     _______, MENU,    FN,      KC_PENT
  ),
  [_COLEDH] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    KC_DEL,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, NUMPAD,  NUMROW,  KC_LALT, KC_SPC,  _______, _______, KC_SPC,  NAV,     _______, MENU,    FN,      KC_PENT
  ),
  [_NUMROW] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, 
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_QUOT,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_RSFT,
    KC_LCTL, KC_LGUI, _______, _______, KC_LALT, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
  ),
  [_NUMPAD] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSLS,
    _______, _______, _______, _______, _______, _______,                   _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_PENT,
    KC_LCTL, KC_LGUI, _______, _______, KC_LALT, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_PENT
  ),
  [_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, UNDO,    REDO,    _______,                   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS,
    _______, SLCTALL, _______, CUT,     COPY,    PASTE,                     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LGUI, _______, MOUS,    KC_LALT, KC_ESC,  _______, _______, VIM,     _______, _______, _______, _______, _______ 
  ),
  [_VIM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, VUNDO,   VREDO,   _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, VDEL,    VYANK,   VPASTE,                    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, VWDEL,   VWYANK,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
  ),
  [_MOUS] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, KC_WH_D, KC_WH_U, _______, _______,
    _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, _______, _______, _______, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_FN] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                    KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    KC_LSFT, KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LGUI, _______, _______, KC_LALT, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case UNDO:
    if (record->event.pressed) { SEND_STRING(SS_LCTL("z")); }
    break;
  case REDO:
    if (record->event.pressed) { SEND_STRING(SS_LCTL("y")); }
    break;
  case SLCTALL:
    if (record->event.pressed) { SEND_STRING(SS_LCTL("a")); }
    break;
  case CUT:
    if (record->event.pressed) { SEND_STRING(SS_LCTL("x")); }
    break;
  case COPY:
    if (record->event.pressed) { SEND_STRING(SS_LCTL("c")); }
    break;
  case PASTE:
    if (record->event.pressed) { SEND_STRING(SS_LCTL("v")); }
    break;
  case VUNDO:
    if (record->event.pressed) { SEND_STRING("u"); }
    break;
  case VREDO:
    if (record->event.pressed) { SEND_STRING(SS_LCTL("r")); }
    break;
  case VDEL:
    if (record->event.pressed) { SEND_STRING("dd"); }
    break;
  case VYANK:
    if (record->event.pressed) { SEND_STRING("yy"); }
    break;
  case VWDEL:
    if (record->event.pressed) { SEND_STRING("dw"); }
    break;
  case VWYANK:
    if (record->event.pressed) { SEND_STRING("yw"); }
    break;
  case VPASTE:
    if (record->event.pressed) { SEND_STRING("p"); }
    break;
  }
  return true;
};
