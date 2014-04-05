import random

num = 1
def add_test(data):
    global num
    f = open('tests/' + str(num).zfill(3), 'w')
    f.write(str(len(data)) + '\n')
    f.write(str(data[0][0]))
    for p in data[1:]:
        f.write(' ' + str(p[0]))
    f.write('\n')

    f.write(str(data[0][1]))
    for p in data[1:]:
        f.write(' ' + str(p[1]))
    f.write('\n')
    print 'test', num, 'done'
    num += 1

M = 10**9
def gen_random(n, offset=1):
    data = []
    for i in xrange(n):
        data.append((random.randint(0, M), random.randint(1, M) + offset))
    return data

def gen_exact_sum(n):
    data = []
    s1 = s2 = sum([random.randint(1, M) for i in xrange(n)])
    for i in xrange(n):
        while True:
            a = random.randint(0, 9 * s1 / (n - i) / 5)
            if s1 >= a:
                break

        while True:
            l = random.randint(1, 9 * s2 / (n - i) / 5)
            if s2 >= l + (n - i - 1):
                break

        s1 -= a
        s2 -= l

        data.append([a, l])

    for i in range(n):
        data[i][0] += s1 / n
        data[i][1] += s2 / n
        s1 -= s1 / n
        s2 -= s2 / n
    data[random.randint(0, n-1)][0] += s1
    data[random.randint(0, n-1)][1] += s2
    return data

def almost_exact_sum(n):
    data = gen_exact_sum(n)
    while True:
        p = random.randint(0, n-1)
        if data[p][0] != 0:
            data[p][0] -= 1
            break
    return data

# tests 1..5 are manual
num = 5
data = []
for i in xrange(999999):
    data.append((random.randint(1, 10), random.randint(1, 1000)))
data.append((M, 1))
random.shuffle(data)

add_test(data)

