import random
import time

MAX = 1000
T = 20
# n >= 3 for this random method to produce a connected set of rectangles
def genRandom(n):
    rectangles = set()
    xcoords = set()
    ycoords = set()

    rectangles.add((-MAX + 1, -MAX + 1, MAX - 1, MAX - 1))
    xcoords.add(-MAX+1)
    xcoords.add(MAX - 1)
    ycoords.add(-MAX + 1)
    ycoords.add(MAX - 1)
    n -= 1
    for i in xrange(n/2):
        while True:
            x1 = random.randint(-MAX + T, MAX - T)
            y1 = random.randint(-MAX + T, MAX - T)
            x2 = random.randint(-MAX + T, MAX - T)
            y2 = random.randint(-MAX + T, MAX - T)

            if x1 > x2:
                x1, x2 = x2, x1
            x2 += 4
            if y1 > y2:
                y1, y2 = y2, y1
            y2 += 4

            p = random.randint(x1 + 1, x2 - 2)
            q = random.randint(y1 + 1, y2 - 2)
            tmp = random.randint(0, 3)
            if tmp == 0:
                u = -MAX
                v = q + 1
            elif tmp == 1:
                u = MAX
                v = q + 1
            elif tmp == 2:
                u = p + 1
                v = MAX
            else:
                u = p + 1
                v = -MAX

            if u < p:
                u, p = p, u
            if v < q:
                v, q = q, v

            x = [it for it in [x1, x2, p, u] if it != MAX and it != -MAX]
            if len(x) < 3:
                continue
            y = [it for it in [y1, y2, q, v] if it != MAX and it != -MAX]
            if len(y) < 3:
                continue

            flag = True
            for it in x:
                if it in xcoords:
                    flag = False
                    break
            for it in y:
                if it in ycoords:
                    flag = False
                    break
            if not flag:
                continue
            for it in x:
                xcoords.add(it)
            for it in y:
                ycoords.add(it)
            rectangles.add((x1, y1, x2, y2))
            rectangles.add((p, q, u, v))
            break

    return rectangles

def dfs(p, g, vis):
    for q in xrange(len(g)):
        if g[p][q] and (not vis[q]):
            vis[q] = True
            dfs(q, g, vis)

def flatIntersect(p, q, u, v):
    return max(p, u) <= min(q, v)

def isOk(r1, r2):
    x1, y1, x2, y2 = r1
    p, q, u, v = r2
    if flatIntersect(y1, y2, q, v) and len(set([x1, x2]) & set([p, u])) != 0 or \
            flatIntersect(x1, x2, p, u) and len(set([y1, y2]) & set([q, v])) != 0:
                return False
    return True

def isIntersect(r1, r2):
    x1, y1, x2, y2 = r1
    p, q, u, v = r2
    a = max(x1, p)
    b = min(x2, u)
    c = max(y1, q)
    d = min(y2, v)
    return a <= b and c <= d

def check(rectangles):
    rectangles = list(rectangles)
    n = len(rectangles)
    for i in xrange(n):
        for j in xrange(i+1, n):
            if not isOk(rectangles[i], rectangles[j]):
                print i, j
                print rectangles[i]
                print rectangles[j]
                return False

    g = []
    for i in xrange(n):
        row = []
        for j in xrange(n):
            if i == j:
                row.append(False)
            else:
                row.append(isIntersect(rectangles[i], rectangles[j]))

        g.append(row)

    vis = [False for i in range(n)]
    vis[0] = True
    dfs(0, g, vis)
    return not (False in vis)


N = [10, 50, 100, 1000, 1000, 5000, 50000, 100000, 100000, 100000, 100000]
N_test = [10, 20, 30, 50, 80, 100]

random.seed(0)
def hard():
    global MAX
    global T
    MAX = 1000000000
    T = 100
    for i in xrange(len(N)):
        rectangles = genRandom(N[i])
        f = open('tests/' + str(i+1).zfill(3), 'w')
        f.write(str(len(rectangles)) + '\n')
        for x in rectangles:
            f.write(str(x[0]) + ' ' + str(x[1]) + ' ' + str(x[2]) + ' ' + str(x[3]) + '\n')
        f.close()
        print 'test', 'hard', i, 'n = ', N[i], 'done'

def all_pair_crossing(n):
    f = open('tests/' + str(len(N)+1).zfill(3), 'w')
    f.write(str(n) + '\n')
    for i in xrange(n):
        f.write(str(i) + ' ' + str(i) + ' ' + str(i + n) + ' ' + str(i + n) + '\n')
    f.close()
    print 'test', 'all_pair_cross', 'n = ', n, 'done'

def easy():
    global MAX
    global T
    MAX = 300
    T = 20
    for i in xrange(len(N_test)):
        rectangles = genRandom(N_test[i])
        f = open('tests/easy' + str(i+1).zfill(3), 'w')
        f.write(str(len(rectangles)) + '\n')
        print check(rectangles)
        for x in rectangles:
            f.write(str(x[0]) + ' ' + str(x[1]) + ' ' + str(x[2]) + ' ' + str(x[3]) + '\n')
        f.close()
        print 'test', 'easy', i, 'n = ', N_test[i], 'done'

hard()
easy()
all_pair_crossing(100000)

