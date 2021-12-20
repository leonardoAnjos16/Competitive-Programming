#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e8 + 5;

int n;
vector<vector<pair<int, int>>> g;
vector<int> dist;

void get_dist() {
    vector<bool> vis(n, false);
    dist.assign(n, INF);
    dist[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.emplace(0, 0);

    while (!heap.empty()) {
        int v = heap.top().second;
        heap.pop();

        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, w]: g[v])
            if (!vis[u] && dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                heap.emplace(dist[u], u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, m;
    cin >> n >> k >> m;
    n++;

    vector<int> houses(k);
    for (int i = 0; i < k; i++)
        cin >> houses[i];

    g.assign(n, vector<pair<int, int>>());
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;

        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    get_dist();

    int sum = 0, mx = -INF;
    for (auto house: houses) {
        sum += dist[house];
        mx = max(mx, dist[house]);
    }

    sum *= 2; mx *= 2;
    cout << sum << " " << mx << "\n";
}