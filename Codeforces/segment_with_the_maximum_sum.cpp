#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    struct Node {
        long prefix, suffix, sum, best;

        Node(): prefix(0LL), suffix(0LL), sum(0LL), best(0LL) {}
        Node(long prefix, long suffix, long sum, long best):
            prefix(prefix), suffix(suffix), sum(sum), best(best) {}

        Node operator +(Node other) {
            long new_prefix = max(prefix, sum + other.prefix);
            long new_suffix = max(suffix + other.sum, other.suffix);
            long new_sum = sum + other.sum;
            long new_best = max({ best, other.best, suffix + other.prefix });
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

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    long query(int l, int r) {
        return query(1, 1, n, l, r).best;
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = Node(max(a[l], 0), max(a[l], 0), a[l], max(a[l], 0));
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) a[i] = v, tree[node] = Node(max(v, 0), max(v, 0), v, max(a[l], 0));
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
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

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree tree(a, n);
    long ans = tree.query(1, n);
    cout << ans << "\n";

    while (m--) {
        int i, v;
        cin >> i >> v;

        tree.update(i + 1, v);
        ans = tree.query(1, n);
        cout << ans << "\n";
    }
}