#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Triangle {
    private:
        long long x1, y1, x2, y2, x3, y3;
    public:
        Triangle() {
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        }

        Triangle(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
            this->x3 = x3;
            this->y3 = y3;
        }

        long long area2() const  {
            long long a = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
            return a > 0 ? a : - a;
        }

        bool contains(Triangle t) {
            return contains(t.x1, t.y1) &&
                contains(t.x2, t.y2) &&
                contains(t.x3, t.y3);
        }

        bool contains(long long x, long long y) {
            long long a1 = Triangle(x1, y1, x2, y2, x, y).area2();
            long long a2 = Triangle(x1, y1, x3, y3, x, y).area2();
            long long a3 = Triangle(x2, y2, x3, y3, x, y).area2();
            return area2() == a1 + a2 + a3;
        }

        bool operator < (const Triangle &other) const {
            return area2() < other.area2();
        }
};
int main() {
    int n;
    cin >> n;
    vector<Triangle> triangles;
    for (int i = 0; i < n; ++i) {
        triangles.push_back(Triangle()); // also reads
    }

    sort(triangles.begin(), triangles.end());

    int ans = 0;
    vector<int> d(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (triangles[i].contains(triangles[j])) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
        ans = max(ans, d[i]);
    }
    cout << ans << '\n';
    return 0;
}

