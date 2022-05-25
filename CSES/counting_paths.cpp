#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 25;

vector<vector<int>> tree, up;
vector<int> depth, parent, values, ans;

void get_depth_and_parent(int node = 0, int p = -1) {
    for (int child: tree[node])
        if (child != p) {
            parent[child] = node;
            depth[child] = depth[node] + 1;
            get_depth_and_parent(child, node);
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

void solve(int node = 0, int p = -1) {
    ans[node] = values[node];
    for (int child: tree[node])
        if (child != p) {
            solve(child, node);
            ans[node] += ans[child];
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    depth.assign(n, 0);
    parent.assign(n, 0);
    get_depth_and_parent();

    up.assign(LOG, vector<int>(n));
    for (int i = 0; i < n; i++)
        up[0][i] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < n; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];

    values.assign(n, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;

        values[a - 1]++;
        values[b - 1]++;

        int c = lca(a - 1, b - 1);
        if (c) values[parent[c]]--;
        values[c]--;
    }

    ans.resize(n);
    solve();

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}