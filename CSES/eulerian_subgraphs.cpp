#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<bool> vis;

int visit(int v) {
    if (vis[v]) return 0;

    int ans = 1;
    vis[v] = true;

    for (int u: g[v])
        ans += visit(u);

    return ans;
}

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    int cnt = 0;
    vis.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!vis[i])
            cnt += visit(i) - 1;

    int ans = exp(2, m - cnt);
    cout << ans << "\n";
}