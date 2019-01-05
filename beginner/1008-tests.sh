#!/bin/bash

INPUT="25\n100\n5.50
1\n200\n20.50
6\n145\n15.55"

for i in $INPUT; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
