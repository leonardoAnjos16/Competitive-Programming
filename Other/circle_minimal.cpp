#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<pair<int, int>>> g;
set<tuple<int, int, int>> cycle;

vector<bool> vis;
int node = -1, parent = -1;

bool get_cycle(int v = 0, int p = -1) {
    if (vis[v]) {
        node = v;
        parent = p;
        return true;
    }

    vis[v] = true;
    for (auto [w, u]: g[v])
        if (u != p && get_cycle(u, v) && (u != node || v == parent)) {
            cycle.emplace(w, min(u, v), max(u, v));
            return true;
        }

    return false;
}

bool erase(int v, pair<int, int> wu) {
    auto [w, u] = wu;
    return cycle.erase(make_tuple(w, min(u, v), max(u, v)));
}

void emplace(int v, pair<int, int> wu) {
    auto [w, u] = wu;
    cycle.emplace(w, min(u, v), max(u, v));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    g.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u - 1].emplace_back(w, v - 1);
        g[v - 1].emplace_back(w, u - 1);
    }

    vis.assign(n, false);
    get_cycle();

    long ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
        
        bool erased_first = erase(i, g[i][0]);
        for (int j = 1; j <= 2 && j < (int) g[i].size(); j++) {
            bool erased_second = erase(i, g[i][j]);

            auto [mn, u, v] = *cycle.begin();
            ans = min(ans, (long) g[i][0].first + g[i][j].first + mn);

            if (erased_second) emplace(i, g[i][j]);
        }

        if (erased_first) emplace(i, g[i][0]);
    }

    cout << ans << "\n";
}