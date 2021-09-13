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
        int n, m;
        cin >> n >> m;

        vector<int> a(m);
        vector<int> ordered(m);

        for (int i = 0; i < m; i++) {
            cin >> a[i];
            ordered[i] = a[i];
        }

        sort(ordered.begin(), ordered.end());

        map<int, int> cnt;
        FenwickTree tree(m);

        int ans = 0;
        for (int i = 0; i < m; i++) {
            int pos = upper_bound(ordered.begin(), ordered.end(), a[i]) - ordered.begin() - cnt[a[i]] - 1;
            if (pos) ans += tree.sum(0, pos - 1);
            tree.add(pos, 1); cnt[a[i]]++;
        }

        cout << ans << "\n";
    }
}