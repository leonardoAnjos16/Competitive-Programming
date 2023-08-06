#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
private:
    int n;
    vector<pair<int, int>> a;
    vector<pair<int, int>> tree;

public:
    SegmentTree(int n, vector<pair<int, int>> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, pair<int, int> v) {
        update(1, 1, n, i, v);
    }

    pair<int, int> query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    pair<int, int> merge(pair<int, int> left, pair<int, int> right) {
        int mx = max(left.first, right.first);
        int mn = min(left.second, right.second);
        return make_pair(mx, mn);
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int i, pair<int, int> v) {
        if (l == r) tree[node] = v;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    pair<int, int> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return make_pair(INT_MIN, INT_MAX);
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        return merge(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> guards(N + 1);
    for (int i = 1; i <= N; i++) {
        int L, R;
        cin >> L >> R;
        guards[i] = make_pair(L, R);
    }

    SegmentTree tree(N, guards);
    while (Q--) {
        char op; cin >> op;
        if (op == 'C') {
            int i, l, r;
            cin >> i >> l >> r;
            tree.update(i, make_pair(l, r));
        } else {
            int a, b;
            cin >> a >> b;

            auto [l, r] = tree.query(a, b);
            if (l > r) cout << "0\n";
            else cout << (r - l + 1) << "\n";
        }
    }
}