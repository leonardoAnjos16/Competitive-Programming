#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

vector<bool> vis;

void get_reachable(int v, vector<vector<int>> &g, vector<bool> &reachable) {
    if (vis[v]) return;

    vis[v] = true;
    reachable[v] = true;

    for (int u: g[v])
        get_reachable(u, g, reachable);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    vector<vector<int>> g(n, vector<int>()), rg(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;

        edges[i] = make_tuple(a - 1, b - 1, x);
        g[a - 1].push_back(b - 1);
        rg[b - 1].push_back(a - 1);
    }

    vector<llong> scores(n, -INF);
    scores[0] = 0LL;

    for (int i = 1; i < n; i++)
        for (auto [u, v, w]: edges)
            scores[v] = max(scores[v], scores[u] + w);

    vis.assign(n, false);
    vector<bool> sreaches(n, false);
    get_reachable(0, g, sreaches);

    vis.assign(n, false);
    vector<bool> treaches(n, false);
    get_reachable(n - 1, rg, treaches);

    for (auto [u, v, w]: edges)
        if (scores[u] + w > scores[v]) {
            scores[v] = scores[u] + w;
            if (sreaches[v] && treaches[v]) {
                cout << "-1\n";
                return 0;
            }
        }

    llong ans = scores[n - 1];
    cout << ans << "\n";
}