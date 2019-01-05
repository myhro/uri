#!/bin/bash

INPUT="576
11257
503"

for i in $INPUT; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
