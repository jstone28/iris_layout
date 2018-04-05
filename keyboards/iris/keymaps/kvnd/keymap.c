#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _RAISE 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

// #define KC_CRAS CTL_T(KC_RASE)// Hold for Ctrl, Tap for Raise
#define LSPO_KEY KC_LEFT_CURLY_BRACE
#define RSPC_KEY KC_RIGHT_CURLY_BRACE

#define KC_ZALT MT(MOD_LALT, KC_Z)
#define KC_EGUI MT(MOD_LGUI, KC_ENT)
#define KC_TCTL MT(MOD_LCTL, KC_GRAVE)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , MINUS ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , LBRACKET  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RASE, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,ZALT, X  , C  , V  , B  ,    ,         , N  , M  ,COMM,DOT ,SLSH,RASE,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       TCTL,EGUI,BSPC,         SPC ,    ,    
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,   ,   ,BSLASH,EQUAL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MUTE,    ,    ,    ,    ,                   ,    ,    , UP ,QUOT,RBRACKET,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,VOLU,    ,    ,    ,    ,                   ,    ,LEFT,DOWN,RGHT,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,VOLD,MRWD,MFFD,MPLY,    ,         ,    ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,     ,    ,            ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}
