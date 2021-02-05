// vim: foldmethod=marker

// Quick Help for Vim users, as this file will be folded by markers
//     Vim-Folds:
//         zo     open fold
//         zc     close fold
//         zj/zk  jump between folds
//         zn     no folds (disable them)
//         zM     fold everything (enable them)

// Includes {{{

#include QMK_KEYBOARD_H
#include "version.h"
#include "global_definitions.h"
#include "features/feature_support.h"

// }}}

// Keyboard Enums {{{

// Alias enums for layers
// Must start at zero:
// https://docs.qmk.fm/#/configurator_default_keymaps?id=layer-references
enum layers {
    HUB = 0, // Central-Hub/BIOS Layer to redirect to appropriate layers
    QWE,     // QWERTY Layer
    SYM,     // Symbols Layer
    ART1,    // Digital Art Layer 1
    ART2,    // Digital Art Layer 2
    EXTRA,   // Misc Layer (IE: Function Keys, Numpad)
    UI,      // User Interface Layer (IE: Mouse functions, RGB, Media, EEPROM Flash)
};

//}}}

// Keyboard Mappings {{{
// For all keycodes go here: ../../../../docs/keycodes.md

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Central Hub: Acts as router to other layers {{{

    [HUB] = LAYOUT_ergodox(

        // Left Hand {{{

        KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,
        KC_TAB,         TO(QWE),        TO(ART1),       ______________, ______________, ______________, ______________,
        LCTL_T(KC_ESCAPE), TO(UI),      ______________, ______________, ______________, ______________,
        ______________, ______________, ______________, ______________, ______________, ______________, CKC_VERSION,
        ______________, ______________, ______________, ______________, TT(EXTRA),

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        KC_SPACE,       KC_LSHIFT,      ______________,

        //}}}

        // Right Hand {{{

        KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_F13,
        ______________, ______________, ______________, ______________, ______________, ______________, KC_F14,
                        ______________, ______________, ______________, ______________, ______________, KC_ENTER,
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       ______________,

        // Thumb cluster
        ______________, ______________,
        ______________,
        MO(UI),         KC_ENTER,       KC_BSPACE

        //}}}

    ),

    //}}}

    // QWERTY Base {{{

    [QWE] = LAYOUT_ergodox(

        // Left Hand {{{

        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           XXXXXXXXXXXXXX,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_BSPACE,
        KC_LCTL,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
        KC_LALT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_ENTER,
        TO(HUB),        KC_LGUI,        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, TT(EXTRA),

        // Thumb cluster
                        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
                                        KC_LCMD,
        KC_SPACE,       KC_LSHIFT,      MO(SYM),

        //}}}

        // Right Hand {{{

        XXXXXXXXXXXXXX, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
        XXXXXXXXXXXXXX, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_SLASH,
                        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_ENTER,
        XXXXXXXXXXXXXX, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_HYPR,
                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_MEH,

        // Thumb cluster
        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
        KC_RCMD,
        MO(UI),         KC_ENTER,       KC_BSPACE

        //}}}

    ),

    //}}}

    // Generic Symbols {{{

    [SYM] = LAYOUT_ergodox(

        // Left Hand {{{

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

        // Right Hand {{{

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

    // Digital Art Base 1 {{{

    [ART1] = LAYOUT_ergodox(

        // Left Hand {{{

        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,
        KC_TAB,         SELECT_ALL,     LINE_TOOL,      ______________, PICK_TOOL,      TRANSFORM_TOOL, DARKEN_BRUSH,
        KC_LCTL,        SELECT_TOOL,    FILL_TOOL,      MOVE_TOOL,      TD(TD_BR_ER),   SIZE_INC,
        KC_LALT,        ______________, ______________, TD(TD_C_P_X),   KC_PC_UNDO,     SIZE_DEC,       LIGHTEN_BRUSH,
        TO(HUB),        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,


        // Thumb cluster
                        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
                                        CYCLE_APP_LAYOUT,
        KC_SPACE,       KC_LSHIFT,      MO(ART2),

        //}}}

        // Right Hand {{{

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

    // Digital Art Base 2 {{{

    [ART2] = LAYOUT_ergodox(

        // Left Hand {{{

        ______________, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,
        KC_LSHIFT,      INVERT,         ______________, LAYER_GO_UP,    LAYER_ADD,      LAYER_CLEAR,    ______________,
        ______________, MENU_RSV_1,     MENU_RSV_2,     LAYER_GO_DO,    LAYER_SHOW,     LAYER_GROUP,
        ______________, MENU_RSV_3,     MENU_RSV_4,     LAYER_MERGE,    ___CRITICAL___, LAYER_DUP,      PEN_PRESSURE,
        TO(HUB),        ______________, ______________, ______________, ______________,

        // Thumb cluster
                        ______________, ______________,
                                        ______________,
        ______________, ______________, ______________,

        //}}}

        // Right Hand {{{

        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
                        ______________, ______________, ______________, ______________, ______________, ______________,
        ______________, ______________, ______________, ______________, ______________, ______________, ______________,
                                        ______________, ______________, ______________, ______________, ______________,

        // Thumb cluster

        ______________, ______________,
        ______________,
        ______________, ______________, ______________

        //}}}

    ),

    //}}}

    // Extra (Function + Numpad Keys) {{{

    [EXTRA] = LAYOUT_ergodox(

        // Left Hand {{{

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

        // Right Hand {{{

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

    // User Interface {{{

    [UI] = LAYOUT_ergodox(

        // Left Hand {{{

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

        // Right Hand {{{

        ______________,      ______________,      ______________,      ______________,      ______________,      ______________,      ______________,
        ______________,      ______________,      ______________,      ______________,      ______________,      ______________,      ______________,
                             KC_AUDIO_MUTE,       KC_MS_BTN1,          KC_MS_BTN2,          KC_MS_BTN3,          ______________,      ______________,
        ______________,      KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     KC_MEDIA_NEXT_TRACK, ______________,
                             RGB_TOG,             RGB_MODE_REVERSE,    RGB_MODE_FORWARD,    ______________,      RESET,

        // Thumb cluster
        ______________, ______________,
        ______________,
        ______________, ______________, ______________

        //}}}

    ),

    //}}}

};

//}}}

// Keyboard Functions {{{

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case TOGGLE_LAYER_COLOR:

            #if defined(RGBLIGHT_ENABLE)
            toggle_rgb(record);
            #endif // defined(RGBLIGHT_ENABLE)

            return false;


        case CKC_VERSION: // Print out the version/branch/date of compilation upon keypress

            if (record->event.pressed)
            {
                // IE: "ergodox_ez/scagle @ master Wed Feb  3 01:00:00 AM PST 2021 Features: [rgb_light, tap_dance,]"
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " KEYMAP_BRANCH " " KEYMAP_DATE " Features: [" ENABLED_FEATURES "]");
            }
            return false;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state)
{
    uint8_t layer = biton32(state);

    #if defined(SCAGLE_LEDS_ENABLE)
    update_leds(layer);
    #endif // defined(SCAGLE_LEDS_ENABLE)

    #if defined(RGBLIGHT_ENABLE)
    update_rgb(layer);
    #endif // defined(RGBLIGHT_ENABLE)

    return state;

};

void keyboard_post_init_user(void)
{
    debug_enable=false;
}

//}}}
