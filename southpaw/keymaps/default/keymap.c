#include QMK_KEYBOARD_H
#include "os_detection.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_numpad_5x5(
        KC_A,
        KC_B,
        KC_C,

        RGB_TOG,
        KC_LEFT_PAREN,
        KC_RIGHT_PAREN,
        KC_CIRCUMFLEX,
        KC_PIPE,


        KC_NUM,
        KC_PSLS,
        KC_PAST,
        KC_PMNS,

        KC_P7,
        KC_P8,
        KC_P9,
        KC_PPLS,

        KC_P4,
        KC_P5,
        KC_P6,

        KC_P1,
        KC_P2,
        KC_P3,
        KC_PENT,

        KC_P0,
        KC_PDOT
        )
};

// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//      // Mapping for Base layer
//     [0] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), // Mappings for 1st Encoder
//       ENCODER_CCW_CW(KC_VOLD, KC_VOLU), // Mappings for 2nd Encoder
//       ENCODER_CCW_CW(KC_UP, KC_DOWN) // Mappings for 3nd Encoder
//       },



//     // [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),  ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  }, // Mapping for Layer 1
//     // [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  }, // Mapping for Layer 2
//     // [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) }, // Mapping for Layer 3

//     // You can add more layers here if you need them, or you can also delete lines for layers you are not using
// };
// #endif

// 2D Array with cursor position
uint16_t cursor_pos[2] = {0,0};
void cursorCardinalMove(uint8_t direction) { // North = 0, East = 1, South = 2, West = 3
    switch (direction) {
        case 0:
            if(cursor_pos[1] > 0)
                cursor_pos[1] -= 1;
            break;
        case 1:
            if(cursor_pos[0] < 65535)
                cursor_pos[0] += 1;
            break;
        case 2:
            if(cursor_pos[1] < 65535)
                cursor_pos[1] += 1;
            break;
        case 3:
            if(cursor_pos[0] > 0)
                cursor_pos[0] -= 1;
            break;
    }
}

bool oledNavMode = true;
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
    case 0:
        if (clockwise) {
            if (oledNavMode){
                cursorCardinalMove(1);
            } else {
                tap_code(KC_A);
            }
        } else {
            if (oledNavMode){
                cursorCardinalMove(3);
            } else {
                tap_code(KC_Q);
            }
        }
        break;
    case 1:
        if (clockwise) {
            if (oledNavMode){
                cursorCardinalMove(2);
            } else {
                tap_code(KC_S);
            }
        } else {
            if (oledNavMode){
                cursorCardinalMove(0);
            } else {
                tap_code(KC_W);
            }
        }
        break;
    case 2:
        if (clockwise) {
            tap_code(KC_D);
        } else {
            tap_code(KC_E);
        }
        break;

    default:
        break;
    }
    return false;
}

void keyboard_post_init_user(void) {
    // Console messages are used for update speed test results
    // debug_enable = true;

    // TODO Make This changeable in the oled menu
    rgb_matrix_mode(RGB_MATRIX_SPLASH);

}

#ifdef OLED_ENABLE
// Draw to oled
bool oled_task_user() {
    oled_set_cursor(0,0);
    char str[100];
    sprintf(str, "Cursor: %d, %d", cursor_pos[0], cursor_pos[1]);
    oled_write(str, false);

    oled_set_cursor(0,1);
    char str2[100];
    sprintf(str2, "OS: %d", detected_host_os());
    oled_write(str2, false);

    oled_set_cursor(0,2);
    char str3[100];
    sprintf(str3, "MacOS: %d", OS_MACOS);
    oled_write(str3, false);

    return false;
}
#endif

bool rgb_matrix_indicators_user(){
    led_t led_state = host_keyboard_led_state();
    if (!led_state.num_lock && detected_host_os() != OS_MACOS && detected_host_os() != OS_IOS) {
        rgb_matrix_set_color(1,RGB_WHITE);
    }
    return true; // Does not do anything unless rgb_matrix_indicators_kb uses it (rgb_matrix_indicators_ is blank by default)
}
