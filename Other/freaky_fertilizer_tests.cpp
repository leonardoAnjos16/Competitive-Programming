#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 998244353;

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<pair<int, int>> tree;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;
        tree.assign(4 * n, make_pair(1, 0));
    }

    void update(int l, int r, int mult, int add) {
        update(1, 1, n, l, r, mult, add);
    }

    int query(int i) {
        return query(1, 1, n, i);
    }

private:
    void update_tree(int node, int mult, int add) {
        int new_mult = (1LL * tree[node].first * mult) % MOD;
        int new_add = (1LL * tree[node].second * mult) % MOD;
        new_add = (new_add + add) % MOD;
        tree[node] = make_pair(new_mult, new_add);
    }

    void push_down(int node) {
        update_tree(2 * node, tree[node].first, tree[node].second);
        update_tree(2 * node + 1, tree[node].first, tree[node].second);
        tree[node].first = 1;
        tree[node].second = 0;
    }

    void update(int node, int l, int r, int ul, int ur, int mult, int add) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_tree(node, mult, add);
            return;
        }

        push_down(node);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur, mult, add);
        update(2 * node + 1, m + 1, r, ul, ur, mult, add);
    }

    int query(int node, int l, int r, int i) {
        if (l == r) {
            int ans = (1LL * tree[node].first * a[i]) % MOD;
            ans = (ans + tree[node].second) % MOD;
            return ans;
        }

        int m = (l + r) / 2, ans;
        if (i <= m) ans = query(2 * node, l, m, i);
        else ans = query(2 * node + 1, m + 1, r, i);

        ans = (1LL * tree[node].first * ans) % MOD;
        ans = (ans + tree[node].second) % MOD;
        return ans;
    }
};

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int a, int m) {
    return exp(a, m - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    SegmentTree tree(n, x);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, f, g, t;
            cin >> l >> r >> f >> g >> t;

            if (!t) continue;

            int mult = exp(f, t);
            int add = (1LL * ((mult + MOD - 1) % MOD) * mod_mult_inv((f + MOD - 1) % MOD, MOD)) % MOD;
            add = (1LL * g * add) % MOD;
            if (f == 1) add = (1LL * g * t) % MOD;

            tree.update(l, r, mult, add);
        } else {
            int i; cin >> i;

            int ans = tree.query(i);
            cout << ans << "\n";
        }
    }
}