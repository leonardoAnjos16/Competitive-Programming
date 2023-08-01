#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct MergeSortTree {
private:
    int n;
    vector<int> a;
    vector<vector<int>> tree;

public:
    MergeSortTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r, int v) {
        return query(1, 1, n, l, r, v);
    }

private:
    void merge(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i = 0, j = 0, k = 0;
        int nb = b.size(), nc = c.size();

        a.resize(nb + nc);
        while (j < nb || k < nc) {
            if (j >= nb) a[i++] = c[k++];
            else if (k >= nc) a[i++] = b[j++];
            else if (b[j] <= c[k]) a[i++] = b[j++];
            else a[i++] = c[k++];
        }
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = vector<int>(1, a[l]);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            merge(tree[node], tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr, int v) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) {
            auto it = lower_bound(tree[node].begin(), tree[node].end(), v);
            return tree[node].end() - it;
        }

        int m = (l + r) / 2;
        return query(2 * node, l, m, ql, qr, v) + query(2 * node + 1, m + 1, r, ql, qr, v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Y, N;
    cin >> Y >> N;

    vector<int> x(Y + 1);
    for (int i = 1; i <= Y; i++)
        cin >> x[i];

    MergeSortTree tree(Y, x);
    while (N--) {
        int a, p, f;
        cin >> a >> p >> f;

        if (p <= x[a] || !f) cout << "0\n";
        else {
            int ans = tree.query(a + 1, a + f, p);
            cout << ans << "\n";
        }
    }
}