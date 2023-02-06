#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int n;
vector<vector<pair<int, int>>> g;
vector<vector<llong>> dists;

void get_dists() {
    vector<vector<bool>> vis(2, vector<bool>(n, false));
    dists.assign(2, vector<llong>(n, INF));
    dists[1][0] = 0LL;

    using t3 = tuple<llong, int, int>;
    priority_queue<t3, vector<t3>, greater<t3>> heap;
    heap.emplace(0, 1, 0);

    while (!heap.empty()) {
        auto [dist, coupons, v] = heap.top(); heap.pop();
        if (vis[coupons][v]) continue;
        vis[coupons][v] = true;

        for (auto [u, w]: g[v]) {
            if (!vis[coupons][u] && dists[coupons][v] + w < dists[coupons][u]) {
                dists[coupons][u] = dists[coupons][v] + w;
                heap.emplace(dists[coupons][u], coupons, u);
            }

            if (coupons && !vis[coupons - 1][u] && dists[coupons][v] + w / 2 < dists[coupons - 1][u]) {
                dists[coupons - 1][u] = dists[coupons][v] + w / 2;
                heap.emplace(dists[coupons - 1][u], coupons - 1, u);
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
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].emplace_back(b - 1, c);
    }

    get_dists();

    assert(dists[0][n - 1] <= dists[1][n - 1]);
    llong ans = dists[0][n - 1];
    cout << ans << "\n";
}