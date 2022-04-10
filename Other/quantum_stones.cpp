#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18 + 5;

int n, k;
vector<vector<pair<int, int>>> g;
vector<vector<long>> dists;

void get_dists(int start) {
    vector<vector<bool>> vis(n, vector<bool>(k + 1, false));
    dists.assign(n, vector<long>(k + 1, INF));
    dists[start][0] = 0LL;

    priority_queue<tuple<long, int, int>, vector<tuple<long, int, int>>, greater<tuple<long, int, int>>> heap;
    heap.emplace(0LL, start, 0);

    while (!heap.empty()) {
        auto [dist, v, changed] = heap.top(); heap.pop();
        if (vis[v][changed]) continue;
        vis[v][changed] = true;

        for (auto [u, w]: g[v]) {
            if (!vis[u][changed] && dists[v][changed] + w < dists[u][changed]) {
                dists[u][changed] = dists[v][changed] + w;
                heap.emplace(dists[u][changed], u, changed);
            }

            if (changed + 1 <= k && !vis[u][changed + 1]) {
                int weight = w;
                for (int i = 2; i * i <= weight; i++) {
                    if (weight % i == 0 && dists[v][changed] + w / i + 2LL * i < dists[u][changed + 1]) {
                        dists[u][changed + 1] = dists[v][changed] + w / i + 2LL * i;
                        heap.emplace(dists[u][changed + 1], u, changed + 1);
                    }

                    while (weight % i == 0) weight /= i;
                }

                if (weight > 1 && dists[v][changed] + w / weight + 2LL * weight < dists[u][changed + 1]) {
                    dists[u][changed + 1] = dists[v][changed] + w / weight + 2LL * weight;
                    heap.emplace(dists[u][changed + 1], u, changed + 1);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int m;
        cin >> n >> m >> k;

        g.assign(n, vector<pair<int, int>>());
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;

            g[u - 1].emplace_back(v - 1, w);
            g[v - 1].emplace_back(u - 1, w);
        }

        int S, E;
        cin >> S >> E;

        get_dists(S - 1);

        long ans = INF;
        for (int i = 0; i <= k; i++)
            ans = min(ans, dists[E - 1][i]);

        cout << (ans >= INF ? -1LL : ans) << "\n";
    }
}