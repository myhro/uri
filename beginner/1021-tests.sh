#!/bin/bash

INPUT="576.73
4.00
91.01"

for i in $INPUT; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
