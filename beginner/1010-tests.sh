#!/bin/bash

INPUT1="12 1 5.30\n16 2 5.10"
INPUT2="13 2 15.30\n161 4 5.20"
INPUT3="1 1 15.10\n2 1 15.10"

for i in "$INPUT1" "$INPUT2" "$INPUT3"; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
