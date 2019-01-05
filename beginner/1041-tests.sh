#!/bin/bash

INPUT="4.5 -2.2
0.1 0.1
0.0 0.0
0.0 0.1
0.1 0.0
0.0 -0.1
-0.1 0.0"

while read -r LINE; do
    echo -e "$LINE"
    echo
    echo -e "$LINE" | ./a.out
    echo
done <<< "$INPUT"
