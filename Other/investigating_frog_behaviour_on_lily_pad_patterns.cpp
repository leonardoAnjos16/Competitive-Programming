#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e6 + 5;

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void add(int i, int v) {
        if (!i) tree[i] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    int sum(int i) {
        if (i < 0) return 0;

        int ans = tree[0];
        while (i) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> x(n);
    FenwickTree tree(MAX);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        tree.add(x[i], 1);
    }

    int q; cin >> q;
    while (q--) {
        int i; cin >> i;
        int pos = x[i - 1];

        int l = pos + 1, r = MAX - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (tree.sum(pos, mid) >= mid - pos + 1) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        tree.add(pos, -1);
        tree.add(ans, 1);
        x[i - 1] = ans;

        assert(ans != -1);
        cout << ans << "\n";
    }
}