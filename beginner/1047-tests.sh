#!/bin/bash

INPUT1="7 8 9 10"

INPUT2="7 7 7 7"

INPUT3="7 10 8 9"

INPUT4="10 12 10 11"

INPUT5="1 0 1 1"

INPUT6="2 0 1 0"

for i in "$INPUT1" "$INPUT2" "$INPUT3" "$INPUT4" "$INPUT5" "$INPUT6"; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
