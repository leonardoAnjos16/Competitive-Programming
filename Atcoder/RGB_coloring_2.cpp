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

const int MAX = 25;

vector<vi> g;
int c[MAX];
vi component;
bitset<MAX> vis;

void get_component(int v) {
    if (vis[v]) return;

    vis[v] = true;
    component.pb(v);

    for (auto u: g[v])
        get_component(u);
}

long ways(vi &comp, int i = 0) {
    if (i >= size(comp)) return 1LL;

    long ans = 0LL;
    int v = comp[i];

    for (int j = 0; j < 3; j++) {
        bool possible = true;
        for (auto u: g[v])
            if (c[u] == j)
                possible = false;

        if (possible) {
            c[v] = j;
            ans += ways(comp, i + 1);
            c[v] = -1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    g.assign(N, vi());
    while (M--) {
        int A, B;
        cin >> A >> B;

        g[A - 1].pb(B - 1);
        g[B - 1].pb(A - 1);
    }

    memset(c, -1, sizeof c);

    long ans = 1LL;
    for (int i = 0; i < N; i++) {
        get_component(i);
        ans *= ways(component);
        component.clear();
    }
    
    cout << ans << "\n";
}