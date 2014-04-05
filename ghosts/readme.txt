Files:
gentests.py - Generates tests in 'tests' folder. The first 12 tests are small (<= 1000)
compare.sh - compares the output of slow.cpp and sol.cpp on the easy tests
slow.cpp - A solution for n <= 1000
sol.cpp - An optimal solution

001 - 005 are manual tests

NOTICE: you need to compile sol.cpp with compiler option of high stack size.
    g++ -Wl,-stack_size -Wl,100000000 sol.cpp -o sol.cpp.out
