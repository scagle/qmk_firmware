#include "features/rgb_light.h"
#include "timer.h"

#define UPDATE_CONSUMED true
#define UPDATE_NOT_CONSUMED false

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
rgblight_config_t rgblight_config;

#if defined(SCAGLE_RGBLIGHT_ANIMATIONS)
static bool update_rgb_animation(void);
#endif  // defined(SCAGLE_RGBLIGHT_ANIMATIONS)

void update_rgb(uint8_t layer) {


    // Write to Glow LEDs (TODO: Figure out why this needs to be written every time)
    if (rgblight_config.enable == true)
    {
        #if defined(SCAGLE_RGBLIGHT_ANIMATIONS)
        if (update_rgb_animation() == UPDATE_CONSUMED)
            return;
        #endif  // defined(SCAGLE_RGBLIGHT_ANIMATIONS)

        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom(layer_colors[layer][0], layer_colors[layer][1], layer_colors[layer][2]);

    } else {

        rgblight_disable_noeeprom();
    }
}

#if defined(SCAGLE_RGBLIGHT_ANIMATIONS)

void flash_rgb(uint8_t hue, uint8_t sat, uint8_t val) {

}

static bool update_rgb_animation() {
    return UPDATE_NOT_CONSUMED;
}

//TODO: Implement if/when necessary

//static uint8_t counter = 0;
//void begin_startup_rgb_animation() {
//
//}
//
//static void update_startup_rgb_animation() {
//
//}

#endif  // defined(SCAGLE_RGBLIGHT_ANIMATIONS)
