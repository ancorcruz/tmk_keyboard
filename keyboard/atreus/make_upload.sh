#!/usr/bin/env sh

make upload KEYMAP=${1:-qwerty_ancor} USB=/dev/cu.usbmodem1411
