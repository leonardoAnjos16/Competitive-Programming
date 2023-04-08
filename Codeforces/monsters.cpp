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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<vector<int>> g(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }

        bool possible = false;
        vector<bool> vis(n, false);

        for (int i = 0; i < n && !possible; i++)
            if (!vis[i] && !a[i]) {
                vis[i] = true;
                set<int> reachable = { i };

                set<pair<int, int>> neighbors;
                for (int v: g[i])
                    neighbors.emplace(a[v], v);

                while (!neighbors.empty() && neighbors.begin()->first <= (int) reachable.size()) {
                    int v = neighbors.begin()->second;
                    neighbors.erase(neighbors.begin());

                    reachable.insert(v);
                    vis[v] = true;

                    for (int u: g[v])
                        if (!reachable.count(u))
                            neighbors.emplace(a[u], u);
                }

                possible = (int) reachable.size() >= n;
            }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}