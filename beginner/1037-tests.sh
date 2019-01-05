#!/bin/bash

INPUT="25.01
25.00
100.00
-25.02"

for i in $INPUT; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
