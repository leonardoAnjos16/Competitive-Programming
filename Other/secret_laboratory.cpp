#include <bits/stdc++.h>

using namespace std;

const long long int INF = 1e18 + 5;

int n;
vector<vector<tuple<int, int, int>>> g;
vector<long long int> dists;

void get_dists(int code) {
    vector<bool> vis(n, false);
    dists.assign(n, INF);
    dists[0] = 0LL;

    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> heap;
    heap.emplace(0LL, 0);

    while (!heap.empty()) {
        int v = heap.top().second; heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, d, s]: g[v])
            if (!vis[u] && code >= s && dists[v] + d < dists[u]) {
                dists[u] = dists[v] + d;
                heap.emplace(dists[u], u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m;
    cin >> n >> m;

    int l = INT_MAX, r = INT_MIN;
    g.assign(n, vector<tuple<int, int, int>>());

    for (int i = 0; i < m; i++) {
        int x, y, d, s;
        cin >> x >> y >> d >> s;

        l = min(l, s);
        r = max(r, s);

        g[x - 1].emplace_back(y - 1, d, s);
        g[y - 1].emplace_back(x - 1, d, s);
    }

    int T; cin >> T;

    int code = -1, time = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        get_dists(mid);
        if (dists[n - 1] > T) l = mid + 1;
        else r = mid - 1, code = mid, time = dists[n - 1];
    }

    if (code == -1) cout << "NO\n";
    else cout << "YES\n" << code << " " << time << "\n";
}