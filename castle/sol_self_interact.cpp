#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    int iter = 0;
    int C = 0;
    srand(time(0));
    while (true) {
start:
        ++iter;
    if (iter > 1)
        break;
    int n, f;
    // cin >> n >> f;
    n = 100000;
    f = -2;
    int k = 0;
    while (k*k < n)
        ++k;
    vector< pair<int, int> > d(n, make_pair(-1, -1)); // value, next pairs
    vector< pair<int, int> > base;
    
    int count = 0;
    for (int i = 0; i < k; ++i) {
        int b = rand() % n;
        if (d[b].second != -1) // next != -1 => OPEN b has been outputted
            continue;
        cout << "OPEN " << b + 1 << '\n';
        ++count;
        int v, p;
        // cin >> v >> p;
        v = b;
        p = 1 + (b + 1) % n;
        if (v == f) {
            cout << "YES\n";
            cerr << count << '\n';
            goto start;
        }

        base.push_back(make_pair(v, b));
        d[b] = make_pair(v, p - 1);
    }
    cerr << "First phase done\n";
    sort(base.begin(), base.end());
    k = base.size();

    int p, q, i;
    for (i = 0; i < k; ++i)
        if (base[i].first > f)
            break;
    if (i == k) 
        p = k - 1;
    else
        p = (i - 1 + k)%k;
    cerr << "p = " << p << '\n';
    q = base[(p + 1)%k].second;
    p = base[p].second;
    cerr << "q = " << q << '\n'; 
    do {
        cout << "OPEN " << p + 1 << '\n';
        ++count;
        int v;
        // cin >> v >> p;
        v = p;
        p = 1 + (p + 1) % n;
        if (v == f) {
            cout << "YES\n";
            cerr << count << '\n';
            goto start;
        }
        --p;
    }
    while (p != q);
    cout << "NO\n";
    C += count;
    cerr << count << '\n';
    }
    cerr << C << '\n';
    return 0;
}

