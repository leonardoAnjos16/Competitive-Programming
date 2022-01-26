#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    const int INF = 2e9;

    int n;
    vector<int> a, tree;

public:
    SegmentTree(vector<int> &a, int n) {
        this->n = n;
        this->a = a;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) a[i] = tree[node] = v;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INF;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        return min(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
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

    SegmentTree tree(a, n);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            tree.update(i + 1, v);
        } else {
            int l, r;
            cin >> l >> r;

            int ans = tree.query(l + 1, r);
            cout << ans << "\n";
        }
    }
}