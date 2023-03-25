#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

vector<vector<pair<int, int>>> tree;
vector<int> depth, parent, dists, sz, cparent;
vector<vector<tuple<int, int, int>>> updates;
vector<vector<int>> up;
vector<bool> rem;

void init(int node = 0, int p = -1) {
    for (auto [child, w]: tree[node])
        if (child != p) {
            depth[child] = depth[node] + 1;
            dists[child] = dists[node] + w;
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
    return dists[u] + dists[v] - 2 * dists[lca(u, v)];
}

void get_size(int node = 0, int p = -1) {
    sz[node] = 1;
    for (auto [child, w]: tree[node])
        if (child != p && !rem[child]) {
            get_size(child, node);
            sz[node] += sz[child];
        }
}

int centroid(int size, int node, int p = -1) {
    for (auto [child, w]: tree[node])
        if (child != p && !rem[child] && 2 * sz[child] > size)
            return centroid(size, child, node);

    return node;
}

int decompose(int node = 0) {
    get_size(node);
    int c = centroid(sz[node], node);

    rem[c] = true;
    for (auto [child, w]: tree[c])
        if (!rem[child])
            cparent[decompose(child)] = c;

    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    tree.assign(N, vector<pair<int, int>>());
    for (int i = 1; i < N; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        tree[a - 1].emplace_back(b - 1, w);
        tree[b - 1].emplace_back(a - 1, w);
    }

    depth.assign(N, 0);
    parent.assign(N, 0);
    dists.assign(N, 0);
    init();

    up.assign(LOG, vector<int>(N));
    for (int i = 0; i < N; i++)
        up[0][i] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < N; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];

    sz.resize(N);
    cparent.assign(N, -1);
    rem.assign(N, false);
    decompose();

    int t = 1;
    updates.assign(N, vector<tuple<int, int, int>>());

    int Q; cin >> Q;
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int v, d, c;
            cin >> v >> d >> c;
            v--;

            int node = v;
            while (node != -1) {
                int nd = d - dist(node, v);
                while (!updates[node].empty() && get<0>(updates[node].back()) <= nd)
                    updates[node].pop_back();

                updates[node].emplace_back(nd, c, t);
                node = cparent[node];
            }

            t++;
        } else {
            int v;
            cin >> v;
            v--;

            int node = v, ans = 0, lt = 0;
            while (node != -1) {
                int d = dist(node, v);
                auto it = lower_bound(updates[node].rbegin(), updates[node].rend(), make_tuple(d, -1, -1));

                if (it != updates[node].rend() && get<2>(*it) > lt) {
                    lt = get<2>(*it);
                    ans = get<1>(*it);
                }

                node = cparent[node];
            }

            cout << ans << "\n";
        }
    }
}