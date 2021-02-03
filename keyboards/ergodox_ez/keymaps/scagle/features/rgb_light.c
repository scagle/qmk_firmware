#include "rgb_light.h"
#include QMK_KEYBOARD_H

inline void toggle_rgb(keyrecord_t *record)
{
    if (record->event.pressed)
    {
        rgb_enabled ^= 1;
    }
}

inline void update_rgb(uint8_t layer) {
    // Write to Glow LEDs (TODO: Figure out why this needs to be written every time)
    if (rgblight_config.enable == true) {
        if (rgb_enabled) {
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(1);
            rgblight_sethsv_noeeprom(layer_colors[layer][0], layer_colors[layer][1], layer_colors[layer][2]);
        }
        else {
            rgblight_disable_noeeprom();
        }
    }
}
