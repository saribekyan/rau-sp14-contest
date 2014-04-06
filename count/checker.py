import sys

WA = 1
OK = 0

f = [0, 1]
N = 2000
for i in xrange(2, N+1):
    f.append(f[i-1] + f[i-2])

inp = open(sys.argv[1], 'r').readline()
out = open(sys.argv[2], 'r').readline()
if len(out) > 2000:
    exit(WA)

inp_val = 0
for i in xrange(0, len(inp) - 1):
    inp_val += f[len(inp) - i - 2] * int(inp[i])
inp_val += 1

out_val = 0
for i in xrange(0, len(out) - 1):
    out_val += f[len(out) - i - 2] * int(out[i])

if inp_val == out_val:
    exit(OK)

exit(WA)

