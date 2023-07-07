#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

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

vector<vector<vector<int>>> idx, pyramid;
vector<int> dependencies;

void get_dependencies(int depth, int row, int col) {
    if (depth < 0 || row < 0 || row > depth || col < 0 || col > depth - row) return;

    if (pyramid[depth][row][col] < 0)
        dependencies.push_back(idx[depth][row][col]);

    get_dependencies(depth - 1, row - 1, col);
    get_dependencies(depth - 1, row, col - 1);
    get_dependencies(depth - 1, row, col);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int cnt = 0;
    idx.resize(N);
    pyramid.resize(N);

    for (int i = 0; i < N; i++) {
        idx[i].resize(i + 1);
        pyramid[i].resize(i + 1);

        for (int j = 0; j < i + 1; j++) {
            idx[i][j].resize(i - j + 1);
            pyramid[i][j].resize(i - j + 1);

            for (int k = 0; k < i - j + 1; k++) {
                cin >> pyramid[i][j][k];
                idx[i][j][k] = ++cnt;
            }
        }
    }

    llong sum = 0LL;
    int src = 0, snk = cnt + 1;
    MaxFlow<llong> solver(cnt + 2);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < i + 1; j++)
            for (int k = 0; k < i - j + 1; k++) {
                if (pyramid[i][j][k] <= 0) solver.add_edge(idx[i][j][k], snk, -pyramid[i][j][k]);
                else {
                    sum += pyramid[i][j][k];
                    get_dependencies(i, j, k);
                    sort(dependencies.begin(), dependencies.end());
                    dependencies.erase(unique(dependencies.begin(), dependencies.end()), dependencies.end());

                    solver.add_edge(src, idx[i][j][k], pyramid[i][j][k]);
                    for (int dependency: dependencies)
                        solver.add_edge(idx[i][j][k], dependency, INF);

                    dependencies.clear();
                }
            }

    llong ans = sum - solver.max_flow(src, snk);
    cout << ans << "\n";
}