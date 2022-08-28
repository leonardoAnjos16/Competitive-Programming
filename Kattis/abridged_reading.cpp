#include <bits/stdc++.h>

using namespace std;

const int LOG = 20;

vector<int> pages;
vector<vector<int>> tree;
vector<int> parent, depth, dists;
vector<vector<int>> up;

void get_depth_and_dists(int node = 0) {
    for (int child: tree[node]) {
        depth[child] = depth[node] + 1;
        dists[child] = dists[node] + pages[child];
        get_depth_and_dists(child);
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

    int n, m;
    cin >> n >> m;

    pages.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> pages[i];

    parent.assign(n + 1, 0);
    tree.resize(n + 1, vector<int>());
    vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        indeg[b]++;
        outdeg[a]++;
        parent[b] = a;
        tree[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        if (!indeg[i]) {
            parent[i] = 0;
            tree[0].push_back(i);
        }

    depth.assign(n + 1, 0);
    dists.assign(n + 1, 0);
    get_depth_and_dists();

    up.assign(LOG, vector<int>(n + 1));
    for (int i = 0; i <= n; i++)
        up[0][i] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j <= n; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && !outdeg[i] && !outdeg[j])
                ans = min(ans, dists[i] + dists[j] - dists[lca(i, j)]);

    cout << ans << "\n";
}