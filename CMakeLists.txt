# Top-level project for the Pico tutorial series.
#
# Everything common to every step lives here: the SDK bootstrap, the board
# choice and the language standards. Each step/ folder only describes its own
# executable, and is pulled in with add_subdirectory() at the bottom.

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Writes build/compile_commands.json, which is what gives the C/C++ extension
# working IntelliSense (correct includes and defines) for every step.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.3.0)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

# One board for the whole repo. Must be set before the SDK is initialised,
# because the SDK uses it to pick headers, linker script and CPU flags.
set(PICO_BOARD pico2_w CACHE STRING "Board type")

# Locates the SDK (via PICO_SDK_PATH) and pulls its CMake machinery into this
# build, which is what defines pico_sdk_init(), pico_add_extra_outputs(), etc.
include(pico_sdk_import.cmake)

project(PicoTalkie C CXX ASM)

# Actually configures the SDK: sets up the cross-compiler, defines the
# pico_* libraries. Nothing pico_* works before this line.
pico_sdk_init()

# Shared library first, so the steps below can link against it.
add_subdirectory(common)

# ---- tutorial steps: add one line per new step ----
add_subdirectory(step_01)
add_subdirectory(step_02)
