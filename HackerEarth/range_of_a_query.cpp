#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<tuple<long, int, int>> tree;

public:
    SegmentTree(vector<int> &a) {
        this->a = a;
        this->n = a.size();
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    long query(int l, int r) {
        return get<0>(query(1, 1, n, l, r));
    }

private:
    void build(int i, int l, int r) {
        if (l == r) tree[i] = make_tuple(a[l - 1], 1, 1);
        else {
            int mid = (l + r) / 2;
            build(2 * i, l, mid);
            build(2 * i + 1, mid + 1, r);

            long ml, mr; int pl, sl, pr, sr;
            tie(ml, pl, sl) = tree[2 * i];
            tie(mr, pr, sr) = tree[2 * i + 1];

            long m = max(ml, mr);
            int p = pl, s = sr;

            if (a[mid - 1] == a[mid]) {
                m = max(m, sum(a[mid - 1], sl + pr));
                if (sl == mid - l + 1) p = sl + pr;
                if (pr == r - mid) s = sl + pr;
            }

            tree[i] = make_tuple(m, p, s);
        }
    }

    void update(int i, int l, int r, int j, int v) {
        if (l == r) a[l - 1] = v, tree[i] = make_tuple(v, 1, 1);
        else {
            int mid = (l + r) / 2;
            if (j <= mid) update(2 * i, l, mid, j, v);
            else update(2 * i + 1, mid + 1, r, j, v);

            long ml, mr; int pl, sl, pr, sr;
            tie(ml, pl, sl) = tree[2 * i];
            tie(mr, pr, sr) = tree[2 * i + 1];

            long m = max(ml, mr);
            int p = pl, s = sr;

            if (a[mid - 1] == a[mid]) {
                m = max(m, sum(a[mid - 1], sl + pr));
                if (sl == mid - l + 1) p = sl + pr;
                if (pr == r - mid) s = sl + pr;
            }

            tree[i] = make_tuple(m, p, s);
        }
    }

    tuple<long, int, int> query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[i];

        int mid = (l + r) / 2;
        if (qr <= mid) return query(2 * i, l, mid, ql, qr);
        if (ql > mid) return query(2 * i + 1, mid + 1, r, ql, qr);

        long ml, mr; int pl, sl, pr, sr;
        tie(ml, pl, sl) = query(2 * i, l, mid, ql, qr);
        tie(mr, pr, sr) = query(2 * i + 1, mid + 1, r, ql, qr);

        long m = max(ml, mr);
        int p = pl, s = sr;

        if (a[mid - 1] == a[mid]) {
            m = max(m, sum(a[mid - 1], sl + pr));
            if (sl == mid - l + 1) p = sl + pr;
            if (pr == r - mid) s = sl + pr;
        }

        return make_tuple(m, p, s);
    }

    long sum(int v, int size) {
        long ans = v * (v + 1LL) / 2LL;
        if (size < v) {
            long diff = v - size;
            ans -= diff * (diff + 1) / 2;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    SegmentTree tree(A);
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int L, R;
            cin >> L >> R;

            long ans = tree.query(L, R);
            cout << ans << " ";
        } else {
            int X, V;
            cin >> X >> V;
            tree.update(X, V);
        }
    }
}