#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

int n, m[MAX], ans = 0;
vector<vector<int> > g;
bitset<MAX> vis;

pair<int, int> solve(int v = 0) {
    vis[v] = true;
    
    pair<int, int> aux = {1, m[v]};
    for (int i = 0; i < (int) g[v].size(); i++) {
        if (!vis[g[v][i]]) {
            pair<int, int> children = solve(g[v][i]);
            aux.first += children.first;
            aux.second += children.second; 
            ans += abs(children.first - children.second);
        }
    }

    return aux;
}

int main() {
    while (scanf("%d", &n), n) {
        g.assign(n, vector<int>());
        for (int i = 0; i < n; i++) {
            int v; scanf("%d", &v);
            int d; scanf("%d %d", &m[--v], &d);

            for (int j = 0; j < d; j++) {
                int u; scanf("%d", &u);
                g[v].push_back(--u);
                g[u].push_back(v);
            }
        }

        solve();
        printf("%d\n", ans);

        g.clear();
        vis.reset();
        ans = 0;
    }
}