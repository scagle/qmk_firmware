// vim: foldmethod=marker

/********************************/
/*  My Keyboard Configurations  */
/********************************/

// Quick Help for Vim users, as this file will be folded by markers '{{{' and '}}}':
//     Vim-Folds:
//         zo     open fold
//         zc     close fold
//         zj/zk  jump between folds
//         zn     no folds (disable them)
//         zM     fold everything (enable them)


//* Includes {{{
#include QMK_KEYBOARD_H
#include "version.h"
//}}}


//* Defines {{{
#define KC_MAC_UNDO  LGUI(KC_Z)
#define KC_MAC_CUT   LGUI(KC_X)
#define KC_MAC_COPY  LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_MAC_SAVE  LGUI(KC_S)
#define KC_PC_UNDO   LCTL(KC_Z)
#define KC_PC_CUT    LCTL(KC_X)
#define KC_PC_COPY   LCTL(KC_C)
#define KC_PC_PASTE  LCTL(KC_V)
#define KC_PC_SAVE   LCTL(KC_S)
#define ES_LESS_MAC  KC_GRAVE
#define ES_GRTR_MAC  LSFT(KC_GRAVE)
#define ES_BSLS_MAC  ALGR(KC_6)
#define NO_PIPE_ALT  KC_GRAVE
#define NO_BSLS_ALT  KC_EQUAL
#define NUM_LEDS     3
//}}}


//* Constants {{{
const uint8_t layer_colors[][3] = {
  // Hue , Sat , Val
    {0   , 0   , 155},
    {25  , 255 , 155},
    {50  , 255 , 155},
    {100 , 255 , 155},
    {150 , 255 , 155},
    {200 , 255 , 155},
    {225 , 255 , 155},
    {255 , 255 , 155},
};
//}}}


//* Enumerations {{{
enum layers {
    HUB = 0,
    QWE,
    SYM,
    ART1,
    ART2,
    EXTRA,
    UI,
};

enum custom_keycodes {
    RGB_SLD = EZ_SAFE_RANGE,
    ______________ = _______,
    XXXXXXXXXXXXXX = XXXXXXX,
    ___CRITICAL___ = _______,  // Key on layer beneath this one is critically important

    // Krita Painting Mappings
    BRUSH_TOOL     = KC_B,
    MOVE_TOOL      = KC_T,
    FILL_TOOL      = KC_F,
    TRANSFORM_TOOL = LCTL(KC_T),
    SELECT_TOOL    = LCTL(KC_R),
    PICK_TOOL      = KC_P,
    ERASE          = KC_E,
    SIZE_INC       = KC_LBRACKET,
    SIZE_DEC       = KC_RBRACKET,
//  ALPHA_INC      = KC_I,
//  ALPHA_DEC      = KC_O,
    VALUE_INC      = KC_K,
    VALUE_DEC      = KC_L,
    PEN_PRESSURE   = KC_W,
    SELECT_ALL     = LCTL(KC_R),
    INVERT         = LCTL(KC_I),   // [Default: Invert color, +Shift: Invert selection]

    // Krita Layer Mappings
    LAYER_SHOW     = KC_TILD,
    LAYER_GO_UP    = KC_PGUP,
    LAYER_GO_DO    = KC_PGDOWN,
    LAYER_ADD      = KC_INSERT,
    LAYER_DEL      = KC_DEL,
    LAYER_DUP      = LCTL(KC_J),
    LAYER_MERGE    = LCTL(KC_E),
    LAYER_GROUP    = LCTL(KC_G),
    MENU_RSV_1     = HYPR(KC_1),  // Reserved for user to assign as needed
    MENU_RSV_2     = HYPR(KC_2),  // Reserved for user to assign as needed
    MENU_RSV_3     = HYPR(KC_3),  // Reserved for user to assign as needed
    MENU_RSV_4     = HYPR(KC_4),  // Reserved for user to assign as needed
    MENU_RSV_5     = HYPR(KC_5),  // Reserved for user to assign as needed
    MENU_RSV_6     = HYPR(KC_6),  // Reserved for user to assign as needed

    // TODO: Make these mappings dynamic and loadable, for multiple programs?
    CYCLE_APP_LAYOUT = _______,   // Reserved for potential implementation in future
};
//}}}


//* Keyboard Mappings {{{
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// For all keycodes go here: ../../../../docs/keycodes.md

    //** Central Hub: Acts as router to other layers {{{
    [HUB] = LAYOUT_ergodox(

        //*** Left Hand {{{
        KC_ESCAPE          , KC_F1          , KC_F2          , KC_F3          , KC_F4          , KC_F5          , KC_F6          ,
        KC_TAB             , TO(QWE)        , TO(ART1)        , ______________ , ______________ , ______________ , ______________ ,
        LCTL_T(KC_ESCAPE)  , TO(UI)         , ______________ , ______________ , ______________ , ______________ ,
        ______________     , ______________ , ______________ , ______________ , ______________ , ______________ , ______________ ,
        ______________     , ______________ , ______________ , ______________ , TT(EXTRA)      ,

        // Thumb cluster
                             ______________ , ______________ ,
                                              ______________ ,
        KC_SPACE           , KC_LSHIFT      , ______________ ,
        //}}}

        //*** Right Hand {{{
        KC_F7          , KC_F8          , KC_F9          , KC_F10         , KC_F11         , KC_F12         , KC_F13         ,
        ______________ , ______________ , ______________ , ______________ , ______________ , ______________ , KC_F14         ,
                         ______________ , ______________ , ______________ , ______________ , ______________ , KC_ENTER       ,
        ______________ , ______________ , ______________ , ______________ , ______________ , ______________ , ______________ ,
                                          KC_LEFT        , KC_DOWN        , KC_UP          , KC_RIGHT       , ______________ ,

        // Thumb cluster
        ______________ , ______________ ,
        ______________ ,
        MO(UI)         , KC_ENTER       , KC_BSPACE
        //}}}

    ),
    //}}}

    //** QWERTY Base {{{
    [QWE] = LAYOUT_ergodox(

        //*** Left Hand {{{
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           XXXXXXXXXXXXXX,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_BSPACE,
        KC_LCTL,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
        KC_LALT,        LCMD_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,           KC_ENTER,
        TO(HUB),        KC_LGUI,        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, TT(EXTRA),

        // Thumb cluster
                        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
                                        XXXXXXXXXXXXXX,
        KC_SPACE,       KC_LSHIFT,      MO(SYM),
        //}}}

        //*** Right Hand {{{
        XXXXXXXXXXXXXX, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
        XXXXXXXXXXXXXX, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_SLASH,
                        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_ENTER,
        XXXXXXXXXXXXXX, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_HYPR,
                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_MEH,

        // Thumb cluster
        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
        KC_HYPR,
        MO(UI),         KC_ENTER,       KC_BSPACE
        //}}}

    ),
    //}}}

    //** Generic Symbols {{{
    [SYM] = LAYOUT_ergodox(

        //*** Left Hand {{{
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, KC_TILD,        KC_COMMA,       KC_LABK,        KC_BSLASH,      KC_PLUS,        ______________,
        ______________, KC_AT,          KC_LCBR,        KC_LBRACKET,    KC_LPRN,        KC_EQUAL,
        ______________, KC_HASH,        KC_QUOTE,       KC_DQUO,        KC_DLR,         KC_MINUS,       ______________,
        TO(HUB),        ______________, ______________, ______________, ______________,

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        KC_SPACE,       KC_LSHIFT,      ______________,
        //}}}

        //*** Right Hand {{{
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, KC_ASTR,        KC_PERC,        KC_RABK,        KC_DOT,         ______________, ______________,
                        KC_SLASH,       KC_RPRN,        KC_RBRACKET,    KC_RCBR,        KC_UNDS,        ______________,
        ______________, KC_AMPR,        KC_PIPE,        KC_CIRC,        KC_EXLM,        KC_QUES,        ______________,
                                        ______________, ______________, ______________, ______________, ______________,

        // Thumb cluster
        ______________, ______________,
        ______________,
        KC_LSHIFT,      KC_ENTER,       KC_BSPACE
        //}}}

    ),
    //}}}

    //** Digital Art Base 1 {{{
    [ART1] = LAYOUT_ergodox(

        //*** Left Hand {{{
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,
        KC_TAB,         INVERT,         SELECT_ALL,     ERASE,          PICK_TOOL,      TRANSFORM_TOOL, VALUE_INC,
        KC_LCTL,        FILL_TOOL,      SELECT_TOOL,    MOVE_TOOL,      BRUSH_TOOL,     SIZE_INC,
        KC_LGUI,        KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_PC_UNDO,     SIZE_DEC,       VALUE_DEC,
        TO(HUB),        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,


        // Thumb cluster
                        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
                                        CYCLE_APP_LAYOUT,
        KC_SPACE,       KC_LSHIFT,      MO(ART2),
        //}}}

        //*** Right Hand {{{
        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
                        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
                                        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,

        // Thumb cluster
        XXXXXXXXXXXXXX , XXXXXXXXXXXXXX ,
        XXXXXXXXXXXXXX ,
        MO(UI)         , KC_ENTER       , KC_BSPACE
        //}}}

    ),
    //}}}

    //** Digital Art Base 2 {{{
    [ART2] = LAYOUT_ergodox(
        //*** Left Hand {{{
        ______________, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,
        ______________, MENU_RSV_1,     MENU_RSV_2,     LAYER_GO_UP,    LAYER_ADD,      LAYER_DEL,      ______________,
        ______________, MENU_RSV_3,     MENU_RSV_4,     LAYER_GO_DO,    LAYER_SHOW,     LAYER_DUP,
        ______________, MENU_RSV_5,     MENU_RSV_6,     LAYER_MERGE,    ___CRITICAL___, LAYER_GROUP,    ______________,
        TO(HUB),        ______________, ______________, ______________, ______________,

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        ______________, ______________, ______________,
        //}}}

        //*** Right Hand {{{
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
                        ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
                                        ______________, ______________, ______________, ______________, ______________,

        // Thumb cluster
        ______________, ______________,
        ______________,
        ______________, ______________, ______________,
        //}}}

    ),
    //}}}

    //** Extra (Function + Numpad Keys) {{{
    [EXTRA] = LAYOUT_ergodox(

        //*** Left Hand {{{
        ______________, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, ______________, ______________, ______________, ______________,

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        ______________, ______________, ______________,
        //}}}

        //*** Right Hand {{{
        KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         ______________,
        ______________, ______________, KC_7,           KC_8,           KC_9,           ______________, ______________,
                        ______________, KC_4,           KC_5,           KC_6,           ______________, ______________,
        ______________, ______________, KC_1,           KC_2,           KC_3,           ______________, ______________,
                                        KC_0,           ______________, ______________, ______________, ______________,

        // Thumb cluster
        ______________, ______________,
        ______________,
        ______________, ______________, ______________
        //}}}

    ),
    //}}}

    //** User Interface {{{
    [UI] = LAYOUT_ergodox(

        //*** Left Hand {{{
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, ______________, XXXXXXXXXXXXXX, KC_MS_UP,       XXXXXXXXXXXXXX, KC_MS_WH_UP,    ______________,
        ______________, ______________, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,
        ______________, ______________, XXXXXXXXXXXXXX, KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_MS_BTN3,     ______________,
        TO(HUB),        ______________, ______________, ______________, ______________,

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        ______________, ______________, ______________,
        //}}}

        //*** Right Hand {{{
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
                        ______________, KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,     ______________, ______________,
        ______________, ______________, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK, ______________,
                                        RGB_TOG,        ______________, ______________, ______________, RESET,

        // Thumb cluster
        ______________, ______________,
        ______________,
        ______________, KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE
        //}}}

    ),
    //}}}

};
//}}}


//* Extra Functionality {{{
rgblight_config_t rgblight_config;
bool suspended = false;
bool disable_layer_color = 0;
uint8_t last_layer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case TOGGLE_LAYER_COLOR:
            if (record->event.pressed) {
                disable_layer_color ^= 1;
            }
            return false;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    // Detect change in layers
    if (layer != last_layer) {

        last_layer = layer;

        // Check if Indicator LEDs should be on
        if (layer) {
            ergodox_board_led_on();
        } else {
            ergodox_board_led_off();
        }

        // Check which LED's need to be on (follows binary format)
        // LED's go [1, 2, 3, ...], so go backwards
        for (int i = NUM_LEDS; i > 0; i--) {
            if (layer >> (NUM_LEDS - i) & 0x1) {
                ergodox_right_led_on(i);
            } else {
                ergodox_right_led_off(i);
            }
        }
    }
    // Write to Glow LEDs (TODO: Figure out why this needs to be written every time)
    if (rgblight_config.enable == true) {
        if(!disable_layer_color) {
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(1);
            rgblight_sethsv_noeeprom(layer_colors[layer][0], layer_colors[layer][1], layer_colors[layer][2]);
        }
        else {
            rgblight_disable_noeeprom();
        }
    }

    return state;

};

void keyboard_post_init_user(void) {
    layer_state_set_user(layer_state);
}
//}}}
