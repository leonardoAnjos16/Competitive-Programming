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

const int INF = 1e9;
const int MAX = 1e5 + 5;

vector<vector<pii>> g;
int dists[MAX][3];

void get_dists() {
    vector<bitset<MAX>> vis(3, bitset<MAX>());
    for (int i = 0; i < size(g); i++)
        for (int j = 0; j < 3; j++)
            dists[i][j] = INF;

    pq<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> heap;
    heap.push({ 0, { 0, 0 } });

    dists[0][0] = 0;
    for (int i = 0; i < 3 * size(g); i++) {
        int v, mod;
        do {
            if (heap.empty()) return;
            v = heap.top().snd.fst;
            mod = heap.top().snd.snd;
            heap.pop();
        } while (vis[mod][v]);

        vis[mod][v] = true;
        if (v + 1 == size(g)) continue;

        for (auto e: g[v]) {
            int u = e.fst, w = e.snd;
            if (!vis[(mod + 1) % 3][u] && dists[v][mod] + w < dists[u][(mod + 1) % 3]) {
                dists[u][(mod + 1) % 3] = dists[v][mod] + w;
                heap.push({ dists[u][(mod + 1) % 3], { u, (mod + 1) % 3 } });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<pii>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u - 1].pb({ v - 1, w });
        g[v - 1].pb({ u - 1, w });
    }

    get_dists();

    pair<int, string> ans[3];
    ans[0] = { dists[n - 1][0], "me" };
    ans[1] = { dists[n - 1][1], "Gon" };
    ans[2] = { dists[n - 1][2], "Killua" };

    sort(ans, ans + 3);
    for (int i = 0; i < 3; i++)
        cout << ans[i].snd << "\n";
}