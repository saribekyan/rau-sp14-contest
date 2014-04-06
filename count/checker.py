#!/usr/bin/python
import sys


WA = 1
OK = 0
PE = 2

f = [0, 1]
N = 2000
for i in xrange(2, N+1):
    f.append(f[i-1] + f[i-2])

inp = open(sys.argv[1], 'r').readline().rstrip()
out = open(sys.argv[2], 'r').readline().rstrip()
if len(out) > 2000:
    exit(WA)
	
for i in xrange(0, len(inp) - 1):
	if inp[i] != '0' and inp[i] != '1':
		exit(PE)

inp_val = 0
for i in xrange(0, len(inp) - 1):
    inp_val += f[len(inp) - i - 1] * int(inp[i])
	
print "input = " + str(inp_val)
inp_val += 1

out_val = 0

print "len(out) = " + str(len(out))
for i in xrange(0, len(out) - 1):
    out_val += f[len(out) - i - 1] * int(out[i])
	
print "output = " + str(out_val) 

if inp_val == out_val:
	print "ok"
	exit(OK)
	
print "wa"
exit(WA)

