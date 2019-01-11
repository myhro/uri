#!/bin/bash

set -u

PREFIX=$(echo "$1" | cut -d "-" -f 1)

for t in input output; do
    csplit --prefix "$t" --suppress-matched --quiet "${PREFIX}-${t}.txt" '/---/' '{*}'
done

for f in input*; do
    NUMBER=$(echo "$f" | grep -E -o '[0-9]{2}')
    echo "Test $NUMBER"
    diff -u <(cat output"$NUMBER") <(./a.out < input"$NUMBER") | grep -v "/dev/fd/"
done

rm -f input*
rm -f output*
