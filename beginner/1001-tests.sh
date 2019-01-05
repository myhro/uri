#!/bin/bash

INPUT="10\n9
-10\n4
15\n-7"

for i in $INPUT; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
