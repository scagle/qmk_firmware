# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

LTO_ENABLE = yes        # Link Time Optimization by GCC
#RGBLIGHT_ENABLE = yes   # RGB Lights, and functionality
#TAP_DANCE_ENABLE = yes  # Multiple presses = Multiple variations of key presses

COMMAND_ENABLE = no     # Allow "Magic" TMK commands
#WEBUSB_ENABLE = yes    # Used with Ergodox EZ website configuration viewer
#ORYX_ENABLE = yes      # Used with Ergodox EZ website configuration viewer

# Debug Enables
#CONSOLE_ENABLE = yes   # Allow dumping to console (with "sudo hdi_listen")

KEYMAP_BRANCH = $(shell \
 if [ -d "${KEYMAP_PATH}/.git" ]; then \
  cd "${KEYMAP_PATH}"; \
 fi; \
 git rev-parse --abbrev-ref HEAD 2>/dev/null)

KEYMAP_DATE = $(shell date)

OPT_DEFS += -DKEYMAP_BRANCH=\"$(KEYMAP_BRANCH)\" 
OPT_DEFS += -DKEYMAP_DATE=\""$(KEYMAP_DATE)"\"
