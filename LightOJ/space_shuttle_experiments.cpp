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

    const int INF = 1e6 + 5;

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int m, n;
        cin >> m >> n;

        int sum = 0;
        vector<int> p(m + 1);

        for (int i = 1; i <= m; i++) {
            cin >> p[i];
            sum += p[i];
        }

        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> c[i];

        vector<vector<int>> instruments(m + 1);
        for (int i = 1; i <= m; i++) {
            int q; cin >> q;

            instruments[i].resize(q);
            for (int j = 0; j < q; j++)
                cin >> instruments[i][j];
        }

        MaxFlow solver(m + n + 2);
        int src = 0, snk = m + n + 1;

        for (int i = 1; i <= m; i++) {
            solver.add_edge(src, i, p[i]);
            for (int instrument: instruments[i])
                solver.add_edge(i, m + instrument, INF);
        }

        for (int i = 1; i <= n; i++)
            solver.add_edge(m + i, snk, c[i]);

        cout << "Case " << t << ": ";
        int ans = sum - solver.max_flow(src, snk);
        cout << ans << "\n";
    }
}