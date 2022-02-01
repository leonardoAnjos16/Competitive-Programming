#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 20;

vector<vector<pair<int, int>>> tree;
vector<int> parent, depth;
vector<long> sum;
vector<vector<int>> up;

void get_parent_depth_and_sum(int node = 0, int p = -1) {
    for (auto [child, weight]: tree[node])
        if (child != p) {
            parent[child] = node;
            depth[child] = depth[node] + 1;
            sum[child] = sum[node] + weight;
            get_parent_depth_and_sum(child, node);
        }
}

int lca(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);

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
        int N;
        cin >> N;

        tree.assign(N, vector<pair<int, int>>());
        for (int i = 1; i < N; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            tree[a - 1].emplace_back(b - 1, c);
            tree[b - 1].emplace_back(a - 1, c);
        }

        parent.assign(N, 0);
        depth.assign(N, 0);
        sum.assign(N, 0);
        get_parent_depth_and_sum();

        up.assign(LOG, vector<int>(N));
        for (int i = 0; i < N; i++)
            up[0][i] = parent[i];

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < N; j++)
                up[i][j] = up[i - 1][up[i - 1][j]];

        string op;
        while (cin >> op, op != "DONE") {
            int a, b;
            cin >> a >> b;

            int c = lca(a - 1, b - 1);
            if (op == "DIST") {
                long ans = sum[a - 1] + sum[b - 1] - 2 * sum[c];
                cout << ans << "\n";
            } else {
                int k; cin >> k;

                int v = a - 1, nodes = depth[a - 1] + depth[b - 1] - 2 * depth[c] + 1;
                if (k <= depth[a - 1] - depth[c] + 1) k--;
                else k = nodes - k, v = b - 1;

                for (int i = 0; i < LOG; i++)
                    if (k & (1 << i))
                        v = up[i][v];

                cout << (v + 1) << "\n";
            }
        }
    }
}