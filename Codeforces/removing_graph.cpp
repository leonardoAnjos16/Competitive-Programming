#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> g;
vector<bool> vis;

int cycle(int v) {
    if (vis[v]) return 0;

    int ans = 1;
    vis[v] = true;

    for (int u: g[v])
        ans += cycle(u);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r;
    cin >> n >> l >> r;

    g.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;

        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    vector<int> cycles;
    vis.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!vis[i])
            cycles.push_back(cycle(i));

    int ans = 0;
    for (int c: cycles) {
        if (c >= l + r) continue;
        ans ^= c / l;
    }

    cout << (ans ? "Alice" : "Bob") << "\n";
}