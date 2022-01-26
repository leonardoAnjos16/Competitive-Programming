#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> tree;

public:
    SegmentTree(vector<int> &a, int n) {
        this->n = n;
        this->a = a;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    int merge(int l, int r, int left, int right) {
        if (!((r - l + 1) & 1))
            return left + right;

        return left - right;
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(l, m, tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) a[i] = tree[node] = v;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = merge(l, m, tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        if (qr <= m) return query(2 * node, l, m, ql, qr);
        if (ql > m) return query(2 * node + 1, m + 1, r, ql, qr);

        int left = query(2 * node, l, m, ql, qr);
        int right = query(2 * node + 1, m + 1, r, ql, qr);
        return merge(max(l, ql), m, left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int m; cin >> m;
    SegmentTree tree(a, n);

    while (m--) {
        int op; cin >> op;
        if (op == 0) {
            int i, j;
            cin >> i >> j;
            tree.update(i, j);
        } else {
            int l, r;
            cin >> l >> r;

            int ans = tree.query(l, r);
            cout << ans << "\n";
        }
    }
}