#include "feature/background_functions/sleep.h"

#include "include/globals.h"
#include "include/background_functions/transitions.h"

// Definitions for disabling lights after timeout
#if (SLEEP_TIME >= 127)
    #error "SLEEP_TIME has to be 126 or lower!"
#endif
#define SLEEP_TIME_HALF_MINUTES (SLEEP_TIME * 2)
#define SLEEP  255  // uint8_t - 0

static uint16_t milliseconds_since_last_key;
static uint8_t  half_minutes_since_last_key;

void wakeup_idle() 
{
    transition(WAKEUP_FROM_IDLE);
    milliseconds_since_last_key = timer_read();
    half_minutes_since_last_key = 0;
}

void sleep_idle() 
{
    transition(SLEEP_FROM_IDLE);
    half_minutes_since_last_key = SLEEP;
}

void caffeinate_idle() 
{
    if (half_minutes_since_last_key == SLEEP)
    {
        wakeup_idle();

    } else {

        milliseconds_since_last_key = timer_read();
    }
}

void update_idle() 
{
    if (half_minutes_since_last_key == SLEEP) return;

    if (half_minutes_since_last_key >= SLEEP_TIME_HALF_MINUTES)
    {
        sleep_idle();
        return;
    }

    // If 30 seconds has elapsed since last key press
    if (timer_elapsed(milliseconds_since_last_key) > 30000) 
    {
        half_minutes_since_last_key++;
        milliseconds_since_last_key = timer_read();
    }
}
