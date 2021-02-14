# vim: foldmethod=marker

# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file


# Features {{{

# My Custom Features
SCAGLE_LEDS_ENABLE = yes      # [+]   Onboard LEDs
SCAGLE_KEY_SWAP = yes         # [?]   Dynamically Swappable keys

# QMK/External Features
RGBLIGHT_ENABLE = yes         # [+++] RGB Lights, and functionality
TAP_DANCE_ENABLE = yes        # [+]   Multiple presses = Multiple variations of key presses
COMBO_ENABLE = no             # [?]   TODO: Combination of keys = specific unique key press

LTO_ENABLE = yes              # [--]  Link Time Optimization by GCC
COMMAND_ENABLE = no           # [++]  Allow "Magic" TMK commands
CONSOLE_ENABLE = no           # [+++] Allow dumping to console (with "sudo hdi_listen")

# }}} Features


# Sources {{{

# Keep track of features to be printed out by keyboard's CKC_VERSION key.
ENABLED_FEATURES=

ifeq ($(strip $(SCAGLE_LEDS_ENABLE)), yes)
	ENABLED_FEATURES += leds,
	SRC += features/leds.c
	OPT_DEFS += -DSCAGLE_LEDS_ENABLE  # Add it manually, since it's custom
endif

ifeq ($(strip $(SCAGLE_KEY_SWAP)), yes)
	ENABLED_FEATURES += key_swap,
	SRC += features/key_swap.c
	OPT_DEFS += -DSCAGLE_KEY_SWAP  # Add it manually, since it's custom
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	ENABLED_FEATURES += rgb_light,
	SRC += features/rgb_light.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	ENABLED_FEATURES += tap_dance,
	SRC += features/tap_dance.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
	ENABLED_FEATURES += combo,
	SRC += features/combo.c
endif

# }}} Sources


# Options {{{

KEYMAP_BRANCH = $(shell \
 if [ -d "${KEYMAP_PATH}/.git" ]; then \
  cd "${KEYMAP_PATH}"; \
 fi; \
 git rev-parse --abbrev-ref HEAD 2>/dev/null)

KEYMAP_DATE = $(shell date)

OPT_DEFS += -DKEYMAP_BRANCH=\"$(KEYMAP_BRANCH)\"
OPT_DEFS += -DKEYMAP_DATE=\""$(KEYMAP_DATE)"\"
OPT_DEFS += -DENABLED_FEATURES=\""$(strip $(ENABLED_FEATURES))"\"


# }}} Options
