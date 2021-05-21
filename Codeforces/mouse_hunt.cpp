#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

vector<vi> g;
int vis[MAX];
vector<pii> cycles;

void get_cycle(int v) {
    vis[v] = 1;
    for (auto u: g[v]) {
        if (vis[u] == 1) cycles.pb({ u, v });
        else if (!vis[u]) get_cycle(u);
    }

    vis[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int c[MAX];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    g.assign(n, vi());
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        g[i].pb(a - 1);
    }

    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++)
        if (!vis[i]) get_cycle(i);

    int ans = 0;
    for (auto cycle: cycles) {
        int u = cycle.fst, v = cycle.snd;

        int mn = c[u];
        while (u != v) {
            u = g[u][0];
            mn = min(mn, c[u]);
        }

        ans += mn;
    }

    cout << ans << "\n";
}