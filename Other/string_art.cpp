#include <bits/stdc++.h>

using namespace std;

struct DSU {
private:
    int n;
    vector<int> ds, sz;

public:
    DSU(int n) {
        this->n = n;
        ds.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++)
            ds[i] = i, sz[i] = 1;
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j) {
        i = find(i); j = find(j);
        if (sz[i] < sz[j]) swap(i, j);
        if (i != j) sz[i] += sz[j];
        ds[j] = i;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    DSU tree(n);
    vector<pair<int, int>> ans;

    vector<int> color(m + 1);
    for (int i = 0; i < n; i++)
        color[i] = i + 1;

    int nodes = n;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (tree.find(u - 1) == tree.find(v - 1)) {
            ans.emplace_back(u, ++nodes);
            color[nodes - 1] = color[v - 1];
        } else {
            ans.emplace_back(u, v);
            tree.join(u - 1, v - 1);
        }
    }

    cout << nodes << "\n";
    for (int i = 0; i <= m; i++) {
        if (i) cout << " ";
        cout << color[i];
    }

    cout << "\n";

    for (auto [u, v]: ans)
        cout << u << " " << v << "\n";
}