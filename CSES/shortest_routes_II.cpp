#include <bits/stdc++.h>
 
using namespace std;
 
const long long int INF = 1e18 + 5;
 
int n;
vector<vector<long long int>> g;
vector<vector<long long int>> dists;
 
void get_dists() {
    dists.assign(n, vector<long long int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            dists[i][j] = g[i][j];
        
        dists[i][i] = 0LL;
    }
 
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dists[i][k] + dists[k][j] < dists[i][j])
                    dists[i][j] = dists[i][k] + dists[k][j];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int m, q;
    cin >> n >> m >> q;
 
    g.assign(n, vector<long long int>(n, INF));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1][b - 1] = g[b - 1][a - 1] = min(g[a - 1][b - 1], (long long int) c);
    }
 
    get_dists();
    while (q--) {
        int a, b;
        cin >> a >> b;
 
        long long int ans = dists[a - 1][b - 1];
        if (ans >= INF) cout << "-1\n";
        else cout << ans << "\n";
    }
}