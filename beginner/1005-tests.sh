#!/bin/bash

INPUT="5.0\n7.1
0.0\n7.1
10.0\n10.0"

for i in $INPUT; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
