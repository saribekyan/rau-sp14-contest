#!/bin/bash
FILES=tests/easy*
for f in $FILES
do
    echo $f
    diff <( ./test_sol.cpp.out < $f ) <( ./sol.cpp.out < $f)
done

