#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, INT_MAX);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] = min(tree[node], v);
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INT_MAX;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        return min(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        vector<tuple<int, int, int>> r(n);
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            r[i] = make_tuple(a, b, c);
        }

        sort(r.begin(), r.end());

        SegmentTree tree(n);
        tree.update(get<1>(r[0]), get<2>(r[0]));

        int ans = 1;
        for (int i = 1; i < n; i++) {
            auto [a, b, c] = r[i];
            if (tree.query(1, b) > c) ans++;
            tree.update(b, c);
        }

        cout << ans << "\n";
    }
}