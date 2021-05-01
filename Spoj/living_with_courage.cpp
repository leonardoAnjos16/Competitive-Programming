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

const int MAX = 2e5 + 5;

struct SegmentTree {
private:
    vi a; int n;
    vector<pll> tree;

public:
    SegmentTree(vi &a) {
        this->a = a;
        this->n = size(a);
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void add(int i, int x) {
        add(i, x, 1, 1, n);
    }

    pll query(int l, int r) {
        return query(l, r, 1, 1, n);
    }

private:
    void build(int i, int l, int r) {
        if (l == r) tree[i] = { a[l - 1], a[l - 1] };
        else {
            int mid = (l + r) / 2;
            int lc = 2 * i, rc = lc + 1;

            build(lc, l, mid);
            build(rc, mid + 1, r);

            tree[i] = { min(tree[lc].fst, tree[rc].fst), tree[lc].snd + tree[rc].snd };
        }
    }

    void add(int j, int x, int i, int l, int r) {
        if (l == r) tree[i] = { tree[i].fst + x, tree[i].fst + x };
        else {
            int mid = (l + r) / 2;
            int lc = 2 * i, rc = lc + 1;

            if (j <= mid) add(j, x, lc, l, mid);
            else add(j, x, rc, mid + 1, r);

            tree[i] = { min(tree[lc].fst, tree[rc].fst), tree[lc].snd + tree[rc].snd };
        }
    }

    pll query(int ql, int qr, int i, int l, int r) {
        if (ql <= l && r <= qr) return tree[i];

        int mid = (l + r) / 2;
        int lc = 2 * i, rc = lc + 1;

        if (qr <= mid) return query(ql, qr, lc, l, mid);
        if (ql > mid) return query(ql, qr, rc, mid + 1, r);

        pll left = query(ql, qr, lc, l, mid);
        pll right = query(ql, qr, rc, mid + 1, r);
        return { min(left.fst, right.fst), left.snd + right.snd };
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int p; cin >> p;
    SegmentTree tree(a);

    while (p--) {
        string op; cin >> op;
        if (op == "EAT") {
            long x; int y;
            cin >> x >> y;
            tree.add(y + 1, -x);
        } else if (op == "GROW") {
            long x; int y;
            cin >> x >> y;
            tree.add(y + 1, x);
        } else {
            int l, r;
            cin >> l >> r;

            pll aux = tree.query(l + 1, r + 1);
            long ans = aux.snd - aux.fst;
            cout << ans << "\n";
        }
    }
}