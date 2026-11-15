# PicoTalkie

An encrypted push-to-talk walkie-talkie on a Raspberry Pi Pico 2 W, built one
step at a time, in C with the Pico SDK.

**The tutorial: <https://btbbass.github.io/picotalkie/>**

Each part of the tutorial is a folder here, and one CMake build compiles them
all.

| Folder | Part |
|--------|------|
| `step_01/` | [Blink and serial](https://btbbass.github.io/picotalkie/01-blink-and-serial/) |
| `step_02/` | [A debounced button](https://btbbass.github.io/picotalkie/02-debounced-button/) |

New folders appear as new parts are published.

## Building

The toolchain comes from the Raspberry Pi Pico VS Code extension, installed
under `~/.pico-sdk`. `tools/build.sh` puts it on the path for you:

```bash
tools/build.sh step_01      # one part
tools/build.sh              # all of them
```

Each part produces `build/<step>/<step>.uf2`. Part 1 explains the set-up from
an empty machine.

The site source is in `tutorial/`. To preview it locally:

```bash
pip install --user -r requirements-docs.txt
mkdocs serve
```

## License

Code: [MIT](LICENSE). `pico_sdk_import.cmake` comes from the Raspberry Pi Pico
SDK and keeps its own BSD-3-Clause notice.

Tutorial text in `tutorial/`:
[CC BY 4.0](https://creativecommons.org/licenses/by/4.0/). Reuse it freely,
crediting *PicoTalkie by btbbass* with a link back.

To report a mistake, please [open an issue](https://github.com/btbbass/picotalkie/issues).
