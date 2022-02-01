#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<vector<int>> tree;

public:
    SegmentTree(vector<int> &a, int n) {
        this->n = n;
        this->a = a;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    vector<int> merge(vector<int> left, vector<int> right) {
        vector<int> ans(left.size() + right.size());
        std::merge(left.begin(), left.end(), right.begin(), right.end(), ans.begin());
        return ans;
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = vector<int>(1, a[l]);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) {
            auto end = lower_bound(tree[node].begin(), tree[node].end(), ql);
            auto begin = upper_bound(tree[node].begin(), tree[node].end(), qr);
            return end - tree[node].begin() + tree[node].end() - begin;
        }

        int m = (l + r) / 2;
        int left = query(2 * node, l, m, ql, qr);
        int right = query(2 * node + 1, m + 1, r, ql, qr);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> numbers(2 * n + 1);
    vector<vector<int>> segments(n + 1);

    for (int i = 1; i <= 2 * n; i++) {
        cin >> numbers[i];
        segments[numbers[i]].push_back(i);
    }

    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
        a[i] = segments[numbers[i]][0] == i ? segments[numbers[i]][1] : segments[numbers[i]][0];

    SegmentTree tree(a, 2 * n);
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        int ans = tree.query(segments[i][0], segments[i][1]);
        cout << ans;
    }
}