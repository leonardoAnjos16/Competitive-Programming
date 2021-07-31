#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a, tree;

public:
    SegmentTree(vector<int> &a) {
        this->a = a;
        this->n = a.size();
        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int i, int l, int r) {
        if (l == r) tree[i] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INT_MAX;
        if (ql <= l && r <= qr) return tree[i];

        int m = (l + r) / 2;
        int left = query(2 * i, l, m, ql, qr);
        int right = query(2 * i + 1, m + 1, r, ql, qr);
        return min(left, right);
    }
};

long students(SegmentTree &tree, map<int, vector<int>> &pos, int i, int j, int last_mn = 0) {
    if (i > j) return 0;

    int last_pos = i - 1;
    int mn = tree.query(i, j);

    long ans = mn - last_mn;
    for (auto it = lower_bound(pos[mn].begin(), pos[mn].end(), i);
        it != upper_bound(pos[mn].begin(), pos[mn].end(), j); it++) {
            ans += students(tree, pos, last_pos + 1, *it - 1, mn);
            last_pos = *it;
    }

    ans += students(tree, pos, last_pos + 1, j, mn);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n + 1);
    map<int, vector<int>> pos;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    SegmentTree tree(a);
    
    long ans = students(tree, pos, 1, n);
    cout << ans << "\n";
}