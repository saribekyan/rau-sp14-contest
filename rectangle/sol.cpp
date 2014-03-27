#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
    void read() {
        cin >> x1 >> y1 >> x2 >> y2;
    }

    void transform(vector<int> & yCoordinates) {
        y1 = lower_bound(yCoordinates.begin(), yCoordinates.end(), y1) - yCoordinates.begin() + 1;
        y2 = lower_bound(yCoordinates.begin(), yCoordinates.end(), y2) - yCoordinates.begin() + 1;
    }
};

class Fenwick {
    int size;
    vector<int> data;
public:
    Fenwick(int size) {
        this->size = size;
        data.resize(size + 1, 0);
    }

    void add(int index, int val) {
        while (index <= size) {
            data[index] += val;
            index += index & -index;
        }
    }

    int intervalSum(int p, int q) {
        if (p > q)
            return 0;
        int s = 0;
        while (q) {
            s += data[q];
            q -= q & -q;
        }
        --p;
        while (p) {
            s -= data[p];
            p -= p & -p;
        }
        return s;
    }
};
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 1 << '\n';
        return 0;
    }
    vector<int> yCoordinates;
    vector<Rectangle> rectangles;
    for (int i = 0; i < n; ++i) {
        Rectangle r;
        r.read();
        rectangles.push_back(r);
        yCoordinates.push_back(r.y1);
        yCoordinates.push_back(r.y2);
    }
    sort(yCoordinates.begin(), yCoordinates.end());
    vector< pair<int, pair<int, int> > > vertical;
    vector< pair<int, pair<int, bool> > > horizontalEndpoints; // x-coordinate, y-coordinate, open-close
    for (int i = 0; i < n; ++i) {
        Rectangle &r = rectangles[i];
        r.transform(yCoordinates);
        vertical.push_back(make_pair(r.x1, make_pair(r.y1, r.y2)));
        vertical.push_back(make_pair(r.x2, make_pair(r.y1, r.y2)));
        horizontalEndpoints.push_back(make_pair(r.x1, make_pair(r.y1, true)));
        horizontalEndpoints.push_back(make_pair(r.x2, make_pair(r.y1, false)));
        horizontalEndpoints.push_back(make_pair(r.x1, make_pair(r.y2, true)));
        horizontalEndpoints.push_back(make_pair(r.x2, make_pair(r.y2, false)));
    }

    sort(horizontalEndpoints.begin(), horizontalEndpoints.end());
    sort(vertical.begin(), vertical.end());

    Fenwick fenwick(vertical.size());

    int pointIndex = 0;
    long long intersectionCount = 0;
    for (int i = 0; i < vertical.size(); ++i) {
        while (pointIndex < horizontalEndpoints.size() &&
                horizontalEndpoints[pointIndex].first <= vertical[i].first) {
            if (horizontalEndpoints[pointIndex].second.second)
                fenwick.add(horizontalEndpoints[pointIndex].second.first, 1);
            else
                fenwick.add(horizontalEndpoints[pointIndex].second.first, -1);
            ++pointIndex;
        }
        intersectionCount += fenwick.intervalSum(vertical[i].second.first + 1, vertical[i].second.second - 1);
    }

    cout << intersectionCount + 2 << '\n';
    return 0;
}

