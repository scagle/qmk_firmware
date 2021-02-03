#ifndef _SCAGLE_RGB_LIGHT_H_
#define _SCAGLE_RGB_LIGHT_H_
#pragma once

// Layer HSV Colors
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

#endif // #ifndef _SCAGLE_RGB_LIGHT_H_
