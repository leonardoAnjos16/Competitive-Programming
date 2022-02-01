#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    const int NOP = -1e9 - 5;

    int n;
    vector<int> a;
    vector<int> lazy;
    vector<pair<long, long>> tree;

public:
    SegmentTree(vector<int> &a, int n) {
        this->n = n;
        this->a = a;

        lazy.assign(4 * n, NOP);
        tree.resize(4 * n);

        build(1, 1, n);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    long query(int l, int r) {
        return query(1, 1, n, l, r).second;
    }

public:
    pair<long, long> merge(pair<long, long> left, pair<long, long> right, int l, int r) {
        pair<long, long> ans;
        ans.first = left.first + right.first;
        ans.second = left.second + right.second + right.first * (r - l + 1);
        return ans;
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = make_pair(a[l], a[l]);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1], l, m);
        }
    }

    void update_lazy(int node, int l, int r, int v) {
        tree[node].first += v * (r - l + 1);
        tree[node].second += v * (r - l + 1LL) * (r - l + 2LL) / 2LL;

        if (lazy[node] == NOP) lazy[node] = v;
        else lazy[node] += v;
    }

    void push_down(int node, int l, int r) {
        if (lazy[node] == NOP) return;

        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = NOP;
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
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], l, m);
    }

    pair<long, long> query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        if (qr <= m) return query(2 * node, l, m, ql, qr);
        if (ql > m) return query(2 * node + 1, m + 1, r, ql, qr);

        auto left = query(2 * node, l, m, ql, qr);
        auto right = query(2 * node + 1, m + 1, r, ql, qr);
        return merge(left, right, max(l, ql), m);
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
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1) {
            int d; cin >> d;
            tree.update(l, r, d);
        } else {
            long ans = tree.query(l, r);
            cout << ans << "\n";
        }
    }
}