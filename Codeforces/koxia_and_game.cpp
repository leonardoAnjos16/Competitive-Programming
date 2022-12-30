#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 998244353;

vector<vector<int>> g;
vector<int> vertices, edges;
vector<bool> vis, self_loop;

void traverse(int v) {
    vis[v] = true;
    vertices.back()++;

    for (int u: g[v]) {
        edges.back()++;
        if (u == v) self_loop.back() = true;
        else if (!vis[u]) traverse(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        g.assign(n, vector<int>());
        for (int i = 0; i < n; i++) {
            int b; cin >> b;
            g[a[i] - 1].push_back(b - 1);
            g[b - 1].push_back(a[i] - 1);
        }

        vis.assign(n, false);
        vertices.clear();
        edges.clear();
        self_loop.clear();

        for (int i = 0; i < n; i++)
            if (!vis[i]) {
                vertices.push_back(0);
                edges.push_back(0);
                self_loop.push_back(false);
                traverse(i);
            }

        int ans = 1;
        for (int i = 0; i < (int) vertices.size() && ans; i++) {
            if (vertices[i] != edges[i] / 2) ans = 0;
            else if (self_loop[i]) ans = (1LL * ans * n) % MOD;
            else ans = (2LL * ans) % MOD;
        }

        cout << ans << "\n";
    }
}