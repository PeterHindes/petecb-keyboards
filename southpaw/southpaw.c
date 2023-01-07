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


led_config_t g_led_config = { { // Key Matrix to LED Index
    // Normal All
    {  0,      1,      2,      3,      4     },
    // Normal All
    {  5,      6,      7,      8,      NO_LED},
    // Normal All
    {  9,     10,     11,     12,      NO_LED},
    // Normal except last=plus
    { 13,     14,     15,     16,      17    },
    // Normal excpet last=enter and middle=fat_zero
    { 18, NO_LED,     19,     20,      21    }
 }, { // LED Index to Physical Position
    {0  ,0 },  {56  ,0 },   {112 ,0 },   {168 ,0 },   {224 ,0 },
    {0  ,16},  {56  ,16},   {112 ,16},   {168 ,16},   /*BLANK*/
    {0  ,32},  {56  ,32},   {112 ,32},   {168 ,32},   /*BLANK*/
    {0  ,48},  {56  ,48},   {112 ,48},   {168 ,48},   {220 ,24},
    {0  ,64},  /*BLANK*/    {84  ,64},   {168 ,64},   {220 ,56}
 }, {
     LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
     LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
     LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
     LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
     LED_FLAG_KEYLIGHT,                    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
 } };

