#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong sum = 0LL;
vector<vector<pair<int, int>>> tree;
vector<int> C, sz, total, cnt;
vector<llong> ans;

void init(int node = 0, int parent = -1) {
    sz[node] = 1;
    total[C[node]]++;

    for (auto [child, _]: tree[node])
        if (child != parent) {
            init(child, node);
            sz[node] += sz[child];
        }
}

void add(int node, int parent, int big, int v) {
    int color = C[node];
    sum -= 1LL * cnt[color] * (total[color] - cnt[color]);

    cnt[color] += v;
    sum += 1LL * cnt[color] * (total[color] - cnt[color]);

    for (auto [child, _]: tree[node])
        if (child != parent && child != big)
            add(child, node, big, v);
}

void solve(int node = 0, int parent = -1, int edge = 0, bool keep = true) {
    int big = -1, bedge = -1, mx = INT_MIN;
    for (auto [child, id]: tree[node])
        if (child != parent && sz[child] > mx) {
            bedge = id;
            big = child;
            mx = sz[child];
        }

    for (auto [child, id]: tree[node])
        if (child != parent && child != big)
            solve(child, node, id, false);

    if (big != -1) solve(big, node, bedge);

    add(node, parent, big, 1);
    ans[edge] = sum;

    if (!keep) add(node, parent, -1, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    C.resize(N);
    for (int i = 0; i < N; i++)
        cin >> C[i];

    tree.assign(N, vector<pair<int, int>>());
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].emplace_back(v - 1, i);
        tree[v - 1].emplace_back(u - 1, i);
    }

    sz.resize(N);
    total.assign(N + 1, 0);
    init();

    cnt.assign(N + 1, 0);
    ans.assign(N, 0LL);
    solve();

    for (int i = 1; i < N; i++) {
        if (i > 1) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}