#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18;

struct SegmentTree {
private:
    int n;
    vector<long> a;
    vector<long> tree, lazy;

public:
    SegmentTree(int n, vector<long> &a) {
        this->n = n;
        this->a = a;

        tree.assign(4 * n, 0LL);
        lazy.assign(4 * n, 0LL);

        build(1, 1, n);
    }

    void update(int l, int r, long v) {
        update(1, 1, n, l, r, v);
    }

    long query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update_lazy(int i, int l, int r, long v) {
        tree[i] += v;
        if (l < r)
            lazy[i] += v;
    }

    void build(int i, int l, int r) {
        if (l == r) tree[i] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int i, int l, int r, int ul, int ur, long v) {
        if (r < ul || l > ur) return;

        if (ul <= l && r <= ur) update_lazy(i, l, r, v);
        else {
            int m = (l + r) / 2;
            if (lazy[i]) {
                update_lazy(2 * i, l, m, lazy[i]);
                update_lazy(2 * i + 1, m + 1, r, lazy[i]);
                lazy[i] = 0LL;
            }

            update(2 * i, l, m, ul, ur, v);
            update(2 * i + 1, m + 1, r, ul, ur, v);
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    long query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INF;
        if (ql <= l && r <= qr) return tree[i];

        int m = (l + r) / 2;
        if (lazy[i]) {
            update_lazy(2 * i, l, m, lazy[i]);
            update_lazy(2 * i + 1, m + 1, r, lazy[i]);
            lazy[i] = 0LL;
        }

        return min(query(2 * i, l, m, ql, qr), query(2 * i + 1, m + 1, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int m; cin >> m;
    cin.ignore();

    SegmentTree tree(n, a);
    while (m--) {
        string s;
        getline(cin, s);
        stringstream ss(s);

        string number;
        vector<long> numbers;

        while (ss >> number)
            numbers.push_back(stoi(number));

        if ((int) numbers.size() == 2) {
            long ans = INF;
            if (numbers[0] <= numbers[1])
                ans = tree.query(numbers[0] + 1, numbers[1] + 1);
            else {
                ans = tree.query(numbers[0] + 1, n);
                ans = min(ans, tree.query(1, numbers[1] + 1));
            }

            cout << ans << "\n";
        } else {
            if (numbers[0] <= numbers[1])
                tree.update(numbers[0] + 1, numbers[1] + 1, numbers[2]);
            else {
                tree.update(numbers[0] + 1, n, numbers[2]);
                tree.update(1, numbers[1] + 1, numbers[2]);
            }
        }
    }
}