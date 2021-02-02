// vim: foldmethod=marker

// Quick Help for Vim users, as this file will be folded by markers '{{{' and '}}}':
//     Vim-Folds:
//         zo     open fold
//         zc     close fold
//         zj/zk  jump between folds
//         zn     no folds (disable them)
//         zM     fold everything (enable them)

//* Includes {{{

#include QMK_KEYBOARD_H
#include "keymap.h"
#include "version.h"

//}}}

//* Enumerations {{{

enum macros {
    CF_VERS = SAFE_RANGE,
};

enum layers {
    // Must start at zero:
    // https://docs.qmk.fm/#/configurator_default_keymaps?id=layer-references
    HUB = 0,
    QWE,
    SYM,
    ART1,
    ART2,
    EXTRA,
    UI,
};

enum mapped_keycodes {
    // Layer Mappings
    ______________ = _______,  // Transparent Key (Uses key from lower layer)
    XXXXXXXXXXXXXX = XXXXXXX,  // NoOp Block Key (Does nothing + Blocks keys on layers beneath)
    ___CRITICAL___ = _______,  // Transparent Key (Key beneath this one is critically important)

    // Art Painting Mappings
    BRUSH_TOOL     = KC_B,
    MOVE_TOOL      = KC_T,
    FILL_TOOL      = KC_F,
    TRANSFORM_TOOL = LCTL(KC_T),
    SELECT_TOOL    = LCTL(KC_R),
    PICK_TOOL      = KC_P,
    LINE_TOOL      = KC_V,
    ERASE_TOOL     = KC_E,
    SIZE_INC       = KC_RBRACKET,  // TODO: Do a LSFT() variant of these
    SIZE_DEC       = KC_LBRACKET,
//  ALPHA_INC      = KC_O,         // TODO: Do a LSFT() variant of these
//  ALPHA_DEC      = KC_I,
    DARKEN_BRUSH   = KC_K,         // TODO: Do a LSFT() variant of these
    LIGHTEN_BRUSH  = KC_L,
    PEN_PRESSURE   = KC_W,
    SELECT_ALL     = LCTL(KC_A),
    INVERT         = LCTL(KC_I),   // [Default: Invert color, +Shift: Invert selection]

    // Art Layer Mappings
    LAYER_SHOW     = KC_TILD,
    LAYER_GO_UP    = KC_PGUP,
    LAYER_GO_DO    = KC_PGDOWN,
    LAYER_ADD      = KC_INSERT,
    LAYER_CLEAR    = KC_DEL,
    LAYER_DUP      = LCTL(KC_J),
    LAYER_MERGE    = LCTL(KC_E),
    LAYER_GROUP    = LCTL(KC_G),
    MENU_RSV_1     = HYPR(KC_1),  // Reserved for user to assign as needed
    MENU_RSV_2     = HYPR(KC_2),  // Reserved for user to assign as needed
    MENU_RSV_3     = HYPR(KC_3),  // Reserved for user to assign as needed
    MENU_RSV_4     = HYPR(KC_4),  // Reserved for user to assign as needed

    // TODO: Make these mappings dynamic and loadable, for multiple programs?
    // TODO: Make this a macro instead of static key
    CYCLE_APP_LAYOUT = _______,   // Reserved for potential implementation in future
};

enum custom_keycodes {
// "Tap Dance" keycodes
    TD_C_P_X = EZ_SAFE_RANGE,  // Copy, Paste, Cut
    TD_BRUSH_ERASE,            // Brush tool, Erase tool/modifier
};

//}}}

//* Definitions {{{

#if defined(TAP_DANCE_ENABLE)
void copy_paste_cut(qk_tap_dance_state_t *state, void *user_data);
void brush_erase(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_C_P_X]       = ACTION_TAP_DANCE_FN(copy_paste_cut),
    [TD_BRUSH_ERASE] = ACTION_TAP_DANCE_DOUBLE(BRUSH_TOOL, ERASE_TOOL),
};
#endif

// RGB Layer HSV Colors
const uint8_t layer_colors[][3] = {
//   Hue , Sat , Val
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

//* Keyboard Mappings {{{
// For all keycodes go here: ../../../../docs/keycodes.md

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //** Central Hub: Acts as router to other layers {{{

    [HUB] = LAYOUT_ergodox(

        //*** Left Hand {{{

        KC_ESCAPE          , KC_F1          , KC_F2          , KC_F3          , KC_F4          , KC_F5          , KC_F6          ,
        KC_TAB             , TO(QWE)        , TO(ART1)       , ______________ , ______________ , ______________ , ______________ ,
        LCTL_T(KC_ESCAPE)  , TO(UI)         , ______________ , ______________ , ______________ , ______________ ,
        ______________     , ______________ , ______________ , ______________ , ______________ , ______________ , CF_VERS,
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
        KC_LALT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_ENTER,
        TO(HUB),        KC_LGUI,        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX, TT(EXTRA),

        // Thumb cluster
                        XXXXXXXXXXXXXX, XXXXXXXXXXXXXX,
                                        KC_LCMD,
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
        KC_RCMD,
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
        KC_TAB,         SELECT_ALL,     LINE_TOOL,      ______________, PICK_TOOL,      TRANSFORM_TOOL, DARKEN_BRUSH,
        KC_LCTL,        SELECT_TOOL,    FILL_TOOL,      MOVE_TOOL,      TD_BRUSH_ERASE, SIZE_INC,
        KC_LALT,        ______________, ______________, TD_C_P_X,       KC_PC_UNDO,     SIZE_DEC,       LIGHTEN_BRUSH,
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
    // FIXME: KC_LSHIFT is a work around for doing "SHIFT(LAYER_CLEAR) == LAYER_DELETE", since SHIFT is very uncomfortable here.

    [ART2] = LAYOUT_ergodox(
        //*** Left Hand {{{

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

        //*** Right Hand {{{

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

//* Keyboard Functions {{{

//** "Tap Dance" Functions {{{

#if defined(TAP_DANCE_ENABLE)

// Tap 1: Copy
// Tap 2: Paste
// Tap 3: Cut
void copy_paste_cut(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_MAC_CUT);
    } else if (state->count == 2) {
        register_code16(KC_MAC_COPY);
    } else {
        register_code16(KC_MAC_PASTE);
    }
}

#endif // defined(TAP_DANCE_ENABLE)

//}}}

rgblight_config_t rgblight_config;
bool suspended = false;
bool disable_layer_color = 0;
uint8_t last_layer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case TOGGLE_LAYER_COLOR:
            if (record->event.pressed)
            {
                disable_layer_color ^= 1;
            }
            return false;

        case CF_VERS: // Print out the version/branch/date of compilation upon keypress
            if (record->event.pressed)
            {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " KEYMAP_BRANCH " (" KEYMAP_DATE ")");
            }
            return false;

        default:
            return true;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state)
{

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

void keyboard_post_init_user(void)
{
    layer_state_set_user(layer_state);
    // Customise these values to desired behaviour
    debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;
}

//}}}
