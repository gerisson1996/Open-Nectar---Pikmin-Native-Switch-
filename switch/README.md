# Pikmin Native Switch - bootstrap build

This directory contains the first Nintendo Switch/libnx build target.

The immediate goal is deliberately small: verify devkitA64 + libnx, AArch64
linking, NACP generation and NRO packaging before wiring the full Pikmin
sources and platform backends into the target.

## Requirements

Install devkitPro with the Switch development group (devkitA64 + libnx).

DEVKITPRO must be set in the environment.

## Build

From the repository root:

    make -f switch/Makefile

Output:

    build-switch/pikmin-switch.nro

Once this bootstrap target is green, the next stage is to add the portable
Open Nectar sources and replace desktop/Android platform dependencies
incrementally.
