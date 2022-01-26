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

    int query(int l, int r) {
        pair<int, int> mxs = query(1, 1, n, l, r);
        return mxs.first + mxs.second;
    }

private:
    pair<int, int> merge(pair<int, int> left, pair<int, int> right) {
        int mx = max(left.first, right.first);
        int snd_mx = max(min(left.first, right.first), max(left.second, right.second));
        return make_pair(mx, snd_mx);
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = make_pair(a[l], -1);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] = make_pair(a[i] = v, -1);
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    pair<int, int> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return make_pair(INT_MIN, INT_MIN);
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

    int N; cin >> N;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    int Q; cin >> Q;
    SegmentTree tree(A, N);

    while (Q--) {
        char op; cin >> op;
        if (op == 'U') {
            int i, x;
            cin >> i >> x;
            tree.update(i, x);
        } else {
            int x, y;
            cin >> x >> y;

            int ans = tree.query(x, y);
            cout << ans << "\n";
        }
    }
}