#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    int query(int i) {
        return query(1, 1, n, i);
    }

private:
    void update(int node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) tree[node] = max(tree[node], v);
        else {
            int m = (l + r) / 2;
            update(2 * node, l, m, ul, ur, v);
            update(2 * node + 1, m + 1, r, ul, ur, v);
        }
    }

    int query(int node, int l, int r, int i) {
        int ans = tree[node];
        if (l == r) return ans;

        int m = (l + r) / 2;
        if (i <= m) ans = max(ans, query(2 * node, l, m, i));
        else ans = max(ans, query(2 * node + 1, m + 1, r, i));
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    SegmentTree tree(n);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            tree.update(l + 1, r, v);
        } else {
            int i; cin >> i;

            int ans = tree.query(i + 1);
            cout << ans << "\n";
        }
    }
}