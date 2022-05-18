#!/usr/bin/env sh

sketch_file=sketch_may17a

arduino-cli compile --fqbn arduino:avr:uno ${sketch_file}
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno ${sketch_file}
