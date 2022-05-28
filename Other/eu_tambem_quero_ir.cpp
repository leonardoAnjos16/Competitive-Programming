#include <bits/stdc++.h>

using namespace std;

#define long long long int

long cost(int n, vector<vector<pair<int, int>>> &g) {
    vector<bool> vis(n, false);
    vector<int> costs(n, -1);
    costs[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.emplace(0, 0);

    while (!heap.empty()) {
        auto [c, v] = heap.top(); heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, w]: g[v])
            if (!vis[u] && (costs[u] == -1 || w < costs[u])) {
                costs[u] = w;
                heap.emplace(w, u);
            }
    }

    long ans = 0LL;
    for (int i = 0; i < n; i++) {
        if (costs[i] == -1) return -1LL;
        ans += costs[i];
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; long x;
    cin >> n >> m >> x;

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = make_tuple(u, v, c);
    }

    int l = 1, r = m, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        vector<vector<pair<int, int>>> g(n + 1, vector<pair<int, int>>());
        for (int i = 0; i < mid; i++) {
            auto [u, v, c] = edges[i];
            g[u].emplace_back(v, c);
            g[v].emplace_back(u, c);
        }

        long aux = cost(n + 1, g);
        if (aux == -1 || aux > x) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}