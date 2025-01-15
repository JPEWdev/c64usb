/*
 * SPDX-License-Identifier MIT License
 *
 * Copyright (c) 2024 Joshua Watt
 */
#include "hid_report.h"

#include "util.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

void hid_report_init(struct hid_report *report, uint8_t len) {
  memset(report, 0, sizeof(*report));
  report->len = len;
}

void hid_report_start(struct hid_report *report) { report->cur_bit = 0; }

void hid_report_add_byte(struct hid_report *report, uint8_t byte) {
  if ((report->cur_bit % 8) != 0) {
    return;
  }

  uint8_t cur_byte = report->cur_bit / 8;

  if (cur_byte >= report->len) {
    return;
  }

  if (report->data[cur_byte] != byte) {
    report->changed = true;
    report->data[cur_byte] = byte;
  }
  report->cur_bit += 8;
}

void hid_report_add_bit(struct hid_report *report, bool bit) {
  if (report->cur_bit >= report->len * 8) {
    return;
  }

  uint8_t cur_byte = report->cur_bit / 8;
  uint8_t cur_bit_mask = 1 << (report->cur_bit % 8);

  if (report->data[cur_byte] & cur_bit_mask) {
    if (!bit) {
      report->changed = true;
      report->data[cur_byte] &= ~cur_bit_mask;
    }
  } else if (bit) {
    report->changed = true;
    report->data[cur_byte] |= cur_bit_mask;
  }

  report->cur_bit++;
}

void hid_report_fill_bits(struct hid_report *report, uint8_t num_bits) {
  for (uint8_t i = 0; i < num_bits; i++) {
    hid_report_add_bit(report, false);
  }
}

void hid_report_finish(struct hid_report *report) {
  while ((report->cur_bit % 8) != 0) {
    hid_report_add_bit(report, false);
  }

  while (report->cur_bit < report->len * 8) {
    hid_report_add_byte(report, 0);
  }
}
