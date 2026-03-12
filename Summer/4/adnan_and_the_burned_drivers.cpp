#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int BASE = 243;
const int MOD = 1e9 + 7;

struct SegmentTree {
private:
    int n;
    string s;
    vector<int> p, tree;

public:
    SegmentTree(int n, string &s) {
        this->n = n;
        this->s = s;

        tree.resize(4 * n);
        p.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            p[i] = (1LL * p[i - 1] * BASE) % MOD;

        build(1, 1, n);
    }

    void update(int i, char c) {
        update(1, 1, n, i, c);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    int merge(int left, int right, int l, int r) {
        return ((1LL * left * p[r - l + 1]) % MOD + right) % MOD;
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = s[l - 1] - 'a' + 1;
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1], m + 1, r);
        }
    }

    void update(int node, int l, int r, int i, char c) {
        if (l == r) tree[node] = c - 'a' + 1;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, c);
            else update(2 * node + 1, m + 1, r, i, c);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1], m + 1, r);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        int left = query(2 * node, l, m, ql, qr);
        int right = query(2 * node + 1, m + 1, r, ql, qr);

        if (qr <= m) return left;
        if (ql > m) return right;

        return merge(left, right, m + 1, min(qr, r));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;

        string s; cin >> s;

        SegmentTree tree(N, s);

        reverse(s.begin(), s.end());
        SegmentTree rtree(N, s);

        while (E--) {
            int op; cin >> op;
            if (op == 1) {
                int idx; char c;
                cin >> idx >> c;

                tree.update(idx, c);
                rtree.update(N - idx + 1, c);
            } else {
                int l, r;
                cin >> l >> r;

                if (tree.query(l, r) == rtree.query(N - r  + 1, N - l + 1)) cout << "Adnan Wins\n";
                else cout << "ARCNCD!\n";
            }
        }
    }
}