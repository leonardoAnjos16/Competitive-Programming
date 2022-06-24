#include <bits/stdc++.h>

using namespace std;

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

int to_int(string &num) {
    int size = num.size();
    return stoi(num.substr(0, size - 2) + num[size - 1]);
}

int square_dist(pair<int, int> p, pair<int, int> q) {
    int dx = q.first - p.first;
    int dy = q.second - p.second;
    return dx * dx + dy * dy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, v;
    while (cin >> n >> m >> s >> v) {
        MaxFlow solver(n + m + 2);
        int src = 0, snk = n + m + 1;

        vector<pair<int, int>> gophers(n);
        for (int i = 0; i < n; i++) {
            string _x, _y;
            cin >> _x >> _y;

            int x = to_int(_x);
            int y = to_int(_y);

            gophers[i] = make_pair(x, y);
            solver.add_edge(src, i + 1, 1);
        }

        for (int i = 0; i < m; i++) {
            string _x, _y;
            cin >> _x >> _y;

            int x = to_int(_x);
            int y = to_int(_y);
            pair<int, int> hole = make_pair(x, y);

            solver.add_edge(n + i + 1, snk, 1);
            for (int j = 0; j < n; j++)
                if (square_dist(gophers[j], hole) <= 100LL * v * v * s * s)
                    solver.add_edge(j + 1, n + i + 1, 1);
        }

        int ans = n - solver.max_flow(src, snk);
        cout << ans << "\n";
    }
}