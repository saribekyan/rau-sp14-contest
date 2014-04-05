#include <iostream>
#include <vector>
using namespace std;

int get_farthest(int p, int par, vector< vector< pair<int, int> > > &g) {
    int farthest = 0;
    for (int i = 0; i < g[p].size(); ++i) {
        int q = g[p][i].first;
        if (q != par) {
            farthest = max(farthest, get_farthest(q, p, g) + g[p][i].second);
        }
    }
    return farthest;
}
int main() {
    int n;
    cin >> n;
    vector< vector< pair<int, int> > > g(n, vector< pair<int, int> >());
    for (int i = 0; i < n - 1; ++i) {
        int u, v, p;
        cin >> u >> v >> p;
        g[u - 1].push_back(make_pair(v - 1, p));
        g[v - 1].push_back(make_pair(u - 1, p));
    }

    int best_dist = n + 1, p;
    for (int i = 0; i < n; ++i) {
        int dist = get_farthest(i, -1, g);
        if (dist < best_dist) {
            best_dist = dist;
            p = i;
        }
    }
    cout << p + 1 << '\n';
    return 0;
}

