#include <iostream>
#include <vector>
using namespace std;

vector< vector< pair<int, int> > > g;
vector<int> depths;
void get_depths(int p, int par) {
    for (int i = 0; i < g[p].size(); ++i) {
        int q = g[p][i].first;
        if (q != par) {
            get_depths(q, p);
            depths[p] = max(depths[p], depths[q] + g[p][i].second);
        }
    }
}

pair<int, int> solve(int p, int par, int up) {
    if (par != -1 && g[p].size() == 1) {
        return make_pair(up, p);
    }

    int w1, d1 = -1, w2, d2 = -1;
    for (int i = 0; i < g[p].size(); ++i) {
        int q = g[p][i].first;
        if (g[p][i].first != par) {
           int dep = depths[q] + g[p][i].second;
           if (dep > d1) {
               d2 = d1;
               w2 = w1;
               d1 = dep;
               w1 = q;
           } else if (dep > d2) {
               d2 = dep;
               w2 = q;
           }
        }
    }

    pair<int, int> best = make_pair(max(up, depths[p]), p);
    for (int i = 0; i < g[p].size(); ++i) {
        int q = g[p][i].first;
        if (q != par) {
            if (q == w1) {
                best = min(best, solve(q, p, max(up, d2) + g[p][i].second));
            } else {
                best = min(best, solve(q, p, max(up, d1) + g[p][i].second));
            }
        }
    }
    return best;
}
int main() {
//    rlimit r;
//    r.rlim_cur = 100000000;
//    r.rlim_max = 200000000;
//    setrlimit(RLIMIT_STACK, &r);
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        g[i] = vector< pair<int, int> >();
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v, p;
        cin >> u >> v >> p;
        g[u - 1].push_back(make_pair(v - 1, p));
        g[v - 1].push_back(make_pair(u - 1, p));
    }

    // cerr << "pre-depths\n";
    depths.resize(n, 0);
    get_depths(0, -1);
    // cerr << "depths\n";
    cout << solve(0, -1, 0).second + 1 << '\n';
    return 0;
}

