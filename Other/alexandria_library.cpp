#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

vector<vector<int>> tree;
vector<int> depth, nodes, parent;
vector<vector<int>> up;

void init(int node = 0, int p = -1) {
    nodes[node] = 1;
    for (int child: tree[node])
        if (child != p) {
            parent[child] = node;
            depth[child] = depth[node] + 1;

            init(child, node);
            nodes[node] += nodes[child];
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

int lift(int v, int dist) {
    for (int i = 0; i < LOG; i++)
        if (dist & (1 << i))
            v = up[i][v];

    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("library.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;

        tree.assign(N, vector<int>());
        for (int i = 1; i < N; i++) {
            int U, V;
            cin >> U >> V;

            tree[U - 1].push_back(V - 1);
            tree[V - 1].push_back(U - 1);
        }

        parent.assign(N, 0);
        depth.assign(N, 0);
        nodes.resize(N);
        init();

        up.assign(LOG, vector<int>(N));
        for (int i = 0; i < N; i++)
            up[0][i] = parent[i];

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < N; j++)
                up[i][j] = up[i - 1][up[i - 1][j]];

        while (Q--) {
            int U, V;
            cin >> U >> V;

            int l = lca(--U, --V);
            int dist = depth[U] + depth[V] - 2 * depth[l];

            if (dist & 1) cout << "0\n";
            else if (!dist) cout << N << "\n";
            else {
                int mid = lift(depth[U] > depth[V] ? U : V, dist / 2);
                if (depth[U] < depth[mid] || depth[V] > depth[U]) {
                    int ans = nodes[mid] - nodes[lift(V, dist / 2 - 1)];
                    cout << ans << "\n";
                } else if (depth[V] < depth[mid] || depth[U] > depth[V]) {
                    int ans = nodes[mid] - nodes[lift(U, dist / 2 - 1)];
                    cout << ans << "\n";
                } else {
                    int ans = N - nodes[lift(U, dist / 2 - 1)] - nodes[lift(V, dist / 2 - 1)];
                    cout << ans << "\n";
                }
            }
        }
    }
}