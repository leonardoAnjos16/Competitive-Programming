#include <bits/stdc++.h>

using namespace std;

#define llong long long int

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

    const int INF = 1e9 + 5;

    int N; cin >> N;

    MaxFlow solver(2 * N + 2);
    for (int i = 1; i <= N; i++) {
        int C; cin >> C;
        solver.add_edge(i, N + i, C);
    }

    int a, b;
    vector<int> indeg(N + 1, 0), outdeg(N + 1, 0);

    while (cin >> a >> b) {
        solver.add_edge(N + a + 1, b + 1, INF);
        outdeg[a + 1]++;
        indeg[b + 1]++;
    }

    int src = 0, snk = 2 * N + 1;
    for (int i = 1; i <= N; i++) {
        if (!indeg[i]) solver.add_edge(src, i, INF);
        if (!outdeg[i]) solver.add_edge(N + i, snk, INF);
    }

    int ans = solver.max_flow(src, snk);
    cout << ans << "\n";
}