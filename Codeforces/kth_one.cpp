#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> tree;

public:
    SegmentTree(vector<int> &a, int n) {
        this->n = n;
        this->a = a;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i) {
        update(1, 1, n, i);
    }

    int query(int k) {
        return query(1, 1, n, k);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int l, int r, int i) {
        if (l == r) a[i] = tree[node] = 1 - a[i];
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i);
            else update(2 * node + 1, m + 1, r, i);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int l, int r, int k) {
        if (l == r) return l;

        int m = (l + r) / 2;
        if (tree[2 * node] >= k) return query(2 * node, l, m, k);
        return query(2 * node + 1, m + 1, r, k - tree[2 * node]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree tree(a, n);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i; cin >> i;
            tree.update(i + 1);
        } else {
            int k; cin >> k;

            int ans = tree.query(k + 1) - 1;
            cout << ans << "\n";
        }
    }
}