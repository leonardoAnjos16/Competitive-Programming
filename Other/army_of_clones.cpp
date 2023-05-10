#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 32;

int x;
vector<int> a;
vector<vector<int>> g;
vector<vector<bool>> vis;

void visit(int divs, int v = 0) {
    int clones = x >> divs;
    if (!clones || vis[divs][v]) return;

    vis[divs][v] = true;
    for (int u: g[v])
        visit(clones > a[u] ? divs : divs + 1, u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    cin >> x;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vis.assign(MAX, vector<bool>(n, false));
    visit(x > a[0] ? 0 : 1);

    int divs = 0;
    while ((x >> divs) && !vis[divs][n - 1]) divs++;

    int ans = x >> divs;
    cout << ans << "\n";
}