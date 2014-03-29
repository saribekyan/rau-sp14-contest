num = 1

def puttest(d, find_num):
    f = open('tests/' + str(num).zfill(3), 'w')
    f.write(str(len(d)) + ' ' + str(find_num) + '\n')
    for x in d:
        f.write(str(x[0]) + ' ' + str(x[1]) + '\n')
    f.close()

    f = open('tests/' + str(num).zfill(3) + '.a', 'w')
    if find_num in [x[0] for x in d]:
        f.write('YES\n')
    else:
        f.write('NO\n')
    f.close()

    print 'test', num, 'done'
    global num
    num += 1

INF = 1000000000

import random
def gen_rand(n, M = INF):
    while True:
        v = list(set([random.randint(-M, M) for i in xrange(n)]))
        if len(v) != 1:
            break
    n = len(v)
    v = sorted(v)
    p = range(n)
    random.shuffle(p)
    d = [0 for i in xrange(n)]
    for i in xrange(n):
        d[p[i]] = ((v[i], p[(i+1)%n] + 1))
    return d

# small manual tests
puttest([(1, 1)], 2)

puttest([(1, 1)], 1)

puttest([(1, 2), (3, 1)], 2)

puttest([(1, 2), (3, 1)], 3)

n = 100000
puttest([(i, (i+1)%n + 1) for i in xrange(n)], n / 2)  # 1...n test, exists
puttest([(i, (i+1)%n + 1) for i in xrange(n)], -1)     # 1...n test, does not exist

N = [100, 1000, 5000, 100000, 100000, 100000]

# exist
for n in N:
    d = gen_rand(n)
    n = len(d)
    puttest(d, d[random.randint(0, n-1)][0])

# may not exist
for n in N:
    d = gen_rand(n)
    puttest(d, random.randint(-INF, INF))

