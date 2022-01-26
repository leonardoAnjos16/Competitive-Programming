#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<pair<int, int>> tree;

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

    pair<int, int> query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    pair<int, int> merge(pair<int, int> left, pair<int, int> right) {
        if (left.first == right.first)
            return make_pair(left.first, left.second + right.second);
        
        return left.first < right.first ? left : right;
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = make_pair(a[l], 1);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] = make_pair(a[i] = v, 1);
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    pair<int, int> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return make_pair(INT_MAX, 0);
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        auto left = query(2 * node, l, m, ql, qr);
        auto right = query(2 * node + 1, m + 1, r, ql, qr);
        return merge(left, right);
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

            auto ans = tree.query(l + 1, r);
            cout << ans.first << " " << ans.second << "\n";
        }
    }
}