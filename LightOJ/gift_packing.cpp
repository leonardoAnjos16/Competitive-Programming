#include <bits/stdc++.h>

using namespace std;

#define long long long int

template<typename T = int>
struct MinCostFlow {
private:
    struct Edge {
        int from, to;
        T cap, cost, flow;

        Edge(int from, int to, T cap, T cost):
            from(from), to(to), cap(cap), cost(cost), flow(0) {}
    };

    const T INF = numeric_limits<T>::max();

    int n, src, snk;
    vector<Edge> edges;
    vector<vector<int>> ids;
    vector<T> dist;
    vector<int> parent;

public:
    MinCostFlow(int n): n(n) {
        ids.assign(n, vector<int>());
    }

    void add_edge(int u, int v, T cap, T cost) {
        int m = edges.size();

        edges.emplace_back(u, v, cap, cost);
        ids[u].push_back(m);

        edges.emplace_back(v, u, 0, -cost);
        ids[v].push_back(m + 1);
    }

    pair<T, T> min_cost_flow(int src, int snk, int max_flow) {
        this->src = src;
        this->snk = snk;

        pair<T, T> ans = make_pair(0, 0);
        while (ans.first < max_flow && shortest_paths()) {
            auto [flow, cost] = get_flow_and_cost();
            T add = min(flow, max_flow - ans.first);

            ans.first += add;
            ans.second += add * cost;
        }

        return ans;
    }

    pair<T, T> min_cost_max_flow(int src, int snk) {
        return min_cost_flow(src, snk, numeric_limits<T>::max());
    }

private:
    bool shortest_paths() {
        parent.assign(n, -1);
        dist.assign(n, INF);
        dist[src] = 0;

        queue<int> relaxed;
        relaxed.push(src);

        vector<bool> in_relaxed(n, false);
        in_relaxed[src] = true;

        while (!relaxed.empty()) {
            int v = relaxed.front();
            in_relaxed[v] = false;
            relaxed.pop();

            for (auto id: ids[v]) {
                auto [from, to, cap, cost, flow] = edges[id];

                int new_dist = dist[v] + cost;
                if (cap - flow > 0 && new_dist < dist[to]) {
                    parent[to] = id;
                    dist[to] = new_dist;

                    if (!in_relaxed[to]) {
                        relaxed.push(to);
                        in_relaxed[to] = true;
                    }
                }
            }
        }

        return dist[snk] < INF;
    }

    pair<T, T> get_flow_and_cost() {
        pair<T, T> flow_cost = make_pair(INF, 0);

        int v = snk;
        while (v != src) {
            auto [from, to, cap, cost, flow] = edges[parent[v]];
            flow_cost.first = min(flow_cost.first, cap - flow);
            flow_cost.second += cost;
            v = from;
        }

        v = snk;
        while (v != src) {
            edges[parent[v]].flow += flow_cost.first;
            edges[parent[v] ^ 1].flow -= flow_cost.first;
            v = edges[parent[v]].from;
        }

        return flow_cost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;

        int src = 0, snk = 2 * n + 1;
        MinCostFlow solver(2 * n + 2);

        for (int i = 1; i <= n; i++) {
            solver.add_edge(src, i, 1, 0);
            solver.add_edge(n + i, snk, 1, 0);

            for (int j = 1; j <= n; j++) {
                int p; cin >> p;
                solver.add_edge(i, n + j, 1, -p);
            }
        }

        cout << "Case " << t << ": ";
        int ans = -solver.min_cost_max_flow(src, snk).second;
        cout << ans << "\n";
    }
}