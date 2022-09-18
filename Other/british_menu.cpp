#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SCC {
private:
    int n;
    stack<int> order;
    vector<bool> vis;
    vector<int> component;
    vector<vector<int>> g, gt;

public:
    SCC(int n, vector<vector<int>> &g) {
        this->n = n;
        this->g = g;

        gt.assign(n, vector<int>());
        for (int i = 0; i < n; i++)
            for (auto v: g[i])
                gt[v].push_back(i);
    }

    vector<int> get_components() {
        vis.assign(n, false);
        for (int i = 0; i < n; i++)
            if (!vis[i]) toposort(i);

        int idx = 0;
        component.assign(n, -1);

        while (!order.empty()) {
            int v = order.top(); order.pop();
            if (component[v] == -1)
                get_component(v, idx++);
        }

        return component;
    }

private:
    void toposort(int v) {
        if (vis[v]) return;
        vis[v] = true;

        for (auto u: g[v])
            toposort(u);

        order.push(v);
    }

    void get_component(int v, int c) {
        if (~component[v]) return;
        component[v] = c;

        for (auto u: gt[v])
            get_component(u, c);
    }
};

void get_dists(vector<vector<int>> &g, vector<int> &component, map<int, int> &dists, vector<bool> &vis, int v, int d = 0) {
    dists[v] = max(dists[v], d);
    for (int u: g[v])
        if (component[u] == component[v] && !vis[u]) {
            vis[u] = true;
            get_dists(g, component, dists, vis, u, d + 1);
            vis[u] = false;
        }
}

int longest(vector<vector<int>> &g, vector<int> &component, vector<map<int, int>> &dists, vector<vector<int>> &memo, int v, bool in = true) {
    int &ans = memo[in][v];
    if (~ans) return ans;

    ans = 0;
    if (in)
        for (auto [u, d]: dists[v])
            ans = max(ans, d + longest(g, component, dists, memo, u, !in));
    else
        for (int u: g[v])
            if (component[u] != component[v])
                ans = max(ans, longest(g, component, dists, memo, u, !in) + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }

    vector<bool> vis(n, false);
    vector<map<int, int>> dists(n);
    vector<int> component = SCC(n, g).get_components();

    for (int i = 0; i < n; i++) {
        vis[i] = true;
        get_dists(g, component, dists[i], vis, i);
        vis[i] = false;
    }

    vector<vector<int>> memo(2, vector<int>(n, -1));

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, longest(g, component, dists, memo, i) + 1);

    cout << ans << "\n";
}