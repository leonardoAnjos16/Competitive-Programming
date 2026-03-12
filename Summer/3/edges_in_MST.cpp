#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct DSU {
private:
    int n;
    vector<int> ds, sz;

public:
    DSU(int n) {
        this->n = n;
        sz.assign(n, 1);

        ds.resize(n);
        for (int i = 0; i < n; i++)
            ds[i] = i;
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j) {
        i = find(i); j = find(j);
        if (sz[i] > sz[j]) swap(i, j);
        if (i != j) sz[j] += sz[i];
        ds[i] = j;
    }
};

int t = 0;
vector<vector<pair<int, int>>> g;
vector<int> indices, tin, low;
vector<bool> vis, bridge;

void find_bridges(int v, int parent = -1) {
    vis[v] = true;
    tin[v] = low[v] = t++;

    for (int i = indices[v]; i < (int) g[v].size(); i++) {
        auto [u, idx] = g[v][i];
        if (idx == parent) continue;

        if (vis[u]) low[v] = min(low[v], tin[u]);
        else {
            find_bridges(u, idx);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) bridge[idx] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = make_tuple(w, a - 1, b - 1, i);
    }

    sort(edges.begin(), edges.end());

    DSU tree(n);
    int start = 0;
    vector<int> ans(m, 1);

    g.assign(n, vector<pair<int, int>>());
    indices.assign(n, 0);
    vis.assign(n, false);
    bridge.assign(m, false);
    tin.resize(n);
    low.resize(n);

    while (start < m) {
        int end = start + 1;
        while (end < m && get<0>(edges[end]) == get<0>(edges[start])) end++;

        for (int i = start; i < end; i++) {
            auto [w, a, b, idx] = edges[i];
            int u = tree.find(a), v = tree.find(b);

            g[u].emplace_back(v, idx);
            g[v].emplace_back(u, idx);

            vis[u] = vis[v] = false;
            if (u == v) ans[idx] = 0;
        }

        for (int i = start; i < end; i++)
            if (!vis[tree.find(get<1>(edges[i]))])
                find_bridges(tree.find(get<1>(edges[i])));

        for (int i = start; i < end; i++) {
            auto [w, a, b, idx] = edges[i];
            if (bridge[idx]) ans[idx] = 2;
            tree.join(a, b);

            indices[tree.find(a)] = g[tree.find(a)].size();
            indices[tree.find(b)] = g[tree.find(b)].size();
        }

        start = end;
    }

    for (int i = 0; i < m; i++) {
        if (!ans[i]) cout << "none\n";
        else if (ans[i] == 1) cout << "at least one\n";
        else cout << "any\n";
    }
}