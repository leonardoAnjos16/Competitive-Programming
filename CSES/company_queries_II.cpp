#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 25;

vector<int> e, depth;
vector<vector<int>> up;

int get_depth(int node) {
    if (!node) return depth[node] = 0;
    if (depth[node] != -1) return depth[node];
    return depth[node] = get_depth(e[node]) + 1;
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

    return e[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    e.assign(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> e[i];
        e[i]--;
    }

    depth.assign(n, -1);
    for (int i = 0; i < n; i++)
        get_depth(i);

    up.assign(LOG, vector<int>(n));
    for (int i = 0; i < n; i++)
        up[0][i] = e[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < n; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];

    while (q--) {
        int a, b;
        cin >> a >> b;

        int ans = lca(a - 1, b - 1) + 1;
        cout << ans << "\n";
    }
}