// Macros keycode
enum {
    Z_mcLCL = SAFE_RANGE,
    Z_mcSPC
};

// Macro intervals
uint16_t mc_leftClick_interval = 120;
uint16_t mc_space_interval = 40;

// Macro key state
bool mc_leftClick = false;
bool mc_space = false;

// Macro timer
static uint16_t mc_leftClick_timer = 0;
static uint16_t mc_space_timer = 0;

// Macro processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    switch(keycode) {
        // Autoclick - L
        case Z_mcLCL:
            if (record->event.pressed) {
                tap_code(KC_BTN1);
                tap_code(KC_BTN1);
                mc_leftClick = true;
                mc_leftClick_timer = timer_read();
            } else {
                mc_leftClick = false;
            }
            return false;  // end Z_mcLCL

        // Spam space
        case Z_mcSPC:
        if (record->event.pressed) {
            tap_code(KC_SPC);
            mc_space = true;
            mc_space_timer = timer_read();
        } else {
            mc_space = false;
        }
        return false;  // end Z_mcSPC
    }
    return true;    // end switch
}

void matrix_scan_user(void) {
    // if auto clicker is pressed
    if (mc_leftClick == true) {
        // if auto clicker timer has elapsed the interval timer
        if (timer_elapsed(mc_leftClick_timer) >= mc_leftClick_interval) {
            tap_code(KC_BTN1);
            mc_leftClick_timer = timer_read();
        }
    }
    // if spam space is pressed
    if (mc_space == true) {
        if (timer_elapsed(mc_space_timer) >= mc_space_interval) {
            tap_code(KC_SPC);
            mc_space_timer = timer_read();
        }
    }
}