#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> lazy;
    vector<pair<int, int>> tree;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        lazy.assign(4 * n, 0);
        build(1, 1, n);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    pair<int, int> query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = make_pair(a[l], l);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update_lazy(int node, int v) {
        tree[node].first += v;
        lazy[node] += v;
    }

    void push_down(int node) {
        update_lazy(2 * node, lazy[node]);
        update_lazy(2 * node + 1, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_lazy(node, v);
            return;
        }

        push_down(node);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur, v);
        update(2 * node + 1, m + 1, r, ul, ur, v);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    pair<int, int> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return make_pair(INT_MIN, -1);
        if (ql <= l && r <= qr) return tree[node];

        push_down(node);

        int m = (l + r) / 2;
        pair<int, int> ans = query(2 * node, l, m, ql, qr);
        ans = max(ans, query(2 * node + 1, m + 1, r, ql, qr));
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree tree(n, a);

    bool done = false;
    for (int i = 0; i < n && !done; i++) {
        auto [mx, idx] = tree.query(1, n);
        if (mx < n - 1) done = true;
        else {
            tree.update(1, n, 1);
            tree.update(idx, idx, -n);
        }
    }

    if (!done) cout << "Recurrent\n";
    else {
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << " ";
            cout << tree.query(i, i).first;
        }

        cout << "\n";
    }
}