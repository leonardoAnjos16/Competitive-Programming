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
    vector<tuple<int, int, int, int>> tree;

public:
    SegmentTree(vi &a) {
        this->a = a;
        this->n = size(a);
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, int x) {
        update(i, x, 1, 1, n);
    }

    tuple<int, int, int, int> query(int l, int r) {
        return query(l, r, 1, 1, n);
    }

private:
    void build(int i, int l, int r) {
        if (l == r) tree[i] = { a[l - 1], a[l - 1], a[l - 1], a[l - 1] };
        else {
            int mid = (l + r) / 2;
            int lc = 2 * i, rc = lc + 1;

            build(lc, l, mid);
            build(rc, mid + 1, r);

            int prefix = max(get<0>(tree[lc]), get<1>(tree[lc]) + get<0>(tree[rc]));
            int sum = get<1>(tree[lc]) + get<1>(tree[rc]);
            int best = max({ get<2>(tree[lc]), get<2>(tree[rc]), get<3>(tree[lc]) + get<0>(tree[rc]) });
            int suffix = max(get<3>(tree[lc]) + get<1>(tree[rc]), get<3>(tree[rc]));

            tree[i] = { prefix, sum, best, suffix };
        }
    }

    void update(int j, int x, int i, int l, int r) {
        if (l == r) tree[i] = { x, x, x, x };
        else {
            int mid = (l + r) / 2;
            int lc = 2 * i, rc = lc + 1;

            if (j <= mid) update(j, x, lc, l, mid);
            else update(j, x, rc, mid + 1, r);

            int prefix = max(get<0>(tree[lc]), get<1>(tree[lc]) + get<0>(tree[rc]));
            int sum = get<1>(tree[lc]) + get<1>(tree[rc]);
            int best = max({ get<2>(tree[lc]), get<2>(tree[rc]), get<3>(tree[lc]) + get<0>(tree[rc]) });
            int suffix = max(get<3>(tree[lc]) + get<1>(tree[rc]), get<3>(tree[rc]));

            tree[i] = { prefix, sum, best, suffix };
        }
    }

    tuple<int, int, int, int> query(int ql, int qr, int i, int l, int r) {
        if (ql <= l && r <= qr) return tree[i];

        int mid = (l + r) / 2;
        int lc = 2 * i, rc = lc + 1;

        if (qr <= mid) return query(ql, qr, lc, l, mid);
        if (ql > mid) return query(ql, qr, rc, mid + 1, r);

        auto left = query(ql, qr, lc, l, mid);
        auto right = query(ql, qr, rc, mid + 1, r);

        int prefix = max(get<0>(left), get<1>(left) + get<0>(right));
        int sum = get<1>(left) + get<1>(right);
        int best = max({ get<2>(left), get<2>(right), get<3>(left) + get<0>(right) });
        int suffix = max(get<3>(left) + get<1>(right), get<3>(right));

        return { prefix, sum, best, suffix };
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vi A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int M; cin >> M;
    SegmentTree tree(A);

    while (M--) {
        int op, x, y;
        cin >> op >> x >> y;

        if (!op) tree.update(x, y);
        else {
            auto ans = tree.query(x, y);
            cout << get<2>(ans) << "\n";
        }
    }
}