#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int t;
vector<vector<tuple<int, int, int>>> g;
vector<vector<pair<int, int>>> forest;
vector<int> tin, low, components, balance;
vector<bool> vis, bridge;

void get_bridges(int v, int parent = -1) {
    vis[v] = true;
    tin[v] = low[v] = t++;

    for (auto [u, w, idx]: g[v]) {
        if (u == parent) continue;

        if (vis[u]) low[v] = min(low[v], tin[u]);
        else {
            get_bridges(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) bridge[idx] = true;
        }
    }
}

void get_components(int v, int component) {
    components[v] = component;
    for (auto [u, w, idx]: g[v])
        if (components[u] == -1 && !bridge[idx])
            get_components(u, component);
}

llong cost(int node, int wp = 0) {
    vis[node] = true;

    llong ans = 0LL;
    for (auto [child, w]: forest[node])
        if (!vis[child]) {
            ans += cost(child, w);
            balance[node] += balance[child];
        }

    ans += 1LL * abs(balance[node]) * wp;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n, b;
        cin >> n >> b;

        string s; cin >> s;

        g.assign(n, vector<tuple<int, int, int>>());
        for (int i = 0; i < b; i++) {
            int x, y, c;
            cin >> x >> y >> c;

            g[x - 1].emplace_back(y - 1, c, i);
            g[y - 1].emplace_back(x - 1, c, i);
        }

        vis.assign(n, false);
        bridge.assign(b, false);
        tin.resize(n);
        low.resize(n);

        for (int i = 0; i < n; i++)
            if (!vis[i]) get_bridges(i);

        int component = 0;
        components.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (components[i] == -1)
                get_components(i, component++);

        int size = *max_element(components.begin(), components.end()) + 1;
        forest.assign(size, vector<pair<int, int>>());
        balance.assign(size, 0);

        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') balance[components[i]]++;
            else if (s[i] == 'H') balance[components[i]]--;

            for (auto [v, w, idx]: g[i])
                if (components[i] != components[v])
                    forest[components[i]].emplace_back(components[v], w);
        }

        llong ans = 0LL;
        vis.assign(size, false);

        for (int i = 0; i < size; i++)
            if (!vis[i]) ans += cost(i);

        cout << ans << "\n";
    }
}