#include QMK_KEYBOARD_H
#include "os_detection.h"
#include <print.h>

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
// uint16_t cursor_pos[2] = {0,0};
// void cursorCardinalMove(uint8_t direction) { // North = 0, East = 1, South = 2, West = 3
//     switch (direction) {
//         case 0:
//             if(cursor_pos[1] > 0)
//                 cursor_pos[1] -= 1;
//             break;
//         case 1:
//             if(cursor_pos[0] < 65535)
//                 cursor_pos[0] += 1;
//             break;
//         case 2:
//             if(cursor_pos[1] < 65535)
//                 cursor_pos[1] += 1;
//             break;
//         case 3:
//             if(cursor_pos[0] > 0)
//                 cursor_pos[0] -= 1;
//             break;
//     }
// }

uint16_t cursor_pos = 0;
uint16_t maxCursorPos = 0;
// boolean direction taken
void cursorLinearLimitedMove(bool direction) {
    if (direction) {
        if (cursor_pos < maxCursorPos)
            cursor_pos += 1;
    } else {
        if (cursor_pos > 0)
            cursor_pos -= 1;
    }
    dprintf("cursorLinearLimitedMove: %d", cursor_pos);
}
void newMenu(uint16_t newMax) {
    maxCursorPos = newMax;
    // I like this but for our application a change means a new menu so a reset is more appropreate
    // if (cursor_pos > maxCursorPos)
    //     cursor_pos = maxCursorPos;
    cursor_pos = 0;
}


bool oledNavMode = true;
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
    case 0:
        if (clockwise) {
            if (oledNavMode){
                cursorLinearLimitedMove(true);
            } else {
                tap_code(KC_A);
            }
        } else {
            if (oledNavMode){
                cursorLinearLimitedMove(false);
            } else {
                tap_code(KC_Q);
            }
        }
        break;
    case 1:
        if (clockwise) {
                tap_code(KC_S);
        } else {
                tap_code(KC_W);
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
    debug_enable = true;
    debug_matrix = false;

    // TODO Make This changeable in the oled menu
    rgb_matrix_mode(RGB_MATRIX_SPLASH);

}

#ifdef OLED_ENABLE
// Array of menu items
const char * menu_items[] = {
    "Menu Item 1",
    "Menu Item 2",
    "Menu Item 3",
    "Menu Item 4",
    "Menu Item 5",
    "Menu Item 6",
};

// Nice Macro
inline int Largest(int a,int b)
{
        int r;
        r=(a>b)?a:b;
        return(r);
}
inline int Smallest(int a,int b)
{
        int r;
        r=(a<b)?a:b;
        return(r);
}

newMenu(sizeof(menu_items)/sizeof(menu_items[0]));
// Draw to oled
bool oled_task_user() {
    // oled_set_cursor(0,0);
    // char str[100];
    // sprintf(str, "Cursor: %d, %d", cursor_pos[0], cursor_pos[1]);
    // oled_write(str, false);

    // oled_set_cursor(0,1);
    // char str2[100];
    // sprintf(str2, "%c OS: %d", 0x10, detected_host_os());
    // oled_write(str2, false);

    // for each menu item
    uint16_t startPos = Largest(cursor_pos-2 , 0);
    for (uint16_t i = startPos; i < Smallest(startPos+4 , sizeof(menu_items)/sizeof(menu_items[0])); i++) // hardcoded number of lines in display
    {
        oled_set_cursor(0,i-startPos);
        char str[100];
        sprintf(str, "%c %s", (cursor_pos == i ? 0x10 : 0x20), menu_items[i]);
        oled_write(str, false);
    }


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
