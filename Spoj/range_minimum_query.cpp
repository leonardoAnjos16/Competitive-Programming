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
    vi tree;

public:
    SegmentTree(vi &a) {
        this->a = a;
        this->n = size(a);
        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int l, int r) {
        return query(l, r, 1, 1, n);
    }

private:
    void build(int i, int l, int r) {
        if (l == r) tree[i] = a[l - 1];
        else {
            int mid = (l + r) / 2;
            int lc = 2 * i, rc = lc + 1;

            build(lc, l, mid);
            build(rc, mid + 1, r);

            tree[i] = min(tree[lc], tree[rc]);
        }
    }

    int query(int ql, int qr, int i, int l, int r) {
        if (ql <= l && r <= qr) return tree[i];

        int mid = (l + r) / 2;
        int lc = 2 * i, rc = lc + 1;

        if (qr <= mid) return query(ql, qr, lc, l, mid);
        if (ql > mid) return query(ql, qr, rc, mid + 1, r);

        int left = query(ql, qr, lc, l, mid);
        int right = query(ql, qr, rc, mid + 1, r);
        return min(left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int Q; cin >> Q;
    SegmentTree tree(a);

    while (Q--) {
        int i, j;
        cin >> i >> j;

        int ans = tree.query(i + 1, j + 1);
        cout << ans << "\n";
    }
}