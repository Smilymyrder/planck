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
#define Work   1  // workworkworkworkwork
#define Num    2  // numbers + arrowkeys (+ deadkeys?)
#define Fn     4  // functions and navigation to other layers

#define Fkeys  3  // raised numberslayer for f-keys

#define Pad    5  // numpad

// Switching layers
#define qtyl  TO(Qwerty) // go to default layer - if needed
#define wrkl  TO(Work)   // go to workworkworkworkwork
#define numl  MO(Num)    //momentary num layer
#define fkyl   MO(Fkeys)  // momentary f-keys layer
// #define fn1   MO(Fn)     //momentary function layer

// tap toggle fn layer
#define funl   TT(Fn)      // layer tap-toggle

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
 * | Ctrl | GUI  | Alt  | Num  |Enter |Space | Bspc |Shift |  [   |  ]   |  -   |  =   |
 * `-----------------------------------------------------------------------------------'
 */
[Qwerty] = {
  { KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, ___},
  { KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT},
  { funl, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, ___},
  { KC_LCTL, KC_LGUI, KC_LALT, numl, KC_ENT, KC_SPC, KC_BSPC, KC_LSFT, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL}
},

/* Workman
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Num  |  Fn  |Space | Bspc |Enter |  [   |  ]   |  -   |  =   |
 * `-----------------------------------------------------------------------------------'
 */
[Work] = {
  { KC_ESC, KC_Q, KC_D, KC_R, KC_W, KC_B, KC_J, KC_F, KC_U, KC_P, KC_SCLN, KC_BSLASH},
  { KC_TAB, KC_A, KC_S, KC_H, KC_T, KC_G, KC_Y, KC_N, KC_E, KC_O, KC_I, KC_QUOT},
  { KC_LSFT, KC_Z, KC_X, KC_M, KC_C, KC_V, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT},
  { KC_LCTL, KC_LGUI, KC_LALT, numl, funl, KC_SPC, KC_BSPC, KC_ENT, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL}
},


/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * | ___  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ___  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Fkeys |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ___  | ___  | ___  | Num  | ___  | ___  | Del  | ___  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[Num] = {
  { ___, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL},
  { ___, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX},
  { ___, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, ___},
  { ___, ___, ___, ___, fkyl, ___, KC_DEL, ___, ___, ___, ___, ___}
},

/* F-keys
 * ,-----------------------------------------------------------------------------------.
 * | ___  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ___  | F11  | F12  |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Fkeys |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ___  | ___  | ___  | ___  | ___  | ___  | ___  | ___  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[Fkeys] = {
  { ___, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, XXX},
  { ___, KC_F11, KC_F12, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX},
  { ___, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX},
  { ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___}
},

/* Function layer (toggle) Fn
 * ,-----------------------------------------------------------------------------------.
 * |Qwerty| MsB1 | MsU  | MsB2 |MsWhU |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Work | MsL  | MsD  | MsR  |MsWhD |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  | Left |  Up  | Down | Rght |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ___  | ___  | ___  |  x   | ___  | ___  | ___  | ___  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[Fn] = {
  { qtyl, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, XXX, XXX, XXX, XXX, XXX, XXX, XXX},
  { wrkl, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXX, XXX, XXX, XXX, XXX, XXX, XXX},
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
  { KC_KP_0, XXX, KC_LALT, XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  wrkl }
}
};

//audio - this sohuld make it so it plays a startup song
// #ifdef AUDIO_ENABLE
// float tone_startup[][2] = SONG(STARTUP_SONG);
// // float tone_fnlock[][2] = SONG(x);
// #endif

// not sure what this whole block does
// void matrix_init_user(void) {
//   #ifdef AUDIO_ENABLE
//     startup_user();
//   #endif
// }
// #ifdef AUDIO_ENABLE
//   void startup_user() {
//     PLAY_SONG(tone_startup);
// }
// #endif

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
