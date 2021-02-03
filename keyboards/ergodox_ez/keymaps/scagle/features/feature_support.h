// Handle generic operations required by feature enabling/disabling

#ifndef _SCAGLE_FEATURE_SUPPORT_H_
#define _SCAGLE_FEATURE_SUPPORT_H_
#pragma once

#if defined(TAP_DANCE_ENABLE)
#include "tap_dance.h"
#else
#define TD(x) _______   // Assign dummy keys for disabled features
#endif // defined(TAP_DANCE_ENABLE)

#if defined(RGBLIGHT_ENABLE)
#include "rgb_light.h"
#else
#define RGB_TOG _______ // Assign dummy keys for disabled features
#endif // defined(RGBLIGHT_ENABLE)

#endif // #ifndef _SCAGLE_FEATURE_SUPPORT_H_
