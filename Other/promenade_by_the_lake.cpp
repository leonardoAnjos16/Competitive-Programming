#include <bits/stdc++.h>

using namespace std;

vector<int> deg;
vector<vector<int>> g;
vector<bool> vis;

bool solve(vector<pair<int, int>> &added, int v, int prev = -1) {
    vis[v] = true;
    for (int u: g[v])
        if (!vis[u])
            solve(added, u, v);

    if (!(deg[v] & 1)) return true;
    if (prev == -1) return false;

    added.emplace_back(prev, v);
    deg[prev]++; deg[v]++;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    deg.assign(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        deg[a - 1]++;
        deg[b - 1]++;
    }

    g.assign(N, vector<int>());
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vis.assign(N, false);
    vector<pair<int, int>> added;

    bool possible = true;
    for (int i = 0; i < N && possible; i++)
        if (!vis[i])
            possible = solve(added, i);

    if (!possible) cout << "NO\n";
    else {
        cout << "YES\n";

        int sz = added.size();
        cout << sz << "\n";

        for (auto [u, v]: added)
            cout << (u + 1) << " " << (v + 1) << "\n";
    }
}