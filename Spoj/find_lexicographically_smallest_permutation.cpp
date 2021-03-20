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

const long INF = 1e18;
const int MAX = 1e3 + 5;

int a[MAX];
vector<vi> g;

bitset<MAX> vis;
pq<int, vi, greater<int>> indices, values;

void dfs(int v) {
    if (vis[v]) return;

    vis[v] = true;
    indices.push(v);
    values.push(a[v]);

    for (auto u: g[v]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        g.assign(n, vi());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            g[u - 1].pb(v - 1);
            g[v - 1].pb(u - 1);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                while (!indices.empty()) {
                    int idx = indices.top(); indices.pop();
                    int value = values.top(); values.pop();
                    a[idx] = value;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << a[i];
        }

        cout << "\n";
        g.clear();
        vis.reset();
    }
}