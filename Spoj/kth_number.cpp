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

        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r, int k) {
        return query(1, 1, n, l, r, k);
    }

private:
    void merge(vector<int> &node, vector<int> &left, vector<int> &right) {
        node.resize(left.size() + right.size());

        int i = 0, j = 0, k = 0;
        while (i < (int) left.size() || j < (int) right.size()) {
            if (i >= (int) left.size()) node[k++] = right[j++];
            else if (j >= (int) right.size()) node[k++] = left[i++];
            else if (left[i] <= right[j]) node[k++] = left[i++];
            else node[k++] = right[j++];
        }
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = vector<int>(1, a[l - 1]);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            merge(tree[node], tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr, int k) {
        if (l == r) return tree[node][0];

        auto end = upper_bound(tree[2 * node].begin(), tree[2 * node].end(), qr - 1);
        auto begin = lower_bound(tree[2 * node].begin(), tree[2 * node].end(), ql - 1);

        int cnt = end - begin, m = (l + r) / 2;
        if (cnt >= k) return query(2 * node, l, m, ql, qr, k);
        return query(2 * node + 1, m + 1, r, ql, qr, k - cnt);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());

    vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
        indices[idx] = i;
    }

    SegmentTree tree(n, indices);
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;

        int idx = tree.query(i, j, k);

        int ans = a[idx];
        cout << ans << "\n";
    }
}