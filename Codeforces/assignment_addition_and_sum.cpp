#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<long> tree;
    vector<long> ass, add;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0LL);
        ass.assign(4 * n, -1LL);
        add.assign(4 * n, 0LL);
    }

    void assign(int l, int r, int v) {
        assign(1, 1, n, l, r, v);
    }

    void addition(int l, int r, int v) {
        addition(1, 1, n, l, r, v);
    }

    long query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update_ass(int node, int l, int r, int v) {
        tree[node] = v * (r - l + 1LL);
        add[node] = 0LL;
        ass[node] = v;
    }

    void update_add(int node, int l, int r, long v) {
        tree[node] += v * (r - l + 1);
        add[node] += v;
    }

    void push_down(int node, int l, int r) {
        int m = (l + r) / 2;
        if (ass[node] != -1LL) {
            update_ass(2 * node, l, m, ass[node]);
            update_ass(2 * node + 1, m + 1, r, ass[node]);
        }

        update_add(2 * node, l, m, add[node]);
        update_add(2 * node + 1, m + 1, r, add[node]);

        ass[node] = -1LL;
        add[node] = 0LL;
    }

    void assign(int node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_ass(node, l, r, v);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        assign(2 * node, l, m, ul, ur, v);
        assign(2 * node + 1, m + 1, r, ul, ur, v);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void addition(int node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_add(node, l, r, v);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        addition(2 * node, l, m, ul, ur, v);
        addition(2 * node + 1, m + 1, r, ul, ur, v);
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

    int n, m;
    cin >> n >> m;

    SegmentTree tree(n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1) {
            int v; cin >> v;
            tree.assign(l + 1, r, v);
        } else if (op == 2) {
            int v; cin >> v;
            tree.addition(l + 1, r, v);
        } else {
            long ans = tree.query(l + 1, r);
            cout << ans << "\n";
        }
    }
}