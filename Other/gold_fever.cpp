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
        tree.assign(4 * n, 0);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    int query(int i) {
        return query(1, 1, n, i);
    }

private:
    void update(int node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;

        if (ul <= l && r <= ur) tree[node] = max(tree[node], v);
        else {
            int m = (l + r) / 2;
            update(2 * node, l, m, ul, ur, v);
            update(2 * node + 1, m + 1, r, ul, ur, v);
        }
    }

    int query(int node, int l, int r, int i) {
        if (l == r) return tree[node];

        int m = (l + r) / 2, ans;
        if (i <= m) ans = query(2 * node, l, m, i);
        else ans = query(2 * node + 1, m + 1, r, i);
        return ans = max(ans, tree[node]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int ans = 0;
    SegmentTree tree(2 * N);

    for (int i = 1; i <= N; i++) {
        int g, a, b;
        cin >> g >> a >> b;

        int curr = tree.query(i);
        ans = max(ans, curr);

        tree.update(i + a, i + b, curr + g);
    }

    for (int i = N + 1; i <= 2 * N; i++)
        ans = max(ans, tree.query(i));

    cout << ans << "\n";
}