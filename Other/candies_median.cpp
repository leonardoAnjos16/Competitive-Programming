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

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    int query(long k) {
        return query(1, 1, n, k);
    }

private:
    void update_lazy(int node, int l, int r, long v) {
        lazy[node] += v;
        tree[node] += (r - l + 1LL) * v;
    }

    void push_down(int node, int l, int r) {
        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = 0LL;
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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, long k) {
        if (l == r) return l;

        push_down(node, l, r);

        int m = (l + r) / 2;
        if (tree[2 * node] >= k) return query(2 * node, l, m, k);
        return query(2 * node + 1, m + 1, r, k - tree[2 * node]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree tree(n);
    while (q--) {
        int k; cin >> k;
        assert(k > 0);

        long cnt = 0LL;
        vector<tuple<int, int, int>> ops;

        while (k--) {
            int l, r, x;
            cin >> l >> r >> x;

            ops.emplace_back(l, r, x);
            cnt += (r - l + 1LL) * x;
            tree.update(l, r, x);
        }

        long mid = (cnt + 1LL) / 2LL;
        int first = tree.query(mid);
        int second = cnt & 1LL ? first : tree.query(mid + 1LL);

        int sum = a[first] + a[second];

        cout << (sum / 2);
        if (sum & 1) cout << ".5";
        cout << "\n";

        for (auto [l, r, x]: ops)
            tree.update(l, r, -x);
    }
}