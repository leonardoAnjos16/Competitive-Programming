#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int N, K;
vector<bool> pine;
vector<vector<pair<int, int>>> g;
vector<llong> dists;

void get_dists() {
    vector<bool> vis(N, false);
    dists.assign(N, INF);
    dists[0] = 0LL;

    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> heap;
    heap.emplace(0LL, 0);

    while (!heap.empty()) {
        auto [d, v] = heap.top(); heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, w]: g[v])
            if (!vis[u] && dists[v] + w + (pine[v] ? K : 0) < dists[u]) {
                dists[u] = dists[v] + w + (pine[v] ? K : 0);
                heap.emplace(dists[u], u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, P; llong T;
    cin >> N >> M >> T >> K >> P;
    T *= 60LL;

    pine.assign(N, false);
    for (int i = 0; i < P; i++) {
        int p; cin >> p;
        pine[p - 1] = true;
    }

    g.assign(N, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x - 1].emplace_back(y - 1, w * 60);
    }

    get_dists();

    llong ans = dists[N - 1];
    if (ans > T) cout << "-1\n";
    else cout << ans << "\n";
}