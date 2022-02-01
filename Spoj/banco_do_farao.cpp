#include <bits/stdc++.h>

using namespace std;

#define long long long int

pair<int, int> operator +(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

struct SegmentTree {
private:
    struct Node {
        pair<int, int> sum, prefix, suffix, best;

        Node(): sum({ 0, 0 }), prefix({ 0, 0 }), suffix({ 0, 0 }), best({ 0, 0 }) {}
        Node(int v): sum({ v, 1 }), prefix({ v, 1 }), suffix({ v, 1 }), best({ v, 1 }) {}
        Node(pair<int, int> sum, pair<int, int> prefix, pair<int, int> suffix, pair<int, int> best):
            sum(sum), prefix(prefix), suffix(suffix), best(best) {}

        Node operator +(Node other) {
            pair<int, int> new_sum = sum + other.sum;
            pair<int, int> new_prefix = max(prefix, sum + other.prefix);
            pair<int, int> new_suffix = max(suffix + other.sum, other.suffix);
            pair<int, int> new_best = max({ best, other.best, suffix + other.prefix });
            return Node(new_sum, new_prefix, new_suffix, new_best);
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

    pair<int, int> query(int l, int r) {
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

        /* auto [sum, prefix, suffix, best] = tree[node];
        cout << node << " " << l << " " << r << " " << sum.first << " " << sum.second << "\n"; */
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        if (qr <= m) return query(2 * node, l, m, ql, qr);
        if (ql > m) return query(2 * node + 1, m + 1, r, ql, qr);

        Node left = query(2 * node, l, m, ql, qr);
        Node right = query(2 * node + 1, m + 1, r, ql, qr);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> a[i];

        int Q; cin >> Q;
        SegmentTree tree(a, N);

        while (Q--) {
            int A, B;
            cin >> A >> B;

            pair<int, int> ans = tree.query(A, B);
            cout << ans.first << " " << ans.second << "\n";
        }
    }
}