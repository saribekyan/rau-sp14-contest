import random

num = 1
def add_test(edges):
    global num
    f = open('tests/' + str(num).zfill(3), 'w')
    f.write(str(len(edges) + 1) + '\n')
    for edge in edges:
        f.write(str(edge[0] + 1) + ' ' + str(edge[1] + 1) + ' ' + str(edge[2]) + '\n')
    f.close()
    print 'test', num, 'done'
    num += 1

def gen_line(n, gen_f, x=0.5):
    ind = [i for i in xrange(n)]
    random.shuffle(ind)
    d = []
    for i in xrange(n - 1):
        d.append((ind[i], ind[i + 1], gen_f(x)))
    return d

par = []
rank = []

def find(p):
    global par
    global rank
    if p == par[p]:
        return p
    par[p] = find(par[p])
    return par[p]

def join(p, q):
    global par
    global rank
    p = find(p)
    q = find(q)
    if p == q:
        return False # already joined
    if rank[p] < rank[q]:
        par[p] = q
        rank[q] += rank[p]
    else:
        par[q] = p
        rank[p] += rank[q]
    return True

def gen_random(n, gen_f, x=0.5, l=0):
    global par
    global rank
    par = [i for i in xrange(n)]
    rank = [1 for i in xrange(n)]

    edges = gen_line(l, gen_f, x)
    for edge in edges:
        join(edge[0], edge[1])

    m = len(edges)
    while m < n - 1:
        p = random.randint(0, n - 1)
        q = random.randint(0, n - 1)
        if join(p, q):
            edges.append((p, q, gen_f(x)))
            m += 1
    return edges

# tests 1 .. 5 are manual
num = 6

ones = lambda x: 1
zeros = lambda x: 0
rands = lambda x: int(random.random() < x)

# for tests 6 .. 12 , n <= 1000
add_test(gen_line(1000, ones))
add_test(gen_line(1000, rands))
add_test(gen_random(100, rands, 0.8))
add_test(gen_random(500, ones, 200))
add_test(gen_random(1000, zeros, 800))
add_test(gen_random(1000, rands, 0.7, 300))
add_test(gen_random(999, rands, 0.3, 500))

# 13 .. 20
add_test(gen_line(100000, rands, 0.3))
add_test(gen_line(100000, ones))
add_test(gen_random(40000, rands))
add_test(gen_random(50000, rands, 0.8, 20000))
add_test(gen_random(80000, rands, 0.6, 30000))
add_test(gen_random(100000, zeros))
add_test(gen_random(100000, rands, 0.7, 60000))
add_test(gen_random(100000, rands, 0.9, 30000))

