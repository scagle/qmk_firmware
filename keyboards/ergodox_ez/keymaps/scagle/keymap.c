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
#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define NUM_LEDS 3
//}}}


//* Constants {{{
const uint8_t layer_colors[][3] = {
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
    DVO,
    DVO_SYM,
    QWE,
    QWE_MIR,
    QWE_SYM,
//  SYMB,
    NUMPAD,
    UI,
};

enum custom_keycodes {
    RGB_SLD = EZ_SAFE_RANGE,
    ______________ = _______,
    XXXXXXXXXXXXXX = XXXXXXX

};
//}}}


//* Keyboard Mappings {{{
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// For all keycodes go here: ../../../../docs/keycodes.md

    //** Central Hub: Acts as router to other layers {{{
    [HUB] = LAYOUT_ergodox(

        //*** Left Hand {{{
        KC_ESCAPE          , KC_F1          , KC_F2          , KC_F3          , KC_F4          , KC_F5          , KC_F6          ,
        KC_TAB             , TO(DVO)     , TO(QWE)     , ______________ , ______________ , ______________ , ______________ ,
        LCTL_T(KC_ESCAPE)  , TO(UI)         , ______________ , ______________ , ______________ , ______________ ,
        ______________     , ______________ , ______________ , ______________ , ______________ , ______________ , ______________ ,
        ______________     , ______________ , ______________ , ______________ , TT(NUMPAD)     ,

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

    //** Dvorak Base {{{
    [DVO] = LAYOUT_ergodox(

        //*** Left Hand {{{
        ______________    , KC_1           , KC_2           , KC_3           , KC_4       , KC_5 , KC_MINUS       ,
        KC_TAB            , KC_QUOTE       , KC_COMMA       , KC_DOT         , KC_P       , KC_Y , ______________ ,
        LCTL_T(KC_ESCAPE) , KC_A           , KC_O           , KC_E           , KC_U       , KC_I ,
        KC_LGUI           , KC_SCOLON      , KC_Q           , KC_J           , KC_K       , KC_X , TT(DVO_SYM) ,
        TO(HUB)           , ______________ , ______________ , ______________ , TT(NUMPAD) ,

        // Thumb cluster
                   ______________ , ______________ ,
                                    TT(NUMPAD)     ,
        KC_SPACE , KC_LSHIFT      , MO(DVO_SYM) ,
        //}}}

        //*** Right Hand {{{
        ______________ , KC_6 , KC_7    , KC_8    , KC_9  , KC_0     , ______________ ,
        TT(UI)         , KC_F , KC_G    , KC_C    , KC_R  , KC_L     , KC_SLASH       ,
                         KC_D , KC_H    , KC_T    , KC_N  , KC_S     , KC_ENTER       ,
        KC_X           , KC_B , KC_M    , KC_W    , KC_V  , KC_Z     , MO(DVO_SYM) ,
                                KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT , KC_NO          ,

        // Thumb cluster
        ______________ , ______________ ,
        ______________ ,
        MO(UI)         , KC_ENTER       , KC_BSPACE
        //}}}

    ),
    //}}}

    //** Dvorak Symbols  {{{
    //  TODO: Redo this layer as we already have a NUMPAD layer that does this, and this is poorly planned.
    [DVO_SYM] = LAYOUT_ergodox(

        //*** Left Hand {{{
        ______________, KC_EXLM,        KC_QUES,        KC_MINUS,       KC_GRAVE,       KC_UNDS,        KC_PC_COPY,
        ______________, KC_DQUO,        KC_COMMA,       KC_LCBR,        KC_RCBR,        KC_PERC,        ______________,
        ______________, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_QUES,
        ______________, KC_CIRC,        KC_PIPE,        KC_LBRACKET,    KC_RBRACKET,    KC_AT,          ______________,
        TO(HUB),        ______________, ______________, KC_LABK,        ______________,

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        KC_SPACE,       KC_LSHIFT,      ______________,
        //}}}

        //*** Right Hand {{{
        ______________, KC_TILD,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       ______________,
        ______________, KC_SLASH,       KC_7,           KC_8,           KC_9,           ______________, ______________,
                        KC_EQUAL,       KC_4,           KC_5,           KC_6,           ______________, ______________,
        ______________, KC_AMPR,        KC_1,           KC_2,           KC_3,           ______________, ______________,
                                        KC_0,           KC_DOT,         KC_BSLASH,      ______________, KC_NO,

        // Thumb cluster
        ______________, ______________,
        ______________,
        MO(UI),         KC_ENTER,       KC_BSPACE
        //}}}

    ),
    //}}}

    //** QWE Base {{{
    [QWE] = LAYOUT_ergodox(

        //*** Left Hand {{{
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           ______________,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_BSPACE,
        KC_LCTL,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
        KC_LALT,        LCMD_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,           KC_ENTER,
        TO(HUB),        KC_LGUI,        ______________, ______________, ______________,

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        KC_SPACE,       KC_LSHIFT,      TT(QWE_SYM),
        //}}}

        //*** Right Hand {{{
        ______________, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
        ______________, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
                        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_ENTER,
        ______________, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_HYPR,
                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_MEH,

        // Thumb cluster
        ______________, ______________,
        KC_HYPR,
        MO(UI),         KC_ENTER,       KC_BSPACE
        //}}}

    ),
    //}}}

    //** QWE Symbols {{{
    /*
    [SYMB] = LAYOUT_ergodox(

        // Left
        VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
        RESET,  KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
        KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
        EPRM,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                        RGB_MOD,RGB_LYR,
                                                KC_TRNS,
                                RGB_VAD,RGB_VAI,KC_TRNS,
        // Right
        KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                 KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
        KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                          KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
        RGB_TOG, RGB_SLD,
        KC_TRNS,
        KC_TRNS, RGB_HUD, RGB_HUI

    ),
    */
    //}}}

    //** QWE Left Hand Mirror (Gaming) {{{
    [QWE_MIR] = LAYOUT_ergodox(

        //*** Left Hand {{{
        KC_MINUS,       KC_0,           KC_9,           KC_8,           KC_7,           KC_6,           ______________,
        KC_BSLASH,      KC_P,           KC_O,           KC_I,           KC_U,           KC_Y,           ______________,
        ______________, KC_SCOLON,      KC_L,           KC_K,           KC_J,           KC_H,
        ______________, KC_SLASH,       KC_DOT,         KC_COMMA,       KC_M,           KC_N,           ______________,
        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       TO(QWE),

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        KC_SPACE,       KC_LSHIFT,      ______________,
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
        MO(UI),         KC_ENTER,       KC_BSPACE
        //}}}

    ),
    //}}}

    //** QWE Symbols 2 {{{
    [QWE_SYM] = LAYOUT_ergodox(

        //*** Left Hand {{{
        ______________, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ______________,
        ______________, KC_BSLASH,      KC_SLASH,       KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        ______________,
        ______________, KC_LCBR,        KC_RCBR,        KC_LPRN,        KC_RPRN,        KC_GRAVE,
        ______________, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        ______________,
        TO(HUB),        ______________, ______________, ______________, TO(QWE),

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        KC_SPACE,       KC_LSHIFT,      ______________,
        //}}}

        //*** Right Hand {{{
        ______________, ______________, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       ______________,
        ______________, ______________, KC_LABK,        KC_RABK,        ______________, ______________, ______________,
                        KC_DQUO,        KC_EQUAL,       KC_PLUS,        KC_MINUS,       KC_UNDS,        ______________,
        ______________, KC_CIRC,        KC_CIRC,        KC_ASTR,        KC_LPRN,        KC_RPRN,        ______________,
                                        ______________, ______________, ______________, ______________, ______________,

        // Thumb cluster
        ______________, ______________,
        ______________,
        ______________, KC_ENTER,       KC_BSPACE
        //}}}

    ),
    //}}}

    //** Numpad {{{
    [NUMPAD] = LAYOUT_ergodox(

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
                                        ______________, ______________, ______________, ______________, RESET,

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
