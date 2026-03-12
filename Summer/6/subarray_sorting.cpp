#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> tree;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] = v;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INF;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        return min(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n + 1);
        vector<queue<int>> pos(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]].push(i);
        }

        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> b[i];

        bool possible = true;
        SegmentTree tree(n, a);

        for (int i = 1; i <= n && possible; i++) {
            if (pos[b[i]].empty()) possible = false;
            else {
                int idx = pos[b[i]].front(); pos[b[i]].pop();
                if (tree.query(1, idx) < b[i]) possible = false;
                else tree.update(idx, INF);
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}