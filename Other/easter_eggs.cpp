#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

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

int squared_dist(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    return dx * dx + dy * dy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int N, B, R;
    cin >> N >> B >> R;

    vector<int> bx(B), by(B);
    for (int i = 0; i < B; i++)
        cin >> bx[i] >> by[i];

    vector<int> rx(R), ry(R);
    for (int i = 0; i < R; i++)
        cin >> rx[i] >> ry[i];

    int l = 0, r = 1e9 + 5, mn = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        MaxFlow<int> solver(B + R + 2);
        for (int i = 0; i < B; i++)
            for (int j = 0; j < R; j++)
                if (squared_dist(bx[i], by[i], rx[j], ry[j]) < mid)
                    solver.add_edge(i + 1, B + j + 1, 1);

        int src = 0, snk = B + R + 1;
        for (int i = 1; i <= B; i++)
            solver.add_edge(src, i, 1);

        for (int i = 1; i <= R; i++)
            solver.add_edge(B + i, snk, 1);

        int max_ind_set = B + R - solver.max_flow(src, snk);
        if (max_ind_set < N) r = mid - 1;
        else l = mid + 1, mn = mid;
    }

    ldouble ans = sqrtl(mn);
    cout << ans << "\n";
}