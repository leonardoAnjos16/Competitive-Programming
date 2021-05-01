#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 17;

struct SegmentTree {
private:
    vi a; int n;
    vector<pii> tree;

public:
    SegmentTree(vi &a, int n) {
        this->a = a;
        this->n = n;

        tree.resize(n << 2);
        build(1, 1, n);
    }

    void update(int i, int x) {
        update(1, 1, n, i, x);
    }

    pii query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int i, int l, int r) {
        if (l == r) tree[i] = { a[l - 1], a[l - 1] };
        else {
            int m = (l + r) / 2;
            int lc = 2 * i, rc = 2 * i + 1;

            build(lc, l, m);
            build(rc, m + 1, r);

            tree[i] = { tree[lc].snd | tree[rc].snd, tree[lc].fst ^ tree[rc].fst };
        }
    }

    void update(int i, int l, int r, int j, int x) {
        if (l == r) tree[i] = { x, x };
        else {
            int m = (l + r) / 2;
            int lc = 2 * i, rc = 2 * i + 1;

            if (j <= m) update(lc, l, m, j, x);
            else update(rc, m + 1, r, j, x);

            tree[i] = { tree[lc].snd | tree[rc].snd, tree[lc].fst ^ tree[rc].fst };
        }
    }

    pii query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[i];

        int m = (l + 2) / 2;
        int lc = 2 * i, rc = 2 * i + 1;

        if (qr <= m) return query(lc, l, m, ql, qr);
        else if (ql > m) return query(rc, m + 1, r, ql, qr);
        else {
            pii left = query(lc, l, m, ql, qr);
            pii right = query(rc, m + 1, r, ql, qr);
            return { left.snd | right.snd, left.fst ^ right.fst };
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi a(1 << n);
    for (int i = 0; i < (1 << n); i++)
        cin >> a[i];

    SegmentTree st(a, 1 << n);
    while (m--) {
        int p, b;
        cin >> p >> b;
        st.update(p, b);

        pii ans = st.query(1, (1 << n) + 1);
        if (n & 1) cout << ans.fst << "\n";
        else cout << ans.snd << "\n";
    }
}