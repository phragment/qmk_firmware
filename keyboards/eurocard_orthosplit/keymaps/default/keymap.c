// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN,
    _2ND
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // row by row
  [_BASE] = LAYOUT(
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
       KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,

     KC_TAB,   KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,

     KC_ESC,   KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,

    KC_LSFT, KC_BSLS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   MO(1), KC_PSCR,

    KC_LCTL, KC_LGUI, KC_LALT,   MO(1),   TO(2),   TO(1),  KC_SPC,
    KC_BTN1, KC_BTN3, KC_BTN2,   KC_NO, KC_RALT,  KC_APP, RGB_TOG
  ),
  [_FN] = LAYOUT(
      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
      KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,

      KC_NO,   KC_NO,   KC_NO,   KC_UP,  KC_DEL,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO, KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(0),   TO(2),   KC_NO,
    KC_BTN4,   KC_NO, KC_BTN5,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  [_2ND] = LAYOUT(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(1),   TO(0),   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};


#include "print.h"

const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,
    my_layer2_layer
);

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    dprintf("layer_state_set_user, state %d\n", state);
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(2, layer_state_cmp(state, _2ND));
    return state;
}

#include "ps2_mouse.h"

uint32_t my_callback2(uint32_t trigger_time, void *cb_arg) {
  ps2_mouse_set_inhibit(false);
  return 0;
}

uint32_t my_callback1(uint32_t trigger_time, void *cb_arg) {
  gpio_write_pin_low( PS2_RST_PIN );
  defer_exec(1500, my_callback2, NULL);
  return 0;
}

// well defined reset
void reset_trackpoint(void) {
  ps2_mouse_set_inhibit(true);
  gpio_set_pin_output( PS2_RST_PIN );
  gpio_write_pin_high( PS2_RST_PIN );
  defer_exec(500, my_callback1, NULL);
}

void keyboard_pre_init_user(void) {
  //ps2_mouse_set_inhibit(true);
  reset_trackpoint();

  //
  gpio_set_pin_output( SPLIT_HAND_PIN_ );
  gpio_write_pin_high( SPLIT_HAND_PIN_ );

  //
  gpio_set_pin_output( HAVE_PS2_PIN_ );
  gpio_write_pin_high( HAVE_PS2_PIN_ );

  //
  gpio_set_pin_output( USR_LED_PIN );
  gpio_write_pin_high( USR_LED_PIN );
}

void keyboard_post_init_user(void) {
  debug_enable = true;
  //debug_matrix = true;
  //debug_keyboard = true;
  debug_mouse = true;

  //
  rgblight_layers = my_rgb_layers;

  //
  //reset_trackpoint();

  //
  gpio_write_pin_low( USR_LED_PIN );
}
