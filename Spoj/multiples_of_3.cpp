#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> lazy;
    vector<array<int, 3>> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        lazy.assign(4 * n, 0);
        tree.assign(4 * n, array<int, 3>());
        build(1, 1, n);
    }

    void update(int l, int r) {
        update(1, 1, n, l, r);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r)[0];
    }

private:
    array<int, 3> merge(array<int, 3> left, array<int, 3> right) {
        array<int, 3> ans;
        for (int i = 0; i < 3; i++)
            ans[i] = left[i] + right[i];

        return ans;
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = array<int, 3>({ 1, 0, 0 });
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update_lazy(int node, int l, int r, int v) {
        array<int, 3> aux;
        for (int i = 0; i < 3; i++)
            aux[(i + v) % 3] = tree[node][i];

        
        tree[node] = aux;
        lazy[node] += v;
    }

    void push_down(int node, int l, int r) {
        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ul, int ur) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_lazy(node, l, r, 1);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur);
        update(2 * node + 1, m + 1, r, ul, ur);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    array<int, 3> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return array<int, 3>();
        if (ql <= l && r <= qr) return tree[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        array<int, 3> left = query(2 * node, l, m, ql, qr);
        array<int, 3> right = query(2 * node + 1, m + 1, r, ql, qr);
        return merge(left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    SegmentTree tree(N);
    while (Q--) {
        int op, A, B;
        cin >> op >> A >> B;

        if (!op) tree.update(A + 1, B + 1);
        else {
            int ans = tree.query(A + 1, B + 1);
            cout << ans << "\n";
        }
    }
}