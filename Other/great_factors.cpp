#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 1e4 + 5;

int largest_prime_factor[MAX_A] = {0, 1};
int prime_factors_sum[MAX_A] = {0};

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> sum, lazy;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        sum.resize(4 * n);
        lazy.assign(4 * n, -1);

        build(1, 1, n);
    }

    void update(int i) {
        update(1, 1, n, i);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) {
            lazy[node] = a[l];
            sum[node] = prime_factors_sum[a[l]];
        } else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            sum[node] = sum[2 * node] + sum[2 * node + 1];
        }
    }

    void update_lazy(int node, int l, int r, int v) {
        lazy[node] = v;
        sum[node] = prime_factors_sum[v] * (r - l + 1);
    }

    void push_down(int node, int l, int r) {
        if (lazy[node] == -1) return;

        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = -1;
    }

    void update(int node, int l, int r, int i) {
        if (l == r) {
            lazy[node] /= largest_prime_factor[lazy[node]];
            sum[node] = prime_factors_sum[lazy[node]];
        } else {
            push_down(node, l, r);

            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i);
            else update(2 * node + 1, m + 1, r, i);
            sum[node] = sum[2 * node] + sum[2 * node + 1];
        }
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
        sum[node] = sum[2 * node] + sum[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return sum[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < MAX_A; i++)
        if (!largest_prime_factor[i])
            for (int j = i; j < MAX_A; j += i)
                largest_prime_factor[j] = i;

    for (int i = 2; i < MAX_A; i++) {
        int v = i;
        while (v > 1) {
            prime_factors_sum[i] += largest_prime_factor[v];
            v /= largest_prime_factor[v];
        }
    }

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree tree(n, a);

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i;

            tree.update(i);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;

            int ans = tree.query(l, r);
            cout << ans << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;

            tree.update(l, r, x);
        }
    }
}