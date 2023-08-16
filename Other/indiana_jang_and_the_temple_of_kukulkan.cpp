#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> need, ans;
vector<bool> vis;

bool solve(int v, int prev = -1, int edge = -1) {
    vis[v] = true;
    for (auto [u, id]: g[v])
        if (!vis[u])
            solve(u, v, id);

    if (!need[v]) return true;
    if (prev == -1) return false;

    need[v] = 0;
    need[prev] = 1 - need[prev];

    ans.push_back(edge);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(m, vector<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        int s1, s2;
        cin >> s1 >> s2;

        g[s1 - 1].emplace_back(s2 - 1, i + 1);
        g[s2 - 1].emplace_back(s1 - 1, i + 1);
    }

    need.resize(m);
    for (int i = 0; i < m; i++)
        cin >> need[i];

    vis.assign(m, false);

    bool possible = true;
    for (int i = 0; i < m && possible; i++)
        if (!vis[i] && !solve(i))
            possible = false;

    if (!possible) cout << "-1\n";
    else {
        int sz = ans.size();
        cout << sz << "\n";

        for (int i = 0; i < sz; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}