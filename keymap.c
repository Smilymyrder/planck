#include "planck.h"
#include "action_layer.h"   // layers?
#include "mousekey.h"       // enables mousekeys
#include "eeconfig.h"       // audiostuff

// includes audio z
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

extern keymap_config_t keymap_config;

#define Qwerty 0  // default layer
#define Num    1  // numbers + arrowkeys (+ deadkeys?)
#define Fn     2  // functions and navigation to other layers
#define Pad    3  // numpad

// Switching layers
#define qtyl  TO(Qwerty) // go to default layer - if needed
#define numl  MO(Num)    //momentary num layer
// #define fn1   MO(Fn)     //momentary function layer

// tap toggle fn layer
#define fn1   TT(Fn)      // layer tap-toggle
#define TAPPING_TOGGLE 2  //defines number of taps needed

// Fillers to make layering more clear
#define ___     KC_TRNS
#define XXX     KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty layer / default
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |   P  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Num  |Enter |Space | Bspc |Shift |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[Qwerty] = {
  { KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, ___},
  { KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT},
  { fn1, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, ___},
  { KC_LCTRL, KC_LGUI, KC_LALT, numl, KC_ENT, KC_SPC, KC_BSPC, KC_LSFT, ___, ___, ___, ___}
},

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * | ___  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ___  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ___  | ___  | ___  | Num  | ___  | ___  | Del  | ___  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[Num] = {
  { ___,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XXX },
  { ___,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX },
  { ___,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX },
  { ___,  XXX,  XXX,  ___,  ___,  ___,  KC_DEL,   ___,  XXX,  XXX,  XXX,  ___ }
},

/* Function layer (toggle) Fn / use this for navigation to other layers
 * ,-----------------------------------------------------------------------------------.
 * | ___  | MsB1 | MsU  | MsB2 |MsWhU |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ___  | MsL  | MsD  | MsR  |MsWhD |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  | Left |  Up  | Down | Rght |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ___  | ___  | ___  |  x   | ___  | ___  | ___  | ___  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[Fn] = {
  { ___, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, XXX, XXX, XXX, XXX, XXX, XXX, XXX},
  { ___, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXX, XXX, XXX, XXX, XXX, XXX, XXX},
  { ___, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, XXX, XXX, XXX, XXX, XXX, XXX, XXX},
  { ___, ___, ___, XXX, ___, ___, ___, ___, XXX, XXX, XXX, XXX}
},

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |  7   |  8   |  9   |      |      |      |      |      |      |      |      |Numloc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  4   |  5   |  6   |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  1   |  2   |  3   |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  0   |      | LAlt |      |      |      |      |      |      |      |      |workl |
 * `-----------------------------------------------------------------------------------'
 */
[Pad] = {
  { KC_KP_7, KC_KP_8, KC_KP_9, XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  KC_LOCKING_NUM },
  { KC_KP_4, KC_KP_5, KC_KP_6, XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX },
  { KC_KP_1, KC_KP_2, KC_KP_3, XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX },
  { KC_KP_0, XXX, KC_LALT, XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  workl }
}
};

//audio - this sohuld make it so it plays a startup song
#ifdef AUDIO_ENABLE
float tone_startup[][2] = SONG(STARTUP_SONG);
// float tone_fnlock[][2] = SONG(x);
#endif

// not sure what this whole block does
void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
    startup_user();
  #endif
}
#ifdef AUDIO_ENABLE
  void startup_user() {
    PLAY_SONG(tone_startup);
}
#endif

// /* TEMPLATE
//  * ,-----------------------------------------------------------------------------------.
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_] = {
//   {    ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     },
//   {    ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     },
//   {    ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     },
//   {    ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     }
// }
// };
