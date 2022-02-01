#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<long> a;
    vector<pair<long, long>> tree;

public:
    SegmentTree(vector<long> &a, int n) {
        this->n = n;
        this->a = a;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int l, int r) {
        update(1, 1, n, l, r);
    }

    long query(int l, int r) {
        return query(1, 1, n, l, r).first;
    }

private:
    pair<long, long> merge(pair<long, long> left, pair<long, long> right) {
        return make_pair(left.first + right.first, max(left.second, right.second));
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = make_pair(a[l], a[l]);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int ul, int ur) {
        if (r < ul || l > ur || tree[node].second == 1) return;

        if (l == r) {
            a[l] = sqrt(a[l]);
            tree[node] = make_pair(a[l], a[l]);
        } else {
            int m = (l + r) / 2;
            update(2 * node, l, m, ul, ur);
            update(2 * node + 1, m + 1, r, ul, ur);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    pair<long, long> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return make_pair(0LL, LLONG_MIN);
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        pair<long, long> left = query(2 * node, l, m, ql, qr);
        pair<long, long> right = query(2 * node + 1, m + 1, r, ql, qr);
        return merge(left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num_cases = 0;
    while (cin >> N) {
        cout << "Case #" << ++num_cases << ":\n";

        vector<long> A(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> A[i];

        int M; cin >> M;
        SegmentTree tree(A, N);

        while (M--) {
            int i, x, y;
            cin >> i >> x >> y;
            if (x > y) swap(x, y);

            if (!i) tree.update(x, y);
            else {
                long ans = tree.query(x, y);
                cout << ans << "\n";
            }
        }

        cout << "\n";
    }
}