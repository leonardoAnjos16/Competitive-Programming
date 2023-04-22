#include <bits/stdc++.h>

using namespace std;

#define llong long long int

template<typename T>
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
            for (int id: ids[v]) {
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

const int MAX = 2e7 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<MAX> composite;
    for (int i = 3; i * i < MAX; i += 2)
        if (!composite[i])
            for (int j = 3 * i; j < MAX; j += 2 * i)
                composite[j] = true;

    int n; cin >> n;

    int ones = 0;
    vector<int> p;

    for (int i = 0; i < n; i++) {
        int pi; cin >> pi;
        if (pi == 1) ones++;
        else p.push_back(pi);
    }

    if (ones) p.push_back(1);
    n = p.size();

    MaxFlow<int> solver(n + 2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int pij = p[i] + p[j];
            if ((p[i] & 1) && (pij & 1) && !composite[pij])
                solver.add_edge(i + 1, j + 1, 1);
        }

    for (int i = 0; i < n; i++) {
        if (p[i] & 1) solver.add_edge(0, i + 1, 1);
        else solver.add_edge(i + 1, n + 1, 1);
    }

    int ans = n - solver.max_flow(0, n + 1);
    cout << ans << "\n";
}