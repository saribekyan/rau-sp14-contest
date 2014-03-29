num = 1
def addtest(n):
    global num

    f = open('tests/' + str(num).zfill(3), 'w')
    f.write(str(n) + '\n')
    f.close()

    num += 1

N = [1, 2, 10, 100, 500, 10**3, 3456, 2 * 10**4, 2 * 10**5, 10**6, \
        10**7, 10**8, 10**9, 123456789, 987654321, 265346725, 123451234]

for n in N:
    addtest(n)

