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

        edges.emplace_back(v, cap);
        ids[u].push_back(m);

        edges.emplace_back(u, 0);
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

    void get_matches(vector<int> &chosen) {
        for (int i = 0; i < (int) chosen.size(); i++)
            for (int id: ids[i + 1])
                if (edges[id].cap == 0)
                    chosen[i] = edges[id].to;
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

int pos(vector<llong> &nums, llong num) {
    return lower_bound(nums.begin(), nums.end(), num) - nums.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<llong> results;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];

        results.push_back(a[i] + b[i]);
        results.push_back(a[i] - b[i]);
        results.push_back(1LL * a[i] * b[i]);
    }

    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());

    int m = results.size();
    MaxFlow<int> solver(n + m + 2);

    int src = 0, snk = n + m + 1;
    for (int i = 0; i < n; i++) {
        solver.add_edge(src, i + 1, 1);
        solver.add_edge(i + 1, n + pos(results, a[i] + b[i]) + 1, 1);
        solver.add_edge(i + 1, n + pos(results, a[i] - b[i]) + 1, 1);
        solver.add_edge(i + 1, n + pos(results, 1LL * a[i] * b[i]) + 1, 1);
    }

    for (int i = 0; i < m; i++)
        solver.add_edge(n + i + 1, snk, 1);

    int matches = solver.max_flow(src, snk);
    if (matches < n) cout << "impossible\n";
    else {
        vector<int> chosen(n, -1);
        solver.get_matches(chosen);

        for (int i = 0; i < n; i++) {
            assert(chosen[i] != -1);

            llong result = results[chosen[i] - n - 1];
            char op = result == a[i] + b[i] ? '+' : (result == a[i] - b[i] ? '-' : '*');

            cout << a[i] << " " << op << " " << b[i] << " = " << result << "\n";
        }
    }
}