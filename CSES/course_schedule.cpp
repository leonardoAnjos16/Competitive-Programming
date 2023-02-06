#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> g;
vector<int> vis;
stack<int> ans;

bool solve(int v) {
    if (vis[v] == 2) return true;
    if (vis[v] == 1) return false;

    vis[v] = 1;
    for (int u: g[v])
        if (!solve(u))
            return false;

    vis[v] = 2;
    ans.push(v + 1);

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }

    vis.assign(n, 0);
    bool possible = true;

    for (int i = 0; i < n && possible; i++)
        if (!solve(i)) possible = false;

    if (!possible) cout << "IMPOSSIBLE\n";
    else {
        while (!ans.empty()) {
            cout << ans.top(); ans.pop();
            if (!ans.empty()) cout << " ";
        }

        cout << "\n";
    }
}