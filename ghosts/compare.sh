#!/bin/bash
for f in 001 002 003 004 005 006 007 008 009 010 011 012
do
    echo $f
    diff <( ./slow.cpp.out < tests/$f ) <( ./sol.cpp.out < tests/$f)
done

