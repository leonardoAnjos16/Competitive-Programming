#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

int n;
vector<vector<int>> tree;
vector<vector<pair<int, int>>> queries;
vector<int> depth, nodes, ans;
vector<int> cnt;

void get_depth_and_nodes(int node) {
    nodes[node] = 1;
    for (int child: tree[node]) {
        depth[child] = depth[node] + 1;
        get_depth_and_nodes(child);
        nodes[node] += nodes[child];
    }
}

void add(int node, int big, int v) {
    cnt[depth[node]] += v;
    for (int child: tree[node])
        if (child != big)
            add(child, big, v);
}

void solve(int node, bool keep = false) {
    int mx = 0, big = -1;
    for (int child: tree[node])
        if (nodes[child] > mx) {
            big = child;
            mx = nodes[child];
        }

    for (int child: tree[node])
        if (child != big)
            solve(child);

    if (big != -1) solve(big, true);

    add(node, big, 1);
    for (auto [p, idx]: queries[node])
        ans[idx] = cnt[depth[node] + p] - 1;

    if (!keep) add(node, -1, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<int> roots, parent(n);
    tree.assign(n, vector<int>());

    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        parent[i] = r - 1;

        if (!r) roots.push_back(i);
        else tree[r - 1].push_back(i);
    }

    vector<vector<int>> up(LOG, vector<int>(n));
    for (int i = 0; i < n; i++)
        up[0][i] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < n; j++) {
            if (up[i - 1][j] == -1) up[i][j] = -1;
            else up[i][j] = up[i - 1][up[i - 1][j]];
        }

    depth.assign(n, 0);
    nodes.resize(n);

    for (int root: roots)
        get_depth_and_nodes(root);

    int m; cin >> m;

    queries.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int v, p;
        cin >> v >> p;

        if (depth[--v] >= p) {
            for (int j = 0; j < LOG; j++)
                if (p & (1 << j))
                    v = up[j][v];

            assert(v != -1);
            queries[v].emplace_back(p, i);
        }
    }

    cnt.assign(n, 0);
    ans.assign(m, 0);

    for (int root: roots)
        solve(root);

    for (int i = 0; i < m; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}