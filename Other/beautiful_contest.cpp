#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 2e6 + 5;

struct SegmentTree {
private:
    int n;
    vector<llong> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0LL);
    }

    void update(int i, llong v) {
        update(1, 1, n, i, v);
    }

    llong query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update(int node, int l, int r, int i, llong v) {
        if (l == r) tree[node] = v;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    llong query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INT_MIN;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        return max(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
    }
};

SegmentTree tree(MAX);
llong dp[MAX] = {0LL};
multiset<llong> beauties[MAX];

void update(int d) {
    if (beauties[d].empty()) dp[d] = 0LL;
    else {
        llong b = *beauties[d].rbegin();
        dp[d] = max({ b, b + dp[2 * d], b + dp[2 * d + 1], 0LL });
    }

    tree.update(d, dp[d]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while (n--) {
        int t, d; llong b;
        cin >> t >> d >> b;

        if (t == 1) {
            beauties[d].insert(b);
            while (d) {
                update(d);
                d >>= 1;
            }
        } else {
            beauties[d].erase(beauties[d].find(b));
            while (d) {
                update(d);
                d >>= 1;
            }
        }

        llong ans = tree.query(1, MAX);
        cout << ans << "\n";
    }
}