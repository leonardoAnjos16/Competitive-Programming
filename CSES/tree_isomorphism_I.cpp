#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

vector<int> nodes;

int pow(int a, int n) {
    if (!n) return 1;

    int ans = pow(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int get_hash(vector<vector<int>> &tree, int node = 0, int parent = -1) {
    nodes[node] = 1;
    vector<pair<int, int>> children;

    for (int child: tree[node])
        if (child != parent) {
            children.emplace_back(get_hash(tree, child, node), child);
            nodes[node] += nodes[child];
        }

    sort(children.begin(), children.end());

    int ans = 1;
    for (auto [h, child]: children) {
        int p = pow(2, 2 * nodes[child]);
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
        int n; cin >> n;

        vector<vector<int>> tree(n, vector<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        nodes.resize(n);
        int h1 = get_hash(tree);

        tree.assign(n, vector<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        int h2 = get_hash(tree);

        cout << (h1 == h2 ? "YES" : "NO") << "\n";
    }
}