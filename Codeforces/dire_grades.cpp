#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
private:
    int n;
    vector<long double> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0.0);
    }

    void add(int i, long double v) {
        if (!i) tree[i] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    long double sum(int i, int j) {
        return sum(j) - sum(i - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    long double sum(int i) {
        if (i < 0) return 0.0;

        long double ans = tree[0];
        while (i > 0) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;
    vector<long double> a(n + 1);

    FenwickTree tree(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tree.add(i, a[i]);
    }

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int e; long double v;
            cin >> e >> v;

            tree.add(e, v - a[e]);
            a[e] = v;
        } else {
            int l, r;
            cin >> l >> r;

            long double sum = tree.sum(l, r);
            long double ans = sum / (r - l + 1);

            cout << ans << "\n";
        }
    }
}