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

const int MAX = 2e3 + 5;

vector<vi> g;
int ans = INT_MIN;

void dfs(int v, int depth = 1) {
    for (auto u: g[v])
        dfs(u, depth + 1);

    ans = max(ans, depth);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    g.assign(n, vi());

    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p != -1) g[--p].pb(i);
    }

    for (int i = 0; i < n; i++) dfs(i);
    cout << ans << "\n";
}