#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SegmentTree {
private:
    int n;
    vector<int> tree;
    vector<int> lazy;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    int query() {
        return query(1, 1, n);
    }

private:
    void update_lazy(int node, int l, int r, int v) {
        if (v == -1) return;

        if (v == 0) tree[node] = 0;
        else if (v == 1) tree[node] = r - l + 1;
        else tree[node] = (r - l + 1) - tree[node];

        if (v < 2) lazy[node] = v;
        else lazy[node] = 1 - lazy[node];
    }

    void push_down(int node, int l, int r) {
        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = -1;
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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r) {
        if (l == r) return l;

        push_down(node, l, r);

        int m = (l + r) / 2;
        if (tree[2 * node] < m - l + 1)
            return query(2 * node, l, m);

        return query(2 * node + 1, m + 1, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<llong> indices(1, 1LL);
    vector<tuple<int, llong, llong>> queries(n);

    for (int i = 0; i < n; i++) {
        int t; llong l, r;
        cin >> t >> l >> r;

        indices.push_back(l);
        indices.push_back(r + 1LL);
        queries[i] = make_tuple(t, l, r);
    }

    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());
    int sz = indices.size();

    SegmentTree tree(sz);
    for (auto [t, l, r]: queries) {
        int ul = lower_bound(indices.begin(), indices.end(), l) - indices.begin() + 1;
        int ur = upper_bound(indices.begin(), indices.end(), r) - indices.begin();

        assert(ul <= ur);

        if (t == 1) tree.update(ul, ur, 1);
        else if (t == 2) tree.update(ul, ur, 0);
        else tree.update(ul, ur, 2);

        int idx = tree.query() - 1;
        cout << indices[idx] << "\n";
    }
}