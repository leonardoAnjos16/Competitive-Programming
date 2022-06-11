#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 4e8 + 5;

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

int dist(pair<int, int> p, pair<int, int> q) {
    auto [px, py] = p;
    auto [qx, qy] = q;
    return abs(qx - px) + abs(qy - py);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<pair<int, int>> students(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        students[i] = make_pair(x, y);
    }

    vector<pair<int, int>> tutors(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        tutors[i] = make_pair(x, y);
    }

    int l = 0, r = MAX, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        MaxFlow solver(2 * N + 2);
        int src = 0, snk = 2 * N + 1;

        for (int i = 0; i < N; i++) {
            solver.add_edge(src, i + 1, 1);
            solver.add_edge(N + i + 1, snk, 1);

            for (int j = 0; j < N; j++)
                if (dist(students[i], tutors[j]) <= mid)
                    solver.add_edge(i + 1, N + j + 1, 1);
        }

        int flow = solver.max_flow(src, snk);
        if (flow < N) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}