#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SegmentTree {
private:
    int n;
    vector<llong> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
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
        if (r < ql || l > qr) return LLONG_MIN;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        return max(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<tuple<int, int, int>> jobs(N);
    for (int i = 0; i < N; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        jobs[i] = make_tuple(l, r, c);
    }

    sort(jobs.begin(), jobs.end());

    SegmentTree tree(N);
    vector<llong> dp(N + 1, 0LL);

    for (int i = N - 1; i >= 0; i--) {
        auto [l, r, c] = jobs[i];
        int idx = upper_bound(jobs.begin(), jobs.end(), make_tuple(r, INT_MAX, INT_MAX)) - jobs.begin();

        llong incomplete = tree.query(i + 1, idx) - 1LL * l * S - c;
        llong complete = dp[idx] + (r - l + 1LL) * S - c;

        dp[i] = max({ dp[i + 1], incomplete, complete });
        tree.update(i + 1, 1LL * l * S + dp[i]);
    }

    llong ans = dp[0];
    cout << ans << "\n";
}