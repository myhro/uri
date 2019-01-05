#!/bin/bash

INPUT="30\n10
-30\n10
0\n0"

for i in $INPUT; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
