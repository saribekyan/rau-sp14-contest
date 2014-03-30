import math
import sys

line = sys.stdin.readline()
n = int(line.split(' ')[0])
k = int(line.split(' ')[1])

print math.factorial(n + k -1) / math.factorial(k - 1) /  math.factorial(n)

