#ifndef CONFIG_H
#define CONFIG_H
#include "config_common.h"

#define VENDOR_ID     0xFEAE
#define PRODUCT_ID    0x8847
#define DEVICE_VER    0x0001
#define MANUFACTURER  TheVan Keyboards
#define PRODUCT       V4N4G0N
#define DESCRIPTION   V4N4G0N

#define MATRIX_ROWS 5
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { F0, F1, F4, F6, F7 }
#define MATRIX_COL_PINS { F5, B0, B1, B2, B3, B7, D2, D3, D5, D4, D6, D7 }




#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_LEVELS 1
#define BACKLIGHT_PIN B7

#define DEBOUNCE 5
#define TAPPING_TERM 175

#define USB_MAX_POWER_CONSUMPTION 100
#define PERMISSIVE_HOLD
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )
#endif