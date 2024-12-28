/*
 * SPDX-License-Identifier MIT License
 *
 * Copyright (c) 2024 Joshua Watt
 */
#ifndef USB_HID_KEYS_H
#define USB_HID_KEYS_H

#define HID_KEY_A (0x04)             // Keyboard a and A
#define HID_KEY_B (0x05)             // Keyboard b and B
#define HID_KEY_C (0x06)             // Keyboard c and C
#define HID_KEY_D (0x07)             // Keyboard d and D
#define HID_KEY_E (0x08)             // Keyboard e and E
#define HID_KEY_F (0x09)             // Keyboard f and F
#define HID_KEY_G (0x0A)             // Keyboard g and G
#define HID_KEY_H (0x0B)             // Keyboard h and H
#define HID_KEY_I (0x0C)             // Keyboard i and I
#define HID_KEY_J (0x0D)             // Keyboard j and J
#define HID_KEY_K (0x0E)             // Keyboard k and K
#define HID_KEY_L (0x0F)             // Keyboard l and L
#define HID_KEY_M (0x10)             // Keyboard m and M
#define HID_KEY_N (0x11)             // Keyboard n and N
#define HID_KEY_O (0x12)             // Keyboard o and O
#define HID_KEY_P (0x13)             // Keyboard p and P
#define HID_KEY_Q (0x14)             // Keyboard q and Q
#define HID_KEY_R (0x15)             // Keyboard r and R
#define HID_KEY_S (0x16)             // Keyboard s and S
#define HID_KEY_T (0x17)             // Keyboard t and T
#define HID_KEY_U (0x18)             // Keyboard u and U
#define HID_KEY_V (0x19)             // Keyboard v and V
#define HID_KEY_W (0x1A)             // Keyboard w and W
#define HID_KEY_X (0x1B)             // Keyboard x and X
#define HID_KEY_Y (0x1C)             // Keyboard y and Y
#define HID_KEY_Z (0x1D)             // Keyboard z and Z
#define HID_KEY_1 (0x1E)             // Keyboard 1 and !
#define HID_KEY_2 (0x1F)             // Keyboard 2 and @
#define HID_KEY_3 (0x20)             // Keyboard 3 and #
#define HID_KEY_4 (0x21)             // Keyboard 4 and $
#define HID_KEY_5 (0x22)             // Keyboard 5 and %
#define HID_KEY_6 (0x23)             // Keyboard 6 and ∧
#define HID_KEY_7 (0x24)             // Keyboard 7 and &
#define HID_KEY_8 (0x25)             // Keyboard 8 and *
#define HID_KEY_9 (0x26)             // Keyboard 9 and (
#define HID_KEY_0 (0x27)             // Keyboard 0 and )
#define HID_KEY_ENTER (0x28)         // Keyboard Return (ENTER)
#define HID_KEY_ESCAPE (0x29)        // Keyboard ESCAPE
#define HID_KEY_BACKSPACE (0x2A)     // Keyboard DELETE (Backspace)
#define HID_KEY_TAB (0x2B)           // Keyboard Tab
#define HID_KEY_SPACEBAR (0x2C)      // Keyboard Spacebar
#define HID_KEY_MINUS (0x2D)         // Keyboard - and (underscore)
#define HID_KEY_EQUAL (0x2E)         // Keyboard = and +
#define HID_KEY_LEFT_BRACKET (0x2F)  // Keyboard [ and {
#define HID_KEY_RIGHT_BRACKET (0x30) // Keyboard ] and }
#define HID_KEY_BACKSLASH (0x31)     // Keyboard \ and |
// #define HID_KEY_ (0x32) // Keyboard Non-US # and ˜
#define HID_KEY_SEMICOLON (0x33)      // Keyboard ; and :
#define HID_KEY_QUOTE (0x34)          // Keyboard ‘ and “
#define HID_KEY_GRAVE_ACCENT (0x35)   // Keyboard Grave Accent and Tilde
#define HID_KEY_COMMA (0x36)          // Keyboard , and <
#define HID_KEY_PERIOD (0x37)         // Keyboard . and >
#define HID_KEY_SLASH (0x38)          // Keyboard / and ?
#define HID_KEY_CAPS_LOCK (0x39)      // Keyboard Caps Lock
#define HID_KEY_F1 (0x3A)             // Keyboard F1
#define HID_KEY_F2 (0x3B)             // Keyboard F2
#define HID_KEY_F3 (0x3C)             // Keyboard F3
#define HID_KEY_F4 (0x3D)             // Keyboard F4
#define HID_KEY_F5 (0x3E)             // Keyboard F5
#define HID_KEY_F6 (0x3F)             // Keyboard F6
#define HID_KEY_F7 (0x40)             // Keyboard F7
#define HID_KEY_F8 (0x41)             // Keyboard F8
#define HID_KEY_F9 (0x42)             // Keyboard F9
#define HID_KEY_F10 (0x43)            // Keyboard F10
#define HID_KEY_F11 (0x44)            // Keyboard F11
#define HID_KEY_F12 (0x45)            // Keyboard F12
#define HID_KEY_PRINT_SCREEN (0x46)   // Keyboard PrintScreen
#define HID_KEY_SCROLL_LOCK (0x47)    // Keyboard Scroll Lock
#define HID_KEY_PAUSE (0x48)          // Keyboard Pause
#define HID_KEY_INSERT (0x49)         // Keyboard Insert
#define HID_KEY_HOME (0x4A)           // Keyboard Home
#define HID_KEY_PAGE_UP (0x4B)        // Keyboard PageUp
#define HID_KEY_DELETE_FORWARD (0x4C) // Keyboard Delete Forward
#define HID_KEY_END (0x4D)            // Keyboard End
#define HID_KEY_PAGE_DOWN (0x4E)      // Keyboard PageDown
#define HID_KEY_RIGHT_ARROW (0x4F)    // Keyboard RightArrow
#define HID_KEY_LEFT_ARROW (0x50)     // Keyboard LeftArrow
#define HID_KEY_DOWN_ARROW (0x51)     // Keyboard DownArrow
#define HID_KEY_UP_ARROW (0x52)       // Keyboard UpArrow
#define HID_KEY_NUM_LOCK (0x53)       // Keypad Num Lock and Clear
#define HID_KEY_KP_SLASH (0x54)       // Keypad /
#define HID_KEY_KP_ASTERIX (0x55)     // Keypad *
#define HID_KEY_KP_MINUS (0x56)       // Keypad -
#define HID_KEY_KP_PLUS (0x57)        // Keypad +
#define HID_KEY_KP_ENTER (0x58)       // Keypad ENTER
#define HID_KEY_KP_1 (0x59)           // Keypad 1 and End
#define HID_KEY_KP_2 (0x5A)           // Keypad 2 and Down Arrow
#define HID_KEY_KP_3 (0x5B)           // Keypad 3 and PageDn
#define HID_KEY_KP_4 (0x5C)           // Keypad 4 and Left Arrow
#define HID_KEY_KP_5 (0x5D)           // Keypad 5
#define HID_KEY_KP_6 (0x5E)           // Keypad 6
#define HID_KEY_KP_7 (0x5F)           // Keypad 7
#define HID_KEY_KP_8 (0x60)           // Keypad 8
#define HID_KEY_KP_9 (0x61)           // Keypad 9
#define HID_KEY_KP_0 (0x62)           // Keypad 0
#define HID_KEY_KP_DOT (0x63)         // Keypad . and Delete
// #define HID_KEY_KP_ (0x64) // Keyboard Non-US \and |
#define HID_KEY_KP_APP (0x65)              // Keyboard Application
#define HID_KEY_KP_POWER (0x66)            // Keyboard Power
#define HID_KEY_KP_EQUAL (0x67)            // Keypad =
#define HID_KEY_F13 (0x68)                 // Keyboard F13
#define HID_KEY_F14 (0x69)                 // Keyboard F14
#define HID_KEY_F15 (0x6A)                 // Keyboard F15
#define HID_KEY_F16 (0x6B)                 // Keyboard F16
#define HID_KEY_F17 (0x6C)                 // Keyboard F17
#define HID_KEY_F18 (0x6D)                 // Keyboard F18
#define HID_KEY_F19 (0x6E)                 // Keyboard F19
#define HID_KEY_F20 (0x6F)                 // Keyboard F20
#define HID_KEY_F21 (0x70)                 // Keyboard F21
#define HID_KEY_F22 (0x71)                 // Keyboard F22
#define HID_KEY_F23 (0x72)                 // Keyboard F23
#define HID_KEY_F24 (0x73)                 // Keyboard F24
#define HID_KEY_EXECUTE (0x74)             // Keyboard Execute
#define HID_KEY_HELP (0x75)                // Keyboard Help
#define HID_KEY_MENU (0x76)                // Keyboard Menu
#define HID_KEY_SELECT (0x77)              // Keyboard Select
#define HID_KEY_STOP (0x78)                // Keyboard Stop
#define HID_KEY_AGAIN (0x79)               // Keyboard Again
#define HID_KEY_UNDO (0x7A)                // Keyboard Undo
#define HID_KEY_CUT (0x7B)                 // Keyboard Cut
#define HID_KEY_COPY (0x7C)                // Keyboard Copy
#define HID_KEY_PASTE (0x7D)               // Keyboard Paste
#define HID_KEY_FIND (0x7E)                // Keyboard Find
#define HID_KEY_MUTE (0x7F)                // Keyboard Mute
#define HID_KEY_VOLUME_UP (0x80)           // Keyboard Volume Up
#define HID_KEY_VOLUME_DOWN (0x81)         // Keyboard Volume Down
#define HID_KEY_LOCKING_CAPS_LOCK (0x82)   // Keyboard Locking Caps Lock
#define HID_KEY_LOCKING_NUM_LOCK (0x83)    // Keyboard Locking Num Lock
#define HID_KEY_LOCKING_SCROLL_LOCK (0x84) // Keyboard Locking Scroll Lock
#define HID_KEY_KP_COMMA (0x85)            // Keypad Comma
#define HID_KEY_KP_EQUAL_SIGN (0x86)       // Keypad Equal Sign
#define HID_KEY_INTERNATIONAL_1 (0x87)     // Keyboard International1
#define HID_KEY_INTERNATIONAL_2 (0x88)     // Keyboard International2
#define HID_KEY_INTERNATIONAL_3 (0x89)     // Keyboard International3
#define HID_KEY_INTERNATIONAL_4 (0x8A)     // Keyboard International4
#define HID_KEY_INTERNATIONAL_5 (0x8B)     // Keyboard International5
#define HID_KEY_INTERNATIONAL_6 (0x8C)     // Keyboard International6
#define HID_KEY_INTERNATIONAL_7 (0x8D)     // Keyboard International7
#define HID_KEY_INTERNATIONAL_8 (0x8E)     // Keyboard International8
#define HID_KEY_INTERNATIONAL_9 (0x8F)     // Keyboard International9
#define HID_KEY_LANG_1 (0x90)              // Keyboard LANG1
#define HID_KEY_LANG_2 (0x91)              // Keyboard LANG2
#define HID_KEY_LANG_3 (0x92)              // Keyboard LANG3
#define HID_KEY_LANG_4 (0x93)              // Keyboard LANG4
#define HID_KEY_LANG_5 (0x94)              // Keyboard LANG5
#define HID_KEY_LANG_6 (0x95)              // Keyboard LANG6
#define HID_KEY_LANG_7 (0x96)              // Keyboard LANG7
#define HID_KEY_LANG_8 (0x97)              // Keyboard LANG8
#define HID_KEY_LANG_9 (0x98)              // Keyboard LANG9
#define HID_KEY_ALT_ERASE (0x99)           // Keyboard Alternate Erase
#define HID_KEY_SYSRQ (0x9A)               // Keyboard SysReq/Attention
#define HID_KEY_CANCEL (0x9B)              // Keyboard Cancel
#define HID_KEY_CLEAR (0x9C)               // Keyboard Clear
#define HID_KEY_PRIOR (0x9D)               // Keyboard Prior
#define HID_KEY_RETURN (0x9E)              // Keyboard Return
#define HID_KEY_SEPARATOR (0x9F)           // Keyboard Separator
#define HID_KEY_OUT (0xA0)                 // Keyboard Out
#define HID_KEY_OPER (0xA1)                // Keyboard Oper
#define HID_KEY_CLEAR_AGAIN (0xA2)         // Keyboard Clear/Again
#define HID_KEY_CRSEL (0xA3)               // Keyboard CrSel/Props
#define HID_KEY_EXSEL (0xA4)               // Keyboard ExSel
#define HID_KEY_KP_00 (0xB0)               // Keypad 00
#define HID_KEY_KP000 (0xB1)               // Keypad 000
#define HID_KEY_THOUSANDS_SEPARATOR (0xB2) // Thousands Separator
#define HID_KEY_DECIMAL_SEPARATOR (0xB3)   // Decimal Separator
#define HID_KEY_CURRENCY_UNIT (0xB4)       // Currency Unit
#define HID_KEY_CURRENCY_SUBUNIT (0xB5)    // Currency Sub-unit
#define HID_KEY_KP_LEFT_PAREN (0xB6)       // Keypad (
#define HID_KEY_KP_RIGHT_PAREN (0xB7)      // Keypad )
#define HID_KEY_KP_LEFT_BRACE (0xB8)       // Keypad {
#define HID_KEY_KP_RIGHT_BRACE (0xB9)      // Keypad }
#define HID_KEY_KP_TAB (0xBA)              // Keypad Tab
#define HID_KEY_KP_BACKSPACE (0xBB)        // Keypad Backspace
#define HID_KEY_KP_A (0xBC)                // Keypad A
#define HID_KEY_KP_B (0xBD)                // Keypad B
#define HID_KEY_KP_C (0xBE)                // Keypad C
#define HID_KEY_KP_D (0xBF)                // Keypad D
#define HID_KEY_KP_E (0xC0)                // Keypad E
#define HID_KEY_KP_F (0xC1)                // Keypad F
#define HID_KEY_KP_XOR (0xC2)              // Keypad XOR
#define HID_KEY_KP_CARET (0xC3)            // Keypad ∧
#define HID_KEY_KP_PERCENT (0xC4)          // Keypad %
#define HID_KEY_KP_LESS_THAN (0xC5)        // Keypad <
#define HID_KEY_KP_GREATER_THAN (0xC6)     // Keypad >
#define HID_KEY_KP_AMPERSAND (0xC7)        // Keypad &
#define HID_KEY_KP_AND (0xC8)              // Keypad &&
#define HID_KEY_KP_PIPE (0xC9)             // Keypad |
#define HID_KEY_KP_OR (0xCA)               // Keypad ||
#define HID_KEY_KP_COLON (0xCB)            // Keypad :
#define HID_KEY_KP_HASH (0xCC)             // Keypad #
#define HID_KEY_KP_SPACE (0xCD)            // Keypad Space
#define HID_KEY_KP_AT (0xCE)               // Keypad @
#define HID_KEY_KP_BANG (0xCF)             // Keypad !
#define HID_KEY_KP_MEM_STORE (0xD0)        // Keypad Memory Store
#define HID_KEY_KP_MEM_RECALL (0xD1)       // Keypad Memory Recall
#define HID_KEY_KP_MEM_CLEAR (0xD2)        // Keypad Memory Clear
#define HID_KEY_KP_MEM_ADD (0xD3)          // Keypad Memory Add
#define HID_KEY_KP_MEM_SUBTRACT (0xD4)     // Keypad Memory Subtract
#define HID_KEY_KP_MEM_MULTIPLY (0xD5)     // Keypad Memory Multiply
#define HID_KEY_KP_MEM_DIVIDE (0xD6)       // Keypad Memory Divide
#define HID_KEY_KP_PLUS_MINUS (0xD7)       // Keypad +/-
#define HID_KEY_KP_CLEAR (0xD8)            // Keypad Clear
#define HID_KEY_KP_CLEAR_ENTRY (0xD9)      // Keypad Clear Entry
#define HID_KEY_KP_BINARY (0xDA)           // Keypad Binary
#define HID_KEY_KP_OCTAL (0xDB)            // Keypad Octal
#define HID_KEY_KP_DECIMAL (0xDC)          // Keypad Decimal
#define HID_KEY_KP_HEXADECIMAL (0xDD)      // Keypad Hexadecimal
#define HID_KEY_LEFT_CONTROL (0xE0)        // Keyboard LeftControl
#define HID_KEY_LEFT_SHIFT (0xE1)          // Keyboard LeftShift
#define HID_KEY_LEFT_ALT (0xE2)            // Keyboard LeftAlt
#define HID_KEY_LEFT_GUI (0xE3)            // Keyboard Left GUI
#define HID_KEY_RIGHT_CONTROL (0xE4)       // Keyboard RightControl
#define HID_KEY_RIGHT_SHIFT (0xE5)         // Keyboard RightShift
#define HID_KEY_RIGHT_ALT (0xE6)           // Keyboard RightAlt
#define HID_KEY_RIGHT_GUI (0xE7)           // Keyboard Right GUI

#endif
