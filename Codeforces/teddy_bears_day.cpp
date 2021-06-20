#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<pair<int, int>> cities;
vector<vector<pair<int, long>>> g;

tuple<int, int, long> solve(int u = 0, int v = 0) {
    int sent = cities[u].first, received = cities[u].second; long cost = 0LL;
    for (auto p: g[u]) {
        int x = p.first;
        long w = p.second;

        if (x != v) {
            int s, r; long c;
            tie(s, r, c) = solve(x, u);

            sent += s;
            received += r;
            cost += c + (s + r) * w;
        }
    }

    int mn = min(sent, received);
    sent -= mn; received -= mn;

    return make_tuple(sent, received, cost);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cities.assign(n, make_pair(0, 0));
        g.assign(n, vector<pair<int, long>>());

        for (int i = 1; i < n; i++) {
            int u, v; long w;
            cin >> u >> v >> w;

            g[u - 1].emplace_back(v - 1, w);
            g[v - 1].emplace_back(u - 1, w);
        }

        int q; cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;

            cities[u - 1].first++;
            cities[v - 1].second++;
        }

        int sent, received; long cost;
        tie(sent, received, cost) = solve();

        cout << cost << "\n";
    }
}