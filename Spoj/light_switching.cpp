#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> tree;
    vector<bool> lazy;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, false);
    }

    void update(int l, int r) {
        update(1, 1, n, l, r);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update_lazy(int node, int l, int r) {
        tree[node] = r - l - tree[node] + 1;
        lazy[node] = !lazy[node];
    }

    void push_down(int node, int l, int r) {
        if (!lazy[node]) return;

        int m = (l + r) / 2;
        update_lazy(2 * node, l, m);
        update_lazy(2 * node + 1, m + 1, r);
        lazy[node] = false;
    }

    void update(int node, int l, int r, int ul, int ur) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_lazy(node, l, r);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur);
        update(2 * node + 1, m + 1, r, ul, ur);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        int left = query(2 * node, l, m, ql, qr);
        int right = query(2 * node + 1, m + 1, r, ql, qr);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    SegmentTree tree(N);
    while (M--) {
        int op, S, E;
        cin >> op >> S >> E;

        if (!op) tree.update(S, E);
        else {
            int ans = tree.query(S, E);
            cout << ans << "\n";
        }
    }
}