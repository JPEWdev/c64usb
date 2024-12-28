/*
 * SPDX-License-Identifier MIT License
 *
 * Copyright (c) 2024 Joshua Watt
 */
#include "pin.h"

#include <stdbool.h>
#include <stdint.h>

void pin_init(struct pin const *pin) { pin_set(pin, PIN_HIGH_Z); }

void pin_set(struct pin const *pin, enum pin_state state) {
  switch (state) {
  case PIN_OUTPUT_LO:
    (*pin->ddr) |= pin->mask;
    (*pin->port) &= ~pin->mask;
    break;
  case PIN_OUTPUT_HI:
    (*pin->ddr) |= pin->mask;
    (*pin->port) |= pin->mask;
    break;
  case PIN_INPUT:
    (*pin->ddr) &= ~pin->mask;
    (*pin->port) |= pin->mask;
    break;
  case PIN_HIGH_Z:
    // Set pin as high impedance input
    (*pin->ddr) &= ~pin->mask;
    (*pin->port) &= ~pin->mask;
    break;
  }
}

bool pin_read(struct pin const *pin) {
  bool val = !(*pin->pin & pin->mask);
  return val;
}

