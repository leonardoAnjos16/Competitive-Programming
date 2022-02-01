#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<long> tree, lazy;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0LL);
        lazy.assign(4 * n, 0LL);
    }

    void update(int l, int r, long v) {
        update(1, 1, n, l, r, v);
    }

    long query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update_lazy(int node, int l, int r, long v) {
        tree[node] += v * (r - l + 1);
        lazy[node] += v;
    }

    void push_down(int node, int l, int r) {
        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = 0LL;
    }

    void update(int node, int l, int r, int ul, int ur, long v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_lazy(node, l, r, v);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur, v);
        update(2 * node + 1, m + 1, r, ul, ur, v);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return tree[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        long left = query(2 * node, l, m, ql, qr);
        long right = query(2 * node + 1, m + 1, r, ql, qr);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, C;
        cin >> N >> C;

        SegmentTree tree(N);
        while (C--) {
            int op; cin >> op;
            if (!op) {
                int p, q; long v;
                cin >> p >> q >> v;
                tree.update(p, q, v);
            } else {
                int p, q;
                cin >> p >> q;

                long ans = tree.query(p, q);
                cout << ans << "\n";
            }
        }
    }
}