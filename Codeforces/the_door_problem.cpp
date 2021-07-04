#include <bits/stdc++.h>

using namespace std;

#define long long long int

#include <bits/stdc++.h>

using namespace std;

struct TwoSAT {
private:
    int n;
    vector<vector<int>> g, gt;
    vector<int> component;
    vector<bool> vis;
    stack<int> order;

public:
    TwoSAT(int n) {
        this->n = n;
        clear();
    }

    void clear() {
        g.assign(2 * n, vector<int>());
        gt.assign(2 * n, vector<int>());
        component.assign(2 * n, -1);
        vis.assign(2 * n, false);
        order = stack<int>();
    }

    void add_or(int u, int v) {
        // (u || v)
        // (!u -> v) && (!v -> u)
        g[2 * u + 1].push_back(2 * v);
        g[2 * v + 1].push_back(2 * u);
    }

    void add_xor(int u, int v) {
        // (u || v) && (!u || !v)
        // (!u -> v) && (!v -> u) && (u -> !v) && (v -> !u)
        g[2 * u].push_back(2 * v + 1);
        g[2 * v].push_back(2 * u + 1);
        g[2 * u + 1].push_back(2 * v);
        g[2 * v + 1].push_back(2 * u);
    }

    void add_xnor(int u, int v) {
        // (u || !v) && (!u || v)
        // (!u -> !v) && (v -> u) && (u -> v) && (!v -> !u)
        g[2 * u].push_back(2 * v);
        g[2 * v].push_back(2 * u);
        g[2 * u + 1].push_back(2 * v + 1);
        g[2 * v + 1].push_back(2 * u + 1);
    }

    void add_nand(int u, int v) {
        // (!u || !v)
        // (u -> !v) && (v -> !u)
        g[2 * u].push_back(2 * v + 1);
        g[2 * v].push_back(2 * u + 1);
    }

    bool solve(vector<bool> &assignment) {
        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) toposort(i);

        reverse();
        int idx = 0;

        while (!order.empty()) {
            int v = order.top(); order.pop();
            if (component[v] == -1)
                get_component(v, idx++);
        }

        assignment.resize(n);
        for (int i = 0; i < n; i++) {
            if (component[2 * i] == component[2 * i + 1])
                return false;

            assignment[i] = component[2 * i] > component[2 * i + 1];
        }

        return true;
    }

private:
    void reverse() {
        for (int i = 0; i < 2 * n; i++)
            for (auto v: g[i])
                gt[v].push_back(i);
    }

    void toposort(int v) {
        vis[v] = true;
        for (auto u: g[v])
            if (!vis[u])
                toposort(u);

        order.push(v);
    }

    void get_component(int v, int c) {
        component[v] = c;
        for (auto u: gt[v])
            if (component[u] == -1)
                get_component(u, c);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> r[i];

    vector<vector<int>> switches(n);
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        while (x--) {
            int door; cin >> door;
            switches[door - 1].push_back(i);
        }
    }

    TwoSAT solver(m);
    for (int i = 0; i < n; i++) {
        assert((int) switches[i].size() == 2);
        int u = switches[i][0];
        int v = switches[i][1];

        if (r[i]) solver.add_xnor(u, v);
        else solver.add_xor(u, v);
    }

    vector<bool> assignment;
    bool possible = solver.solve(assignment);
    cout << (possible ? "YES" : "NO") << "\n";
}