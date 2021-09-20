#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<pair<int, long>> tree;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, int x) {
        update(1, 1, n, i, x);
    }

    void update(int l, int r, int x) {
        update(1, 1, n, l, r, x);
    }

    long query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void merge(int i) {
        int mx = max(tree[2 * i].first, tree[2 * i + 1].first);
        long sum = tree[2 * i].second + tree[2 * i + 1].second;
        tree[i] = make_pair(mx, sum);
    }

    void build(int i, int l, int r) {
        if (l == r) tree[i] = make_pair(a[l], a[l]);
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            merge(i);
        }
    }

    void update(int i, int l, int r, int j, int x) {
        if (l == r) tree[i] = make_pair(x, x);
        else {
            int m = (l + r) / 2;
            if (j <= m) update(2 * i, l, m, j, x);
            else update(2 * i + 1, m + 1, r, j, x);
            merge(i);
        }
    }

    void update(int i, int l, int r, int ul, int ur, int x) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur && tree[i].first < x) return;

        if (l == r) tree[i] = make_pair(tree[i].first % x, tree[i].second % x);
        else {
            int m = (l + r) / 2;
            update(2 * i, l, m, ul, ur, x);
            update(2 * i + 1, m + 1, r, ul, ur, x);
            merge(i);
        }
    }

    long query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return tree[i].second;

        int m = (l + r) / 2;
        return query(2 * i, l, m, ql, qr) + query(2 * i + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree tree(n, a);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;

            long ans = tree.query(l, r);
            cout << ans << "\n";
        } else if (op == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            tree.update(l, r, x);
        } else {
            int k, x;
            cin >> k >> x;
            tree.update(k, x);
        }
    }
}