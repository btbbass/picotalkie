# Step 01 - blink the on-board LED and print over USB serial.
#
# No boilerplate here: the SDK is already initialised by the root
# CMakeLists.txt, so this file only describes the executable itself.

add_executable(step_01 main.c)

pico_set_program_name(step_01 "step_01")
pico_set_program_version(step_01 "0.1")

# Send printf() to the USB CDC serial port rather than the physical UART pins,
# so a single USB cable gives both power and a console.
pico_enable_stdio_usb(step_01 1)
pico_enable_stdio_uart(step_01 0)

target_link_libraries(step_01
    pico_stdlib           # gpio, timers, printf plumbing, clocks
    pico_cyw43_arch_none  # CYW43 wireless chip driver; the LED hangs off it.
                          # "_none" = driver without a network stack (no lwIP yet)
    tutorial_common
)

# Turns the .elf into the .uf2 you drag onto the BOOTSEL drive
# (plus .bin/.hex/.dis/.map for inspection).
pico_add_extra_outputs(step_01)
