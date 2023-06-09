#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int n;
vector<vector<pair<int, int>>> g;
vector<llong> dist;
vector<bool> vis;
vector<int> ans;

void get_dists(int start) {
    vector<bool> vis(n, false);
    dist.assign(n, INF);
    dist[start] = 0LL;

    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> heap;
    heap.emplace(0LL, start);

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
}

bool possible(int v = 0) {
    if (v == 1) {
        ans.push_back(1);
        return true;
    }

    if (vis[v]) return false;

    vis[v] = true;
    ans.push_back(v);

    for (auto [u, w]: g[v])
        if (dist[u] + w > dist[v] && possible(u))
            return true;

    ans.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    g.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        g[a].emplace_back(b, d);
        g[b].emplace_back(a, d);
    }

    get_dists(1);

    vis.assign(n, false);
    if (!possible()) cout << "impossible\n";
    else {
        int k = ans.size();
        cout << k;

        for (int v: ans)
            cout << " " << v;

        cout << "\n";
    }
}