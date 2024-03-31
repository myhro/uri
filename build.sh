#!/bin/bash

set -eu

if [[ "$1" = *.c ]]; then
    gcc -O2 -lm "$1"
elif [[ "$1" == *.cpp ]]; then
    g++ -std=c++20 -O2 -lm "$1"
fi
