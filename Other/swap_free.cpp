#include <bits/stdc++.h>

using namespace std;

#define long long long int

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
        aux.emplace(s, -1);

        while (!aux.empty()) {
            int v = aux.front().first;
            T flow = aux.front().second;
            aux.pop();

            for (auto u: g[v])
                if (p[u] == -1 && c[v][u] > 0) {
                    p[u] = v;
                    if (flow == -1 || c[v][u] < flow)
                        flow = c[v][u];

                    if (u == t) return flow;
                    aux.emplace(u, flow);
                }
        }

        return 0;
    }
};

vector<int> color;

void get_color(vector<vector<int>> &g, int v, int c = 0) {
    if (~color[v]) assert(color[v] == c);
    else {
        color[v] = c;
        for (auto u: g[v])
            get_color(g, u, 1 - c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < (int) words[i].size(); k++)
                if (words[i][k] != words[j][k]) cnt++;

            if (cnt == 2) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }

    color.assign(n, -1);
    for (int i = 0; i < n; i++)
        if (color[i] == -1)
            get_color(g, i);

    vector<vector<int>> h(n + 2, vector<int>());
    vector<vector<int>> c(n + 2, vector<int>(n + 2, 0));

    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            h[0].push_back(i + 1);
            h[i + 1].push_back(0);
            c[0][i + 1] = 1;
        } else {
            h[i + 1].push_back(n + 1);
            h[n + 1].push_back(i + 1);
            c[i + 1][n + 1] = 1;
        }

        if (!color[i])
            for (auto v: g[i])
                if (color[v]) {
                    h[i + 1].push_back(v + 1);
                    h[v + 1].push_back(i + 1);
                    c[i + 1][v + 1] = 1;
                }
    }

    MaxFlow<int> solver(n + 2, h, c);
    int ans = n - solver.max_flow(0, n + 1);
    cout << ans << "\n";
}