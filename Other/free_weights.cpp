#include <bits/stdc++.h>

using namespace std;

#define llong long long int

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
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INT_MIN;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        return max(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> w(2, vector<int>(n + 1));
    map<int, vector<pair<int, int>>> pos;

    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
            pos[w[i][j]].emplace_back(i, j);
        }

    vector<SegmentTree> trees;
    for (int i = 0; i < 2; i++)
        trees.emplace_back(n, w[i]);

    int ans = 0;
    for (auto [v, indices]: pos) {
        if (indices[0].first != indices[1].first) ans = v;
        else {
            int l = indices[0].second;
            int r = indices[1].second;
            if (l > r) swap(l, r);

            if (l + 1 < r && trees[indices[0].first].query(l + 1, r - 1) > v) ans = v;
            else ans = max(ans, trees[indices[0].first].query(l + 1, r - 1));
        }
    }

    cout << ans << "\n";
}