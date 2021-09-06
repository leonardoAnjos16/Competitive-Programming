#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;

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

bitset<MAX> vis;
vector<vector<int>> g;

bool path(int v, int goal) {
    if (vis[v]) return false;
    if (v == goal) return true;

    vis[v] = true;
    for (auto u: g[v])
        if (path(u, goal))
            return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }

    SCC scc(n, g);
    vector<int> component = scc.get_components();

    int a, b;
    bool possible = true;

    for (int i = 1; i < n && possible; i++)
        if (component[i] != component[i - 1]) {
            a = i; b = i + 1;
            possible = false;
        }

    if (possible) cout << "YES\n";
    else {
        cout << "NO\n";
        if (path(a - 1, b - 1))
            swap(a, b);

        cout << a << " " << b << "\n";
    }
}