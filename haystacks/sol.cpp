#include <iostream>
#include <vector>
#include <cstdio>
#include <assert.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        // scanf("%d", &a[i]);
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        // scanf("%d", &l[i]);
        cin >> l[i];
    }

    for (int p = 0; p < n;) {
        int i;
        long long s = 0;
        for (i = 0; i < n; ++i) {
            int q = (p + i) % n;
            if (s + a[q] >= l[q]) {
                s += a[q] - l[q];
            }
            else {
                break;
            }
        }
        if (i == n) {
            cout << p + 1 << '\n';
            return 0;
        }
        p += i + 1;
    }

    cout << -1 << '\n';
    return 0;
}

