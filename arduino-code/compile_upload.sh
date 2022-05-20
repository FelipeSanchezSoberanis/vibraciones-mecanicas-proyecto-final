#!/usr/bin/env sh

sketch_file=arduino-code.ino

arduino-cli compile --fqbn arduino:avr:uno ${sketch_file}
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno ${sketch_file}
