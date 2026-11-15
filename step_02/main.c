#include <stdio.h>
#include <inttypes.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "button.h"

#define LED_PIN CYW43_WL_GPIO_LED_PIN
#define PTT_PIN 6

static button_t ptt;

int main(void) {
    stdio_init_all();
    if (cyw43_arch_init() != 0) return -1;

    button_init(&ptt, PTT_PIN);

    while (true) {
        uint32_t now = to_ms_since_boot(get_absolute_time());

        button_update(&ptt, now);

        if (ptt.edge_down || ptt.edge_up) {
            printf("PTT %-4s @ %6" PRIu32 " ms  (%" PRIu32 " bounces rejected)\n",
                   ptt.edge_down ? "down" : "up", now, ptt.bounces);
            ptt.bounces = 0;        // count per transition, not forever
        }

        cyw43_arch_gpio_put(LED_PIN, ptt.pressed);
    }
}