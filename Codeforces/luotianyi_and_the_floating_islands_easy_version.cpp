#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

int sum, nodes;
vector<vector<int>> tree;
vector<int> sz, depth;

void init(int node = 0, int parent = -1) {
    sz[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            depth[child] = depth[node] + 1;
            init(child, node);
            sz[node] += sz[child];
        }
}

int count(int root, int node, int parent) {
    int aux = (depth[node] - 2 * depth[root] + 1) % MOD;
    aux = (1LL * aux * nodes) % MOD;
    int ans = (sum + aux) % MOD;

    for (int child: tree[node])
        if (child != parent)
            ans = (ans + count(root, child, node)) % MOD;

    return ans;
}

void add(int node, int parent) {
    nodes++;
    sum = (sum + depth[node]) % MOD;

    for (int child: tree[node])
        if (child != parent)
            add(child, node);
}

int solve(int node = 0, int parent = -1, bool keep = false) {
    int big = -1, mx = INT_MIN;
    for (int child: tree[node])
        if (child != parent && sz[child] > mx) {
            big = child;
            mx = sz[child];
        }

    int ans = 0;
    for (int child: tree[node])
        if (child != parent && child != big)
            ans = (ans + solve(child, node)) % MOD;

    if (big != -1) ans = (ans + solve(big, node, true)) % MOD;

    int aux = (1 - depth[node] + MOD) % MOD;
    aux = (1LL * aux * nodes) % MOD;
    aux = (aux + sum) % MOD;
    ans = (ans + aux) % MOD;

    nodes++;
    sum = (sum + depth[node]) % MOD;

    for (int child: tree[node])
        if (child != parent && child != big) {
            ans = (ans + count(node, child, node)) % MOD;
            add(child, node);
        }

    if (!keep) sum = nodes = 0;

    return ans;
}

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int a, int m) {
    return exp(a, m - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    if (k & 1) cout << "1\n";
    else if (k == 2) {
        sz.resize(n);
        depth.assign(n, 0);
        init();

        sum = nodes = 0;
        int ans = solve();

        int comb = (n * (n - 1LL) / 2LL) % MOD;
        ans = (1LL * ans * mod_mult_inv(comb, MOD)) % MOD;

        cout << ans << "\n";
    }
}