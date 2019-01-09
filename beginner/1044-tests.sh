#!/bin/bash

INPUT1="6 24"
INPUT2="6 25"
INPUT3="4 36"
INPUT4="36 4"

for i in "$INPUT1" "$INPUT2" "$INPUT3" "$INPUT4"; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
