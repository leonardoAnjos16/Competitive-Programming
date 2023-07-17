#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

int t = 0;
vector<vector<pair<int, int>>> g;
vector<int> tin, low, component;
vector<bool> bridge, vis;

vector<vector<int>> tree;
vector<int> depth, parent;
vector<vector<int>> up;

void get_bridges(int v = 0, int prev = -1) {
    vis[v] = true;
    tin[v] = low[v] = t++;

    for (auto [u, id]: g[v]) {
        if (u == prev) continue;

        if (vis[u]) low[v] = min(low[v], tin[u]);
        else {
            get_bridges(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) bridge[id] = true;
        }
    }
}

void get_component(int v, int c) {
    component[v] = c;
    for (auto [u, id]: g[v])
        if (!bridge[id] && component[u] == -1)
            get_component(u, c);
}

void init(int node = 0) {
    vis[node] = true;
    for (int child: tree[node])
        if (!vis[child]) {
            depth[child] = depth[node] + 1;
            parent[child] = node;
            init(child);
        }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    int diff = depth[v] - depth[u];
    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i))
            v = up[i][v];

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--)
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }

    return parent[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;

    g.assign(N, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        g[A - 1].emplace_back(B - 1, i);
        g[B - 1].emplace_back(A - 1, i);
    }

    tin.resize(N);
    low.resize(N);
    vis.assign(N, false);
    bridge.assign(M, false);
    get_bridges();

    int c = 0;
    component.assign(N, -1);

    for (int i = 0; i < N; i++)
        if (component[i] == -1)
            get_component(i, c++);

    tree.assign(c, vector<int>());
    for (int i = 0; i < N; i++)
        for (auto [v, _]: g[i])
            if (component[i] != component[v])
                tree[component[i]].push_back(component[v]);

    vis.assign(c, false);
    parent.assign(c, 0);
    depth.assign(c, 0);
    init();

    vector<int> sz(c, 0);
    for (int i = 0; i < N; i++)
        sz[component[i]]++;

    up.assign(LOG, vector<int>(c));
    vector<vector<int>> mx(LOG, vector<int>(c));

    for (int i = 0; i < c; i++) {
        up[0][i] = parent[i];
        mx[0][i] = max(sz[i], sz[parent[i]]);
    }

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < c; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][up[i - 1][j]]);
        }

    while (Q--) {
        int S, E;
        cin >> S >> E;

        int u = component[S - 1], v = component[E - 1], l = lca(u, v);

        int ans = max(sz[u], sz[v]);
        int diff = depth[u] - depth[l];

        for (int i = 0; i < LOG; i++)
            if (diff & (1 << i)) {
                ans = max(ans, mx[i][u]);
                u = up[i][u];
            }

        diff = depth[v] - depth[l];
        for (int i = 0; i < LOG; i++)
            if (diff & (1 << i)) {
                ans = max(ans, mx[i][v]);
                v = up[i][v];
            }

        cout << (ans == 1 ? "YES" : "NO") << "\n";
    }
}