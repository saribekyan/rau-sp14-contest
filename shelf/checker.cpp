#include <string>
#include <vector>
#include <iostream>
#include "../testlib.h"
using namespace std;

const int MAX_LINE = 100000;
const int MAX_CHANGE = 3600;

int main(int argc, char * argv[]) {
    setName("counts the number of row changes");
    registerTestlibCmd(argc, argv);

    int n;
    istringstream(inf.readString("2|25|100")) >> n;

    vector< vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = i*n + j;
    vector< int > mem(n + 1, -1);

    int recentRow = 0, rowChange = 0, lineCount = 0;
    pattern pt("TAKE|PUT");
    while (true) {

        if (ouf.eof() || ouf.eoln())
            break;
        string op = ouf.readWord(pt);
        int s, b, i;
        s = ouf.readInt(1, n) - 1;
        b = ouf.readInt(1, n) - 1;
        i = ouf.readInt(1, n + 1) - 1;
        ouf.seekEoln();
//        cerr << op << ' ' << p << ' ' << q << ' ' << v << '\n';

        ++lineCount;
        if (lineCount > MAX_LINE) {
            quitf(_wa, "More than %d output lines", MAX_LINE);
        }

        if (s != recentRow) {
            ++rowChange;
            recentRow = s;
            if (rowChange > MAX_CHANGE)
                quitf(_wa, "More than %d row changes", MAX_CHANGE);
        }

        if (op == "TAKE") {
            if (a[s][b] == -1)
                quitf(_wa, "TAKE: shelf %d, %d is already empty", s + 1, b + 1);
            else if (mem[i] != -1)
                quitf(_wa, "TAKE: bin location %d is occupied", i + 1);
            else {
                mem[i] = a[s][b];
                a[s][b] = -1;
            }
        } else {
            if (a[s][b] != -1)
                quitf(_wa, "PUT: shelf %d %d is occupied", s + 1, b + 1);
            else if (mem[i] == -1)
                quitf(_wa, "PUT: bin location %d is empty", i + 1);
            else {
                a[s][b] = mem[i];
                mem[i] = -1;
            }
        }
    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j)
//            cerr << a[i][j] << ' ';
//        cerr << '\n';
//    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] != j*n + i)
                quitf(_wa, "didn't transpose");
    quitf(_ok, "n = %d, row change = %d", n, rowChange);
    return 0;
}

