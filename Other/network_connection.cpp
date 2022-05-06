#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e9 + 5;

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> tree;

public:
    SegmentTree(vector<int> a) {
        this->a = a;
        this->n = a.size();

        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = a[l - 1];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INF;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        int left = query(2 * node, l, m, ql, qr);
        int right = query(2 * node + 1, m + 1, r, ql, qr);
        return min(left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D, B, M;
    cin >> D >> B >> M;

    vector<int> p(M);
    for (int i = 0; i < M; i++)
        cin >> p[i];

    sort(p.begin(), p.end());

    int l = 1, r = D, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        vector<int> dp(D + 1, INF);
        for (int j = 0; j <= mid; j++)
            dp[j] = abs(j - p[0]);

        SegmentTree tree(dp);
        for (int i = 1; i < M; i++) {
            vector<int> curr(D + 1, INF);
            for (int j = 0; j <= D; j++)
                curr[j] = tree.query(j - mid + 1, j + 1) + abs(j - p[i]);

            dp = curr;
            tree = SegmentTree(dp);
        }

        if (tree.query(D - mid + 1, D + 1) > B) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}