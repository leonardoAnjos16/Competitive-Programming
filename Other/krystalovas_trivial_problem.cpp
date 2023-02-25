#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> sum, ssum, lazy;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        sum.resize(4 * n);
        ssum.resize(4 * n);
        lazy.assign(4 * n, 0);

        build(1, 1, n);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, (v + MOD) % MOD);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) sum[node] = a[l], ssum[node] = (1LL * a[l] * a[l]) % MOD;
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
            ssum[node] = (ssum[2 * node] + ssum[2 * node + 1]) % MOD;
        }
    }

    void update_lazy(int node, int l, int r, int v) {
        int aux = ((r - l + 1LL) * v) % MOD;
        aux = (1LL * aux * v) % MOD;
        ssum[node] = (ssum[node] + aux) % MOD;
        
        aux = (2LL * sum[node] * v) % MOD;
        ssum[node] = (ssum[node] + aux) % MOD;

        aux = ((r - l + 1LL) * v) % MOD;
        sum[node] = (sum[node] + aux) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }

    void push_down(int node, int l, int r) {
        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = 0;
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
        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        ssum[node] = (ssum[2 * node] + ssum[2 * node + 1]) % MOD;
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return ssum[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        return (query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr)) % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> L(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> L[i];

    SegmentTree tree(N, L);
    while (Q--) {
        char op; cin >> op;
        if (op == 'u') {
            int l, r, x;
            cin >> l >> r >> x;

            tree.update(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;

            int ans = tree.query(l, r);
            cout << ans << "\n";
        }
    }
}