#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int n;
vector<vector<int>> g;
vector<int> c, deg;
vector<llong> nc;

void get_costs() {
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!deg[i]) q.push(i);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u: g[v]) {
            nc[u] += min(1LL * c[v], nc[v]);
            if (--deg[u] == 0) q.push(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;

        c.resize(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];

        for (int i = 0; i < k; i++) {
            int p; cin >> p;
            c[p - 1] = 0;
        }

        nc.assign(n, 0);
        deg.assign(n, 0);
        g.assign(n, vector<int>());

        for (int i = 0; i < n; i++) {
            int m; cin >> m;

            deg[i] += m;
            if (!m) nc[i] = INF;

            while (m--) {
                int e; cin >> e;
                g[e - 1].push_back(i);
            }
        }

        get_costs();

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << min(1LL * c[i], nc[i]);
        }

        cout << "\n";
    }
}