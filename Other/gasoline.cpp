#include <bits/stdc++.h>

using namespace std;

#define long long long int

template<typename T = int>
struct MaxFlow {
private:
    struct Edge {
        int to;
        T cap, flow, cost;

        Edge(int to, T cap, T cost) {
            this->to = to;
            this->cap = cap;
            this->cost = cost;
            this->flow = 0;
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

    void add_edge(int u, int v, T cap, T cost) {
        int m = edges.size();

        edges.push_back(Edge(v, cap, cost));
        ids[u].push_back(m);

        edges.push_back(Edge(u, 0, cost));
        ids[v].push_back(m + 1);
    }

    T max_flow(int src, int snk, T cost) {
        const T INF = numeric_limits<T>::max();

        this->src = src;
        this->snk = snk;

        for (auto &e: edges)
            e.flow = 0;

        T ans = 0;
        while (get_depths(cost)) {
            T flow;
            first.assign(n, 0);

            while ((flow = find_path(src, INF)) > 0)
                ans += flow;
        }

        return ans;
    }

private:
    bool get_depths(T cost) {
        depth.assign(n, -1);
        depth[src] = 0;

        queue<int> aux;
        aux.push(src);

        while (!aux.empty()) {
            int v = aux.front(); aux.pop();
            for (auto id: ids[v]) {
                auto [u, cap, flow, c] = edges[id];
                if (c <= cost && cap - flow > 0 && depth[u] == -1) {
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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P, R, C;
    cin >> P >> R >> C;

    int demand = 0;
    vector<int> D(P);

    for (int i = 0; i < P; i++) {
        cin >> D[i];
        demand += D[i];
    }

    vector<int> E(R);
    for (int i = 0; i < R; i++)
        cin >> E[i];

    MaxFlow solver(2 * (P + R + 1));
    for (int i = 0; i < R; i++) {
        solver.add_edge(0, i + 1, E[i], 0);
        solver.add_edge(i + 1, R + i + 1, E[i], 0);
    }

    for (int i = 0; i < P; i++) {
        solver.add_edge(2 * R + i + 1, 2 * R + P + i + 1, D[i], 0);
        solver.add_edge(2 * R + P + i + 1, 2 * (P + R) + 1, D[i], 0);
    }

    int mn = INT_MAX, mx = INT_MIN;
    while (C--) {
        int I, J, T;
        cin >> I >> J >> T;

        mn = min(mn, T); mx = max(mx, T);
        solver.add_edge(R + J, 2 * R + I, INF, T);
    }

    int src = 0, snk = 2 * (P + R) + 1;
    int flow = solver.max_flow(src, snk, INF);

    if (flow < demand) cout << "-1\n";
    else {
        int l = mn, r = mx, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            int curr = solver.max_flow(src, snk, mid);
            if (curr < flow) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        cout << ans << "\n";
    }
}