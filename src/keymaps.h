/*
 * SPDX-License-Identifier MIT License
 *
 * Copyright (c) 2024 Joshua Watt
 */
#ifndef KEYMAPS_H
#define KEYMAPS_H

#include <avr/pgmspace.h>
#include <stdint.h>

#define KEY_ROWS (8)
#define KEY_COLS (8)
#define KEY_AUX (16)

struct keymap {
  uint8_t restore;
  uint8_t keys[KEY_ROWS][KEY_COLS];
  uint8_t aux[KEY_AUX];
};

PROGMEM extern const struct keymap vice_keymap;

#endif
