#include "iris.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;


enum {
  TD_RSE = 0,
  TD_PLS,
  TD_BLSH,
  TD_BRCK
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_RASE TO(1)
#define KC_MASE TT(1)
#define KC_MAIN TO(0)

#define LSPO_KEY KC_LEFT_CURLY_BRACE
#define RSPC_KEY KC_RIGHT_CURLY_BRACE

#define KC_ZALT MT(MOD_LALT, KC_Z)
#define KC_EGUI MT(MOD_LGUI, KC_ENT)
#define KC_TCTL MT(MOD_LCTL, KC_GRAVE)

#define KC_TD TD

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for quote, twice for RAISE
  [TD_RSE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, TO(1)),
  [TD_PLS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),
  [TD_BLSH] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_BSLASH),
  [TD_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  ,  0 ,MINUS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,LBRACKET,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MASE, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,ZALT, X  , C  , V  , B  ,BSPC,         , N  , M  ,COMM,DOT ,SLSH,RASE,
  //`i----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       TCTL,LGUI,ENT,         SPC ,LEFT,RGHT
  //                  `----+----+----'        `----+----+----'
  ),

  KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,MUTE,MRWD,MFFD,MPLY,    ,                   ,    ,    ,    ,BSLASH,EQUAL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,VOLU,    ,    ,    ,    ,                   ,    , UP ,    ,    ,RBRACKET,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,VOLD,    ,    ,    ,    ,                   ,LEFT,DOWN,RGHT,    ,MAIN,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,   ,     ,    , DEL      ,    ,    ,    ,    ,    ,    ,MAIN,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,     ,    ,            ,  UP,DOWN
  //                  `----+----+----'        `----+----+----'
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
