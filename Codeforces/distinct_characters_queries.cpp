#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 26;

struct SegmentTree {
private:
    int n;
    string s;
    vector<vector<int>> tree;

public:
    SegmentTree(int n, string &s) {
        this->n = n;
        this->s = s;

        tree.assign(4 * n, vector<int>(MAX, 0));
        build(1, 1, n);
    }

    void update(int i, char c) {
        update(1, 1, n, i, c);
    }

    int query(int l, int r) {
        vector<int> cnt = query(1, 1, n, l, r);

        int ans = 0;
        for (int i = 0; i < MAX; i++)
            ans += cnt[i] != 0;

        return ans;
    }

private:
    void merge(int i) {
        for (int j = 0; j < MAX; j++)
            tree[i][j] = tree[2 * i][j] + tree[2 * i + 1][j];
    }

    void build(int i, int l, int r) {
        if (l == r) tree[i][s[l] - 'a'] = 1;
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            merge(i);
        }
    }

    void update(int i, int l, int r, int j, char c) {
        if (l == r) {
            tree[i][s[j] - 'a'] = 0;
            tree[i][c - 'a'] = 1;
            s[j] = c;
        } else {
            int m = (l + r) / 2;
            if (j <= m) update(2 * i, l, m, j, c);
            else update(2 * i + 1, m + 1, r, j, c);
            merge(i);
        }
    }

    vector<int> query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return vector<int>(MAX, 0);
        if (ql <= l && r <= qr) return tree[i];

        int m = (l + r) / 2;
        vector<int> left = query(2 * i, l, m, ql, qr);
        vector<int> right = query(2 * i + 1, m + 1, r, ql, qr);

        vector<int> ans(MAX, 0);
        for (int i = 0; i < MAX; i++)
            ans[i] = left[i] + right[i];

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();
    s = "." + s;

    int q; cin >> q;
    SegmentTree tree(n, s);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos; char c;
            cin >> pos >> c;
            tree.update(pos, c);
        } else {
            int l, r;
            cin >> l >> r;

            int ans = tree.query(l, r);
            cout << ans << "\n";
        }
    }
}