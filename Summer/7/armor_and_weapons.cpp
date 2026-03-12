#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] = max(tree[i], v);
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
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

    int n, m;
    cin >> n >> m;

    int q; cin >> q;

    set<pair<int, int>> combs;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (n > m) swap(a, b);
        combs.emplace(a, b);
    }

    if (n > m) swap(n, m);

    int ans = 0;
    bool found = false;

    queue<pair<int, int>> cq;
    cq.emplace(1, 1);

    while (!cq.empty() && !found) {
        SegmentTree tree(n);
        vector<pair<int, int>> nq;

        while (!cq.empty() && !found) {
            auto [a, b] = cq.front(); cq.pop();
            if (a == n && b == m) found = true;
            else if (tree.query(a, n) < b) {
                int power = combs.count(make_pair(a, b)) ? a + b + 1 : a + b;
                if (a < n) nq.emplace_back(min(power, n), b);
                if (b < m) nq.emplace_back(a, min(power, m));
                tree.update(a, b);
            }
        }

        if (!found) {
            ans++;
            sort(nq.rbegin(), nq.rend());
            for (auto [a, b]: nq) cq.emplace(a, b);
        }
    }

    cout << ans << "\n";
}