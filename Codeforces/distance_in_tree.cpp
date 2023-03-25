#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n, k;
vector<vector<int>> tree;
vector<int> sz, depth, cnt;

void init(int node = 0, int parent = -1) {
    sz[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            depth[child] = depth[node] + 1;
            init(child, node);
            sz[node] += sz[child];
        }
}

llong count(int root, int node, int parent) {
    // d + depth[node] - 2 * depth[r] == k -> d == k - depth[node] + 2 * depth[r]
    int d = k - depth[node] + 2 * depth[root];
    llong ans = d >= 0 && d < n ? cnt[d] : 0LL;

    for (int child: tree[node])
        if (child != parent)
            ans += count(root, child, node);

    return ans;
}

void add(int node, int parent, int v) {
    cnt[depth[node]] += v;
    for (int child: tree[node])
        if (child != parent)
            add(child, node, v);
}

llong solve(int node = 0, int parent = -1, bool keep = true) {
    int mx = INT_MIN, big = -1;
    for (int child: tree[node])
        if (child != parent && sz[child] > mx) {
            big = child;
            mx = sz[child];
        }

    llong ans = 0LL;
    for (int child: tree[node])
        if (child != parent && child != big)
            ans += solve(child, node, false);

    if (big != -1) ans += solve(big, node);

    if (depth[node] + k < n)
        ans += cnt[depth[node] + k];

    cnt[depth[node]]++;
    for (int child: tree[node])
        if (child != parent && child != big) {
            ans += count(node, child, node);
            add(child, node, 1);
        }

    if (!keep) add(node, parent, -1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    sz.resize(n);
    depth.assign(n, 0);
    init();

    cnt.assign(n, 0);

    llong ans = solve();
    cout << ans << "\n";
}