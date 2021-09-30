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

    void add(int i, int v) {
        if (!i) tree[0] += v;
        else {
            while (i < n) {
                tree[i] += v;
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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n), sorted(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sorted[i] = a[i];
        }

        sort(sorted.begin(), sorted.end());

        long ans = 0LL;
        FenwickTree tree(n);

        for (int i = 0; i < n; i++) {
            int idx = upper_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
            int back = tree.sum(idx, n);

            idx = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
            int front = tree.sum(0, idx - 1);

            ans += min(front, back);
            tree.add(idx, 1);
        }

        cout << ans << "\n";
    }
}