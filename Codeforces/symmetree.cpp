#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

vector<int> h, nodes;
vector<vector<int>> tree;

int pow(int a, int n) {
    if (!n) return 1;

    int ans = pow(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

void get_hash(int node = 0, int parent = -1) {
    nodes[node] = 1;
    vector<pair<int, int>> children;

    for (int child: tree[node])
        if (child != parent) {
            get_hash(child, node);
            nodes[node] += nodes[child];
            children.emplace_back(h[child], child);
        }

    sort(children.begin(), children.end());

    h[node] = 1;
    for (auto [ch, child]: children) {
        int p = pow(2, 2 * nodes[child]);
        h[node] = (1LL * h[node] * p) % MOD;
        h[node] = (h[node] + ch) % MOD;
    }

    h[node] = (2LL * h[node]) % MOD;
}

bool symmetric(int node = 0, int parent = -1) {
    vector<pair<int, int>> children;
    for (int child: tree[node])
        if (child != parent)
            children.emplace_back(h[child], child);

    sort(children.begin(), children.end());

    vector<int> odd;
    int cnt = !children.empty();

    for (int i = 1; i < (int) children.size() && (int) odd.size() < 2; i++) {
        if (children[i].first == children[i - 1].first) cnt++;
        else {
            if (cnt & 1)
                odd.push_back(children[i - 1].second);

            cnt = 1;
        }
    }

    if (cnt & 1) odd.push_back(children.back().second);

    if (odd.empty()) return true;
    if ((int) odd.size() >= 2) return false;

    return symmetric(odd[0], node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        tree.assign(n, vector<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        h.resize(n);
        nodes.resize(n);
        get_hash();

        cout << (symmetric() ? "YES" : "NO") << "\n";
    }
}