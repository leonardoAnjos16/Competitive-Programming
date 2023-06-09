#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

int n;
vector<int> p;
vector<vector<pair<int, int>>> g;
vector<vector<int>> dist;

int get_dist(int s, int e, int c) {
    dist.assign(n, vector<int>(c + 1, INF));
    dist[s][0] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    heap.emplace(0, s, 0);

    while (!heap.empty()) {
        auto [d, v, fuel] = heap.top(); heap.pop();
        if (d > dist[v][fuel]) continue;
        if (v == e) return d;

        if (fuel < c && dist[v][fuel] + p[v] < dist[v][fuel + 1]) {
            dist[v][fuel + 1] = dist[v][fuel] + p[v];
            heap.emplace(dist[v][fuel + 1], v, fuel + 1);
        }

        for (auto [u, w]: g[v])
            if (fuel >= w && dist[v][fuel] < dist[u][fuel - w]) {
                dist[u][fuel - w] = dist[v][fuel];
                heap.emplace(dist[u][fuel - w], u, fuel - w);
            }
    }

    return INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    p.resize(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    g.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }

    int q; cin >> q;
    while (q--) {
        int c, s, e;
        cin >> c >> s >> e;

        int ans = get_dist(s, e, c);
        if (ans >= INF) cout << "impossible\n";
        else cout << ans << "\n";
    }
}