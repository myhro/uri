#!/bin/bash

INPUT1="7
-5
6
-3.4
4.6
12"

INPUT2="1
2
3
4
5
6"

for i in "$INPUT1" "$INPUT2"; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
