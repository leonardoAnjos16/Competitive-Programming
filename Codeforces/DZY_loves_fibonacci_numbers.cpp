#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 3e5 + 5;
const int MOD = 1e9 + 9;

long fib[MAX] = { 0LL, 1LL, 1LL }, ps[MAX] = { 0LL };

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<long> tree;
    vector<pair<long, long>> lazy;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        lazy.assign(4 * n, make_pair(0LL, 0LL));

        build(1, 1, n);
    }

    void update(int l, int r) {
        assert(update(1, 1, n, l, r, 1) == r - l + 1);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void merge(int i) {
        tree[i] = (tree[2 * i] + tree[2 * i + 1]) % MOD;
    }

    void update_lazy(int i, int l, int r, long a, long b) {
        if (l == r) tree[i] += a;
        else {
            tree[i] += a * (ps[r - l - 1] + 1);
            tree[i] += b * ps[r - l];
            tree[i] %= MOD;

            lazy[i].first += a;
            lazy[i].first %= MOD;

            lazy[i].second += b;
            lazy[i].second %= MOD;
        }
    }

    void pushdown(int i, int l, int r) {
        if (lazy[i].first) {
            int m = (l + r) / 2;
            update_lazy(2 * i, l, m, lazy[i].first, lazy[i].second);

            long a = (fib[m - l] * lazy[i].first + fib[m - l + 1] * lazy[i].second) % MOD;
            long b = (fib[m - l + 1] * lazy[i].first + fib[m - l + 2] * lazy[i].second) % MOD;

            update_lazy(2 * i + 1, m + 1, r, a, b);
            lazy[i].first = lazy[i].second = 0LL;
        }
    }

    void build(int i, int l, int r) {
        if (l == r) tree[i] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            merge(i);
        }
    }

    int update(int i, int l, int r, int ul, int ur, int s) {
        if (r < ul || l > ur) return 0;

        if (ul <= l && r <= ur) {
            update_lazy(i, l, r, fib[s], fib[s + 1]);
            return r - l + 1;
        } else {
            pushdown(i, l, r);
            int m = (l + r) / 2;

            int updated = update(2 * i, l, m, ul, ur, s);
            updated += update(2 * i + 1, m + 1, r, ul, ur, s + updated);

            merge(i);
            return updated;
        }
    }

    long query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[i];

        pushdown(i, l, r);
        int m = (l + r) / 2;

        return (query(2 * i, l, m, ql, qr) + query(2 * i + 1, m + 1, r, ql, qr)) % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 3; i < MAX; i++)
        fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;

    for (int i = 1; i < MAX; i++)
        ps[i] = (ps[i - 1] + fib[i]) % MOD;

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree tree(n, a);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1) tree.update(l, r);
        else {
            int ans = tree.query(l, r);
            cout << ans << "\n";
        }
    }
}