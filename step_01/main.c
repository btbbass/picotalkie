#include <stdio.h>
#include <inttypes.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define LED_PIN CYW43_WL_GPIO_LED_PIN

#define OFF_MS 200
#define ON_MS  800

int main(void) {
    stdio_init_all();

    if (cyw43_arch_init() != 0) {
        return -1;
    }

    bool led_on = false;
    uint32_t count = 0;
    uint32_t last_update = to_ms_since_boot(get_absolute_time());

    while (true) {
        uint32_t now = to_ms_since_boot(get_absolute_time());

        if (!led_on && (now - last_update) >= OFF_MS) {
            cyw43_arch_gpio_put(LED_PIN, true);
            led_on = true;
            last_update = now;
        }

        if (led_on && (now - last_update) >= ON_MS) {
            cyw43_arch_gpio_put(LED_PIN, false);
            led_on = false;
            last_update = now;

            printf("blink %" PRIu32 "\n", count++);
        }
    }
}

