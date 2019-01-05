#!/bin/bash

INPUT="5.0\n6.0\n7.0
5.0\n10.0\n10.0
10.0\n10.0\n5.0"

for i in $INPUT; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
