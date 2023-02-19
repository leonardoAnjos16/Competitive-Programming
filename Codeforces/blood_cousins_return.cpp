#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<string> name;
vector<vector<int>> tree;
vector<vector<pair<int, int>>> queries, subtree;
vector<int> depth, nodes, id, ans;
vector<map<string, int>> cnt;

void get_depth_and_nodes(int node) {
    nodes[node] = 1;
    for (int child: tree[node]) {
        depth[child] = depth[node] + 1;
        get_depth_and_nodes(child);
        nodes[node] += nodes[child];
    }
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

    if (big != -1) {
        solve(big, true);
        id[node] = id[big];
    }

    subtree[id[node]].emplace_back(node, depth[node]);
    cnt[depth[node]][name[node]]++;

    for (int child: tree[node])
        if (child != big)
            for (auto [v, d]: subtree[id[child]]) {
                cnt[d][name[v]]++;
                subtree[id[node]].emplace_back(v, d);
            }

    for (auto [k, idx]: queries[node])
        ans[idx] = depth[node] + k < n ? cnt[depth[node] + k].size() : 0;

    if (!keep)
        for (auto [v, d]: subtree[id[node]])
            if (--cnt[d][name[v]] == 0)
                cnt[d].erase(name[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    name.resize(n);
    tree.assign(n, vector<int>());

    vector<int> roots;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> name[i] >> r;

        if (!r) roots.push_back(i);
        else tree[r - 1].push_back(i);
    }

    assert(!roots.empty());

    int m; cin >> m;

    queries.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int v, k;
        cin >> v >> k;
        queries[v - 1].emplace_back(k, i);
    }

    depth.assign(n, 0);
    nodes.resize(n);

    id.resize(n);
    for (int i = 0; i < n; i++)
        id[i] = i;

    subtree.assign(n, vector<pair<int, int>>());
    cnt.assign(n, map<string, int>());
    ans.resize(m);

    for (int root: roots) {
        get_depth_and_nodes(root);
        solve(root);
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}