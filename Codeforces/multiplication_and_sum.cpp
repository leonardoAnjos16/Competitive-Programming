#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    const int MOD = 1e9 + 7;

    int n;
    vector<int> tree, lazy;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n);
        lazy.assign(4 * n, 1);
        build(1, 1, n);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    int merge(int left, int right) {
        return (left + right) % MOD;
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = 1;
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update_lazy(int node, int l, int r, int v) {
        tree[node] = (1LL * tree[node] * v) % MOD;
        lazy[node] = (1LL * lazy[node] * v) % MOD;
    }

    void push_down(int node, int l, int r) {
        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = 1;
    }

    void update(int node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_lazy(node, l, r, v);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur, v);
        update(2 * node + 1, m + 1, r, ul, ur, v);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        int left = query(2 * node, l, m, ql, qr);
        int right = query(2 * node + 1, m + 1, r, ql, qr);
        return merge(left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    SegmentTree tree(n);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            tree.update(l + 1, r, v);
        } else {
            int l, r;
            cin >> l >> r;

            int ans = tree.query(l + 1, r);
            cout << ans << "\n";
        }
    }
}