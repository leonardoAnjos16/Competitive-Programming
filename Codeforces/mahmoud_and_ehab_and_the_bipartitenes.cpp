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

const int MAX = 1e5 + 5;

vector<vi> g;

vi colors;
bitset<MAX> vis;

void bipartite(int v = 0, int c = 0) {
    if (vis[v]) return;

    vis[v] = true;
    colors[v] = c;

    for (auto u: g[v])
        bipartite(u, 1 - c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    g.assign(n, vi());
    colors.assign(n, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u - 1].pb(v - 1);
        g[v - 1].pb(u - 1);
    }

    bipartite();

    int zeroes = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i]) ones++;
        else zeroes++;
    }

    long ans = 0;
    for (int i = 0; i < n; i++) {
        if (!colors[i]) {
            int cnt = 0;
            for (auto v: g[i])
                if (colors[v]) cnt++;

            ans += ones - cnt;
        }
    }

    cout << ans << "\n";
}