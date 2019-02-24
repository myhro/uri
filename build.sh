#!/bin/bash

set -eu

if [[ "$1" = *.c ]]; then
    gcc -O2 -lm "$1"
elif [[ "$1" == *.cpp ]]; then
    g++ -std=c++11 -O2 -lm "$1"
elif [[ "$1" == *.go ]]; then
    go build -o a.out "$1"
fi
