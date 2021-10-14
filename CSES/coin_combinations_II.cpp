#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= c[i])
                dp[i][j] += dp[i][j - c[i]];

            dp[i][j] %= MOD;
        }

    int ans = dp[n][x];
    cout << ans << "\n";
}