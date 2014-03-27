def same(f, n, val):
    for i in xrange(n):
        f.write(str(val))

def alternate(f, n):
    for i in xrange(n):
        f.write(str(i%2))

import random
def rnd(f, n):
    for i in xrange(n):
        if random.random() < 0.7:
            f.write('1')
        else:
            f.write('0')

num = 0
def newf():
    global num
    num += 1
    return open('tests/' + str(num).zfill(3), 'w')

# 001
f = newf()
same(f, 10, 1)
f.write('\n')

# 002
f = newf()
same(f, 100, 1)
f.write('\n')

# 003
f = newf()
same(f, 1000, 1)
f.write('\n')

# 004
f = newf()
same(f, 10, 0)
f.write('\n')

# 005
f = newf()
same(f, 100, 0)
f.write('\n')

# 006
f = newf()
same(f, 1000, 0)
f.write('\n')

# 007
f = newf()
same(f, 10, 0)
alternate(f, 10)
same(f, 10, 1)
f.write('\n')

# 008
f = newf()
same(f, 100, 0)
rnd(f, 200)
same(f, 200, 1)
alternate(f, 200)
same(f, 10, 1)
f.write('\n')

# 009
f = newf()
f.write('0\n')

# 010
f = newf()
f.write('10\n')

# 011
f = newf()
f.write('100\n')

# 012
f = newf()
f.write('110\n')

# 013
f = newf()
f.write('111\n')

