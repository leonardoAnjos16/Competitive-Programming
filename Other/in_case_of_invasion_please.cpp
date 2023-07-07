#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

vector<llong> get_dists(vector<vector<pair<int, int>>> &g, int s) {
    vector<bool> vis(g.size(), false);
    vector<llong> dist(g.size(), INF);
    dist[s] = 0LL;

    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> heap;
    heap.emplace(0LL, s);

    while (!heap.empty()) {
        int v = heap.top().second; heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, w]: g[v])
            if (!vis[u] && dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                heap.emplace(dist[u], u);
            }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    cin >> n >> m >> s;

    llong sum = 0LL;
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }

    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u - 1].emplace_back(v - 1, w);
        g[v - 1].emplace_back(u - 1, w);
    }

    vector<int> c(s);
    vector<vector<llong>> dists(s);

    for (int i = 0; i < s; i++) {
        int shelter;
        cin >> shelter >> c[i];
        dists[i] = get_dists(g, shelter - 1);
    }

    llong l = 0LL, r = INF, ans = -1LL;
    while (l <= r) {
        llong mid = (l + r) / 2;

        vector<llong> groups(1 << s, 0LL);
        for (int i = 0; i < n; i++) {
            int group = 0;
            for (int j = 0; j < s; j++)
                if (dists[j][i] <= mid)
                    group |= 1 << j;

            groups[group] += p[i];
        }

        vector<llong> sos(1 << s, 0LL);
        for (int i = 0; i < (1 << s); i++)
            sos[i] = groups[i];

        for (int i = 0; i < s; i++)
            for (int j = 0; j < (1 << s); j++)
                if (j & (1 << i))
                    sos[j] += sos[j ^ (1 << i)];

        llong min_cut = INF;
        for (int i = 0; i < (1 << s); i++) {
            llong cut = sum - sos[~i & ((1 << s) - 1)];
            for (int j = 0; j < s; j++)
                if (!(i & (1 << j)))
                    cut += c[j];

            min_cut = min(min_cut, cut);
        }

        if (min_cut < sum) l = mid + 1LL;
        else r = mid - 1LL, ans = mid;
    }

    cout << ans << "\n";
}