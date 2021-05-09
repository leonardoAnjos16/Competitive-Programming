#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 3e4 + 5;

vector<vi> g;
bitset<MAX> vis;

void dfs(int v = 0) {
    if (vis[v]) return;

    vis[v] = true;
    for (auto u: g[v]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    g.assign(n, vi());
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        g[i - 1].pb(i + a - 1);
    }

    dfs();
    cout << (vis[t - 1] ? "YES" : "NO") << "\n";
}