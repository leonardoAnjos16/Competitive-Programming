#include <bits/stdc++.h>

using namespace std;

#define llong long long int

pair<int, llong> operator +(pair<int, llong> a, pair<int, llong> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

struct SegmentTree {
private:
    int n;
    vector<pair<int, llong>> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, make_pair(0, 0LL));
    }

    void update(int i, int val, int v) {
        update(1, 1, n, i, val, v);
    }

    int query(int k) {
        return query(1, 1, n, k);
    }

    pair<int, llong> query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update(int node, int l, int r, int i, int val, int v) {
        if (l == r) tree[node] = tree[node] + make_pair(v, 1LL * val * v);
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, val, v);
            else update(2 * node + 1, m + 1, r, i, val, v);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int l, int r, int k) {
        if (l == r) return l;

        int m = (l + r) / 2;
        if (tree[2 * node].first >= k) return query(2 * node, l, m, k);
        return query(2 * node + 1, m + 1, r, k - tree[2 * node].first);
    }

    pair<int, llong> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return make_pair(0, 0LL);
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> x(n), order(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        order[i] = x[i];
    }

    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());

    int size = order.size();
    SegmentTree tree(size);

    for (int i = 0; i < n; i++) {
        if (i >= k) {
            int idx = lower_bound(order.begin(), order.end(), x[i - k]) - order.begin();
            tree.update(idx + 1, x[i - k], -1);
        }

        int idx = lower_bound(order.begin(), order.end(), x[i]) - order.begin();
        tree.update(idx + 1, x[i], 1);

        if (i + 1 >= k) {
            if (i + 1 > k) cout << " ";
            idx = tree.query((k + 1) / 2);

            int median = order[idx - 1];
            auto [cnt, sum] = tree.query(1, idx);
            llong ans = 1LL * cnt * median - sum;

            tie(cnt, sum) = tree.query(idx, size);
            ans += sum - 1LL * cnt * median;
            cout << ans;
        }
    }

    cout << "\n";
}