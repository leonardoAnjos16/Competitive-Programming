#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> sum, psum;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        sum.resize(4 * n);
        psum.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r).second;
    }

private:
    void build(int node, int l, int r) {
        if (l == r) sum[node] = a[l], psum[node] = 0;
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);

            sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;

            int aux = (1LL * sum[2 * node] * sum[2 * node + 1]) % MOD;
            psum[node] = (psum[2 * node] + psum[2 * node + 1]) % MOD;
            psum[node] = (psum[node] + aux) % MOD;
        }
    }

    pair<int, int> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return make_pair(0, 0);
        if (ql <= l && r <= qr) return make_pair(sum[node], psum[node]);

        int m = (l + r) / 2;
        auto [lsum, lpsum] = query(2 * node, l, m, ql, qr);
        auto [rsum, rpsum] = query(2 * node + 1, m + 1, r, ql, qr);

        int s = (lsum + rsum) % MOD;

        int aux = (1LL * lsum * rsum) % MOD;
        int p = (lpsum + rpsum) % MOD;
        p = (p + aux) % MOD;

        return make_pair(s, p);
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

    SegmentTree tree(n, a);
    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = tree.query(l, r);
        cout << ans << "\n";
    }
}