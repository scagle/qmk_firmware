/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

//#define ORYX_CONFIGURATOR

#define FIRMWARE_VERSION u8"EW99G/EnEyb"

// Times before a "tap" becomes a "hold" (milliseconds)
#undef  TAPPING_TERM    // ergodox_ez keyboard has default of 200
#define TAPPING_TERM 150

// Times before a TT() modifier switches layers (milliseconds)
#undef  TAPPING_TOGGLE  // ergodox_ez keyboard has default of 1
#define TAPPING_TOGGLE 2


#if defined(RGBLIGHT_ENABLE)

    #undef  RGBLIGHT_ANIMATIONS
//  #define RGBLIGHT_ANIMATIONS  // consumes ~10% memory. Use cautiously, or define just the ones you want.

    #undef  RGBLIGHT_SLEEP       
//  #define RGBLIGHT_SLEEP       // ~84 bytes, ~0.28%

//  #define SCAGLE_RGBLIGHT_ANIMATIONS

#endif  // defined(RGBLIGHT_ENABLE)


#if defined(COMBO_ENABLE)

    #define COMBO_COUNT 1  // Must be updated when adding new combo keys. 
                           // TODO: See if this can defined alongside combo definitions, as this location is weird.

#endif  // defined(COMBO_ENABLE)
