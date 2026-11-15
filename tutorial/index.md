---
description: >-
  A step-by-step tutorial series: build an encrypted push-to-talk
  walkie-talkie on a Raspberry Pi Pico 2 W, in C with the Pico SDK.
---

# PicoTalkie

**An encrypted push-to-talk walkie-talkie on a Raspberry Pi Pico 2 W, built one
step at a time, in C with the Pico SDK.**

By the end of the series, two boards talk to each other over the internet,
encrypted, with a key exchanged in person over Bluetooth. We start much smaller
than that, with one LED and one button.

## Why I built this

I am an engineer, and I studied mostly electronics on paper: I passed several
exams, but I had never created anything from scratch. This is my first time,
and I really enjoy it, because it is empowering, and it is unblocking a lot of
latent creativity.

For my whole life, I have been told that I am a cold thinker, and that all
engineers are like that. I think they are wrong, because being rational does
not stop me from being creative (I must admit I do the same, sometimes, with
people I don't consider rational *enough*).

Anyway, I wanted to finally take some time not only to learn something new,
but also to express a creative idea I had: how strong the link with my
children is, even when they are not with me.

And what better way to express it than with two boards that, once paired over
Bluetooth, always find each other, exactly like two entangled particles that
stay linked even when they are light years apart?

Except mine can actually exchange information.

## How the series works

Each part is a **separate firmware target** in one repository. You can flash any
stage and see exactly what it adds, and when something breaks you always have a
known-good step to go back to.

The bugs are written up too, in the part where they happened.

## The parts

| Part | What it adds | |
|------|--------------|---|
| [1](01-blink-and-serial.md) | Toolchain, blink the on-board LED, `printf` over USB | :material-check: published |
| [2](02-debounced-button.md) | A debounced push-to-talk button | :material-check: published |
| 3 | I²S microphone capture with PIO | coming |
| 4 | Continuous capture with ping-pong DMA, gated by push-to-talk | coming |
| 5 | Playback to a MAX98357A: hear your own echo | coming |
| 6 | MQTT transport over a public broker | coming |
| 7 | ChaCha20-Poly1305 encryption and authentication | coming |
| 8 | BLE pairing: X25519 over Bluetooth, key stored in flash | coming |
| 9 | DSP: DC blocker, noise gate, soft limiter | coming |
| … | Wi-Fi provisioning, the flash map, a secure/non-secure split, OTA updates | coming |

## Who it's for

You should be comfortable reading C. You don't need any embedded experience,
because part 1 starts from an empty machine, and I explain every new piece of
hardware when it first shows up.

## What you need for parts 1 and 2

- A **Raspberry Pi Pico 2 W**. The *Pico 2 WH* has the headers pre-soldered,
  which saves you a soldering job.
- A **micro-USB cable that carries data**. Plenty of cables only charge, and
  those are the usual reason a board "doesn't show up".
- For part 2: a breadboard, a push button and two jumper wires.

**[Start with part 1 →](01-blink-and-serial.md)**
