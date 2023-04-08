#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> tree;
vector<llong> importance;
vector<int> a, p, sz;

void init(int node = 0, int parent = -1) {
    sz[node] = 1;
    importance[node] = a[node];

    for (int child: tree[node])
        if (child != parent) {
            p[child] = node;
            init(child, node);
            sz[node] += sz[child];
            importance[node] += importance[child];
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    importance.resize(n);
    p.assign(n, -1);
    sz.resize(n);
    init();

    vector<set<pair<int, int>>> ntree(n, set<pair<int, int>>());
    for (int i = 0; i < n; i++)
        for (int v: tree[i])
            if (v != p[i])
                ntree[i].emplace(-sz[v], v);

    while (m--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) cout << importance[x - 1] << "\n";
        else if (!ntree[x - 1].empty()) {
            int fa = p[x - 1];
            auto [ns, c] = *ntree[x - 1].begin();
            ntree[x - 1].erase(ntree[x - 1].begin());
            ntree[fa].erase(make_pair(-sz[x - 1], x - 1));

            p[x - 1] = c;
            p[c] = fa;

            sz[x - 1] -= sz[c];
            sz[c] += sz[x - 1];

            importance[x - 1] -= importance[c];
            importance[c] += importance[x - 1];

            ntree[fa].emplace(-sz[c], c);
            ntree[c].emplace(-sz[x - 1], x - 1);
        }
    }
}