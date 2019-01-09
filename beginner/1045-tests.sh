#!/bin/bash

INPUT1="7.0 5.0 7.0"
INPUT2="6.0 6.0 10.0"
INPUT3="6.0 6.0 6.0"
INPUT4="5.0 7.0 2.0"
INPUT5="6.0 8.0 10.0"
INPUT6="95.4 95.4 95.4"

for i in "$INPUT1" "$INPUT2" "$INPUT3" "$INPUT4" "$INPUT5" "$INPUT6"; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
