#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int n;
vector<vector<pair<int, int>>> g;
vector<vector<llong>> dist;

void get_dists(int s) {
    vector<vector<bool>> vis(2, vector<bool>(n, false));
    dist.emplace_back(n, 0LL);
    dist.emplace_back(n, INF);
    dist[1][s] = 0LL;

    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++)
        for (auto [v, _]: g[i])
            deg[v]++;

    stack<int> slow;
    slow.push(s);

    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> fast;
    for (int i = 0; i < n; i++)
        fast.emplace(dist[1][i], i);

    while (!slow.empty() || !fast.empty()) {
        int idx = -1, v = -1;
        if (!slow.empty()) {
            idx = 0;
            v = slow.top();
            slow.pop();
        } else {
            idx = 1;
            v = fast.top().second;
            fast.pop();
        }

        if (vis[idx][v]) continue;
        vis[idx][v] = true;

        for (auto [u, w]: g[v]) {
            llong ndist = dist[idx][v] + w;
            if (idx == 1 && ndist > dist[0][u]) dist[0][u] = min(ndist, INF);
            else if (!idx && ndist < dist[1][u]) {
                dist[1][u] = ndist;
                fast.emplace(ndist, u);
            }
        }

        if (idx == 1)
            for (auto [u, _]: g[v])
                if (--deg[u] == 0)
                    slow.push(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s, t;
    cin >> n >> m >> s >> t;

    g.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[b].emplace_back(a, w);
    }

    get_dists(t);

    llong ans = dist[0][s];
    if (ans >= INF) cout << "infinity\n";
    else cout << ans << "\n";
}