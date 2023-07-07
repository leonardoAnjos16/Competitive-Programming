#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

struct DSU {
private:
    int n;
    vector<int> ds, sz;

public:
    DSU(int n) {
        this->n = n;
        sz.assign(n, 1);

        ds.resize(n);
        iota(ds.begin(), ds.end(), 0);
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j) {
        i = find(i); j = find(j);
        if (sz[i] > sz[j]) swap(i, j);
        if (i != j) sz[j] += sz[i];
        ds[i] = j;
    }
};

int n, A, B;
vector<int> l, r, t;

int moves() {
    queue<tuple<int, int, int>> q;
    q.emplace(A, B, 0);

    DSU tree(n);
    tree.join(A, B);

    while (!q.empty()) {
        auto [u, v, d] = q.front(); q.pop();
        if (t[u] != t[v]) return d;

        if (tree.find(l[u]) != tree.find(l[v])) {
            tree.join(l[u], l[v]);
            q.emplace(l[u], l[v], d + 1);
        }

        if (tree.find(r[u]) != tree.find(r[v])) {
            tree.join(r[u], r[v]);
            q.emplace(r[u], r[v], d + 1);
        }
    }

    return INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> A >> B;

    l.resize(n);
    r.resize(n);
    t.resize(n);

    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i] >> t[i];

    int ans = moves();
    if (ans >= INF) cout << "indistinguishable\n";
    else cout << ans << "\n";
}