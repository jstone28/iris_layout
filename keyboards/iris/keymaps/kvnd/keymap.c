#include "iris.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum custom_keycodes {
    SHOT_MACRO = SAFE_RANGE,
};

enum {
  TD_RSE = 0,
  TD_PLS,
  TD_BLSH,
  TD_BRCK
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_RASE MO(1)
#define KC_LWR MO(2)


#define KC_ZALT MT(MOD_LALT, KC_Z)
#define KC_TCTL MT(MOD_LCTL, KC_GRAVE)

#define KC_TD TD

#define KC_WLFT LALT(KC_LEFT) // WORD LEFT
#define KC_WRHT LALT(KC_RIGHT) // WORD RIGHT

#define KC_CCRL LCTL(KC_GRAVE) // XCode - Change Editor
#define KC_CLAE HYPR(KC_GRAVE) // XCode - Close Editor
#define KC_XBCK LCTL(LGUI(KC_LEFT)) // XCode - History Back
#define KC_XFWD LCTL(LGUI(KC_RIGHT)) // XCode - History Forward

#define KC_ALRD LGUI(KC_SPACE) // Toggle Alfred

#define KC_LOCK LGUI(LCTL(KC_Q)) // Lock the screen
#define KC_SCST SHOT_MACRO // Screenshot Macro
#define KC_FCS HYPR(KC_F)

//Tap Dance Definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//   //Tap once for quote, twice for RAISE
//   [TD_RSE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, TO(1)),
//   [TD_PLS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),
//   [TD_BLSH] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_BSLASH),
//   [TD_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  ,  0 ,MINUS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,LBRACKET,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RASE, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,ZALT, X  , C  , V  , B  ,BSPC,          , N  , M  ,COMM,DOT ,SLSH,RASE,
  //`i----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       TCTL,LGUI,ENT,          SPC ,ALRD,LWR
  //                  `----+----+----'        `----+----+----'
  ),

  KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,MUTE,MRWD,MFFD,MPLY,    ,                   ,    ,    ,    ,BSLASH,EQUAL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,VOLU,    ,    ,    ,    ,                   ,WLFT, UP ,WRHT,    ,RBRACKET,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,VOLD,SCST,    ,    ,    ,                   ,LEFT,DOWN,RGHT,    ,CLAE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,   ,     ,    , DEL      ,    ,    ,   ,XBCK,XFWD,CCRL,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,     ,BSPC,        ENT ,    ,    
  //                  `----+----+----'        `----+----+----'
  ),

  KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,   ,     ,    ,         ,    ,    ,    , FCS,    ,BTN2,LOCK,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,     ,    ,            ,    ,    
  //                  `----+----+----'        `----+----+----'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
        switch(keycode) {
            case SHOT_MACRO:
                SEND_STRING(SS_LSFT(SS_LGUI("4")));
                SEND_STRING(" ");
                return false;
        }
    }
    return true;
}