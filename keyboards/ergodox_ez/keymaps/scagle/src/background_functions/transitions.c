#include "include/background_functions/transitions.h"
#include "include/globals.h"
#include "feature/background_functions/sleep.h"
#include "feature/ui_functions/rgb_light.h"
#include "feature/ui_functions/leds.h"

void transition(transition_t state)
{
    switch (state)
    {
        #if defined(SCAGLE_SLEEP_ENABLE)
        case WAKEUP_FROM_IDLE:
            wakeup_idle();
            break;

        case SLEEP_FROM_IDLE:
            sleep_idle();
            break;
        #endif  // defined(SCAGLE_SLEEP_ENABLE)

        case WAKEUP_FROM_POWER:
            debug_enable = DISABLED;
            set_led_enabled(ENABLED);

            #if defined(SCAGLE_LEDS_ENABLE)
            update_rgb(HUB);
            #endif  // defined(SCAGLE_LEDS_ENABLE)
            break;

        case WAKEUP_FROM_HOST:
            rgblight_enable_noeeprom();
            set_led_enabled(ENABLED);

            #if defined(SCAGLE_LEDS_ENABLE)
            update_rgb(HUB);
            #endif  // defined(SCAGLE_LEDS_ENABLE)
            break;

        case SLEEP_FROM_HOST:
            set_led_enabled(DISABLED);
            break;
    }
}
