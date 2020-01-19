#include QMK_KEYBOARD_H

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    RH_DEMO,               //Demo mode
};

keymap_config_t keymap_config;

//Tap Dance Declarations
enum {
  CTRL = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [CTRL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker( // Main keymap
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUBS, KC_HOME, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        LM(1, MOD_LSFT), KC_Z, KC_X, KC_C,   KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        MO(2),   KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT_65_ansi_blocker( // Flip KC_QUOT and KC_2 and adjust ESC to match what is on the keys when shift is held
        KC_BSLS, _______, KC_QUOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_2,             _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [2] = LAYOUT_65_ansi_blocker( // Main secondary
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_MPLY, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, KC_BSLS, KC_END, \
        TD(CTRL),RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______ ,_______, _______, _______,          _______, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, DBG_MTRX,DBG_KBD, _______, _______,          KC_PGUP, KC_VOLD, \
        RH_DEMO, _______, _______,                            _______,                            _______, RH_DEMO, KC_WBAK, KC_PGDN, KC_WFWD  \
    ),
    [3] = LAYOUT_65_ansi_blocker( // Mac-layout
        KC_ESC,  _______, KC_2,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, KC_LALT, LM(4, MOD_LGUI),                    _______,                            _______, _______, _______, _______, _______  \
    ),
    [4] = LAYOUT_65_ansi_blocker(
        KC_NUBS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    /*
    [X] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

static uint32_t flash_timer;
static uint32_t key_timer;

static bool reset;
static bool demo_held;
static bool demo_mode;
static bool rgb_flash;

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

void keyboard_post_init_user(void) {
    #ifdef CONSOLE_ENABLE
        debug_enable = true; // If debugging is compiled in then enable it to begin with
    #endif
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    if (reset && timer_elapsed32(key_timer) > 500) {
        reset_keyboard();
    }

    if (demo_held && timer_elapsed32(key_timer) > 1000) {
        dprintf("Demo mode toggle\n");
        demo_held = false;
        // Toggle demo mode
        demo_mode = !demo_mode;
        // Flash the keyboard to indicate mode change
        rgb_matrix_config.hsv.h += 128;
        flash_timer = timer_read32();
        rgb_flash = true;
    }

    if (rgb_flash && timer_elapsed32(flash_timer) > 500) {
        rgb_flash = false;
        rgb_matrix_config.hsv.h += 128;
    }

};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL   (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT    (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

#define MAC_MODE    (layer_state_is(3))
#define MOD_LGUI    (get_mods() & MOD_BIT(KC_LGUI))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    key_timer = timer_read32();

    // Handle demo-mode
    if (keycode == RH_DEMO) {
        demo_held = record->event.pressed;
        return false;
    } else if (demo_mode) {
        if (keycode == MO(2)) return true;
        return false;
    }

    /* Handle logic to facilitate win+3 = # (KC_BSLS)

    If:
    * Win is pressed down = NOOP
    * Win+3 is pressed = LGUI up if down, KC_BSLS tapped
    * Win+ANY is pressed = LGUI down, ANY reg/unreg
    * Win released = LGUI up if down, else tap LGUI if KC_BSLS not sent
    */
    static bool lgui_down;
    static bool lgui_mute;
    static bool bsls_mode;
    if (!MAC_MODE) { // We don't need any of this chutney in mac mode
        if (keycode == KC_LGUI) {
            lgui_down = record->event.pressed;
            if (!lgui_down) { // Keyup
                if (!MOD_LGUI) { // Keyup & LGUI never sent
                    if (!lgui_mute) tap_code(KC_LGUI); // Tap if KC_BSLS not sent
                } else              unregister_code(KC_LGUI); // Unsend LGUI
                lgui_mute = false;
            }
            return false;
        }
        if (lgui_down) {
            // LGUI is held down so there is some action to take
            if (keycode == KC_3) {
                // Our special key 3 has been pressed
                lgui_mute = true; // Suppress LGUI being tapped when it comes back up again
                bsls_mode = true; // Flag the keycode for special handling
                if (MOD_LGUI) unregister_code(KC_LGUI); // LGUI has been sent so unsend it
            } else {
                // Some other key pressed so begin a chord
                register_code(KC_LGUI);
            }
        }
        if (keycode == KC_3 && bsls_mode) {
            // Send/unsend KS_BSLS to get #
            if (record->event.pressed)
                register_code(KC_BSLS);
            else {
                unregister_code(KC_BSLS);
                bsls_mode = false;
            }
            return false;
        }
    }
    
    switch (keycode) {
        case RGB_VAI:
            // Drop into mac-mode on fn+ralt+w
            if (record->event.pressed && get_mods() & MOD_BIT(KC_RALT)) {
                if (MAC_MODE) {
                    layer_off(3);
                    // Turn on RGB
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                } else {
                    layer_on(3);
                    // Turn off RGB
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                }
                return false;
            }
            return true;
        case KC_BSLS:
            if (MODS_SHIFT && MODS_CTRL) { // Support ctrl+shift+esc
                if (record->event.pressed) tap_code(KC_ESC);
                return false;
            }
            return true;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            reset = record->event.pressed;
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
