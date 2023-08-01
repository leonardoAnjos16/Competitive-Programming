#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;

int phi[MAX];

struct SegmentTree {
private:
    struct Node {
        llong sum;
        int equal;

        Node(llong sum = 0LL, int equal = -1): sum(sum), equal(equal) {}

        Node operator +(Node other) {
            llong nsum = sum + other.sum;
            int nequal = equal == -1 || other.equal == -1 ? -1 : (equal != other.equal ? -1 : equal);
            return Node(nsum, nequal);
        }
    };

    int n;
    vector<int> a;
    vector<int> lazy;
    vector<Node> tree;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        lazy.assign(4 * n, -1);
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int l, int r, int v = -1) {
        update(1, 1, n, l, r, v);
    }

    llong query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = Node(a[l], a[l]);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update_lazy(int node, int l, int r, int v) {
        tree[node].sum = (r - l + 1LL) * v;
        tree[node].equal = v;
        lazy[node] = v;
    }

    void push_down(int node, int l, int r) {
        if (lazy[node] == -1) return;

        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = -1;
    }

    void update(int node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            if (v != -1) {
                update_lazy(node, l, r, v);
                return;
            }

            if (tree[node].equal != -1) {
                update_lazy(node, l, r, phi[tree[node].equal]);
                return;
            }
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur, v);
        update(2 * node + 1, m + 1, r, ul, ur, v);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    llong query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return tree[node].sum;

        push_down(node, l, r);

        int m = (l + r) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < MAX; i++)
        phi[i] = i;

    for (int i = 2; i < MAX; i++)
        if (phi[i] == i)
            for (int j = i; j < MAX; j += i)
                phi[j] -= phi[j] / i;

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree tree(n, a);
    while (q--) {
        int t, L, R;
        cin >> t >> L >> R;

        if (t == 1) tree.update(L, R);
        else if (t == 2) {
            int x; cin >> x;
            tree.update(L, R, x);
        }
        else {
            llong ans = tree.query(L, R);
            cout << ans << "\n";
        }
    }
}