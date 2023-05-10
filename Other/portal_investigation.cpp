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

template<typename T = int>
struct MaxFlow {
private:
    struct Edge {
        int to;
        T cap;

        Edge(int to, T cap) {
            this->to = to;
            this->cap = cap;
        }
    };

    int n, src, snk;
    vector<Edge> edges;
    vector<vector<int>> ids;
    vector<int> depth, first;

public:
    MaxFlow(int n) {
        this->n = n;
        ids.assign(n, vector<int>());
    }

    void add_edge(int u, int v, T cap) {
        int m = edges.size();

        edges.push_back(Edge(v, cap));
        ids[u].push_back(m);

        edges.push_back(Edge(u, 0));
        ids[v].push_back(m + 1);
    }

    T max_flow(int src, int snk) {
        const T INF = numeric_limits<T>::max();

        this->src = src;
        this->snk = snk;

        T ans = 0;
        while (get_depths()) {
            T flow;
            first.assign(n, 0);

            while ((flow = find_path(src, INF)) > 0)
                ans += flow;
        }

        return ans;
    }

private:
    bool get_depths() {
        depth.assign(n, -1);
        depth[src] = 0;

        queue<int> aux;
        aux.push(src);

        while (!aux.empty()) {
            int v = aux.front(); aux.pop();
            for (auto id: ids[v]) {
                Edge &e = edges[id];
                if (e.cap > 0 && depth[e.to] == -1) {
                    aux.push(e.to);
                    depth[e.to] = depth[v] + 1;
                }
            }
        }

        return depth[snk] != -1;
    }

    T find_path(int v, T flow) {
        if (flow == 0) return 0;
        if (v == snk) return flow;

        while (first[v] < (int) ids[v].size()) {
            int id = ids[v][first[v]];
            Edge &e = edges[id];

            if (depth[e.to] == depth[v] + 1) {
                T curr = find_path(e.to, min(flow, e.cap));
                if (curr > 0) {
                    edges[id].cap -= curr;
                    edges[id ^ 1].cap += curr;
                    return curr;
                }
            }

            first[v]++;
        }

        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    vector<vector<int>> g(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        edges[i] = make_pair(a - 1, b - 1);
    }

    vector<int> component = SCC(n, g).get_components();

    int portals = 0;
    for (auto [u, v]: edges)
        if (component[u] == component[v])
            portals++;

    cout << portals << "\n";

    int components = *max_element(component.begin(), component.end()) + 1;
    vector<int> sz(components, 0);

    for (int i = 0; i < n; i++)
        sz[component[i]]++;

    vector<int> deg(components, 0);
    for (int i = 0; i < components; i++)
        for (int v: g[i])
            deg[component[v]]++;

    MaxFlow<int> solver(2 * components + 2);
    for (auto [u, v]: edges)
        if (component[u] != component[v])
            solver.add_edge(component[u] + 1, components + component[v] + 1, 1);

    for (int i = 0; i < components; i++)
        if (sz[i] == 1)
            solver.add_edge(i + 1, components + i + 1, 1);

    int src = 0, snk = 2 * components + 1;
    for (int i = 0; i < components; i++) {
        solver.add_edge(src, i + 1, 1);
        solver.add_edge(components + i + 1, snk, 1);
    }

    int clones = components - solver.max_flow(src, snk);
    cout << clones << "\n";
}