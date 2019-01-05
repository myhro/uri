#!/bin/bash

INPUT="JOAO\n500.00\n1230.30
PEDRO\n700.00\n0.00
MANGOJATA\n1700.00\n1230.50"

for i in $INPUT; do
    echo -e "$i"
    echo
    echo -e "$i" | ./a.out
    echo
done
