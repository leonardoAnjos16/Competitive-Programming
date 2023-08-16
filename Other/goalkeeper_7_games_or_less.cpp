#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<pair<int, int>> tree;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    pair<int, int> query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = make_pair(a[l], l);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] = make_pair(v, i);
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    pair<int, int> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return make_pair(INT_MAX, -1);
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        return min(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> A(n + 1);
    map<int, set<int>> pos;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pos[A[i]].insert(i);
    }

    vector<int> nxt(n + 1, INT_MAX);
    for (int i = 1; i <= n; i++) {
        auto it = pos[A[i]].upper_bound(i);
        if (it != pos[A[i]].end())
            nxt[i] = *it;
    }

    SegmentTree tree(n, nxt);
    while (q--) {
        int op; cin >> op;
        if (op == 0) {
            int i, x;
            cin >> i >> x;

            auto it = pos[A[i]].find(i);
            if (it != pos[A[i]].begin()) {
                auto prev = it; prev--;
                auto nnxt = it; nnxt++;
                tree.update(*prev, nnxt != pos[A[i]].end() ? *nnxt : INT_MAX);
            }

            pos[A[i]].erase(it);

            it = pos[A[i] = x].upper_bound(i);
            if (it != pos[A[i]].begin()) {
                auto prev = it; prev--;
                tree.update(*prev, i);
            }

            tree.update(i, it != pos[A[i]].end() ? *it : INT_MAX);
            pos[A[i]].insert(i);
        } else {
            int l, r;
            cin >> l >> r;

            auto [i1, j1] = tree.query(l, r);
            if (i1 > r) cout << "-1\n";
            else {
                auto [ni1, _] = tree.query(i1, i1);
                tree.update(i1, INT_MAX);
                tree.update(j1, INT_MAX);

                auto [i2, j2] = tree.query(l, r);
                if (i2 > r) cout << "-1\n";
                else cout << i1 << " " << j1 << " " << i2 << " " << j2 << "\n";

                tree.update(i1, ni1);
                tree.update(j1, i1);
            }
        }
    }
}