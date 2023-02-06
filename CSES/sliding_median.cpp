#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int k) {
        return query(1, 1, n, k);
    }

private:
    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] += v;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
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

    int n, k;
    cin >> n >> k;

    vector<int> x(n), order(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        order[i] = x[i];
    }

    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());

    int size = order.size();
    SegmentTree tree(size);

    for (int i = 0; i < n; i++) {
        if (i >= k) {
            int idx = lower_bound(order.begin(), order.end(), x[i - k]) - order.begin();
            tree.update(idx + 1, -1);
        }

        int idx = lower_bound(order.begin(), order.end(), x[i]) - order.begin();
        tree.update(idx + 1, 1);

        if (i + 1 >= k) {
            if (i + 1 > k) cout << " ";
            idx = tree.query((k + 1) / 2);
            cout << order[idx - 1];
        }
    }

    cout << "\n";
}