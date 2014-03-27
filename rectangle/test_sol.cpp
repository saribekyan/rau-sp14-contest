#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int COORD_MAX =  100;
const int N_MAX     =  1000;
// This solution assumes that the rectangle coordinates are
// smaller than COORD_MAX in absolute value and there are no more
// than N_MAX rectangles.
// Should be used to test the correctness of the optimal solution.

const int ARRAY_SIZE = 4*COORD_MAX + 3;

struct Rectangle {
    int x1, y1, x2, y2;
    void readAndTransform() {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = 2*(x1 + COORD_MAX) + 1;
        y1 = 2*(y1 + COORD_MAX) + 1;
        x2 = 2*(x2 + COORD_MAX) + 1;
        y2 = 2*(y2 + COORD_MAX) + 1;
    }

    void fill(vector< vector<bool> > & occupied) {
        for (int x = x1; x <= x2; ++x) {
            occupied[x][y1] = occupied[x][y2] = true;
        }
        for (int y = y1; y <= y2; ++y) {
            occupied[x1][y] = occupied[x2][y] = true;
        }
    }
};
int main() {
    int n;
    cin >> n;
    vector< vector<bool> > occupied(ARRAY_SIZE, vector<bool>(ARRAY_SIZE, false));
    for (int i = 0; i < n; ++i) {
        Rectangle r;
        r.readAndTransform();
        r.fill(occupied);
    }

    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, 1, -1, 0};

    int regionCount = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i)
        for (int j = 0; j < ARRAY_SIZE; ++j) {
            if (!occupied[i][j]) {
                stack< pair<int, int> > s;
                s.push(make_pair(i, j));
                occupied[i][j] = true;
                while (!s.empty()) {
                    pair<int, int> p = s.top(); s.pop();
                    for (int k = 0; k < 4; ++k) {
                        pair<int, int> q = make_pair(p.first + dx[k], p.second + dy[k]);
                        if (0 <= q.first && q.first < ARRAY_SIZE &&
                            0 <= q.second && q.second < ARRAY_SIZE &&
                            !occupied[q.first][q.second]) {
                            s.push(q);
                            occupied[q.first][q.second] = true;
                        }
                    }
                }
                ++regionCount;
            }
        }
    cout << regionCount << '\n';
    return 0;
}

