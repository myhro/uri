#!/bin/bash

INPUT1="vertebrado
mamifero
onivoro"

INPUT2="vertebrado
ave
carnivoro"

INPUT3="invertebrado
anelideo
onivoro"

for i in "$INPUT1" "$INPUT2" "$INPUT3"; do
    echo "$i"
    echo
    echo "$i" | ./a.out
    echo
done
