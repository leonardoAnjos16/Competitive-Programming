#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int M;
vector<vector<pair<int, int>>> tree;
vector<int> nodes;
vector<bool> rem;

void extended_euclidean(llong a, llong b, llong &x, llong &y) {
    if (!b) {
        x = 1LL;
        y = 0LL;
    } else {
        extended_euclidean(b, a % b, x, y);
        llong aux = x; x = y;
        y = aux - a / b * y;
    }
}

llong mod_mult_inv(llong a, llong m) {
    llong x, y;
    extended_euclidean(a, m, x, y);
    return (x % m + m) % m;
}

void get_nodes(int node, int parent = -1) {
    nodes[node] = 1;
    for (auto [child, d]: tree[node])
        if (child != parent && !rem[child]) {
            get_nodes(child, node);
            nodes[node] += nodes[child];
        }
}

int centroid(int size, int node, int parent = -1) {
    for (auto [child, d]: tree[node])
        if (child != parent && !rem[child] && 2 * nodes[child] > size)
            return centroid(size, child, node);

    return node;
}

void count_bottom(map<int, int> &cnt, int node, int parent, int bottom, int pow) {
    cnt[bottom]++;
    for (auto [child, d]: tree[node])
        if (child != parent && !rem[child])
            count_bottom(cnt, child, node, (bottom + ((1LL * d * pow) % M)) % M, (10LL * pow) % M);
}

llong count(map<int, int> &all, map<int, int> &curr, int node, int parent, int top, int bottom, int pow) {
    int aux = ((-top % M) + M) % M;
    aux = (1LL * aux * mod_mult_inv(pow, M)) % M;

    llong ans = 0LL;
    ans += all[aux] - curr[aux];
    assert(all[aux] >= curr[aux]);

    for (auto [child, d]: tree[node])
        if (child != parent && !rem[child])
            ans += count(all, curr, child, node, (10LL * top + d) % M, (bottom + ((1LL * d * pow) % M)) % M, (10LL * pow) % M);

    return ans;
}

llong solve(int node = 0) {
    get_nodes(node);
    int c = centroid(nodes[node], node);

    map<int, int> all;
    vector<map<int, int>> subtrees;

    for (auto [child, d]: tree[c])
        if (!rem[child]) {
            map<int, int> curr;
            count_bottom(curr, child, c, d % M, 10 % M);

            subtrees.push_back(curr);
            for (auto [num, q]: curr) all[num] += q;
        }

    int idx = 0;
    llong ans = all[0]++;

    for (auto [child, d]: tree[c])
        if (!rem[child])
            ans += count(all, subtrees[idx++], child, c, d % M, d % M, 10 % M);

    all.clear();
    subtrees.clear();

    rem[c] = true;
    for (auto [child, d]: tree[c])
        if (!rem[child])
            ans += solve(child);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> M;

    tree.assign(n, vector<pair<int, int>>());
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    nodes.resize(n);
    rem.assign(n, false);

    llong ans = solve();
    cout << ans << "\n";
}