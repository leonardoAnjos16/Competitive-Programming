#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int N;
    string S;
    vector<bool> changed;
    vector<int> tree, lazy;

public:
    SegmentTree(int N, string S) {
        this->N = N;
        this->S = S;

        changed.assign(4 * N, false);
        tree.assign(4 * N, 0);
        lazy.resize(4 * N);

        build(1, 1, N);
    }

    void update(int l, int r, int v) {
        update(1, 1, N, l, r, v);
    }

    int query(int l, int r) {
        return query(1, 1, N, l, r);
    }

private:
    void update_tree(int i) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    void update_lazy(int i, int l, int r, int v) {
        if (l == r) tree[i] = v >= 0 ? v : 1 - tree[i];
        else if (v >= 0 || !changed[i]) {
            lazy[i] = v;
            changed[i] = true;

            if (!v) tree[i] = 0;
            else if (v > 0) tree[i] = r - l + 1;
            else tree[i] = r - l - tree[i] + 1;
        } else if (lazy[i] >= 0) {
            lazy[i] = 1 - lazy[i];
            tree[i] = lazy[i] ? r - l + 1 : 0;
        } else {
            changed[i] = false;
            tree[i] = r - l - tree[i] + 1;
        }
    }

    void build(int i, int l, int r) {
        if (l == r) tree[i] = S[l] == '1';
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            update_tree(i);
        }
    }

    void update(int i, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;

        if (ul <= l && r <= ur) update_lazy(i, l, r, v);
        else {
            int m = (l + r) / 2;
            if (changed[i]) {
                changed[i] = false;
                update_lazy(2 * i, l, m, lazy[i]);
                update_lazy(2 * i + 1, m + 1, r, lazy[i]);
            }

            update(2 * i, l, m, ul, ur, v);
            update(2 * i + 1, m + 1, r, ul, ur, v);
            update_tree(i);
        }
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[i];

        int m = (l + r) / 2;
        if (changed[i]) {
            changed[i] = false;
            update_lazy(2 * i, l, m, lazy[i]);
            update_lazy(2 * i + 1, m + 1, r, lazy[i]);
        }

        return query(2 * i, l, m, ql, qr) + query(2 * i + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ":\n";

        int M; cin >> M;

        string S = ".";
        while (M--) {
            int num_concat; cin >> num_concat;
            string concat; cin >> concat;
            while (num_concat--) S += concat;
        }

        int N = S.size() - 1;
        SegmentTree tree(N, S);

        int Q; cin >> Q;
        int num_query = 1;

        while (Q--) {
            char op; int a, b;
            cin >> op >> a >> b;

            if (op == 'F') tree.update(a + 1, b + 1, 1);
            else if (op == 'E') tree.update(a + 1, b + 1, 0);
            else if (op == 'I') tree.update(a + 1, b + 1, -1);
            else cout << "Q" << num_query++ << ": " << tree.query(a + 1, b + 1) << "\n";
        }
    }
}