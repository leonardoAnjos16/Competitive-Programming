#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 30;

vector<vector<int>> g;
bitset<MAX> vis;

void traverse(int v) {
    vis[v] = true;
    for (auto u: g[v])
        if (!vis[u])
            traverse(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        char mx; cin >> mx;

        string edge;
        cin.ignore();

        g.assign(mx - 'A' + 1, vector<int>());
        while (getline(cin, edge) && edge != "") {
            int u = edge[0] - 'A';
            int v = edge[1] - 'A';

            g[u].push_back(v);
            g[v].push_back(u);
        }

        vis.reset();

        int ans = 0;
        for (char c = 'A'; c <= mx; c++)
            if (!vis[c - 'A']) traverse(c - 'A'), ans++;

        cout << ans << "\n";
        if (t) cout << "\n";
    }
}