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

const int MAX = 1e6 + 5;

vector<vector<pii>> g;

int prim() {
    bitset<MAX> vis;

    int weights[MAX];
    memset(weights, -1, sizeof weights);

    pq<pii, vector<pii>, greater<pii>> heap;
    heap.emplace(0, 0);

    int ans = 0;
    weights[0] = 0;

    for (int i = 0; i < size(g); i++) {
        int v;
        do {
            if (heap.empty()) return -1;
            v = heap.top().snd; heap.pop();
        } while (vis[v]);

        vis[v] = true;
        ans = max(ans, weights[v]);

        for (auto e: g[v]) {
            int u = e.fst, w = e.snd;
            if (!vis[u] && (weights[u] == -1 || w <= weights[u])) {
                weights[u] = w;
                heap.emplace(weights[u], u);
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m, n || m) {
        g.assign(n, vector<pii>());
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            g[u].pb({ v, w });
            g[v].pb({ u, w });
        }

        int ans = prim();

        if (ans != -1) cout << ans << "\n";
        else cout << "IMPOSSIBLE\n";

        g.clear();
    }
}