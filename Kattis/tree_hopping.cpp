#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

int n;
vector<vector<int>> tree;
vector<int> parent, depth;
vector<vector<int>> up;

void get_parent_and_depth(int node = 0, int p = 0) {
    parent[node] = p;
    for (int child: tree[node])
        if (child != p) {
            depth[child] = depth[node] + 1;
            get_parent_and_depth(child, node);
        }
}

int lca(int u, int v) {
    if (depth[v] < depth[u]) swap(u, v);

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

    int t; cin >> t;
    while (t--) {
        cin >> n;

        tree.assign(n, vector<int>());
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;

            tree[a - 1].push_back(b - 1);
            tree[b - 1].push_back(a - 1);
        }

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        parent.resize(n);
        depth.assign(n, 0);
        get_parent_and_depth();

        up.assign(LOG, vector<int>(n));
        for (int i = 0; i < n; i++)
            up[0][i] = parent[i];

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < n; j++)
                up[i][j] = up[i - 1][up[i - 1][j]];

        bool ans = true;
        for (int i = 1; i < n; i++) {
            int u = p[i - 1], v = p[i], w = lca(u, v);
            ans &= (depth[u] + depth[v] - 2 * depth[w] <= 3);
        }

        cout << ans << "\n";
    }
}