// vim: foldmethod=marker

#ifndef _SCAGLE_GLOBAL_DEFINITIONS_H_
#define _SCAGLE_GLOBAL_DEFINITIONS_H_
#pragma once

#include QMK_KEYBOARD_H

// Defines {{{

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

// Enums {{{

enum mapped_key_codes {

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

enum custom_key_codes {
    CKC_VERSION = EZ_SAFE_RANGE,                  // Type out version/compilation info
};

//}}}

#endif // #ifndef _SCAGLE_GLOBAL_DEFINITIONS_H_
