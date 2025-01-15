/*
 * SPDX-License-Identifier MIT License
 *
 * Copyright (c) 2024 Joshua Watt
 */
#ifndef HID_REPORT_H
#define HID_REPORT_H

#include <stdbool.h>
#include <stdint.h>

struct hid_report {
  uint8_t data[8];
  uint8_t len;
  uint8_t cur_bit;
  bool changed;
};

void hid_report_init(struct hid_report *report, uint8_t len);
void hid_report_start(struct hid_report *report);
void hid_report_add_byte(struct hid_report *report, uint8_t byte);
void hid_report_add_bit(struct hid_report *report, bool bit);
void hid_report_fill_bits(struct hid_report *report, uint8_t num_bits);
void hid_report_finish(struct hid_report *report);

#endif
