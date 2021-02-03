# vim: foldmethod=marker

# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

# Features {{{

RGBLIGHT_ENABLE = yes   # RGB Lights, and functionality
TAP_DANCE_ENABLE = yes # Multiple presses = Multiple variations of key presses


LTO_ENABLE = yes       # Link Time Optimization by GCC
COMMAND_ENABLE = no    # Allow "Magic" TMK commands
CONSOLE_ENABLE = no   # Allow dumping to console (with "sudo hdi_listen")

# }}} Features


# Options {{{

KEYMAP_BRANCH = $(shell \
 if [ -d "${KEYMAP_PATH}/.git" ]; then \
  cd "${KEYMAP_PATH}"; \
 fi; \
 git rev-parse --abbrev-ref HEAD 2>/dev/null)

KEYMAP_DATE = $(shell date)

OPT_DEFS += -DKEYMAP_BRANCH=\"$(KEYMAP_BRANCH)\"
OPT_DEFS += -DKEYMAP_DATE=\""$(KEYMAP_DATE)"\"

# }}} Options


# Sources {{{

# Keep track of major features to be printed out by keyboard's version key.

ENABLED_FEATURES=

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	ENABLED_FEATURES += rgb_light,
	SRC += features/rgb_light.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	ENABLED_FEATURES += tap_dance,
	SRC += features/tap_dance.c
endif

OPT_DEFS += -DENABLED_FEATURES=\""$(strip $(ENABLED_FEATURES))"\"

# }}} Sources
