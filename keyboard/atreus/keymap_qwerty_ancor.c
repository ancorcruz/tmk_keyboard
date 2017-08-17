#include "keymap_common.h"

/* Ancor's Atreus layout. Based on the default layour.  */

/* The default Atreus layout. First layer is normal keys, second
   (momentary fn layer) is numbers, most punctuation, and
   arrows. Third (modal, persistent) layer is function keys and other
   rarely-used keys. */

/* default layout ESC and ENTER are disabled */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty, mostly letters */
  KEYMAP(
      KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    \
      KC_A,    KC_S,   KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, \
      KC_FN6,  KC_X,   KC_C,    KC_V,    KC_B,                    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_FN7,  \
      KC_TRNS, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_FN4, KC_FN5, KC_SPC,  KC_FN0, KC_MINS, KC_QUOT, KC_TRNS
  ), \

  /* 1: punctuation and numbers */
  KEYMAP(
      SHIFT(KC_1), SHIFT(KC_2), KC_UP, SHIFT(KC_LBRC), SHIFT(KC_RBRC), KC_PGUP, KC_7, KC_8, KC_9, SHIFT(KC_8), \
      SHIFT(KC_3), KC_LEFT,     KC_DOWN, KC_RIGHT, SHIFT(KC_4), KC_PGDN, KC_4, KC_5, KC_6, SHIFT(KC_EQUAL), \
      KC_FN8,      KC_RBRC,     SHIFT(KC_9), SHIFT(KC_0), SHIFT(KC_7), KC_GRAVE, KC_1, KC_2, KC_3, KC_FN9, \
      KC_FN1,      SHIFT(KC_INS), KC_LGUI, KC_LSFT, KC_DEL, KC_LCTL, KC_LALT, KC_SPC, KC_FN0, KC_DOT, KC_0, KC_EQUAL
  ), \

  /* 2: arrows and function keys */
  LAYER_TWO
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),

  [4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),  // Escape when tapped, Left Control when held
  [5] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ENT),  // Enter when tapped, Left Alt when held
  [6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_Z),    // 'Z' when tapped, Left Shift when held
  [7] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SLSH), // '/' when tapped, Right Shift when held

  [8] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_LBRC), // '[' when tapped, Left Shift when held

  // This one looks useless, there is nothing useful on the momentary fn layer left hand when shift is held
  [9] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_BSLS), // '\' when tapped, Right Shift when held
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
