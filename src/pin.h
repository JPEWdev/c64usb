/*
 * SPDX-License-Identifier MIT License
 *
 * Copyright (c) 2024 Joshua Watt
 */
#ifndef PIN_H
#define PIN_H

#include <stdbool.h>
#include <stdint.h>

#define PIN(P, BIT) {&PORT##P, &DDR##P, &PIN##P, 1 << (BIT)}

struct pin {
  volatile uint8_t *port;
  volatile uint8_t *ddr;
  volatile uint8_t *pin;
  uint8_t mask;
};

enum pin_state {
  PIN_OUTPUT_LO,
  PIN_OUTPUT_HI,
  PIN_INPUT,
  PIN_HIGH_Z,
};

static __inline bool pin_equal(struct pin const *pina, struct pin const *pinb) {
  return (pina->port == pinb->port) && (pina->mask == pinb->mask);
}

void pin_init(struct pin const *pin);
void pin_set(struct pin const *pin, enum pin_state state);
bool pin_read(struct pin const *pin);

#endif
