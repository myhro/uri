#!/bin/bash

INPUT1="3
0
4
2"

INPUT2="10
0
1
2
3
4
5
6
7
8
60"

for i in "$INPUT1" "$INPUT2"; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
