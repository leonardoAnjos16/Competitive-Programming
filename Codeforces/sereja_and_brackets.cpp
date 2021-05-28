#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    string s; int n;
    vector<tuple<int, int, int>> tree;

public:
    SegmentTree(string &s) {
        this->s = s;
        this->n = size(s);
        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r) {
        int o, c, b;
        tie(o, c, b) = query(1, 1, n, l, r);
        return b;
    }

private:
    void build(int i, int l, int r) {
        if (l == r) {
            int o = s[l - 1] == '(' ? 1 : 0;
            int c = s[l - 1] == ')' ? 1 : 0;
            tree[i] = make_tuple(o, c, 0);
        } else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);

            int lo, lc, lb, ro, rc, rb;
            tie(lo, lc, lb) = tree[2 * i];
            tie(ro, rc, rb) = tree[2 * i + 1];

            int aux = min(lo, rc);
            int o = lo - aux + ro;
            int c = lc + rc - aux;
            int b = lb + rb + 2 * aux;

            tree[i] = make_tuple(o, c, b);
        }
    }

    tuple<int, int, int> query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[i];

        int m = (l + r) / 2;
        if (qr <= m) return query(2 * i, l, m, ql, qr);
        if (ql > m) return query(2 * i + 1, m + 1, r, ql, qr);

        int lo, lc, lb, ro, rc, rb;
        tie(lo, lc, lb) = query(2 * i, l, m, ql, qr);
        tie(ro, rc, rb) = query(2 * i + 1, m + 1, r, ql, qr);

        int aux = min(lo, rc);
        int o = lo - aux + ro;
        int c = lc + rc - aux;
        int b = lb + rb + 2 * aux;

        return make_tuple(o, c, b);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    SegmentTree tree(s);

    int m; cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        int ans = tree.query(l, r);
        cout << ans << "\n";
    }
}