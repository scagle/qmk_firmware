/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

//#define ORYX_CONFIGURATOR

#define FIRMWARE_VERSION u8"EW99G/EnEyb"

// Times before a "tap" becomes a "hold" (milliseconds)
#define TAPPING_TERM 200

#if defined(RGBLIGHT_ENABLE)
    #define RGBLIGHT_ANIMATIONS  // supposedly consumes a lot of bytes
    #define RGBLIGHT_SLEEP
    #define SCAGLE_RGBLIGHT_ANIMATIONS
#endif  // defined(RGBLIGHT_ENABLE)

#if defined(COMBO_ENABLE)
    #define COMBO_COUNT 1
#endif  // defined(COMBO_ENABLE)
