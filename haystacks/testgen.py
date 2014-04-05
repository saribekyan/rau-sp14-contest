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
    a = [random.randint(0, M / 2) for i in xrange(n)]
    s1 = sum(a)
    l = [random.randint(1, M / 2) for i in xrange(n)]
    s2 = sum(l)
    t = s1 - s2
    if t < 0:
        t = -t
        for i in xrange(n):
            a[i] += t / (n - i)
            t -= t / (n - i)
    else:
        for i in xrange(n):
            l[i] += t / (n - i)
            t -= t / (n - i)
    return zip(a, l)

def almost_exact_sum(n):
    data = gen_exact_sum(n)
    while True:
        p = random.randint(0, n-1)
        if data[p][0] != 0:
            data[p] = (data[p][0] - 1, data[p][1])
            break
    return data

# tests 1..5 are manual


num = 12
add_test(almost_exact_sum(1000000))
# add_test(gen_random(1000000))
# data = []
# for i in xrange(999999):
#     data.append((random.randint(1, 10), random.randint(1, 1000)))
# data.append((M, 1))
# random.shuffle(data)
# 
# add_test(data)

