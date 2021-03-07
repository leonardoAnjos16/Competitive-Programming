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

struct cmp {
    bool operator() (pii a, pii b) {
        return b.fst - b.snd > a.fst - a.snd;
    }
};

vector<vi> g;

vi dists;
vi children;
bitset<MAX> vis;

void get_dists() {
    queue<int> aux;
    aux.push(0);
    vis.reset();

    while (!aux.empty()) {
        int v = aux.front();
        aux.pop();

        for (auto u: g[v]) {
            if (!vis[u]) {
                aux.push(u);
                vis[u] = true;
                dists[u] = dists[v] + 1;
            }
        }
    }
}

bool get_children(int v = 0) {
    if (vis[v]) return false;

    vis[v] = true;
    children[v] = 0;

    for (auto u: g[v])
        if (get_children(u))
            children[v] += children[u] + 1;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    g.assign(n, vi());
    dists.assign(n, 0);
    children.assign(n, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        g[u - 1].pb(v - 1);
        g[v - 1].pb(u - 1);
    }

    get_children();
    get_dists();

    priority_queue<pii, vector<pii>, cmp> pq;
    for (int i = 0; i < n; i++)
        pq.push({ dists[i], children[i] });

    long ans = 0LL;
    while (k--) {
        pii top = pq.top(); pq.pop();
        ans += top.fst - top.snd;
    }

    cout << ans << "\n";
}