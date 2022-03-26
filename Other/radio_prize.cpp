#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> t, tsum, nodes;
vector<vector<pair<int, int>>> tree;
vector<long> ans;

void get_initial(int node = 0, int parent = -1, long dist = 0LL) {
    nodes[node] = 1;
    tsum[node] = t[node];
    ans[0] += (t[0] + t[node]) * dist;

    for (auto [child, w]: tree[node])
        if (child != parent) {
            get_initial(child, node, dist + w);
            nodes[node] += nodes[child];
            tsum[node] += tsum[child];
        }
}

long get_dists(int node = 0, int parent = -1, long dist = 0LL) {
    long ans = dist;
    for (auto [child, w]: tree[node])
        if (child != parent)
            ans += get_dists(child, node, dist + w);

    return ans;
}

void solve(int node, int parent, int weight, long dists) {
    int cnt_diff = nodes[0] - nodes[node] - nodes[node] + 1;
    long new_dists = dists + (cnt_diff - 1) * weight;

    if (parent != -1) {
        ans[node] = ans[parent] - t[parent] * (dists - weight) + t[node] * (new_dists - weight);
        ans[node] += 1LL * (tsum[0] - tsum[node] - t[parent] - tsum[node] + t[node]) * weight;
    }

    for (auto [child, w]: tree[node])
        if (child != parent)
            solve(child, node, w, new_dists);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    t.resize(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    tree.assign(n, vector<pair<int, int>>());
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        tree[u - 1].emplace_back(v - 1, w);
        tree[v - 1].emplace_back(u - 1, w);
    }

    tsum.resize(n);
    nodes.resize(n);
    ans.assign(n, 0);
    get_initial();

    solve(0, -1, 0, get_dists());
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";
}