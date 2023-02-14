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

    void add(int u, int v) {
        g[u].push_back(v);
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

    TwoSAT solver(n);
    bool possible = true;

    while (m--) {
        int x, y, c; string op;
        cin >> x >> y >> op >> c;

        if (op == "=" && c == 1) solver.add_xor(x, y);
        else if ((op == "!=" && c == 0) || (op == ">" && c == 0) || (op == ">=" && c == 1)) solver.add_or(x, y);
        else if (op == "!=" && c == 1) solver.add_xnor(x, y);
        else if ((op == "!=" && c == 2) || (op == "<" && c == 2) || (op == "<=" && c == 1)) solver.add_nand(x, y);
        else if ((op == "<" && c == 0) || (op == ">" && c == 2)) possible = false;
        else if ((op == "=" && c == 0) || (op == "<" && c == 1) || (op == "<=" && c == 0)) {
            solver.add(2 * x, 2 * x + 1);
            solver.add(2 * y, 2 * y + 1);
        }
        else if ((op == "=" && c == 2) || (op == ">" && c == 1) || (op == ">=" && c == 2)) {
            solver.add(2 * x + 1, 2 * x);
            solver.add(2 * y + 1, 2 * y);
        }
    }

    vector<bool> assignment;
    possible &= solver.solve(assignment);

    cout << (possible ? "Yes" : "No") << "\n";
}