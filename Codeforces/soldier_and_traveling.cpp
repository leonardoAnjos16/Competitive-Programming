#include <bits/stdc++.h>

using namespace std;

#define long long long int

template<typename T = int>
struct MaxFlow {
private:
    struct Edge {
        int from, to;
        T cap, flow;

        Edge(int from, int to, T cap) {
            this->from = from;
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

        edges.push_back(Edge(u, v, cap));
        ids[u].push_back(m);

        edges.push_back(Edge(v, u, 0));
        ids[v].push_back(m + 1);
    }

    T max_flow(int src, int snk) {
        const T INF = numeric_limits<T>::max();

        this->src = src;
        this->snk = snk;

        for (auto &e: edges)
            e.flow = 0;

        T ans = 0;
        while (get_depths()) {
            T flow;
            first.assign(n, 0);

            while ((flow = find_path(src, INF)) > 0)
                ans += flow;
        }

        return ans;
    }

    vector<vector<int>> get_flow() {
        int vertices = (n - 2) / 2;
        vector<vector<int>> ans(vertices, vector<int>(vertices, 0));

        for (auto [from, to, cap, flow]: edges) {
            int mn = min(from, to), mx = max(from, to);
            if (mn == src || mx == snk) continue;
            ans[mn - 1][mx - vertices - 1] = abs(flow);
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
                auto [from, u, cap, flow] = edges[id];
                if (cap - flow > 0 && depth[u] == -1) {
                    aux.push(u);
                    depth[u] = depth[v] + 1;
                }
            }
        }

        return depth[snk] != -1;
    }

    T find_path(int v, T flow) {
        if (flow == 0) return 0;
        if (v == snk) return flow;

        while (first[v] < (int) ids[v].size()) {
            int id = ids[v][first[v]++];
            Edge e = edges[id];

            if (depth[e.to] == depth[v] + 1) {
                T curr = find_path(e.to, min(flow, e.cap - e.flow));
                if (curr > 0) {
                    edges[id].flow += curr;
                    edges[id ^ 1].flow -= curr;
                    return curr;
                }
            }
        }

        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int sum_a = 0;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }

    int sum_b = 0;
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum_b += b[i];
    }

    const int INF = 1e6 + 5;

    MaxFlow solver(2 * n + 2);
    int source = 0, sink = 2 * n + 1;

    for (int i = 0; i < n; i++) {
        solver.add_edge(source, i + 1, a[i]);
        solver.add_edge(n + i + 1, sink, b[i]);
        solver.add_edge(i + 1, n + i + 1, INF);
    }

    while (m--) {
        int p, q;
        cin >> p >> q;

        solver.add_edge(p, n + q, INF);
        solver.add_edge(q, n + p, INF);
    }

    int max_flow = solver.max_flow(source, sink);
    if (max_flow != sum_a || max_flow != sum_b) cout << "NO\n";
    else {
        cout << "YES\n";

        vector<vector<int>> ans = solver.get_flow();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) cout << " ";
                cout << ans[i][j];
            }

            cout << "\n";
        }
    }
}