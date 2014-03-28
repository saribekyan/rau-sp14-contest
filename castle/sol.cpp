#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    int k = 0;
    while (k*k < n)
        ++k;

    vector< pair<int, int> > d(n, make_pair(-1, -1)); // value, next pairs
    vector< pair<int, int> > base;
    for (int i = 0; i < k; ++i) {
        int b = rand() % n;
        if (d[b].second != -1) // next != -1 => OPEN b has been outputted
            continue;
        cout << "OPEN " << b + 1 << '\n';
        int v, p;
        cin >> v >> p;
        if (v == f) {
            cout << "YES\n";
            return 0;
        }

        base.push_back(make_pair(v, b));
        d[b] = make_pair(v, p - 1);
    }

    sort(base.begin(), base.end());
    k = base.size();

    int p, q, i;
    for (i = 0; i < k; ++i)
        if (base[i].first > f)
            break;
    if (i == k) 
        p = base[k - 1].second;
    else
        p = base[(i - 1 + k)%k].second;
    q = base[(p + 1)%k].second;

    do {
        cout << "OPEN " << p + 1 << '\n';
        int v;
        cin >> v >> p;
        if (v == f) {
            cout << "YES\n";
            return 0;
        }
        --p;
    }
    while (p != q);
    cout << "NO\n";
    return 0;
}

