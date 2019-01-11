#!/bin/bash

for t in input output; do
    csplit --prefix "$t" --suppress-matched --quiet beginner/1061-"$t".txt '/---/' '{*}'
done

for f in input*; do
    NUMBER=$(echo "$f" | grep -E -o '[0-9]{2}')
    echo "$NUMBER"
    diff -u <(cat output"$NUMBER") <(./a.out < input"$NUMBER")
done

rm -f input*
rm -f output*
