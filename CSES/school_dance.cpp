#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n, m;
vector<vector<int>> g, c;

int find_path(int s, int t, vector<int> &p) {
    p.assign(n + m + 2, -1);
    p[s] = s;

    queue<pair<int, int>> aux;
    aux.emplace(s, INT_MAX);

    while (!aux.empty()) {
        int v = aux.front().first;
        int flow = aux.front().second;
        aux.pop();

        for (auto u: g[v])
            if (p[u] == -1 && c[v][u]) {
                p[u] = v;
                flow = min(flow, c[v][u]);

                if (u == t) return flow;
                aux.emplace(u, flow);
            }
    }

    return 0;
}

int max_matching(int s, int t) {
    vector<int> p;
    int ans = 0, flow;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> n >> m >> k;

    g.assign(n + m + 2, vector<int>());
    c.assign(n + m + 2, vector<int>(n + m + 2, 0));

    for (int i = 1; i <= n; i++) {
        g[0].push_back(i);
        g[i].push_back(0);
        c[0][i] = 1;
    }

    for (int i = n + 1; i <= n + m; i++) {
        g[i].push_back(n + m + 1);
        g[n + m + 1].push_back(i);
        c[i][n + m + 1] = 1;
    }

    while (k--) {
        int a, b;
        cin >> a >> b;

        if (!c[a][n + b]) {
            g[a].push_back(n + b);
            g[n + b].push_back(a);
        }
        
        c[a][n + b] = 1;
    }

    int ans = max_matching(0, n + m + 1);
    cout << ans << "\n";

    vector<pair<int, int>> matching;
    for (int i = 1; i <= n; i++)
        for (auto j: g[i])
            if (j && !c[i][j])
                matching.emplace_back(i, j - n);

    assert((int) matching.size() == ans);
    for (auto p: matching)
        cout << p.first << " " << p.second << "\n";
}