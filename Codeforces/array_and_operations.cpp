#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n;
vector<vector<int>> g, c;

int find_path(int s, int t, vector<int> &p) {
    p.assign(n + 2, -1);
    p[s] = s;

    queue<pair<int, int>> aux;
    aux.push(make_pair(s, INT_MAX));

    while (!aux.empty()) {
        int v = aux.front().first;
        int flow = aux.front().second;
        aux.pop();

        for (auto u: g[v]) {
            if (p[u] == -1 && c[v][u]) {
                p[u] = v;
                flow = min(flow, c[v][u]);

                if (u == t) return flow;
                aux.push(make_pair(u, flow));
            }
        }
    }

    return 0;
}

int max_flow(int s, int t) {
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

    int m;
    cin >> n >> m;

    vector<map<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int ai; cin >> ai;
        for (long j = 2LL; j * j <= ai; j++)
            while (!(ai % j)) a[i][j]++, ai /= j;

        if (ai > 1) a[i][ai]++;
    }

    g.assign(n + 2, vector<int>());
    for (int i = 2; i <= n; i += 2) {
        g[0].push_back(i);
        g[i].push_back(0);
    }

    for (int i = 1; i <= n; i += 2) {
        g[i].push_back(n + 1);
        g[n + 1].push_back(i);
    }

    while (m--) {
        int i, j;
        cin >> i >> j;

        g[i].push_back(j);
        g[j].push_back(i);
    }

    set<int> primes;
    for (int i = 1; i <= n; i++)
        for (auto p: a[i])
            primes.insert(p.first);

    int ans = 0;
    for (auto p: primes) {
        c.assign(n + 2, vector<int>(n + 2, 0));
        for (int i = 2; i <= n; i += 2)
            c[0][i] = a[i][p];

        for (int i = 1; i <= n; i += 2)
            c[i][n + 1] = a[i][p];

        for (int i = 2; i <= n; i += 2)
            for (auto j: g[i])
                c[i][j] = min(a[i][p], a[j][p]);

        ans += max_flow(0, n + 1);
    }

    cout << ans << "\n";
}