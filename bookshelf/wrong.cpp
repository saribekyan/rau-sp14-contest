#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            cout << "TAKE " << i << ' ' << j << ' ' << 1 << '\n';
            cout << "TAKE " << j << ' ' << i << ' ' << 2 << '\n';
            cout << "PUT " << i << ' ' << j << ' ' << 2 << '\n';
            cout << "PUT " << j << ' ' << i << ' ' <<1 << '\n';
        }
    return 0;
}

