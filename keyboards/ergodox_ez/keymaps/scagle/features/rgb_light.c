#include "features/rgb_light.h"
#include "timer.h"

#define UPDATE_CONSUMED true
#define UPDATE_NOT_CONSUMED false

const uint8_t layer_colors[][3] = {
//   Hue , Sat , Val
    {0   , 0   , 255},  // Neutral for base layer

    {0   , 200 , 255},  // 1 and 2 need highly distinguishable colors
    {127 , 255 , 255},

    {63  , 200 , 255},  // 3 and 4 need highly distinguishable colors
    {190 , 255 , 255},

    {225 , 200 , 255},  // W/E for extras that I almost never use

    {225 , 255 , 255},  // SPIZZAZY for the fun UI layer
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
