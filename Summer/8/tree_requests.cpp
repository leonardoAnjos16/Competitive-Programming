#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<char> c;
vector<int> nodes, depth, odd;
vector<vector<int>> tree, cnt;
vector<vector<pair<int, int>>> queries;
vector<bool> ans;

void get_nodes_and_depth(int node = 0) {
    nodes[node] = 1;
    for (int child: tree[node]) {
        depth[child] = depth[node] + 1;
        get_nodes_and_depth(child);
        nodes[node] += nodes[child];
    }
}

void add(int node, int big, int v) {
    cnt[depth[node]][c[node] - 'a'] += v;
    if (cnt[depth[node]][c[node] - 'a'] & 1) odd[depth[node]]++;
    else odd[depth[node]]--;

    for (int child: tree[node])
        if (child != big)
            add(child, big, v);
}

void solve(int node = 0, bool keep = true) {
    int mx = 0, big = -1;
    for (int child: tree[node])
        if (nodes[child] > mx)
            mx = nodes[child], big = child;

    for (int child: tree[node])
        if (child != big)
            solve(child, false);

    if (big != -1) solve(big);

    add(node, big, 1);
    for (auto [h, idx]: queries[node])
        ans[idx] = odd[h] <= 1;

    if (!keep) add(node, -1, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        tree[p - 1].push_back(i);
    }

    c.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    nodes.resize(n);
    depth.assign(n, 0);
    get_nodes_and_depth();

    queries.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int v, h;
        cin >> v >> h;
        queries[v - 1].emplace_back(h - 1, i);
    }

    cnt.assign(n, vector<int>(26, 0));
    odd.assign(n, 0);
    ans.resize(m);

    solve();
    for (int i = 0; i < m; i++)
        cout << (ans[i] ? "Yes" : "No") << "\n";
}