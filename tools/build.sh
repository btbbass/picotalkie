#!/usr/bin/env bash
#
# Configure and build every step, using the toolchain the Raspberry Pi Pico
# VS Code extension installed under ~/.pico-sdk. Nothing here needs to be on
# PATH and nothing needs installing with a package manager - which is the whole
# point, and the reason a plain `cmake -S . -B build` fails from a bare shell.
#
#   tools/build.sh                # configure if needed, then build everything
#   tools/build.sh step_10        # build one target
#
set -e

PICO_ROOT="${PICO_ROOT:-$HOME/.pico-sdk}"
SDK_VERSION=2.3.0
TOOLCHAIN_VERSION=15_2_Rel1
CMAKE_VERSION=v4.3.4
NINJA_VERSION=v1.13.2

export PICO_SDK_PATH="$PICO_ROOT/sdk/$SDK_VERSION"
export PICO_TOOLCHAIN_PATH="$PICO_ROOT/toolchain/$TOOLCHAIN_VERSION"
export picotool_DIR="$PICO_ROOT/picotool/$SDK_VERSION/picotool"
export PATH="$PICO_ROOT/cmake/$CMAKE_VERSION/bin:$PICO_ROOT/ninja/$NINJA_VERSION:$PICO_TOOLCHAIN_PATH/bin:$PATH"

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

if [ ! -f build/build.ninja ]; then
    cmake -S . -B build -G Ninja
fi

if [ $# -gt 0 ]; then
    cmake --build build --target "$@"
else
    cmake --build build
fi
