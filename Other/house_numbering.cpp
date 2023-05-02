#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<tuple<int, int, int>>> g;
vector<int> vis, path, cycle, ans;
vector<set<int>> adjacent;

bool get_cycle(int v = 0, int prev = -1) {
    if (vis[v] == 2) return false;
    if (vis[v] == 1) {
        int idx = (int) path.size() - 1;
        while (idx >= 0 && path[idx] != v)
            cycle.push_back(path[idx--]);

        cycle.push_back(v);
        return true;
    }

    vis[v] = 1;
    path.push_back(v);

    for (auto [u, _, __]: g[v])
        if (u != prev && get_cycle(u, v))
            return true;

    vis[v] = 2;
    path.pop_back();

    return false;
}

bool get_adjacent(int v) {
    for (auto [u, h, id]: g[v])
        if (!vis[u]) {
            if (adjacent[v].count(h))
                return false;

            adjacent[v].insert(h);
            ans[id] = u + 1;
        }

    vis[v] = 2;
    for (auto [u, _, __]: g[v])
        if (!vis[u] && !get_adjacent(u))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    g.assign(n, vector<tuple<int, int, int>>());
    for (int i = 0; i < n; i++) {
        int u, v, h;
        cin >> u >> v >> h;

        g[u - 1].emplace_back(v - 1, h, i);
        g[v - 1].emplace_back(u - 1, h, i);
    }

    vis.assign(n, 0);
    assert(get_cycle());

    int sz = cycle.size();
    vector<pair<int, int>> houses;

    for (int i = 0; i < sz; i++) {
        int idx = 0;
        auto [v, h, id] = g[cycle[i]][0];

        while (v != cycle[(i + 1) % sz] && idx + 1 < (int) g[cycle[i]].size())
            tie(v, h, id) = g[cycle[i]][++idx];

        assert(idx < (int) g[cycle[i]].size());
        houses.emplace_back(h, id);
    }

    vis.assign(n, 0);
    for (int v: cycle)
        vis[v] = 2;

    bool possible = true;
    adjacent.assign(n, set<int>());
    ans.assign(n, -1);

    for (int v: cycle)
        if (!get_adjacent(v))
            possible = false;

    if (possible) {
        for (int i = 0; i < sz && possible; i++) {
            if (adjacent[cycle[i]].count(houses[i].first)) possible = false;
            else ans[houses[i].second] = cycle[(i + 1) % sz] + 1;
        }

        if (!possible) {
            possible = true;
            for (int i = 0; i < sz && possible; i++) {
                if (adjacent[cycle[i]].count(houses[(i - 1 + sz) % sz].first)) possible = false;
                else ans[houses[i].second] = cycle[i] + 1;
            }
        }
    }

    if (!possible) cout << "impossible\n";
    else {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}