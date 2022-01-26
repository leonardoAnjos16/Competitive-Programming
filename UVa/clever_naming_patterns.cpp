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

    vector<int> get_flow(int source, int sink) {
        vector<int> ans;
        max_flow(source, sink);

        for (int i = 0; i < (int) edges.size(); i += 2)
            if (edges[i].flow == edges[i].cap)
                ans.push_back(edges[i].to);

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
                int from = edges[id].from;
                int u = edges[id].to;
                int cap = edges[id].cap;
                int flow = edges[id].flow;

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

    int N; cin >> N;
    for (int t = 1; t <= N; t++) {
        int n; cin >> n;

        int num_names = 0;
        vector<vector<string>> names(n);

        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            names[i].resize(k);
            num_names += k;

            for (int j = 0; j < k; j++)
                cin >> names[i][j];
        }

        MaxFlow<int> solver(2 * n + num_names + 2);
        int source = 0, sink = 2 * n + num_names + 1;

        int names_seen = 0;
        for (int i = 0; i < n; i++) {
            solver.add_edge(source, i + 1, 1);
            for (int j = 0; j < (int) names[i].size(); j++) {
                char first = names[i][j][0];
                if (first >= 'A' && first <= 'Z')
                    first = first - 'A' + 'a';

                if (first < 'a' + n) {
                    solver.add_edge(i + 1, names_seen + j + n + 1, 1);
                    solver.add_edge(names_seen + j + n + 1, n + num_names + first - 'a' + 1, 1);
                }
            }

            names_seen += (int) names[i].size();
        }

        for (int i = 0; i < n; i++)
            solver.add_edge(n + num_names + i + 1, sink, 1);

        vector<string> all_names;
        for (int i = 0; i < n; i++)
            for (string name: names[i])
                all_names.push_back(name);

        vector<string> ans;
        vector<int> used = solver.get_flow(source, sink);

        for (int i = 0; i < (int) used.size(); i++)
            if (used[i] >= n + 1 && used[i] <= n + num_names)
                ans.push_back(all_names[used[i] - n - 1]);

        for (int i = 0; i < (int) ans.size(); i++) {
            if (ans[i][0] >= 'a' && ans[i][0] <= 'z')
                ans[i][0] = ans[i][0] - 'a' + 'A';
            
            for (int j = 1; j < (int) ans[i].size(); j++)
                if (ans[i][j] >= 'A' && ans[i][j] <= 'Z')
                    ans[i][j] = ans[i][j] - 'A' + 'a';
        }

        sort(ans.begin(), ans.end());

        cout << "Case #" << t << ":\n";
        for (string name: ans)
            cout << name << "\n";
    }
}