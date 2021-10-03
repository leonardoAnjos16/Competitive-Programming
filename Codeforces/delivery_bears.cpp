#include <bits/stdc++.h>

using namespace std;

template<typename T>
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
        aux.emplace(s, LLONG_MAX);

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> g(n, vector<int>());
    vector<vector<int>> w(n, vector<int>(n, 0));

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
        w[a - 1][b - 1] = c;
    }

    long double l = 0.0, r = 1e6, ans = 0.0;
    vector<vector<long long int>> c(n, vector<long long int>(n));

    for (int i = 0; i < 100; i++) {
        long double mid = (l + r) / 2.0;

        for (int j = 0; j < n; j++)
            for (auto v: g[j])
                c[j][v] = w[j][v] / mid;

        MaxFlow<long long int> solver(n, g, c);
        long long int bears = solver.max_flow(0, n - 1);

        if (bears < x) r = mid;
        else l = mid, ans = x * mid;
    }

    cout << ans << "\n";
}