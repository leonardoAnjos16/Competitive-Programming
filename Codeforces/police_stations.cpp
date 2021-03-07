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

const int MAX = 3e5 + 5;

int d;
set<int> p;
vector<vi> g;
set<pii> used;

void bfs() {
    queue<pii> aux;
    bitset<MAX> vis;

    for (auto v: p) {
        vis[v] = true;
        aux.emplace(v, 0);
    }

    while (!aux.empty()) {
        pii front = aux.front(); aux.pop();
        if (front.snd >= d) continue;

        for (auto v: g[front.fst]) {
            if (!vis[v]) {
                vis[v] = true;
                used.emplace(front.fst, v);
                aux.emplace(v, front.snd + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k >> d;

    for (int i = 0; i < k; i++) {
        int v; cin >> v;
        p.insert(v - 1);
    }

    vector<pii> edges;
    g.assign(n, vi());

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        edges.pb({ --u, --v });
        g[u].pb(v);
        g[v].pb(u);
    }

    bfs();

    int ans = size(edges) - size(used);
    cout << ans << "\n";

    for (int i = 0; i < size(edges); i++)
        if (!used.count(edges[i]) && !used.count({ edges[i].snd, edges[i].fst }))
            cout << (i + 1) << " ";

    cout << "\n";
}