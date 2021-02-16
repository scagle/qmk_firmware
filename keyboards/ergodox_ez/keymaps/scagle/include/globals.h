// All global constants used across multiple files

#ifndef _SCAGLE_GLOBALS_H_
#define _SCAGLE_GLOBALS_H_
#pragma once

#include QMK_KEYBOARD_H

#define KC_MAC_UNDO  LGUI(KC_Z)
#define KC_MAC_CUT   LGUI(KC_X)
#define KC_MAC_COPY  LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO   LCTL(KC_Z)
#define KC_PC_CUT    LCTL(KC_X)
#define KC_PC_COPY   LCTL(KC_C)
#define KC_PC_PASTE  LCTL(KC_V)
#define NUM_LEDS     3

#define DISABLED 0
#define ENABLED  1

enum mapped_key_codes {

    // Layer Mappings
    ______________ = _______,  // Transparent Key (Uses key from lower layer)
    XXXXXXXXXXXXXX = XXXXXXX,  // NoOp Block Key (Does nothing + Blocks keys on layers beneath)
    ___CRITICAL___ = _______,  // Transparent Key (Key beneath this one is critically important)

    // Art Painting Mappings
    // Legend:
    //   "_SH_" = Shift-able for alternate effect
    //   "_C_"  = Ctrl-able for alternate effect
    //   "_TG_" = Toggles effect
    BRUSH_TOOL_SH  = KC_B,         // Brush Tool | +Shift: Erase
    MOVE_TOOL      = KC_T,
    FILL_TOOL      = KC_F,
    TRANSFORM_TOOL = LCTL(KC_T),
    SELECT_TOOL_SH = LCTL(KC_R),   // Select Rect | +Shift: Select Free-hand
    PICK_TOOL      = KC_P,
    LINE_TOOL      = KC_V,
    ERASE_TOOL     = KC_E,
    BRUSH_SIZE_SH  = KC_RBRACKET,  // Increment  | +Shift: Decrement
    BRUSH_ALPHA_SH = KC_O,         // Increment  | +Shift: Decrement
    BRUSH_VAL_SH   = KC_K,         // Darken     | +Shift: Lighten
    SELECT_ALL_SH  = LCTL(KC_A),   // Select All | +Shift: Select None 
    INVERT_SH      = LCTL(KC_I),   // Inv Color  | +Shift: Inv Selection
    PEN_ANALOG_TG  = KC_W,
    PREV_BRUSH     = KC_SLASH,

    // Art Layer Mappings
    LAYER_UP_C_SH  = KC_PGUP,    // Go Up                  | +Shift:       Go Up (Skip Groups)
                                 // +Ctrl: Move Layer Up   | +Ctrl +Shift: XXXXXXXXXXXXXX
    LAYER_DO_C_SH  = KC_PGDOWN,  // Go Down                | +Shift:       Go Down (Skip Groups)
                                 // +Ctrl: Move Layer Down | +Ctrl +Shift: XXXXXXXXXXXXXX
    LAYER_SHOW     = KC_TILD,
    LAYER_ADD      = KC_INSERT,
    LAYER_CLEAR_SH = KC_DEL,     // Clear Layer | +Shift: Delete Layer
    LAYER_DUP      = LCTL(KC_J),
    LAYER_MERGE    = LCTL(KC_E),
    LAYER_GROUP    = LCTL(KC_G),
    MENU_RSV_1     = MEH(KC_1),  // Reserved for user to assign as needed
    MENU_RSV_2     = MEH(KC_2),  // Reserved for user to assign as needed
    MENU_RSV_3     = MEH(KC_3),  // Reserved for user to assign as needed
    MENU_RSV_4     = MEH(KC_4),  // Reserved for user to assign as needed
    MENU_RSV_5     = MEH(KC_5),  // Reserved for user to assign as needed
    MENU_RSV_6     = MEH(KC_6),  // Reserved for user to assign as needed

    // TODO: Make these mappings dynamic and loadable, for multiple programs?
    // TODO: Make this a macro instead of static key
    CYCLE_APP_LAYOUT = _______,   // Reserved for potential implementation in future
};

enum custom_key_codes {
    CKC_SHOW_VERSION = EZ_SAFE_RANGE,                  // Type out version/compilation info
};

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

#endif // #ifndef _SCAGLE_GLOBALS_H_
