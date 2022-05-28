#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] += v;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        int left = query(2 * node, l, m, ql, qr);
        int right = query(2 * node + 1, m + 1, r, ql, qr);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    vector<long> sums(n + 1, 0LL);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sums[i + 1] = sums[i] + a[i];
    }

    sort(sums.begin(), sums.end());
    sums.erase(unique(sums.begin(), sums.end()), sums.end());

    int size = sums.size();
    SegmentTree tree(size);

    int idx = lower_bound(sums.begin(), sums.end(), 0) - sums.begin();
    tree.update(idx + 1, 1);

    long ans = 0LL, sum = 0LL;
    for (int i = 0; i < n; i++) {
        sum += a[i];

        int idx = lower_bound(sums.begin(), sums.end(), sum) - sums.begin();
        tree.update(idx + 1, 1);

        idx = upper_bound(sums.begin(), sums.end(), sum - x) - sums.begin();
        if (idx) ans += tree.query(1, idx);
    }

    cout << ans << "\n";
}