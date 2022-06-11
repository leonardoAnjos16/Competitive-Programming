#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18 + 5;

int N;
vector<vector<pair<int, int>>> g;

long get_dist(int mx) {
    vector<bool> vis(N, false);
    vector<long> dists(N, INF);
    dists[0] = 0LL;

    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> heap;
    heap.emplace(0LL, 0);

    while (!heap.empty()) {
        int v = heap.top().second; heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, w]: g[v])
            if (!vis[u] && w <= mx && dists[v] + w < dists[u]) {
                dists[u] = dists[v] + w;
                heap.emplace(dists[u], u);
            }
    }

    return dists[N - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, X;
    cin >> N >> M >> X;

    int l = INT_MAX, r = INT_MIN;
    g.assign(N, vector<pair<int, int>>());

    for (int i = 0; i < M; i++) {
        int C1, C2, T;
        cin >> C1 >> C2 >> T;

        l = min(l, T);
        r = max(r, T);

        g[C1 - 1].emplace_back(C2 - 1, T);
        g[C2 - 1].emplace_back(C1 - 1, T);
    }


    int ans = -1;
    long best = get_dist(r);

    while (l <= r) {
        int mid = (l + r) / 2;

        long dist = get_dist(mid);
        // dist <= best + X * best / 100
        // dist <= (100 + X) * best / 100
        // dist * 100 <= 100 + X * best
        if (dist == INF || dist * 100LL > best * (100LL + X)) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}