#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> g;
vector<bool> neighbor;
vector<vector<long>> memo;

long count(int paths = 0, int lawn = 0) {
    if (paths >= 3) return neighbor[lawn];

    long &ans = memo[paths][lawn];
    if (~ans) return ans;

    ans = 0LL;
    for (int v: g[lawn])
        ans += count(paths + 1, v);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    neighbor.assign(n, false);
    for (int v: g[0])
        neighbor[v] = true;

    memo.assign(5, vector<long>(n + 5, -1));

    long ans = count();
    int neighbors = g[0].size();
    ans -= 1LL * neighbors * neighbors;

    for (int v: g[0])
        ans -= (int) g[v].size() - 1;

    cout << ans << "\n";
}