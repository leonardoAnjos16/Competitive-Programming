#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct DSU {
public:
    int n, components;
    vector<int> ds, sz;

public:
    DSU(int n) {
        this->n = components = n;

        ds.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            ds[i] = i;
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j, int w, llong &sum) {
        i = find(i); j = find(j);
        if (sz[i] < sz[j]) swap(i, j);

        if (i != j) {
            sum += 1LL * w * sz[i] * sz[j];
            sz[i] += sz[j];
            components++;
            ds[j] = i;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(6) << fixed;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges[i] = make_tuple(min(a[x - 1], a[y - 1]), x - 1, y - 1);
    }

    sort(edges.rbegin(), edges.rend());

    DSU tree(n);
    llong sum = 0LL;

    for (int i = 0; i < m && tree.components > 1; i++) {
        auto [w, u, v] = edges[i];
        tree.join(u, v, w, sum);
    }

    llong pairs = n * (n - 1LL) / 2LL;
    long double ans = 1.0L * sum / pairs;
    cout << ans << "\n";
}