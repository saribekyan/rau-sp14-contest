#include <iostream>
using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    for (int i = 0; i < n; ++i) {
        cout << "OPEN " << i + 1 << flush;
        cin >> v >> p;
        if (v == f) {
            cout << "YES" << flush;
            return 0;
        }
    }
    cout << "NO" << flush;
    return 0;
}

