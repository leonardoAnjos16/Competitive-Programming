#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int n, k;
vector<vector<pair<int, int>>> g;
vector<vector<llong>> dists;

void get_dists() {
    vector<int> vis(n, 0);
    dists.assign(n, vector<llong>(k, INF));
    dists[0][0] = 0LL;

    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> heap;
    heap.emplace(0LL, 0);

    while (!heap.empty()) {
        auto [dist, v] = heap.top(); heap.pop();
        if (vis[v] >= k) continue;
        dists[v][vis[v]++] = dist;

        for (auto [u, w]: g[v])
            if (vis[u] < k)
                heap.emplace(dist + w, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m >> k;

    g.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].emplace_back(b - 1, c);
    }

    get_dists();

    for (int i = 0; i < k; i++) {
        if (i) cout << " ";
        cout << dists[n - 1][i];
    }

    cout << "\n";
}