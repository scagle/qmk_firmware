#include "rgb_light.h"

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
uint8_t rgb_enabled = 1;
rgblight_config_t rgblight_config;


void toggle_rgb(keyrecord_t *record)
{
    if (record->event.pressed)
    {
        rgb_enabled ^= 1;
    }
}

void update_rgb(uint8_t layer) {
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

#if defined(SCAGLE_RGBLIGHT_STARTUP_ANIMATION)

//TODO: Implement if/when necessary

//static uint8_t counter = 0;
//void begin_startup_rgb_animation() {
//
//}
//
//static void update_startup_rgb_animation() {
//
//}

#endif // defined(SCAGLE_RGBLIGHT_STARTUP_ANIMATION)
