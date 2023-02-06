#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;
const llong INF = 1e18 + 5;

int n;
vector<vector<pair<int, int>>> g;
vector<int> ways, mn, mx;
vector<llong> dists;

void get_dists() {
    ways.assign(n, 0);
    mn.assign(n, INT_MAX);
    mx.assign(n, INT_MIN);
    dists.assign(n, INF);

    ways[0] = 1;
    dists[0] = 0LL;
    mn[0] = mx[0] = 0;

    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> heap;
    heap.emplace(0LL, 0);

    while (!heap.empty()) {
        auto [dist, v] = heap.top(); heap.pop();
        if (dist > dists[v]) continue;

        for (auto [u, w]: g[v]) {
            if (dist + w < dists[u]) {
                ways[u] = ways[v];
                mn[u] = mn[v] + 1;
                mx[u] = mx[v] + 1;
                dists[u] = dist + w;
                heap.emplace(dists[u], u);
            } else if (dist + w == dists[u]) {
                ways[u] = (ways[u] + ways[v]) % MOD;
                mn[u] = min(mn[u], mn[v] + 1);
                mx[u] = max(mx[u], mx[v] + 1);
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

    cout << dists[n - 1] << " " << ways[n - 1] << " " << mn[n - 1] << " " << mx[n - 1] << "\n";
}