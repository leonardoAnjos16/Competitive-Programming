#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e9 + 5;

int n;
vector<vector<pair<int, int>>> g;

int dist(int start, int end, int x) {
    vector<bool> vis(n, false);
    vector<int> dists(n, INF);
    dists[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        int v = heap.top().second; heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        if (v == end) return dists[v] + x;

        for (auto [u, w]: g[v])
            if (!vis[u] && dists[v] + w + x < dists[u]) {
                dists[u] = dists[v] + w + x;
                heap.emplace(dists[u], u);
            }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, q;
    cin >> n >> m >> q;

    g.assign(n, vector<pair<int, int>>());
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].emplace_back(v - 1, w);
    }

    while (q--) {
        int u, v, x;
        cin >> u >> v >> x;

        int ans = dist(u - 1, v - 1, x);
        cout << ans << "\n";
    }
}