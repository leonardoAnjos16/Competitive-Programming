#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e6 + 5;

int last_prime[MAX] = {0};

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> tree;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = last_prime[a[l]];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) {
            a[i] += v;
            tree[node] = last_prime[a[i]];
        } else {
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

    last_prime[1] = 1;
    for (int i = 2; i < MAX; i++)
        if (!last_prime[i])
            for (int j = i; j < MAX; j += i)
                last_prime[j] = i;

    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    SegmentTree tree(N, A);
    while (M--) {
        int op; cin >> op;
        if (op == 1) {
            for (int i = 1; i < N - i + 1; i++) {
                tree.update(i, A[N - i + 1]);
                tree.update(N - i + 1, -A[N - i + 1]);

                A[i] += A[N - i + 1];
                A[N - i + 1] = 0;
            }

            if (N > 1) N = (N + 1) / 2;
        } else {
            int x, y;
            cin >> x >> y;

            int ans = tree.query(x, y);
            cout << ans << "\n";
        }
    }
}