#include <bits/stdc++.h>

using namespace std;

#define llong long long int

pair<llong, int> operator +(pair<llong, int> a, pair<llong, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

struct SegmentTree {
private:
    int n;
    vector<pair<int, int>> a;
    vector<pair<llong, int>> tree;
    vector<llong> lazy;

public:
    SegmentTree(int n, vector<pair<int, int>> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        lazy.assign(4 * n, 0LL);

        build(1, 1, n);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    llong query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update_lazy(int node, llong v) {
        tree[node].first += tree[node].second * v;
        lazy[node] += v;
    }

    void push_down(int node) {
        update_lazy(2 * node, lazy[node]);
        update_lazy(2 * node + 1, lazy[node]);
        lazy[node] = 0LL;
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node].second += v;
        else {
            push_down(node);

            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_lazy(node, v);
            return;
        }

        push_down(node);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur, v);
        update(2 * node + 1, m + 1, r, ul, ur, v);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    llong query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return tree[node].first;

        push_down(node);

        int m = (l + r) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;

    for (int i = 1; i <= n; i++)
        cin >> a[i].second;

    SegmentTree tree(n, a);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            tree.update(x, -1);
        } else if (op == 2) {
            int x; cin >> x;
            tree.update(x, 1);
        } else if (op == 3) {
            int l, r, x;
            cin >> l >> r >> x;
            tree.update(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;

            llong ans = tree.query(l, r);
            cout << ans << "\n";
        }
    }
}