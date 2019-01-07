#!/bin/bash

INPUT1="2.0 4.0 7.5 8.0
6.4"

INPUT2="2.0 6.5 4.0 9.0"

INPUT3="9.0 4.0 8.5 9.0"

INPUT4="10.0 10.0 0.0 0.0
5.0"

for i in "$INPUT1" "$INPUT2" "$INPUT3" "$INPUT4"; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
