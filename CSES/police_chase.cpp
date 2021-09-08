#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 505;

int n;
vector<vector<int>> g, c;
set<int> first;
bitset<MAX> vis;

int find_path(int s, int t, vector<int> &p) {
    p.assign(n, -1);
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

int min_cut(int s, int t) {
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

void get_first(int v = 0) {
    if (vis[v]) return;
    vis[v] = true;

    first.insert(v);
    for (auto u: g[v])
        if (c[v][u])
            get_first(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    c.assign(n, vector<int>(n, 0));

    while (m--) {
        int a, b;
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);

        c[a - 1][b - 1] = 1;
        c[b - 1][a - 1] = 1;
    }

    int cut = min_cut(0, n - 1);
    cout << cut << "\n";

    get_first();

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
        for (auto v: g[i])
            if (first.count(i) && !first.count(v))
                ans.emplace_back(i + 1, v + 1);

    for (auto p: ans)
        cout << p.first << " " << p.second << "\n";
}