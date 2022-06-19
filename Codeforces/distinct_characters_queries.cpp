#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 26;

vector<int> operator +(vector<int> a, vector<int> b) {
    vector<int> ans(a.size());
    for (int i = 0; i < (int) a.size(); i++)
        ans[i] = a[i] + b[i];

    return ans;
}

vector<int> operator -(vector<int> a, vector<int> b) {
    vector<int> ans(a.size());
    for (int i = 0; i < (int) a.size(); i++)
        ans[i] = a[i] - b[i];

    return ans;
}

struct FenwickTree {
private:
    int n;
    vector<vector<int>> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, vector<int>(MAX, 0));
    }

    void add(int i, char c, int v) {
        if (!i) tree[0][c - 'a'] += v;
        else {
            while (i < n) {
                tree[i][c - 'a'] += v;
                i += LSO(i);
            }
        }
    }

    int query(int l, int r) {
        vector<int> cnt = query(r) - query(l - 1);

        int ans = 0;
        for (int i = 0; i < MAX; i++)
            ans += cnt[i] > 0;

        return ans;
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    vector<int> query(int i) {
        if (i < 0) return vector<int>(MAX, 0);

        vector<int> ans = tree[0];
        while (i) {
            ans = ans + tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    FenwickTree tree(n);
    for (int i = 0; i < n; i++)
        tree.add(i + 1, s[i], 1);

    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos; char c;
            cin >> pos >> c;

            tree.add(pos, s[pos - 1], -1);
            tree.add(pos, c, 1);
            s[pos - 1] = c;
        } else {
            int l, r;
            cin >> l >> r;

            int ans = tree.query(l, r);
            cout << ans << "\n";
        }
    }
}