#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            g[v - 1].emplace_back(u - 1, i);
            g[u - 1].emplace_back(v - 1, i);
        }

        bool found = false;
        vector<int> ans(m, 1);

        for (int i = 0; i < n && !found; i++)
            if ((int) g[i].size() + 1 < n) {
                found = true;
                for (auto [v, idx]: g[i])
                    ans[idx] = 2;
            }

        if (!found) {
            ans[g[0][0].second] = 2;
            for (int i = 1; i + 1 < n; i++)
                ans[g[0][i].second] = 3;
        }

        cout << (found ? 2 : 3) << "\n";
        for (int i = 0; i < m; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}