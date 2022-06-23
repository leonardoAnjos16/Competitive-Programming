#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 55;
const int INF = 1e9 + 5;

int n;
vector<vector<pair<int, int>>> g;
vector<vector<int>> dists;

int cost(int wab, int wbc) {
    return !wab ? wbc * wbc : 2 * wab * wbc + wbc * wbc;
}

void get_dists() {
    vector<vector<bool>> vis(MAX, vector<bool>(n, false));
    dists.assign(MAX, vector<int>(n, INF));
    dists[0][0] = 0;

    using Node = pair<int, pair<int, int>>;
    priority_queue<Node, vector<Node>, greater<Node>> heap;
    heap.emplace(0, make_pair(0, 0));

    while (!heap.empty()) {
        auto [wab, v] = heap.top().second; heap.pop();
        if (vis[wab][v]) continue;
        vis[wab][v] = true;

        for (auto [u, wbc]: g[v]) {
            int w = wab ? 0 : wbc;
            if (!vis[w][u] && dists[wab][v] + cost(wab, wbc) < dists[w][u]) {
                dists[w][u] = dists[wab][v] + cost(wab, wbc);
                heap.emplace(dists[w][u], make_pair(w, u));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    g.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u - 1].emplace_back(v - 1, w);
        g[v - 1].emplace_back(u - 1, w);
    }

    get_dists();

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << (dists[0][i] >= INF ? -1 : dists[0][i]);
    }

    cout << "\n";
}