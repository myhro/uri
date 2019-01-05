#!/bin/bash

INPUT="10.0 20.1 5.1
0.0 20.0 5.0
10.3 203.0 5.0
10.0 3.0 5.0"

while read -r LINE; do
    echo -e "$LINE"
    echo
    echo -e "$LINE" | ./a.out
    echo
done <<< "$INPUT"
