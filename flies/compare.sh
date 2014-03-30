#!/bin/bash
FILES=`ls tests/[0-9][0-9][0-9]`
for f in $FILES
do
    echo $f
    diff <( python sol.py < $f ) <( ./sol.cpp.out < $f)
done

