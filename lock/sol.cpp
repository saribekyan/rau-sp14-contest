#include <iostream>
#include <algorithm>
using namespace std;

/////////////////////////////////////////////////////////////
const bool TEST = false;

int a[100][100], d[101];

void init(int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = i * n + j;
}
void print(int n) {
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
/////////////////////////////////////////////////////////////

void take(int s, int b, int i) {
    if (TEST)
        d[i] = a[s][b];
    else
        cout << "TAKE " << s + 1 << ' ' << b + 1 << ' ' << i + 1 << '\n';
}
void put(int i, int s, int b) {
    if (TEST)
        a[s][b] = d[i];
    else
        cout << "PUT " << i + 1 << ' ' << s + 1 << ' ' << b + 1 << '\n';
}
int main() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "TAKE 1 2 1\nTAKE 2 1 2\nPUT 2 1 2\nPUT 1 2 1\n";
        return 0;
    }

    if (TEST)
        init(n);

    int m = 1;
    while (m*m < n) {
        ++m;
    }

    // m x m squares on diagonal
    for (int i = 0; i < m; ++i) {
        int base = i*m;
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < m; ++k)
                take(base + j, base + k, j*m + k);

        for (int j = 0; j < m; ++j)
            for (int k = 0; k < m; ++k)
                put(k*m + j, base + j, base + k);
    }

    // other m x m squares
    for (int i = 0; i < m; ++i)
        for (int j = i+1; j < m; ++j) {
            int base_i = i * m;
            int base_j = j * m;

            for (int k = 0; k < m; ++k)
                for (int l = 0; l < m; ++l)
                    take(base_i + k, base_j + l, k*m + l);

            int prev = m*m;
            for (int l = 0; l < m; ++l)
                for (int k = 0; k < m; ++k) {
                    take(base_j + l, base_i + k, prev);
                    put(k*m + l, base_j + l, base_i + k);
                    prev = k*m + l;
                }

            for (int k = 0; k+1 < m; ++k)
                for (int l = 0; l < m; ++l)
                    put(k*m + l, base_i + k + 1, base_j + l);

            for (int k = 0; k + 1 < m; ++k)
                put((m-1)*m + k, base_i, base_j + k + 1);

            put(m*m, base_i, base_j);
        }

    if (TEST)
        print(n);
    return 0;
}

