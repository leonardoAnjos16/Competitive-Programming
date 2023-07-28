#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct PersistentDSU {
private:
    int n;
    vector<int> ds, sz, tm;

public:
    PersistentDSU(int n) {
        this->n = n;
        sz.assign(n, 1);
        tm.assign(n, 0);

        ds.resize(n);
        iota(ds.begin(), ds.end(), 0);
    }

    int find(int i, int t = INT_MAX) {
        if (ds[i] == i || tm[i] > t) return i;
        return find(ds[i], t);
    }

    void join(int i, int j, int t) {
        i = find(i); j = find(j);
        if (i == j) return;

        if (sz[i] > sz[j]) swap(i, j);
        sz[j] += sz[i];
        ds[i] = j;
        tm[i] = t;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        vector<tuple<int, int, int>> edges(m);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges[i] = make_tuple(max(h[u - 1], h[v - 1]), u - 1, v - 1);
        }

        sort(edges.begin(), edges.end());

        int t = 1;
        PersistentDSU tree(n);

        for (auto [_, u, v]: edges)
            tree.join(u, v, t++);

        int q; cin >> q;
        while (q--) {
            int a, b, e;
            cin >> a >> b >> e;

            t = upper_bound(edges.begin(), edges.end(), make_tuple(h[a - 1] + e, n, n)) - edges.begin();
            cout << (tree.find(a - 1, t) == tree.find(b - 1, t) ? "YES" : "NO") << "\n";
        }
    }
}