#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> g(N, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        g[A - 1].emplace_back(B - 1, C);
        g[B - 1].emplace_back(A - 1, C);
    }

    vector<int> dists(N, -1);
    dists[0] = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto [u, w]: g[v])
            if (dists[u] == -1) {
                q.push(u);
                dists[u] = dists[v] + 1;
            }
    }

    vector<llong> costs(N, INF);
    costs[0] = 0LL;

    for (int i = 0; i < N; i++)
        for (auto [v, w]: g[i])
            if (dists[v] == dists[i] + 1)
                costs[v] = min(costs[v], 1LL * dists[v] * w);

    llong ans = 0LL;
    for (int i = 0; i < N; i++)
        ans += costs[i];

    cout << ans << "\n";
}