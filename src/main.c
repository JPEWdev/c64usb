/*
 * SPDX-License-Identifier MIT License
 *
 * Copyright (c) 2024 Joshua Watt
 */
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <stdbool.h>
#include <string.h>
#include <util/atomic.h>
#include <util/delay.h>

#include "hid_report.h"
#include "keymaps.h"
#include "pin.h"
#include "timer.h"
#include "usb_hid_keys.h"
#include "usbdrv.h"
#include "util.h"

#define KEYBOARD_REPORT_ID (1)
#define POLL_RATE_MS (16)
#define SETTLE_TIME_US (100)

// Settle time must be less than the poll rate and also less than the maximum
// settle time
_Static_assert(SETTLE_TIME_US * 9 <= POLL_RATE_MS * 1000,
               "Settle time is too long");

#define NUM_JOYSTICKS (2)

#define DEBUG_SCAN (0)

#define ROW_0 PIN(B, 4)
#define ROW_1 PIN(D, 6)
#define ROW_2 PIN(D, 7)
#define ROW_3 PIN(B, 0)
#define ROW_4 PIN(B, 1)
#define ROW_5 PIN(B, 2)
#define ROW_6 PIN(B, 3)
#define ROW_7 PIN(D, 5)

#define COL_0 PIN(B, 5)
#define COL_1 PIN(C, 0)
#define COL_2 PIN(C, 1)
#define COL_3 PIN(D, 0)
#define COL_4 PIN(C, 3)
#define COL_5 PIN(C, 4)
#define COL_6 PIN(C, 5)
#define COL_7 PIN(C, 2)

static const struct pin rows[] = {
    ROW_0, ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7,
};

_Static_assert(ARRAY_SIZE(rows) == KEY_ROWS, "keymap wrong size");

static const struct pin cols[] = {
    COL_0, COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7,
};

_Static_assert(ARRAY_SIZE(cols) == KEY_COLS, "keymap wrong size");

static const struct pin aux[] = {
    COL_0, COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7,
    ROW_0, ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7,
};
_Static_assert(ARRAY_SIZE(aux) == KEY_AUX, "Keymap wrong size");

static const struct pin restore_pin = PIN(D, 1);
static const struct pin aux_pin = PIN(D, 4);

#define REPORT_BIT_KEYS (1 + (KEY_AUX))
#define REPORT_BYTE_KEYS (4)

#if REPORT_BIT_KEYS % 8
#define REPORT_BIT_KEY_BYTES ((REPORT_BIT_KEYS / 8) + 1)
#define REPORT_CONST_BITS (8 - (REPORT_BIT_KEYS % 8))
#else
#define REPORT_BIT_KEY_BYTES (REPORT_BIT_KEYS / 8)
#define REPORT_CONST_BITS (0)
#endif

#define REPORT_KEY_BYTES (REPORT_BIT_KEY_BYTES + REPORT_BYTE_KEYS)

static struct hid_report report;

static const struct keymap *const keymap = &vice_keymap;

// Idle rate is in multiples of 4 milliseconds
static uint8_t idle_rate;
static uint32_t last_idle;

/* clang-format off */
PROGMEM static const uint8_t usb_hid_report_descriptor_header[] = {
    0x05, 0x01,                 // Usage Page (Generic Desktop Ctrls)
    0x09, 0x06,                 // Usage (Keyboard)
    0xA1, 0x01,                 // Collection (Application)
    0x85, KEYBOARD_REPORT_ID,   //   Report ID
    0x05, 0x07,                 //   Usage Page (Kbrd/Keypad)
    0x15, 0x00,                 //   Logical Minimum (0)
    0x25, 0x01,                 //   Logical Maximum (1)
    0x75, 0x01,                 //   Report Size (1)
    0x95, REPORT_BIT_KEYS,      //   Report Count
};

PROGMEM static const uint8_t usb_hid_report_descriptor_footer[] = {
    0x81, 0x02,                 //   Input (Data, Variable, Absolute)
    0x75, REPORT_CONST_BITS,    //   Report Size
    0x95, 0x01,                 //   Report Count (1)
    0x81, 0x03,                 //   Input (Constant)
    0x95, REPORT_BYTE_KEYS,     //   Report Count
    0x75, 0x08,                 //   Report Size (8)
    0x15, 0x00,                 //   Logical Minimum (0)
    0x25, 0xFF,                 //   Logical Maximum (0xFF)
    0x05, 0x07,                 //   Usage Page (Key codes)
    0x19, 0x00,                 //   Usage Minimum (0)
    0x29, 0xFF,                 //   Usage Maximum (0xFF)
    0x81, 0x00,                 //   Input (Data, Array)
    0xC0,                       // End Collection
};
/* clang-format on */

char usbHidReportDescriptor[sizeof(usb_hid_report_descriptor_header) +
                            (2 * REPORT_BIT_KEYS) +
                            sizeof(usb_hid_report_descriptor_footer)];

_Static_assert(sizeof(usbHidReportDescriptor) ==
                   USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH,
               "HID report is wrong size");

#if DEBUG_SCAN
static void set_debug_leds(uint8_t leds) {
  for (uint8_t i = 0; i < KEY_ROWS; i++) {
    pin_set(&rows[i], (leds & 1) ? PIN_OUTPUT_LO : PIN_HIGH_Z);
    leds >>= 1;
  }
}
#else
#define set_debug_leds(leds)
#endif

static void reset(void) {
  cli();
  wdt_enable(WDTO_15MS);
  while (true)
    ;
}

#define add_keymap(k)                                                          \
  do {                                                                         \
    *(ptr++) = 0x09;                                                           \
    *(ptr++) = pgm_read_byte(&(k));                                            \
  } while (0)
static void init_hid_report() {
  char *ptr = usbHidReportDescriptor;

  memcpy_P(ptr, usb_hid_report_descriptor_header,
           sizeof(usb_hid_report_descriptor_header));
  ptr += sizeof(usb_hid_report_descriptor_header);

  for (uint8_t i = 0; i < KEY_AUX; i++) {
    add_keymap(keymap->aux[i]);
  }
  add_keymap(keymap->restore);

  memcpy_P(ptr, usb_hid_report_descriptor_footer,
           sizeof(usb_hid_report_descriptor_footer));
  ptr += sizeof(usb_hid_report_descriptor_footer);

  // Check report size
  if (ptr != usbHidReportDescriptor + sizeof(usbHidReportDescriptor)) {
    reset();
  }
}

static void poll_loop() {
  uint32_t now = get_milliseconds();

  wdt_reset();
  usbPoll();

  if (usbInterruptIsReady() &&
      (report.changed || (idle_rate && (now - last_idle >= idle_rate * 4)))) {
    report.changed = false;
    usbSetInterrupt(report.data, report.len);
    last_idle = now;
  }
}

static void read_settle() {
  poll_loop();
  _delay_us(SETTLE_TIME_US);
}

static void read_inputs() {
  struct hid_report r;

  // Make a copy of the report so we don't have to keep interrupts disabled
  // while sleeping
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { r = report; }

  hid_report_start(&r);
  hid_report_add_byte(&r, KEYBOARD_REPORT_ID);

  for (uint8_t col = 0; col < KEY_COLS; col++) {
    pin_set(&cols[col], PIN_INPUT);
  }

  for (uint8_t row = 0; row < KEY_ROWS; row++) {
    pin_set(&rows[row], PIN_INPUT);
  }
  pin_set(&restore_pin, PIN_INPUT);

  // Read auxiliary inputs
  pin_set(&aux_pin, PIN_OUTPUT_LO);
  read_settle();
  for (uint8_t i = 0; i < KEY_AUX; i++) {
    hid_report_add_bit(&r, pin_read(&aux[i]));
  }
  pin_set(&aux_pin, PIN_HIGH_Z);

  // Read restore pin
  hid_report_add_bit(&r, pin_read(&restore_pin));

  hid_report_fill_bits(&r, REPORT_CONST_BITS);

  for (uint8_t row = 0; row < KEY_ROWS; row++) {
    pin_set(&rows[row], PIN_HIGH_Z);
  }

  for (uint8_t row = 0; row < KEY_ROWS; row++) {
    pin_set(&rows[row], PIN_OUTPUT_LO);
    read_settle();
    for (uint8_t col = 0; col < KEY_COLS; col++) {
      if (pin_read(&cols[col])) {
        hid_report_add_byte(&r, pgm_read_byte(&keymap->keys[row][col]));
      }
    }
    pin_set(&rows[row], PIN_HIGH_Z);
  }

  for (uint8_t row = 0; row < KEY_ROWS; row++) {
    pin_set(&rows[row], PIN_INPUT);
  }

  hid_report_finish(&r);

  // Update report
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { report = r; }
}

int main(void) {
  wdt_enable(WDTO_1S);
  init_hid_report();

  timer_init();

  // Initialize pins
  for (uint8_t col = 0; col < KEY_COLS; col++) {
    pin_init(&cols[col]);
  }
  for (uint8_t row = 0; row < KEY_ROWS; row++) {
    pin_init(&rows[row]);
  }
  pin_init(&aux_pin);
  pin_init(&restore_pin);
  hid_report_init(&report, REPORT_KEY_BYTES + 1);

  usbInit();
  usbDeviceDisconnect(); /* enforce re-enumeration, do this while interrupts are
                            disabled! */

  /* fake USB disconnect for > 250 ms */
  {
    uint8_t i = 250;
    set_debug_leds(1);
    while (--i) {
      wdt_reset();
      _delay_ms(1);
    }
    set_debug_leds(0);
  }
  usbDeviceConnect();

  sei();
  uint32_t last_key_poll = get_milliseconds();
  last_idle = get_milliseconds();

  while (true) {
    poll_loop();

    uint32_t now = get_milliseconds();

    if (now - last_key_poll >= POLL_RATE_MS) {
      set_debug_leds(0);
      read_inputs();
      set_debug_leds(report.data[3]);
      last_key_poll = now;
    }
  }
}

usbMsgLen_t usbFunctionSetup(uchar data[8]) {
  usbRequest_t const *request = (usbRequest_t const *)data;

  if ((request->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS) {
    if (request->bRequest == USBRQ_HID_GET_REPORT) {
      /* wValue: ReportType (highbyte), ReportID (lowbyte) */
      if (request->wValue.bytes[1] == KEYBOARD_REPORT_ID) {
        report.changed = false;
        usbMsgPtr = report.data;
        return report.len;
      }

    } else if (request->bRequest == USBRQ_HID_GET_IDLE) {
      usbMsgPtr = &idle_rate;
      return 1;

    } else if (request->bRequest == USBRQ_HID_SET_IDLE) {
      idle_rate = request->wValue.bytes[1];
      last_idle = get_milliseconds();
    }
  }
  return 0;
}
