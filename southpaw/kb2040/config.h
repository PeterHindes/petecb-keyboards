// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define MATRIX_COL_PINS \
    { GP5 , GP6 , GP7 , GP8 , GP9 }
#define MATRIX_ROW_PINS \
    { GP0  , GP1 , GP2 , GP3 , GP4  }
#define DEBUG_MATRIX_SCAN_RATE

// #define QMK_WAITING_TEST_BUSY_PIN GP8
// #define QMK_WAITING_TEST_YIELD_PIN GP9

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN GP19
    #define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral
    // #define NOP_FUDGE 0.2
#endif

#define ENCODERS_PAD_B { GP26, GP26, GP26 }
#define ENCODERS_PAD_A { GP27, GP28, GP29 }

// settings for the oled keyboard demo with Adafruit 0.91" OLED display on the Stemma QT port
#define OLED_DISPLAY_128X32
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP12
#define I2C1_SCL_PIN GP13

