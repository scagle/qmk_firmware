#include "tap_dance.h"

void copy_paste_cut(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BR_ER] = ACTION_TAP_DANCE_DOUBLE(BRUSH_TOOL, ERASE_TOOL),
    [TD_C_P_X] = ACTION_TAP_DANCE_FN(copy_paste_cut),
};

// Copy Paste Cut:
//   - 1 Tap  = Copy
//   - 2 Taps = Paste
//   - 3 Taps = Cut
void copy_paste_cut(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_MAC_COPY);
    } else if (state->count == 2) {
        register_code16(KC_MAC_PASTE);
    } else {
        register_code16(KC_MAC_CUT);
    }
}
