#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

int n;
vector<vector<int>> tree;
vector<int> sz;

void get_size(int node = 0, int parent = -1) {
    sz[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            get_size(child, node);
            sz[node] += sz[child];
        }
}

pair<int, int> centroids(int node = 0, int parent = -1) {
    for (int child: tree[node])
        if (child != parent && 2 * sz[child] > n)
            return centroids(child, node);

    for (int child: tree[node])
        if (child != parent && 2 * sz[child] == n)
            return make_pair(node, child);

    return make_pair(node, node);
}

int pow(int a, int n) {
    if (!n) return 1;

    int ans = pow(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int get_hash(int node, int parent = -1) {
    sz[node] = 1;
    vector<pair<int, int>> children;

    for (int child: tree[node])
        if (child != parent) {
            children.emplace_back(get_hash(child, node), child);
            sz[node] += sz[child];
        }

    sort(children.begin(), children.end());

    int ans = 1;
    for (auto [h, child]: children) {
        int p = pow(2, 2 * sz[child]);
        ans = (1LL * ans * p) % MOD;
        ans = (ans + h) % MOD;
    }

    ans = (2LL * ans) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;

        tree.assign(n, vector<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        sz.resize(n);
        get_size();

        auto [c1, c2] = centroids();
        int h1 = get_hash(c1), h2 = get_hash(c2);

        tree.assign(n, vector<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        get_size();
        int c3 = centroids().first;
        int h3 = get_hash(c3);

        cout << (h1 == h3 || h2 == h3 ? "YES" : "NO") << "\n";
    }
}