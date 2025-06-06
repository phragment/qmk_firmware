// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

//#define AUTO_SHIFT_TIMEOUT 175

enum layer_names {
    _BASE,
    _FN,
    _2ND
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // row by row
  [_BASE] = LAYOUT(
    // first row, left pcb
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    // first row, right pcb
       KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,

    // second row
      KC_NO,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,

      KC_NO,  KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,

      KC_NO, KC_BSLS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT, KC_PSCR,

      KC_NO, KC_LGUI, KC_LALT, KC_LCTL,   MO(1), KC_LSFT,  KC_SPC,
    KC_BTN1, KC_BTN3, KC_BTN2, KC_RALT,  KC_APP,   KC_NO,   KC_NO
  ),
  [_FN] = LAYOUT(
      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
      KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,

      KC_NO,   KC_NO,   KC_NO,   KC_UP,  KC_DEL, KC_BSPC,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO, KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO,
      KC_NO, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  [_2ND] = LAYOUT(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};

const uint16_t PROGMEM keymaps_std[][MATRIX_ROWS][MATRIX_COLS] = {
  // row by row
  [_BASE] = LAYOUT(
    // first row, left pcb
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    // first row, right pcb
       KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,

    // second row
     KC_TAB,   KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,

     KC_ESC,   KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,

    KC_LSFT, KC_BSLS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT, KC_PSCR,

    KC_LCTL, KC_LGUI, KC_LALT,   MO(1),   MO(2), KC_LSFT,  KC_SPC,
    KC_BTN1, KC_BTN3, KC_BTN2, KC_RGHT, KC_RALT,  KC_APP,   MO(1)
  ),
  [_FN] = LAYOUT(
      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
      KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,

      KC_NO,   KC_NO,   KC_NO,   KC_UP,  KC_DEL, KC_BSPC,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO, KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,   KC_NO,   KC_NO
  ),
  [_2ND] = LAYOUT(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO, KC_PGUP,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO, KC_HOME, KC_PGDN,  KC_END,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
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

uint32_t reen_trackpoint(uint32_t trigger_time, void *cb_arg) {
  if (gpio_read_pin( HAVE_PS2_PIN )) {
    dprintf("mouse enabled\n");
    ps2_mouse_set_inhibit(false);

    // TODO reinit here?
    //ps2_mouse_init();

  } else {
    dprintf("mouse disabled\n");
    ps2_mouse_disable_data_reporting();
  }
  //ps2_mouse_set_inhibit(false);
  return 0;
}

uint32_t rst_off(uint32_t trigger_time, void *cb_arg) {
  gpio_write_pin_low( PS2_RST_PIN );
  defer_exec(1500, reen_trackpoint, NULL);
  return 0;
}

// well defined reset
void reset_trackpoint(void) {
  //ps2_mouse_set_inhibit(true);
  ps2_mouse_disable_data_reporting();

  gpio_set_pin_output( PS2_RST_PIN );
  gpio_write_pin_high( PS2_RST_PIN );

  defer_exec(500, rst_off, NULL);
}


int popcount(unsigned int x) {
  int c = 0;
  for (; x != 0; x >>= 1) {
    if (x & 1) {
      c++;
    }
  }
  return c;
}


int wd_thres = 4;
unsigned int wd_hist = 0;

int wd_top = 6;
int wd_bot = 3;

int wd_state = 0;

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
  //dprintf("x %d y %d\n", mouse_report->x, mouse_report->y);
  //dprintf("buttons %d\n", mouse_report->buttons);

  return;

  // window detector, derivative
  // filter x and y together to make movement more smooth
  int tmp = abs(mouse_report->x) + abs(mouse_report->y);
  if (tmp > wd_thres) {
    wd_hist += 1;
  }
  wd_hist <<= 1;

  if (wd_state) {
    if (popcount(wd_hist) < wd_bot) {
      wd_state = 0;
    }
  } else {
    if (popcount(wd_hist) > wd_top) {
      wd_state = 1;
    }
  }

  if (wd_state == 0) {
    mouse_report->x = 0;
    mouse_report->y = 0;
  }

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
  //debug_mouse = true;

  //
  rgblight_layers = my_rgb_layers;

  //
  //reset_trackpoint();

  //
  gpio_write_pin_low( USR_LED_PIN );
}
