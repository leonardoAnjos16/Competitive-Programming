#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void add(int i, int x) {
        if (!i) tree[0] += x;
        else {
            while (i < n) {
                tree[i] += x;
                i += LSO(i);
            }
        }
    }

    int sum(int i, int j) {
        return sum(j) - sum(i - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    int sum(int i) {
        if (i < 0) return 0;

        int sum = tree[0];
        while (i > 0) {
            sum += tree[i];
            i -= LSO(i);
        }

        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        vector<int> uniq;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            uniq.push_back(a[i]);
        }

        sort(uniq.begin(), uniq.end());
        unique(uniq.begin(), uniq.end());

        long ans = 0LL;
        FenwickTree tree((int) uniq.size() + 5);

        for (int i = 0; i < n; i++) {
            if (a[i] < r) {
                int j = lower_bound(uniq.begin(), uniq.end(), l - a[i]) - uniq.begin();
                int k = upper_bound(uniq.begin(), uniq.end(), r - a[i]) - uniq.begin() - 1;
                if (j <= k) ans += tree.sum(j, k);
            }

            int j = lower_bound(uniq.begin(), uniq.end(), a[i]) - uniq.begin();
            tree.add(j, 1);
        }

        cout << ans << "\n";
    }
}