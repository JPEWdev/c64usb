/*
 * SPDX-License-Identifier MIT License
 *
 * Copyright (c) 2024 Joshua Watt
 */
#include "timer.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/atomic.h>

// Milliseconds counted for each interrupt
#define MS_PER_INT (1)

#define TIMER_COMP ((MS_PER_INT * F_CPU / 1000) / 8)

// Make sure the comparison is at least 255 (to ensure high enough precision)
// and not too large to fit in the 16 bit compare register
_Static_assert(TIMER_COMP >= 0xFF && TIMER_COMP <= 0xFFFF,
               "Timer compare out of range, change clock divider");

static volatile uint32_t milliseconds = 0;

uint32_t get_milliseconds() {
  uint32_t result;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { result = milliseconds; }
  return result;
}

void timer_init() {
  TCCR1B |= (1 << WGM12) | (1 << CS11);
  OCR1AH = TIMER_COMP >> 8;
  OCR1AL = TIMER_COMP & 0xFF;
  TIMSK1 |= (1 << OCIE1A);
}

ISR(TIMER1_COMPA_vect) { milliseconds += MS_PER_INT; }
