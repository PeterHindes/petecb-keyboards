// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "southpaw.h"

void keyboard_post_init_kb(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
    keyboard_post_init_user();
}


// led_config_t g_led_config = { {
//     {  0,      1,      2,      3,      4     },
//     {  5,      6,      7,      8,      NO_LED},
//     {  9,      10,    11,     12,      NO_LED},
//     { 13,      14,    15,     16,      17    },
//     { 18,      NO_LED,19,     20,      21    }
//  }, { // TODO fix positions
//     {0,0},   {20,0},   {40,0},   {60,0},
//     {0,13},  {20,13},  {40,13},  {60,13},
//     {0,25},  {20,25},  {40,25},  {60,25},
//     {0,38},  {20,38},  {40,38},  {60,38},
//     {0,50},  {20,50},  {40,50},  {60,57},
//     {10,63},       {40,63}
//  }, {
//      4, 4, 4, 4, 4,
//      4, 4, 4, 4,
//      4, 4, 4, 4,
//      4, 4, 4, 4, 4,
//      4,    4, 4, 4,
//  } };
