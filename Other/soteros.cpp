#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct DSU {
public:
    int n, components;
    vector<int> ds, sz;

public:
    DSU() {}
    DSU(int n) {
        this->n = components = n;
        sz.assign(n, 1);

        ds.resize(n);
        for (int i = 0; i < n; i++)
            ds[i] = i;
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j) {
        i = find(i); j = find(j);
        if (sz[i] > sz[j]) swap(i, j);
        if (i != j) sz[j] += sz[i], components--;
        ds[i] = j;
    }
};

vector<vector<int>> tree;
vector<pair<int, int>> street;
vector<int> sz, ans;
DSU components;

void get_size(int node = 0) {
    sz[node] = 1;
    for (int child: tree[node]) {
        get_size(child);
        sz[node] += sz[child];
    }
}

void add(int node, int big) {
    if (street[node].first != -1)
        components.join(street[node].first, street[node].second);

    for (int child: tree[node])
        if (child != big)
            add(child, big);
}

void rem(int node) {
    if (street[node].first != -1) {
        auto [u, v] = street[node];
        components.ds[u] = u;
        components.ds[v] = v;
        components.sz[u] = components.sz[v] = 1;
    }

    for (int child: tree[node])
        rem(child);
}

void solve(int node = 0, bool keep = true) {
    int mx = INT_MIN, big = -1;
    for (int child: tree[node])
        if (sz[child] > mx) {
            big = child;
            mx = sz[child];
        }

    for (int child: tree[node])
        if (child != big)
            solve(child, false);

    if (big != -1) solve(big);

    add(node, big);
    ans[node] = components.components;

    if (!keep) {
        rem(node);
        components.components = components.n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    cin >> n >> K;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        tree[p - 1].push_back(i);
    }

    street.resize(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        street[i] = make_pair(u - 1, v - 1);
    }

    sz.resize(n);
    get_size();

    ans.resize(n);
    components = DSU(K);

    solve();
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";
}