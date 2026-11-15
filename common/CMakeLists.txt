# Code shared by several tutorial steps (Wi-Fi setup, audio capture, crypto
# helpers, ...). Nothing lives here yet; it is wired up so that adding a
# shared file later is a one-line change.
#
# INTERFACE rather than STATIC on purpose: the Pico SDK compiles sources
# per-target, so that each executable's own options (board config, stdio
# routing) also apply to the shared sources it pulls in. A STATIC library
# would be compiled once with the wrong settings and shared by everyone.

add_library(tutorial_common INTERFACE)

# Any step linking tutorial_common can #include headers from this folder.
target_include_directories(tutorial_common INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Shared .c files go here as the series grows, e.g.
# target_sources(tutorial_common INTERFACE ${CMAKE_CURRENT_LIST_DIR}/wifi_connect.c)

target_link_libraries(tutorial_common INTERFACE pico_stdlib)
