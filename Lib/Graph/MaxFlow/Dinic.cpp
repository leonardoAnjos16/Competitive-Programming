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