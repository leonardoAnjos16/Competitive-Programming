#include <bits/stdc++.h>

using namespace std;

#define llong long long int

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

    bool solve() {
        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) toposort(i);

        reverse();
        int idx = 0;

        while (!order.empty()) {
            int v = order.top(); order.pop();
            if (component[v] == -1)
                get_component(v, idx++);
        }

        for (int i = 0; i < n; i++)
            if (component[2 * i] == component[2 * i + 1])
                return false;

        return true;
    }

private:
    void reverse() {
        for (int i = 0; i < 2 * n; i++)
            for (int v: g[i])
                gt[v].push_back(i);
    }

    void toposort(int v) {
        vis[v] = true;
        for (int u: g[v])
            if (!vis[u])
                toposort(u);

        order.push(v);
    }

    void get_component(int v, int c) {
        component[v] = c;
        for (int u: gt[v])
            if (component[u] == -1)
                get_component(u, c);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<llong> vertices;
    vector<tuple<llong, llong, int, int>> original_queries(n);

    for (int i = 0; i < n; i++) {
        llong x, y; int a, b;
        cin >> x >> y >> a >> b;

        vertices.push_back(2LL * x);
        vertices.push_back(2LL * y + 1LL);
        original_queries[i] = make_tuple(x, y, a, b);
    }

    sort(vertices.begin(), vertices.end());
    vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());
    int size = vertices.size();

    vector<tuple<int, int, int, int>> queries;
    for (auto [x, y, a, b]: original_queries) {
        int row = lower_bound(vertices.begin(), vertices.end(), 2LL * x) - vertices.begin();
        int col = lower_bound(vertices.begin(), vertices.end(), 2LL * y + 1LL) - vertices.begin();
        queries.emplace_back(row, col, a, b);
    }

    TwoSAT solver(size);
    int l = 0, r = n, ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        solver.clear();

        for (int i = 0; i < mid; i++) {
            auto [x, y, a, b] = queries[i];
            if (a == b) solver.add_xnor(x, y);
            else solver.add_xor(x, y);
        }

        if (!solver.solve()) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    for (int i = 0; i < ans; i++)
        cout << "Yes\n";

    for (int i = ans; i < n; i++)
        cout << "No\n";
}