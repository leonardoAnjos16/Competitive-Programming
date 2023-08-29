#include <bits/stdc++.h>

using namespace std;

const int LOG = 20;

struct DSU {
private:
    int n;
    vector<int> ds, sz;

public:
    DSU() {}
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

void update(DSU trees[LOG], int n, int idx, int i, int j) {
    if (trees[idx].find(i) == trees[idx].find(j)) return;

    if (!idx) trees[0].join(i, 2 * n - j - 1);
    else {
        trees[idx].join(i, j);
        update(trees, n, idx - 1, i, j);
        update(trees, n, idx - 1, i + (1 << (idx - 1)), j + (1 << (idx - 1)));
    }
}

bool query(DSU trees[LOG], int idx, int i, int j) {
    if (trees[idx].find(i) == trees[idx].find(j)) return true;
    if (!idx) return false;

    if (!query(trees, idx - 1, i, j)) return false;
    if (!query(trees, idx - 1, i + (1 << (idx - 1)), j + (1 << (idx - 1)))) return false;

    trees[idx].join(i, j);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    DSU trees[LOG];
    for (int i = 0; i < LOG; i++)
        trees[i] = DSU(2 * n);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;

            int sz = (r-- - l-- + 1);
            int rl = 2 * n - r - 1, rr = 2 * n - l - 1;

            for (int i = LOG; i >= 0; i--)
                if (sz & (1 << i)) {
                    update(trees, n, i, l, rl);
                    l += 1 << i;
                    rl += 1 << i;
                }
        } else {
            int a, b, x, y;
            cin >> a >> b >> x >> y;

            if (b-- - a-- != y-- - x--) cout << "Not equal\n";
            else {
                bool equal = true;
                int sz = (b - a + 1);

                for (int i = LOG; i >= 0 && equal; i--)
                    if (sz & (1 << i)) {
                        equal = query(trees, i, a, x);
                        a += 1 << i;
                        x += 1 << i;
                    }

                cout << (equal ? "Equal" : "Unknown") << "\n";
            }
        }
    }
}