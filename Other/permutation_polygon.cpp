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

        int ans = tree[0];
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

    int n; cin >> n;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        int u = i, v = p;
        if (u > v) swap(u, v);
        g[u].push_back(v);
    }

    long ans = 0LL;
    FenwickTree tree(n);

    for (int i = 1; i <= n; i++) {
        sort(g[i].rbegin(), g[i].rend());
        tree.add(i, (int) g[i].size() - 2);

        for (auto j: g[i]) {
            ans += tree.sum(0, j - 1);
            tree.add(j, 1);
        }
    }

    cout << ans << "\n";
}