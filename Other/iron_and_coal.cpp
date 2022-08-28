#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e6 + 5;

vector<int> get_dists(int n, vector<vector<int>> &g, vector<int> &sources) {
    queue<int> q;
    vector<int> dists(n, INF);
    vector<bool> vis(n, false);

    for (int source: sources) {
        q.push(source);
        dists[source] = 0;
        vis[source] = true;
    }

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u: g[v])
            if (!vis[u]) {
                q.push(u);
                vis[u] = true;
                dists[u] = dists[v] + 1;
            }
    }

    return dists;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> o(m);
    for (int i = 0; i < m; i++) {
        cin >> o[i];
        o[i]--;
    }

    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        c[i]--;
    }

    vector<vector<int>> g(n, vector<int>()), gr(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        while (a--) {
            int b; cin >> b;
            g[i].push_back(b - 1);
            gr[b - 1].push_back(i);
        }
    }

    vector<int> sources(1, 0);
    vector<int> dists = get_dists(n, g, sources);

    vector<int> odists = get_dists(n, gr, o);
    vector<int> cdists = get_dists(n, gr, c);

    int ans = INF;
    for (int i = 0; i < n; i++)
        if (dists[i] < INF && odists[i] < INF && cdists[i] < INF)
            ans = min(ans, dists[i] + odists[i] + cdists[i]);

    if (ans >= INF) cout << "impossible\n";
    else cout << ans << "\n";
}