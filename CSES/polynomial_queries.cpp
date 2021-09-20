#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<long> tree;
    vector<pair<int, long>> lazy;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        lazy.assign(4 * n, make_pair(0, 0LL));

        build(1, 1, n);
    }

    void update(int l, int r) {
        update(1, 1, n, l, r, -l + 1LL);
    }

    long query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    long sum(long v) {
        return v * (v + 1LL) / 2LL;
    }

    long sum(int l, int r, long v) {
        return sum(v + r - l) - sum(v - 1);
    }

    void update_lazy(int i, int l, int r, int cnt, long v) {
        tree[i] += cnt * (sum(r) - sum(l - 1)) + (r - l + 1) * v;
        if (l < r) {
            lazy[i].first += cnt;
            lazy[i].second += v;
        }
    }

    void build(int i, int l, int r) {
        if (l == r) tree[i] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void update(int i, int l, int r, int ul, int ur, long v) {
        if (r < ul || l > ur) return;

        if (ul <= l && r <= ur) update_lazy(i, l, r, 1, v);
        else {
            int m = (l + r) / 2;
            if (lazy[i].first) {
                update_lazy(2 * i, l, m, lazy[i].first, lazy[i].second);
                update_lazy(2 * i + 1, m + 1, r, lazy[i].first, lazy[i].second);
                lazy[i].first = lazy[i].second = 0;
            }

            update(2 * i, l, m, ul, ur, v);
            update(2 * i + 1, m + 1, r, ul, ur, v);
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    long query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return tree[i];

        int m = (l + r) / 2;
        if (lazy[i].first) {
            update_lazy(2 * i, l, m, lazy[i].first, lazy[i].second);
            update_lazy(2 * i + 1, m + 1, r, lazy[i].first, lazy[i].second);
            lazy[i].first = lazy[i].second = 0;
        }

        long left = query(2 * i, l, m, ql, qr);
        long right = query(2 * i + 1, m + 1, r, ql, qr);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> t[i];

    SegmentTree tree(n, t);
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 1) tree.update(a, b);
        else {
            long ans = tree.query(a, b);
            cout << ans << "\n";
        }
    }
}