#!/bin/bash

INPUT="5\n6\n7\n8
0\n0\n7\n8
5\n6\n-7\n8"

for i in $INPUT; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
