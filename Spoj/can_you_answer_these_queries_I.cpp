#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    struct Node {
        int prefix, suffix, sum, best;

        Node(): prefix(0), suffix(0), sum(0), best(0) {}
        Node(int v): prefix(v), suffix(v), sum(v), best(v) {}
        Node(int prefix, int suffix, int sum, int best):
            prefix(prefix), suffix(suffix), sum(sum), best(best) {}

        Node operator +(Node other) {
            int new_prefix = max(prefix, sum + other.prefix);
            int new_suffix = max(suffix + other.sum, other.suffix);
            int new_sum = sum + other.sum;
            int new_best = max({ best, other.best, suffix + other.prefix });
            return Node(new_prefix, new_suffix, new_sum, new_best);
        }
    };

    int n;
    vector<int> a;
    vector<Node> tree;

public:
    SegmentTree(vector<int> &a, int n) {
        this->n = n;
        this->a = a;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r).best;
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = Node(a[l]);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        if (qr <= m) return query(2 * node, l, m, ql, qr);
        if (ql > m) return query(2 * node + 1, m + 1, r, ql, qr);
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    int M; cin >> M;
    SegmentTree tree(A, N);

    while (M--) {
        int x, y;
        cin >> x >> y;

        int ans = tree.query(x, y);
        cout << ans << "\n";
    }
}