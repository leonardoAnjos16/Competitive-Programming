template<typename T = int>
struct MaxFlow {
private:
    int n;
    vector<vector<int>> g;
    vector<vector<T>> c;

public:
    MaxFlow(int n, vector<vector<int>> &g, vector<vector<T>> &c) {
        this->n = n;
        this->g = g;
        this->c = c;
    }

    MaxFlow(int n, vector<vector<pair<int, T>>> &g) {
        this->n = n;
        this->g.assign(n, vector<int>());
        c.assign(n, vector<T>(n, 0));

        for (int i = 0; i < n; i++)
            for (auto p: g[i]) {
                int v = p.first;
                T w = p.second;

                this->g[i].push_back(v);
                this->g[v].push_back(i);
                c[i][v] = w;
            }
    }

    T max_flow(int s, int t) {
        vector<int> p;
        T ans = 0, flow;

        while ((flow = find_path(s, t, p)) > 0) {
            ans += flow;

            int curr = t;
            while (curr != s) {
                c[p[curr]][curr] -= flow;
                c[curr][p[curr]] += flow;
                curr = p[curr];
            }
        }

        return ans;
    }

private:
    T find_path(int s, int t, vector<int> &p) {
        p.assign(n, -1);
        p[s] = s;

        queue<pair<int, T>> aux;
        aux.emplace(s, numeric_limits<T>::max());

        while (!aux.empty()) {
            int v = aux.front().first;
            T flow = aux.front().second;
            aux.pop();

            for (auto u: g[v])
                if (p[u] == -1 && c[v][u] > 0) {
                    p[u] = v;
                    flow = min(flow, c[v][u]);

                    if (u == t) return flow;
                    aux.emplace(u, flow);
                }
        }

        return 0;
    }
};