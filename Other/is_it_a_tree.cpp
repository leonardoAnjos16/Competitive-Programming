#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> g;
vector<bool> vis;

void visit(int v = 0) {
    if (vis[v]) return;
    vis[v] = true;

    for (auto u: g[v])
        visit(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    g.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    bool isTree = M == N - 1;
    vis.assign(N, false);

    visit();

    for (int i = 0; i < N && isTree; i++)
        if (!vis[i]) isTree = false;

    cout << (isTree ? "YES" : "NO") << "\n";
}