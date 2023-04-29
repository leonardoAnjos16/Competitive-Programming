#include <bits/stdc++.h>

using namespace std;

#define llong long long int

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

    vector<int> solve(int l, int r) {
        vector<int> ans(r - l + 1);
        for (int i = 0; i < n; i++)
            for (int id: ids[i])
                if (edges[id].to >= l && edges[id].to <= r && !edges[id].cap)
                    ans[edges[id].to - l] = i - 1;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    map<string, int> id;
    vector<string> names(N);

    for (int i = 0; i < N; i++) {
        cin >> names[i];
        id[names[i]] = i;
    }

    vector<vector<bool>> place(N, vector<bool>(N, true));

    int R; cin >> R;
    while (R--) {
        int M, W;
        cin >> M >> W;

        vector<int> horses(M);
        for (int i = 0; i < M; i++) {
            string name; cin >> name;
            horses[i] = id[name];
        }

        sort(horses.begin(), horses.end());

        int idx = 0;
        for (int i = 0; i < M; i++) {
            while (idx < horses[i])
                place[idx++][W - 1] = false;

            for (int j = 0; j + 1 < W; j++)
                place[idx][j] = false;

            idx++;
        }

        while (idx < N)
            place[idx++][W - 1] = false;
    }

    int src = 0, snk = 2 * N + 1;
    MaxFlow<int> solver(2 * N + 2);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (place[i][j])
                solver.add_edge(i + 1, N + j + 1, 1);

        solver.add_edge(src, i + 1, 1);
        solver.add_edge(N + i + 1, snk, 1);
    }

    assert(solver.max_flow(src, snk) == N);

    vector<int> ans = solver.solve(N + 1, 2 * N);
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << names[ans[i]];
    }

    cout << "\n";
}