#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<pair<int, int>> a;
    vector<pair<int, int>> tree;

public:
    SegmentTree(vector<pair<int, int>> &a) {
        this->a = a;
        this->n = (int) a.size();
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int l, int r, pair<int, int> x) {
        update(1, 1, n, l, r, x);
    }

    pair<int, int> query(int i) {
        return query(1, 1, n, i);
    }

private:
    void build(int i, int l, int r) {
        if (l == r) tree[i] = a[l - 1];
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            tree[i] = make_pair(0, 0);
        }
    }

    void update(int i, int l, int r, int ul, int ur, pair<int, int> x) {
        if (ul <= l && r <= ur) tree[i] = x;
        else {
            // l...ul...ur...r
            if (tree[i] != make_pair(0, 0))
                tree[2 * i] = tree[2 * i + 1] = tree[i];

            int m = (l + r) / 2;
            if (ul <= m) update(2 * i, l, m, ul, ur, x);
            if (ur > m) update(2 * i + 1, m + 1, r, ul, ur, x);
            tree[i] = tree[2 * i] == tree[2 * i + 1] ? tree[2 * i] : make_pair(0, 0);
        }
    }

    pair<int, int> query(int i, int l, int r, int qi) {
        if (tree[i] != make_pair(0, 0)) return tree[i];

        int m = (l + r) / 2;
        if (qi <= m) return query(2 * i, l, m, qi);
        else return query(2 * i + 1, m + 1, r, qi);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(2 * n);
    for (auto &ai: a) cin >> ai;

    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
        b[i] = make_pair(i + n + 1, i + 1);

    SegmentTree tree(b);
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            tree.update(y, y + k - 1, make_pair(x, y));
        } else {
            int x; cin >> x;

            auto aux = tree.query(x);
            int diff = x - aux.second;

            int ans = a[aux.first + diff - 1];
            cout << ans << "\n";
        }
    }
}