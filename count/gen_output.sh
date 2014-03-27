#!/bin/bash
FILES=tests/[0-9][0-9][0-9]
for f in $FILES
do
    echo $f
    ./sol.cpp.out < $f > $f.a
done

