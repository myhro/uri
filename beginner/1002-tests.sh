#!/bin/bash

INPUT="2.00
100.64
150.00"

for i in $INPUT; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
