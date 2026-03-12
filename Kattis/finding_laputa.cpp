#include <bits/stdc++.h>

using namespace std;

#define llong long long int

pair<llong, int> operator +(pair<llong, int> a, pair<llong, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

int LSO(int i) {
    int ans = 0;
    while (i) {
        ans++;
        i >>= 1;
    }

    return --ans;
}

int cost(int i, int j) {
    int diff = __builtin_popcount(i ^ j);
    return diff * diff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> g(1 << n, vector<int>(n));
    for (int i = 0; i < n * (1 << (n - 1)); i++) {
        int u, v, w;
        cin >> u >> v >> w;

        int idx = LSO(u ^ v);
        g[u][idx] = w;
        g[v][idx] = w;
    }

    vector<pair<llong, int>> dp(1 << n, make_pair(0LL, 0));
    for (int i = 1; i < (1 << n); i++) {
        dp[i] = make_pair(LLONG_MAX, INT_MAX);
        for (int j = i & (i - 1); j > 0; j = i & (j - 1)) {
            if (__builtin_popcount(i ^ j) == 1) dp[i] = min(dp[i], dp[j] + make_pair(g[i][LSO(i ^ j)], 0));
            else dp[i] = min(dp[i], dp[j] + make_pair(cost(i, j), 1));
        }

        if (__builtin_popcount(i) == 1) dp[i] = min(dp[i], dp[0] + make_pair(g[i][LSO(i)], 0));
        else dp[i] = min(dp[i], dp[0] + make_pair(cost(i, 0), 1));
    }

    auto [w, edges] = dp[(1 << n) - 1];
    cout << w << "\n" << edges << "\n";
}