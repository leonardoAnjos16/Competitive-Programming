#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, INT_MAX);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] = v;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INT_MAX;
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

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;

        vector<tuple<int, int, int>> competitors(N);
        for (int i = 0; i < N; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            competitors[i] = make_tuple(a, b, c);
        }

        sort(competitors.begin(), competitors.end());

        int ans = 0;
        SegmentTree tree(N);

        for (int i = 0; i < N; i++) {
            int a, b, c;
            tie(a, b, c) = competitors[i];

            int mn = tree.query(1, b);
            if (mn > c) ans++;
            tree.update(b, c);
        }

        cout << ans << "\n";
    }
}