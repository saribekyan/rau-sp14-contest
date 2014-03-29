#include <iostream>
using namespace std;

const long long MOD = 1000000007LL;

struct Matrix {
    long long a, b, c, d;
    Matrix(long long a, long long b, long long c, long long d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    Matrix operator * (Matrix other) {
        return Matrix(
                (a * other.a + b * other.c) % MOD,
                (a * other.b + b * other.d) % MOD,
                (c * other.a + d * other.c) % MOD,
                (c * other.b + d * other.d) % MOD);
    }
    Matrix operator + (Matrix other) {
        return Matrix((a + other.a) % MOD,
                (b + other.b) % MOD,
                (c + other.c) % MOD,
                (d + other.d) % MOD);
    }
};

Matrix power(Matrix m, int p) {
    if (p == 0) {
        return Matrix(1, 0, 0, 1);
    }
    Matrix r = power(m, p / 2);
    r = r * r;
    if (p % 2)
        r = r * m;
    return r;
}

Matrix sum(Matrix m, int n) {
    if (n == 0)
        return Matrix(1, 0, 0, 1);
    if (n % 2 == 0) {
        Matrix r = sum(m, n / 2 - 1);
        return r + power(m, n / 2) + power(m, n / 2 + 1) * r;
    } else {
        Matrix r = sum(m, n / 2);
        return r + power(m, (n + 1) / 2) * r;
    }
}
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 26 << '\n';
        return 0;
    }

    Matrix a = sum(Matrix(5, 105, 1, 0), n - 1);

    cout << a.a * 26 + a.b << '\n';

    return 0;
}

