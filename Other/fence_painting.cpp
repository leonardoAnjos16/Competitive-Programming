#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

tuple<int, int, int> operator +(tuple<int, int, int> a, tuple<int, int, int> b) {
    auto [abest, amn, amx] = a;
    auto [bbest, bmn, bmx] = b;

    int best = max({ abest, bbest, bmx - amn });
    return make_tuple(best, min(amn, bmn), max(amx, bmx));
}

struct SegmentTree {
private:
    struct QueryTree {
    private:
        int n;
        vector<int> a;
        vector<tuple<int, int, int>> tree;

    public:
        QueryTree() {}
        QueryTree(int n, vector<int> &a) {
            this->n = n;
            this->a = a;

            tree.resize(4 * n);
            build(1, 1, n);
        }

        tuple<int, int, int> query(int l, int r) {
            assert(l <= n && r <= n);
            return query(1, 1, n, l, r);
        }

    private:
        void build(int node, int l, int r) {
            if (l == r) tree[node] = make_tuple(0, a[l], a[l]);
            else {
                int m = (l + r) / 2;
                build(2 * node, l, m);
                build(2 * node + 1, m + 1, r);
                tree[node] = tree[2 * node] + tree[2 * node + 1];
            }
        }

        tuple<int, int, int> query(int node, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) return tree[node];

            int m = (l + r) / 2;
            if (qr <= m) return query(2 * node, l, m, ql, qr);
            if (ql > m) return query(2 * node + 1, m + 1, r, ql, qr);

            return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
        }
    };

    int n;
    vector<int> a;
    vector<tuple<int, int, int>> tree;
    vector<int> lazy;
    QueryTree btree;

public:
    SegmentTree(int n, vector<int> &a, vector<int> &b) {
        this->n = n;
        this->a = a;

        btree = QueryTree(2 * n, b);
        lazy.assign(4 * n, -1);
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int l, int r, int k) {
        update(1, 1, n, l, r, k);
    }

    tuple<int, int, int> query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = make_tuple(0, a[l], a[l]);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update_lazy(int node, int l, int r, int k) {
        lazy[node] = k;
        tree[node] = btree.query(k, k + r - l);
    }

    void push_down(int node, int l, int r) {
        if (lazy[node] == -1) return;

        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node] + m - l + 1);
        lazy[node] = -1;
    }

    void update(int node, int l, int r, int ul, int ur, int k) {
        if (ul <= l && r <= ur) {
            update_lazy(node, l, r, k);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        if (ur <= m) update(2 * node, l, m, ul, ur, k);
        else if (ul > m) update(2 * node + 1, m + 1, r, ul, ur, k);
        else {
            update(2 * node, l, m, ul, ur, k);
            update(2 * node + 1, m + 1, r, ul, ur, k + m - max(ul, l) + 1);
        }

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    tuple<int, int, int> query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        if (qr <= m) return query(2 * node, l, m, ql, qr);
        if (ql > m) return query(2 * node + 1, m + 1, r, ql, qr);

        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> b(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[n + i] = b[i];
    }

    SegmentTree tree(n, a, b);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, k;
            cin >> l >> r >> k;

            tree.update(l + 1, r + 1, k + 1);
            auto [ans, mn, mx] = tree.query(1, n);
            cout << ans << "\n";
        } else {
            int l, r;
            cin >> l >> r;

            auto [ans, mn, mx] = tree.query(l + 1, r + 1);
            cout << ans << "\n";
        }
    }
}