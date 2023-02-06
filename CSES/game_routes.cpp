#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

int n;
vector<vector<int>> g;
vector<int> memo;

int ways(int v = 0) {
    if (v + 1 == n) return 1;

    int &ans = memo[v];
    if (~ans) return ans;

    ans = 0;
    for (int u: g[v])
        ans = (ans + ways(u)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }

    memo.assign(n, -1);

    int ans = ways();
    cout << ans << "\n";
}