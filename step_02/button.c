#include "button.h"
#include "hardware/gpio.h"

#define DEBOUNCE_MS 20u

void button_init(button_t *b, uint32_t pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);            // active low: pressed reads 0

    b->pin            = pin;
    b->pressed        = false;
    b->edge_down      = false;
    b->edge_up        = false;
    b->raw            = false;
    b->last_change_ms = 0;
    b->bounces        = 0;
    
}

void button_update(button_t *b, uint32_t now_ms) {
    b->edge_down = false;
    b->edge_up   = false;

    bool raw = !gpio_get(b->pin);   // invert: active low

    if (raw != b->raw) {
        // A change arriving less than DEBOUNCE_MS after the previous one is
        // the contact chattering, not a finger: count it.
        if ((now_ms - b->last_change_ms) < DEBOUNCE_MS) b->bounces++;

        b->raw            = raw;
        b->last_change_ms = now_ms;
        return;                     // it moved: restart the clock
    }

    if (raw != b->pressed && (now_ms - b->last_change_ms) >= DEBOUNCE_MS) {
        b->pressed = raw;           // stable long enough: commit
        if (raw) b->edge_down = true;
        else     b->edge_up   = true;
    }
}