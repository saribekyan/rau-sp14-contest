num = 1
def addtest(n, k):
    global num

    f = open('tests/' + str(num).zfill(3), 'w')
    f.write(str(n) + ' ' + str(k) + '\n')
    f.close()
    num += 1

tests = [[4,1], [5,3], [2,9], [5,5], [6,6], [8,9], [13, 12], [14,14], [15,12], [15,15],  \
    [16, 17], [18, 15], [20,20], [22, 21], [24, 23], [24, 26], [26,26], [29, 25], [30,29], [30,30] ]

for t in tests:
    addtest(t[0],t[1])

