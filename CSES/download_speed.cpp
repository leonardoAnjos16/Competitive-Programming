#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct MaxFlow {
private:
    int n;
    vector<vector<int>> g;
    vector<vector<long>> c;

public:
    MaxFlow(int n, vector<vector<int>> &g, vector<vector<long>> &c) {
        this->n = n;
        this->g = g;
        this->c = c;
    }

    MaxFlow(int n, vector<vector<pair<int, long>>> &g) {
        this->n = n;
        this->g.assign(n, vector<int>());
        c.assign(n, vector<long>(n, 0));

        for (int i = 0; i < n; i++)
            for (auto p: g[i]) {
                int v = p.first;
                long w = p.second;

                this->g[i].push_back(v);
                this->g[v].push_back(i);
                c[i][v] = w;
            }
    }

    long max_flow(int s, int t) {
        vector<int> p;
        long ans = 0LL, flow;

        while (flow = find_path(s, t, p)) {
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
    long find_path(int s, int t, vector<int> &p) {
        p.assign(n, -1);
        p[s] = s;

        queue<pair<int, long>> aux;
        aux.emplace(s, LLONG_MAX);

        while (!aux.empty()) {
            int v = aux.front().first;
            long flow = aux.front().second;
            aux.pop();

            for (auto u: g[v])
                if (p[u] == -1 && c[v][u]) {
                    p[u] = v;
                    flow = min(flow, c[v][u]);

                    if (u == t) return flow;
                    aux.emplace(u, flow);
                }
        }

        return 0LL;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>());
    vector<vector<long>> cap(n, vector<long>(n, 0LL));

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (!cap[a - 1][b - 1]) {
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }

        cap[a - 1][b - 1] += c;
    }

    MaxFlow solver(n, g, cap);
    long ans = solver.max_flow(0, n - 1);
    cout << ans << "\n";
}