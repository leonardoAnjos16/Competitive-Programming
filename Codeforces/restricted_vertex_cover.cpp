#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;

vector<vector<int>> g, gt;
vector<int> component;
stack<int> order;
bitset<MAX> vis;

void toposort(int v) {
    vis[v] = true;
    for (auto u: g[v])
        if (!vis[u])
            toposort(u);

    order.push(v);
}

void get_component(int v, int idx) {
    component[v] = idx;
    for (auto u: gt[v])
        if (component[u] == -1)
            get_component(u, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        g.assign(2 * n, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            u--; v--;
            if (w) {
                // u ^ v = (u || v) && (!u || !v)
                // u ^ v = (!u -> v) && (!v -> u) && (u -> !v) && (v -> !u)
                g[2 * u].push_back(2 * v + 1);
                g[2 * v].push_back(2 * u + 1);
                g[2 * u + 1].push_back(2 * v);
                g[2 * v + 1].push_back(2 * u);
            } else {
                // u || v = (!u -> v) && (!v -> u)
                g[2 * u + 1].push_back(2 * v);
                g[2 * v + 1].push_back(2 * u);
            }
        }

        gt.assign(2 * n, vector<int>());
        for (int i = 0; i < 2 * n; i++)
            for (auto v: g[i])
                gt[v].push_back(i);

        vis.reset();
        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) toposort(i);

        int idx = 0;
        component.assign(2 * n, -1);

        while (!order.empty()) {
            int v = order.top(); order.pop();
            if (component[v] == -1)
                get_component(v, idx++);
        }

        bool possible = true;
        for (int i = 0; i < n && possible; i++)
            if (component[2 * i] == component[2 * i + 1])
                possible = false;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}