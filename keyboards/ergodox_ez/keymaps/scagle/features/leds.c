#include "leds.h"
#include QMK_KEYBOARD_H
#include "global_definitions.h"

uint8_t last_layer = 0;

void update_leds(uint8_t layer) 
{
    // Only update LEDs on layer transitions
    if (layer != last_layer) {

        last_layer = layer;

        // Check if Indicator LEDs should be on
        if (layer) {
            ergodox_board_led_on();
        } else {
            ergodox_board_led_off();
        }

        // Turn on LEDs to represent current layer (as binary)
        for (int i = NUM_LEDS; i > 0; i--) {
            if (layer >> (NUM_LEDS - i) & 0x1) {
                ergodox_right_led_on(i);
            } else {
                ergodox_right_led_off(i);
            }
        }
    }
}
