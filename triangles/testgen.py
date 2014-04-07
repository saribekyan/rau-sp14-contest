import random

MAX = 100000000
num = 5 # 4 manual tests

def add_test(triangles):
    global num
    f = open('tests/' + str(num).zfill(3), 'w')

    f.write(str(len(triangles)) + '\n')
    for triangle in triangles:
        f.write(str(triangle[0]))
        for c in triangle[1:]:
            f.write(' ' + str(c));
        f.write('\n')
    f.close()

    print 'test', num, 'done'
    num += 1

def area(triangle):
    x1, y1, x2, y2, x3, y3 = triangle
    return abs(x1 * y2 + x2 * y3 + x3 * y1 - \
            (x2 * y1 + x3 * y2 + x1 * y3));

def contains(triangle, (x, y)):
    x1, y1, x2, y2, x3, y3 = triangle
    return area(triangle) == area((x1, y1, x2, y2, x, y)) + area((x1, y1, x3, y3, x, y)) + area((x2, y2, x3, y3, x, y))

def get_point(x = -MAX, X = MAX, y = -MAX, Y = MAX):
    return (random.randint(x, X), random.randint(y, Y))

def get_triangle():
    while True:
        triangle = []
        for i in xrange(3):
            triangle += list(get_point())
        triangle = tuple(triangle)
        if area(triangle) != 0:
            return triangle

# completely random n triangles
def gen_rand(n):
    return [get_triangle() for i in xrange(n)]

# random triangles sharing m v > 2 verticies
def gen_rand_less_vertices(n, m):
    pts = []
    i = 0
    while i < m:
        pt = get_point();
        if pt not in pts:
            pts.append(pt)
            i += 1
    flag = False
    for a in pts:
        for b in pts:
            for c in pts:
                if area(tuple(list(a) + list(b) + list(c))) != 0:
                    flag = True
            if flag:
                break
        if flag:
            break
    if not flag:
        return gen_rand_less_vertices(n, m)

    i = 0
    triangles = []
    while i < n:
        triangle = []
        for t in xrange(3):
            triangle += list(pts[random.randint(0, m-1)])
        triangle = tuple(triangle)
        if area(triangle) != 0:
            triangles.append(triangle)
            i += 1
    return triangles

# returns
def gen_nested(m):
    triangle = tuple((list(get_point(-MAX, -MAX / 2, -MAX, -MAX / 2)) + list(get_point(MAX / 2, MAX, -MAX, -MAX / 2)) + list(get_point(-MAX, MAX, MAX/2, MAX))))
    triangles = [triangle]

    prev = 2*MAX
    R = 4
    for k in xrange(m - 1):
        x = min([triangle[2*i] for i in xrange(3)])
        X = max([triangle[2*i] for i in xrange(3)])
        y = min([triangle[2*i + 1] for i in xrange(3)])
        Y = max([triangle[2*i + 1] for i in xrange(3)])

        dx = X - x
        dy = Y - y

        #print dx, dy

        #if dx + dy < prev:
        #    R -= 1
        #    prev = dx + dy

        tpts = []
        M = 100000
        for C in xrange(M):
            pt = get_point(x, x + dx/R, y, y + dy/R)
            if contains(triangle, pt) and (len(tpts) != 4 or area(tuple(tpts + list(pt))) != 0):
                tpts += list(pt)
                break

        for C in xrange(M):
            pt = get_point(X - dx/R, X, y, y + dy/R)
            if contains(triangle, pt) and (len(tpts) != 4 or area(tuple(tpts + list(pt))) != 0):
                tpts += list(pt)
                break

        for C in xrange(M):
            pt = get_point(x, X, Y - dy / R, Y)
            if contains(triangle, pt) and (len(tpts) != 4 or area(tuple(tpts + list(pt))) != 0):
                tpts += list(pt)
                break

        if len(tpts) != 6:
            return gen_nested(m)

        triangle = tuple(tpts)
        triangles.append(triangle)
    return triangles

def gen_nested_right_angled(m):
    return [(0, 0, i+1, 0, 0, i+1) for i in xrange(m)]

def gen_nested_chain(n):
    d = []
    while n >= 30:
        d += gen_nested(30)
        n -= 30
    if n > 0:
        d += gen_nested(n)
    return d


add_test(gen_rand(100))
add_test(gen_rand(1000))
MAX = 1000
add_test(gen_rand(1000))
MAX = 100000000
add_test(gen_rand_less_vertices(100, 10))
add_test(gen_rand_less_vertices(1000, 100))
add_test(gen_rand_less_vertices(1000, 3)) # same triangle x 1000
add_test(gen_nested_chain(100))
add_test(gen_nested_right_angled(1000))
add_test(gen_nested_chain(100) + gen_nested_right_angled(10) + gen_rand_less_vertices(800, 50) + gen_rand(40))
add_test(gen_nested_chain(19) + gen_nested_right_angled(78) + gen_rand_less_vertices(800, 50) + gen_rand(40))
add_test(gen_nested_chain(29) + gen_nested_right_angled(9) + gen_rand_less_vertices(800, 50) + gen_rand(40))

