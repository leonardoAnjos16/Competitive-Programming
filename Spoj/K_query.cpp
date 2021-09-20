#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<vector<int>> tree;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.assign(4 * n, vector<int>());
        build(1, 1, n);
    }

    int query(int l, int r, int k) {
        return query(1, 1, n, l, r, k);
    }

private:
    void merge_trees(int i) {
        merge(tree[2 * i].begin(), tree[2 * i].end(), tree[2 * i + 1].begin(), tree[2 * i + 1].end(), back_inserter(tree[i]));
    }

    int smaller(int i, int k) {
        return upper_bound(tree[i].begin(), tree[i].end(), k) - tree[i].begin();
    }

    void build(int i, int l, int r) {
        if (l == r) tree[i] = vector<int>(1, a[l]);
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            merge_trees(i);
        }
    }

    int query(int i, int l, int r, int ql, int qr, int k) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return r - l - smaller(i, k) + 1;

        int m = (l + r) / 2;
        return query(2 * i, l, m, ql, qr, k) + query(2 * i + 1, m + 1, r, ql, qr, k);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int q; cin >> q;
    SegmentTree tree(n, a);

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;

        int ans = tree.query(i, j, k);
        cout << ans << "\n";
    }
}