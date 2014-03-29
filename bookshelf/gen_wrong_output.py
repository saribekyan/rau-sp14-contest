def dumb(num):
    f = open('tests/00'+str(num), 'r')
    n = int(f.readline())
    f.close()
    
    f = open('tests/00'+str(num)+'.wrong', 'w')
    for i in xrange(1, n + 1):
        for j in xrange(1, n + 1):
            if i < j:
                f.write('TAKE ' + str(i) + ' ' + str(j) + ' 1\n')
                f.write('TAKE ' + str(j) + ' ' + str(i) + ' 2\n')
                f.write('PUT ' + str(i) + ' ' + str(j) + ' 2\n')
                f.write('PUT ' + str(j) + ' ' + str(i) + ' 1\n')

dumb(2)

