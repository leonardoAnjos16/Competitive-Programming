#include <bits/stdc++.h>

using namespace std;

int cnt;
vector<bool> eartifact, cartifact, bridge, vis;
vector<vector<pair<int, bool>>> tree;
vector<vector<pair<int, int>>> g;
vector<int> tin, low, component;

void find_bridges(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = cnt++;

    for (auto [u, edge_id]: g[v]) {
        if (u == p) continue;

        if (vis[u]) low[v] = min(low[v], tin[u]);
        else {
            find_bridges(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) bridge[edge_id] = true;
        }
    }
}

void get_component(int v, int component_id) {
    component[v] = component_id;
    for (auto [u, edge_id]: g[v])
        if (component[u] == -1 && !bridge[edge_id])
            get_component(u, component_id);
}

bool reachable(int node, int t, int parent = -1, bool artifact = false) {
    if (node == t) return artifact || cartifact[node];

    for (auto [child, has_artifact]: tree[node])
        if (child != parent && reachable(child, t, node, artifact || has_artifact || cartifact[node]))
            return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    eartifact.assign(m, false);
    g.assign(n, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z) eartifact[i] = true;
        g[x - 1].emplace_back(y - 1, i);
        g[y - 1].emplace_back(x - 1, i);
    }

    cnt = 0;
    tin.assign(n, 0);
    low.assign(n, 0);
    vis.assign(n, false);
    bridge.assign(m, false);

    for (int i = 0; i < n; i++)
        if (!vis[i])
            find_bridges(i);

    int id = 0;
    component.assign(n, -1);

    for (int i = 0; i < n; i++)
        if (component[i] == -1)
            get_component(i, id++);

    cartifact.assign(id, false);
    for (int i = 0; i < n; i++)
        for (auto [v, edge_id]: g[i])
            if (component[i] == component[v] && eartifact[edge_id])
                cartifact[component[i]] = true;

    tree.assign(id, vector<pair<int, bool>>());
    for (int i = 0; i < n; i++)
        for (auto [v, edge_id]: g[i])
            if (component[i] != component[v])
                tree[component[i]].emplace_back(component[v], eartifact[edge_id]);

    int a, b;
    cin >> a >> b;

    cout << (reachable(component[a - 1], component[b - 1]) ? "YES" : "NO") << "\n";
}