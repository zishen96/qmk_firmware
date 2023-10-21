#include <stdlib.h>
#include <time.h>

/**
 * Custom keycode definition for use in keymap
 * Z_mcLCL  :   Auto left click
 * Z_mcSPC  :   Auto spacebar spam
 */
enum { Z_mcLCL = SAFE_RANGE, Z_mcSPC };

#ifndef AUTO_LEFTCLICK_KEY
#    define AUTO_LEFTCLICK_KEY KC_BTN1
#endif

#ifndef AUTO_SPACE_KEY
#    define AUTO_SPACE_KEY KC_SPC
#endif

/**
 * Custom code init
 */
void keyboard_post_init_user(void) {
    srand(timer_read());
}

/**
 * Configuration for macro repeat interval + random drift range
 */
static uint16_t MIN_REPEAT_INTERVAL = 96;
static uint16_t DRIFT_RANGE         = 88;

/**
 * Internal macro processing state
 */
static deferred_token auto_leftClick_token = INVALID_DEFERRED_TOKEN;
static deferred_token auto_space_token     = INVALID_DEFERRED_TOKEN;

/**
 * Macro callback function
 */
static uint32_t auto_leftClick_callback(uint32_t trigger_time, void *cb_arg) {
    tap_code_delay(AUTO_LEFTCLICK_KEY, 8);
    return MIN_REPEAT_INTERVAL + rand() % DRIFT_RANGE;
}

static uint32_t auto_space_callback(uint32_t trigger_time, void *cb_arg) {
    tap_code_delay(AUTO_SPACE_KEY, 8);
    return MIN_REPEAT_INTERVAL + rand() % DRIFT_RANGE;
}

/**
 * Macro start
 */
static void auto_leftClick_start(void) {
    if (auto_leftClick_token == INVALID_DEFERRED_TOKEN) {
        uint32_t next_delay_ms = auto_leftClick_callback(0, NULL);
        auto_leftClick_token   = defer_exec(next_delay_ms, auto_leftClick_callback, NULL);
    }
}
static void auto_space_start(void) {
    if (auto_space_token == INVALID_DEFERRED_TOKEN) {
        uint32_t next_delay_ms = auto_space_callback(0, NULL);
        auto_space_token   = defer_exec(next_delay_ms, auto_space_callback, NULL);
    }
}

/**
 * Macro stop
 */
static void auto_leftClick_stop(void) {
    if (auto_leftClick_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(auto_leftClick_token);
        unregister_code16(AUTO_LEFTCLICK_KEY);
        auto_leftClick_token = INVALID_DEFERRED_TOKEN;
    }
}
static void auto_space_stop(void) {
    if (auto_space_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(auto_space_token);
        unregister_code16(AUTO_SPACE_KEY);
        auto_space_token = INVALID_DEFERRED_TOKEN;
    }
}

/**
 * Processing event
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Auto left click
        case Z_mcLCL:
            if (record->event.pressed) {
                auto_leftClick_start();
            } else {
                auto_leftClick_stop();
            }
            return false;

        // Auto spacebar
        case Z_mcSPC:
            if (record->event.pressed) {
                auto_space_start();
            } else {
                auto_space_stop();
            }
            return false;
    }
    return true;
}
