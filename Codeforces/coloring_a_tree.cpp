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

const int MAX = 1e4 + 5;

vector<vi> g;
int c[MAX];

int steps(int v = 0, int color = 0) {
    int ans = color != c[v];
    for (auto u: g[v])
        ans += steps(u, c[v]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    g.assign(n, vi());
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        g[p - 1].pb(i);
    }

    for (int i = 0; i < n; i++)
        cin >> c[i];

    int ans = steps();
    cout << ans << "\n";
}