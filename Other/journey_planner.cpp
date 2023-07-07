#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> g, rg;
vector<int> vis, reach;

int edges(int v, int t) {
    vis[v] = t;
    reach[v]++;

    int ans = 0;
    for (int u: rg[v])
        if (vis[u] < t)
            ans += edges(u, t) + 1;

    return ans;
}

int reachable(int v, int t) {
    vis[v] = t;

    int ans = 1;
    for (int u: g[v])
        if (vis[u] < t)
            ans += reachable(u, t);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);

    int n;
    while (cin >> n, n) {
        int m; cin >> m;

        g.assign(n, vector<int>());
        rg.assign(n, vector<int>());

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;

            g[x - 1].push_back(y - 1);
            rg[y - 1].push_back(x - 1);
        }

        vector<int> vertices(n);
        iota(vertices.begin(), vertices.end(), 0);

        mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
        shuffle(vertices.begin(), vertices.end(), rng);

        vis.assign(n, 0);
        reach.assign(n, 0);
        int t = 1, total = 0;

        for (int i = 0; i < n && total < 50 * n; i++)
            total += edges(vertices[i], t++);

        int v = 0;
        for (int i = 1; i < n; i++)
            if (reach[i] > reach[v])
                v = i;

        int d = reachable(v++, t);
        cout << v << " " << d << "\n";
    }
}