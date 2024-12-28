/*
 * SPDX-License-Identifier MIT License
 *
 * Copyright (c) 2024 Joshua Watt
 */
#include "keymaps.h"
#include "usb_hid_keys.h"
#include "util.h"

#include <stdint.h>

/* This key mapping maps the keys to the VICE positional layout, which should
 * provide a 1:1 mapping of the keys */
PROGMEM const struct keymap vice_keymap = {
    /* RESTORE */ HID_KEY_PAGE_UP,
    {
        {
            /* R, C */
            /* 0, 0 - DEL */ HID_KEY_BACKSPACE,
            /* 0, 1 - RET */ HID_KEY_ENTER,
            /* 0, 2 - LR */ HID_KEY_RIGHT_ARROW,
            /* 0, 3 - F7 */ HID_KEY_F7,
            /* 0, 4 - F1 */ HID_KEY_F1,
            /* 0, 5 - F3 */ HID_KEY_F3,
            /* 0, 6 - F5 */ HID_KEY_F5,
            /* 0, 7 - UD */ HID_KEY_DOWN_ARROW,
        },
        {

            /* 1, 0 - 3 */ HID_KEY_3,
            /* 1, 1 - W */ HID_KEY_W,
            /* 1, 2 - A */ HID_KEY_A,
            /* 1, 3 - 4 */ HID_KEY_4,
            /* 1, 4 - Z */ HID_KEY_Z,
            /* 1, 5 - S */ HID_KEY_S,
            /* 1, 6 - E */ HID_KEY_E,
            /* 1, 7 - L SHIFT */ HID_KEY_LEFT_SHIFT,
        },
        {

            /* 2, 0 - 5 */ HID_KEY_5,
            /* 2, 1 - R */ HID_KEY_R,
            /* 2, 2 - D */ HID_KEY_D,
            /* 2, 3 - 6 */ HID_KEY_6,
            /* 2, 4 - C */ HID_KEY_C,
            /* 2, 5 - F */ HID_KEY_F,
            /* 2, 6 - T */ HID_KEY_T,
            /* 2, 7 - X */ HID_KEY_X,
        },
        {

            /* 3, 0 - 7 */ HID_KEY_7,
            /* 3, 1 - Y */ HID_KEY_Y,
            /* 3, 2 - G */ HID_KEY_G,
            /* 3, 3 - 8 */ HID_KEY_8,
            /* 3, 4 - B */ HID_KEY_B,
            /* 3, 5 - H */ HID_KEY_H,
            /* 3, 6 - U */ HID_KEY_U,
            /* 3, 7 - V */ HID_KEY_V,
        },
        {

            /* 4, 0 - 9 */ HID_KEY_9,
            /* 4, 1 - I */ HID_KEY_I,
            /* 4, 2 - J */ HID_KEY_J,
            /* 4, 3 - 0 */ HID_KEY_0,
            /* 4, 4 - M */ HID_KEY_M,
            /* 4, 5 - K */ HID_KEY_K,
            /* 4, 6 - O */ HID_KEY_O,
            /* 4, 7 - N */ HID_KEY_N,
        },
        {

            /* 5, 0 - + */ HID_KEY_MINUS,
            /* 5, 1 - P */ HID_KEY_P,
            /* 5, 2 - L */ HID_KEY_L,
            /* 5, 3 - - */ HID_KEY_EQUAL,
            /* 5, 4 - . */ HID_KEY_PERIOD,
            /* 5, 5 - : */ HID_KEY_SEMICOLON,
            /* 5, 6 - @ */ HID_KEY_LEFT_BRACKET,
            /* 5, 7 - , */ HID_KEY_COMMA,
        },
        {

            /* 6, 0 - £ */ HID_KEY_END,
            /* 6, 1 - * */ HID_KEY_RIGHT_BRACKET,
            /* 6, 2 - ; */ HID_KEY_QUOTE,
            /* 6, 3 - HOME */ HID_KEY_HOME,
            /* 6, 4 - R SHIFT */ HID_KEY_RIGHT_SHIFT,
            /* 6, 5 - = */ HID_KEY_PAGE_DOWN,
            /* 6, 6 - ↑ */ HID_KEY_BACKSLASH,
            /* 6, 7 - / */ HID_KEY_SLASH,
        },
        {

            /* 7, 0 - 1 */ HID_KEY_1,
            /* 7, 1 - ← */ HID_KEY_GRAVE_ACCENT,
            /* 7, 2 - CRTL */ HID_KEY_TAB,
            /* 7, 3 - 2 */ HID_KEY_2,
            /* 7, 4 - SPACE */ HID_KEY_SPACEBAR,
            /* 7, 5 - C= */ HID_KEY_LEFT_CONTROL,
            /* 7, 6 - Q */ HID_KEY_Q,
            /* 7, 7 - RUN/STOP */ HID_KEY_ESCAPE,
        },
    },
    {
        /* Aux 0 - Joystick 1 down */ HID_KEY_KP_PLUS,
        /* Aux 1 - Joystick 1 up */ HID_KEY_KP_MINUS,
        /* Aux 2 - Joystick 1 left */ HID_KEY_SLASH,
        /* Aux 3 - Joystick 1 right */ HID_KEY_KP_ASTERIX,
        /* Aux 4 - Joystick 1 button */ HID_KEY_KP_5,
        /* Aux 5 */ HID_KEY_F8,
        /* Aux 6 */ HID_KEY_F9,
        /* Aux 7 */ HID_KEY_F10,
        /* Aux 8 - Joystick 2 Down */ HID_KEY_KP_8,
        /* Aux 9 - Joystick 2 Up */ HID_KEY_KP_2,
        /* Aux 10 - Joystick 2 Left */ HID_KEY_KP_4,
        /* Aux 11 - Joystick 2 Right */ HID_KEY_KP_6,
        /* Aux 12 - Joystick 2 Button */ HID_KEY_KP_0,
        /* Aux 13 */ HID_KEY_F11,
        /* Aux 14 */ HID_KEY_F12,
        /* Aux 15 */ HID_KEY_LEFT_ALT,
    }};

