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

    int n, m, q;
    cin >> n >> m >> q;

    PersistentDSU tree(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        tree.join(a - 1, b - 1, i + 1);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        int l = 0, r = m, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (tree.find(a - 1, mid) != tree.find(b - 1, mid)) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        cout << ans << "\n";
    }
}