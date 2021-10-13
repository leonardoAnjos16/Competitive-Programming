#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<set<int>> tree(n, set<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].insert(v - 1);
            tree[v - 1].insert(u - 1);
        }

        set<int> leaves;
        vector<int> deg(n);

        for (int i = 0; i < n; i++) {
            deg[i] = tree[i].size();
            if (deg[i] <= 1)
                leaves.insert(i);
        }

        int ans = n;
        vector<bool> removed(n, false);

        while (k-- && ans) {
            set<int> new_leaves;
            for (auto v: leaves) {
                ans--;
                removed[v] = true;

                for (auto u: tree[v])
                    if (!removed[u] && --deg[u] <= 1)
                        new_leaves.insert(u);
            }

            leaves = new_leaves;
        }

        cout << ans << "\n";
    }
}