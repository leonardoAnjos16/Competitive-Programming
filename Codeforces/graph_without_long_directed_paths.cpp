#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

vector<vi> g;

vi colors;
bitset<MAX> vis;

bool bipartite(int v = 0, int c = 0) {
    if (vis[v]) return colors[v] == c;

    vis[v] = true;
    colors[v] = c;

    for (auto u: g[v])
        if (!bipartite(u, 1 - c))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vi());
    colors.assign(n, 0);

    vector<pii> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        edges.pb({ --u, --v });
        g[u].pb(v);
        g[v].pb(u);
    }

    if (!bipartite()) {
        cout << "NO\n";
        return 0;
    }

    string ans(m, '-');
    for (int i = 0; i < m; i++)
        ans[i] = colors[edges[i].fst] ? '0' : '1';

    cout << "YES\n" << ans << "\n";
}