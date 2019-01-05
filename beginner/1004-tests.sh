#!/bin/bash

INPUT="3\n9
-30\n10
0\n9"

for i in $INPUT; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
