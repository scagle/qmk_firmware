// vim: foldmethod=marker

#include "tap_dance.h"

#define REGISTER true
#define UNREGISTER false


// Function Prototypes {{{
// TAP...TAP...TAP...FINISH...RESET

void copy_paste_cut_finish(qk_tap_dance_state_t *state, void *user_data);
void copy_paste_cut_reset(qk_tap_dance_state_t *state, void *user_data);
static void copy_paste_cut(qk_tap_dance_state_t *state, void *user_data, const bool register_key);

// }}} Function Prototypes


// Action Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BR_ER] = ACTION_TAP_DANCE_DOUBLE(BRUSH_TOOL, ERASE_TOOL),
    [TD_C_P_X] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, copy_paste_cut_finish, copy_paste_cut_reset),
};


// Function Implementations {{{

// Copy Paste Cut: {{{
//   - 1 Tap  = Copy
//   - 2 Taps = Paste
//   - 3 Taps = Cut

void copy_paste_cut_finish(qk_tap_dance_state_t *state, void *user_data) 
{
    copy_paste_cut(state, user_data, REGISTER);
}

void copy_paste_cut_reset(qk_tap_dance_state_t *state, void *user_data) 
{
    copy_paste_cut(state, user_data, UNREGISTER);
}

static void copy_paste_cut(qk_tap_dance_state_t *state, void *user_data, const bool register_key) 
{
    if (state->count == 1) {
        if (register_key == REGISTER)      register_code16(LCTL(KC_C));
        if (register_key == UNREGISTER)  unregister_code16(LCTL(KC_C));
    } else if (state->count == 2) {
        if (register_key == REGISTER)      register_code16(LCTL(KC_P));
        if (register_key == UNREGISTER)  unregister_code16(LCTL(KC_P));
    } else {
        if (register_key == REGISTER)      register_code16(LCTL(KC_X));
        if (register_key == UNREGISTER)  unregister_code16(LCTL(KC_X));
    }
}

// }}} Copy Paste Cut

// }}} Function Implementations
