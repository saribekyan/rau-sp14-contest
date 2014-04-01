#include <iostream>
#include <string>
#include <vector>
#include "../testlib.h"
using namespace std;

#define N 100000
#define M 1000000000

#define OK 0
#define PE 4
#define WA 5

bool finish() {
    if (!ouf.seekEof())
        return false;
    ouf.close();
    return true;
}
int main(int argc, char * argv[]) {
    setName("interacts with user program");
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
    inf.close();
    cout << n << ' ' << f << '\n' << flush;

    int m = 100 + n / 5 + 1;
    while (m--) {
        string s = ouf.readToken();

        if (s == "YES" || s == "NO") {
            if (finish()) {
                tout << s << '\n' << flush;
                return OK;
            } else {
                tout << "The last line of the output should contain YES or NO.\n";
                return PE;
            }
            continue;
        }
        if (s == "OPEN") {
            int num = ouf.readInt() - 1;
            if (0 <= num && num < n) {
                cout << vp[num].first << ' ' << vp[num].second << '\n' << flush;
                continue;
            }
            tout << "Invalid box number: " << num + 1 << '\n';
            return PE;
        }

        tout << "Each non-empty line has to start with YES or NO\n";
        return PE;
    }
    tout << "Too many lines of output.\n";
    return PE;
}

