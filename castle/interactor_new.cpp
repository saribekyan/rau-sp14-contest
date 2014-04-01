#include <iostream>
#include <string>
#include <vector>
#include "../testlib.h"
using namespace std;

#define N 100000
#define M 1000000000
int main(int argc, char * argv[]) {
    // setName("interacts with user program");
    registerInteraction(argc, argv);

    int n, f;
    n = inf.readInt(1, N);
    f = inf.readInt(-M, M);

    vector< pair<int, int> > vp;
    for (int i = 0; i < n; ++i) {
        int v, p;
        v = inf.readInt(-M, M);
        p = inf.readInt(1, n);
        vp.push_back(make_pair(v, p));
    }
    cout << n << ' ' << f << '\n';

    int m = 100 + n / 5 + 1;
    while (m--) {
        string s = ouf.readWord("OPEN|YES|NO");

        if (s == "YES" || s == "NO") {
            ouf.seekEof();
            ouf.readEof();
            tout << s << '\n';
            quitf(_ok, ("output = " + s).c_str());
        }

        int num = ouf.readInt(1, n) - 1;

        cout << vp[num].first << ' ' << vp[num].second << '\n';
    }
    quitf(_pe, "Too many output lines");
}

