#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 2e3 + 5;

vector<vector<int>> g;
vector<int> colors;
bitset<MAX> vis;

bool bipartite(int v = 0, int c = 0) {
    if (vis[v]) return colors[v] == c;

    colors[v] = c;
    vis[v] = true;

    for (auto u: g[v])
        if (!bipartite(u, 1 - c))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int V, E;
        cin >> V >> E;

        g.assign(V, vector<int>());
        colors.assign(V, -1);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;

            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }

        bool possible = true;
        for (int i = 0; i < V && possible; i++)
            if (!vis[i]) possible &= bipartite(i);

        string ans = possible ? "No suspicious bugs found!" : "Suspicious bugs found!";
        cout << "Scenario #" << t << ":\n" << ans << "\n";

        g.clear();
        colors.clear();
        vis.reset();
    }
}