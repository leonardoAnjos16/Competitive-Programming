#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;
const int INF = 1e9 + 5;

vector<vector<int>> tree;
vector<int> depth, parent, sz, cparent, best;
vector<vector<int>> up;
vector<bool> rem;

void init(int node = 0, int p = -1) {
    for (int child: tree[node])
        if (child != p) {
            depth[child] = depth[node] + 1;
            parent[child] = node;
            init(child, node);
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

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void get_size(int node, int p = -1) {
    sz[node] = 1;
    for (int child: tree[node])
        if (child != p && !rem[child]) {
            get_size(child, node);
            sz[node] += sz[child];
        }
}

int centroid(int size, int node, int p = -1) {
    for (int child: tree[node])
        if (child != p && !rem[child] && 2 * sz[child] > size)
            return centroid(size, child, node);

    return node;
}

int decompose(int node = 0) {
    get_size(node);
    int c = centroid(sz[node], node);

    rem[c] = true;
    for (int child: tree[c])
        if (!rem[child])
            cparent[decompose(child)] = c;

    return c;
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
    init();

    up.assign(LOG, vector<int>(n));
    for (int i = 0; i < n; i++)
        up[0][i] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < n; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];

    cparent.assign(n, -1);
    rem.assign(n, false);
    sz.resize(n);
    decompose();

    int node = 0;
    best.assign(n, INF);

    while (node != -1) {
        best[node] = dist(node, 0);
        node = cparent[node];
    }

    while (m--) {
        int t, v;
        cin >> t >> v;
        v--;

        if (t == 1) {
            int node = v;
            while (node != -1) {
                if (dist(node, v) < best[node])
                    best[node] = dist(node, v);

                node = cparent[node];
            }
        } else {
            int ans = INF, node = v;
            while (node != -1) {
                if (best[node] + dist(node, v) < ans)
                    ans = best[node] + dist(node, v);

                node = cparent[node];
            }

            cout << ans << "\n";
        }
    }
}