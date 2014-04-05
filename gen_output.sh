#!/bin/bash

# This script is used to generate the output for the tests that are at
# $1/tests in the format of 3 digits (ex. 012).
# $1 is the first argument and in general should be the folder name
# of the problem

FILES=`ls $1/tests/[0-9][0-9][0-9]`
for f in $FILES
do
    echo $f
    ./$1/sol.cpp.out < $f > $f.a
done

