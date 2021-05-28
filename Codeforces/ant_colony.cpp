#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> tree;

public:
    SegmentTree(vector<int> &a) {
        this->a = a;
        this->n = (int) a.size();
        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int i, int l, int r) {
        if (l == r) tree[i] = a[l - 1];
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            tree[i] = gcd(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[i];

        int m = (l + r) / 2;
        if (qr <= m) return query(2 * i, l, m, ql, qr);
        if (ql > m) return query(2 * i + 1, m + 1, r, ql, qr);

        int left = query(2 * i, l, m, ql, qr);
        int right = query(2 * i + 1, m + 1, r, ql, qr);
        return gcd(left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> s(n);
    map<int, vector<int>> indices;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        indices[s[i]].push_back(i + 1);
    }

    SegmentTree tree(s);

    int t; cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int winner = tree.query(l, r);
        auto first = lower_bound(indices[winner].begin(), indices[winner].end(), l);
        auto last = upper_bound(indices[winner].begin(), indices[winner].end(), r);

        int free = last - first;
        int ans = r - l + 1 - free;
        cout << ans << "\n";
    }
}