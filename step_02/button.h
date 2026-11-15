#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

typedef struct {
    uint32_t pin;
    bool     pressed;        // debounced level
    bool     edge_down;      // true for one update, on press
    bool     edge_up;        // true for one update, on release
    bool     raw;            // internal
    uint32_t last_change_ms; // internal
    uint32_t bounces;        // number of bounces
} button_t;

void button_init(button_t *b, uint32_t pin);
void button_update(button_t *b, uint32_t now_ms);

#endif