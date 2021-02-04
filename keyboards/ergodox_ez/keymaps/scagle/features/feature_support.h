// Handle generic operations required by feature enabling/disabling

#ifndef _SCAGLE_FEATURE_SUPPORT_H_
#define _SCAGLE_FEATURE_SUPPORT_H_
#pragma once


#if defined(SCAGLE_LEDS_ENABLE)
#include "leds.h"
#endif // defined(SCAGLE_LEDS_ENABLE)

#if defined(TAP_DANCE_ENABLE)
#include "tap_dance.h"
#else
#define TD(x) XXXXXXX   // Assign dummy keys for disabled features
#endif // defined(TAP_DANCE_ENABLE)

#if defined(RGBLIGHT_ENABLE)
#include "rgb_light.h"
#endif // defined(RGBLIGHT_ENABLE)


#endif // #ifndef _SCAGLE_FEATURE_SUPPORT_H_
